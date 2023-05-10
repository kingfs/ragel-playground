
#line 1 "transition_action.rl"
#include <string.h>
#include <stdio.h>


#line 27 "transition_action.rl"



#line 12 "transition_action.c"
static const char _foo_actions[] = {
	0, 1, 1, 2, 0, 3, 2, 3, 
	2
};

static const char _foo_key_offsets[] = {
	0, 0, 2, 7, 12, 15, 17
};

static const char _foo_trans_keys[] = {
	48, 57, 32, 9, 13, 48, 57, 32, 
	9, 13, 48, 57, 32, 9, 13, 48, 
	57, 48, 57, 0
};

static const char _foo_single_lengths[] = {
	0, 0, 1, 1, 1, 0, 0
};

static const char _foo_range_lengths[] = {
	0, 1, 2, 2, 1, 1, 1
};

static const char _foo_index_offsets[] = {
	0, 0, 2, 6, 10, 13, 15
};

static const char _foo_indicies[] = {
	0, 1, 2, 2, 3, 1, 2, 2, 
	4, 1, 2, 2, 1, 5, 1, 5, 
	1, 0
};

static const char _foo_trans_targs[] = {
	2, 0, 6, 3, 4, 1
};

static const char _foo_trans_actions[] = {
	6, 0, 1, 6, 6, 3
};

static const int foo_start = 5;
static const int foo_first_final = 5;
static const int foo_error = 0;

static const int foo_en_main = 5;


#line 30 "transition_action.rl"

int main( int argc, char **argv )
{
    int cs = 0;
    char *start = NULL;

    if ( argc > 1 ) {
        char *p = argv[1];
        char *pe = p + strlen(p) + 1;
        char *eof = pe;

        printf("Input string: [%s]\n", p);
        printf("----start----\n\n");

        
#line 77 "transition_action.c"
	{
	cs = foo_start;
	}

#line 45 "transition_action.rl"
        
#line 84 "transition_action.c"
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
	_trans = _foo_indicies[_trans];
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
#line 7 "transition_action.rl"
	{
        printf("\033[31mEntering Action\033[0m\n");
		start = p;
	}
	break;
	case 1:
#line 12 "transition_action.rl"
	{
		printf("\033[31mLeaving Actions: [%.*s]\033[0m\n", (int)(p-start), start);
	}
	break;
	case 2:
#line 16 "transition_action.rl"
	{
        printf("\033[32mFinishing Action\033[0m\n");
    }
	break;
	case 3:
#line 20 "transition_action.rl"
	{
        printf("\033[34mAll Transition Action\033[0m\n");
    }
	break;
#line 183 "transition_action.c"
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

#line 46 "transition_action.rl"
    }

    printf("\n----end----\n");
    return 0;
}