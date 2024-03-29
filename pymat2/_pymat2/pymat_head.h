/* Global pymat header includes, system-dependant defines, etc */
#ifndef __PYMAT_HEAD_INCLUDED__
#define __PYMAT_HEAD_INCLUDED__

// We're not building a MEX file, we're building a standalone app.
#undef MATLAB_MEX_FILE
#include <Python.h>
#include <structmember.h>
#include <numpy/arrayobject.h>

#if defined(NO_IMPORT_ARRAY) || defined(NO_IMPORT)
#	error No Numpy array allowed
#endif

#ifdef WINDOWS
/* For some reason there is no 'mwSize' type in windows version of Matlab */
typedef size_t mwSize;
#include <windows.h>
#endif

#ifndef max
#define max(x,y) ((x) > (y) ? (x) : (y))
#endif
#ifndef min
#define min(x,y) ((x) < (y) ? (x) : (y))
#endif

#define PY_MODULE_NAME	"_pymat2"

#define _STR(x) #x
#define STR(x) _STR(x)

/*
 * Usually DISTUTILS_PYMAT_VERSION is provided by distutils
 * (aka its provided by setup.py)
 */
#ifndef DISTUTILS_PYMAT_VERSION
# define PYMAT_VERSION "UNKNOWN_PYMAT_VERSION"
#else
# define PYMAT_VERSION STR(DISTUTILS_PYMAT_VERSION)
#endif


#ifdef __GNUC__
# define DONT_COMPLAIN_THAT_VARIABLE_IS_NOT_USED __attribute__ ((unused))
#else
# define DONT_COMPLAIN_THAT_VARIABLE_IS_NOT_USED
#endif


/*
* I know that it is evil, but it is simpliest of all hacks
* I can think of now.
*
* If you have any proposals on how to remove this thing,
* notify me please.
*/
static DONT_COMPLAIN_THAT_VARIABLE_IS_NOT_USED int pyarray_works(void){
	int is_ok;
	if(!PyArray_API){
		is_ok = (_import_array() >= 0);
	}else{
		is_ok = 1;
	}
	return is_ok;
}

#endif /* __PYMAT_HEAD_INCLUDED__ */
