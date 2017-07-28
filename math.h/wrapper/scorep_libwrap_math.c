#include "libwrap.h"

#define SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ) \
    libwrap_math_region__ ## func

#define SCOREP_LIBWRAP_REGION_HANDLE( func ) \
    SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ).handle

#define SCOREP_LIBWRAP_REGION_FILTERED( func ) \
    SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ).filtered

#if defined( SCOREP_LIBWRAP_SHARED )
#define SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) \
    SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ).funcptr
#endif

#include <scorep/SCOREP_Libwrap_Macros.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* region descriptors */

#if defined( SCOREP_LIBWRAP_STATIC )

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    SCOREP_LIBWRAP_DECLARE_REAL_FUNC( rettype, func, args ); \
    static struct \
    { \
        SCOREP_RegionHandle handle; \
        int                 filtered; \
    } SCOREP_LIBWRAP_REGION_DESCRIPTOR( func );

#elif defined( SCOREP_LIBWRAP_SHARED )

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static struct \
    { \
        SCOREP_RegionHandle handle; \
        int                 filtered; \
        SCOREP_LIBWRAP_FUNC_TYPE( rettype, funcptr, args ); \
    } SCOREP_LIBWRAP_REGION_DESCRIPTOR( func );

#endif

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_math.inc.c"

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static void libwrap_math_init__##func( SCOREP_LibwrapHandle* handle ) \
    { \
        SCOREP_LIBWRAP_FUNC_INIT( handle, func, prettyname, file, line ); \
    }

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_math.inc.c"

/* region init functions */

static void
libwrap_math_init( SCOREP_LibwrapHandle* handle )
{
#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    ns libwrap_math_init__##func( handle );

#include "scorep_libwrap_math.inc.c"
}

#if defined( SCOREP_LIBWRAP_SHARED )

#define LIBWRAP_EARLY_INIT( func ) \
    do \
    { \
        if ( !SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) ) \
        { \
            libwrap_math_early_init(); \
        } \
    } while ( 0 )

