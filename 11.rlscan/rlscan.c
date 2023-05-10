
#line 1 "rlscan.rl"
/*
 * Lexes Ragel input files.
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void escapeXML( char *data )
{
	while ( *data != 0 ) {
		switch ( *data ) {
			case '<': cout << "&lt;"; break;
			case '>': cout << "&gt;"; break;
			case '&': cout << "&amp;"; break;
			default: cout << *data; break;
		}
		data += 1;
	}
}

void escapeXML( char c )
{
	switch ( c ) {
		case '<': cout << "&lt;"; break;
		case '>': cout << "&gt;"; break;
		case '&': cout << "&amp;"; break;
		default: cout << c; break;
	}
}

void escapeXML( char *data, int len )
{
	for ( char *end = data + len; data != end; data++  ) {
		switch ( *data ) {
			case '<': cout << "&lt;"; break;
			case '>': cout << "&gt;"; break;
			case '&': cout << "&amp;"; break;
			default: cout << *data; break;
		}
	}
}

inline void write( const char *data )
{
	cout << data;
}

inline void write( char c )
{
	cout << c;
}

inline void write( char *data, int len )
{
	cout.write( data, len );
}



#line 237 "rlscan.rl"



#line 71 "rlscan.c"
static const char _RagelScan_actions[] = {
	0, 1, 0, 1, 2, 1, 3, 1, 
	4, 1, 5, 1, 6, 1, 7, 1, 
	8, 1, 9, 1, 10, 1, 11, 1, 
	12, 1, 13, 1, 14, 1, 15, 1, 
	16, 1, 17, 1, 18, 1, 19, 1, 
	20, 1, 21, 1, 22, 1, 23, 1, 
	24, 1, 25, 1, 26, 1, 27, 1, 
	28, 1, 29, 1, 30, 1, 31, 1, 
	32, 1, 33, 1, 34, 1, 35, 1, 
	36, 1, 37, 1, 38, 1, 39, 2, 
	0, 1
};

static const unsigned char _RagelScan_key_offsets[] = {
	0, 0, 2, 2, 4, 6, 6, 8, 
	9, 10, 12, 14, 17, 19, 19, 21, 
	23, 23, 25, 26, 27, 29, 29, 31, 
	32, 34, 34, 36, 38, 38, 40, 46, 
	48, 48, 50, 51, 56, 58, 59, 60, 
	62, 64, 64, 70, 72, 74, 76, 101, 
	103, 104, 106, 108, 111, 113, 119, 125, 
	127, 134, 141, 143, 150
};

static const char _RagelScan_trans_keys[] = {
	34, 92, 34, 92, 39, 92, 39, 92, 
	10, 10, 0, 42, 0, 42, 0, 42, 
	47, 34, 92, 34, 92, 39, 92, 39, 
	92, 10, 10, 34, 92, 34, 92, 10, 
	39, 92, 39, 92, 47, 92, 47, 92, 
	48, 57, 65, 70, 97, 102, 92, 93, 
	92, 93, 37, 0, 34, 37, 39, 47, 
	34, 92, 37, 123, 39, 92, 42, 47, 
	0, 34, 39, 47, 123, 125, 34, 92, 
	39, 92, 42, 47, 0, 10, 34, 35, 
	39, 47, 48, 91, 95, 123, 125, 33, 
	46, 49, 57, 58, 64, 65, 90, 92, 
	96, 97, 122, 124, 126, 34, 92, 10, 
	39, 92, 47, 92, 120, 48, 57, 48, 
	57, 48, 57, 65, 70, 97, 102, 48, 
	57, 65, 70, 97, 102, 48, 57, 95, 
	48, 57, 65, 90, 97, 122, 95, 48, 
	57, 65, 90, 97, 122, 92, 93, 95, 
	48, 57, 65, 90, 97, 122, 37, 0
};

static const char _RagelScan_single_lengths[] = {
	0, 2, 0, 2, 2, 0, 2, 1, 
	1, 2, 2, 3, 2, 0, 2, 2, 
	0, 2, 1, 1, 2, 0, 2, 1, 
	2, 0, 2, 2, 0, 2, 0, 2, 
	0, 2, 1, 5, 2, 1, 1, 2, 
	2, 0, 6, 2, 2, 2, 11, 2, 
	1, 2, 2, 1, 0, 0, 0, 0, 
	1, 1, 2, 1, 1
};

static const char _RagelScan_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 7, 0, 
	0, 0, 0, 1, 1, 3, 3, 1, 
	3, 3, 0, 3, 0
};

static const unsigned char _RagelScan_index_offsets[] = {
	0, 0, 3, 4, 7, 10, 11, 14, 
	16, 18, 21, 24, 28, 31, 32, 35, 
	38, 39, 42, 44, 46, 49, 50, 53, 
	55, 58, 59, 62, 65, 66, 69, 73, 
	76, 77, 80, 82, 88, 91, 93, 95, 
	98, 101, 102, 109, 112, 115, 118, 137, 
	140, 142, 145, 148, 151, 153, 157, 161, 
	163, 168, 173, 176, 181
};

static const char _RagelScan_trans_targs[] = {
	35, 2, 1, 3, 35, 2, 1, 35, 
	5, 4, 6, 35, 5, 4, 35, 8, 
	35, 8, 0, 11, 10, 0, 11, 10, 
	0, 11, 41, 10, 42, 13, 12, 14, 
	42, 13, 12, 42, 16, 15, 17, 42, 
	16, 15, 42, 19, 42, 19, 46, 21, 
	20, 22, 46, 21, 20, 46, 23, 46, 
	25, 24, 26, 46, 25, 24, 46, 28, 
	27, 29, 46, 28, 27, 53, 53, 53, 
	46, 32, 46, 31, 33, 32, 46, 31, 
	46, 46, 35, 36, 37, 39, 40, 35, 
	35, 2, 1, 38, 35, 35, 35, 35, 
	5, 4, 35, 7, 35, 0, 0, 43, 
	44, 45, 42, 42, 42, 42, 13, 12, 
	42, 16, 15, 42, 18, 42, 0, 46, 
	47, 48, 49, 50, 51, 58, 59, 46, 
	60, 46, 55, 46, 56, 46, 56, 46, 
	46, 46, 21, 20, 46, 23, 46, 25, 
	24, 46, 28, 27, 30, 52, 46, 52, 
	46, 54, 54, 54, 46, 54, 54, 54, 
	46, 52, 46, 57, 57, 57, 57, 46, 
	57, 57, 57, 57, 46, 32, 46, 31, 
	57, 57, 57, 57, 46, 34, 46, 35, 
	35, 35, 35, 35, 35, 35, 35, 42, 
	42, 42, 42, 42, 42, 42, 42, 46, 
	46, 46, 46, 46, 46, 46, 46, 46, 
	46, 46, 46, 46, 46, 46, 35, 35, 
	35, 35, 35, 42, 42, 42, 46, 46, 
	46, 46, 46, 46, 46, 46, 46, 46, 
	46, 46, 46, 46, 0
};

static const char _RagelScan_trans_actions[] = {
	61, 0, 0, 0, 61, 0, 0, 59, 
	0, 0, 0, 59, 0, 0, 65, 0, 
	65, 0, 0, 1, 1, 0, 1, 1, 
	0, 1, 79, 1, 11, 0, 0, 0, 
	11, 0, 0, 9, 0, 0, 0, 9, 
	0, 0, 15, 0, 15, 0, 35, 0, 
	0, 0, 35, 0, 0, 31, 0, 33, 
	0, 0, 0, 33, 0, 0, 39, 0, 
	0, 0, 39, 0, 0, 0, 0, 0, 
	55, 0, 37, 0, 0, 0, 37, 0, 
	27, 57, 71, 7, 0, 7, 7, 69, 
	61, 0, 0, 0, 75, 67, 73, 59, 
	0, 0, 63, 0, 75, 0, 0, 7, 
	7, 7, 17, 19, 21, 11, 0, 0, 
	9, 0, 0, 13, 0, 23, 0, 29, 
	7, 7, 7, 7, 7, 7, 0, 41, 
	7, 43, 0, 43, 0, 43, 0, 43, 
	45, 35, 0, 0, 31, 0, 33, 0, 
	0, 39, 0, 0, 0, 0, 49, 0, 
	49, 0, 0, 0, 51, 0, 0, 0, 
	51, 0, 49, 0, 0, 0, 0, 47, 
	0, 0, 0, 0, 47, 0, 37, 0, 
	0, 0, 0, 0, 47, 0, 53, 77, 
	77, 77, 77, 77, 77, 77, 77, 25, 
	25, 25, 25, 25, 25, 25, 25, 57, 
	57, 57, 57, 57, 57, 57, 57, 57, 
	57, 55, 57, 57, 57, 57, 75, 75, 
	73, 75, 75, 23, 23, 23, 53, 53, 
	53, 53, 49, 49, 51, 51, 49, 47, 
	47, 53, 47, 53, 0
};

static const char _RagelScan_to_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 3, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 3, 0, 0, 0, 0, 
	0, 0, 3, 0, 0, 0, 3, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};

static const char _RagelScan_from_state_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 5, 0, 0, 0, 0, 
	0, 0, 5, 0, 0, 0, 5, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};

static const unsigned char _RagelScan_eof_trans[] = {
	0, 191, 191, 191, 191, 191, 191, 191, 
	191, 0, 0, 0, 199, 199, 199, 199, 
	199, 199, 199, 199, 214, 214, 214, 214, 
	214, 214, 214, 214, 214, 214, 210, 214, 
	214, 214, 214, 0, 219, 219, 217, 219, 
	219, 0, 0, 222, 222, 222, 0, 236, 
	236, 236, 236, 231, 231, 230, 230, 231, 
	235, 235, 236, 235, 236
};

static const int RagelScan_start = 35;
static const int RagelScan_error = 0;

static const int RagelScan_en_c_comment = 9;
static const int RagelScan_en_ilscan = 42;
static const int RagelScan_en_rlscan = 46;
static const int RagelScan_en_main = 35;


#line 240 "rlscan.rl"

#define BUFSIZE 2048

int main()
{
	std::ios::sync_with_stdio(false);

	int cs, act;
	char *ts, *te;
	int stack[1], top;

	static char inbuf[BUFSIZE];
	bool single_line = false;
	int inline_depth = 0;

	
#line 277 "rlscan.c"
	{
	cs = RagelScan_start;
	top = 0;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 256 "rlscan.rl"

	bool done = false;
	int have = 0;
	while ( !done ) {
		/* How much space is in the buffer? */
		int space = BUFSIZE - have;
		if ( space == 0 ) {
			/* Buffer is full. */
			cerr << "TOKEN TOO BIG" << endl;
			exit(1);
		}

		/* Read in a block. */
		char *p = inbuf + have;
		cin.read( p, space );
		int len = cin.gcount();
		char *pe = p + len;
		char *eof = 0;

		/* Check for EOF. */
		if ( len == 0 ) {
			eof = pe;
			done = true;
		}

		
