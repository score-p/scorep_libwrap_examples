#include "libwrap.h"

#define SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ) \
    libwrap_gmp_region__ ## func

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
#include "scorep_libwrap_gmp.inc.c"

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static void libwrap_gmp_init__##func( SCOREP_LibwrapHandle* handle ) \
    { \
        SCOREP_LIBWRAP_FUNC_INIT( handle, func, prettyname, file, line ); \
    }

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_gmp.inc.c"

/* region init functions */

static void
libwrap_gmp_init( SCOREP_LibwrapHandle* handle )
{
#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    ns libwrap_gmp_init__##func( handle );

#include "scorep_libwrap_gmp.inc.c"
}

#if defined( SCOREP_LIBWRAP_SHARED )

#define LIBWRAP_EARLY_INIT( func ) \
    do \
    { \
        if ( !SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) ) \
        { \
            libwrap_gmp_early_init(); \
        } \
    } while ( 0 )

/* region early init functions */

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static void libwrap_gmp_early_init__##func() \
    { \
        SCOREP_Libwrap_EarlySharedPtrInit( #func, ( void** )&SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) ); \
    }

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_gmp.inc.c"

static void
libwrap_gmp_early_init()
{
#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    ns libwrap_gmp_early_init__##func();

#include "scorep_libwrap_gmp.inc.c"
}

#else

#define LIBWRAP_EARLY_INIT( func ) do { } while ( 0 )

#endif

static const char* libwrap_gmp_libnames[] = {
    "libgmp.so"
};
static SCOREP_LibwrapHandle*          libwrap_gmp_handle;
static const SCOREP_LibwrapAttributes libwrap_gmp_attributes =
{
    SCOREP_LIBWRAP_VERSION,
    "gmp",
    "gmp",
    SCOREP_LIBWRAP_MODE,
    libwrap_gmp_init,
    1,
    libwrap_gmp_libnames
};


#undef __gmp_set_memory_functions
void
SCOREP_LIBWRAP_FUNC_NAME( __gmp_set_memory_functions )( void *(*scorep_libwrap_arg_1)(unsigned long), void *(*scorep_libwrap_arg_2)(void *, unsigned long, unsigned long), void (*scorep_libwrap_arg_3)(void *, unsigned long) )
{
    LIBWRAP_EARLY_INIT( __gmp_set_memory_functions );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_set_memory_functions );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmp_set_memory_functions, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_set_memory_functions );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmp_get_memory_functions
void
SCOREP_LIBWRAP_FUNC_NAME( __gmp_get_memory_functions )( void *(**scorep_libwrap_arg_1)(unsigned long), void *(**scorep_libwrap_arg_2)(void *, unsigned long, unsigned long), void (**scorep_libwrap_arg_3)(void *, unsigned long) )
{
    LIBWRAP_EARLY_INIT( __gmp_get_memory_functions );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_get_memory_functions );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmp_get_memory_functions, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_get_memory_functions );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmp_randinit_default
void
SCOREP_LIBWRAP_FUNC_NAME( __gmp_randinit_default )( __gmp_randstate_struct scorep_libwrap_arg_1[1] )
{
    LIBWRAP_EARLY_INIT( __gmp_randinit_default );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_randinit_default );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmp_randinit_default, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_randinit_default );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmp_randinit_lc_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmp_randinit_lc_2exp )( __gmp_randstate_struct scorep_libwrap_arg_1[1], const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmp_randinit_lc_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_randinit_lc_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmp_randinit_lc_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_randinit_lc_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmp_randinit_lc_2exp_size
int
SCOREP_LIBWRAP_FUNC_NAME( __gmp_randinit_lc_2exp_size )( __gmp_randstate_struct scorep_libwrap_arg_1[1], unsigned long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmp_randinit_lc_2exp_size );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_randinit_lc_2exp_size );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmp_randinit_lc_2exp_size, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_randinit_lc_2exp_size );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmp_randinit_mt
void
SCOREP_LIBWRAP_FUNC_NAME( __gmp_randinit_mt )( __gmp_randstate_struct scorep_libwrap_arg_1[1] )
{
    LIBWRAP_EARLY_INIT( __gmp_randinit_mt );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_randinit_mt );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmp_randinit_mt, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_randinit_mt );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmp_randinit_set
