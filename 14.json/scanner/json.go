
//line ./scanner/json.rl:1
package scanner

import (
    "main/token"
)


//line ./scanner/json.go:11
var _json_lexer_actions []byte = []byte{
	0, 1, 0, 1, 2, 1, 3, 1, 5, 
	1, 6, 1, 7, 1, 8, 1, 9, 
	1, 10, 1, 11, 1, 12, 1, 13, 
	1, 14, 1, 15, 1, 17, 1, 18, 
	1, 19, 1, 20, 1, 21, 1, 22, 
	1, 23, 1, 24, 1, 25, 1, 26, 
	1, 27, 1, 28, 1, 29, 1, 30, 
	1, 31, 1, 32, 1, 33, 1, 34, 
	1, 35, 1, 36, 1, 37, 2, 0, 
	1, 2, 3, 4, 2, 3, 16, 
}

var _json_lexer_key_offsets []int16 = []int16{
	0, 0, 5, 14, 20, 26, 32, 38, 
	41, 43, 47, 49, 50, 51, 52, 53, 
	54, 55, 56, 57, 58, 59, 64, 73, 
	79, 85, 91, 97, 100, 102, 106, 108, 
	109, 110, 111, 112, 113, 114, 115, 116, 
	117, 118, 123, 128, 137, 143, 149, 155, 
	161, 164, 166, 170, 172, 173, 174, 176, 
	177, 178, 179, 180, 181, 182, 183, 184, 
	185, 196, 200, 202, 207, 224, 228, 232, 
	234, 239, 257, 261, 266, 270, 272, 
}

var _json_lexer_trans_keys []byte = []byte{
	34, 92, 127, 0, 31, 34, 47, 92, 
	98, 102, 110, 114, 116, 117, 48, 57, 
	65, 70, 97, 102, 48, 57, 65, 70, 
	97, 102, 48, 57, 65, 70, 97, 102, 
	48, 57, 65, 70, 97, 102, 46, 48, 
	57, 48, 57, 43, 45, 48, 57, 48, 
	57, 97, 108, 115, 101, 117, 108, 108, 
	114, 117, 10, 34, 92, 127, 0, 31, 
	34, 47, 92, 98, 102, 110, 114, 116, 
	117, 48, 57, 65, 70, 97, 102, 48, 
	57, 65, 70, 97, 102, 48, 57, 65, 
	70, 97, 102, 48, 57, 65, 70, 97, 
	102, 46, 48, 57, 48, 57, 43, 45, 
	48, 57, 48, 57, 97, 108, 115, 101, 
	117, 108, 108, 114, 117, 10, 34, 92, 
	127, 0, 31, 9, 32, 58, 11, 12, 
	34, 47, 92, 98, 102, 110, 114, 116, 
	117, 48, 57, 65, 70, 97, 102, 48, 
	57, 65, 70, 97, 102, 48, 57, 65, 
	70, 97, 102, 48, 57, 65, 70, 97, 
	102, 46, 48, 57, 48, 57, 43, 45, 
	48, 57, 48, 57, 42, 42, 42, 47, 
	97, 108, 115, 101, 117, 108, 108, 114, 
	117, 34, 43, 45, 46, 91, 102, 110, 
	116, 123, 48, 57, 69, 101, 48, 57, 
	48, 57, 46, 69, 101, 48, 57, 13, 
	32, 34, 44, 46, 91, 93, 102, 110, 
	116, 123, 9, 12, 43, 45, 48, 57, 
	13, 32, 9, 12, 69, 101, 48, 57, 
	48, 57, 46, 69, 101, 48, 57, 13, 
	32, 34, 44, 46, 47, 91, 102, 110, 
	116, 123, 125, 9, 12, 43, 45, 48, 
	57, 13, 32, 9, 12, 9, 32, 58, 
	11, 12, 69, 101, 48, 57, 48, 57, 
	46, 69, 101, 48, 57, 
}

var _json_lexer_single_lengths []byte = []byte{
	0, 3, 9, 0, 0, 0, 0, 1, 
	0, 2, 0, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 3, 9, 0, 
	0, 0, 0, 1, 0, 2, 0, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 3, 3, 9, 0, 0, 0, 0, 
	1, 0, 2, 0, 1, 1, 2, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	9, 2, 0, 3, 11, 2, 2, 0, 
	3, 12, 2, 3, 2, 0, 3, 
}

