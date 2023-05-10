.DEFAULT_GOAL:=help
SHELL:=/bin/bash
TARGET:=stats_char_in_string

.PHONY: help generate compile test clean

help:  ## Display this help
	@awk 'BEGIN {FS = ":.*##"; printf "Usage:\n  make \033[36m\033[0m\n\nTargets:\n"} /^[a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2 }' $(MAKEFILE_LIST)

generate:	## generate c file from ragel file
	ragel -o $(TARGET).c $(TARGET).rl -G2

compile: generate	## build binary
	gcc $(TARGET).c -o $(TARGET)

test: compile	## test run
	./$(TARGET) < test.case

clean:	## clean artifacts
	rm -rf $(TARGET) $(TARGET).c

gitignore:	## generate ignore file
	echo -e "$(TARGET)\n$(TARGET).c" > .gitignore