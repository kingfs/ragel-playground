
#line 1 "format.rl"
/*
 * Partial printf implementation.
 */

#define BUFLEN 1024
#include <stdio.h>

typedef void (*WriteFunc)( char *data, int len );

struct format
{
	char buf[BUFLEN+1];
	int buflen;
	WriteFunc write;

	int flags;
	int width;
	int prec;
	int cs;
};

void do_conv( struct format *fsm, char c )
{
	printf( "flags: %x\n", fsm->flags );
	printf( "width: %i\n", fsm->width );
	printf( "prec: %i\n", fsm->prec );
	printf( "conv: %c\n", c );
	printf( "\n" );
}

#define FL_HASH          0x01
#define FL_ZERO          0x02
#define FL_DASH          0x04
#define FL_SPACE         0x08
#define FL_PLUS          0x10

#define FL_HAS_WIDTH   0x0100
#define FL_WIDTH_ARG   0x0200
#define FL_HAS_PREC    0x0400
#define FL_PREC_ARG    0x0800

#define FL_LEN_H     0x010000
#define FL_LEN_HH    0x020000
#define FL_LEN_L     0x040000
#define FL_LEN_LL    0x080000


#line 137 "format.rl"



#line 55 "format.c"
static const char _format_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10, 1, 
	11, 1, 14, 1, 15, 1, 16, 1, 
	17, 1, 18, 1, 20, 2, 3, 16, 
	2, 6, 16, 2, 12, 16, 2, 13, 
	16, 2, 19, 20
};

static const unsigned char _format_key_offsets[] = {
	0, 0, 21, 41, 61, 73, 87, 98, 
	108, 117, 127, 136, 149, 169, 189, 209, 
	223, 237, 238, 239, 240
};

static const char _format_trans_keys[] = {
	32, 35, 37, 42, 43, 45, 46, 48, 
	88, 104, 105, 108, 115, 117, 120, 49, 
	57, 99, 100, 111, 112, 32, 35, 42, 
	43, 45, 46, 48, 88, 104, 105, 108, 
	115, 117, 120, 49, 57, 99, 100, 111, 
	112, 32, 35, 42, 43, 45, 46, 48, 
	88, 104, 105, 108, 115, 117, 120, 49, 
	57, 99, 100, 111, 112, 46, 88, 104, 
	105, 108, 115, 117, 120, 99, 100, 111, 
	112, 42, 88, 104, 105, 108, 115, 117, 
	120, 48, 57, 99, 100, 111, 112, 88, 
	104, 105, 108, 115, 117, 120, 99, 100, 
	111, 112, 88, 104, 105, 115, 117, 120, 
	99, 100, 111, 112, 88, 105, 115, 117, 
	120, 99, 100, 111, 112, 88, 105, 108, 
	115, 117, 120, 99, 100, 111, 112, 88, 
	105, 115, 117, 120, 99, 100, 111, 112, 
	88, 104, 105, 108, 115, 117, 120, 48, 
	57, 99, 100, 111, 112, 32, 35, 42, 
	43, 45, 46, 48, 88, 104, 105, 108, 
	115, 117, 120, 49, 57, 99, 100, 111, 
	112, 32, 35, 42, 43, 45, 46, 48, 
	88, 104, 105, 108, 115, 117, 120, 49, 
	57, 99, 100, 111, 112, 32, 35, 42, 
	43, 45, 46, 48, 88, 104, 105, 108, 
	115, 117, 120, 49, 57, 99, 100, 111, 
	112, 46, 88, 104, 105, 108, 115, 117, 
	120, 48, 57, 99, 100, 111, 112, 46, 
	88, 104, 105, 108, 115, 117, 120, 48, 
	57, 99, 100, 111, 112, 37, 37, 37, 
	37, 0
};

static const char _format_single_lengths[] = {
	0, 15, 14, 14, 8, 8, 7, 6, 
	5, 6, 5, 7, 14, 14, 14, 8, 
	8, 1, 1, 1, 1
};