#line 313 "rlscan.c"
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
	_acts = _RagelScan_actions + _RagelScan_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 3:
#line 1 "NONE"
	{ts = p;}
	break;
#line 334 "rlscan.c"
		}
	}

	_keys = _RagelScan_trans_keys + _RagelScan_key_offsets[cs];
	_trans = _RagelScan_index_offsets[cs];

	_klen = _RagelScan_single_lengths[cs];
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

	_klen = _RagelScan_range_lengths[cs];
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
_eof_trans:
	cs = _RagelScan_trans_targs[_trans];

	if ( _RagelScan_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _RagelScan_actions + _RagelScan_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 76 "rlscan.rl"
	{ escapeXML( (*p) ); }
	break;
	case 1:
#line 77 "rlscan.rl"
	{ {cs = stack[--top]; goto _again;} }
	break;
	case 4:
#line 1 "NONE"
	{te = p+1;}
	break;
	case 5:
#line 79 "rlscan.rl"
	{te = p+1;{
		escapeXML( ts, te-ts );
	}}
	break;
	case 6:
#line 79 "rlscan.rl"
	{te = p+1;{
		escapeXML( ts, te-ts );
	}}
	break;
	case 7:
#line 91 "rlscan.rl"
	{te = p+1;{
			write( "/*" );
			{stack[top++] = cs; cs = 9;goto _again;}
		}}
	break;
	case 8:
#line 79 "rlscan.rl"
	{te = p+1;{
		escapeXML( ts, te-ts );
	}}
	break;
	case 9:
#line 97 "rlscan.rl"
	{te = p+1;{
			write( '{' );
			inline_depth += 1; 
		}}
	break;
	case 10:
#line 102 "rlscan.rl"
	{te = p+1;{
			write( '}' );
			/* If dropping down to the last } then return 
			 * to ragel code. */
			if ( --inline_depth == 0 ) {
				write( "</inline>\n" );
				{cs = 46;goto _again;}
			}
		}}
	break;
	case 11:
#line 112 "rlscan.rl"
	{te = p+1;{ escapeXML( *ts ); }}
	break;
	case 12:
#line 112 "rlscan.rl"
	{te = p;p--;{ escapeXML( *ts ); }}
	break;
	case 13:
#line 112 "rlscan.rl"
	{{p = ((te))-1;}{ escapeXML( *ts ); }}
	break;
	case 14:
#line 120 "rlscan.rl"
	{te = p+1;{
			if ( !single_line ) {
				write( "</section>\n" );
				{cs = 35;goto _again;}
			}
		}}
	break;
	case 15:
#line 127 "rlscan.rl"
	{te = p+1;{
			if ( single_line ) {
				write( "</section>\n" );
				{cs = 35;goto _again;}
			}
		}}
	break;
	case 16:
#line 156 "rlscan.rl"
	{te = p+1;}
	break;
	case 17:
#line 159 "rlscan.rl"
	{te = p+1;{
			write( "<single_lit>" );
			escapeXML( ts, te-ts );
			write( "</single_lit>\n" );
		}}
	break;
	case 18:
#line 166 "rlscan.rl"
	{te = p+1;{
			write( "<double_lit>" );
			escapeXML( ts, te-ts );
			write( "</double_lit>\n" );
		}}
	break;
	case 19:
#line 173 "rlscan.rl"
	{te = p+1;{
			write( "<or_lit>" );
			escapeXML( ts, te-ts );
			write( "</or_lit>\n" );
		}}
	break;
	case 20:
#line 180 "rlscan.rl"
	{te = p+1;{
			write( "<re_lit>" );
			escapeXML( ts, te-ts );
			write( "</re_lit>\n" );
		}}
	break;
	case 21:
#line 187 "rlscan.rl"
	{te = p+1;{
			inline_depth = 1;
			write( "<inline>{" );
			{cs = 42;goto _again;}
		}}
	break;
	case 22:
#line 193 "rlscan.rl"
	{te = p+1;{
			write( "<symbol>" );
			escapeXML( (*p) );
			write( "</symbol>\n" );
		}}
	break;
	case 23:
#line 199 "rlscan.rl"
	{te = p+1;}
	break;
	case 24:
#line 135 "rlscan.rl"
	{te = p;p--;{
			write( "<word>" );
			write( ts, te-ts );
			write( "</word>\n" );
		}}
	break;
	case 25:
#line 142 "rlscan.rl"
	{te = p;p--;{
			write( "<int>" );
			write( ts, te-ts );
			write( "</int>\n" );
		}}
	break;
	case 26:
#line 149 "rlscan.rl"
	{te = p;p--;{
			write( "<hex>" );
			write( ts, te-ts );
			write( "</hex>\n" );
		}}
	break;
	case 27:
#line 193 "rlscan.rl"
	{te = p;p--;{
			write( "<symbol>" );
			escapeXML( (*p) );
			write( "</symbol>\n" );
		}}
	break;
	case 28:
#line 142 "rlscan.rl"
	{{p = ((te))-1;}{
			write( "<int>" );
			write( ts, te-ts );
			write( "</int>\n" );
		}}
	break;
	case 29:
#line 193 "rlscan.rl"
	{{p = ((te))-1;}{
			write( "<symbol>" );
			escapeXML( (*p) );
			write( "</symbol>\n" );
		}}
	break;
	case 30:
#line 79 "rlscan.rl"
	{te = p+1;{
		escapeXML( ts, te-ts );
	}}
	break;
	case 31:
#line 79 "rlscan.rl"
	{te = p+1;{
		escapeXML( ts, te-ts );
	}}
	break;
	case 32:
#line 211 "rlscan.rl"
	{te = p+1;{
			escapeXML( ts, te-ts );
			{stack[top++] = cs; cs = 9;goto _again;}
		}}
	break;
	case 33:
#line 79 "rlscan.rl"
	{te = p+1;{
		escapeXML( ts, te-ts );
	}}
	break;
	case 34:
#line 218 "rlscan.rl"
	{te = p+1;{ 
			write( "<section>\n" );
			single_line = false;
			{cs = 46;goto _again;}
		}}
	break;
	case 35:
#line 230 "rlscan.rl"
	{te = p+1;{ 
			escapeXML( *ts );
		}}
	break;
	case 36:
#line 235 "rlscan.rl"
	{te = p+1;}
	break;
	case 37:
#line 224 "rlscan.rl"
	{te = p;p--;{
			write( "<section>\n" ); 
			single_line = true; 
			{cs = 46;goto _again;}
		}}
	break;
	case 38:
#line 230 "rlscan.rl"
	{te = p;p--;{ 
			escapeXML( *ts );
		}}
	break;
	case 39:
#line 230 "rlscan.rl"
	{{p = ((te))-1;}{ 
			escapeXML( *ts );
		}}
	break;
#line 652 "rlscan.c"
		}
	}

_again:
	_acts = _RagelScan_actions + _RagelScan_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 2:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 665 "rlscan.c"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _RagelScan_eof_trans[cs] > 0 ) {
		_trans = _RagelScan_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 282 "rlscan.rl"

		if ( cs == RagelScan_error ) {
			/* Machine failed before finding a token. */
			cerr << "PARSE ERROR" << endl;
			exit(1);
		}

		if ( ts == 0 )
			have = 0;
		else {
			/* There is a prefix to preserve, shift it over. */
			have = pe - ts;
			memmove( inbuf, ts, have );
			te = inbuf + (te-ts);
			ts = inbuf;
		}
	}
	return 0;
}
