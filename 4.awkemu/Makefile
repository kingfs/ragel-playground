all: compile
.PHONY: all

generate:
	ragel -n -p -o awkemu.c awkemu.rl 
.PHONY: generate

compile: generate
	gcc awkemu.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