static const char _format_range_lengths[] = {
	0, 3, 3, 3, 2, 3, 2, 2, 
	2, 2, 2, 3, 3, 3, 3, 3, 
	3, 0, 0, 0, 0
};

static const unsigned char _format_index_offsets[] = {
	0, 0, 19, 37, 55, 66, 78, 88, 
	97, 105, 114, 122, 133, 151, 169, 187, 
	199, 211, 213, 215, 217
};

static const char _format_indicies[] = {
	1, 2, 3, 4, 5, 6, 7, 8, 
	10, 11, 10, 12, 10, 10, 10, 9, 
	10, 10, 0, 1, 2, 4, 5, 6, 
	7, 8, 10, 11, 10, 12, 10, 10, 
	10, 9, 10, 10, 0, 1, 2, 4, 
	5, 6, 7, 8, 10, 11, 10, 12, 
	10, 10, 10, 9, 10, 10, 0, 13, 
	14, 15, 14, 16, 14, 14, 14, 14, 
	14, 0, 17, 19, 20, 19, 21, 19, 
	19, 19, 18, 19, 19, 0, 10, 11, 
	10, 12, 10, 10, 10, 10, 10, 0, 
	22, 23, 22, 22, 22, 22, 22, 22, 
	0, 10, 10, 10, 10, 10, 10, 10, 
	0, 24, 24, 25, 24, 24, 24, 24, 
	24, 0, 10, 10, 10, 10, 10, 10, 
	10, 0, 19, 20, 19, 21, 19, 19, 
	19, 18, 19, 19, 0, 1, 2, 4, 
	5, 6, 7, 8, 10, 11, 10, 12, 
	10, 10, 10, 9, 10, 10, 0, 1, 
	2, 4, 5, 6, 7, 8, 10, 11, 
	10, 12, 10, 10, 10, 9, 10, 10, 
	0, 1, 2, 4, 5, 6, 7, 8, 
	10, 11, 10, 12, 10, 10, 10, 9, 
	10, 10, 0, 13, 14, 15, 14, 16, 
	14, 14, 14, 26, 14, 14, 0, 13, 
	14, 15, 14, 16, 14, 14, 14, 26, 
	14, 14, 0, 28, 27, 28, 27, 28, 
	27, 28, 27, 0
};

static const char _format_trans_targs[] = {
	0, 2, 3, 20, 4, 12, 13, 5, 
	14, 15, 19, 7, 9, 5, 19, 7, 
	9, 6, 11, 19, 7, 9, 19, 8, 
	19, 10, 16, 18, 1
};

static const char _format_trans_actions[] = {
	35, 21, 15, 31, 5, 23, 19, 0, 
	17, 3, 29, 0, 0, 7, 37, 7, 
	7, 11, 9, 40, 13, 13, 43, 25, 
	46, 27, 3, 31, 1
};

static const char _format_eof_actions[] = {
	0, 49, 49, 49, 49, 49, 49, 49, 
	49, 49, 49, 49, 49, 49, 49, 49, 
	49, 33, 33, 33, 33
};

static const int format_start = 17;
static const int format_first_final = 17;
static const int format_error = 0;

static const int format_en_main = 17;


#line 140 "format.rl"

void format_init( struct format *fsm )
{
	fsm->buflen = 0;
	
#line 188 "format.c"
	{
	 fsm->cs = format_start;
	}

#line 145 "format.rl"
}

