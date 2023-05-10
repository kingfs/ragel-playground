
#line 1 "statechart.rl"
/*
 * Demonstrate the use of labels, the epsilon operator, and the join operator
 * for creating machines using the named state and transition list paradigm.
 * This implementes the same machine as the atoi example.
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

struct StateChart
{
	bool neg;
	int val;
	int cs;

	int init( );
	int execute( const char *data, int len );
	int finish( );
};


#line 66 "statechart.rl"



#line 33 "statechart.c"
static const char _StateChart_actions[] = {
	0, 1, 0, 1, 2, 2, 0, 1, 
	2, 0, 2, 2, 3, 4
};

static const char _StateChart_key_offsets[] = {
	0, 0, 2, 5, 7, 10, 13, 17
};

static const char _StateChart_trans_keys[] = {
	48, 57, 10, 48, 57, 48, 57, 10, 
	48, 57, 10, 48, 57, 43, 45, 48, 
	57, 43, 45, 48, 57, 0
};

static const char _StateChart_single_lengths[] = {
	0, 0, 1, 0, 1, 1, 2, 2
};

static const char _StateChart_range_lengths[] = {
	0, 1, 1, 1, 1, 1, 1, 1
};

static const char _StateChart_index_offsets[] = {
	0, 0, 2, 5, 7, 10, 13, 17
};

static const char _StateChart_indicies[] = {
	0, 1, 2, 3, 1, 0, 1, 2, 
	3, 1, 2, 3, 1, 4, 5, 6, 
	1, 4, 5, 6, 1, 0
};

static const char _StateChart_trans_targs[] = {
	2, 0, 7, 5, 1, 3, 4
};

static const char _StateChart_trans_actions[] = {
	3, 0, 11, 3, 1, 5, 8
};

static const int StateChart_start = 6;
static const int StateChart_first_final = 6;
static const int StateChart_error = 0;

static const int StateChart_en_main = 6;


#line 69 "statechart.rl"

int StateChart::init( )
{
	neg = false;
	val = false;
	
#line 89 "statechart.c"
	{
	cs = StateChart_start;
	}

#line 75 "statechart.rl"
	return 1;
}

int StateChart::execute( const char *data, int len )
{
	const char *p = data;
	const char *pe = data + len;

	
#line 104 "statechart.c"
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
	_keys = _StateChart_trans_keys + _StateChart_key_offsets[cs];
	_trans = _StateChart_index_offsets[cs];

	_klen = _StateChart_single_lengths[cs];
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

	_klen = _StateChart_range_lengths[cs];
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
	_trans = _StateChart_indicies[_trans];
	cs = _StateChart_trans_targs[_trans];

	if ( _StateChart_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _StateChart_actions + _StateChart_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 28 "statechart.rl"
	{
		neg = false;
		val = 0;
	}
	break;
	case 1:
#line 33 "statechart.rl"
	{
		neg = true;
	}
	break;
	case 2:
#line 37 "statechart.rl"
	{ 
		val = val * 10 + ((*p) - '0');
	}
	break;
	case 3:
#line 41 "statechart.rl"
	{
		if ( neg )
			val = -1 * val;
	}
	break;
	case 4:
#line 65 "statechart.rl"
	{ cout << val << endl; }
	break;
#line 208 "statechart.c"
		}
	}

_again:
	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 84 "statechart.rl"

	if ( cs == StateChart_error )
		return -1;
	if ( cs >= StateChart_first_final )
		return 1;
	return 0;
}

int StateChart::finish( )
{
	if ( cs == StateChart_error )
		return -1;
	if ( cs >= StateChart_first_final )
		return 1;
	return 0;
}


#define BUFSIZE 1024

int main()
{
	char buf[BUFSIZE];

	StateChart atoi;
	atoi.init();
	while ( fgets( buf, sizeof(buf), stdin ) != 0 ) {
		atoi.execute( buf, strlen(buf) );
	}
	if ( atoi.finish() <= 0 )
		cerr << "statechart: error: parsing input" << endl;
	return 0;
}
