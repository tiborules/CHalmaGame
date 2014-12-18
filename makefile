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
DEBUG_FLAGS=-O0 -g
CFLAGS=-std=c99 -Wall -Wextra -O2 $(INCLUDES) $(DEBUG_FLAGS) -fPIC
RM=rm -f

PACKAGE=halma-game
FILES_TO_ARCHIVE=$(SRC_DIR)/ makefile doxygen_configuration.ini LICENSE* README*


.PHONY: $(DOC_DIR)

all: $(BIN_DIR)/$(PACKAGE)-text $(BIN_DIR)/libtab2dchar.a $(BIN_DIR)/libtab2dchar.so doc tar-bz2


$(BIN_DIR)/$(PACKAGE)-text: $(BIN_DIR)/stdio_functions.o $(BIN_DIR)/string_functions.o $(BIN_DIR)/tab_2d_char_essential.o $(BIN_DIR)/tab_2d_char_print.o $(BIN_DIR)/tab_2d_char_scan.o $(BIN_DIR)/tab_2d_char_file.o $(BIN_DIR)/halma_game_essential.o $(BIN_DIR)/tab_2d_char_fill_zone.o $(BIN_DIR)/halma_game_player.o $(BIN_DIR)/halma_game_players.o $(BIN_DIR)/main-c.o
	$(CC) $(CFLAGS) \
		$(BIN_DIR)/stdio_functions.o $(BIN_DIR)/string_functions.o \
		$(BIN_DIR)/tab_2d_char_essential.o $(BIN_DIR)/tab_2d_char_fill_zone.o $(BIN_DIR)/tab_2d_char_print.o $(BIN_DIR)/tab_2d_char_scan.o $(BIN_DIR)/tab_2d_char_file.o \
		$(BIN_DIR)/halma_game_essential.o $(BIN_DIR)/halma_game_player.o $(BIN_DIR)/halma_game_players.o $(BIN_DIR)/main-c.o \
		-o $(BIN_DIR)/$(PACKAGE)-text

$(BIN_DIR)/main-c.o: $(SRC_DIR)/stdio_functions.h $(SRC_DIR)/tab_2d_char_io.h  $(SRC_DIR)/tab_2d_char_file.h $(SRC_DIR)/halma_game_essential.h $(SRC_DIR)/main-c.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main-c.c -o $(BIN_DIR)/main-c.o

$(BIN_DIR)/halma_game_players.o: $(SRC_DIR)/halma_game_player.h $(SRC_DIR)/halma_game_players.h $(SRC_DIR)/halma_game_players.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/halma_game_players.c -o $(BIN_DIR)/halma_game_players.o

$(BIN_DIR)/halma_game_player.o: $(SRC_DIR)/bool.h $(SRC_DIR)/string_functions.h $(SRC_DIR)/halma_game_player.h $(SRC_DIR)/halma_game_player.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/halma_game_player.c -o $(BIN_DIR)/halma_game_player.o

$(BIN_DIR)/halma_game_essential.o: $(SRC_DIR)/tab_2d_char_print.h $(SRC_DIR)/halma_game_essential.h $(SRC_DIR)/halma_game_essential.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/halma_game_essential.c -o $(BIN_DIR)/halma_game_essential.o

$(BIN_DIR)/libtab2dchar.so: $(BIN_DIR)/stdio_functions.o $(BIN_DIR)/tab_2d_char_essential.o $(BIN_DIR)/tab_2d_char_print.o $(BIN_DIR)/tab_2d_char_scan.o $(BIN_DIR)/tab_2d_char_file.o
	$(CC) -o $(BIN_DIR)/libtab2dchar.so -shared $(BIN_DIR)/tab_2d_char_*.o

$(BIN_DIR)/libtab2dchar.a: $(BIN_DIR)/stdio_functions.o $(BIN_DIR)/tab_2d_char_essential.o $(BIN_DIR)/tab_2d_char_print.o $(BIN_DIR)/tab_2d_char_scan.o $(BIN_DIR)/tab_2d_char_file.o
	ar -rv $(BIN_DIR)/libtab2dchar.a $(BIN_DIR)/tab_2d_char_*.o

$(BIN_DIR)/tab_2d_char_file.o: $(SRC_DIR)/bool.h $(SRC_DIR)/tab_2d_char_print.h $(SRC_DIR)/tab_2d_char_file.h $(SRC_DIR)/tab_2d_char_file.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tab_2d_char_file.c -o $(BIN_DIR)/tab_2d_char_file.o

$(BIN_DIR)/tab_2d_char_scan.o: $(SRC_DIR)/stdio_functions.h $(SRC_DIR)/tab_2d_char_essential.h $(SRC_DIR)/tab_2d_char_scan.h $(SRC_DIR)/tab_2d_char_scan.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tab_2d_char_scan.c -o $(BIN_DIR)/tab_2d_char_scan.o

$(BIN_DIR)/tab_2d_char_print.o: $(SRC_DIR)/tab_2d_char_essential.h $(SRC_DIR)/tab_2d_char_print.h $(SRC_DIR)/tab_2d_char_print.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tab_2d_char_print.c -o $(BIN_DIR)/tab_2d_char_print.o

$(BIN_DIR)/tab_2d_char_fill_zone.o: $(SRC_DIR)/tab_2d_char_essential.h $(SRC_DIR)/tab_2d_char_fill_zone.h $(SRC_DIR)/tab_2d_char_fill_zone.c
	mkdir -p $(BIN_DIR)/
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tab_2d_char_fill_zone.c -o $(BIN_DIR)/tab_2d_char_fill_zone.o

$(BIN_DIR)/tab_2d_char_essential.o: $(SRC_DIR)/bool.h $(SRC_DIR)/tab_2d_char_essential.h $(SRC_DIR)/tab_2d_char_essential.c
	mkdir -p $(BIN_DIR)/
	$(CC) $(CFLAGS) -c $(SRC_DIR)/tab_2d_char_essential.c -o $(BIN_DIR)/tab_2d_char_essential.o

$(BIN_DIR)/position_2d_uint_pair.o: $(SRC_DIR)/position_2d_uint.h $(SRC_DIR)/position_2d_uint_pair.h $(SRC_DIR)/position_2d_uint_pair.c
	mkdir -p $(BIN_DIR)/
	$(CC) $(CFLAGS) -c $(SRC_DIR)/position_2d_uint_pair.c -o $(BIN_DIR)/position_2d_uint_pair.o

$(BIN_DIR)/position_2d_uint.o: $(SRC_DIR)/position_2d_uint.h $(SRC_DIR)/position_2d_uint.c
	mkdir -p $(BIN_DIR)/
	$(CC) $(CFLAGS) -c $(SRC_DIR)/position_2d_uint.c -o $(BIN_DIR)/position_2d_uint.o

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
	$(RM) -rf -- \
		$(BIN_DIR)/ $(DOC_DIR)/ \
		*.o a.out *.exe *.msi *.dmg \
		*.zip *.tar.* *.7z \
		*~ .\#*# \#*# *.bak $(SRC_DIR)/*~