void
SCOREP_LIBWRAP_FUNC_NAME( __gmp_randinit_set )( __gmp_randstate_struct scorep_libwrap_arg_1[1], const __gmp_randstate_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmp_randinit_set );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_randinit_set );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmp_randinit_set, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_randinit_set );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmp_randseed
void
SCOREP_LIBWRAP_FUNC_NAME( __gmp_randseed )( __gmp_randstate_struct scorep_libwrap_arg_1[1], const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmp_randseed );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_randseed );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmp_randseed, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_randseed );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmp_randseed_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmp_randseed_ui )( __gmp_randstate_struct scorep_libwrap_arg_1[1], unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmp_randseed_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_randseed_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmp_randseed_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_randseed_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmp_randclear
void
SCOREP_LIBWRAP_FUNC_NAME( __gmp_randclear )( __gmp_randstate_struct scorep_libwrap_arg_1[1] )
{
    LIBWRAP_EARLY_INIT( __gmp_randclear );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_randclear );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmp_randclear, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_randclear );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmp_urandomb_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmp_urandomb_ui )( __gmp_randstate_struct scorep_libwrap_arg_1[1], unsigned long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmp_urandomb_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_urandomb_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmp_urandomb_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_urandomb_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmp_urandomm_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmp_urandomm_ui )( __gmp_randstate_struct scorep_libwrap_arg_1[1], unsigned long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmp_urandomm_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmp_urandomm_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmp_urandomm_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmp_urandomm_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_realloc
void *
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_realloc )( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    void * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_realloc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_realloc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_realloc, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_realloc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_abs
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_abs )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_abs );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_abs );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_abs, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_abs );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_add
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_add )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_add );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_add );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_add, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_add );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_add_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_add_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_add_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_add_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_add_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_add_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_addmul
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_addmul )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_addmul );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_addmul );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_addmul, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_addmul );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_addmul_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_addmul_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_addmul_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_addmul_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_addmul_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_addmul_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_and
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_and )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_and );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_and );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_and, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_and );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_array_init
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_array_init )( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_array_init );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_array_init );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_array_init, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_array_init );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_bin_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_bin_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_bin_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_bin_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_bin_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_bin_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_bin_uiui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_bin_uiui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_bin_uiui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_bin_uiui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_bin_uiui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_bin_uiui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_cdiv_q
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cdiv_q )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_cdiv_q );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cdiv_q );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cdiv_q, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cdiv_q );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_cdiv_q_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cdiv_q_2exp )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_cdiv_q_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cdiv_q_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cdiv_q_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cdiv_q_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_cdiv_q_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cdiv_q_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cdiv_q_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cdiv_q_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cdiv_q_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cdiv_q_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_cdiv_qr
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cdiv_qr )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpz_cdiv_qr );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cdiv_qr );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cdiv_qr, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cdiv_qr );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_cdiv_qr_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cdiv_qr_ui )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cdiv_qr_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cdiv_qr_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cdiv_qr_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cdiv_qr_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_cdiv_r
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cdiv_r )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_cdiv_r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cdiv_r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cdiv_r, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cdiv_r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_cdiv_r_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cdiv_r_2exp )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_cdiv_r_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cdiv_r_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cdiv_r_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cdiv_r_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_cdiv_r_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cdiv_r_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cdiv_r_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cdiv_r_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cdiv_r_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cdiv_r_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_cdiv_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cdiv_ui )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cdiv_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cdiv_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cdiv_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cdiv_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_clear
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_clear )( __mpz_struct * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpz_clear );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_clear );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_clear, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_clear );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_clrbit
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_clrbit )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_clrbit );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_clrbit );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_clrbit, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_clrbit );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_cmp
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cmp )( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cmp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cmp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cmp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cmp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_cmp_d
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cmp_d )( const __mpz_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cmp_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cmp_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cmp_d, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cmp_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_cmp_si
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cmp_si )( const __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cmp_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cmp_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cmp_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cmp_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_cmp_ui
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cmp_ui )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cmp_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cmp_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cmp_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cmp_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_cmpabs
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cmpabs )( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cmpabs );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cmpabs );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cmpabs, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cmpabs );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_cmpabs_d
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cmpabs_d )( const __mpz_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cmpabs_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cmpabs_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cmpabs_d, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cmpabs_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_cmpabs_ui
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_cmpabs_ui )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_cmpabs_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_cmpabs_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_cmpabs_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_cmpabs_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_com
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_com )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_com );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_com );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_com, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_com );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_combit
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_combit )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_combit );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_combit );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_combit, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_combit );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_congruent_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_congruent_p )( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_congruent_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_congruent_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_congruent_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_congruent_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_congruent_2exp_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_congruent_2exp_p )( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_congruent_2exp_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_congruent_2exp_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_congruent_2exp_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_congruent_2exp_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_congruent_ui_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_congruent_ui_p )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_congruent_ui_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_congruent_ui_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_congruent_ui_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_congruent_ui_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_divexact
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_divexact )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_divexact );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_divexact );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_divexact, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_divexact );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_divexact_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_divexact_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_divexact_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_divexact_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_divexact_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_divexact_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_divisible_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_divisible_p )( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_divisible_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_divisible_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_divisible_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_divisible_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_divisible_ui_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_divisible_ui_p )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_divisible_ui_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_divisible_ui_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_divisible_ui_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_divisible_ui_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_divisible_2exp_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_divisible_2exp_p )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_divisible_2exp_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_divisible_2exp_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_divisible_2exp_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_divisible_2exp_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_dump
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_dump )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpz_dump );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_dump );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_dump, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_dump );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_export
void *
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_export )( void * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, int scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, int scorep_libwrap_arg_5, unsigned long scorep_libwrap_arg_6, const __mpz_struct * scorep_libwrap_arg_7 )
{
    void * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_export );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_export );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_export, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5, scorep_libwrap_arg_6, scorep_libwrap_arg_7 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_export );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fac_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fac_ui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_fac_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fac_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fac_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fac_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_2fac_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_2fac_ui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_2fac_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_2fac_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_2fac_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_2fac_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_mfac_uiui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_mfac_uiui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_mfac_uiui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_mfac_uiui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_mfac_uiui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_mfac_uiui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_primorial_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_primorial_ui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_primorial_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_primorial_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_primorial_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_primorial_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_fdiv_q
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fdiv_q )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_fdiv_q );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fdiv_q );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fdiv_q, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fdiv_q );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_fdiv_q_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fdiv_q_2exp )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_fdiv_q_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fdiv_q_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fdiv_q_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fdiv_q_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_fdiv_q_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fdiv_q_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fdiv_q_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fdiv_q_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fdiv_q_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fdiv_q_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fdiv_qr
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fdiv_qr )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpz_fdiv_qr );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fdiv_qr );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fdiv_qr, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fdiv_qr );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_fdiv_qr_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fdiv_qr_ui )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fdiv_qr_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fdiv_qr_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fdiv_qr_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fdiv_qr_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fdiv_r
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fdiv_r )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_fdiv_r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fdiv_r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fdiv_r, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fdiv_r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_fdiv_r_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fdiv_r_2exp )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_fdiv_r_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fdiv_r_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fdiv_r_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fdiv_r_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_fdiv_r_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fdiv_r_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fdiv_r_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fdiv_r_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fdiv_r_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fdiv_r_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fdiv_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fdiv_ui )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fdiv_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fdiv_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fdiv_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fdiv_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fib_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fib_ui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_fib_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fib_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fib_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fib_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_fib2_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fib2_ui )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_fib2_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fib2_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fib2_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fib2_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_fits_sint_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fits_sint_p )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fits_sint_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fits_sint_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fits_sint_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fits_sint_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fits_slong_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fits_slong_p )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fits_slong_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fits_slong_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fits_slong_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fits_slong_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fits_sshort_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fits_sshort_p )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fits_sshort_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fits_sshort_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fits_sshort_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fits_sshort_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fits_uint_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fits_uint_p )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fits_uint_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fits_uint_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fits_uint_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fits_uint_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fits_ulong_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fits_ulong_p )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fits_ulong_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fits_ulong_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fits_ulong_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fits_ulong_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_fits_ushort_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_fits_ushort_p )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_fits_ushort_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_fits_ushort_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_fits_ushort_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_fits_ushort_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_gcd
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_gcd )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_gcd );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_gcd );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_gcd, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_gcd );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_gcd_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_gcd_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_gcd_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_gcd_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_gcd_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_gcd_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_gcdext
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_gcdext )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4, const __mpz_struct * scorep_libwrap_arg_5 )
{
    LIBWRAP_EARLY_INIT( __gmpz_gcdext );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_gcdext );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_gcdext, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_gcdext );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_get_d
