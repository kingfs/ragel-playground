
#line 1 "params.rl"
/*
 * Parse command line arguments.
 */

#include <stdio.h>
#include <string.h>

#define BUFLEN 1024

struct params
{
	char buffer[BUFLEN+1];
	int buflen;
	int cs;
};


#line 61 "params.rl"



#line 25 "params.c"
static const char _params_actions[] = {
	0, 1, 0, 1, 3, 1, 4, 2, 
	1, 5, 2, 1, 6, 2, 1, 7, 
	2, 2, 0
};

static const char _params_key_offsets[] = {
	0, 0, 8, 10, 11, 12, 13, 14, 
	15, 16, 17, 18, 19, 20, 21, 22, 
	23, 24, 25, 26, 27, 28, 29, 30, 
	31, 32, 33, 34, 35, 36, 37, 38, 
	39, 40, 41, 42
};

static const char _params_trans_keys[] = {
	45, 63, 72, 77, 83, 104, 111, 118, 
	104, 118, 101, 108, 112, 0, 101, 114, 
	115, 105, 111, 110, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 45, 45, 45, 
	45, 45, 45, 0
};

static const char _params_single_lengths[] = {
	0, 8, 2, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1
};

static const char _params_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0
};

static const char _params_index_offsets[] = {
	0, 0, 9, 12, 14, 16, 18, 20, 
	22, 24, 26, 28, 30, 32, 34, 36, 
	38, 40, 42, 44, 46, 48, 50, 52, 
	54, 56, 58, 60, 62, 64, 66, 68, 
	70, 72, 74, 76
};

static const char _params_indicies[] = {
	0, 2, 3, 4, 5, 6, 7, 8, 
	1, 9, 10, 1, 11, 1, 12, 1, 
	13, 1, 14, 1, 15, 1, 16, 1, 
	17, 1, 18, 1, 19, 1, 20, 1, 
	21, 1, 14, 1, 14, 1, 23, 22, 
	25, 24, 25, 24, 1, 22, 27, 26, 
	29, 28, 29, 28, 1, 26, 14, 1, 
	31, 30, 33, 32, 33, 32, 1, 30, 
	21, 1, 34, 1, 34, 1, 34, 1, 
	34, 1, 34, 1, 34, 1, 0
};

static const char _params_trans_targs[] = {
	2, 0, 14, 15, 16, 20, 24, 25, 
	29, 3, 7, 4, 5, 6, 31, 8, 
	9, 10, 11, 12, 13, 32, 17, 19, 
	18, 33, 21, 23, 22, 34, 26, 28, 
	27, 35, 1
};

static const char _params_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 5, 16, 0, 
	1, 13, 16, 0, 1, 10, 16, 0, 
	1, 7, 0
};

static const int params_start = 30;
static const int params_first_final = 30;
static const int params_error = 0;

static const int params_en_main = 30;


#line 64 "params.rl"

void params_init( struct params *fsm )
{
	fsm->buflen = 0;
	
#line 115 "params.c"
	{
	 fsm->cs = params_start;
	}

#line 69 "params.rl"
}

void params_execute( struct params *fsm, const char *data, int len )
{
	const char *p = data;
	const char *pe = data + len;

	
#line 129 "params.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if (  fsm->cs == 0 )
		goto _out;
_resume:
	_keys = _params_trans_keys + _params_key_offsets[ fsm->cs];
	_trans = _params_index_offsets[ fsm->cs];

	_klen = _params_single_lengths[ fsm->cs];
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

	_klen = _params_range_lengths[ fsm->cs];
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
	_trans = _params_indicies[_trans];
	 fsm->cs = _params_trans_targs[_trans];

	if ( _params_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _params_actions + _params_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 24 "params.rl"
	{
		if ( fsm->buflen < BUFLEN )
			fsm->buffer[fsm->buflen++] = (*p);
	}
	break;
	case 1:
#line 30 "params.rl"
	{
		if ( fsm->buflen < BUFLEN )
			fsm->buffer[fsm->buflen++] = 0;
	}
	break;
	case 2:
#line 36 "params.rl"
	{ fsm->buflen = 0; }
	break;
	case 3:
#line 38 "params.rl"
	{ printf("help\n"); }
	break;
	case 4:
#line 39 "params.rl"
	{ printf("version\n"); }
	break;
	case 5:
#line 40 "params.rl"
	{ printf("output: \"%s\"\n", fsm->buffer); }
	break;
	case 6:
#line 41 "params.rl"
	{ printf("spec: \"%s\"\n", fsm->buffer); }
	break;
	case 7:
#line 42 "params.rl"
	{ printf("machine: \"%s\"\n", fsm->buffer); }
	break;
#line 241 "params.c"
		}
	}

_again:
	if (  fsm->cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	_out: {}
	}

#line 77 "params.rl"
}

int params_finish( struct params *fsm )
{
	if ( fsm->cs == params_error )
		return -1;
	if ( fsm->cs >= params_first_final )
		return 1;
	return 0;
}

#define BUFSIZE 2048

int main( int argc, char **argv )
{
	int a;
	struct params params;

	params_init( &params );
	for ( a = 1; a < argc; a++ )
		params_execute( &params, argv[a], strlen(argv[a])+1 );
	if ( params_finish( &params ) != 1 )
		fprintf( stderr, "params: error processing arguments\n" );

	return 0;
}
