all: compile
.PHONY: all

generate:
	ragel -n -p -o clang.c clang.rl 
.PHONY: generate

compile: generate
	gcc clang.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
