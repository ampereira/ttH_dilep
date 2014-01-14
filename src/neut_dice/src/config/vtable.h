

#ifndef __VTABLE_X86_H_
#define __VTABLE_X86_H_


#include <config/work.cfg.h>
#include <gamalib/work/work.h>

/*
 *
 * Include work description files
 *
 */

#include <samples/saxpy/saxpy.h>

typedef void (work::*executeFN)(void);
typedef List<work*>* (work::*diceFN)(double* wl, unsigned int device);

const executeFN WORK_CPU_TABLE[WORK_TOTAL] =  {
    &work::execute<CPU_X86>,
    (executeFN)&saxpy::execute<CPU_X86>
};

const executeFN WORK_GPU_LIB_TABLE[WORK_TOTAL] = {
    &work::execute<GPU_LIB>,
    (executeFN)&saxpy::execute<GPU_LIB>
};


/* #include <samples/BH/BHForce.h> */

/* typedef work pWork; */

/* typedef void (work::*executeFN)(void); */
//typedef List<work*>* (work::*diceFN)(double* wl, unsigned int device);
/* typedef std::vector<pointerInfo>* (work::*toCacheRFN)(); */
/* typedef std::vector<pointerInfo>* (work::*toCacheWFN)(); */

/* const executeFN WORK_CPU_TABLE[WORK_TOTAL] = { */
		/* &work::execute<CPU_X86> */
		/* (executeFN)&BHForce::execute<CPU_X86> */
/* }; */


/* const executeFN WORK_GPU_LIB_TABLE[WORK_TOTAL] = { */
/* 		&work::execute<GPU_LIB>, */
//		(executeFN)&BHForce::execute<GPU_LIB>
/* }; */


/* const toCacheRFN TOCACHER_CPU_TABLE[WORK_TOTAL] = { */
/* 	&work::toCacheR, */
/* 	(toCacheRFN)&BHForce::toCacheR */
/* }; */

/* const toCacheRFN TOCACHEW_CPU_TABLE[WORK_TOTAL] = { */
/* 	&work::toCacheR, */
/* 	(toCacheWFN)&BHForce::toCacheW */
/* }; */


#endif
