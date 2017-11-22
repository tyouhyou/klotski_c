#ifndef DEFINE_H_
#define DEFINE_H_

#include <stdarg.h>
#include <stdio.h>

typedef enum BOOL {
	FALSE = 0,
	TRUE
}BOOL;

#ifndef NULL
#define NULL	(void *)0
#endif

#define _DEBUG	1
#define _WARN	2
#define _ERROR	3
#define _LOG_LEVEL	_DEBUG

//#define LOG		TRUE
#ifdef LOG
#define DEBUG(fmt, ...) do{if(_LOG_LEVEL<=_DEBUG){fprintf(stderr,"LOG [%s:%d:%s()]: " fmt,__FILE__,__LINE__,__func__,##__VA_ARGS__);fprintf(stderr,"\n");}}while(0)
#define WARN(fmt, ...) do{if(_LOG_LEVEL<=_WARN){fprintf(stderr,"WARN [%s:%d:%s()]: " fmt,__FILE__,__LINE__,__func__,##__VA_ARGS__);fprintf(stderr,"\n");}}while(0)
#define ERROR(fmt, ...) do{if(_LOG_LEVEL<=_ERROR){fprintf(stderr,"ERROR [%s:%d:%s()]: " fmt,__FILE__,__LINE__,__func__,##__VA_ARGS__);fprintf(stderr,"\n");}}while(0)
#else
#define DEBUG(fmt, ...)
#define WARN(fmt, ...)
#define ERROR(fmt, ...)
#endif

#define DRAW	TRUE
#define DRAWC(chr) do{if(DRAW)fprintf(stderr,"%c", (char)chr + 0x30);}while(0)
#define DRAWL do{if(DRAW)fprintf(stderr,"|");}while(0)
#define DRAWU do{if(DRAW)fprintf(stderr,"\n---------\n");}while(0)
#define YIELD(str) do{if(DRAW){fprintf(stderr, "\n" str "\n");}}while(0)

#endif /* DEFINE_H_ */
