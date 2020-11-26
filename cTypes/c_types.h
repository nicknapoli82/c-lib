#ifndef C_TYPES_DEF
#define C_TYPES_DEF

#define i8 signed char
#define u8 unsigned char

#define i16 signed short
#define u16 unsigned short

#ifndef __SIZEOF_INT__
  #define __SIZEOF_INT__ sizeof(int)
#endif
#ifndef __SIZEOF_LONG__
  #define __SIZEOF_LONG__ sizeof(long)
#endif
#ifndef __SIZEOF_LONG_LONG__
  #define __SIZEOF_LONG_LONG__ sizeof(long long)
#endif

#if __SIZEOF_INT__ == 4
  #define i32 signed int
  #define u32 unsigned int

#elif __SIZEOF_INT__ == 2
  #if __SIZEOF_LONG__ == 4
    #define i32 signed long
    #define u32 unsigned long
  #endif

#endif

#if __SIZEOF_LONG__ == 8
  #define i64 signed long
  #define u63 unsigned long
#elif __SIZEOF_LONG == 4
  #if __SIZEOF_LONG_LONG__ == 8
    #define i64 signed long long
    #define u63 unsigned long long
  #endif
#endif

// Although I am less concerned with floating point types
// We still want to stick with this convention
// It is not the responsibility for this macro system
// to determine if f128 is available. Thats still on you

#define f32 float
#define f64 double
#define f128 long double

#endif