double
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_get_d )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_get_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_get_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_get_d, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_get_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_get_d_2exp
double
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_get_d_2exp )( long * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_get_d_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_get_d_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_get_d_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_get_d_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_get_si
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_get_si )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_get_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_get_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_get_si, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_get_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_get_str
char *
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_get_str )( char * scorep_libwrap_arg_1, int scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    char * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_get_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_get_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_get_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_get_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_get_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_get_ui )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_get_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_get_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_get_ui, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_get_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_getlimbn
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_getlimbn )( const __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_getlimbn );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_getlimbn );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_getlimbn, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_getlimbn );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_hamdist
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_hamdist )( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_hamdist );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_hamdist );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_hamdist, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_hamdist );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_import
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_import )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, int scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, int scorep_libwrap_arg_5, unsigned long scorep_libwrap_arg_6, const void * scorep_libwrap_arg_7 )
{
    LIBWRAP_EARLY_INIT( __gmpz_import );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_import );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_import, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5, scorep_libwrap_arg_6, scorep_libwrap_arg_7 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_import );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_init
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_init )( __mpz_struct * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpz_init );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_init );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_init, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_init );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_init2
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_init2 )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_init2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_init2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_init2, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_init2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_init_set
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_init_set )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_init_set );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_init_set );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_init_set, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_init_set );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_init_set_d
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_init_set_d )( __mpz_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_init_set_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_init_set_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_init_set_d, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_init_set_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_init_set_si
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_init_set_si )( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_init_set_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_init_set_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_init_set_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_init_set_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_init_set_str
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_init_set_str )( __mpz_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_init_set_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_init_set_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_init_set_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_init_set_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_init_set_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_init_set_ui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_init_set_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_init_set_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_init_set_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_init_set_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_invert
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_invert )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_invert );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_invert );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_invert, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_invert );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_ior
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_ior )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_ior );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_ior );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_ior, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_ior );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_jacobi
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_jacobi )( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_jacobi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_jacobi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_jacobi, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_jacobi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_kronecker_si
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_kronecker_si )( const __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_kronecker_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_kronecker_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_kronecker_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_kronecker_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_kronecker_ui
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_kronecker_ui )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_kronecker_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_kronecker_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_kronecker_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_kronecker_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_si_kronecker
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_si_kronecker )( long scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_si_kronecker );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_si_kronecker );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_si_kronecker, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_si_kronecker );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_ui_kronecker
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_ui_kronecker )( unsigned long scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_ui_kronecker );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_ui_kronecker );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_ui_kronecker, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_ui_kronecker );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_lcm
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_lcm )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_lcm );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_lcm );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_lcm, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_lcm );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_lcm_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_lcm_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_lcm_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_lcm_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_lcm_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_lcm_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_lucnum_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_lucnum_ui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_lucnum_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_lucnum_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_lucnum_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_lucnum_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_lucnum2_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_lucnum2_ui )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_lucnum2_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_lucnum2_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_lucnum2_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_lucnum2_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_millerrabin
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_millerrabin )( const __mpz_struct * scorep_libwrap_arg_1, int scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_millerrabin );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_millerrabin );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_millerrabin, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_millerrabin );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_mod
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_mod )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_mod );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_mod );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_mod, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_mod );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_mul
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_mul )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_mul );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_mul );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_mul, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_mul );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_mul_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_mul_2exp )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_mul_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_mul_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_mul_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_mul_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_mul_si
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_mul_si )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_mul_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_mul_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_mul_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_mul_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_mul_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_mul_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_mul_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_mul_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_mul_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_mul_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_neg
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_neg )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_neg );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_neg );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_neg, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_neg );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_nextprime
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_nextprime )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_nextprime );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_nextprime );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_nextprime, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_nextprime );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_perfect_power_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_perfect_power_p )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_perfect_power_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_perfect_power_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_perfect_power_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_perfect_power_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_perfect_square_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_perfect_square_p )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_perfect_square_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_perfect_square_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_perfect_square_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_perfect_square_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_popcount
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_popcount )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_popcount );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_popcount );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_popcount, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_popcount );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_pow_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_pow_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_pow_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_pow_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_pow_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_pow_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_powm
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_powm )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpz_powm );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_powm );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_powm, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_powm );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_powm_sec
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_powm_sec )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpz_powm_sec );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_powm_sec );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_powm_sec, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_powm_sec );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_powm_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_powm_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpz_powm_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_powm_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_powm_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_powm_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_probab_prime_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_probab_prime_p )( const __mpz_struct * scorep_libwrap_arg_1, int scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_probab_prime_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_probab_prime_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_probab_prime_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_probab_prime_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_random
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_random )( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_random );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_random );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_random, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_random );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_random2
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_random2 )( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_random2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_random2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_random2, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_random2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_realloc2
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_realloc2 )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_realloc2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_realloc2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_realloc2, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_realloc2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_remove
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_remove )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_remove );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_remove );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_remove, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_remove );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_root
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_root )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_root );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_root );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_root, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_root );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_rootrem
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_rootrem )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpz_rootrem );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_rootrem );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_rootrem, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_rootrem );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_rrandomb
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_rrandomb )( __mpz_struct * scorep_libwrap_arg_1, __gmp_randstate_struct scorep_libwrap_arg_2[1], unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_rrandomb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_rrandomb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_rrandomb, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_rrandomb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_scan0
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_scan0 )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_scan0 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_scan0 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_scan0, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_scan0 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_scan1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_scan1 )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_scan1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_scan1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_scan1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_scan1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_set
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_set )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_set );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_set );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_set, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_set );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_set_d
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_set_d )( __mpz_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_set_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_set_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_set_d, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_set_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_set_f
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_set_f )( __mpz_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_set_f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_set_f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_set_f, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_set_f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_set_q
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_set_q )( __mpz_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_set_q );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_set_q );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_set_q, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_set_q );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_set_si
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_set_si )( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_set_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_set_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_set_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_set_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_set_str
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_set_str )( __mpz_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_set_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_set_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_set_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_set_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_set_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_set_ui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_set_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_set_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_set_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_set_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_setbit
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_setbit )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_setbit );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_setbit );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_setbit, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_setbit );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_size
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_size )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_size );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_size );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_size, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_size );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_sizeinbase
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_sizeinbase )( const __mpz_struct * scorep_libwrap_arg_1, int scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_sizeinbase );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_sizeinbase );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_sizeinbase, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_sizeinbase );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_sqrt
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_sqrt )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_sqrt );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_sqrt );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_sqrt, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_sqrt );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_sqrtrem
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_sqrtrem )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_sqrtrem );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_sqrtrem );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_sqrtrem, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_sqrtrem );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_sub
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_sub )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_sub );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_sub );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_sub, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_sub );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_sub_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_sub_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_sub_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_sub_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_sub_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_sub_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_ui_sub
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_ui_sub )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_ui_sub );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_ui_sub );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_ui_sub, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_ui_sub );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_submul
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_submul )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_submul );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_submul );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_submul, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_submul );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_submul_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_submul_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_submul_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_submul_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_submul_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_submul_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_swap
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_swap )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_swap );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_swap );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_swap, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_swap );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_tdiv_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tdiv_ui )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_tdiv_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tdiv_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tdiv_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tdiv_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_tdiv_q
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tdiv_q )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_tdiv_q );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tdiv_q );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tdiv_q, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tdiv_q );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_tdiv_q_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tdiv_q_2exp )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_tdiv_q_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tdiv_q_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tdiv_q_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tdiv_q_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_tdiv_q_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tdiv_q_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_tdiv_q_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tdiv_q_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tdiv_q_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tdiv_q_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_tdiv_qr
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tdiv_qr )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpz_tdiv_qr );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tdiv_qr );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tdiv_qr, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tdiv_qr );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_tdiv_qr_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tdiv_qr_ui )( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_tdiv_qr_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tdiv_qr_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tdiv_qr_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tdiv_qr_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_tdiv_r
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tdiv_r )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_tdiv_r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tdiv_r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tdiv_r, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tdiv_r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_tdiv_r_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tdiv_r_2exp )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_tdiv_r_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tdiv_r_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tdiv_r_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tdiv_r_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_tdiv_r_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tdiv_r_ui )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_tdiv_r_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tdiv_r_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tdiv_r_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tdiv_r_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_tstbit
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_tstbit )( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_tstbit );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_tstbit );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_tstbit, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_tstbit );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_ui_pow_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_ui_pow_ui )( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_ui_pow_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_ui_pow_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_ui_pow_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_ui_pow_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_urandomb
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_urandomb )( __mpz_struct * scorep_libwrap_arg_1, __gmp_randstate_struct scorep_libwrap_arg_2[1], unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_urandomb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_urandomb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_urandomb, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_urandomb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_urandomm
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_urandomm )( __mpz_struct * scorep_libwrap_arg_1, __gmp_randstate_struct scorep_libwrap_arg_2[1], const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_urandomm );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_urandomm );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_urandomm, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_urandomm );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_xor
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_xor )( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpz_xor );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_xor );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_xor, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_xor );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_limbs_read
const unsigned long *
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_limbs_read )( const __mpz_struct * scorep_libwrap_arg_1 )
{
    const unsigned long * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_limbs_read );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_limbs_read );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_limbs_read, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_limbs_read );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_limbs_write
