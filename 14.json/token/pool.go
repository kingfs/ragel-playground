package token

const DefaultBlockSize = 1024

type Pool struct {
	block []Token
	off   int
}

func NewPool(blockSize int) *Pool {
	return &Pool{
		block: make([]Token, blockSize),
	}
}

func (p *Pool) ResizeBlock() {
	newBlock := make([]Token, len(p.block))
	p.block = append(p.block, newBlock...)
}

func (p *Pool) GenBlock() *Token {
	if len(p.block) == 0 {
		return nil
	}

	if len(p.block) == p.off {
		p.ResizeBlock()
	}

	p.off += 1

	return &p.block[p.off - 1]
}