/* region early init functions */

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static void libwrap_math_early_init__##func() \
    { \
        SCOREP_Libwrap_EarlySharedPtrInit( #func, ( void** )&SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) ); \
    }

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_math.inc.c"

static void
libwrap_math_early_init()
{
#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    ns libwrap_math_early_init__##func();

#include "scorep_libwrap_math.inc.c"
}

#else

#define LIBWRAP_EARLY_INIT( func ) do { } while ( 0 )

#endif

static const char* libwrap_math_libnames[] = {
    "libm.so"
};
static SCOREP_LibwrapHandle*          libwrap_math_handle;
static const SCOREP_LibwrapAttributes libwrap_math_attributes =
{
    SCOREP_LIBWRAP_VERSION,
    "math",
    "math.h",
    SCOREP_LIBWRAP_MODE,
    libwrap_math_init,
    1,
    libwrap_math_libnames
};


#undef acos
double
SCOREP_LIBWRAP_FUNC_NAME( acos )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( acos );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( acos );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( acos, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( acos );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef asin
double
SCOREP_LIBWRAP_FUNC_NAME( asin )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( asin );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( asin );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( asin, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( asin );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef atan
double
SCOREP_LIBWRAP_FUNC_NAME( atan )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( atan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( atan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( atan, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( atan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef atan2
double
SCOREP_LIBWRAP_FUNC_NAME( atan2 )( double __y, double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( atan2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( atan2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( atan2, ( __y, __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( atan2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef cos
double
SCOREP_LIBWRAP_FUNC_NAME( cos )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( cos );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( cos );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( cos, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( cos );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef sin
double
SCOREP_LIBWRAP_FUNC_NAME( sin )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( sin );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( sin );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( sin, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( sin );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef tan
double
SCOREP_LIBWRAP_FUNC_NAME( tan )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( tan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( tan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( tan, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( tan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef cosh
double
SCOREP_LIBWRAP_FUNC_NAME( cosh )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( cosh );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( cosh );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( cosh, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( cosh );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef sinh
double
SCOREP_LIBWRAP_FUNC_NAME( sinh )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( sinh );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( sinh );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( sinh, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( sinh );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef tanh
double
SCOREP_LIBWRAP_FUNC_NAME( tanh )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( tanh );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( tanh );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( tanh, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( tanh );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef acosh
double
SCOREP_LIBWRAP_FUNC_NAME( acosh )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( acosh );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( acosh );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( acosh, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( acosh );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef asinh
double
SCOREP_LIBWRAP_FUNC_NAME( asinh )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( asinh );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( asinh );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( asinh, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( asinh );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef atanh
double
SCOREP_LIBWRAP_FUNC_NAME( atanh )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( atanh );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( atanh );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( atanh, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( atanh );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef exp
double
SCOREP_LIBWRAP_FUNC_NAME( exp )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( exp, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log
double
SCOREP_LIBWRAP_FUNC_NAME( log )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log10
double
SCOREP_LIBWRAP_FUNC_NAME( log10 )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log10 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log10 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log10, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log10 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef expm1
double
SCOREP_LIBWRAP_FUNC_NAME( expm1 )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( expm1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( expm1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( expm1, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( expm1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log1p
double
SCOREP_LIBWRAP_FUNC_NAME( log1p )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log1p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log1p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log1p, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log1p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef logb
double
SCOREP_LIBWRAP_FUNC_NAME( logb )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( logb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( logb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( logb, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( logb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef exp2
double
SCOREP_LIBWRAP_FUNC_NAME( exp2 )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( exp2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( exp2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( exp2, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( exp2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log2
double
SCOREP_LIBWRAP_FUNC_NAME( log2 )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log2, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef pow
double
SCOREP_LIBWRAP_FUNC_NAME( pow )( double __x, double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( pow );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( pow );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( pow, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( pow );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef sqrt
double
SCOREP_LIBWRAP_FUNC_NAME( sqrt )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( sqrt );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( sqrt );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( sqrt, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( sqrt );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef hypot
double
SCOREP_LIBWRAP_FUNC_NAME( hypot )( double __x, double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( hypot );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( hypot );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( hypot, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( hypot );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef cbrt
double
SCOREP_LIBWRAP_FUNC_NAME( cbrt )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( cbrt );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( cbrt );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( cbrt, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( cbrt );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef ceil
double
SCOREP_LIBWRAP_FUNC_NAME( ceil )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( ceil );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( ceil );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( ceil, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( ceil );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fabs
double
SCOREP_LIBWRAP_FUNC_NAME( fabs )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fabs );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fabs );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fabs, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fabs );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef floor
double
SCOREP_LIBWRAP_FUNC_NAME( floor )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( floor );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( floor );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( floor, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( floor );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fmod
double
SCOREP_LIBWRAP_FUNC_NAME( fmod )( double __x, double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fmod );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fmod );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fmod, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fmod );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef drem
double
SCOREP_LIBWRAP_FUNC_NAME( drem )( double __x, double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( drem );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( drem );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( drem, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( drem );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef significand
double
SCOREP_LIBWRAP_FUNC_NAME( significand )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( significand );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( significand );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( significand, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( significand );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nan
double
SCOREP_LIBWRAP_FUNC_NAME( nan )( const char * __tagb )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nan, ( __tagb ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef j0
double
SCOREP_LIBWRAP_FUNC_NAME( j0 )( double scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( j0 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( j0 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( j0, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( j0 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef j1
double
SCOREP_LIBWRAP_FUNC_NAME( j1 )( double scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( j1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( j1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( j1, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( j1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef jn
double
SCOREP_LIBWRAP_FUNC_NAME( jn )( int scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( jn );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( jn );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( jn, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( jn );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef y0
double
SCOREP_LIBWRAP_FUNC_NAME( y0 )( double scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( y0 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( y0 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( y0, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( y0 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef y1
double
SCOREP_LIBWRAP_FUNC_NAME( y1 )( double scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( y1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( y1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( y1, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( y1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef yn
double
SCOREP_LIBWRAP_FUNC_NAME( yn )( int scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( yn );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( yn );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( yn, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( yn );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef erf
double
SCOREP_LIBWRAP_FUNC_NAME( erf )( double scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( erf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( erf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( erf, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( erf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef erfc
double
SCOREP_LIBWRAP_FUNC_NAME( erfc )( double scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( erfc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( erfc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( erfc, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( erfc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lgamma
double
SCOREP_LIBWRAP_FUNC_NAME( lgamma )( double scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lgamma );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lgamma );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lgamma, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lgamma );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef tgamma
double
SCOREP_LIBWRAP_FUNC_NAME( tgamma )( double scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( tgamma );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( tgamma );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( tgamma, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( tgamma );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef gamma
double
SCOREP_LIBWRAP_FUNC_NAME( gamma )( double scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( gamma );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( gamma );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( gamma, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( gamma );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lgamma_r
double
SCOREP_LIBWRAP_FUNC_NAME( lgamma_r )( double scorep_libwrap_arg_1, int * __signgamp )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lgamma_r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lgamma_r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lgamma_r, ( scorep_libwrap_arg_1, __signgamp ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lgamma_r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef rint
double
SCOREP_LIBWRAP_FUNC_NAME( rint )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( rint );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( rint );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( rint, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( rint );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nextafter
double
SCOREP_LIBWRAP_FUNC_NAME( nextafter )( double __x, double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nextafter );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nextafter );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nextafter, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nextafter );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nexttoward
double
SCOREP_LIBWRAP_FUNC_NAME( nexttoward )( double __x, long double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nexttoward );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nexttoward );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nexttoward, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nexttoward );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef remainder
double
SCOREP_LIBWRAP_FUNC_NAME( remainder )( double __x, double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( remainder );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( remainder );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( remainder, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( remainder );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef ilogb
int
SCOREP_LIBWRAP_FUNC_NAME( ilogb )( double __x )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( ilogb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( ilogb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( ilogb, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( ilogb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef scalbln
double
SCOREP_LIBWRAP_FUNC_NAME( scalbln )( double __x, long __n )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( scalbln );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( scalbln );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( scalbln, ( __x, __n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( scalbln );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nearbyint
double
SCOREP_LIBWRAP_FUNC_NAME( nearbyint )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nearbyint );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nearbyint );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nearbyint, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nearbyint );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef round
double
SCOREP_LIBWRAP_FUNC_NAME( round )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( round );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( round );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( round, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( round );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef trunc
double
SCOREP_LIBWRAP_FUNC_NAME( trunc )( double __x )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( trunc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( trunc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( trunc, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( trunc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef remquo
double
SCOREP_LIBWRAP_FUNC_NAME( remquo )( double __x, double __y, int * __quo )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( remquo );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( remquo );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( remquo, ( __x, __y, __quo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( remquo );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lrint
long
SCOREP_LIBWRAP_FUNC_NAME( lrint )( double __x )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lrint );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lrint );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lrint, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lrint );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef llrint
long long
SCOREP_LIBWRAP_FUNC_NAME( llrint )( double __x )
{
    long long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( llrint );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( llrint );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( llrint, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( llrint );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lround
long
SCOREP_LIBWRAP_FUNC_NAME( lround )( double __x )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lround );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lround );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lround, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lround );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef llround
long long
SCOREP_LIBWRAP_FUNC_NAME( llround )( double __x )
{
    long long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( llround );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( llround );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( llround, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( llround );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fdim
double
SCOREP_LIBWRAP_FUNC_NAME( fdim )( double __x, double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fdim );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fdim );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fdim, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fdim );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fmax
double
SCOREP_LIBWRAP_FUNC_NAME( fmax )( double __x, double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fmax );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fmax );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fmax, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fmax );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fmin
double
SCOREP_LIBWRAP_FUNC_NAME( fmin )( double __x, double __y )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fmin );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fmin );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fmin, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fmin );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __fpclassify
int
SCOREP_LIBWRAP_FUNC_NAME( __fpclassify )( double __value )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __fpclassify );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __fpclassify );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __fpclassify, ( __value ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __fpclassify );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fma
double
SCOREP_LIBWRAP_FUNC_NAME( fma )( double __x, double __y, double __z )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fma );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fma );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fma, ( __x, __y, __z ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fma );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef scalb
double
SCOREP_LIBWRAP_FUNC_NAME( scalb )( double __x, double __n )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( scalb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( scalb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( scalb, ( __x, __n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( scalb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef acosf
float
SCOREP_LIBWRAP_FUNC_NAME( acosf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( acosf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( acosf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( acosf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( acosf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef asinf
float
SCOREP_LIBWRAP_FUNC_NAME( asinf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( asinf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( asinf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( asinf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( asinf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef atanf
float
SCOREP_LIBWRAP_FUNC_NAME( atanf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( atanf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( atanf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( atanf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( atanf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef atan2f
float
SCOREP_LIBWRAP_FUNC_NAME( atan2f )( float __y, float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( atan2f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( atan2f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( atan2f, ( __y, __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( atan2f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef cosf
float
SCOREP_LIBWRAP_FUNC_NAME( cosf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( cosf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( cosf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( cosf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( cosf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef sinf
float
SCOREP_LIBWRAP_FUNC_NAME( sinf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( sinf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( sinf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( sinf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( sinf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef tanf
float
SCOREP_LIBWRAP_FUNC_NAME( tanf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( tanf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( tanf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( tanf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( tanf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef coshf
float
SCOREP_LIBWRAP_FUNC_NAME( coshf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( coshf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( coshf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( coshf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( coshf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef sinhf
float
SCOREP_LIBWRAP_FUNC_NAME( sinhf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( sinhf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( sinhf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( sinhf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( sinhf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef tanhf
float
SCOREP_LIBWRAP_FUNC_NAME( tanhf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( tanhf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( tanhf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( tanhf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( tanhf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef acoshf
float
SCOREP_LIBWRAP_FUNC_NAME( acoshf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( acoshf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( acoshf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( acoshf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( acoshf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef asinhf
float
SCOREP_LIBWRAP_FUNC_NAME( asinhf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( asinhf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( asinhf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( asinhf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( asinhf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef atanhf
float
SCOREP_LIBWRAP_FUNC_NAME( atanhf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( atanhf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( atanhf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( atanhf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( atanhf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef expf
float
SCOREP_LIBWRAP_FUNC_NAME( expf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( expf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( expf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( expf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( expf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef logf
float
SCOREP_LIBWRAP_FUNC_NAME( logf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( logf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( logf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( logf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( logf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log10f
float
SCOREP_LIBWRAP_FUNC_NAME( log10f )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log10f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log10f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log10f, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log10f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef expm1f
float
SCOREP_LIBWRAP_FUNC_NAME( expm1f )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( expm1f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( expm1f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( expm1f, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( expm1f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log1pf
float
SCOREP_LIBWRAP_FUNC_NAME( log1pf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log1pf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log1pf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log1pf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log1pf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef logbf
float
SCOREP_LIBWRAP_FUNC_NAME( logbf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( logbf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( logbf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( logbf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( logbf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef exp2f
float
SCOREP_LIBWRAP_FUNC_NAME( exp2f )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( exp2f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( exp2f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( exp2f, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( exp2f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log2f
float
SCOREP_LIBWRAP_FUNC_NAME( log2f )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log2f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log2f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log2f, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log2f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef powf
float
SCOREP_LIBWRAP_FUNC_NAME( powf )( float __x, float __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( powf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( powf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( powf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( powf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef sqrtf
float
SCOREP_LIBWRAP_FUNC_NAME( sqrtf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( sqrtf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( sqrtf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( sqrtf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( sqrtf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef hypotf
float
SCOREP_LIBWRAP_FUNC_NAME( hypotf )( float __x, float __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( hypotf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( hypotf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( hypotf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( hypotf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef cbrtf
float
SCOREP_LIBWRAP_FUNC_NAME( cbrtf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( cbrtf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( cbrtf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( cbrtf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( cbrtf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef ceilf
float
SCOREP_LIBWRAP_FUNC_NAME( ceilf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( ceilf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( ceilf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( ceilf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( ceilf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fabsf
float
SCOREP_LIBWRAP_FUNC_NAME( fabsf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fabsf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fabsf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fabsf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fabsf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef floorf
float
SCOREP_LIBWRAP_FUNC_NAME( floorf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( floorf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( floorf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( floorf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( floorf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fmodf
float
SCOREP_LIBWRAP_FUNC_NAME( fmodf )( float __x, float __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fmodf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fmodf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fmodf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fmodf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef dremf
float
SCOREP_LIBWRAP_FUNC_NAME( dremf )( float __x, float __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( dremf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( dremf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( dremf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( dremf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef significandf
float
SCOREP_LIBWRAP_FUNC_NAME( significandf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( significandf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( significandf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( significandf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( significandf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nanf
float
SCOREP_LIBWRAP_FUNC_NAME( nanf )( const char * __tagb )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nanf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nanf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nanf, ( __tagb ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nanf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef j0f
float
SCOREP_LIBWRAP_FUNC_NAME( j0f )( float scorep_libwrap_arg_1 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( j0f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( j0f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( j0f, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( j0f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef j1f
float
SCOREP_LIBWRAP_FUNC_NAME( j1f )( float scorep_libwrap_arg_1 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( j1f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( j1f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( j1f, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( j1f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef jnf
float
SCOREP_LIBWRAP_FUNC_NAME( jnf )( int scorep_libwrap_arg_1, float scorep_libwrap_arg_2 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( jnf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( jnf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( jnf, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( jnf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef y0f
float
SCOREP_LIBWRAP_FUNC_NAME( y0f )( float scorep_libwrap_arg_1 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( y0f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( y0f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( y0f, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( y0f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef y1f
float
SCOREP_LIBWRAP_FUNC_NAME( y1f )( float scorep_libwrap_arg_1 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( y1f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( y1f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( y1f, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( y1f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef ynf
float
SCOREP_LIBWRAP_FUNC_NAME( ynf )( int scorep_libwrap_arg_1, float scorep_libwrap_arg_2 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( ynf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( ynf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( ynf, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( ynf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef erff
float
SCOREP_LIBWRAP_FUNC_NAME( erff )( float scorep_libwrap_arg_1 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( erff );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( erff );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( erff, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( erff );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef erfcf
float
SCOREP_LIBWRAP_FUNC_NAME( erfcf )( float scorep_libwrap_arg_1 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( erfcf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( erfcf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( erfcf, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( erfcf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lgammaf
float
SCOREP_LIBWRAP_FUNC_NAME( lgammaf )( float scorep_libwrap_arg_1 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lgammaf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lgammaf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lgammaf, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lgammaf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef tgammaf
float
SCOREP_LIBWRAP_FUNC_NAME( tgammaf )( float scorep_libwrap_arg_1 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( tgammaf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( tgammaf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( tgammaf, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( tgammaf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef gammaf
float
SCOREP_LIBWRAP_FUNC_NAME( gammaf )( float scorep_libwrap_arg_1 )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( gammaf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( gammaf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( gammaf, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( gammaf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lgammaf_r
float
SCOREP_LIBWRAP_FUNC_NAME( lgammaf_r )( float scorep_libwrap_arg_1, int * __signgamp )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lgammaf_r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lgammaf_r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lgammaf_r, ( scorep_libwrap_arg_1, __signgamp ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lgammaf_r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef rintf
float
SCOREP_LIBWRAP_FUNC_NAME( rintf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( rintf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( rintf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( rintf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( rintf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nextafterf
float
SCOREP_LIBWRAP_FUNC_NAME( nextafterf )( float __x, float __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nextafterf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nextafterf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nextafterf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nextafterf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nexttowardf
float
SCOREP_LIBWRAP_FUNC_NAME( nexttowardf )( float __x, long double __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nexttowardf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nexttowardf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nexttowardf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nexttowardf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef remainderf
float
SCOREP_LIBWRAP_FUNC_NAME( remainderf )( float __x, float __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( remainderf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( remainderf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( remainderf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( remainderf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef ilogbf
int
SCOREP_LIBWRAP_FUNC_NAME( ilogbf )( float __x )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( ilogbf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( ilogbf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( ilogbf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( ilogbf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef scalblnf
float
SCOREP_LIBWRAP_FUNC_NAME( scalblnf )( float __x, long __n )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( scalblnf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( scalblnf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( scalblnf, ( __x, __n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( scalblnf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nearbyintf
float
SCOREP_LIBWRAP_FUNC_NAME( nearbyintf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nearbyintf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nearbyintf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nearbyintf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nearbyintf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef roundf
float
SCOREP_LIBWRAP_FUNC_NAME( roundf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( roundf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( roundf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( roundf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( roundf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef truncf
float
SCOREP_LIBWRAP_FUNC_NAME( truncf )( float __x )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( truncf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( truncf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( truncf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( truncf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef remquof
float
SCOREP_LIBWRAP_FUNC_NAME( remquof )( float __x, float __y, int * __quo )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( remquof );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( remquof );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( remquof, ( __x, __y, __quo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( remquof );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lrintf
long
SCOREP_LIBWRAP_FUNC_NAME( lrintf )( float __x )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lrintf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lrintf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lrintf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lrintf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef llrintf
long long
SCOREP_LIBWRAP_FUNC_NAME( llrintf )( float __x )
{
    long long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( llrintf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( llrintf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( llrintf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( llrintf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lroundf
long
SCOREP_LIBWRAP_FUNC_NAME( lroundf )( float __x )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lroundf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lroundf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lroundf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lroundf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef llroundf
long long
SCOREP_LIBWRAP_FUNC_NAME( llroundf )( float __x )
{
    long long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( llroundf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( llroundf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( llroundf, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( llroundf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fdimf
float
SCOREP_LIBWRAP_FUNC_NAME( fdimf )( float __x, float __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fdimf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fdimf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fdimf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fdimf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fmaxf
float
SCOREP_LIBWRAP_FUNC_NAME( fmaxf )( float __x, float __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fmaxf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fmaxf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fmaxf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fmaxf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fminf
float
SCOREP_LIBWRAP_FUNC_NAME( fminf )( float __x, float __y )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fminf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fminf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fminf, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fminf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __fpclassifyf
int
SCOREP_LIBWRAP_FUNC_NAME( __fpclassifyf )( float __value )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __fpclassifyf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __fpclassifyf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __fpclassifyf, ( __value ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __fpclassifyf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fmaf
float
SCOREP_LIBWRAP_FUNC_NAME( fmaf )( float __x, float __y, float __z )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fmaf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fmaf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fmaf, ( __x, __y, __z ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fmaf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef scalbf
float
SCOREP_LIBWRAP_FUNC_NAME( scalbf )( float __x, float __n )
{
    float scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( scalbf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( scalbf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( scalbf, ( __x, __n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( scalbf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef acosl
long double
SCOREP_LIBWRAP_FUNC_NAME( acosl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( acosl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( acosl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( acosl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( acosl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef asinl
long double
SCOREP_LIBWRAP_FUNC_NAME( asinl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( asinl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( asinl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( asinl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( asinl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef atanl
long double
SCOREP_LIBWRAP_FUNC_NAME( atanl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( atanl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( atanl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( atanl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( atanl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef atan2l
long double
SCOREP_LIBWRAP_FUNC_NAME( atan2l )( long double __y, long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( atan2l );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( atan2l );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( atan2l, ( __y, __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( atan2l );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef cosl
long double
SCOREP_LIBWRAP_FUNC_NAME( cosl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( cosl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( cosl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( cosl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( cosl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef sinl
long double
SCOREP_LIBWRAP_FUNC_NAME( sinl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( sinl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( sinl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( sinl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( sinl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef tanl
long double
SCOREP_LIBWRAP_FUNC_NAME( tanl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( tanl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( tanl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( tanl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( tanl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef coshl
long double
SCOREP_LIBWRAP_FUNC_NAME( coshl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( coshl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( coshl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( coshl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( coshl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef sinhl
long double
SCOREP_LIBWRAP_FUNC_NAME( sinhl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( sinhl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( sinhl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( sinhl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( sinhl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef tanhl
long double
SCOREP_LIBWRAP_FUNC_NAME( tanhl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( tanhl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( tanhl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( tanhl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( tanhl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef acoshl
long double
SCOREP_LIBWRAP_FUNC_NAME( acoshl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( acoshl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( acoshl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( acoshl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( acoshl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef asinhl
long double
SCOREP_LIBWRAP_FUNC_NAME( asinhl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( asinhl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( asinhl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( asinhl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( asinhl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef atanhl
long double
SCOREP_LIBWRAP_FUNC_NAME( atanhl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( atanhl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( atanhl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( atanhl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( atanhl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef expl
long double
SCOREP_LIBWRAP_FUNC_NAME( expl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( expl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( expl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( expl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( expl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef logl
long double
SCOREP_LIBWRAP_FUNC_NAME( logl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( logl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( logl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( logl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( logl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log10l
long double
SCOREP_LIBWRAP_FUNC_NAME( log10l )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log10l );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log10l );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log10l, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log10l );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef expm1l
long double
SCOREP_LIBWRAP_FUNC_NAME( expm1l )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( expm1l );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( expm1l );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( expm1l, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( expm1l );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log1pl
long double
SCOREP_LIBWRAP_FUNC_NAME( log1pl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log1pl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log1pl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log1pl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log1pl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef logbl
long double
SCOREP_LIBWRAP_FUNC_NAME( logbl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( logbl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( logbl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( logbl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( logbl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef exp2l
long double
SCOREP_LIBWRAP_FUNC_NAME( exp2l )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( exp2l );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( exp2l );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( exp2l, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( exp2l );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef log2l
long double
SCOREP_LIBWRAP_FUNC_NAME( log2l )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( log2l );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( log2l );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( log2l, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( log2l );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef powl
long double
SCOREP_LIBWRAP_FUNC_NAME( powl )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( powl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( powl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( powl, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( powl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef sqrtl
long double
SCOREP_LIBWRAP_FUNC_NAME( sqrtl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( sqrtl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( sqrtl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( sqrtl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( sqrtl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef hypotl
long double
SCOREP_LIBWRAP_FUNC_NAME( hypotl )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( hypotl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( hypotl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( hypotl, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( hypotl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef cbrtl
long double
SCOREP_LIBWRAP_FUNC_NAME( cbrtl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( cbrtl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( cbrtl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( cbrtl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( cbrtl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef ceill
long double
SCOREP_LIBWRAP_FUNC_NAME( ceill )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( ceill );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( ceill );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( ceill, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( ceill );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fabsl
long double
SCOREP_LIBWRAP_FUNC_NAME( fabsl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fabsl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fabsl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fabsl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fabsl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef floorl
long double
SCOREP_LIBWRAP_FUNC_NAME( floorl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( floorl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( floorl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( floorl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( floorl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fmodl
long double
SCOREP_LIBWRAP_FUNC_NAME( fmodl )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fmodl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fmodl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fmodl, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fmodl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef dreml
long double
SCOREP_LIBWRAP_FUNC_NAME( dreml )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( dreml );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( dreml );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( dreml, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( dreml );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef significandl
long double
SCOREP_LIBWRAP_FUNC_NAME( significandl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( significandl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( significandl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( significandl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( significandl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nanl
long double
SCOREP_LIBWRAP_FUNC_NAME( nanl )( const char * __tagb )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nanl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nanl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nanl, ( __tagb ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nanl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef j0l
long double
SCOREP_LIBWRAP_FUNC_NAME( j0l )( long double scorep_libwrap_arg_1 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( j0l );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( j0l );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( j0l, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( j0l );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef j1l
long double
SCOREP_LIBWRAP_FUNC_NAME( j1l )( long double scorep_libwrap_arg_1 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( j1l );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( j1l );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( j1l, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( j1l );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef jnl
long double
SCOREP_LIBWRAP_FUNC_NAME( jnl )( int scorep_libwrap_arg_1, long double scorep_libwrap_arg_2 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( jnl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( jnl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( jnl, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( jnl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef y0l
long double
SCOREP_LIBWRAP_FUNC_NAME( y0l )( long double scorep_libwrap_arg_1 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( y0l );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( y0l );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( y0l, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( y0l );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef y1l
long double
SCOREP_LIBWRAP_FUNC_NAME( y1l )( long double scorep_libwrap_arg_1 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( y1l );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( y1l );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( y1l, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( y1l );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef ynl
long double
SCOREP_LIBWRAP_FUNC_NAME( ynl )( int scorep_libwrap_arg_1, long double scorep_libwrap_arg_2 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( ynl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( ynl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( ynl, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( ynl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef erfl
long double
SCOREP_LIBWRAP_FUNC_NAME( erfl )( long double scorep_libwrap_arg_1 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( erfl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( erfl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( erfl, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( erfl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef erfcl
long double
SCOREP_LIBWRAP_FUNC_NAME( erfcl )( long double scorep_libwrap_arg_1 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( erfcl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( erfcl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( erfcl, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( erfcl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lgammal
long double
SCOREP_LIBWRAP_FUNC_NAME( lgammal )( long double scorep_libwrap_arg_1 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lgammal );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lgammal );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lgammal, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lgammal );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef tgammal
long double
SCOREP_LIBWRAP_FUNC_NAME( tgammal )( long double scorep_libwrap_arg_1 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( tgammal );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( tgammal );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( tgammal, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( tgammal );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef gammal
long double
SCOREP_LIBWRAP_FUNC_NAME( gammal )( long double scorep_libwrap_arg_1 )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( gammal );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( gammal );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( gammal, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( gammal );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lgammal_r
long double
SCOREP_LIBWRAP_FUNC_NAME( lgammal_r )( long double scorep_libwrap_arg_1, int * __signgamp )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lgammal_r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lgammal_r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lgammal_r, ( scorep_libwrap_arg_1, __signgamp ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lgammal_r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef rintl
long double
SCOREP_LIBWRAP_FUNC_NAME( rintl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( rintl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( rintl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( rintl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( rintl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nextafterl
long double
SCOREP_LIBWRAP_FUNC_NAME( nextafterl )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nextafterl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nextafterl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nextafterl, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nextafterl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nexttowardl
long double
SCOREP_LIBWRAP_FUNC_NAME( nexttowardl )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nexttowardl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nexttowardl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nexttowardl, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nexttowardl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef remainderl
long double
SCOREP_LIBWRAP_FUNC_NAME( remainderl )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( remainderl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( remainderl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( remainderl, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( remainderl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef ilogbl
int
SCOREP_LIBWRAP_FUNC_NAME( ilogbl )( long double __x )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( ilogbl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( ilogbl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( ilogbl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( ilogbl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef scalblnl
long double
SCOREP_LIBWRAP_FUNC_NAME( scalblnl )( long double __x, long __n )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( scalblnl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( scalblnl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( scalblnl, ( __x, __n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( scalblnl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef nearbyintl
long double
SCOREP_LIBWRAP_FUNC_NAME( nearbyintl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( nearbyintl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( nearbyintl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( nearbyintl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( nearbyintl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef roundl
long double
SCOREP_LIBWRAP_FUNC_NAME( roundl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( roundl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( roundl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( roundl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( roundl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef truncl
long double
SCOREP_LIBWRAP_FUNC_NAME( truncl )( long double __x )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( truncl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( truncl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( truncl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( truncl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef remquol
long double
SCOREP_LIBWRAP_FUNC_NAME( remquol )( long double __x, long double __y, int * __quo )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( remquol );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( remquol );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( remquol, ( __x, __y, __quo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( remquol );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lrintl
long
SCOREP_LIBWRAP_FUNC_NAME( lrintl )( long double __x )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lrintl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lrintl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lrintl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lrintl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef llrintl
long long
SCOREP_LIBWRAP_FUNC_NAME( llrintl )( long double __x )
{
    long long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( llrintl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( llrintl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( llrintl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( llrintl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef lroundl
long
SCOREP_LIBWRAP_FUNC_NAME( lroundl )( long double __x )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( lroundl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( lroundl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( lroundl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( lroundl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef llroundl
long long
SCOREP_LIBWRAP_FUNC_NAME( llroundl )( long double __x )
{
    long long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( llroundl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( llroundl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( llroundl, ( __x ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( llroundl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fdiml
long double
SCOREP_LIBWRAP_FUNC_NAME( fdiml )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fdiml );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fdiml );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fdiml, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fdiml );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fmaxl
long double
SCOREP_LIBWRAP_FUNC_NAME( fmaxl )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fmaxl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fmaxl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fmaxl, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fmaxl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fminl
long double
SCOREP_LIBWRAP_FUNC_NAME( fminl )( long double __x, long double __y )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fminl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fminl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fminl, ( __x, __y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fminl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __fpclassifyl
int
SCOREP_LIBWRAP_FUNC_NAME( __fpclassifyl )( long double __value )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __fpclassifyl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __fpclassifyl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __fpclassifyl, ( __value ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __fpclassifyl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fmal
long double
SCOREP_LIBWRAP_FUNC_NAME( fmal )( long double __x, long double __y, long double __z )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fmal );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fmal );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fmal, ( __x, __y, __z ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fmal );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef scalbl
long double
SCOREP_LIBWRAP_FUNC_NAME( scalbl )( long double __x, long double __n )
{
    long double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( scalbl );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( scalbl );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( scalbl, ( __x, __n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( scalbl );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef matherr
int
SCOREP_LIBWRAP_FUNC_NAME( matherr )( struct exception * __exc )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( matherr );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_math_handle,
                         libwrap_math_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( matherr );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( matherr, ( __exc ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( matherr );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#ifdef __cplusplus
}
#endif