var _json_lexer_range_lengths []byte = []byte{
	0, 1, 0, 3, 3, 3, 3, 1, 
	1, 1, 1, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 1, 0, 3, 
	3, 3, 3, 1, 1, 1, 1, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 1, 1, 0, 3, 3, 3, 3, 
	1, 1, 1, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 1, 1, 1, 3, 1, 1, 1, 
	1, 3, 1, 1, 1, 1, 1, 
}

var _json_lexer_index_offsets []int16 = []int16{
	0, 0, 5, 15, 19, 23, 27, 31, 
	34, 36, 40, 42, 44, 46, 48, 50, 
	52, 54, 56, 58, 60, 62, 67, 77, 
	81, 85, 89, 93, 96, 98, 102, 104, 
	106, 108, 110, 112, 114, 116, 118, 120, 
	122, 124, 129, 134, 144, 148, 152, 156, 
	160, 163, 165, 169, 171, 173, 175, 178, 
	180, 182, 184, 186, 188, 190, 192, 194, 
	196, 207, 211, 213, 218, 233, 237, 241, 
	243, 248, 264, 268, 273, 277, 279, 
}

var _json_lexer_indicies []byte = []byte{
	2, 3, 1, 1, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 4, 1, 5, 
	5, 5, 1, 6, 6, 6, 1, 7, 
	7, 7, 1, 0, 0, 0, 1, 8, 
	9, 1, 10, 1, 12, 12, 13, 11, 
	13, 11, 14, 1, 15, 1, 16, 1, 
	17, 1, 18, 1, 19, 1, 20, 1, 
	21, 1, 16, 1, 23, 22, 25, 26, 
	1, 1, 24, 24, 24, 24, 24, 24, 
	24, 24, 24, 27, 1, 28, 28, 28, 
	1, 29, 29, 29, 1, 30, 30, 30, 
	1, 24, 24, 24, 1, 31, 32, 1, 
	33, 1, 35, 35, 36, 34, 36, 34, 
	37, 1, 38, 1, 39, 1, 40, 1, 
	41, 1, 42, 1, 43, 1, 44, 1, 
	39, 1, 46, 45, 48, 49, 1, 1, 
	47, 51, 51, 52, 51, 50, 47, 47, 
	47, 47, 47, 47, 47, 47, 53, 1, 
	54, 54, 54, 1, 55, 55, 55, 1, 
	56, 56, 56, 1, 47, 47, 47, 1, 
	57, 58, 1, 59, 1, 61, 61, 62, 
	60, 62, 60, 63, 1, 64, 63, 64, 
	65, 63, 66, 1, 67, 1, 68, 1, 
	69, 1, 70, 1, 71, 1, 72, 1, 
	73, 1, 68, 1, 0, 74, 74, 8, 
	75, 76, 77, 78, 79, 9, 1, 81, 
	81, 10, 80, 13, 80, 10, 81, 81, 
	9, 80, 82, 23, 24, 84, 31, 85, 
	86, 87, 88, 89, 90, 23, 83, 32, 
	1, 82, 23, 23, 91, 93, 93, 33, 
	92, 36, 92, 33, 93, 93, 32, 92, 
	94, 46, 47, 96, 57, 97, 98, 99, 
	100, 101, 102, 103, 46, 95, 58, 1, 
	94, 46, 46, 104, 51, 51, 52, 51, 
	105, 107, 107, 59, 106, 62, 106, 59, 
	107, 107, 58, 106, 
}

var _json_lexer_trans_targs []byte = []byte{
	1, 0, 64, 2, 3, 4, 5, 6, 
	8, 67, 65, 64, 10, 66, 12, 13, 
	14, 64, 16, 17, 64, 19, 68, 69, 
	21, 68, 22, 23, 24, 25, 26, 28, 
	72, 70, 68, 30, 71, 32, 33, 34, 
	68, 36, 37, 68, 39, 73, 74, 41, 
	75, 43, 73, 42, 73, 44, 45, 46, 
	47, 49, 78, 76, 73, 51, 77, 53, 
	54, 73, 56, 57, 58, 73, 60, 61, 
	73, 63, 7, 64, 11, 15, 18, 64, 
	64, 9, 20, 27, 68, 68, 68, 31, 
	35, 38, 68, 68, 68, 29, 40, 48, 
	73, 52, 73, 55, 59, 62, 73, 73, 
	73, 73, 73, 50, 
}

