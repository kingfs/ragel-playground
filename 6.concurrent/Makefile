all: compile
.PHONY: all

generate:
	ragel -n -p -o concurrent.c concurrent.rl 
.PHONY: generate

compile: generate
	g++ concurrent.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
