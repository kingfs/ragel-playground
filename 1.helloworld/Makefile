all: compile
.PHONY: all

generate:
	ragel -n -p -o helloworld.c helloworld.rl 
.PHONY: generate

compile: generate
	gcc helloworld.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
