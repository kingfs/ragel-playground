
#line 1 "mailbox.rl"
/*
 * Parses unix mail boxes into headers and bodies.
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

#define BUFSIZE 2048

/* A growable buffer for collecting headers. */
struct Buffer
{
	Buffer() : data(0), allocated(0), length(0) { }
	~Buffer() { empty(); }

	void append( char p ) {
		if ( ++length > allocated )
			upAllocate( length*2 );
		data[length-1] = p;
	}
		
	void clear() { length = 0; }
	void upAllocate( int len );
	void empty();

	char *data;
	int allocated;
	int length;
};


struct MailboxScanner
{
	Buffer headName;
	Buffer headContent;

	int cs, top, stack[1];

	int init( );
	int execute( const char *data, int len, bool isEof );
	int finish( );
};


#line 137 "mailbox.rl"



#line 56 "mailbox.c"
static const char _MailboxScanner_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 2, 
	4, 3
};

static const short _MailboxScanner_key_offsets[] = {
	0, 0, 1, 2, 3, 4, 6, 8, 
	12, 16, 20, 22, 26, 30, 34, 36, 
	42, 48, 50, 56, 60, 63, 67, 71, 
	74, 82, 86, 90, 94, 98, 100, 106, 
	110, 114, 118, 120, 125, 126, 128, 130, 
	132, 134, 136, 138, 142, 146, 150, 152, 
	156, 160, 164, 166, 172, 178, 180, 186, 
	190, 193, 197, 201, 204, 212, 216, 220, 
	224, 228, 230, 236, 240, 244, 248, 250, 
	254, 258, 262, 264, 270, 274, 278, 282, 
	286, 288, 294, 298, 300, 306, 310, 312, 
	316, 320, 322, 326, 329, 332, 337, 341, 
	345, 349, 351, 357, 361, 365, 369, 373, 
	375, 381, 385, 387, 393, 397, 399, 403, 
	407, 409, 413, 415, 417, 419, 420, 422, 
	424, 425, 426, 427, 428, 429, 430, 433
};

static const char _MailboxScanner_trans_keys[] = {
	114, 111, 109, 32, 10, 32, 10, 32, 
	10, 32, 65, 90, 10, 32, 97, 122, 
	10, 32, 97, 122, 10, 32, 10, 32, 
	65, 90, 10, 32, 97, 122, 10, 32, 
	97, 122, 10, 32, 10, 32, 48, 57, 
	65, 90, 10, 32, 48, 57, 65, 90, 
	10, 32, 10, 32, 48, 57, 65, 90, 
	10, 32, 48, 57, 10, 32, 58, 10, 
	32, 48, 57, 10, 32, 48, 57, 10, 
	32, 58, 10, 32, 43, 45, 48, 57, 
	65, 90, 10, 32, 48, 57, 10, 32, 
	48, 57, 10, 32, 48, 57, 10, 32, 
	48, 57, 10, 32, 10, 32, 48, 57, 
	65, 90, 10, 32, 48, 57, 10, 32, 
	48, 57, 10, 32, 48, 57, 10, 32, 
	10, 33, 57, 59, 126, 10, 10, 114, 
	10, 111, 10, 109, 10, 32, 10, 32, 
	10, 32, 10, 32, 65, 90, 10, 32, 
	97, 122, 10, 32, 97, 122, 10, 32, 
	10, 32, 65, 90, 10, 32, 97, 122, 
	10, 32, 97, 122, 10, 32, 10, 32, 
	48, 57, 65, 90, 10, 32, 48, 57, 
	65, 90, 10, 32, 10, 32, 48, 57, 
	65, 90, 10, 32, 48, 57, 10, 32, 
	58, 10, 32, 48, 57, 10, 32, 48, 
	57, 10, 32, 58, 10, 32, 43, 45, 
	48, 57, 65, 90, 10, 32, 48, 57, 
	10, 32, 48, 57, 10, 32, 48, 57, 
	10, 32, 48, 57, 10, 32, 10, 32, 
	48, 57, 65, 90, 10, 32, 48, 57, 
	10, 32, 48, 57, 10, 32, 48, 57, 
	10, 32, 10, 32, 48, 57, 10, 32, 
	48, 57, 10, 32, 48, 57, 10, 32, 
	10, 32, 43, 45, 65, 90, 10, 32, 
	48, 57, 10, 32, 48, 57, 10, 32, 
	48, 57, 10, 32, 48, 57, 10, 32, 
	10, 32, 65, 90, 97, 122, 10, 32, 
	65, 90, 10, 32, 10, 32, 65, 90, 
	97, 122, 10, 32, 65, 90, 10, 32, 
	10, 32, 48, 57, 10, 32, 48, 57, 
	10, 32, 10, 32, 48, 57, 58, 33, 
	126, 58, 33, 126, 10, 33, 57, 59, 
	126, 10, 32, 48, 57, 10, 32, 48, 
	57, 10, 32, 48, 57, 10, 32, 10, 
	32, 43, 45, 65, 90, 10, 32, 48, 
	57, 10, 32, 48, 57, 10, 32, 48, 
	57, 10, 32, 48, 57, 10, 32, 10, 
	32, 65, 90, 97, 122, 10, 32, 65, 
	90, 10, 32, 10, 32, 65, 90, 97, 
	122, 10, 32, 65, 90, 10, 32, 10, 
	32, 48, 57, 10, 32, 48, 57, 10, 
	32, 10, 32, 48, 57, 9, 32, 9, 
	32, 9, 32, 70, 10, 70, 10, 70, 
	10, 10, 10, 10, 10, 10, 9, 10, 
	32, 9, 10, 32, 0
};