void format_execute( struct format *fsm, const char *data, int len, int isEof )
{
	const char *p = data;
	const char *pe = data + len;
	const char *eof = isEof ? pe : 0;

	
#line 203 "format.c"
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
	_keys = _format_trans_keys + _format_key_offsets[ fsm->cs];
	_trans = _format_index_offsets[ fsm->cs];

	_klen = _format_single_lengths[ fsm->cs];
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

	_klen = _format_range_lengths[ fsm->cs];
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
	_trans = _format_indicies[_trans];
	 fsm->cs = _format_trans_targs[_trans];

	if ( _format_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _format_actions + _format_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 51 "format.rl"
	{
		fsm->flags = 0;
		fsm->width = 0;
		fsm->prec = 0;
	}
	break;
	case 1:
#line 61 "format.rl"
	{ fsm->width = 10 * fsm->width + ((*p)-'0'); }
	break;
	case 2:
#line 62 "format.rl"
	{ fsm->flags |= FL_WIDTH_ARG; }
	break;
	case 3:
#line 63 "format.rl"
	{ fsm->flags |= FL_HAS_WIDTH; }
	break;
	case 4:
#line 67 "format.rl"
	{ fsm->prec = 10 * fsm->prec + ((*p)-'0'); }
	break;
	case 5:
#line 68 "format.rl"
	{ fsm->flags |= FL_PREC_ARG; }
	break;
	case 6:
#line 69 "format.rl"
	{ fsm->flags |= FL_HAS_PREC; }
	break;
	case 7:
#line 73 "format.rl"
	{ fsm->flags |= FL_HASH; }
	break;
	case 8:
#line 74 "format.rl"
	{ fsm->flags |= FL_ZERO; }
	break;
	case 9:
#line 75 "format.rl"
	{ fsm->flags |= FL_DASH; }
	break;
	case 10:
#line 76 "format.rl"
	{ fsm->flags |= FL_SPACE; }
	break;
	case 11:
#line 77 "format.rl"
	{ fsm->flags |= FL_PLUS; }
	break;
	case 12:
#line 86 "format.rl"
	{ fsm->flags |= FL_LEN_H; }
	break;
	case 13:
#line 87 "format.rl"
	{ fsm->flags |= FL_LEN_L; }
	break;
	case 14:
#line 88 "format.rl"
	{ fsm->flags |= FL_LEN_HH; }
	break;
	case 15:
#line 89 "format.rl"
	{ fsm->flags |= FL_LEN_LL; }
	break;
	case 16:
#line 99 "format.rl"
	{ 
		do_conv( fsm, (*p) );
	}
	break;
	case 17:
#line 113 "format.rl"
	{
		if ( fsm->buflen == BUFLEN ) {
			fsm->write( fsm->buf, fsm->buflen );
			fsm->buflen = 0;
		}
		fsm->buf[fsm->buflen++] = (*p);
	}
	break;
	case 20:
#line 128 "format.rl"
	{
		printf("ERROR ON CHAR: 0x%x\n", (*p) );
	}
	break;
#line 367 "format.c"
		}
	}

_again:
	if (  fsm->cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	const char *__acts = _format_actions + _format_eof_actions[ fsm->cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 18:
#line 121 "format.rl"
	{
		if ( fsm->buflen > 0 )
			fsm->write( fsm->buf, fsm->buflen );
	}
	break;
	case 19:
#line 125 "format.rl"
	{
		printf("EOF IN FORMAT\n");
	}
	break;
	case 20:
#line 128 "format.rl"
	{
		printf("ERROR ON CHAR: 0x%x\n", (*p) );
	}
	break;
#line 402 "format.c"
		}
	}
	}

	_out: {}
	}

#line 154 "format.rl"
}

int format_finish( struct format *fsm )
{
	if ( fsm->cs == format_error )
		return -1;
	if ( fsm->cs >= format_first_final )
		return 1;
	return 0;
}


#define INPUT_BUFSIZE 2048

struct format fsm;
char buf[INPUT_BUFSIZE];

void write(char *data, int len )
{
	fwrite( data, 1, len, stdout );
}

int main()
{
	fsm.write = write;
	format_init( &fsm );
	while ( 1 ) {
		int len = fread( buf, 1, INPUT_BUFSIZE, stdin );
		int eof = len != INPUT_BUFSIZE;
		format_execute( &fsm, buf, len, eof );
		if ( eof )
			break;
	}
	if ( format_finish( &fsm ) <= 0 )
		printf("FAIL\n");
	return 0;
}