unsigned long *
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_limbs_write )( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    unsigned long * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_limbs_write );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_limbs_write );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_limbs_write, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_limbs_write );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_limbs_modify
unsigned long *
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_limbs_modify )( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    unsigned long * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_limbs_modify );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_limbs_modify );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_limbs_modify, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_limbs_modify );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpz_limbs_finish
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_limbs_finish )( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpz_limbs_finish );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_limbs_finish );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpz_limbs_finish, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_limbs_finish );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpz_roinit_n
const __mpz_struct *
SCOREP_LIBWRAP_FUNC_NAME( __gmpz_roinit_n )( __mpz_struct * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    const __mpz_struct * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpz_roinit_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpz_roinit_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpz_roinit_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpz_roinit_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpq_abs
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_abs )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_abs );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_abs );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_abs, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_abs );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_add
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_add )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpq_add );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_add );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_add, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_add );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_canonicalize
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_canonicalize )( __mpq_struct * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpq_canonicalize );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_canonicalize );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_canonicalize, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_canonicalize );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_clear
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_clear )( __mpq_struct * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpq_clear );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_clear );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_clear, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_clear );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_cmp
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_cmp )( const __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpq_cmp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_cmp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpq_cmp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_cmp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpq_cmp_si
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_cmp_si )( const __mpq_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpq_cmp_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_cmp_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpq_cmp_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_cmp_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpq_cmp_ui
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_cmp_ui )( const __mpq_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpq_cmp_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_cmp_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpq_cmp_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_cmp_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpq_cmp_z
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_cmp_z )( const __mpq_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpq_cmp_z );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_cmp_z );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpq_cmp_z, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_cmp_z );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpq_div
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_div )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpq_div );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_div );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_div, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_div );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_div_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_div_2exp )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpq_div_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_div_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_div_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_div_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_equal
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_equal )( const __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpq_equal );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_equal );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpq_equal, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_equal );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpq_get_num
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_get_num )( __mpz_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_get_num );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_get_num );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_get_num, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_get_num );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_get_den
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_get_den )( __mpz_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_get_den );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_get_den );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_get_den, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_get_den );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_get_d
double
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_get_d )( const __mpq_struct * scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpq_get_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_get_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpq_get_d, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_get_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpq_get_str
char *
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_get_str )( char * scorep_libwrap_arg_1, int scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 )
{
    char * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpq_get_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_get_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpq_get_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_get_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpq_init
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_init )( __mpq_struct * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpq_init );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_init );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_init, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_init );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_inv
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_inv )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_inv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_inv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_inv, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_inv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_mul
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_mul )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpq_mul );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_mul );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_mul, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_mul );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_mul_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_mul_2exp )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpq_mul_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_mul_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_mul_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_mul_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_neg
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_neg )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_neg );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_neg );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_neg, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_neg );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_set
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_set )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_set );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_set );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_set, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_set );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_set_d
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_set_d )( __mpq_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_set_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_set_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_set_d, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_set_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_set_den
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_set_den )( __mpq_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_set_den );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_set_den );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_set_den, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_set_den );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_set_f
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_set_f )( __mpq_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_set_f );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_set_f );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_set_f, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_set_f );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_set_num
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_set_num )( __mpq_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_set_num );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_set_num );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_set_num, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_set_num );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_set_si
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_set_si )( __mpq_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpq_set_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_set_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_set_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_set_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_set_str
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_set_str )( __mpq_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpq_set_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_set_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpq_set_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_set_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpq_set_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_set_ui )( __mpq_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpq_set_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_set_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_set_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_set_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_set_z
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_set_z )( __mpq_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_set_z );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_set_z );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_set_z, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_set_z );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_sub
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_sub )( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpq_sub );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_sub );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_sub, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_sub );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpq_swap
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpq_swap )( __mpq_struct * scorep_libwrap_arg_1, __mpq_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpq_swap );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpq_swap );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpq_swap, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpq_swap );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_abs
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_abs )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_abs );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_abs );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_abs, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_abs );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_add
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_add )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_add );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_add );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_add, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_add );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_add_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_add_ui )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_add_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_add_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_add_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_add_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_ceil
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_ceil )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_ceil );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_ceil );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_ceil, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_ceil );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_clear
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_clear )( __mpf_struct * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpf_clear );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_clear );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_clear, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_clear );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_cmp
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_cmp )( const __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_cmp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_cmp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_cmp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_cmp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_cmp_z
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_cmp_z )( const __mpf_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_cmp_z );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_cmp_z );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_cmp_z, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_cmp_z );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_cmp_d
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_cmp_d )( const __mpf_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_cmp_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_cmp_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_cmp_d, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_cmp_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_cmp_si
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_cmp_si )( const __mpf_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_cmp_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_cmp_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_cmp_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_cmp_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_cmp_ui
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_cmp_ui )( const __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_cmp_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_cmp_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_cmp_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_cmp_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_div
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_div )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_div );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_div );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_div, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_div );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_div_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_div_2exp )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_div_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_div_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_div_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_div_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_div_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_div_ui )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_div_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_div_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_div_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_div_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_dump
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_dump )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpf_dump );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_dump );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_dump, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_dump );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_eq
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_eq )( const __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_eq );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_eq );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_eq, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_eq );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_fits_sint_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_fits_sint_p )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_fits_sint_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_fits_sint_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_fits_sint_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_fits_sint_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_fits_slong_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_fits_slong_p )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_fits_slong_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_fits_slong_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_fits_slong_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_fits_slong_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_fits_sshort_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_fits_sshort_p )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_fits_sshort_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_fits_sshort_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_fits_sshort_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_fits_sshort_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_fits_uint_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_fits_uint_p )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_fits_uint_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_fits_uint_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_fits_uint_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_fits_uint_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_fits_ulong_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_fits_ulong_p )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_fits_ulong_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_fits_ulong_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_fits_ulong_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_fits_ulong_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_fits_ushort_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_fits_ushort_p )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_fits_ushort_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_fits_ushort_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_fits_ushort_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_fits_ushort_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_floor
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_floor )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_floor );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_floor );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_floor, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_floor );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_get_d
double
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_get_d )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_get_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_get_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_get_d, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_get_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_get_d_2exp
double
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_get_d_2exp )( long * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    double scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_get_d_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_get_d_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_get_d_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_get_d_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_get_default_prec
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_get_default_prec )( void )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_get_default_prec );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_get_default_prec );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_get_default_prec, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_get_default_prec );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_get_prec
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_get_prec )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_get_prec );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_get_prec );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_get_prec, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_get_prec );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_get_si
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_get_si )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_get_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_get_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_get_si, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_get_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_get_str
char *
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_get_str )( char * scorep_libwrap_arg_1, long * scorep_libwrap_arg_2, int scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, const __mpf_struct * scorep_libwrap_arg_5 )
{
    char * scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_get_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_get_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_get_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_get_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_get_ui
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_get_ui )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_get_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_get_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_get_ui, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_get_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_init
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_init )( __mpf_struct * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpf_init );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_init );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_init, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_init );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_init2
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_init2 )( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_init2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_init2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_init2, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_init2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_init_set
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_init_set )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_init_set );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_init_set );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_init_set, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_init_set );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_init_set_d
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_init_set_d )( __mpf_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_init_set_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_init_set_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_init_set_d, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_init_set_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_init_set_si
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_init_set_si )( __mpf_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_init_set_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_init_set_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_init_set_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_init_set_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_init_set_str
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_init_set_str )( __mpf_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_init_set_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_init_set_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_init_set_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_init_set_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_init_set_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_init_set_ui )( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_init_set_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_init_set_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_init_set_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_init_set_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_integer_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_integer_p )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_integer_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_integer_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_integer_p, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_integer_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_mul
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_mul )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_mul );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_mul );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_mul, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_mul );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_mul_2exp
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_mul_2exp )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_mul_2exp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_mul_2exp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_mul_2exp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_mul_2exp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_mul_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_mul_ui )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_mul_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_mul_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_mul_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_mul_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_neg
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_neg )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_neg );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_neg );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_neg, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_neg );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_pow_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_pow_ui )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_pow_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_pow_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_pow_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_pow_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_random2
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_random2 )( __mpf_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_random2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_random2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_random2, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_random2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_reldiff
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_reldiff )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_reldiff );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_reldiff );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_reldiff, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_reldiff );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_set
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_set );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_set_d
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set_d )( __mpf_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_set_d );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set_d );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set_d, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set_d );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_set_default_prec
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set_default_prec )( unsigned long scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( __gmpf_set_default_prec );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set_default_prec );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set_default_prec, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set_default_prec );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_set_prec
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set_prec )( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_set_prec );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set_prec );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set_prec, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set_prec );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_set_prec_raw
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set_prec_raw )( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_set_prec_raw );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set_prec_raw );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set_prec_raw, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set_prec_raw );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_set_q
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set_q )( __mpf_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_set_q );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set_q );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set_q, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set_q );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_set_si
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set_si )( __mpf_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_set_si );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set_si );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set_si, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set_si );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_set_str
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set_str )( __mpf_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_set_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_set_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set_ui )( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_set_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_set_z
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_set_z )( __mpf_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_set_z );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_set_z );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_set_z, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_set_z );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_size
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_size )( const __mpf_struct * scorep_libwrap_arg_1 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpf_size );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_size );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpf_size, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_size );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpf_sqrt
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_sqrt )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_sqrt );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_sqrt );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_sqrt, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_sqrt );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_sqrt_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_sqrt_ui )( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_sqrt_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_sqrt_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_sqrt_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_sqrt_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_sub
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_sub )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_sub );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_sub );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_sub, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_sub );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_sub_ui
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_sub_ui )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_sub_ui );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_sub_ui );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_sub_ui, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_sub_ui );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_swap
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_swap )( __mpf_struct * scorep_libwrap_arg_1, __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_swap );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_swap );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_swap, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_swap );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_trunc
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_trunc )( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpf_trunc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_trunc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_trunc, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_trunc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_ui_div
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_ui_div )( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_ui_div );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_ui_div );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_ui_div, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_ui_div );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_ui_sub
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_ui_sub )( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_ui_sub );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_ui_sub );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_ui_sub, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_ui_sub );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpf_urandomb
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpf_urandomb )( __mpf_struct scorep_libwrap_arg_1[1], __gmp_randstate_struct scorep_libwrap_arg_2[1], unsigned long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpf_urandomb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpf_urandomb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpf_urandomb, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpf_urandomb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_add
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_add )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_add );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_add );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_add, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_add );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_add_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_add_1 )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_add_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_add_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_add_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_add_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_add_n
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_add_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_add_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_add_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_add_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_add_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_addmul_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_addmul_1 )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_addmul_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_addmul_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_addmul_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_addmul_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_cmp
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_cmp )( const unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_cmp );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_cmp );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_cmp, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_cmp );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_zero_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_zero_p )( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_zero_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_zero_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_zero_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_zero_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_divexact_1
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_divexact_1 )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_divexact_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_divexact_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_divexact_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_divexact_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_divexact_by3c
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_divexact_by3c )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_divexact_by3c );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_divexact_by3c );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_divexact_by3c, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_divexact_by3c );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_divrem
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_divrem )( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, const unsigned long * scorep_libwrap_arg_5, long scorep_libwrap_arg_6 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_divrem );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_divrem );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_divrem, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5, scorep_libwrap_arg_6 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_divrem );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_divrem_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_divrem_1 )( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, unsigned long scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_divrem_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_divrem_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_divrem_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_divrem_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_divrem_2
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_divrem_2 )( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, const unsigned long * scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_divrem_2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_divrem_2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_divrem_2, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_divrem_2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_div_qr_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_div_qr_1 )( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, unsigned long scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_div_qr_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_div_qr_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_div_qr_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_div_qr_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_div_qr_2
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_div_qr_2 )( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, const unsigned long * scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_div_qr_2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_div_qr_2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_div_qr_2, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_div_qr_2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_gcd
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_gcd )( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_gcd );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_gcd );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_gcd, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_gcd );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_gcd_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_gcd_1 )( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_gcd_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_gcd_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_gcd_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_gcd_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_gcdext_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_gcdext_1 )( long * scorep_libwrap_arg_1, long * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_gcdext_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_gcdext_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_gcdext_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_gcdext_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_gcdext
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_gcdext )( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, long * scorep_libwrap_arg_3, unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5, unsigned long * scorep_libwrap_arg_6, long scorep_libwrap_arg_7 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_gcdext );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_gcdext );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_gcdext, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5, scorep_libwrap_arg_6, scorep_libwrap_arg_7 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_gcdext );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_get_str
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_get_str )( unsigned char * scorep_libwrap_arg_1, int scorep_libwrap_arg_2, unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_get_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_get_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_get_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_get_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_hamdist
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_hamdist )( const unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_hamdist );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_hamdist );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_hamdist, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_hamdist );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_lshift
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_lshift )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned int scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_lshift );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_lshift );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_lshift, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_lshift );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_mod_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_mod_1 )( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_mod_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_mod_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_mod_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_mod_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_mul
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_mul )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_mul );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_mul );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_mul, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_mul );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_mul_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_mul_1 )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_mul_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_mul_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_mul_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_mul_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_mul_n
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_mul_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_mul_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_mul_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_mul_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_mul_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_sqr
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sqr )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpn_sqr );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sqr );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sqr, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sqr );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_neg
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_neg )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_neg );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_neg );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_neg, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_neg );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_com
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_com )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpn_com );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_com );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_com, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_com );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_perfect_square_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_perfect_square_p )( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_perfect_square_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_perfect_square_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_perfect_square_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_perfect_square_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_perfect_power_p
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_perfect_power_p )( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_perfect_power_p );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_perfect_power_p );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_perfect_power_p, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_perfect_power_p );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_popcount
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_popcount )( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_popcount );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_popcount );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_popcount, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_popcount );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_pow_1
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_pow_1 )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, unsigned long * scorep_libwrap_arg_5 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_pow_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_pow_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_pow_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_pow_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_preinv_mod_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_preinv_mod_1 )( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_preinv_mod_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_preinv_mod_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_preinv_mod_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_preinv_mod_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_random
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_random )( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpn_random );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_random );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_random, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_random );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_random2
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_random2 )( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpn_random2 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_random2 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_random2, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_random2 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_rshift
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_rshift )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned int scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_rshift );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_rshift );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_rshift, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_rshift );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_scan0
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_scan0 )( const unsigned long * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_scan0 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_scan0 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_scan0, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_scan0 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_scan1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_scan1 )( const unsigned long * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_scan1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_scan1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_scan1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_scan1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_set_str
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_set_str )( unsigned long * scorep_libwrap_arg_1, const unsigned char * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, int scorep_libwrap_arg_4 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_set_str );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_set_str );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_set_str, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_set_str );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sizeinbase
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sizeinbase )( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, int scorep_libwrap_arg_3 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sizeinbase );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sizeinbase );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sizeinbase, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sizeinbase );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sqrtrem
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sqrtrem )( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sqrtrem );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sqrtrem );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sqrtrem, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sqrtrem );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sub
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sub )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sub );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sub );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sub, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sub );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sub_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sub_1 )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sub_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sub_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sub_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sub_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sub_n
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sub_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sub_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sub_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sub_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sub_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_submul_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_submul_1 )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_submul_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_submul_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_submul_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_submul_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_tdiv_qr
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_tdiv_qr )( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5, const unsigned long * scorep_libwrap_arg_6, long scorep_libwrap_arg_7 )
{
    LIBWRAP_EARLY_INIT( __gmpn_tdiv_qr );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_tdiv_qr );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_tdiv_qr, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5, scorep_libwrap_arg_6, scorep_libwrap_arg_7 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_tdiv_qr );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_and_n
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_and_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_and_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_and_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_and_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_and_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_andn_n
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_andn_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_andn_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_andn_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_andn_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_andn_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_nand_n
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_nand_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_nand_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_nand_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_nand_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_nand_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_ior_n
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_ior_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_ior_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_ior_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_ior_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_ior_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_iorn_n
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_iorn_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_iorn_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_iorn_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_iorn_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_iorn_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_nior_n
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_nior_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_nior_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_nior_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_nior_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_nior_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_xor_n
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_xor_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_xor_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_xor_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_xor_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_xor_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_xnor_n
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_xnor_n )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_xnor_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_xnor_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_xnor_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_xnor_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_copyi
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_copyi )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpn_copyi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_copyi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_copyi, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_copyi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_copyd
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_copyd )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( __gmpn_copyd );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_copyd );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_copyd, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_copyd );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_zero
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_zero )( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( __gmpn_zero );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_zero );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_zero, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_zero );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_cnd_add_n
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_cnd_add_n )( unsigned long scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_cnd_add_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_cnd_add_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_cnd_add_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_cnd_add_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_cnd_sub_n
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_cnd_sub_n )( unsigned long scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_cnd_sub_n );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_cnd_sub_n );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_cnd_sub_n, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_cnd_sub_n );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_add_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_add_1 )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, unsigned long * scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_add_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_add_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_add_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_add_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_add_1_itch
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_add_1_itch )( long scorep_libwrap_arg_1 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_add_1_itch );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_add_1_itch );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_add_1_itch, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_add_1_itch );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_sub_1
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_sub_1 )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, unsigned long * scorep_libwrap_arg_5 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_sub_1 );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_sub_1 );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_sub_1, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_sub_1 );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_sub_1_itch
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_sub_1_itch )( long scorep_libwrap_arg_1 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_sub_1_itch );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_sub_1_itch );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_sub_1_itch, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_sub_1_itch );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_cnd_swap
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_cnd_swap )( unsigned long scorep_libwrap_arg_1, volatile unsigned long * scorep_libwrap_arg_2, volatile unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_cnd_swap );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_cnd_swap );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_cnd_swap, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_cnd_swap );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_sec_mul
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_mul )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5, unsigned long * scorep_libwrap_arg_6 )
{
    LIBWRAP_EARLY_INIT( __gmpn_sec_mul );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_mul );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_mul, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5, scorep_libwrap_arg_6 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_mul );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_sec_mul_itch
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_mul_itch )( long scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_mul_itch );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_mul_itch );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_mul_itch, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_mul_itch );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_sqr
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_sqr )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long * scorep_libwrap_arg_4 )
{
    LIBWRAP_EARLY_INIT( __gmpn_sec_sqr );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_sqr );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_sqr, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_sqr );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_sec_sqr_itch
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_sqr_itch )( long scorep_libwrap_arg_1 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_sqr_itch );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_sqr_itch );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_sqr_itch, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_sqr_itch );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_powm
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_powm )( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, unsigned long scorep_libwrap_arg_5, const unsigned long * scorep_libwrap_arg_6, long scorep_libwrap_arg_7, unsigned long * scorep_libwrap_arg_8 )
{
    LIBWRAP_EARLY_INIT( __gmpn_sec_powm );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_powm );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_powm, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5, scorep_libwrap_arg_6, scorep_libwrap_arg_7, scorep_libwrap_arg_8 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_powm );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_sec_powm_itch
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_powm_itch )( long scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, long scorep_libwrap_arg_3 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_powm_itch );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_powm_itch );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_powm_itch, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_powm_itch );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_tabselect
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_tabselect )( volatile unsigned long * scorep_libwrap_arg_1, const volatile unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, long scorep_libwrap_arg_4, long scorep_libwrap_arg_5 )
{
    LIBWRAP_EARLY_INIT( __gmpn_sec_tabselect );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_tabselect );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_tabselect, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_tabselect );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_sec_div_qr
