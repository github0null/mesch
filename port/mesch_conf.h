#ifndef _H_MESCH_CONF
#define _H_MESCH_CONF

/////////////////////////////////////////////////////////
//            for cortex-m embedded system
/////////////////////////////////////////////////////////

#define __IS_EMBEDDED_SYSTEM

#include "cmsis_compiler.h"

/* stdio interface */
//#define printf(fmt,...)

/* error interface */

#ifdef DEBUG
__STATIC_INLINE void __endless_loop() 
{
    __BKPT(0);
    while (1);
}
#else
__STATIC_INLINE void __endless_loop() 
{
    while (1);
}
#endif

/* error(E_TYPE,"myfunc") raises error type E_TYPE for function my_func() */
#define	error(err_num,fn_name) __endless_loop()

/* warning(WARN_TYPE,"myfunc") raises warning type WARN_TYPE for 
   function my_func() */
#define warning(err_num,fn_name) __endless_loop()

/* error flags */
#define	EF_EXIT		0	/* exit on error */
#define	EF_ABORT	1	/* abort (dump core) on error */
#define	EF_JUMP		2	/* jump on error */
#define	EF_SILENT	3	/* jump, but don't print message */
#define	ERREXIT()	__endless_loop()
#define	ERRABORT()	__endless_loop()
/* don't print message */
#define	SILENTERR()	__endless_loop()
/* return here on error */
#define	ON_ERROR()	__endless_loop()

/* error catching macros */

/* execute err_part if error errnum is raised while executing ok_part */
#define	catch(errnum,ok_part,err_part) ok_part

/* execute err_part if any error raised while executing ok_part */
#define	catchall(ok_part,err_part) ok_part

/* print message if error raised while executing ok_part,
                then re-raise error to trace calls */
#define	tracecatch(ok_part,function) ok_part

/* other interface */

__STATIC_INLINE int isatty(int x) 
{
    return 0;
}

__STATIC_INLINE int fileno(void *p) 
{
    return 0;
}

#endif
