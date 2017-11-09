$ scorep-libwrap-init --name gmp -x c --libs "-lgmp" wrapper
Created working directory 'wrapper' for library wrapper gmp.

Next:

    $ cd wrapper

Add the #include-statements for your library to libwrap.h.

Add one or more function calls to your library into main.c.
It will be used as a linking-test.

    $ make                 # build wrapper
    $ make check           # execute tests
    $ make install         # install wrapper
    $ make installcheck    # execute more tests

To use the wrapper, link your application like this before executing it:                                                                                                      
                                                                                                                                                                              
    $ scorep --libwrap=gmp gcc  app.c  -lgmp -o app                                                                                                                           
                                                                                                                                                                              
For detailed instructions consult 'README.md'.                                                                                                                                

###############################################################################

$ cd wrapper/
$ vim libwrap.h

"""
#ifndef LIBWRAP_H
#define LIBWRAP_H

#include <gmp.h>

#endif /* LIBWRAP_H */
"""

###############################################################################

$ vim main.c

"""
#include "libwrap.h"

#include <stdio.h>

int
main( int   argc,
      char* argv[] )
{
    mpz_t a, b, c;
    mpz_init_set_str(a, "1", 10);
    mpz_init_set_str(b, "2", 10);
    mpz_add (c, a, b);

    printf("%s + %s = %s\n", mpz_get_str (NULL, 10, a), mpz_get_str (NULL, 10, b), mpz_get_str (NULL, 10, c));

    return 0;
}
"""

###############################################################################

$ make
  CCLD      main
  CPP       libwrap.i
  GEN       scorep_libwrap_gmp.c
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:496: Warning: Ignoring variadic function: '__gmp_randinit(__gmp_randstate_struct *, gmp_randalg_t, ...)'. If this function has a 'va_list' variant, add '__gmp_randinit:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:532: Warning: Ignoring variadic function: '__gmp_asprintf(char **, const char *, ...)'. If this function has a 'va_list' variant, add '__gmp_asprintf:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:550: Warning: Ignoring variadic function: '__gmp_printf(const char *, ...)'. If this function has a 'va_list' variant, add '__gmp_printf:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:553: Warning: Ignoring variadic function: '__gmp_snprintf(char *, size_t, const char *, ...)'. If this function has a 'va_list' variant, add '__gmp_snprintf:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:556: Warning: Ignoring variadic function: '__gmp_sprintf(char *, const char *, ...)'. If this function has a 'va_list' variant, add '__gmp_sprintf:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:592: Warning: Ignoring variadic function: '__gmp_scanf(const char *, ...)'. If this function has a 'va_list' variant, add '__gmp_scanf:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:595: Warning: Ignoring variadic function: '__gmp_sscanf(const char *, const char *, ...)'. If this function has a 'va_list' variant, add '__gmp_sscanf:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:679: Warning: Ignoring variadic function: '__gmpz_clears(mpz_ptr, ...)'. If this function has a 'va_list' variant, add '__gmpz_clears:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:854: Warning: Ignoring variadic function: '__gmpz_inits(mpz_ptr, ...)'. If this function has a 'va_list' variant, add '__gmpz_inits:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:1146: Warning: Ignoring variadic function: '__gmpq_clears(mpq_ptr, ...)'. If this function has a 'va_list' variant, add '__gmpq_clears:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:1185: Warning: Ignoring variadic function: '__gmpq_inits(mpq_ptr, ...)'. If this function has a 'va_list' variant, add '__gmpq_inits:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:1262: Warning: Ignoring variadic function: '__gmpf_clears(mpf_ptr, ...)'. If this function has a 'va_list' variant, add '__gmpf_clears:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/gmp.h:1343: Warning: Ignoring variadic function: '__gmpf_inits(mpf_ptr, ...)'. If this function has a 'va_list' variant, add '__gmpf_inits:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
  QUICK-CHECK
  CC        libscorep_libwrap_gmp_linktime.lo
  CCLD      libscorep_libwrap_gmp_linktime.la
  CC        libscorep_libwrap_gmp_runtime.lo
  CCLD      libscorep_libwrap_gmp_runtime.la

###############################################################################

