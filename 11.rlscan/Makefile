all: compile
.PHONY: all

generate:
	ragel -n -p -o rlscan.c rlscan.rl 
.PHONY: generate

compile: generate
	g++ rlscan.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