unsigned long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_div_qr )( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5, unsigned long * scorep_libwrap_arg_6 )
{
    unsigned long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_div_qr );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_div_qr );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_div_qr, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5, scorep_libwrap_arg_6 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_div_qr );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_div_qr_itch
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_div_qr_itch )( long scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_div_qr_itch );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_div_qr_itch );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_div_qr_itch, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_div_qr_itch );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_div_r
void
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_div_r )( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, unsigned long * scorep_libwrap_arg_5 )
{
    LIBWRAP_EARLY_INIT( __gmpn_sec_div_r );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_div_r );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_div_r, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_div_r );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef __gmpn_sec_div_r_itch
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_div_r_itch )( long scorep_libwrap_arg_1, long scorep_libwrap_arg_2 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_div_r_itch );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_div_r_itch );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_div_r_itch, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_div_r_itch );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_invert
int
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_invert )( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, unsigned long scorep_libwrap_arg_5, unsigned long * scorep_libwrap_arg_6 )
{
    int scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_invert );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_invert );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_invert, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3, scorep_libwrap_arg_4, scorep_libwrap_arg_5, scorep_libwrap_arg_6 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_invert );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef __gmpn_sec_invert_itch
long
SCOREP_LIBWRAP_FUNC_NAME( __gmpn_sec_invert_itch )( long scorep_libwrap_arg_1 )
{
    long scorep_libwrap_var_ret;
    LIBWRAP_EARLY_INIT( __gmpn_sec_invert_itch );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_gmp_handle,
                         libwrap_gmp_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( __gmpn_sec_invert_itch );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( __gmpn_sec_invert_itch, ( scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( __gmpn_sec_invert_itch );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#ifdef __cplusplus
}
#endif