$ make check
  FOUND     __gmp_set_memory_functions
  FOUND     __gmp_get_memory_functions
  FOUND     __gmp_randinit_default
  FOUND     __gmp_randinit_lc_2exp
  FOUND     __gmp_randinit_lc_2exp_size
  FOUND     __gmp_randinit_mt
  FOUND     __gmp_randinit_set
  FOUND     __gmp_randseed
  FOUND     __gmp_randseed_ui
  FOUND     __gmp_randclear
  FOUND     __gmp_urandomb_ui
  FOUND     __gmp_urandomm_ui
  FOUND     __gmpz_realloc
  FOUND     __gmpz_abs
  FOUND     __gmpz_add
  FOUND     __gmpz_add_ui
  FOUND     __gmpz_addmul
  FOUND     __gmpz_addmul_ui
  FOUND     __gmpz_and
  FOUND     __gmpz_array_init
  FOUND     __gmpz_bin_ui
  FOUND     __gmpz_bin_uiui
  FOUND     __gmpz_cdiv_q
  FOUND     __gmpz_cdiv_q_2exp
  FOUND     __gmpz_cdiv_q_ui
  FOUND     __gmpz_cdiv_qr
  FOUND     __gmpz_cdiv_qr_ui
  FOUND     __gmpz_cdiv_r
  FOUND     __gmpz_cdiv_r_2exp
  FOUND     __gmpz_cdiv_r_ui
  FOUND     __gmpz_cdiv_ui
  FOUND     __gmpz_clear
  FOUND     __gmpz_clrbit
  FOUND     __gmpz_cmp
  FOUND     __gmpz_cmp_d
  FOUND     __gmpz_cmp_si
  FOUND     __gmpz_cmp_ui
  FOUND     __gmpz_cmpabs
  FOUND     __gmpz_cmpabs_d
  FOUND     __gmpz_cmpabs_ui
  FOUND     __gmpz_com
  FOUND     __gmpz_combit
  FOUND     __gmpz_congruent_p
  FOUND     __gmpz_congruent_2exp_p
  FOUND     __gmpz_congruent_ui_p
  FOUND     __gmpz_divexact
  FOUND     __gmpz_divexact_ui
  FOUND     __gmpz_divisible_p
  FOUND     __gmpz_divisible_ui_p
  FOUND     __gmpz_divisible_2exp_p
  FOUND     __gmpz_dump
  FOUND     __gmpz_export
  FOUND     __gmpz_fac_ui
  FOUND     __gmpz_2fac_ui
  FOUND     __gmpz_mfac_uiui
  FOUND     __gmpz_primorial_ui
  FOUND     __gmpz_fdiv_q
  FOUND     __gmpz_fdiv_q_2exp
  FOUND     __gmpz_fdiv_q_ui
  FOUND     __gmpz_fdiv_qr
  FOUND     __gmpz_fdiv_qr_ui
  FOUND     __gmpz_fdiv_r
  FOUND     __gmpz_fdiv_r_2exp
  FOUND     __gmpz_fdiv_r_ui
  FOUND     __gmpz_fdiv_ui
  FOUND     __gmpz_fib_ui
  FOUND     __gmpz_fib2_ui
  FOUND     __gmpz_fits_sint_p
  FOUND     __gmpz_fits_slong_p
  FOUND     __gmpz_fits_sshort_p
  FOUND     __gmpz_fits_uint_p
  FOUND     __gmpz_fits_ulong_p
  FOUND     __gmpz_fits_ushort_p
  FOUND     __gmpz_gcd
  FOUND     __gmpz_gcd_ui
  FOUND     __gmpz_gcdext
  FOUND     __gmpz_get_d
  FOUND     __gmpz_get_d_2exp
  FOUND     __gmpz_get_si
  FOUND     __gmpz_get_str
  FOUND     __gmpz_get_ui
  FOUND     __gmpz_getlimbn
  FOUND     __gmpz_hamdist
  FOUND     __gmpz_import
  FOUND     __gmpz_init
  FOUND     __gmpz_init2
  FOUND     __gmpz_init_set
  FOUND     __gmpz_init_set_d
  FOUND     __gmpz_init_set_si
  FOUND     __gmpz_init_set_str
  FOUND     __gmpz_init_set_ui
  FOUND     __gmpz_invert
  FOUND     __gmpz_ior
  FOUND     __gmpz_jacobi
  FOUND     __gmpz_kronecker_si
  FOUND     __gmpz_kronecker_ui
  FOUND     __gmpz_si_kronecker
  FOUND     __gmpz_ui_kronecker
  FOUND     __gmpz_lcm
  FOUND     __gmpz_lcm_ui
  FOUND     __gmpz_lucnum_ui
  FOUND     __gmpz_lucnum2_ui
  FOUND     __gmpz_millerrabin
  FOUND     __gmpz_mod
  FOUND     __gmpz_mul
  FOUND     __gmpz_mul_2exp
  FOUND     __gmpz_mul_si
  FOUND     __gmpz_mul_ui
  FOUND     __gmpz_neg
  FOUND     __gmpz_nextprime
  FOUND     __gmpz_perfect_power_p
  FOUND     __gmpz_perfect_square_p
  FOUND     __gmpz_popcount
  FOUND     __gmpz_pow_ui
  FOUND     __gmpz_powm
  FOUND     __gmpz_powm_sec
  FOUND     __gmpz_powm_ui
  FOUND     __gmpz_probab_prime_p
  FOUND     __gmpz_random
  FOUND     __gmpz_random2
  FOUND     __gmpz_realloc2
  FOUND     __gmpz_remove
  FOUND     __gmpz_root
  FOUND     __gmpz_rootrem
  FOUND     __gmpz_rrandomb
  FOUND     __gmpz_scan0
  FOUND     __gmpz_scan1
  FOUND     __gmpz_set
  FOUND     __gmpz_set_d
  FOUND     __gmpz_set_f
  FOUND     __gmpz_set_q
  FOUND     __gmpz_set_si
  FOUND     __gmpz_set_str
  FOUND     __gmpz_set_ui
  FOUND     __gmpz_setbit
  FOUND     __gmpz_size
  FOUND     __gmpz_sizeinbase
  FOUND     __gmpz_sqrt
  FOUND     __gmpz_sqrtrem
  FOUND     __gmpz_sub
  FOUND     __gmpz_sub_ui
  FOUND     __gmpz_ui_sub
  FOUND     __gmpz_submul
  FOUND     __gmpz_submul_ui
  FOUND     __gmpz_swap
  FOUND     __gmpz_tdiv_ui
  FOUND     __gmpz_tdiv_q
  FOUND     __gmpz_tdiv_q_2exp
  FOUND     __gmpz_tdiv_q_ui
  FOUND     __gmpz_tdiv_qr
  FOUND     __gmpz_tdiv_qr_ui
  FOUND     __gmpz_tdiv_r
  FOUND     __gmpz_tdiv_r_2exp
  FOUND     __gmpz_tdiv_r_ui
  FOUND     __gmpz_tstbit
  FOUND     __gmpz_ui_pow_ui
  FOUND     __gmpz_urandomb
  FOUND     __gmpz_urandomm
  FOUND     __gmpz_xor
  FOUND     __gmpz_limbs_read
  FOUND     __gmpz_limbs_write
  FOUND     __gmpz_limbs_modify
  FOUND     __gmpz_limbs_finish
  FOUND     __gmpz_roinit_n
  FOUND     __gmpq_abs
  FOUND     __gmpq_add
  FOUND     __gmpq_canonicalize
  FOUND     __gmpq_clear
  FOUND     __gmpq_cmp
  FOUND     __gmpq_cmp_si
  FOUND     __gmpq_cmp_ui
  FOUND     __gmpq_cmp_z
  FOUND     __gmpq_div
  FOUND     __gmpq_div_2exp
  FOUND     __gmpq_equal
  FOUND     __gmpq_get_num
  FOUND     __gmpq_get_den
  FOUND     __gmpq_get_d
  FOUND     __gmpq_get_str
  FOUND     __gmpq_init
  FOUND     __gmpq_inv
  FOUND     __gmpq_mul
  FOUND     __gmpq_mul_2exp
  FOUND     __gmpq_neg
  FOUND     __gmpq_set
  FOUND     __gmpq_set_d
  FOUND     __gmpq_set_den
  FOUND     __gmpq_set_f
  FOUND     __gmpq_set_num
  FOUND     __gmpq_set_si
  FOUND     __gmpq_set_str
  FOUND     __gmpq_set_ui
  FOUND     __gmpq_set_z
  FOUND     __gmpq_sub
  FOUND     __gmpq_swap
  FOUND     __gmpf_abs
  FOUND     __gmpf_add
  FOUND     __gmpf_add_ui
  FOUND     __gmpf_ceil
  FOUND     __gmpf_clear
  FOUND     __gmpf_cmp
  FOUND     __gmpf_cmp_z
  FOUND     __gmpf_cmp_d
  FOUND     __gmpf_cmp_si
  FOUND     __gmpf_cmp_ui
  FOUND     __gmpf_div
  FOUND     __gmpf_div_2exp
  FOUND     __gmpf_div_ui
  FOUND     __gmpf_dump
  FOUND     __gmpf_eq
  FOUND     __gmpf_fits_sint_p
  FOUND     __gmpf_fits_slong_p
  FOUND     __gmpf_fits_sshort_p
  FOUND     __gmpf_fits_uint_p
  FOUND     __gmpf_fits_ulong_p
  FOUND     __gmpf_fits_ushort_p
  FOUND     __gmpf_floor
  FOUND     __gmpf_get_d
  FOUND     __gmpf_get_d_2exp
  FOUND     __gmpf_get_default_prec
  FOUND     __gmpf_get_prec
  FOUND     __gmpf_get_si
  FOUND     __gmpf_get_str
  FOUND     __gmpf_get_ui
  FOUND     __gmpf_init
  FOUND     __gmpf_init2
  FOUND     __gmpf_init_set
  FOUND     __gmpf_init_set_d
  FOUND     __gmpf_init_set_si
  FOUND     __gmpf_init_set_str
  FOUND     __gmpf_init_set_ui
  FOUND     __gmpf_integer_p
  FOUND     __gmpf_mul
  FOUND     __gmpf_mul_2exp
  FOUND     __gmpf_mul_ui
  FOUND     __gmpf_neg
  FOUND     __gmpf_pow_ui
  FOUND     __gmpf_random2
  FOUND     __gmpf_reldiff
  FOUND     __gmpf_set
  FOUND     __gmpf_set_d
  FOUND     __gmpf_set_default_prec
  FOUND     __gmpf_set_prec
  FOUND     __gmpf_set_prec_raw
  FOUND     __gmpf_set_q
  FOUND     __gmpf_set_si
  FOUND     __gmpf_set_str
  FOUND     __gmpf_set_ui
  FOUND     __gmpf_set_z
  FOUND     __gmpf_size
  FOUND     __gmpf_sqrt
  FOUND     __gmpf_sqrt_ui
  FOUND     __gmpf_sub
  FOUND     __gmpf_sub_ui
  FOUND     __gmpf_swap
  FOUND     __gmpf_trunc
  FOUND     __gmpf_ui_div
  FOUND     __gmpf_ui_sub
  FOUND     __gmpf_urandomb
  FOUND     __gmpn_add
  FOUND     __gmpn_add_1
  FOUND     __gmpn_add_n
  FOUND     __gmpn_addmul_1
  FOUND     __gmpn_cmp
  FOUND     __gmpn_zero_p
  FOUND     __gmpn_divexact_1
  FOUND     __gmpn_divexact_by3c
  FOUND     __gmpn_divrem
  FOUND     __gmpn_divrem_1
  FOUND     __gmpn_divrem_2
  FOUND     __gmpn_div_qr_1
  FOUND     __gmpn_div_qr_2
  FOUND     __gmpn_gcd
  FOUND     __gmpn_gcd_1
  FOUND     __gmpn_gcdext_1
  FOUND     __gmpn_gcdext
  FOUND     __gmpn_get_str
  FOUND     __gmpn_hamdist
  FOUND     __gmpn_lshift
  FOUND     __gmpn_mod_1
  FOUND     __gmpn_mul
  FOUND     __gmpn_mul_1
  FOUND     __gmpn_mul_n
  FOUND     __gmpn_sqr
  FOUND     __gmpn_neg
  FOUND     __gmpn_com
  FOUND     __gmpn_perfect_square_p
  FOUND     __gmpn_perfect_power_p
  FOUND     __gmpn_popcount
  FOUND     __gmpn_pow_1
  FOUND     __gmpn_preinv_mod_1
  FOUND     __gmpn_random
  FOUND     __gmpn_random2
  FOUND     __gmpn_rshift
  FOUND     __gmpn_scan0
  FOUND     __gmpn_scan1
  FOUND     __gmpn_set_str
  FOUND     __gmpn_sizeinbase
  FOUND     __gmpn_sqrtrem
  FOUND     __gmpn_sub
  FOUND     __gmpn_sub_1
  FOUND     __gmpn_sub_n
  FOUND     __gmpn_submul_1
  FOUND     __gmpn_tdiv_qr
  FOUND     __gmpn_and_n
  FOUND     __gmpn_andn_n
  FOUND     __gmpn_nand_n
  FOUND     __gmpn_ior_n
  FOUND     __gmpn_iorn_n
  FOUND     __gmpn_nior_n
  FOUND     __gmpn_xor_n
  FOUND     __gmpn_xnor_n
  FOUND     __gmpn_copyi
  FOUND     __gmpn_copyd
  FOUND     __gmpn_zero
  FOUND     __gmpn_cnd_add_n
  FOUND     __gmpn_cnd_sub_n
  FOUND     __gmpn_sec_add_1
  FOUND     __gmpn_sec_add_1_itch
  FOUND     __gmpn_sec_sub_1
  FOUND     __gmpn_sec_sub_1_itch
  FOUND     __gmpn_cnd_swap
  FOUND     __gmpn_sec_mul
  FOUND     __gmpn_sec_mul_itch
  FOUND     __gmpn_sec_sqr
  FOUND     __gmpn_sec_sqr_itch
  FOUND     __gmpn_sec_powm
  FOUND     __gmpn_sec_powm_itch
  FOUND     __gmpn_sec_tabselect
  FOUND     __gmpn_sec_div_qr
  FOUND     __gmpn_sec_div_qr_itch
  FOUND     __gmpn_sec_div_r
  FOUND     __gmpn_sec_div_r_itch
  FOUND     __gmpn_sec_invert
  FOUND     __gmpn_sec_invert_itch

