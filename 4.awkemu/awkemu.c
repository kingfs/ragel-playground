
#line 1 "awkemu.rl"
/*
 * Perform the basic line parsing of input performed by awk.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


#line 55 "awkemu.rl"



#line 18 "awkemu.c"
static const char _awkemu_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 2, 1, 3, 2, 2, 0, 2, 
	2, 3
};

static const char _awkemu_key_offsets[] = {
	0, 3, 6, 9, 12
};

static const char _awkemu_trans_keys[] = {
	9, 10, 32, 9, 10, 32, 9, 10, 
	32, 9, 10, 32, 9, 10, 32, 0
};

static const char _awkemu_single_lengths[] = {
	3, 3, 3, 3, 3
};

static const char _awkemu_range_lengths[] = {
	0, 0, 0, 0, 0
};

static const char _awkemu_index_offsets[] = {
	0, 4, 8, 12, 16
};

static const char _awkemu_indicies[] = {
	1, 2, 1, 0, 1, 2, 1, 0, 
	4, 5, 4, 3, 7, 8, 7, 6, 
	7, 8, 7, 6, 0
};

static const char _awkemu_trans_targs[] = {
	1, 2, 4, 0, 2, 4, 0, 2, 
	4
};

static const char _awkemu_trans_actions[] = {
	0, 3, 9, 1, 0, 7, 12, 5, 
	15
};

static const int awkemu_start = 3;

static const int awkemu_en_main = 3;


#line 58 "awkemu.rl"

#define MAXWORDS 256
#define BUFSIZE 4096
char buf[BUFSIZE];

int main()
{
	int i, nwords = 0;
	char *ls = 0;
	char *ws[MAXWORDS];
	char *we[MAXWORDS];

	int cs;
	int have = 0;

	
#line 84 "awkemu.c"
	{
	cs = awkemu_start;
	}

#line 74 "awkemu.rl"

	while ( 1 ) {
		char *p, *pe, *data = buf + have;
		int len, space = BUFSIZE - have;
		/* fprintf( stderr, "space: %i\n", space ); */

		if ( space == 0 ) { 
			fprintf(stderr, "buffer out of space\n");
			exit(1);
		}

		len = fread( data, 1, space, stdin );
		/* fprintf( stderr, "len: %i\n", len ); */
		if ( len == 0 )
			break;

		/* Find the last newline by searching backwards. This is where 
		 * we will stop processing on this iteration. */
		p = buf;
		pe = buf + have + len - 1;
		while ( *pe != '\n' && pe >= buf )
			pe--;
		pe += 1;

		/* fprintf( stderr, "running on: %i\n", pe - p ); */

		
#line 117 "awkemu.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
_resume:
	_keys = _awkemu_trans_keys + _awkemu_key_offsets[cs];
	_trans = _awkemu_index_offsets[cs];

	_klen = _awkemu_single_lengths[cs];
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

	_klen = _awkemu_range_lengths[cs];
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
	_trans = _awkemu_indicies[_trans];
	cs = _awkemu_trans_targs[_trans];

	if ( _awkemu_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _awkemu_actions + _awkemu_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 13 "awkemu.rl"
	{
		ws[nwords] = p;
	}
	break;
	case 1:
#line 17 "awkemu.rl"
	{
		we[nwords++] = p;
	}
	break;
	case 2:
#line 21 "awkemu.rl"
	{
		nwords = 0;
		ls = p;
	}
	break;
	case 3:
#line 26 "awkemu.rl"
	{
		printf("endline(%i): ", nwords );
		fwrite( ls, 1, p - ls, stdout );
		printf("\n");

		for ( i = 0; i < nwords; i++ ) {
			printf("  word: ");
			fwrite( ws[i], 1, we[i] - ws[i], stdout );
			printf("\n");
		}
	}
	break;
#line 222 "awkemu.c"
		}
	}

_again:
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	}

#line 101 "awkemu.rl"

		/* How much is still in the buffer. */
		have = data + len - pe;
		if ( have > 0 )
			memmove( buf, pe, have );

		/* fprintf(stderr, "have: %i\n", have ); */

		if ( len < space )
			break;
	}

	if ( have > 0 )
		fprintf(stderr, "input not newline terminated\n");
	return 0;
}