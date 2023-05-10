all: compile
.PHONY: all

generate:
	ragel -n -p -o mailbox.c mailbox.rl 
.PHONY: generate

compile: generate
	g++ mailbox.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
