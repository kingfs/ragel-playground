.DEFAULT_GOAL:=help
SHELL:=/bin/bash
FILE:=json
TARGET:=json_parser

.PHONY: help generate compile test clean

help:  ## Display this help
	@awk 'BEGIN {FS = ":.*##"; printf "Usage:\n  make \033[36m\033[0m\n\nTargets:\n"} /^[a-zA-Z_-]+:.*?##/ { printf "  \033[36m%-10s\033[0m %s\n", $$1, $$2 }' $(MAKEFILE_LIST)

generate:	## generate c file from ragel file
	ragel -o ./scanner/$(FILE).go -Z ./scanner/$(FILE).rl

compile: generate	## build binary
	go mod tidy && go build -o release/$(TARGET) ./main.go

test: compile	## test run
	./release/$(TARGET) -f test.json

clean:	## clean artifacts
	rm -rf ./release/$(TARGET)

gitignore:	## generate ignore file
	echo -e "./release/$(TARGET)\n" > .gitignore
