SRC_DIR=src
BIN_DIR=bin
GCC=gcc

FILE=doubleHashing

.PHONY: clean

# This is the default task
compile:
	@ mkdir -p $(BIN_DIR)
	@ $(GCC) $(SRC_DIR)/$(FILE).c -o $(BIN_DIR)/$(FILE)
	
clean:
	@ echo Cleaning...
	rm -rf $(BIN_DIR)/
	find . -name  *.*~ -print0 | xargs -0 rm -rf
	find . -name  *~ -print0 | xargs -0 rm -rf
	@ echo
