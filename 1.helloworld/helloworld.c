
#line 1 "helloworld.rl"
#include <stdio.h>
#include <string.h>


#line 8 "helloworld.c"
static const char _foo_key_offsets[] = {
	0, 0, 2, 4, 7, 9, 11
};

static const char _foo_trans_keys[] = {
	48, 57, 48, 57, 46, 48, 57, 48, 
	57, 48, 57, 46, 48, 57, 0
};

static const char _foo_single_lengths[] = {
	0, 0, 0, 1, 0, 0, 1
};

static const char _foo_range_lengths[] = {
	0, 1, 1, 1, 1, 1, 1
};

static const char _foo_index_offsets[] = {
	0, 0, 2, 4, 7, 9, 11
};

static const char _foo_trans_targs[] = {
	3, 0, 4, 0, 2, 6, 0, 5, 
	0, 5, 0, 2, 6, 0, 0
};

static const int foo_start = 1;
static const int foo_first_final = 3;
static const int foo_error = 0;

static const int foo_en_main = 1;


#line 7 "helloworld.rl"


int main(int argc, char *argv[]) {
    int cs;
    if(argc > 1){
        char *p = argv[1];
        char *pe = p + strlen(p);

        
#line 52 "helloworld.c"
	{
	cs = foo_start;
	}

#line 57 "helloworld.c"
	{
	int _klen;
	unsigned int _trans;
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

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 19 "helloworld.rl"

    }

    printf("result=%i\n", cs>=foo_first_final);
    return 0;
}