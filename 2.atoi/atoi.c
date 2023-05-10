
#line 1 "atoi.rl"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#line 10 "atoi.c"
static const char _atoi_actions[] = {
	0, 1, 0, 1, 1
};

static const char _atoi_key_offsets[] = {
	0, 0, 4, 6, 9, 12, 14
};

static const char _atoi_trans_keys[] = {
	43, 45, 48, 57, 48, 57, 10, 48, 
	57, 10, 48, 57, 48, 57, 0
};

static const char _atoi_single_lengths[] = {
	0, 2, 0, 1, 1, 0, 0
};

static const char _atoi_range_lengths[] = {
	0, 1, 1, 1, 1, 1, 0
};

static const char _atoi_index_offsets[] = {
	0, 0, 4, 6, 9, 12, 14
};

static const char _atoi_indicies[] = {
	0, 2, 3, 1, 3, 1, 4, 5, 
	1, 4, 5, 1, 3, 1, 1, 0
};

static const char _atoi_trans_targs[] = {
	2, 0, 5, 3, 6, 4
};

static const char _atoi_trans_actions[] = {
	0, 0, 1, 3, 0, 3
};

static const int atoi_start = 1;
static const int atoi_first_final = 6;
static const int atoi_error = 0;

static const int atoi_en_main = 1;


#line 9 "atoi.rl"


long long ragel_atoi(char *str)
{
    char *p = str, *pe = str + strlen(str);
    int cs;
    long long val = 0;
    bool neg = false;

    
#line 67 "atoi.c"
	{
	cs = atoi_start;
	}

#line 72 "atoi.c"
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
	_keys = _atoi_trans_keys + _atoi_key_offsets[cs];
	_trans = _atoi_index_offsets[cs];

	_klen = _atoi_single_lengths[cs];
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

	_klen = _atoi_range_lengths[cs];
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
	_trans = _atoi_indicies[_trans];
	cs = _atoi_trans_targs[_trans];

	if ( _atoi_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _atoi_actions + _atoi_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 19 "atoi.rl"
	{
            neg = true;
        }
	break;
	case 1:
#line 23 "atoi.rl"
	{ 
            val = val * 10 + ((*p) - '0');
        }
	break;
#line 158 "atoi.c"
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

#line 32 "atoi.rl"


    if ( neg )
        val = -1 * val;

    if ( cs < atoi_first_final )
        fprintf( stderr, "atoi: there was an error\n" );

    return val;
};

int main(int argc, char *argv[])
{
    char buf[1024];

    while (fgets(buf, sizeof(buf), stdin) != 0) {
        long long value = ragel_atoi(buf);
        printf("%lld\n", value);
    }
    return 0;
}
