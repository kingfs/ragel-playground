
#line 1 "concurrent.rl"
/*
 * Show off concurrent abilities.
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#define BUFSIZE 2048

struct Concurrent
{
	int cur_char;
	int start_word;
	int start_comment;
	int start_literal;

	int cs;

	int init( );
	int execute( const char *data, int len, bool isEof );
	int finish( );
};


#line 75 "concurrent.rl"



#line 35 "concurrent.c"
static const char _Concurrent_actions[] = {
	0, 1, 0, 1, 2, 2, 0, 1, 
	2, 0, 2, 2, 0, 3, 2, 0, 
	4, 2, 0, 5, 2, 0, 6, 2, 
	2, 4, 2, 2, 6, 3, 0, 1, 
	3, 3, 0, 1, 5, 3, 0, 2, 
	4, 3, 0, 2, 6, 3, 0, 3, 
	6, 3, 0, 4, 3, 3, 0, 4, 
	5, 3, 0, 6, 5
};

static const unsigned char _Concurrent_key_offsets[] = {
	0, 5, 10, 15, 20, 26, 32, 38, 
	44, 49, 55, 62, 68, 74, 80, 86, 
	91, 96, 101, 106, 112, 119, 125, 129, 
	135, 141, 146, 152, 157, 163, 168, 175, 
	179, 186, 190, 196, 202, 207, 214, 218, 
	225, 231, 237
};

static const char _Concurrent_trans_keys[] = {
	32, 39, 47, 9, 13, 32, 39, 47, 
	9, 13, 32, 39, 47, 9, 13, 32, 
	39, 47, 9, 13, 32, 39, 47, 92, 
	9, 13, 32, 39, 47, 92, 9, 13, 
	32, 39, 47, 92, 9, 13, 32, 39, 
	47, 92, 9, 13, 32, 39, 47, 9, 
	13, 32, 39, 47, 92, 9, 13, 32, 
	39, 42, 47, 92, 9, 13, 32, 39, 
	42, 92, 9, 13, 32, 39, 42, 92, 
	9, 13, 32, 39, 42, 92, 9, 13, 
	32, 39, 42, 92, 9, 13, 32, 39, 
	42, 9, 13, 32, 39, 42, 9, 13, 
	32, 39, 42, 9, 13, 32, 39, 42, 
	9, 13, 32, 39, 42, 92, 9, 13, 
	32, 39, 42, 47, 92, 9, 13, 32, 
	39, 47, 92, 9, 13, 32, 47, 9, 
	13, 32, 39, 47, 92, 9, 13, 32, 
	39, 47, 92, 9, 13, 32, 39, 47, 
	9, 13, 32, 39, 42, 47, 9, 13, 
	32, 39, 42, 9, 13, 32, 39, 42, 
	47, 9, 13, 32, 39, 47, 9, 13, 
	32, 39, 42, 47, 92, 9, 13, 32, 
	47, 9, 13, 32, 39, 42, 47, 92, 
	9, 13, 32, 42, 9, 13, 32, 39, 
	42, 92, 9, 13, 32, 39, 42, 92, 
	9, 13, 32, 39, 42, 9, 13, 32, 
	39, 42, 47, 92, 9, 13, 32, 42, 
	9, 13, 32, 39, 42, 47, 92, 9, 
	13, 32, 39, 42, 92, 9, 13, 32, 
	39, 42, 47, 9, 13, 32, 39, 42, 
	47, 9, 13, 0
};

static const char _Concurrent_single_lengths[] = {
	3, 3, 3, 3, 4, 4, 4, 4, 
	3, 4, 5, 4, 4, 4, 4, 3, 
	3, 3, 3, 4, 5, 4, 2, 4, 
	4, 3, 4, 3, 4, 3, 5, 2, 
	5, 2, 4, 4, 3, 5, 2, 5, 
	4, 4, 4
};

static const char _Concurrent_range_lengths[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1
};

static const short _Concurrent_index_offsets[] = {
	0, 5, 10, 15, 20, 26, 32, 38, 
	44, 49, 55, 62, 68, 74, 80, 86, 
	91, 96, 101, 106, 112, 119, 125, 129, 
	135, 141, 146, 152, 157, 163, 168, 175, 
	179, 186, 190, 196, 202, 207, 214, 218, 
	225, 231, 237
};

static const char _Concurrent_indicies[] = {
	1, 2, 3, 1, 0, 5, 6, 7, 
	5, 4, 5, 6, 7, 5, 4, 1, 
	2, 3, 1, 0, 9, 10, 11, 12, 
	9, 8, 9, 10, 11, 12, 9, 8, 
	14, 15, 16, 17, 14, 13, 9, 10, 
	11, 12, 9, 8, 19, 20, 21, 19, 
	18, 9, 10, 11, 12, 9, 8, 9, 
	10, 22, 11, 12, 9, 8, 24, 25, 
	26, 27, 24, 23, 24, 25, 26, 27, 
	24, 23, 29, 30, 31, 32, 29, 28, 
	24, 25, 26, 27, 24, 23, 34, 35, 
	36, 34, 33, 38, 39, 40, 38, 37, 
	42, 43, 44, 42, 41, 38, 39, 40, 
	38, 37, 24, 25, 26, 27, 24, 23, 
	24, 25, 26, 45, 27, 24, 23, 47, 
	48, 49, 50, 47, 46, 52, 53, 52, 
	51, 9, 10, 11, 12, 9, 8, 14, 
	15, 16, 17, 14, 13, 19, 20, 21, 
	19, 18, 5, 6, 54, 7, 5, 4, 
	38, 39, 40, 38, 37, 38, 39, 40, 
	55, 38, 37, 57, 58, 59, 57, 56, 
	9, 10, 22, 11, 12, 9, 8, 52, 
	53, 52, 51, 9, 10, 22, 11, 12, 
	9, 8, 61, 62, 61, 60, 24, 25, 
	26, 27, 24, 23, 29, 30, 31, 32, 
	29, 28, 34, 35, 36, 34, 33, 24, 
	25, 26, 45, 27, 24, 23, 61, 62, 
	61, 60, 24, 25, 26, 45, 27, 24, 
	23, 24, 25, 26, 27, 24, 23, 38, 
	39, 40, 55, 38, 37, 5, 6, 54, 
	7, 5, 4, 0
};

static const char _Concurrent_trans_targs[] = {
	1, 3, 4, 42, 2, 3, 9, 26, 
	5, 6, 8, 10, 22, 7, 6, 25, 
	30, 31, 2, 3, 9, 26, 11, 12, 
	13, 15, 20, 33, 14, 13, 36, 37, 
	38, 16, 17, 19, 28, 16, 17, 19, 
	28, 18, 17, 40, 41, 21, 5, 6, 
	8, 10, 22, 23, 24, 32, 27, 29, 
	2, 3, 9, 26, 34, 35, 39
};

static const char _Concurrent_trans_actions[] = {
	5, 1, 33, 29, 1, 8, 17, 11, 
	1, 8, 1, 11, 1, 5, 1, 5, 
	29, 5, 20, 41, 57, 45, 1, 1, 
	8, 1, 1, 1, 5, 1, 5, 5, 
	5, 20, 41, 57, 20, 1, 8, 17, 
	1, 5, 1, 33, 5, 1, 14, 37, 
	14, 49, 14, 1, 8, 11, 1, 1, 
	14, 37, 53, 49, 1, 8, 1
};

static const char _Concurrent_eof_actions[] = {
	0, 3, 3, 0, 3, 3, 0, 3, 
	26, 3, 3, 3, 3, 0, 3, 26, 
	3, 0, 3, 3, 3, 23, 3, 3, 
	0, 26, 3, 3, 3, 23, 3, 3, 
	3, 3, 3, 0, 26, 3, 3, 3, 
	3, 3, 3
};

static const int Concurrent_start = 0;
static const int Concurrent_first_final = 0;
static const int Concurrent_error = -1;

static const int Concurrent_en_main = 0;


#line 78 "concurrent.rl"

int Concurrent::init( )
{
	
#line 194 "concurrent.c"
	{
	cs = Concurrent_start;
	}

#line 82 "concurrent.rl"
	cur_char = 0;
	return 1;
}

int Concurrent::execute( const char *data, int len, bool isEof )
{
	const char *p = data;
	const char *pe = data + len;
	const char *eof = isEof ? pe : 0;

	
#line 211 "concurrent.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
_resume:
	_keys = _Concurrent_trans_keys + _Concurrent_key_offsets[cs];
	_trans = _Concurrent_index_offsets[cs];

	_klen = _Concurrent_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _Concurrent_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
	_trans = _Concurrent_indicies[_trans];
	cs = _Concurrent_trans_targs[_trans];

	if ( _Concurrent_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _Concurrent_actions + _Concurrent_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 30 "concurrent.rl"
	{
		cur_char += 1;
	}
	break;
	case 1:
#line 34 "concurrent.rl"
	{
		start_word = cur_char;
	}
	break;
	case 2:
#line 37 "concurrent.rl"
	{
		cout << "word: " << start_word << 
				" " << cur_char-1 << endl;
	}
	break;
	case 3:
#line 42 "concurrent.rl"
	{
		start_comment = cur_char;
	}
	break;
	case 4:
#line 45 "concurrent.rl"
	{
		cout << "comment: " << start_comment <<
				" " << cur_char-1 << endl;
	}
	break;
	case 5:
#line 50 "concurrent.rl"
	{
		start_literal = cur_char;
	}
	break;
	case 6:
#line 53 "concurrent.rl"
	{
		cout << "literal: " << start_literal <<
				" " << cur_char-1 << endl;
	}
	break;
#line 328 "concurrent.c"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _Concurrent_actions + _Concurrent_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 2:
#line 37 "concurrent.rl"
	{
		cout << "word: " << start_word << 
				" " << cur_char-1 << endl;
	}
	break;
	case 4:
#line 45 "concurrent.rl"
	{
		cout << "comment: " << start_comment <<
				" " << cur_char-1 << endl;
	}
	break;
	case 6:
#line 53 "concurrent.rl"
	{
		cout << "literal: " << start_literal <<
				" " << cur_char-1 << endl;
	}
	break;
#line 363 "concurrent.c"
		}
	}
	}

	}

#line 93 "concurrent.rl"

	if ( cs == Concurrent_error )
		return -1;
	if ( cs >= Concurrent_first_final )
		return 1;
	return 0;
}

int Concurrent::finish( )
{
	if ( cs == Concurrent_error )
		return -1;
	if ( cs >= Concurrent_first_final )
		return 1;
	return 0;
}

Concurrent concurrent;
char buf[BUFSIZE];

int main()
{
	concurrent.init();
	while ( 1 ) {
		int len = fread( buf, 1, BUFSIZE, stdin );
		concurrent.execute( buf, len, len != BUFSIZE );
		if ( len != BUFSIZE )
			break;
	}

	if ( concurrent.finish() <= 0 )
		cerr << "concurrent: error parsing input" << endl;
	return 0;
}