var _json_lexer_trans_actions []byte = []byte{
	0, 0, 57, 0, 0, 0, 0, 0, 
	0, 5, 5, 69, 0, 0, 0, 0, 
	0, 59, 0, 0, 61, 0, 27, 74, 
	0, 15, 0, 0, 0, 0, 0, 0, 
	5, 5, 25, 0, 0, 0, 0, 0, 
	17, 0, 0, 19, 0, 55, 77, 0, 
	5, 0, 53, 0, 39, 0, 0, 0, 
	0, 0, 5, 5, 51, 0, 0, 0, 
	0, 37, 0, 0, 0, 41, 0, 0, 
	43, 0, 0, 63, 0, 0, 0, 65, 
	67, 0, 0, 0, 11, 7, 9, 0, 
	0, 0, 13, 21, 23, 0, 0, 0, 
	35, 0, 33, 0, 0, 0, 29, 31, 
	45, 49, 47, 0, 
}

var _json_lexer_to_state_actions []byte = []byte{
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 0, 0, 0, 71, 0, 0, 0, 
	0, 71, 0, 0, 0, 0, 0, 
}

var _json_lexer_from_state_actions []byte = []byte{
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	3, 0, 0, 0, 3, 0, 0, 0, 
	0, 3, 0, 0, 0, 0, 0, 
}

var _json_lexer_eof_trans []int16 = []int16{
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 12, 12, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 23, 0, 0, 0, 
	0, 0, 0, 0, 0, 35, 35, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	46, 0, 51, 0, 0, 0, 0, 0, 
	0, 0, 61, 61, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 81, 81, 81, 0, 92, 93, 93, 
	93, 0, 105, 106, 107, 107, 107, 
}

const json_lexer_start int = 64
const json_lexer_first_final int = 64
const json_lexer_error int = 0

const json_lexer_en_j_array int = 68
const json_lexer_en_j_object int = 73
const json_lexer_en_main int = 64


//line ./scanner/json.rl:17


func (lex *JsonLexer) initJsonLexer() {
    
//line ./scanner/json.go:241
	{
	 lex.cs = json_lexer_start
	 lex.top = 0
	 lex.ts = 0
	 lex.te = 0
	 lex.act = 0
	}

//line ./scanner/json.rl:21
}