static const char _MailboxScanner_single_lengths[] = {
	0, 1, 1, 1, 1, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 3, 2, 2, 3, 
	4, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 1, 1, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	3, 2, 2, 3, 4, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 4, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 1, 1, 1, 2, 2, 
	2, 2, 4, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 1, 2, 2, 
	1, 1, 1, 1, 1, 1, 3, 3
};

static const char _MailboxScanner_range_lengths[] = {
	0, 0, 0, 0, 0, 0, 0, 1, 
	1, 1, 0, 1, 1, 1, 0, 2, 
	2, 0, 2, 1, 0, 1, 1, 0, 
	2, 1, 1, 1, 1, 0, 2, 1, 
	1, 1, 0, 2, 0, 0, 0, 0, 
	0, 0, 0, 1, 1, 1, 0, 1, 
	1, 1, 0, 2, 2, 0, 2, 1, 
	0, 1, 1, 0, 2, 1, 1, 1, 
	1, 0, 2, 1, 1, 1, 0, 1, 
	1, 1, 0, 1, 1, 1, 1, 1, 
	0, 2, 1, 0, 2, 1, 0, 1, 
	1, 0, 1, 1, 1, 2, 1, 1, 
	1, 0, 1, 1, 1, 1, 1, 0, 
	2, 1, 0, 2, 1, 0, 1, 1, 
	0, 1, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0
};

static const short _MailboxScanner_index_offsets[] = {
	0, 0, 2, 4, 6, 8, 11, 14, 
	18, 22, 26, 29, 33, 37, 41, 44, 
	49, 54, 57, 62, 66, 70, 74, 78, 
	82, 89, 93, 97, 101, 105, 108, 113, 
	117, 121, 125, 128, 132, 134, 137, 140, 
	143, 146, 149, 152, 156, 160, 164, 167, 
	171, 175, 179, 182, 187, 192, 195, 200, 
	204, 208, 212, 216, 220, 227, 231, 235, 
	239, 243, 246, 251, 255, 259, 263, 266, 
	270, 274, 278, 281, 287, 291, 295, 299, 
	303, 306, 311, 315, 318, 323, 327, 330, 
	334, 338, 341, 345, 348, 351, 355, 359, 
	363, 367, 370, 376, 380, 384, 388, 392, 
	395, 400, 404, 407, 412, 416, 419, 423, 
	427, 430, 434, 437, 440, 443, 445, 448, 
	451, 453, 455, 457, 459, 461, 463, 467
};