###############################################################################

$ make install
  QUICK-CHECK
  GEN       gmp.libwrap
  GEN       gmp.summary
  INSTALL   libscorep_libwrap_gmp_linktime.la
  INSTALL   libscorep_libwrap_gmp_runtime.la
  INSTALL   gmp.libwrap
  INSTALL   gmp.summary
  INSTALL   gmp.wrap
  INSTALL   gmp.nvcc.wrap
  INSTALL   gmp.filter
  
###############################################################################

$ make installcheck
  SCOREP    main_linktime_wrapped
  SCOREP    main_runtime_wrapped
[Score-P] To further check, please execute the generated binaries:
[Score-P]
[Score-P]     $ ./main_linktime_wrapped
[Score-P]     $ ./main_runtime_wrapped
[Score-P]
[Score-P] If available, verify the output via:
[Score-P]
[Score-P]     $ cube_info -m visits:excl scorep-*/profile.cubex
[Score-P]
[Score-P] It should display numbers you would expect from intercepting
[Score-P] main.c's calls to the target library.

###############################################################################

$ ./main_linktime_wrapped && mv scorep-2* scorep-linktime
1 + 2 = 3

$ ./main_runtime_wrapped && mv scorep-2* scorep-runtime
1 + 2 = 3

$ cube_info -m visits:excl scorep-linktime/profile.cubex
|      Visits (E) | Diff-Calltree
|               1 |  * main
|               2 |  |  * __gmpz_init_set_str(mpz_ptr, const char *, int)
|               1 |  |  * __gmpz_add(mpz_ptr, mpz_srcptr, mpz_srcptr)
|               3 |  |  * __gmpz_get_str(char *, int, mpz_srcptr)

