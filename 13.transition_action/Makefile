all: compile
.PHONY: all

generate:
	ragel -n -p -o transition_action.c transition_action.rl 
.PHONY: generate

compile: generate
	gcc transition_action.c
.PHONY: compile

compile_g2:
	ragel -G2 -p -o transition_action.c transition_action.rl 
	gcc transition_action.c
.PHONY: compile_g2


clean:
	rm -rf a.out
.PHONY: clean
