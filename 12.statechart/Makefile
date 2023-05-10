all: compile
.PHONY: all

generate:
	ragel -n -p -o statechart.c statechart.rl 
.PHONY: generate

compile: generate
	g++ statechart.c
.PHONY: compile

clean:
	rm -rf a.out
.PHONY: clean
