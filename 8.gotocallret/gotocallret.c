
#line 1 "gotocallret.rl"
/*
 * Demonstrate the use of goto, call and return. This machine expects either a
 * lower case char or a digit as a command then a space followed by the command
 * arg. If the command is a char, then the arg must be an a string of chars.
 * If the command is a digit, then the arg must be a string of digits. This
 * choice is determined by action code, rather than though transition
 * desitinations.
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct GotoCallRet 
{
	char comm;
	int cs, top, stack[32];

	int init( );
	int execute( const char *data, int len, bool isEof );
	int finish( );
};


#line 57 "gotocallret.rl"



#line 35 "gotocallret.c"
static const char _GotoCallRet_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 2, 0, 1
};

static const char _GotoCallRet_key_offsets[] = {
	0, 0, 1, 2, 3, 4, 8, 10, 
	14, 18, 18, 22, 26, 28
};

static const char _GotoCallRet_trans_keys[] = {
	32, 10, 10, 10, 65, 90, 97, 122, 
	48, 57, 48, 57, 97, 122, 48, 57, 
	97, 122, 65, 90, 97, 122, 65, 90, 
	97, 122, 48, 57, 48, 57, 0
};

static const char _GotoCallRet_single_lengths[] = {
	0, 1, 1, 1, 1, 0, 0, 0, 
	0, 0, 0, 0, 0, 0
};

static const char _GotoCallRet_range_lengths[] = {
	0, 0, 0, 0, 0, 2, 1, 2, 
	2, 0, 2, 2, 1, 1
};

static const char _GotoCallRet_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 11, 13, 
	16, 19, 20, 23, 26, 28
};

static const char _GotoCallRet_trans_targs[] = {
	2, 0, 8, 0, 9, 4, 9, 4, 
	10, 10, 0, 12, 0, 1, 1, 0, 
	1, 1, 0, 0, 11, 11, 0, 11, 
	11, 0, 13, 0, 13, 0, 0
};

static const char _GotoCallRet_trans_actions[] = {
	9, 15, 13, 15, 17, 1, 3, 0, 
	0, 0, 5, 0, 7, 11, 11, 15, 
	11, 11, 15, 0, 0, 0, 5, 0, 
	0, 5, 0, 7, 0, 7, 0
};

static const char _GotoCallRet_eof_actions[] = {
	0, 15, 15, 0, 0, 5, 7, 0, 
	0, 0, 0, 0, 0, 0
};

static const int GotoCallRet_start = 7;
static const int GotoCallRet_first_final = 7;
static const int GotoCallRet_error = 0;

static const int GotoCallRet_en_garble_line = 3;
static const int GotoCallRet_en_alp_comm = 5;
static const int GotoCallRet_en_dig_comm = 6;
static const int GotoCallRet_en_main = 7;


#line 60 "gotocallret.rl"

int GotoCallRet::init( )
{
	
#line 103 "gotocallret.c"
	{
	cs = GotoCallRet_start;
	top = 0;
	}

#line 64 "gotocallret.rl"
	return 1;
}

int GotoCallRet::execute( const char *data, int len, bool isEof )
{
	const char *p = data;
	const char *pe = data + len;
	const char *eof = isEof ? pe : 0;

	
#line 120 "gotocallret.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_keys = _GotoCallRet_trans_keys + _GotoCallRet_key_offsets[cs];
	_trans = _GotoCallRet_index_offsets[cs];

	_klen = _GotoCallRet_single_lengths[cs];
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

	_klen = _GotoCallRet_range_lengths[cs];
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
	cs = _GotoCallRet_trans_targs[_trans];

	if ( _GotoCallRet_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _GotoCallRet_actions + _GotoCallRet_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 34 "gotocallret.rl"
	{cout << "error: garbling line" << endl;}
	break;
	case 1:
#line 34 "gotocallret.rl"
	{{cs = 7;goto _again;}}
	break;
	case 2:
#line 38 "gotocallret.rl"
	{p--;{cs = stack[--top]; goto _again;}}
	break;
	case 3:
#line 39 "gotocallret.rl"
	{p--;{cs = stack[--top]; goto _again;}}
	break;
	case 4:
#line 42 "gotocallret.rl"
	{
		if ( comm >= 'a' )
			{stack[top++] = cs; cs = 5;goto _again;}
		else 
			{stack[top++] = cs; cs = 6;goto _again;}
	}
	break;
	case 5:
#line 51 "gotocallret.rl"
	{comm = (*p);}
	break;
	case 6:
#line 52 "gotocallret.rl"
	{cout << "correct command" << endl;}
	break;
	case 7:
#line 56 "gotocallret.rl"
	{p--;{cs = 3;goto _again;}}
	break;
#line 230 "gotocallret.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _GotoCallRet_actions + _GotoCallRet_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 2:
#line 38 "gotocallret.rl"
	{p--;{cs = stack[--top]; 	if ( p == pe )
		goto _test_eof;
goto _again;}}
	break;
	case 3:
#line 39 "gotocallret.rl"
	{p--;{cs = stack[--top]; 	if ( p == pe )
		goto _test_eof;
goto _again;}}
	break;
	case 7:
#line 56 "gotocallret.rl"
	{p--;{cs = 3;	if ( p == pe )
		goto _test_eof;
goto _again;}}
	break;
#line 264 "gotocallret.c"
		}
	}
	}

	_out: {}
	}

#line 74 "gotocallret.rl"
	if ( cs == GotoCallRet_error )
		return -1;
	if ( cs >= GotoCallRet_first_final )
		return 1;
	return 0;
}

#define BUFSIZE 1024

int main()
{
	char buf[BUFSIZE];

	GotoCallRet gcr;
	gcr.init();
	while ( fgets( buf, sizeof(buf), stdin ) != 0 )
		gcr.execute( buf, strlen(buf), false );

	gcr.execute( 0, 0, true );
	if ( gcr.cs < GotoCallRet_first_final )
		cerr << "gotocallret: error: parsing input" << endl;
	return 0;
}
