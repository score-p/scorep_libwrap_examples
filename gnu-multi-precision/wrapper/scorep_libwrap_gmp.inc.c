#ifndef SCOREP_LIBWRAP_PROCESS_FUNC
#error SCOREP_LIBWRAP_PROCESS_FUNC not defined
#endif

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmp_set_memory_functions,
                             ( void *(*scorep_libwrap_arg_1)(unsigned long), void *(*scorep_libwrap_arg_2)(void *, unsigned long, unsigned long), void (*scorep_libwrap_arg_3)(void *, unsigned long) ),
                             "__gmp_set_memory_functions(void *(*)(size_t), void *(*)(void *, size_t, size_t), void (*)(void *, size_t))",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             473,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmp_get_memory_functions,
                             ( void *(**scorep_libwrap_arg_1)(unsigned long), void *(**scorep_libwrap_arg_2)(void *, unsigned long, unsigned long), void (**scorep_libwrap_arg_3)(void *, unsigned long) ),
                             "__gmp_get_memory_functions(void *(**)(size_t), void *(**)(void *, size_t, size_t), void (**)(void *, size_t))",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             478,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmp_randinit_default,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1] ),
                             "__gmp_randinit_default(__gmp_randstate_struct *)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             499,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmp_randinit_lc_2exp,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1], const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmp_randinit_lc_2exp(__gmp_randstate_struct *, mpz_srcptr, unsigned long, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             502,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmp_randinit_lc_2exp_size,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1], unsigned long scorep_libwrap_arg_2 ),
                             "__gmp_randinit_lc_2exp_size(__gmp_randstate_struct *, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             505,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmp_randinit_mt,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1] ),
                             "__gmp_randinit_mt(__gmp_randstate_struct *)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             508,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmp_randinit_set,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1], const __gmp_randstate_struct * scorep_libwrap_arg_2 ),
                             "__gmp_randinit_set(__gmp_randstate_struct *, const __gmp_randstate_struct *)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             511,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmp_randseed,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1], const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmp_randseed(__gmp_randstate_struct *, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             514,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmp_randseed_ui,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1], unsigned long scorep_libwrap_arg_2 ),
                             "__gmp_randseed_ui(__gmp_randstate_struct *, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             517,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmp_randclear,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1] ),
                             "__gmp_randclear(__gmp_randstate_struct *)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             520,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmp_urandomb_ui,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1], unsigned long scorep_libwrap_arg_2 ),
                             "__gmp_urandomb_ui(__gmp_randstate_struct *, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             523,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmp_urandomm_ui,
                             ( __gmp_randstate_struct scorep_libwrap_arg_1[1], unsigned long scorep_libwrap_arg_2 ),
                             "__gmp_urandomm_ui(__gmp_randstate_struct *, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             526,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void * ),
                             __gmpz_realloc,
                             ( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_realloc(mpz_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             617,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_abs,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_abs(mpz_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             621,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_add,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_add(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             625,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_add_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_add_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             628,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_addmul,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_addmul(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             631,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_addmul_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_addmul_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             634,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_and,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_and(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             637,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_array_init,
                             ( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpz_array_init(mpz_ptr, mp_size_t, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             640,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_bin_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_bin_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             643,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_bin_uiui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_bin_uiui(mpz_ptr, unsigned long, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             646,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_cdiv_q,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_cdiv_q(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             649,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_cdiv_q_2exp,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_cdiv_q_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             652,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_cdiv_q_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_cdiv_q_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             655,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_cdiv_qr,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 ),
                             "__gmpz_cdiv_qr(mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             658,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_cdiv_qr_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpz_cdiv_qr_ui(mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             661,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_cdiv_r,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_cdiv_r(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             664,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_cdiv_r_2exp,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_cdiv_r_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             667,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_cdiv_r_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_cdiv_r_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             670,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_cdiv_ui,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_cdiv_ui(mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             673,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_clear,
                             ( __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_clear(mpz_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             676,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_clrbit,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_clrbit(mpz_ptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             682,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_cmp,
                             ( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_cmp(mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             685,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_cmp_d,
                             ( const __mpz_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 ),
                             "__gmpz_cmp_d(mpz_srcptr, double)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             688,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_cmp_si,
                             ( const __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_cmp_si(mpz_srcptr, long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             691,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_cmp_ui,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_cmp_ui(mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             694,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_cmpabs,
                             ( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_cmpabs(mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             697,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_cmpabs_d,
                             ( const __mpz_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 ),
                             "__gmpz_cmpabs_d(mpz_srcptr, double)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             700,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_cmpabs_ui,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_cmpabs_ui(mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             703,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_com,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_com(mpz_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             706,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_combit,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_combit(mpz_ptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             709,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_congruent_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_congruent_p(mpz_srcptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             712,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_congruent_2exp_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_congruent_2exp_p(mpz_srcptr, mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             715,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_congruent_ui_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_congruent_ui_p(mpz_srcptr, unsigned long, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             718,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_divexact,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_divexact(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             721,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_divexact_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_divexact_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             724,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_divisible_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_divisible_p(mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             727,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_divisible_ui_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_divisible_ui_p(mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             730,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_divisible_2exp_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_divisible_2exp_p(mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             733,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_dump,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_dump(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             736,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void * ),
                             __gmpz_export,
                             ( void * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, int scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, int scorep_libwrap_arg_5, unsigned long scorep_libwrap_arg_6, const __mpz_struct * scorep_libwrap_arg_7 ),
                             "__gmpz_export(void *, size_t *, int, size_t, int, size_t, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             739,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_fac_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_fac_ui(mpz_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             742,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_2fac_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_2fac_ui(mpz_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             745,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_mfac_uiui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_mfac_uiui(mpz_ptr, unsigned long, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             748,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_primorial_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_primorial_ui(mpz_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             751,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_fdiv_q,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_fdiv_q(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             754,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_fdiv_q_2exp,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_fdiv_q_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             757,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_fdiv_q_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_fdiv_q_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             760,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_fdiv_qr,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 ),
                             "__gmpz_fdiv_qr(mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             763,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_fdiv_qr_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpz_fdiv_qr_ui(mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             766,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_fdiv_r,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_fdiv_r(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             769,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_fdiv_r_2exp,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_fdiv_r_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             772,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_fdiv_r_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_fdiv_r_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             775,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_fdiv_ui,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_fdiv_ui(mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             778,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_fib_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_fib_ui(mpz_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             781,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_fib2_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_fib2_ui(mpz_ptr, mpz_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             784,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_fits_sint_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_fits_sint_p(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             787,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_fits_slong_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_fits_slong_p(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             790,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_fits_sshort_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_fits_sshort_p(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             793,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_fits_uint_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_fits_uint_p(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             797,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_fits_ulong_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_fits_ulong_p(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             802,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_fits_ushort_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_fits_ushort_p(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             807,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_gcd,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_gcd(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             811,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_gcd_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_gcd_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             814,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_gcdext,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4, const __mpz_struct * scorep_libwrap_arg_5 ),
                             "__gmpz_gcdext(mpz_ptr, mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             817,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double ),
                             __gmpz_get_d,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_get_d(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             820,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double ),
                             __gmpz_get_d_2exp,
                             ( long * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_get_d_2exp(long *, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             823,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpz_get_si,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_get_si(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             826,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( char * ),
                             __gmpz_get_str,
                             ( char * scorep_libwrap_arg_1, int scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_get_str(char *, int, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             829,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_get_ui,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_get_ui(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             833,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_getlimbn,
                             ( const __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_getlimbn(mpz_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             838,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_hamdist,
                             ( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_hamdist(mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             842,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_import,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, int scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, int scorep_libwrap_arg_5, unsigned long scorep_libwrap_arg_6, const void * scorep_libwrap_arg_7 ),
                             "__gmpz_import(mpz_ptr, size_t, int, size_t, int, size_t, const void *)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             845,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_init,
                             ( __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_init(mpz_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             848,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_init2,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_init2(mpz_ptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             851,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_init_set,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_init_set(mpz_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             857,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_init_set_d,
                             ( __mpz_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 ),
                             "__gmpz_init_set_d(mpz_ptr, double)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             860,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_init_set_si,
                             ( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_init_set_si(mpz_ptr, long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             863,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_init_set_str,
                             ( __mpz_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 ),
                             "__gmpz_init_set_str(mpz_ptr, const char *, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             866,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_init_set_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_init_set_ui(mpz_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             869,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_invert,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_invert(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             882,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_ior,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_ior(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             885,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_jacobi,
                             ( const __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_jacobi(mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             888,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_kronecker_si,
                             ( const __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_kronecker_si(mpz_srcptr, long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             893,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_kronecker_ui,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_kronecker_ui(mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             896,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_si_kronecker,
                             ( long scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_si_kronecker(long, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             899,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_ui_kronecker,
                             ( unsigned long scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_ui_kronecker(unsigned long, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             902,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_lcm,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_lcm(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             905,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_lcm_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_lcm_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             908,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_lucnum_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_lucnum_ui(mpz_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             913,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_lucnum2_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_lucnum2_ui(mpz_ptr, mpz_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             916,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_millerrabin,
                             ( const __mpz_struct * scorep_libwrap_arg_1, int scorep_libwrap_arg_2 ),
                             "__gmpz_millerrabin(mpz_srcptr, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             919,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_mod,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_mod(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             922,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_mul,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_mul(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             927,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_mul_2exp,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_mul_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             930,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_mul_si,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpz_mul_si(mpz_ptr, mpz_srcptr, long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             933,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_mul_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_mul_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             936,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_neg,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_neg(mpz_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             940,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_nextprime,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_nextprime(mpz_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             944,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_perfect_power_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_perfect_power_p(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             957,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_perfect_square_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_perfect_square_p(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             961,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_popcount,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_popcount(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             966,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_pow_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_pow_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             970,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_powm,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 ),
                             "__gmpz_powm(mpz_ptr, mpz_srcptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             973,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_powm_sec,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 ),
                             "__gmpz_powm_sec(mpz_ptr, mpz_srcptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             976,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_powm_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 ),
                             "__gmpz_powm_ui(mpz_ptr, mpz_srcptr, unsigned long, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             979,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_probab_prime_p,
                             ( const __mpz_struct * scorep_libwrap_arg_1, int scorep_libwrap_arg_2 ),
                             "__gmpz_probab_prime_p(mpz_srcptr, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             982,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_random,
                             ( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_random(mpz_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             985,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_random2,
                             ( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_random2(mpz_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             988,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_realloc2,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_realloc2(mpz_ptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             991,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_remove,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_remove(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             994,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_root,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_root(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             997,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_rootrem,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpz_rootrem(mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1000,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_rrandomb,
                             ( __mpz_struct * scorep_libwrap_arg_1, __gmp_randstate_struct scorep_libwrap_arg_2[1], unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_rrandomb(mpz_ptr, __gmp_randstate_struct *, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1003,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_scan0,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_scan0(mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1006,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_scan1,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_scan1(mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1009,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_set,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_set(mpz_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1012,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_set_d,
                             ( __mpz_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 ),
                             "__gmpz_set_d(mpz_ptr, double)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1015,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_set_f,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_set_f(mpz_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1018,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_set_q,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_set_q(mpz_ptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1022,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_set_si,
                             ( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_set_si(mpz_ptr, long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1026,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_set_str,
                             ( __mpz_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 ),
                             "__gmpz_set_str(mpz_ptr, const char *, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1029,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_set_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_set_ui(mpz_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1032,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_setbit,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_setbit(mpz_ptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1035,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_size,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_size(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1039,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_sizeinbase,
                             ( const __mpz_struct * scorep_libwrap_arg_1, int scorep_libwrap_arg_2 ),
                             "__gmpz_sizeinbase(mpz_srcptr, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1043,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_sqrt,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_sqrt(mpz_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1046,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_sqrtrem,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_sqrtrem(mpz_ptr, mpz_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1049,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_sub,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_sub(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1052,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_sub_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_sub_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1055,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_ui_sub,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_ui_sub(mpz_ptr, unsigned long, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1058,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_submul,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_submul(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1061,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_submul_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_submul_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1064,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_swap,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpz_swap(mpz_ptr, mpz_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1067,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_tdiv_ui,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_tdiv_ui(mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1070,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_tdiv_q,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_tdiv_q(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1073,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_tdiv_q_2exp,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_tdiv_q_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1076,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_tdiv_q_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_tdiv_q_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1079,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_tdiv_qr,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, const __mpz_struct * scorep_libwrap_arg_4 ),
                             "__gmpz_tdiv_qr(mpz_ptr, mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1082,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_tdiv_qr_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpz_tdiv_qr_ui(mpz_ptr, mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1085,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_tdiv_r,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_tdiv_r(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1088,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_tdiv_r_2exp,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_tdiv_r_2exp(mpz_ptr, mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1091,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpz_tdiv_r_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_tdiv_r_ui(mpz_ptr, mpz_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1094,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpz_tstbit,
                             ( const __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpz_tstbit(mpz_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1097,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_ui_pow_ui,
                             ( __mpz_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_ui_pow_ui(mpz_ptr, unsigned long, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1100,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_urandomb,
                             ( __mpz_struct * scorep_libwrap_arg_1, __gmp_randstate_struct scorep_libwrap_arg_2[1], unsigned long scorep_libwrap_arg_3 ),
                             "__gmpz_urandomb(mpz_ptr, __gmp_randstate_struct *, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1103,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_urandomm,
                             ( __mpz_struct * scorep_libwrap_arg_1, __gmp_randstate_struct scorep_libwrap_arg_2[1], const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_urandomm(mpz_ptr, __gmp_randstate_struct *, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1106,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_xor,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2, const __mpz_struct * scorep_libwrap_arg_3 ),
                             "__gmpz_xor(mpz_ptr, mpz_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1110,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( const unsigned long * ),
                             __gmpz_limbs_read,
                             ( const __mpz_struct * scorep_libwrap_arg_1 ),
                             "__gmpz_limbs_read(mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1113,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long * ),
                             __gmpz_limbs_write,
                             ( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_limbs_write(mpz_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1116,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long * ),
                             __gmpz_limbs_modify,
                             ( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_limbs_modify(mpz_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1119,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpz_limbs_finish,
                             ( __mpz_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpz_limbs_finish(mpz_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1122,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( const __mpz_struct * ),
                             __gmpz_roinit_n,
                             ( __mpz_struct * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpz_roinit_n(mpz_ptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1125,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_abs,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_abs(mpq_ptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1133,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_add,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 ),
                             "__gmpq_add(mpq_ptr, mpq_srcptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1137,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_canonicalize,
                             ( __mpq_struct * scorep_libwrap_arg_1 ),
                             "__gmpq_canonicalize(mpq_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1140,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_clear,
                             ( __mpq_struct * scorep_libwrap_arg_1 ),
                             "__gmpq_clear(mpq_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1143,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpq_cmp,
                             ( const __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_cmp(mpq_srcptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1149,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpq_cmp_si,
                             ( const __mpq_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpq_cmp_si(mpq_srcptr, long, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1152,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpq_cmp_ui,
                             ( const __mpq_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpq_cmp_ui(mpq_srcptr, unsigned long, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1155,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpq_cmp_z,
                             ( const __mpq_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_cmp_z(mpq_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1158,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_div,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 ),
                             "__gmpq_div(mpq_ptr, mpq_srcptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1161,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_div_2exp,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpq_div_2exp(mpq_ptr, mpq_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1164,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpq_equal,
                             ( const __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_equal(mpq_srcptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1167,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_get_num,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_get_num(mpz_ptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1170,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_get_den,
                             ( __mpz_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_get_den(mpz_ptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1173,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double ),
                             __gmpq_get_d,
                             ( const __mpq_struct * scorep_libwrap_arg_1 ),
                             "__gmpq_get_d(mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1176,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( char * ),
                             __gmpq_get_str,
                             ( char * scorep_libwrap_arg_1, int scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 ),
                             "__gmpq_get_str(char *, int, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1179,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_init,
                             ( __mpq_struct * scorep_libwrap_arg_1 ),
                             "__gmpq_init(mpq_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1182,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_inv,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_inv(mpq_ptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1193,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_mul,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 ),
                             "__gmpq_mul(mpq_ptr, mpq_srcptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1196,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_mul_2exp,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpq_mul_2exp(mpq_ptr, mpq_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1199,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_neg,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_neg(mpq_ptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1203,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_set,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_set(mpq_ptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1212,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_set_d,
                             ( __mpq_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 ),
                             "__gmpq_set_d(mpq_ptr, double)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1215,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_set_den,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_set_den(mpq_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1218,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_set_f,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_set_f(mpq_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1221,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_set_num,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_set_num(mpq_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1224,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_set_si,
                             ( __mpq_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpq_set_si(mpq_ptr, long, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1227,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpq_set_str,
                             ( __mpq_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 ),
                             "__gmpq_set_str(mpq_ptr, const char *, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1230,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_set_ui,
                             ( __mpq_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpq_set_ui(mpq_ptr, unsigned long, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1233,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_set_z,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_set_z(mpq_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1236,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_sub,
                             ( __mpq_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2, const __mpq_struct * scorep_libwrap_arg_3 ),
                             "__gmpq_sub(mpq_ptr, mpq_srcptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1239,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpq_swap,
                             ( __mpq_struct * scorep_libwrap_arg_1, __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpq_swap(mpq_ptr, mpq_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1242,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_abs,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_abs(mpf_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1248,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_add,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 ),
                             "__gmpf_add(mpf_ptr, mpf_srcptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1251,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_add_ui,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpf_add_ui(mpf_ptr, mpf_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1254,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_ceil,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_ceil(mpf_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1256,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_clear,
                             ( __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_clear(mpf_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1259,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_cmp,
                             ( const __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_cmp(mpf_srcptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1265,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_cmp_z,
                             ( const __mpf_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_cmp_z(mpf_srcptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1268,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_cmp_d,
                             ( const __mpf_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 ),
                             "__gmpf_cmp_d(mpf_srcptr, double)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1271,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_cmp_si,
                             ( const __mpf_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpf_cmp_si(mpf_srcptr, long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1274,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_cmp_ui,
                             ( const __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpf_cmp_ui(mpf_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1277,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_div,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 ),
                             "__gmpf_div(mpf_ptr, mpf_srcptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1280,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_div_2exp,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpf_div_2exp(mpf_ptr, mpf_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1283,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_div_ui,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpf_div_ui(mpf_ptr, mpf_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1286,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_dump,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_dump(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1289,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_eq,
                             ( const __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpf_eq(mpf_srcptr, mpf_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1292,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_fits_sint_p,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_fits_sint_p(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1295,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_fits_slong_p,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_fits_slong_p(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1298,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_fits_sshort_p,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_fits_sshort_p(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1301,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_fits_uint_p,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_fits_uint_p(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1304,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_fits_ulong_p,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_fits_ulong_p(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1307,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_fits_ushort_p,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_fits_ushort_p(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1310,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_floor,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_floor(mpf_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1313,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double ),
                             __gmpf_get_d,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_get_d(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1316,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double ),
                             __gmpf_get_d_2exp,
                             ( long * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_get_d_2exp(long *, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1319,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpf_get_default_prec,
                             ( void ),
                             "__gmpf_get_default_prec()",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1322,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpf_get_prec,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_get_prec(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1325,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpf_get_si,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_get_si(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1328,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( char * ),
                             __gmpf_get_str,
                             ( char * scorep_libwrap_arg_1, long * scorep_libwrap_arg_2, int scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, const __mpf_struct * scorep_libwrap_arg_5 ),
                             "__gmpf_get_str(char *, mp_exp_t *, int, size_t, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1331,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpf_get_ui,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_get_ui(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1334,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_init,
                             ( __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_init(mpf_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1337,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_init2,
                             ( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpf_init2(mpf_ptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1340,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_init_set,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_init_set(mpf_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1346,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_init_set_d,
                             ( __mpf_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 ),
                             "__gmpf_init_set_d(mpf_ptr, double)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1349,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_init_set_si,
                             ( __mpf_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpf_init_set_si(mpf_ptr, long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1352,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_init_set_str,
                             ( __mpf_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 ),
                             "__gmpf_init_set_str(mpf_ptr, const char *, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_init_set_ui,
                             ( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpf_init_set_ui(mpf_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1358,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_integer_p,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_integer_p(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1366,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_mul,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 ),
                             "__gmpf_mul(mpf_ptr, mpf_srcptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1369,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_mul_2exp,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpf_mul_2exp(mpf_ptr, mpf_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1372,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_mul_ui,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpf_mul_ui(mpf_ptr, mpf_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1375,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_neg,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_neg(mpf_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1378,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_pow_ui,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpf_pow_ui(mpf_ptr, mpf_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1386,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_random2,
                             ( __mpf_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpf_random2(mpf_ptr, mp_size_t, mp_exp_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1389,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_reldiff,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 ),
                             "__gmpf_reldiff(mpf_ptr, mpf_srcptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1392,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_set,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_set(mpf_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1395,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_set_d,
                             ( __mpf_struct * scorep_libwrap_arg_1, double scorep_libwrap_arg_2 ),
                             "__gmpf_set_d(mpf_ptr, double)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1398,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_set_default_prec,
                             ( unsigned long scorep_libwrap_arg_1 ),
                             "__gmpf_set_default_prec(mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1401,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_set_prec,
                             ( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpf_set_prec(mpf_ptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1404,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_set_prec_raw,
                             ( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpf_set_prec_raw(mpf_ptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1407,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_set_q,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpq_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_set_q(mpf_ptr, mpq_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1410,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_set_si,
                             ( __mpf_struct * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpf_set_si(mpf_ptr, long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1413,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpf_set_str,
                             ( __mpf_struct * scorep_libwrap_arg_1, const char * scorep_libwrap_arg_2, int scorep_libwrap_arg_3 ),
                             "__gmpf_set_str(mpf_ptr, const char *, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1416,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_set_ui,
                             ( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpf_set_ui(mpf_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1419,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_set_z,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpz_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_set_z(mpf_ptr, mpz_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1422,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpf_size,
                             ( const __mpf_struct * scorep_libwrap_arg_1 ),
                             "__gmpf_size(mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1425,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_sqrt,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_sqrt(mpf_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1428,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_sqrt_ui,
                             ( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpf_sqrt_ui(mpf_ptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1431,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_sub,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 ),
                             "__gmpf_sub(mpf_ptr, mpf_srcptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1434,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_sub_ui,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpf_sub_ui(mpf_ptr, mpf_srcptr, unsigned long)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1437,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_swap,
                             ( __mpf_struct * scorep_libwrap_arg_1, __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_swap(mpf_ptr, mpf_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1440,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_trunc,
                             ( __mpf_struct * scorep_libwrap_arg_1, const __mpf_struct * scorep_libwrap_arg_2 ),
                             "__gmpf_trunc(mpf_ptr, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1443,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_ui_div,
                             ( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 ),
                             "__gmpf_ui_div(mpf_ptr, unsigned long, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1446,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_ui_sub,
                             ( __mpf_struct * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, const __mpf_struct * scorep_libwrap_arg_3 ),
                             "__gmpf_ui_sub(mpf_ptr, unsigned long, mpf_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1449,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpf_urandomb,
                             ( __mpf_struct scorep_libwrap_arg_1[1], __gmp_randstate_struct scorep_libwrap_arg_2[1], unsigned long scorep_libwrap_arg_3 ),
                             "__gmpf_urandomb(__mpf_struct *, __gmp_randstate_struct *, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1452,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_add,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 ),
                             "__gmpn_add(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1461,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_add_1,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpn_add_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1466,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_add_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_add_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1470,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_addmul_1,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpn_addmul_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1473,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpn_cmp,
                             ( const unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpn_cmp(mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1477,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpn_zero_p,
                             ( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_zero_p(mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1482,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_divexact_1,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpn_divexact_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1486,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_divexact_by3c,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpn_divexact_by3c(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1492,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_divrem,
                             ( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, const unsigned long * scorep_libwrap_arg_5, long scorep_libwrap_arg_6 ),
                             "__gmpn_divrem(mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1498,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_divrem_1,
                             ( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, unsigned long scorep_libwrap_arg_5 ),
                             "__gmpn_divrem_1(mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1501,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_divrem_2,
                             ( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, const unsigned long * scorep_libwrap_arg_5 ),
                             "__gmpn_divrem_2(mp_ptr, mp_size_t, mp_ptr, mp_size_t, mp_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1504,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_div_qr_1,
                             ( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, unsigned long scorep_libwrap_arg_5 ),
                             "__gmpn_div_qr_1(mp_ptr, mp_limb_t *, mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1507,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_div_qr_2,
                             ( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, const unsigned long * scorep_libwrap_arg_5 ),
                             "__gmpn_div_qr_2(mp_ptr, mp_ptr, mp_srcptr, mp_size_t, mp_srcptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1510,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_gcd,
                             ( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 ),
                             "__gmpn_gcd(mp_ptr, mp_ptr, mp_size_t, mp_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1513,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_gcd_1,
                             ( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpn_gcd_1(mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1516,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_gcdext_1,
                             ( long * scorep_libwrap_arg_1, long * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpn_gcdext_1(mp_limb_signed_t *, mp_limb_signed_t *, mp_limb_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1519,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_gcdext,
                             ( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, long * scorep_libwrap_arg_3, unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5, unsigned long * scorep_libwrap_arg_6, long scorep_libwrap_arg_7 ),
                             "__gmpn_gcdext(mp_ptr, mp_ptr, mp_size_t *, mp_ptr, mp_size_t, mp_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1522,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_get_str,
                             ( unsigned char * scorep_libwrap_arg_1, int scorep_libwrap_arg_2, unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_get_str(unsigned char *, int, mp_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1525,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_hamdist,
                             ( const unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpn_hamdist(mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1528,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_lshift,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned int scorep_libwrap_arg_4 ),
                             "__gmpn_lshift(mp_ptr, mp_srcptr, mp_size_t, unsigned int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1531,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_mod_1,
                             ( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3 ),
                             "__gmpn_mod_1(mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1534,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_mul,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 ),
                             "__gmpn_mul(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1537,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_mul_1,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpn_mul_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1540,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_mul_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_mul_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1543,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_sqr,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpn_sqr(mp_ptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1546,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_neg,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpn_neg(mp_ptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1550,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_com,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpn_com(mp_ptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1554,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpn_perfect_square_p,
                             ( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_perfect_square_p(mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1557,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpn_perfect_power_p,
                             ( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_perfect_power_p(mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1560,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_popcount,
                             ( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_popcount(mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1563,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_pow_1,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, unsigned long * scorep_libwrap_arg_5 ),
                             "__gmpn_pow_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t, mp_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1566,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_preinv_mod_1,
                             ( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpn_preinv_mod_1(mp_srcptr, mp_size_t, mp_limb_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1570,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_random,
                             ( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_random(mp_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1573,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_random2,
                             ( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_random2(mp_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1576,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_rshift,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned int scorep_libwrap_arg_4 ),
                             "__gmpn_rshift(mp_ptr, mp_srcptr, mp_size_t, unsigned int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1579,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_scan0,
                             ( const unsigned long * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpn_scan0(mp_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1582,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_scan1,
                             ( const unsigned long * scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2 ),
                             "__gmpn_scan1(mp_srcptr, mp_bitcnt_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1585,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_set_str,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned char * scorep_libwrap_arg_2, unsigned long scorep_libwrap_arg_3, int scorep_libwrap_arg_4 ),
                             "__gmpn_set_str(mp_ptr, const unsigned char *, size_t, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1588,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_sizeinbase,
                             ( const unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, int scorep_libwrap_arg_3 ),
                             "__gmpn_sizeinbase(mp_srcptr, mp_size_t, int)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1591,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_sqrtrem,
                             ( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_sqrtrem(mp_ptr, mp_ptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1594,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_sub,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 ),
                             "__gmpn_sub(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1598,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_sub_1,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpn_sub_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1603,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_sub_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_sub_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1607,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_submul_1,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4 ),
                             "__gmpn_submul_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1610,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_tdiv_qr,
                             ( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5, const unsigned long * scorep_libwrap_arg_6, long scorep_libwrap_arg_7 ),
                             "__gmpn_tdiv_qr(mp_ptr, mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1613,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_and_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_and_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1616,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_andn_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_andn_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1618,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_nand_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_nand_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1620,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_ior_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_ior_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1622,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_iorn_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_iorn_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1624,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_nior_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_nior_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1626,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_xor_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_xor_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1628,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_xnor_n,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_xnor_n(mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1630,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_copyi,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpn_copyi(mp_ptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1633,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_copyd,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpn_copyd(mp_ptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1635,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_zero,
                             ( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_zero(mp_ptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1637,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_cnd_add_n,
                             ( unsigned long scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 ),
                             "__gmpn_cnd_add_n(mp_limb_t, mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1640,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_cnd_sub_n,
                             ( unsigned long scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5 ),
                             "__gmpn_cnd_sub_n(mp_limb_t, mp_ptr, mp_srcptr, mp_srcptr, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1642,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_sec_add_1,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, unsigned long * scorep_libwrap_arg_5 ),
                             "__gmpn_sec_add_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t, mp_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1645,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_sec_add_1_itch,
                             ( long scorep_libwrap_arg_1 ),
                             "__gmpn_sec_add_1_itch(mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1647,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_sec_sub_1,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long scorep_libwrap_arg_4, unsigned long * scorep_libwrap_arg_5 ),
                             "__gmpn_sec_sub_1(mp_ptr, mp_srcptr, mp_size_t, mp_limb_t, mp_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1650,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_sec_sub_1_itch,
                             ( long scorep_libwrap_arg_1 ),
                             "__gmpn_sec_sub_1_itch(mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1652,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_cnd_swap,
                             ( unsigned long scorep_libwrap_arg_1, volatile unsigned long * scorep_libwrap_arg_2, volatile unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4 ),
                             "__gmpn_cnd_swap(mp_limb_t, volatile mp_limb_t *, volatile mp_limb_t *, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1655,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_sec_mul,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5, unsigned long * scorep_libwrap_arg_6 ),
                             "__gmpn_sec_mul(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_size_t, mp_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1658,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_sec_mul_itch,
                             ( long scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_sec_mul_itch(mp_size_t, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1660,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_sec_sqr,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, unsigned long * scorep_libwrap_arg_4 ),
                             "__gmpn_sec_sqr(mp_ptr, mp_srcptr, mp_size_t, mp_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1663,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_sec_sqr_itch,
                             ( long scorep_libwrap_arg_1 ),
                             "__gmpn_sec_sqr_itch(mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1665,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_sec_powm,
                             ( unsigned long * scorep_libwrap_arg_1, const unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, unsigned long scorep_libwrap_arg_5, const unsigned long * scorep_libwrap_arg_6, long scorep_libwrap_arg_7, unsigned long * scorep_libwrap_arg_8 ),
                             "__gmpn_sec_powm(mp_ptr, mp_srcptr, mp_size_t, mp_srcptr, mp_bitcnt_t, mp_srcptr, mp_size_t, mp_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1668,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_sec_powm_itch,
                             ( long scorep_libwrap_arg_1, unsigned long scorep_libwrap_arg_2, long scorep_libwrap_arg_3 ),
                             "__gmpn_sec_powm_itch(mp_size_t, mp_bitcnt_t, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1670,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_sec_tabselect,
                             ( volatile unsigned long * scorep_libwrap_arg_1, const volatile unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, long scorep_libwrap_arg_4, long scorep_libwrap_arg_5 ),
                             "__gmpn_sec_tabselect(volatile mp_limb_t *, const volatile mp_limb_t *, mp_size_t, mp_size_t, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1673,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( unsigned long ),
                             __gmpn_sec_div_qr,
                             ( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, long scorep_libwrap_arg_3, const unsigned long * scorep_libwrap_arg_4, long scorep_libwrap_arg_5, unsigned long * scorep_libwrap_arg_6 ),
                             "__gmpn_sec_div_qr(mp_ptr, mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1676,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_sec_div_qr_itch,
                             ( long scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_sec_div_qr_itch(mp_size_t, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1678,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             __gmpn_sec_div_r,
                             ( unsigned long * scorep_libwrap_arg_1, long scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, unsigned long * scorep_libwrap_arg_5 ),
                             "__gmpn_sec_div_r(mp_ptr, mp_size_t, mp_srcptr, mp_size_t, mp_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1680,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_sec_div_r_itch,
                             ( long scorep_libwrap_arg_1, long scorep_libwrap_arg_2 ),
                             "__gmpn_sec_div_r_itch(mp_size_t, mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1682,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             __gmpn_sec_invert,
                             ( unsigned long * scorep_libwrap_arg_1, unsigned long * scorep_libwrap_arg_2, const unsigned long * scorep_libwrap_arg_3, long scorep_libwrap_arg_4, unsigned long scorep_libwrap_arg_5, unsigned long * scorep_libwrap_arg_6 ),
                             "__gmpn_sec_invert(mp_ptr, mp_ptr, mp_srcptr, mp_size_t, mp_bitcnt_t, mp_ptr)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1685,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( long ),
                             __gmpn_sec_invert_itch,
                             ( long scorep_libwrap_arg_1 ),
                             "__gmpn_sec_invert_itch(mp_size_t)",
                             "/usr/include/x86_64-linux-gnu/gmp.h",
                             1687,
                              )

#undef SCOREP_LIBWRAP_PROCESS_FUNC
#ifdef SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#undef SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#endif

