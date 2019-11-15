#ifndef _INC_STDLIB_H_
#define _INC_STDLIB_H_



//std C
#include "assert.h"
#include "ctype.h"
#include "errno.h"
#include "float.h"
#include "inttypes.h"
#include "limits.h"
#include "math.h"
#include "stdarg.h"
#include "stdbool.h"
#include "stddef.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "tgmath.h"
//#include "time.h"
//#include "uchar.h"
#include "wchar.h"
#include "wctype.h"





#ifdef __cplusplus

//C++ Other
#include "iostream"
#include "algorithm"
#include "stdexcept"
#include "string"
//#include "bitset"
//#include "chrono"
//#include "codecvt"
//#include "complex"
#include "exception"
#include "functional"
//#include "initalizer_list"
#include "limits"
//#include "locale"		//not supported.
#include "memory"
#include "new"
#include "numeric"
#include "random"
#include "ratio"
#include "regex"
#include "stdexcept"
#include "string"
#include "system_error"
#include "tuple"
#include "typeindex"
#include "typeinfo"
#include "type_traits"
#include "utility"
#include "valarray"


//C++ STL
#include "vector"
#include "deque"
#include "functional"
#include "iterator"
#include "vector"
#include "list"
#include "map"
#include "memory"
#include "numeric"
#include "queue"
#include "set"
#include "stack"
#include "utility"

#endif // ! __cplusplus


#define  bitSet(value, bit)   ((value) |= (1UL << (bit))) 
#define  bitClr(value, bit)   ((value) &= ~(1UL << (bit))) 
#define  bitRd(value, bit)   (((value) >> (bit)) & 0x01)
#define  bitWr(value, bit, bitvalue)   (bitvalue ? bitSet(value, bit) : bitClr(value, bit))
#define  bit(b)   (1 << (b)) 




#define BANNED(func) sorry_##func##_is_a_banned_function

#undef strcpy
#define strcpy(x,y) BANNED(strcpy)
#undef strcat
#define strcat(x,y) BANNED(strcat)
#undef strncpy
//#define strncpy(x,y,n) BANNED(strncpy)
#undef strncat
//#define strncat(x,y,n) BANNED(strncat)

#undef sprintf
#undef vsprintf
//#ifdef HAVE_VARIADIC_MACROS
#define sprintf(...) BANNED(sprintf)
#define vsprintf(...) BANNED(vsprintf)
//#else
//#define sprintf(buf,fmt,arg) BANNED(sprintf)
//#define vsprintf(buf,fmt,arg) BANNED(sprintf)
//#endif


#endif // ! _INC_STDLIB_H_


