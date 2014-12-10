# Copyright (C) 2014  Spanti Nicola (RyDroid) <rydroid_dev@yahoo.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.


SRC_DIR=src
BIN_DIR=bin
DOC_DIR=doc

CC=gcc
INCLUDES=-I./$(SRC_DIR)
DEBUG_FLAGS=-g
CFLAGS=-std=c99 -Wall $(INCLUDES) $(DEBUG_FLAGS) -fPIC
RM=rm -f

PACKAGE=conway-game-of-life
FILES_TO_ARCHIVE=$(SRC_DIR)/ makefile doxygen_configuration.ini LICENSE* mainpage.dox tests/


.PHONY: $(DOC_DIR)

all: $(BIN_DIR)/main-c $(BIN_DIR)/libtab2dchar.a $(BIN_DIR)/libtab2dchar.so doc tar-bz2


$(BIN_DIR)/main-c: $(SRC_DIR)/bool.h $(BIN_DIR)/stdio_functions.o $(BIN_DIR)/string_functions.o $(BIN_DIR)/tab_2d_char_essential.o $(BIN_DIR)/tab_2d_char_print.o $(BIN_DIR)/tab_2d_char_scan.o $(BIN_DIR)/tab_2d_char_file.o $(BIN_DIR)/conway_game_of_life.o  $(BIN_DIR)/main-c.o
	$(CC) $(CFLAGS) $(BIN_DIR)/stdio_functions.o $(BIN_DIR)/string_functions.o $(BIN_DIR)/tab_2d_char_essential.o $(BIN_DIR)/tab_2d_char_print.o $(BIN_DIR)/tab_2d_char_scan.o $(BIN_DIR)/tab_2d_char_file.o $(BIN_DIR)/conway_game_of_life.o $(BIN_DIR)/main-c.o -o $(BIN_DIR)/main-c

$(BIN_DIR)/main-c.o: $(SRC_DIR)/string_functions.h $(SRC_DIR)/tab_2d_char_file.h $(SRC_DIR)/conway_game_of_life.h $(SRC_DIR)/main-c.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main-c.c -o $(BIN_DIR)/main-c.o

$(BIN_DIR)/conway_game_of_life.o: $(SRC_DIR)/tab_2d_char_print.h $(SRC_DIR)/conway_game_of_life.h $(SRC_DIR)/conway_game_of_life.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/conway_game_of_life.c -o $(BIN_DIR)/conway_game_of_life.o

$(BIN_DIR)/libtab2dchar.so: $(BIN_DIR)/stdio_functions.o $(BIN_DIR)/tab_2d_char_essential.o $(BIN_DIR)/tab_2d_char_print.o $(BIN_DIR)/tab_2d_char_scan.o $(BIN_DIR)/tab_2d_char_file.o
	gcc -o $(BIN_DIR)/libtab2dchar.so -shared $(BIN_DIR)/tab_2d_char_*.o

$(BIN_DIR)/libtab2dchar.a: $(BIN_DIR)/stdio_functions.o $(BIN_DIR)/tab_2d_char_essential.o $(BIN_DIR)/tab_2d_char_print.o $(BIN_DIR)/tab_2d_char_scan.o $(BIN_DIR)/tab_2d_char_file.o
	ar -rv $(BIN_DIR)/libtab2dchar.a $(BIN_DIR)/tab_2d_char_*.o

$(BIN_DIR)/tab_2d_char_file.o: $(SRC_DIR)/bool.h $(SRC_DIR)/tab_2d_char_file.h $(SRC_DIR)/tab_2d_char_file.h $(SRC_DIR)/tab_2d_char_file.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tab_2d_char_file.c -o $(BIN_DIR)/tab_2d_char_file.o

$(BIN_DIR)/tab_2d_char_scan.o: $(SRC_DIR)/stdio_functions.h $(SRC_DIR)/tab_2d_char_essential.h $(SRC_DIR)/tab_2d_char_scan.h $(SRC_DIR)/tab_2d_char_scan.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tab_2d_char_scan.c -o $(BIN_DIR)/tab_2d_char_scan.o

$(BIN_DIR)/tab_2d_char_print.o: $(SRC_DIR)/tab_2d_char_essential.h $(SRC_DIR)/tab_2d_char_print.h $(SRC_DIR)/tab_2d_char_print.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tab_2d_char_print.c -o $(BIN_DIR)/tab_2d_char_print.o

$(BIN_DIR)/tab_2d_char_essential.o: $(SRC_DIR)/bool.h $(SRC_DIR)/tab_2d_char_essential.h $(SRC_DIR)/tab_2d_char_essential.c
	mkdir -p $(BIN_DIR)/
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tab_2d_char_essential.c -o $(BIN_DIR)/tab_2d_char_essential.o

$(BIN_DIR)/string_functions.o: $(SRC_DIR)/string_functions.h $(SRC_DIR)/string_functions.c
	mkdir -p $(BIN_DIR)/
	$(CC) $(CFLAGS) -c $(SRC_DIR)/string_functions.c -o $(BIN_DIR)/string_functions.o

$(BIN_DIR)/stdio_functions.o: $(SRC_DIR)/stdio_functions.h $(SRC_DIR)/stdio_functions.c
	mkdir -p $(BIN_DIR)/
	$(CC) $(CFLAGS) -c $(SRC_DIR)/stdio_functions.c -o $(BIN_DIR)/stdio_functions.o


$(DOC_DIR): $(SRC_DIR)/*.h doxygen_configuration.ini
	doxygen doxygen_configuration.ini
	mkdir -p $(DOC_DIR)/
	# PDF with LaTeX
	cd $(DOC_DIR)/latex/ && make

zip: $(FILES_TO_ARCHIVE)
	zip $(PACKAGE).zip -r -- $(FILES_TO_ARCHIVE)

tar-gz: $(FILES_TO_ARCHIVE)
	tar -zcvf $(PACKAGE).tar.gz $(FILES_TO_ARCHIVE)

tar-bz2: $(FILES_TO_ARCHIVE)
	tar -jcvf $(PACKAGE).tar.bz2 $(FILES_TO_ARCHIVE)

clean:
	$(RM) -rf -- $(BIN_DIR)/ $(DOC_DIR)/ *.zip *.tar.*  *~ $(SRC_DIR)/*~ \#*# *.bak
