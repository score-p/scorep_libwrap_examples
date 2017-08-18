#include "libwrap.h"

#define SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ) \
    libwrap_fftw3_region__ ## func

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
#include "scorep_libwrap_fftw3.inc.c"

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static void libwrap_fftw3_init__##func( SCOREP_LibwrapHandle* handle ) \
    { \
        SCOREP_LIBWRAP_FUNC_INIT( handle, func, prettyname, file, line ); \
    }

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_fftw3.inc.c"

/* region init functions */

static void
libwrap_fftw3_init( SCOREP_LibwrapHandle* handle )
{
#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    ns libwrap_fftw3_init__##func( handle );

#include "scorep_libwrap_fftw3.inc.c"
}

#if defined( SCOREP_LIBWRAP_SHARED )

#define LIBWRAP_EARLY_INIT( func ) \
    do \
    { \
        if ( !SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) ) \
        { \
            libwrap_fftw3_early_init(); \
        } \
    } while ( 0 )

/* region early init functions */

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static void libwrap_fftw3_early_init__##func() \
    { \
        SCOREP_Libwrap_EarlySharedPtrInit( #func, ( void** )&SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) ); \
    }

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_fftw3.inc.c"

static void
libwrap_fftw3_early_init()
{
#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    ns libwrap_fftw3_early_init__##func();

#include "scorep_libwrap_fftw3.inc.c"
}

#else

#define LIBWRAP_EARLY_INIT( func ) do { } while ( 0 )

#endif

static const char* libwrap_fftw3_libnames[] = {
    "libfftw3.so",
    "libfftw3f.so"
};
static SCOREP_LibwrapHandle*          libwrap_fftw3_handle;
static const SCOREP_LibwrapAttributes libwrap_fftw3_attributes =
{
    SCOREP_LIBWRAP_VERSION,
    "fftw3",
    "fftw3",
    SCOREP_LIBWRAP_MODE,
    libwrap_fftw3_init,
    2,
    libwrap_fftw3_libnames
};


#undef fftw_execute
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_execute )( const fftw_plan p )
{
    LIBWRAP_EARLY_INIT( fftw_execute );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_execute );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_execute, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_execute );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_plan_dft
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft )( int rank, const int * n, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft, ( rank, n, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_1d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_1d )( int n, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_1d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_1d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_1d, ( n, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_1d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_2d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_2d )( int n0, int n1, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_2d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_2d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_2d, ( n0, n1, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_2d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_3d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_3d )( int n0, int n1, int n2, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_3d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_3d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_3d, ( n0, n1, n2, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_3d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_many_dft
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_many_dft )( int rank, const int * n, int howmany, fftw_complex * in, const int * inembed, int istride, int idist, fftw_complex * out, const int * onembed, int ostride, int odist, int sign, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_many_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_many_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_many_dft, ( rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_many_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru_dft
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru_dft )( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru_dft, ( rank, dims, howmany_rank, howmany_dims, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru_split_dft
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru_split_dft )( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * ri, double * ii, double * ro, double * io, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru_split_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru_split_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru_split_dft, ( rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru_split_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru64_dft
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru64_dft )( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru64_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru64_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru64_dft, ( rank, dims, howmany_rank, howmany_dims, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru64_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru64_split_dft
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru64_split_dft )( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * ri, double * ii, double * ro, double * io, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru64_split_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru64_split_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru64_split_dft, ( rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru64_split_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_execute_dft
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_execute_dft )( const fftw_plan p, fftw_complex * in, fftw_complex * out )
{
    LIBWRAP_EARLY_INIT( fftw_execute_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_execute_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_execute_dft, ( p, in, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_execute_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_execute_split_dft
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_execute_split_dft )( const fftw_plan p, double * ri, double * ii, double * ro, double * io )
{
    LIBWRAP_EARLY_INIT( fftw_execute_split_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_execute_split_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_execute_split_dft, ( p, ri, ii, ro, io ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_execute_split_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_plan_many_dft_r2c
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_many_dft_r2c )( int rank, const int * n, int howmany, double * in, const int * inembed, int istride, int idist, fftw_complex * out, const int * onembed, int ostride, int odist, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_many_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_many_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_many_dft_r2c, ( rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_many_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_r2c
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_r2c )( int rank, const int * n, double * in, fftw_complex * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_r2c, ( rank, n, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_r2c_1d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_r2c_1d )( int n, double * in, fftw_complex * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_r2c_1d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_r2c_1d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_r2c_1d, ( n, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_r2c_1d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_r2c_2d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_r2c_2d )( int n0, int n1, double * in, fftw_complex * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_r2c_2d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_r2c_2d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_r2c_2d, ( n0, n1, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_r2c_2d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_r2c_3d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_r2c_3d )( int n0, int n1, int n2, double * in, fftw_complex * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_r2c_3d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_r2c_3d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_r2c_3d, ( n0, n1, n2, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_r2c_3d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_many_dft_c2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_many_dft_c2r )( int rank, const int * n, int howmany, fftw_complex * in, const int * inembed, int istride, int idist, double * out, const int * onembed, int ostride, int odist, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_many_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_many_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_many_dft_c2r, ( rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_many_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_c2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_c2r )( int rank, const int * n, fftw_complex * in, double * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_c2r, ( rank, n, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_c2r_1d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_c2r_1d )( int n, fftw_complex * in, double * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_c2r_1d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_c2r_1d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_c2r_1d, ( n, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_c2r_1d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_c2r_2d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_c2r_2d )( int n0, int n1, fftw_complex * in, double * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_c2r_2d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_c2r_2d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_c2r_2d, ( n0, n1, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_c2r_2d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_dft_c2r_3d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_dft_c2r_3d )( int n0, int n1, int n2, fftw_complex * in, double * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_dft_c2r_3d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_dft_c2r_3d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_dft_c2r_3d, ( n0, n1, n2, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_dft_c2r_3d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru_dft_r2c
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru_dft_r2c )( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * in, fftw_complex * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru_dft_r2c, ( rank, dims, howmany_rank, howmany_dims, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru_dft_c2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru_dft_c2r )( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, fftw_complex * in, double * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru_dft_c2r, ( rank, dims, howmany_rank, howmany_dims, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru_split_dft_r2c
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru_split_dft_r2c )( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * in, double * ro, double * io, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru_split_dft_r2c, ( rank, dims, howmany_rank, howmany_dims, in, ro, io, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru_split_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru_split_dft_c2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru_split_dft_c2r )( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * ri, double * ii, double * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru_split_dft_c2r, ( rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru_split_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru64_dft_r2c
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru64_dft_r2c )( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * in, fftw_complex * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru64_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru64_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru64_dft_r2c, ( rank, dims, howmany_rank, howmany_dims, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru64_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru64_dft_c2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru64_dft_c2r )( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, fftw_complex * in, double * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru64_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru64_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru64_dft_c2r, ( rank, dims, howmany_rank, howmany_dims, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru64_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru64_split_dft_r2c
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru64_split_dft_r2c )( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * in, double * ro, double * io, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru64_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru64_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru64_split_dft_r2c, ( rank, dims, howmany_rank, howmany_dims, in, ro, io, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru64_split_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru64_split_dft_c2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru64_split_dft_c2r )( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * ri, double * ii, double * out, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru64_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru64_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru64_split_dft_c2r, ( rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru64_split_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_execute_dft_r2c
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_execute_dft_r2c )( const fftw_plan p, double * in, fftw_complex * out )
{
    LIBWRAP_EARLY_INIT( fftw_execute_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_execute_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_execute_dft_r2c, ( p, in, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_execute_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_execute_dft_c2r
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_execute_dft_c2r )( const fftw_plan p, fftw_complex * in, double * out )
{
    LIBWRAP_EARLY_INIT( fftw_execute_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_execute_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_execute_dft_c2r, ( p, in, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_execute_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_execute_split_dft_r2c
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_execute_split_dft_r2c )( const fftw_plan p, double * in, double * ro, double * io )
{
    LIBWRAP_EARLY_INIT( fftw_execute_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_execute_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_execute_split_dft_r2c, ( p, in, ro, io ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_execute_split_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_execute_split_dft_c2r
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_execute_split_dft_c2r )( const fftw_plan p, double * ri, double * ii, double * out )
{
    LIBWRAP_EARLY_INIT( fftw_execute_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_execute_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_execute_split_dft_c2r, ( p, ri, ii, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_execute_split_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_plan_many_r2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_many_r2r )( int rank, const int * n, int howmany, double * in, const int * inembed, int istride, int idist, double * out, const int * onembed, int ostride, int odist, const fftw_r2r_kind * kind, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_many_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_many_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_many_r2r, ( rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_many_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_r2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_r2r )( int rank, const int * n, double * in, double * out, const fftw_r2r_kind * kind, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_r2r, ( rank, n, in, out, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_r2r_1d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_r2r_1d )( int n, double * in, double * out, fftw_r2r_kind kind, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_r2r_1d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_r2r_1d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_r2r_1d, ( n, in, out, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_r2r_1d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_r2r_2d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_r2r_2d )( int n0, int n1, double * in, double * out, fftw_r2r_kind kind0, fftw_r2r_kind kind1, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_r2r_2d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_r2r_2d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_r2r_2d, ( n0, n1, in, out, kind0, kind1, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_r2r_2d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_r2r_3d
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_r2r_3d )( int n0, int n1, int n2, double * in, double * out, fftw_r2r_kind kind0, fftw_r2r_kind kind1, fftw_r2r_kind kind2, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_r2r_3d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_r2r_3d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_r2r_3d, ( n0, n1, n2, in, out, kind0, kind1, kind2, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_r2r_3d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru_r2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru_r2r )( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * in, double * out, const fftw_r2r_kind * kind, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru_r2r, ( rank, dims, howmany_rank, howmany_dims, in, out, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_plan_guru64_r2r
fftw_plan
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_guru64_r2r )( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * in, double * out, const fftw_r2r_kind * kind, unsigned int flags )
{
    fftw_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_plan_guru64_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_guru64_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_guru64_r2r, ( rank, dims, howmany_rank, howmany_dims, in, out, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_guru64_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_execute_r2r
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_execute_r2r )( const fftw_plan p, double * in, double * out )
{
    LIBWRAP_EARLY_INIT( fftw_execute_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_execute_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_execute_r2r, ( p, in, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_execute_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_destroy_plan
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_destroy_plan )( fftw_plan p )
{
    LIBWRAP_EARLY_INIT( fftw_destroy_plan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_destroy_plan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_destroy_plan, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_destroy_plan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_forget_wisdom
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_forget_wisdom )( void )
{
    LIBWRAP_EARLY_INIT( fftw_forget_wisdom );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_forget_wisdom );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_forget_wisdom, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_forget_wisdom );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_cleanup
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_cleanup )( void )
{
    LIBWRAP_EARLY_INIT( fftw_cleanup );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_cleanup );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_cleanup, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_cleanup );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_set_timelimit
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_set_timelimit )( double t )
{
    LIBWRAP_EARLY_INIT( fftw_set_timelimit );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_set_timelimit );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_set_timelimit, ( t ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_set_timelimit );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_plan_with_nthreads
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_plan_with_nthreads )( int nthreads )
{
    LIBWRAP_EARLY_INIT( fftw_plan_with_nthreads );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_plan_with_nthreads );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_plan_with_nthreads, ( nthreads ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_plan_with_nthreads );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_init_threads
int
SCOREP_LIBWRAP_FUNC_NAME( fftw_init_threads )( void )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_init_threads );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_init_threads );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_init_threads, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_init_threads );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_cleanup_threads
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_cleanup_threads )( void )
{
    LIBWRAP_EARLY_INIT( fftw_cleanup_threads );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_cleanup_threads );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_cleanup_threads, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_cleanup_threads );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_export_wisdom_to_filename
int
SCOREP_LIBWRAP_FUNC_NAME( fftw_export_wisdom_to_filename )( const char * filename )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_export_wisdom_to_filename );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_export_wisdom_to_filename );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_export_wisdom_to_filename, ( filename ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_export_wisdom_to_filename );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_export_wisdom_to_file
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_export_wisdom_to_file )( FILE * output_file )
{
    LIBWRAP_EARLY_INIT( fftw_export_wisdom_to_file );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_export_wisdom_to_file );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_export_wisdom_to_file, ( output_file ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_export_wisdom_to_file );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_export_wisdom_to_string
char *
SCOREP_LIBWRAP_FUNC_NAME( fftw_export_wisdom_to_string )( void )
{
    char * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_export_wisdom_to_string );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_export_wisdom_to_string );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_export_wisdom_to_string, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_export_wisdom_to_string );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_export_wisdom
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_export_wisdom )( fftw_write_char_func write_char, void * data )
{
    LIBWRAP_EARLY_INIT( fftw_export_wisdom );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_export_wisdom );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_export_wisdom, ( write_char, data ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_export_wisdom );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_import_system_wisdom
int
SCOREP_LIBWRAP_FUNC_NAME( fftw_import_system_wisdom )( void )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_import_system_wisdom );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_import_system_wisdom );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_import_system_wisdom, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_import_system_wisdom );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_import_wisdom_from_filename
int
SCOREP_LIBWRAP_FUNC_NAME( fftw_import_wisdom_from_filename )( const char * filename )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_import_wisdom_from_filename );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_import_wisdom_from_filename );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_import_wisdom_from_filename, ( filename ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_import_wisdom_from_filename );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_import_wisdom_from_file
int
SCOREP_LIBWRAP_FUNC_NAME( fftw_import_wisdom_from_file )( FILE * input_file )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_import_wisdom_from_file );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_import_wisdom_from_file );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_import_wisdom_from_file, ( input_file ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_import_wisdom_from_file );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_import_wisdom_from_string
int
SCOREP_LIBWRAP_FUNC_NAME( fftw_import_wisdom_from_string )( const char * input_string )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_import_wisdom_from_string );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_import_wisdom_from_string );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_import_wisdom_from_string, ( input_string ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_import_wisdom_from_string );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_import_wisdom
int
SCOREP_LIBWRAP_FUNC_NAME( fftw_import_wisdom )( fftw_read_char_func read_char, void * data )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_import_wisdom );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_import_wisdom );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_import_wisdom, ( read_char, data ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_import_wisdom );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_fprint_plan
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_fprint_plan )( const fftw_plan p, FILE * output_file )
{
    LIBWRAP_EARLY_INIT( fftw_fprint_plan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_fprint_plan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_fprint_plan, ( p, output_file ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_fprint_plan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_print_plan
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_print_plan )( const fftw_plan p )
{
    LIBWRAP_EARLY_INIT( fftw_print_plan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_print_plan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_print_plan, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_print_plan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_sprint_plan
char *
SCOREP_LIBWRAP_FUNC_NAME( fftw_sprint_plan )( const fftw_plan p )
{
    char * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_sprint_plan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_sprint_plan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_sprint_plan, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_sprint_plan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_malloc
void *
SCOREP_LIBWRAP_FUNC_NAME( fftw_malloc )( size_t n )
{
    void * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_malloc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_malloc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_malloc, ( n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_malloc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_alloc_real
double *
SCOREP_LIBWRAP_FUNC_NAME( fftw_alloc_real )( size_t n )
{
    double * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_alloc_real );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_alloc_real );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_alloc_real, ( n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_alloc_real );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_alloc_complex
fftw_complex *
SCOREP_LIBWRAP_FUNC_NAME( fftw_alloc_complex )( size_t n )
{
    fftw_complex * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_alloc_complex );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_alloc_complex );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_alloc_complex, ( n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_alloc_complex );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_free
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_free )( void * p )
{
    LIBWRAP_EARLY_INIT( fftw_free );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_free );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_free, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_free );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_flops
void
SCOREP_LIBWRAP_FUNC_NAME( fftw_flops )( const fftw_plan p, double * add, double * mul, double * fmas )
{
    LIBWRAP_EARLY_INIT( fftw_flops );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_flops );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftw_flops, ( p, add, mul, fmas ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_flops );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftw_estimate_cost
double
SCOREP_LIBWRAP_FUNC_NAME( fftw_estimate_cost )( const fftw_plan p )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_estimate_cost );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_estimate_cost );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_estimate_cost, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_estimate_cost );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_cost
double
SCOREP_LIBWRAP_FUNC_NAME( fftw_cost )( const fftw_plan p )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_cost );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_cost );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_cost, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_cost );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftw_alignment_of
int
SCOREP_LIBWRAP_FUNC_NAME( fftw_alignment_of )( double * p )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftw_alignment_of );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftw_alignment_of );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftw_alignment_of, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftw_alignment_of );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_execute
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_execute )( const fftwf_plan p )
{
    LIBWRAP_EARLY_INIT( fftwf_execute );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_execute );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_execute, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_execute );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_plan_dft
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft )( int rank, const int * n, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft, ( rank, n, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_1d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_1d )( int n, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_1d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_1d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_1d, ( n, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_1d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_2d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_2d )( int n0, int n1, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_2d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_2d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_2d, ( n0, n1, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_2d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_3d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_3d )( int n0, int n1, int n2, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_3d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_3d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_3d, ( n0, n1, n2, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_3d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_many_dft
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_many_dft )( int rank, const int * n, int howmany, fftwf_complex * in, const int * inembed, int istride, int idist, fftwf_complex * out, const int * onembed, int ostride, int odist, int sign, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_many_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_many_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_many_dft, ( rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_many_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru_dft
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru_dft )( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru_dft, ( rank, dims, howmany_rank, howmany_dims, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru_split_dft
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru_split_dft )( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * ri, float * ii, float * ro, float * io, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru_split_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru_split_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru_split_dft, ( rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru_split_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru64_dft
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru64_dft )( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru64_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru64_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru64_dft, ( rank, dims, howmany_rank, howmany_dims, in, out, sign, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru64_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru64_split_dft
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru64_split_dft )( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * ri, float * ii, float * ro, float * io, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru64_split_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru64_split_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru64_split_dft, ( rank, dims, howmany_rank, howmany_dims, ri, ii, ro, io, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru64_split_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_execute_dft
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_execute_dft )( const fftwf_plan p, fftwf_complex * in, fftwf_complex * out )
{
    LIBWRAP_EARLY_INIT( fftwf_execute_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_execute_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_execute_dft, ( p, in, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_execute_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_execute_split_dft
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_execute_split_dft )( const fftwf_plan p, float * ri, float * ii, float * ro, float * io )
{
    LIBWRAP_EARLY_INIT( fftwf_execute_split_dft );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_execute_split_dft );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_execute_split_dft, ( p, ri, ii, ro, io ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_execute_split_dft );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_plan_many_dft_r2c
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_many_dft_r2c )( int rank, const int * n, int howmany, float * in, const int * inembed, int istride, int idist, fftwf_complex * out, const int * onembed, int ostride, int odist, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_many_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_many_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_many_dft_r2c, ( rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_many_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_r2c
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_r2c )( int rank, const int * n, float * in, fftwf_complex * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_r2c, ( rank, n, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_r2c_1d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_r2c_1d )( int n, float * in, fftwf_complex * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_r2c_1d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_r2c_1d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_r2c_1d, ( n, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_r2c_1d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_r2c_2d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_r2c_2d )( int n0, int n1, float * in, fftwf_complex * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_r2c_2d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_r2c_2d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_r2c_2d, ( n0, n1, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_r2c_2d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_r2c_3d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_r2c_3d )( int n0, int n1, int n2, float * in, fftwf_complex * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_r2c_3d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_r2c_3d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_r2c_3d, ( n0, n1, n2, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_r2c_3d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_many_dft_c2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_many_dft_c2r )( int rank, const int * n, int howmany, fftwf_complex * in, const int * inembed, int istride, int idist, float * out, const int * onembed, int ostride, int odist, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_many_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_many_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_many_dft_c2r, ( rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_many_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_c2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_c2r )( int rank, const int * n, fftwf_complex * in, float * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_c2r, ( rank, n, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_c2r_1d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_c2r_1d )( int n, fftwf_complex * in, float * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_c2r_1d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_c2r_1d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_c2r_1d, ( n, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_c2r_1d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_c2r_2d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_c2r_2d )( int n0, int n1, fftwf_complex * in, float * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_c2r_2d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_c2r_2d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_c2r_2d, ( n0, n1, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_c2r_2d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_dft_c2r_3d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_dft_c2r_3d )( int n0, int n1, int n2, fftwf_complex * in, float * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_dft_c2r_3d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_dft_c2r_3d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_dft_c2r_3d, ( n0, n1, n2, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_dft_c2r_3d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru_dft_r2c
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru_dft_r2c )( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * in, fftwf_complex * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru_dft_r2c, ( rank, dims, howmany_rank, howmany_dims, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru_dft_c2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru_dft_c2r )( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, fftwf_complex * in, float * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru_dft_c2r, ( rank, dims, howmany_rank, howmany_dims, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru_split_dft_r2c
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru_split_dft_r2c )( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * in, float * ro, float * io, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru_split_dft_r2c, ( rank, dims, howmany_rank, howmany_dims, in, ro, io, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru_split_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru_split_dft_c2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru_split_dft_c2r )( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * ri, float * ii, float * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru_split_dft_c2r, ( rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru_split_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru64_dft_r2c
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru64_dft_r2c )( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * in, fftwf_complex * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru64_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru64_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru64_dft_r2c, ( rank, dims, howmany_rank, howmany_dims, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru64_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru64_dft_c2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru64_dft_c2r )( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, fftwf_complex * in, float * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru64_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru64_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru64_dft_c2r, ( rank, dims, howmany_rank, howmany_dims, in, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru64_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru64_split_dft_r2c
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru64_split_dft_r2c )( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * in, float * ro, float * io, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru64_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru64_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru64_split_dft_r2c, ( rank, dims, howmany_rank, howmany_dims, in, ro, io, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru64_split_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru64_split_dft_c2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru64_split_dft_c2r )( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * ri, float * ii, float * out, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru64_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru64_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru64_split_dft_c2r, ( rank, dims, howmany_rank, howmany_dims, ri, ii, out, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru64_split_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_execute_dft_r2c
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_execute_dft_r2c )( const fftwf_plan p, float * in, fftwf_complex * out )
{
    LIBWRAP_EARLY_INIT( fftwf_execute_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_execute_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_execute_dft_r2c, ( p, in, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_execute_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_execute_dft_c2r
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_execute_dft_c2r )( const fftwf_plan p, fftwf_complex * in, float * out )
{
    LIBWRAP_EARLY_INIT( fftwf_execute_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_execute_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_execute_dft_c2r, ( p, in, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_execute_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_execute_split_dft_r2c
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_execute_split_dft_r2c )( const fftwf_plan p, float * in, float * ro, float * io )
{
    LIBWRAP_EARLY_INIT( fftwf_execute_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_execute_split_dft_r2c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_execute_split_dft_r2c, ( p, in, ro, io ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_execute_split_dft_r2c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_execute_split_dft_c2r
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_execute_split_dft_c2r )( const fftwf_plan p, float * ri, float * ii, float * out )
{
    LIBWRAP_EARLY_INIT( fftwf_execute_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_execute_split_dft_c2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_execute_split_dft_c2r, ( p, ri, ii, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_execute_split_dft_c2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_plan_many_r2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_many_r2r )( int rank, const int * n, int howmany, float * in, const int * inembed, int istride, int idist, float * out, const int * onembed, int ostride, int odist, const fftwf_r2r_kind * kind, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_many_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_many_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_many_r2r, ( rank, n, howmany, in, inembed, istride, idist, out, onembed, ostride, odist, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_many_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_r2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_r2r )( int rank, const int * n, float * in, float * out, const fftwf_r2r_kind * kind, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_r2r, ( rank, n, in, out, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_r2r_1d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_r2r_1d )( int n, float * in, float * out, fftwf_r2r_kind kind, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_r2r_1d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_r2r_1d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_r2r_1d, ( n, in, out, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_r2r_1d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_r2r_2d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_r2r_2d )( int n0, int n1, float * in, float * out, fftwf_r2r_kind kind0, fftwf_r2r_kind kind1, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_r2r_2d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_r2r_2d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_r2r_2d, ( n0, n1, in, out, kind0, kind1, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_r2r_2d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_r2r_3d
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_r2r_3d )( int n0, int n1, int n2, float * in, float * out, fftwf_r2r_kind kind0, fftwf_r2r_kind kind1, fftwf_r2r_kind kind2, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_r2r_3d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_r2r_3d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_r2r_3d, ( n0, n1, n2, in, out, kind0, kind1, kind2, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_r2r_3d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru_r2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru_r2r )( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * in, float * out, const fftwf_r2r_kind * kind, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru_r2r, ( rank, dims, howmany_rank, howmany_dims, in, out, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_plan_guru64_r2r
fftwf_plan
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_guru64_r2r )( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * in, float * out, const fftwf_r2r_kind * kind, unsigned int flags )
{
    fftwf_plan scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_plan_guru64_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_guru64_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_guru64_r2r, ( rank, dims, howmany_rank, howmany_dims, in, out, kind, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_guru64_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_execute_r2r
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_execute_r2r )( const fftwf_plan p, float * in, float * out )
{
    LIBWRAP_EARLY_INIT( fftwf_execute_r2r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_execute_r2r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_execute_r2r, ( p, in, out ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_execute_r2r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_destroy_plan
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_destroy_plan )( fftwf_plan p )
{
    LIBWRAP_EARLY_INIT( fftwf_destroy_plan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_destroy_plan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_destroy_plan, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_destroy_plan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_forget_wisdom
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_forget_wisdom )( void )
{
    LIBWRAP_EARLY_INIT( fftwf_forget_wisdom );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_forget_wisdom );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_forget_wisdom, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_forget_wisdom );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_cleanup
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_cleanup )( void )
{
    LIBWRAP_EARLY_INIT( fftwf_cleanup );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_cleanup );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_cleanup, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_cleanup );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_set_timelimit
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_set_timelimit )( double t )
{
    LIBWRAP_EARLY_INIT( fftwf_set_timelimit );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_set_timelimit );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_set_timelimit, ( t ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_set_timelimit );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_plan_with_nthreads
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_plan_with_nthreads )( int nthreads )
{
    LIBWRAP_EARLY_INIT( fftwf_plan_with_nthreads );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_plan_with_nthreads );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_plan_with_nthreads, ( nthreads ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_plan_with_nthreads );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_init_threads
int
SCOREP_LIBWRAP_FUNC_NAME( fftwf_init_threads )( void )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_init_threads );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_init_threads );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_init_threads, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_init_threads );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_cleanup_threads
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_cleanup_threads )( void )
{
    LIBWRAP_EARLY_INIT( fftwf_cleanup_threads );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_cleanup_threads );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_cleanup_threads, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_cleanup_threads );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_export_wisdom_to_filename
int
SCOREP_LIBWRAP_FUNC_NAME( fftwf_export_wisdom_to_filename )( const char * filename )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_export_wisdom_to_filename );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_export_wisdom_to_filename );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_export_wisdom_to_filename, ( filename ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_export_wisdom_to_filename );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_export_wisdom_to_file
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_export_wisdom_to_file )( FILE * output_file )
{
    LIBWRAP_EARLY_INIT( fftwf_export_wisdom_to_file );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_export_wisdom_to_file );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_export_wisdom_to_file, ( output_file ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_export_wisdom_to_file );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_export_wisdom_to_string
char *
SCOREP_LIBWRAP_FUNC_NAME( fftwf_export_wisdom_to_string )( void )
{
    char * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_export_wisdom_to_string );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_export_wisdom_to_string );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_export_wisdom_to_string, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_export_wisdom_to_string );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_export_wisdom
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_export_wisdom )( fftwf_write_char_func write_char, void * data )
{
    LIBWRAP_EARLY_INIT( fftwf_export_wisdom );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_export_wisdom );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_export_wisdom, ( write_char, data ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_export_wisdom );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_import_system_wisdom
int
SCOREP_LIBWRAP_FUNC_NAME( fftwf_import_system_wisdom )( void )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_import_system_wisdom );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_import_system_wisdom );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_import_system_wisdom, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_import_system_wisdom );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_import_wisdom_from_filename
int
SCOREP_LIBWRAP_FUNC_NAME( fftwf_import_wisdom_from_filename )( const char * filename )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_import_wisdom_from_filename );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_import_wisdom_from_filename );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_import_wisdom_from_filename, ( filename ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_import_wisdom_from_filename );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_import_wisdom_from_file
int
SCOREP_LIBWRAP_FUNC_NAME( fftwf_import_wisdom_from_file )( FILE * input_file )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_import_wisdom_from_file );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_import_wisdom_from_file );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_import_wisdom_from_file, ( input_file ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_import_wisdom_from_file );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_import_wisdom_from_string
int
SCOREP_LIBWRAP_FUNC_NAME( fftwf_import_wisdom_from_string )( const char * input_string )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_import_wisdom_from_string );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_import_wisdom_from_string );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_import_wisdom_from_string, ( input_string ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_import_wisdom_from_string );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_import_wisdom
int
SCOREP_LIBWRAP_FUNC_NAME( fftwf_import_wisdom )( fftwf_read_char_func read_char, void * data )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_import_wisdom );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_import_wisdom );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_import_wisdom, ( read_char, data ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_import_wisdom );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_fprint_plan
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_fprint_plan )( const fftwf_plan p, FILE * output_file )
{
    LIBWRAP_EARLY_INIT( fftwf_fprint_plan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_fprint_plan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_fprint_plan, ( p, output_file ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_fprint_plan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_print_plan
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_print_plan )( const fftwf_plan p )
{
    LIBWRAP_EARLY_INIT( fftwf_print_plan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_print_plan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_print_plan, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_print_plan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_sprint_plan
char *
SCOREP_LIBWRAP_FUNC_NAME( fftwf_sprint_plan )( const fftwf_plan p )
{
    char * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_sprint_plan );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_sprint_plan );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_sprint_plan, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_sprint_plan );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_malloc
void *
SCOREP_LIBWRAP_FUNC_NAME( fftwf_malloc )( size_t n )
{
    void * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_malloc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_malloc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_malloc, ( n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_malloc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_alloc_real
float *
SCOREP_LIBWRAP_FUNC_NAME( fftwf_alloc_real )( size_t n )
{
    float * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_alloc_real );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_alloc_real );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_alloc_real, ( n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_alloc_real );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_alloc_complex
fftwf_complex *
SCOREP_LIBWRAP_FUNC_NAME( fftwf_alloc_complex )( size_t n )
{
    fftwf_complex * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_alloc_complex );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_alloc_complex );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_alloc_complex, ( n ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_alloc_complex );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_free
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_free )( void * p )
{
    LIBWRAP_EARLY_INIT( fftwf_free );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_free );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_free, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_free );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_flops
void
SCOREP_LIBWRAP_FUNC_NAME( fftwf_flops )( const fftwf_plan p, double * add, double * mul, double * fmas )
{
    LIBWRAP_EARLY_INIT( fftwf_flops );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_flops );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( fftwf_flops, ( p, add, mul, fmas ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_flops );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef fftwf_estimate_cost
double
SCOREP_LIBWRAP_FUNC_NAME( fftwf_estimate_cost )( const fftwf_plan p )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_estimate_cost );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_estimate_cost );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_estimate_cost, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_estimate_cost );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_cost
double
SCOREP_LIBWRAP_FUNC_NAME( fftwf_cost )( const fftwf_plan p )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_cost );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_cost );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_cost, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_cost );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef fftwf_alignment_of
int
SCOREP_LIBWRAP_FUNC_NAME( fftwf_alignment_of )( float * p )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( fftwf_alignment_of );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_fftw3_handle,
                         libwrap_fftw3_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( fftwf_alignment_of );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( fftwf_alignment_of, ( p ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( fftwf_alignment_of );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#ifdef __cplusplus
}
#endif
