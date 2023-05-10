all: compile
.PHONY: all

generate:
	ragel -n -p -o params.c params.rl 
.PHONY: generate

compile: generate
	g++ params.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
