package scanner

import (
	"main/config"
	"main/stack"
	"main/token"
)

type JsonLexer struct {
	data []byte

	p, pe, cs   int
	ts, te, act int
	top         int
	stack       []int

	notInArray      bool
	bracketStack int
	braceStack   int
	stacks       *stack.Stack

	tokenPool token.Pool
}

func NewLexer(data []byte, config config.Config) *JsonLexer {
	lexer := JsonLexer{
		data:  data,
		top:   0,
		pe:    len(data),
		stack: make([]int, 10),

		bracketStack: 0,
		braceStack:   0,

		stacks:    stack.NewStack(),
		tokenPool: *token.NewPool(config.PoolSize),
	}

	lexer.initJsonLexer()

	return &lexer
}

func (lex *JsonLexer) isNotInArrayParse() bool {
	return lex.notInArray
}

func (lex *JsonLexer) growCallStack() {
	if lex.top == len(lex.stack) {
		lex.stack = append(lex.stack, 0)
	}
}

func (lex *JsonLexer) addSubToken(tkn *token.Token, id token.ID, start, end int) {
	newToken := lex.tokenPool.GenBlock()

	newToken.ID = id
	newToken.Value = lex.data[start:end]

	if lex.bracketStack > 1 {
		parent := lex.stacks.Peak().(token.StackToken)
		parent.Token.SubTokens = append(parent.Token.SubTokens, *newToken)
	} else {
		tkn.SubTokens = append(tkn.SubTokens, *newToken)
	}
}

func (lex *JsonLexer) addSubTokenValue(tkn *token.Token, id token.ID, value string) {
	newToken := lex.tokenPool.GenBlock()

	newToken.ID = id
	newToken.Value = []byte(value)

	if lex.bracketStack > 1 {
		parent := lex.stacks.Peak().(token.StackToken)
		parent.Token.SubTokens = append(parent.Token.SubTokens, *newToken)
	} else {
		tkn.SubTokens = append(tkn.SubTokens, *newToken)
	}
}

func (lex *JsonLexer) pushSubTokenStack(id token.ID, start int) {
	newToken := lex.tokenPool.GenBlock()
	newToken.ID = id

	st := token.StackToken{
		Start: start,
		Token: newToken,
	}

	lex.stacks.Push(st)
}

func (lex *JsonLexer) popSubTokenStack(tkn *token.Token, end int) {
	if lex.stacks.Len() == 0 {
		return
	}

	st := lex.stacks.Pop().(token.StackToken)
	newToken := st.Token
	newToken.Value = lex.data[st.Start:end]

	if lex.bracketStack > 1 {
		parent := lex.stacks.Peak().(token.StackToken)
		parent.Token.SubTokens = append(parent.Token.SubTokens, *newToken)
	} else {
		tkn.SubTokens = append(tkn.SubTokens, *newToken)
	}
}