static const char _MailboxScanner_indicies[] = {
	0, 1, 2, 1, 3, 1, 4, 1, 
	1, 6, 5, 1, 6, 5, 1, 6, 
	7, 5, 1, 6, 8, 5, 1, 6, 
	9, 5, 1, 10, 5, 1, 6, 11, 
	5, 1, 6, 12, 5, 1, 6, 13, 
	5, 1, 14, 5, 1, 15, 16, 11, 
	5, 1, 6, 17, 7, 5, 1, 18, 
	5, 1, 6, 19, 7, 5, 1, 6, 
	20, 5, 1, 6, 21, 5, 1, 6, 
	22, 5, 1, 6, 23, 5, 1, 24, 
	25, 5, 1, 6, 26, 26, 27, 28, 
	5, 1, 6, 29, 5, 1, 6, 30, 
	5, 1, 6, 31, 5, 1, 6, 32, 
	5, 1, 33, 5, 1, 6, 34, 7, 
	5, 1, 6, 35, 5, 1, 6, 36, 
	5, 1, 6, 37, 5, 38, 6, 5, 
	39, 40, 40, 1, 42, 41, 42, 43, 
	41, 42, 44, 41, 42, 45, 41, 42, 
	46, 41, 42, 48, 47, 42, 48, 47, 
	42, 48, 49, 47, 42, 48, 50, 47, 
	42, 48, 51, 47, 42, 52, 47, 42, 
	48, 53, 47, 42, 48, 54, 47, 42, 
	48, 55, 47, 42, 56, 47, 42, 57, 
	58, 53, 47, 42, 48, 59, 49, 47, 
	42, 60, 47, 42, 48, 61, 49, 47, 
	42, 48, 62, 47, 42, 48, 63, 47, 
	42, 48, 64, 47, 42, 48, 65, 47, 
	42, 66, 67, 47, 42, 48, 68, 68, 
	69, 70, 47, 42, 48, 71, 47, 42, 
	48, 72, 47, 42, 48, 73, 47, 42, 
	48, 74, 47, 42, 75, 47, 42, 48, 
	76, 49, 47, 42, 48, 77, 47, 42, 
	48, 78, 47, 42, 48, 79, 47, 38, 
	48, 47, 42, 48, 80, 47, 42, 48, 
	81, 47, 42, 48, 82, 47, 38, 83, 
	47, 42, 48, 84, 84, 85, 47, 42, 
	48, 86, 47, 42, 48, 87, 47, 42, 
	48, 88, 47, 42, 48, 89, 47, 38, 
	48, 47, 42, 48, 90, 50, 47, 42, 
	48, 91, 47, 38, 48, 47, 42, 48, 
	92, 50, 47, 42, 48, 93, 47, 42, 
	75, 47, 42, 48, 94, 47, 42, 48, 
	95, 47, 42, 66, 47, 42, 48, 59, 
	47, 97, 96, 1, 97, 96, 1, 39, 
	40, 40, 1, 1, 6, 98, 5, 1, 
	6, 99, 5, 1, 6, 100, 5, 38, 
	101, 5, 1, 6, 102, 102, 103, 5, 
	1, 6, 104, 5, 1, 6, 105, 5, 
	1, 6, 106, 5, 1, 6, 107, 5, 
	38, 6, 5, 1, 6, 108, 8, 5, 
	1, 6, 109, 5, 38, 6, 5, 1, 
	6, 110, 8, 5, 1, 6, 111, 5, 
	1, 33, 5, 1, 6, 112, 5, 1, 
	6, 113, 5, 1, 24, 5, 1, 6, 
	17, 5, 115, 115, 114, 117, 117, 116, 
	117, 117, 116, 118, 1, 42, 119, 41, 
	42, 119, 41, 121, 120, 121, 120, 121, 
	120, 121, 120, 123, 122, 123, 122, 125, 
	126, 125, 124, 125, 126, 125, 124, 0
};

static const char _MailboxScanner_trans_targs[] = {
	2, 0, 3, 4, 5, 6, 7, 8, 
	9, 10, 11, 12, 13, 14, 15, 16, 
	113, 17, 18, 19, 20, 21, 22, 23, 
	24, 110, 25, 94, 107, 26, 27, 28, 
	29, 30, 31, 32, 33, 34, 35, 118, 
	91, 36, 119, 38, 39, 40, 41, 42, 
	43, 44, 45, 46, 47, 48, 49, 50, 
	51, 52, 90, 53, 54, 55, 56, 57, 
	58, 59, 60, 87, 61, 71, 84, 62, 
	63, 64, 65, 66, 67, 68, 69, 70, 
	72, 73, 74, 75, 76, 81, 77, 78, 
	79, 80, 82, 83, 85, 86, 88, 89, 
	92, 93, 95, 96, 97, 98, 99, 104, 
	100, 101, 102, 103, 105, 106, 108, 109, 
	111, 112, 122, 123, 0, 126, 1, 37, 
	121, 114, 125, 115, 125, 127, 116
};

