all: compile
.PHONY: all

generate:
	ragel -n -p -o atoi.c atoi.rl 
.PHONY: generate

compile: generate
	gcc atoi.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