$ cube_info -m visits:excl scorep-runtime/profile.cubex
|      Visits (E) | Diff-Calltree
|               1 |  * main
|               2 |  |  * __gmpz_init_set_str(mpz_ptr, const char *, int)
|               1 |  |  * __gmpz_add(mpz_ptr, mpz_srcptr, mpz_srcptr)
|               3 |  |  * __gmpz_get_str(char *, int, mpz_srcptr)

###############################################################################

$ ll
total 1532
-rw-rw-r-- 1 brendel brendel    341 Nov  9 15:50 gmp.filter
-rw-rw-r-- 1 brendel brendel    220 Nov  9 15:56 gmp.libwrap
-rw-rw-r-- 1 brendel brendel  13291 Nov  9 15:55 gmp.nvcc.wrap
-rw-rw-r-- 1 brendel brendel    417 Nov  9 15:56 gmp.summary
-rw-rw-r-- 1 brendel brendel   7243 Nov  9 15:55 gmp.wrap
-rw-rw-r-- 1 brendel brendel   1081 Nov  9 15:55 libscorep_libwrap_gmp_linktime.la
-rw-rw-r-- 1 brendel brendel    342 Nov  9 15:55 libscorep_libwrap_gmp_linktime.lo
-rw-rw-r-- 1 brendel brendel 427864 Nov  9 15:55 libscorep_libwrap_gmp_linktime.o
-rw-rw-r-- 1 brendel brendel   1074 Nov  9 15:55 libscorep_libwrap_gmp_runtime.la
-rw-rw-r-- 1 brendel brendel    339 Nov  9 15:55 libscorep_libwrap_gmp_runtime.lo
-rw-rw-r-- 1 brendel brendel 530144 Nov  9 15:55 libscorep_libwrap_gmp_runtime.o
-rw-r--r-- 1 brendel brendel     72 Nov  9 15:50 libwrap.c
-rw-r--r-- 1 brendel brendel    290 Nov  9 15:51 libwrap.h
-rw-rw-r-- 1 brendel brendel  35951 Nov  9 15:55 libwrap.i
-rwxrwxr-x 1 brendel brendel   8464 Nov  9 15:55 main
-rw-r--r-- 1 brendel brendel    570 Nov  9 15:55 main.c
-rwxrwxr-x 1 brendel brendel  20040 Nov  9 15:57 main_linktime_wrapped
-rwxrwxr-x 1 brendel brendel  19960 Nov  9 15:57 main_runtime_wrapped
-rw-rw-r-- 1 brendel brendel  18600 Nov  9 15:50 Makefile
-rw-r--r-- 1 brendel brendel  17886 Nov  9 15:50 README.md
-rw-rw-r-- 1 brendel brendel 250114 Nov  9 15:55 scorep_libwrap_gmp.c
-rw-rw-r-- 1 brendel brendel 145694 Nov  9 15:55 scorep_libwrap_gmp.inc.c
drwxr-xr-x 2 brendel brendel   4096 Nov  9 15:58 scorep-linktime
drwxr-xr-x 2 brendel brendel   4096 Nov  9 15:58 scorep-runtime

