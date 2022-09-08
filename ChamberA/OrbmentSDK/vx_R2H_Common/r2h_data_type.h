#ifndef R2H_DATA_TYPE_H_
#define R2H_DATA_TYPE_H_


#ifdef CPU_BOM_BIG
#define R2H_UINT16_NTOH(i)  	(((i)<<8)|((i)>>8))
#define R2H_UINT16_HTON(i)  	R2H_UINT16_NTOH(i)
#define R2H_UINT32_NTOH(i)  	((((i)&0xff000000)>>24)|(((i)&0x00ff0000)>>8)|(((i)&0x0000ff00)<<8)|(((i)&0x000000ff)<<24))
#define R2H_UINT32_HTON(i)  	R2H_UINT32_NTOH(i)
#else
#define R2H_UINT16_NTOH(i)  	(i)
#define R2H_UINT16_HTON(i)  	R2H_UINT16_NTOH(i)
#define R2H_UINT32_NTOH(i)  	(i)
#define R2H_UINT32_HTON(i)  	R2H_UINT32_NTOH(i)
#endif

typedef int 				R2H_INT32;
typedef short				R2H_INT16;
typedef long long 			R2H_INT64;
typedef unsigned int 		R2H_UINT32;
typedef unsigned short		R2H_UINT16;
typedef unsigned char		R2H_UINT8;
typedef unsigned char		R2H_BYTE;
typedef signed char			R2H_SBYTE;
typedef signed char			R2H_INT8;
typedef char				R2H_CHAR;
typedef char*				R2H_STRING;
typedef const char*			R2H_CONST_STRING;
typedef unsigned long		R2H_ULONG;
typedef long				R2H_LONG;

typedef float				R2H_FLOAT;
typedef double				R2H_DOUBLE;

typedef R2H_UINT16 			R2H_TCP_PORT;
typedef R2H_INT32 			R2H_SOCKET;

#define R2H_IP4_STR_SIZE	(16)
typedef R2H_CHAR 			R2H_IP4_STRING[R2H_IP4_STR_SIZE];

#ifdef _R2H_DEBUG
#define _r2h_dlink_debug_info(arg)\
	printf("*** R2H DLink Debug Info *** : "); \
	printf arg;\
	printf("\n");
#else
#define _r2h_dlink_debug_info(arg)
#endif

#ifdef _R2H_DEBUG
#define _r2h_debug_info(arg)\
	printf("*** R2H Debug Info *** : "); \
	printf arg;\
	printf("\n");
#else
#define _r2h_debug_info(arg)
#endif

#endif
