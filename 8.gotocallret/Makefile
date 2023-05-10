all: compile
.PHONY: all

generate:
	ragel -n -p -o gotocallret.c gotocallret.rl 
.PHONY: generate

compile: generate
	g++ gotocallret.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