$ ll /opt/scorep-libwrap/share/scorep/ | grep gmp
-rw-r--r-- 1 brendel brendel    341 Nov  9 15:57 gmp.filter
-rw-r--r-- 1 brendel brendel    220 Nov  9 15:57 gmp.libwrap
-rw-r--r-- 1 brendel brendel  13291 Nov  9 15:57 gmp.nvcc.wrap
-rw-r--r-- 1 brendel brendel    417 Nov  9 15:57 gmp.summary
-rw-r--r-- 1 brendel brendel   7243 Nov  9 15:57 gmp.wrap

$ ll /opt/scorep-libwrap/lib | grep gmp
-rw-r--r-- 1 brendel brendel   436962 Nov  9 15:56 libscorep_libwrap_gmp_linktime.a
-rwxr-xr-x 1 brendel brendel     1082 Nov  9 15:56 libscorep_libwrap_gmp_linktime.la
-rwxr-xr-x 1 brendel brendel   258504 Nov  9 15:56 libscorep_libwrap_gmp_linktime.so
-rw-r--r-- 1 brendel brendel   536898 Nov  9 15:57 libscorep_libwrap_gmp_runtime.a
-rwxr-xr-x 1 brendel brendel     1075 Nov  9 15:57 libscorep_libwrap_gmp_runtime.la
-rwxr-xr-x 1 brendel brendel   282176 Nov  9 15:57 libscorep_libwrap_gmp_runtime.so
