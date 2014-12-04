SRC_DIR=src
INC_DIR=includes
BIN_DIR=bin
DOC_DIR=doc

CC=gcc
INCLUDES=-I./$(INC_DIR)
DEBUG_FLAGS= #-g
CFLAGS=-std=c99 -Wall $(INCLUDES) $(DEBUG_FLAGS)

PACKAGE=halma-game
FILES_TO_ARCHIVE=$(SRC_DIR)/ $(INC_DIR)/ makefile doxygen_config.ini LICENSE* README.md


.PHONY: $(DOC_DIR)


all: # TODO

# TODO


$(DOC_DIR): $(INC_DIR)/*.h $(SRC_DIR)/*.c doxygen_config.ini
	doxygen doxygen_config.ini
	mkdir -p $(DOC_DIR)/
	cd $(DOC_DIR)/latex/ && make

zip: $(FILES_TO_ARCHIVE)
	zip $(PACKAGE).zip -r -- $(FILES_TO_ARCHIVE)

tar-gz: $(FILES_TO_ARCHIVE)
	tar -zcvf $(PACKAGE).tar.gz $(FILES_TO_ARCHIVE)

tar-bz2: $(FILES_TO_ARCHIVE)
	tar -jcvf $(PACKAGE).tar.bz2 $(FILES_TO_ARCHIVE)

clean:
	rm -rf -- $(BIN_DIR)/ $(DOC_DIR)/ *.zip *.tar.*  *~ \#*# *.bak $(SRC_DIR)/*~ $(SRC_DIR)/*.bak
