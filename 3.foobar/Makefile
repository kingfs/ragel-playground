all: compile
.PHONY: all

generate:
	ragel -n -p -o foobar.c foobar.rl 
.PHONY: generate

compile: generate
	gcc foobar.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
