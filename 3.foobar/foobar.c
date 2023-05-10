
#line 1 "foobar.rl"
#include <string.h>
#include <stdio.h>

// python -c "print(ord('f'),ord('0'),ord('a'),ord('r'),ord('b'))"
// 102 48 97 114 98

#line 9 "foobar.rl"



#line 14 "foobar.c"
static const char _foo_actions[] = {
	0, 1, 0
};

static const char _foo_key_offsets[] = {
	0, 0, 2, 3, 4, 5, 6, 7, 
	8
};

static const char _foo_trans_keys[] = {
	98, 102, 97, 114, 0, 111, 111, 0, 
	0
};

static const char _foo_single_lengths[] = {
	0, 2, 1, 1, 1, 1, 1, 1, 
	0
};

static const char _foo_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0
};

static const char _foo_index_offsets[] = {
	0, 0, 3, 5, 7, 9, 11, 13, 
	15
};

static const char _foo_trans_targs[] = {
	2, 5, 0, 3, 0, 4, 0, 8, 
	0, 6, 0, 7, 0, 8, 0, 0, 
	0
};

static const char _foo_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 1, 
	0, 0, 0, 0, 0, 1, 0, 0, 
	0
};

static const int foo_start = 1;
static const int foo_first_final = 8;
static const int foo_error = 0;

static const int foo_en_main = 1;


#line 12 "foobar.rl"

int main( int argc, char **argv )
{
    int cs, res = 0;
    if ( argc > 1 ) {
        char *p = argv[1];
        char *pe = p + strlen(p) + 1;
        
#line 72 "foobar.c"
	{
	cs = foo_start;
	}

#line 20 "foobar.rl"
        
#line 79 "foobar.c"
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
	_keys = _foo_trans_keys + _foo_key_offsets[cs];
	_trans = _foo_index_offsets[cs];

	_klen = _foo_single_lengths[cs];
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

	_klen = _foo_range_lengths[cs];
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
	cs = _foo_trans_targs[_trans];

	if ( _foo_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _foo_actions + _foo_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 8 "foobar.rl"
	{ res = 1; }
	break;
#line 156 "foobar.c"
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

#line 21 "foobar.rl"
    }
    printf("result = %i\n", res );
    return 0;
}