static const char _MailboxScanner_trans_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 3, 
	1, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	1, 13, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 5, 0, 11, 0, 0, 0, 
	0, 0, 7, 0, 15, 0, 0
};

static const char _MailboxScanner_eof_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 11, 11, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 9, 9
};

static const int MailboxScanner_start = 117;
static const int MailboxScanner_first_final = 117;
static const int MailboxScanner_error = 0;

static const int MailboxScanner_en_consumeHeader = 120;
static const int MailboxScanner_en_printHeader = 124;
static const int MailboxScanner_en_main = 117;


#line 140 "mailbox.rl"

int MailboxScanner::init( )
{
	
#line 330 "mailbox.c"
	{
	cs = MailboxScanner_start;
	top = 0;
	}

#line 144 "mailbox.rl"
	return 1;
}

int MailboxScanner::execute( const char *data, int len, bool isEof )
{
	const char *p = data;
	const char *pe = data + len;
	const char *eof = isEof ? pe : 0;

	
#line 347 "mailbox.c"
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
	_keys = _MailboxScanner_trans_keys + _MailboxScanner_key_offsets[cs];
	_trans = _MailboxScanner_index_offsets[cs];

	_klen = _MailboxScanner_single_lengths[cs];
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

	_klen = _MailboxScanner_range_lengths[cs];
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
	_trans = _MailboxScanner_indicies[_trans];
	cs = _MailboxScanner_trans_targs[_trans];

	if ( _MailboxScanner_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _MailboxScanner_actions + _MailboxScanner_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 52 "mailbox.rl"
	{ headName.append((*p)); }
	break;
	case 1:
#line 55 "mailbox.rl"
	{ cout << endl; }
	break;
	case 2:
#line 86 "mailbox.rl"
	{p--; {cs = stack[--top]; goto _again;}}
	break;
	case 3:
#line 89 "mailbox.rl"
	{headContent.append((*p));}
	break;
	case 4:
#line 90 "mailbox.rl"
	{headContent.append(' ');}
	break;
	case 5:
#line 92 "mailbox.rl"
	{
		headContent.append(0);
		cout << headContent.data << endl;
		headContent.clear();
		p--;
		{cs = stack[--top]; goto _again;}
	}
	break;
	case 6:
#line 108 "mailbox.rl"
	{
		headName.append(0);
		if ( strcmp( headName.data, "From" ) == 0 ||
				strcmp( headName.data, "To" ) == 0 ||
				strcmp( headName.data, "Subject" ) == 0 )
		{
			/* Print the header name, then jump to a machine the will display
			 * the contents. */
			cout << headName.data << ":";
			headName.clear();
			{stack[top++] = cs; cs = 124;goto _again;}
		}

		headName.clear();
		{stack[top++] = cs; cs = 120;goto _again;}
	}
	break;
#line 470 "mailbox.c"
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
	const char *__acts = _MailboxScanner_actions + _MailboxScanner_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 4:
#line 90 "mailbox.rl"
	{headContent.append(' ');}
	break;
	case 5:
#line 92 "mailbox.rl"
	{
		headContent.append(0);
		cout << headContent.data << endl;
		headContent.clear();
		p--;
		{cs = stack[--top]; 	if ( p == pe )
		goto _test_eof;
goto _again;}
	}
	break;
#line 502 "mailbox.c"
		}
	}
	}

	_out: {}
	}

#line 154 "mailbox.rl"

	if ( cs == MailboxScanner_error )
		return -1;
	if ( cs >= MailboxScanner_first_final )
		return 1;
	return 0;
}

int MailboxScanner::finish( )
{
	if ( cs == MailboxScanner_error )
		return -1;
	if ( cs >= MailboxScanner_first_final )
		return 1;
	return 0;
}


void Buffer::empty()
{
	if ( data != 0 ) {
		free( data );

		data = 0;
		length = 0;
		allocated = 0;
	}
}

void Buffer::upAllocate( int len )
{
	if ( data == 0 )
		data = (char*) malloc( len );
	else
		data = (char*) realloc( data, len );
	allocated = len;
}

MailboxScanner mailbox;
char buf[BUFSIZE];

int main()
{
	mailbox.init();
	while ( 1 ) {
		int len = fread( buf, 1, BUFSIZE, stdin );
		mailbox.execute( buf, len, len != BUFSIZE );
		if ( len != BUFSIZE )
			break;
	}
	if ( mailbox.finish() <= 0 )
		cerr << "mailbox: error parsing input" << endl;
	return 0;
}