func (lex *JsonLexer) Lex() *token.Token {
    eof := lex.pe
    var tok token.ID
    tkn := lex.tokenPool.GenBlock()

    
//line ./scanner/json.go:259
	{
	var _klen int
	var _trans int
	var _acts int
	var _nacts uint
	var _keys int
	if ( lex.p) == ( lex.pe) {
		goto _test_eof
	}
	if  lex.cs == 0 {
		goto _out
	}
_resume:
	_acts = int(_json_lexer_from_state_actions[ lex.cs])
	_nacts = uint(_json_lexer_actions[_acts]); _acts++
	for ; _nacts > 0; _nacts-- {
		 _acts++
		switch _json_lexer_actions[_acts - 1] {
		case 2:
//line NONE:1
 lex.ts = ( lex.p)

//line ./scanner/json.go:282
		}
	}

	_keys = int(_json_lexer_key_offsets[ lex.cs])
	_trans = int(_json_lexer_index_offsets[ lex.cs])

	_klen = int(_json_lexer_single_lengths[ lex.cs])
	if _klen > 0 {
		_lower := int(_keys)
		var _mid int
		_upper := int(_keys + _klen - 1)
		for {
			if _upper < _lower {
				break
			}

			_mid = _lower + ((_upper - _lower) >> 1)
			switch {
			case  lex.data[( lex.p)] < _json_lexer_trans_keys[_mid]:
				_upper = _mid - 1
			case  lex.data[( lex.p)] > _json_lexer_trans_keys[_mid]:
				_lower = _mid + 1
			default:
				_trans += int(_mid - int(_keys))
				goto _match
			}
		}
		_keys += _klen
		_trans += _klen
	}

	_klen = int(_json_lexer_range_lengths[ lex.cs])
	if _klen > 0 {
		_lower := int(_keys)
		var _mid int
		_upper := int(_keys + (_klen << 1) - 2)
		for {
			if _upper < _lower {
				break
			}

			_mid = _lower + (((_upper - _lower) >> 1) & ^1)
			switch {
			case  lex.data[( lex.p)] < _json_lexer_trans_keys[_mid]:
				_upper = _mid - 2
			case  lex.data[( lex.p)] > _json_lexer_trans_keys[_mid + 1]:
				_lower = _mid + 2
			default:
				_trans += int((_mid - int(_keys)) >> 1)
				goto _match
			}
		}
		_trans += _klen
	}

_match:
	_trans = int(_json_lexer_indicies[_trans])
_eof_trans:
	 lex.cs = int(_json_lexer_trans_targs[_trans])

	if _json_lexer_trans_actions[_trans] == 0 {
		goto _again
	}

	_acts = int(_json_lexer_trans_actions[_trans])
	_nacts = uint(_json_lexer_actions[_acts]); _acts++
	for ; _nacts > 0; _nacts-- {
		_acts++
		switch _json_lexer_actions[_acts-1] {
		case 3:
//line NONE:1
 lex.te = ( lex.p)+1

		case 4:
//line ./scanner/json.rl:91
 lex.act = 5;
		case 5:
//line ./scanner/json.rl:72
 lex.te = ( lex.p)+1
{
                lex.notInArray = false
                lex.bracketStack += 1
                lex.pushSubTokenStack(token.J_ARRAY, lex.ts)
            }
		case 6:
//line ./scanner/json.rl:77
 lex.te = ( lex.p)+1
{
                lex.bracketStack -= 1
                lex.popSubTokenStack(tkn, lex.te)

                if lex.bracketStack == 0 {
                     lex.top--;  lex.cs =  lex.stack[ lex.top]
goto _again

                }
            }
		case 7:
//line ./scanner/json.rl:85
 lex.te = ( lex.p)+1
{ }
		case 8:
//line ./scanner/json.rl:86
 lex.te = ( lex.p)+1
{
                lex.braceStack += 1
                lex.pushSubTokenStack(token.J_OBJECT, lex.ts)
                { 
        lex.growCallStack()
     lex.stack[ lex.top] =  lex.cs;  lex.top++;  lex.cs = 73; goto _again
 }
            }
		case 9:
//line ./scanner/json.rl:93
 lex.te = ( lex.p)+1
{ lex.addSubToken(tkn, token.J_STRING, lex.ts, lex.te) }
		case 10:
//line ./scanner/json.rl:94
 lex.te = ( lex.p)+1
{ lex.addSubToken(tkn, token.J_BOOL, lex.ts, lex.te) }
		case 11:
//line ./scanner/json.rl:95
 lex.te = ( lex.p)+1
{ lex.addSubToken(tkn, token.J_NULL, lex.ts, lex.te) }
		case 12:
//line ./scanner/json.rl:91
 lex.te = ( lex.p)
( lex.p)--
{ }
		case 13:
//line ./scanner/json.rl:92
 lex.te = ( lex.p)
( lex.p)--
{ lex.addSubToken(tkn, token.J_NUMBER, lex.ts, lex.te) }
		case 14:
//line ./scanner/json.rl:92
( lex.p) = ( lex.te) - 1
{ lex.addSubToken(tkn, token.J_NUMBER, lex.ts, lex.te) }
		case 15:
//line NONE:1
	switch  lex.act {
	case 0:
	{ lex.cs = 0
goto _again
}
	case 5:
	{( lex.p) = ( lex.te) - 1
 }
	}
	
		case 16:
//line ./scanner/json.rl:123
 lex.act = 14;
		case 17:
//line ./scanner/json.rl:102
 lex.te = ( lex.p)+1
{
                lex.braceStack += 1
                lex.pushSubTokenStack(token.J_OBJECT, lex.ts)
            }
		case 18:
//line ./scanner/json.rl:106
 lex.te = ( lex.p)+1
{
                lex.braceStack -= 1
                lex.popSubTokenStack(tkn, lex.te-1)

                if lex.braceStack == 0 {
                     lex.top--;  lex.cs =  lex.stack[ lex.top]
goto _again

                }
            }
		case 19:
//line ./scanner/json.rl:114
 lex.te = ( lex.p)+1
{
                lex.notInArray = false
                lex.bracketStack += 1
                lex.pushSubTokenStack(token.J_ARRAY, lex.ts)
                { 
        lex.growCallStack()
     lex.stack[ lex.top] =  lex.cs;  lex.top++;  lex.cs = 68; goto _again
 }
            }
		case 20:
//line ./scanner/json.rl:120
 lex.te = ( lex.p)+1
{
                lex.popSubTokenStack(tkn, lex.te-1)
            }
		case 21:
//line ./scanner/json.rl:124
 lex.te = ( lex.p)+1
{
                lex.addSubToken(tkn, token.J_COMMENT, lex.ts, lex.te)
            }
		case 22:
//line ./scanner/json.rl:127
 lex.te = ( lex.p)+1
{
                lex.pushSubTokenStack(token.J_OBJECT_KEY_VALUE_PAIR, lex.ts)
                lex.notInArray = true
                { 
        lex.growCallStack()
     lex.stack[ lex.top] =  lex.cs;  lex.top++;  lex.cs = 73; goto _again
 }
            }
		case 23:
//line ./scanner/json.rl:134
 lex.te = ( lex.p)+1
{ lex.addSubToken(tkn, token.J_BOOL, lex.ts, lex.te) }
		case 24:
//line ./scanner/json.rl:135
 lex.te = ( lex.p)+1
{ lex.addSubToken(tkn, token.J_NULL, lex.ts, lex.te) }
		case 25:
//line ./scanner/json.rl:123
 lex.te = ( lex.p)
( lex.p)--
{ }
		case 26:
//line ./scanner/json.rl:132
 lex.te = ( lex.p)
( lex.p)--
{ lex.addSubToken(tkn, token.J_NUMBER, lex.ts, lex.te) }
		case 27:
//line ./scanner/json.rl:133
 lex.te = ( lex.p)
( lex.p)--
{ lex.addSubToken(tkn, token.J_STRING, lex.ts, lex.te) }
		case 28:
//line ./scanner/json.rl:132
( lex.p) = ( lex.te) - 1
{ lex.addSubToken(tkn, token.J_NUMBER, lex.ts, lex.te) }
		case 29:
//line ./scanner/json.rl:133
( lex.p) = ( lex.te) - 1
{ lex.addSubToken(tkn, token.J_STRING, lex.ts, lex.te) }
		case 30:
//line NONE:1
	switch  lex.act {
	case 0:
	{ lex.cs = 0
goto _again
}
	case 14:
	{( lex.p) = ( lex.te) - 1
 }
	}
	
		case 31:
//line ./scanner/json.rl:141
 lex.te = ( lex.p)+1
{ tok = token.J_STRING; ( lex.p)++; goto _out
 }
		case 32:
//line ./scanner/json.rl:142
 lex.te = ( lex.p)+1
{ tok = token.J_BOOL; ( lex.p)++; goto _out
 }
		case 33:
//line ./scanner/json.rl:143
 lex.te = ( lex.p)+1
{ tok = token.J_NULL; ( lex.p)++; goto _out
 }
		case 34:
//line ./scanner/json.rl:144
 lex.te = ( lex.p)+1
{
                tok = token.J_ARRAY
                lex.bracketStack += 1
                { 
        lex.growCallStack()
     lex.stack[ lex.top] =  lex.cs;  lex.top++;  lex.cs = 68; goto _again
 }
                ( lex.p)++; goto _out

            }
		case 35:
//line ./scanner/json.rl:150
 lex.te = ( lex.p)+1
{
                tok = token.J_OBJECT
                lex.braceStack += 1
                { 
        lex.growCallStack()
     lex.stack[ lex.top] =  lex.cs;  lex.top++;  lex.cs = 73; goto _again
 }
                ( lex.p)++; goto _out

            }
		case 36:
//line ./scanner/json.rl:140
 lex.te = ( lex.p)
( lex.p)--
{ tok = token.J_NUMBER; ( lex.p)++; goto _out
 }
		case 37:
//line ./scanner/json.rl:140
( lex.p) = ( lex.te) - 1
{ tok = token.J_NUMBER; ( lex.p)++; goto _out
 }
//line ./scanner/json.go:586
		}
	}

_again:
	_acts = int(_json_lexer_to_state_actions[ lex.cs])
	_nacts = uint(_json_lexer_actions[_acts]); _acts++
	for ; _nacts > 0; _nacts-- {
		_acts++
		switch _json_lexer_actions[_acts-1] {
		case 0:
//line NONE:1
 lex.ts = 0

		case 1:
//line NONE:1
 lex.act = 0

//line ./scanner/json.go:604
		}
	}

	if  lex.cs == 0 {
		goto _out
	}
	( lex.p)++
	if ( lex.p) != ( lex.pe) {
		goto _resume
	}
	_test_eof: {}
	if ( lex.p) == eof {
		if _json_lexer_eof_trans[ lex.cs] > 0 {
			_trans = int(_json_lexer_eof_trans[ lex.cs] - 1)
			goto _eof_trans
		}
	}

	_out: {}
	}

//line ./scanner/json.rl:159


    tkn.Value = lex.data[lex.ts:lex.te]
    tkn.ID = token.ID(tok)

    return tkn
}
