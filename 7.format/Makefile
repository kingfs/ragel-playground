all: compile
.PHONY: all

generate:
	ragel -n -p -o format.c format.rl 
.PHONY: generate

compile: generate
	g++ format.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
