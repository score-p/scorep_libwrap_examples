#ifndef SCOREP_LIBWRAP_PROCESS_FUNC
#error SCOREP_LIBWRAP_PROCESS_FUNC not defined
#endif

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_execute,
                             ( const fftw_plan p ),
                             "fftw_execute(const fftw_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft,
                             ( int rank, const int * n, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags ),
                             "fftw_plan_dft(int, const int *, fftw_complex *, fftw_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_1d,
                             ( int n, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags ),
                             "fftw_plan_dft_1d(int, fftw_complex *, fftw_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_2d,
                             ( int n0, int n1, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags ),
                             "fftw_plan_dft_2d(int, int, fftw_complex *, fftw_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_3d,
                             ( int n0, int n1, int n2, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags ),
                             "fftw_plan_dft_3d(int, int, int, fftw_complex *, fftw_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_many_dft,
                             ( int rank, const int * n, int howmany, fftw_complex * in, const int * inembed, int istride, int idist, fftw_complex * out, const int * onembed, int ostride, int odist, int sign, unsigned int flags ),
                             "fftw_plan_many_dft(int, const int *, int, fftw_complex *, const int *, int, int, fftw_complex *, const int *, int, int, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru_dft,
                             ( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags ),
                             "fftw_plan_guru_dft(int, const fftw_iodim *, int, const fftw_iodim *, fftw_complex *, fftw_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru_split_dft,
                             ( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * ri, double * ii, double * ro, double * io, unsigned int flags ),
                             "fftw_plan_guru_split_dft(int, const fftw_iodim *, int, const fftw_iodim *, double *, double *, double *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru64_dft,
                             ( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, fftw_complex * in, fftw_complex * out, int sign, unsigned int flags ),
                             "fftw_plan_guru64_dft(int, const fftw_iodim64 *, int, const fftw_iodim64 *, fftw_complex *, fftw_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru64_split_dft,
                             ( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * ri, double * ii, double * ro, double * io, unsigned int flags ),
                             "fftw_plan_guru64_split_dft(int, const fftw_iodim64 *, int, const fftw_iodim64 *, double *, double *, double *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_execute_dft,
                             ( const fftw_plan p, fftw_complex * in, fftw_complex * out ),
                             "fftw_execute_dft(const fftw_plan, fftw_complex *, fftw_complex *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_execute_split_dft,
                             ( const fftw_plan p, double * ri, double * ii, double * ro, double * io ),
                             "fftw_execute_split_dft(const fftw_plan, double *, double *, double *, double *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_many_dft_r2c,
                             ( int rank, const int * n, int howmany, double * in, const int * inembed, int istride, int idist, fftw_complex * out, const int * onembed, int ostride, int odist, unsigned int flags ),
                             "fftw_plan_many_dft_r2c(int, const int *, int, double *, const int *, int, int, fftw_complex *, const int *, int, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_r2c,
                             ( int rank, const int * n, double * in, fftw_complex * out, unsigned int flags ),
                             "fftw_plan_dft_r2c(int, const int *, double *, fftw_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_r2c_1d,
                             ( int n, double * in, fftw_complex * out, unsigned int flags ),
                             "fftw_plan_dft_r2c_1d(int, double *, fftw_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_r2c_2d,
                             ( int n0, int n1, double * in, fftw_complex * out, unsigned int flags ),
                             "fftw_plan_dft_r2c_2d(int, int, double *, fftw_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_r2c_3d,
                             ( int n0, int n1, int n2, double * in, fftw_complex * out, unsigned int flags ),
                             "fftw_plan_dft_r2c_3d(int, int, int, double *, fftw_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_many_dft_c2r,
                             ( int rank, const int * n, int howmany, fftw_complex * in, const int * inembed, int istride, int idist, double * out, const int * onembed, int ostride, int odist, unsigned int flags ),
                             "fftw_plan_many_dft_c2r(int, const int *, int, fftw_complex *, const int *, int, int, double *, const int *, int, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_c2r,
                             ( int rank, const int * n, fftw_complex * in, double * out, unsigned int flags ),
                             "fftw_plan_dft_c2r(int, const int *, fftw_complex *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_c2r_1d,
                             ( int n, fftw_complex * in, double * out, unsigned int flags ),
                             "fftw_plan_dft_c2r_1d(int, fftw_complex *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_c2r_2d,
                             ( int n0, int n1, fftw_complex * in, double * out, unsigned int flags ),
                             "fftw_plan_dft_c2r_2d(int, int, fftw_complex *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_dft_c2r_3d,
                             ( int n0, int n1, int n2, fftw_complex * in, double * out, unsigned int flags ),
                             "fftw_plan_dft_c2r_3d(int, int, int, fftw_complex *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru_dft_r2c,
                             ( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * in, fftw_complex * out, unsigned int flags ),
                             "fftw_plan_guru_dft_r2c(int, const fftw_iodim *, int, const fftw_iodim *, double *, fftw_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru_dft_c2r,
                             ( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, fftw_complex * in, double * out, unsigned int flags ),
                             "fftw_plan_guru_dft_c2r(int, const fftw_iodim *, int, const fftw_iodim *, fftw_complex *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru_split_dft_r2c,
                             ( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * in, double * ro, double * io, unsigned int flags ),
                             "fftw_plan_guru_split_dft_r2c(int, const fftw_iodim *, int, const fftw_iodim *, double *, double *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru_split_dft_c2r,
                             ( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * ri, double * ii, double * out, unsigned int flags ),
                             "fftw_plan_guru_split_dft_c2r(int, const fftw_iodim *, int, const fftw_iodim *, double *, double *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru64_dft_r2c,
                             ( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * in, fftw_complex * out, unsigned int flags ),
                             "fftw_plan_guru64_dft_r2c(int, const fftw_iodim64 *, int, const fftw_iodim64 *, double *, fftw_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru64_dft_c2r,
                             ( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, fftw_complex * in, double * out, unsigned int flags ),
                             "fftw_plan_guru64_dft_c2r(int, const fftw_iodim64 *, int, const fftw_iodim64 *, fftw_complex *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru64_split_dft_r2c,
                             ( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * in, double * ro, double * io, unsigned int flags ),
                             "fftw_plan_guru64_split_dft_r2c(int, const fftw_iodim64 *, int, const fftw_iodim64 *, double *, double *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru64_split_dft_c2r,
                             ( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * ri, double * ii, double * out, unsigned int flags ),
                             "fftw_plan_guru64_split_dft_c2r(int, const fftw_iodim64 *, int, const fftw_iodim64 *, double *, double *, double *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_execute_dft_r2c,
                             ( const fftw_plan p, double * in, fftw_complex * out ),
                             "fftw_execute_dft_r2c(const fftw_plan, double *, fftw_complex *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_execute_dft_c2r,
                             ( const fftw_plan p, fftw_complex * in, double * out ),
                             "fftw_execute_dft_c2r(const fftw_plan, fftw_complex *, double *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_execute_split_dft_r2c,
                             ( const fftw_plan p, double * in, double * ro, double * io ),
                             "fftw_execute_split_dft_r2c(const fftw_plan, double *, double *, double *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_execute_split_dft_c2r,
                             ( const fftw_plan p, double * ri, double * ii, double * out ),
                             "fftw_execute_split_dft_c2r(const fftw_plan, double *, double *, double *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_many_r2r,
                             ( int rank, const int * n, int howmany, double * in, const int * inembed, int istride, int idist, double * out, const int * onembed, int ostride, int odist, const fftw_r2r_kind * kind, unsigned int flags ),
                             "fftw_plan_many_r2r(int, const int *, int, double *, const int *, int, int, double *, const int *, int, int, const fftw_r2r_kind *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_r2r,
                             ( int rank, const int * n, double * in, double * out, const fftw_r2r_kind * kind, unsigned int flags ),
                             "fftw_plan_r2r(int, const int *, double *, double *, const fftw_r2r_kind *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_r2r_1d,
                             ( int n, double * in, double * out, fftw_r2r_kind kind, unsigned int flags ),
                             "fftw_plan_r2r_1d(int, double *, double *, fftw_r2r_kind, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_r2r_2d,
                             ( int n0, int n1, double * in, double * out, fftw_r2r_kind kind0, fftw_r2r_kind kind1, unsigned int flags ),
                             "fftw_plan_r2r_2d(int, int, double *, double *, fftw_r2r_kind, fftw_r2r_kind, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_r2r_3d,
                             ( int n0, int n1, int n2, double * in, double * out, fftw_r2r_kind kind0, fftw_r2r_kind kind1, fftw_r2r_kind kind2, unsigned int flags ),
                             "fftw_plan_r2r_3d(int, int, int, double *, double *, fftw_r2r_kind, fftw_r2r_kind, fftw_r2r_kind, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru_r2r,
                             ( int rank, const fftw_iodim * dims, int howmany_rank, const fftw_iodim * howmany_dims, double * in, double * out, const fftw_r2r_kind * kind, unsigned int flags ),
                             "fftw_plan_guru_r2r(int, const fftw_iodim *, int, const fftw_iodim *, double *, double *, const fftw_r2r_kind *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_plan ),
                             fftw_plan_guru64_r2r,
                             ( int rank, const fftw_iodim64 * dims, int howmany_rank, const fftw_iodim64 * howmany_dims, double * in, double * out, const fftw_r2r_kind * kind, unsigned int flags ),
                             "fftw_plan_guru64_r2r(int, const fftw_iodim64 *, int, const fftw_iodim64 *, double *, double *, const fftw_r2r_kind *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_execute_r2r,
                             ( const fftw_plan p, double * in, double * out ),
                             "fftw_execute_r2r(const fftw_plan, double *, double *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_destroy_plan,
                             ( fftw_plan p ),
                             "fftw_destroy_plan(fftw_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_forget_wisdom,
                             ( void ),
                             "fftw_forget_wisdom()",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_cleanup,
                             ( void ),
                             "fftw_cleanup()",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_set_timelimit,
                             ( double t ),
                             "fftw_set_timelimit(double)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftw_export_wisdom_to_filename,
                             ( const char * filename ),
                             "fftw_export_wisdom_to_filename(const char *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_export_wisdom_to_file,
                             ( FILE * output_file ),
                             "fftw_export_wisdom_to_file(FILE *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( char * ),
                             fftw_export_wisdom_to_string,
                             ( void ),
                             "fftw_export_wisdom_to_string()",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_export_wisdom,
                             ( fftw_write_char_func write_char, void * data ),
                             "fftw_export_wisdom(fftw_write_char_func, void *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftw_import_system_wisdom,
                             ( void ),
                             "fftw_import_system_wisdom()",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftw_import_wisdom_from_filename,
                             ( const char * filename ),
                             "fftw_import_wisdom_from_filename(const char *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftw_import_wisdom_from_file,
                             ( FILE * input_file ),
                             "fftw_import_wisdom_from_file(FILE *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftw_import_wisdom_from_string,
                             ( const char * input_string ),
                             "fftw_import_wisdom_from_string(const char *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftw_import_wisdom,
                             ( fftw_read_char_func read_char, void * data ),
                             "fftw_import_wisdom(fftw_read_char_func, void *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_fprint_plan,
                             ( const fftw_plan p, FILE * output_file ),
                             "fftw_fprint_plan(const fftw_plan, FILE *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_print_plan,
                             ( const fftw_plan p ),
                             "fftw_print_plan(const fftw_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( char * ),
                             fftw_sprint_plan,
                             ( const fftw_plan p ),
                             "fftw_sprint_plan(const fftw_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void * ),
                             fftw_malloc,
                             ( size_t n ),
                             "fftw_malloc(size_t)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double * ),
                             fftw_alloc_real,
                             ( size_t n ),
                             "fftw_alloc_real(size_t)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftw_complex * ),
                             fftw_alloc_complex,
                             ( size_t n ),
                             "fftw_alloc_complex(size_t)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_free,
                             ( void * p ),
                             "fftw_free(void *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftw_flops,
                             ( const fftw_plan p, double * add, double * mul, double * fmas ),
                             "fftw_flops(const fftw_plan, double *, double *, double *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double ),
                             fftw_estimate_cost,
                             ( const fftw_plan p ),
                             "fftw_estimate_cost(const fftw_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double ),
                             fftw_cost,
                             ( const fftw_plan p ),
                             "fftw_cost(const fftw_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftw_alignment_of,
                             ( double * p ),
                             "fftw_alignment_of(double *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             355,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_execute,
                             ( const fftwf_plan p ),
                             "fftwf_execute(const fftwf_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft,
                             ( int rank, const int * n, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags ),
                             "fftwf_plan_dft(int, const int *, fftwf_complex *, fftwf_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_1d,
                             ( int n, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags ),
                             "fftwf_plan_dft_1d(int, fftwf_complex *, fftwf_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_2d,
                             ( int n0, int n1, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags ),
                             "fftwf_plan_dft_2d(int, int, fftwf_complex *, fftwf_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_3d,
                             ( int n0, int n1, int n2, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags ),
                             "fftwf_plan_dft_3d(int, int, int, fftwf_complex *, fftwf_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_many_dft,
                             ( int rank, const int * n, int howmany, fftwf_complex * in, const int * inembed, int istride, int idist, fftwf_complex * out, const int * onembed, int ostride, int odist, int sign, unsigned int flags ),
                             "fftwf_plan_many_dft(int, const int *, int, fftwf_complex *, const int *, int, int, fftwf_complex *, const int *, int, int, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru_dft,
                             ( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags ),
                             "fftwf_plan_guru_dft(int, const fftwf_iodim *, int, const fftwf_iodim *, fftwf_complex *, fftwf_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru_split_dft,
                             ( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * ri, float * ii, float * ro, float * io, unsigned int flags ),
                             "fftwf_plan_guru_split_dft(int, const fftwf_iodim *, int, const fftwf_iodim *, float *, float *, float *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru64_dft,
                             ( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, fftwf_complex * in, fftwf_complex * out, int sign, unsigned int flags ),
                             "fftwf_plan_guru64_dft(int, const fftwf_iodim64 *, int, const fftwf_iodim64 *, fftwf_complex *, fftwf_complex *, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru64_split_dft,
                             ( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * ri, float * ii, float * ro, float * io, unsigned int flags ),
                             "fftwf_plan_guru64_split_dft(int, const fftwf_iodim64 *, int, const fftwf_iodim64 *, float *, float *, float *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_execute_dft,
                             ( const fftwf_plan p, fftwf_complex * in, fftwf_complex * out ),
                             "fftwf_execute_dft(const fftwf_plan, fftwf_complex *, fftwf_complex *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_execute_split_dft,
                             ( const fftwf_plan p, float * ri, float * ii, float * ro, float * io ),
                             "fftwf_execute_split_dft(const fftwf_plan, float *, float *, float *, float *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_many_dft_r2c,
                             ( int rank, const int * n, int howmany, float * in, const int * inembed, int istride, int idist, fftwf_complex * out, const int * onembed, int ostride, int odist, unsigned int flags ),
                             "fftwf_plan_many_dft_r2c(int, const int *, int, float *, const int *, int, int, fftwf_complex *, const int *, int, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_r2c,
                             ( int rank, const int * n, float * in, fftwf_complex * out, unsigned int flags ),
                             "fftwf_plan_dft_r2c(int, const int *, float *, fftwf_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_r2c_1d,
                             ( int n, float * in, fftwf_complex * out, unsigned int flags ),
                             "fftwf_plan_dft_r2c_1d(int, float *, fftwf_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_r2c_2d,
                             ( int n0, int n1, float * in, fftwf_complex * out, unsigned int flags ),
                             "fftwf_plan_dft_r2c_2d(int, int, float *, fftwf_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_r2c_3d,
                             ( int n0, int n1, int n2, float * in, fftwf_complex * out, unsigned int flags ),
                             "fftwf_plan_dft_r2c_3d(int, int, int, float *, fftwf_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_many_dft_c2r,
                             ( int rank, const int * n, int howmany, fftwf_complex * in, const int * inembed, int istride, int idist, float * out, const int * onembed, int ostride, int odist, unsigned int flags ),
                             "fftwf_plan_many_dft_c2r(int, const int *, int, fftwf_complex *, const int *, int, int, float *, const int *, int, int, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_c2r,
                             ( int rank, const int * n, fftwf_complex * in, float * out, unsigned int flags ),
                             "fftwf_plan_dft_c2r(int, const int *, fftwf_complex *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_c2r_1d,
                             ( int n, fftwf_complex * in, float * out, unsigned int flags ),
                             "fftwf_plan_dft_c2r_1d(int, fftwf_complex *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_c2r_2d,
                             ( int n0, int n1, fftwf_complex * in, float * out, unsigned int flags ),
                             "fftwf_plan_dft_c2r_2d(int, int, fftwf_complex *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_dft_c2r_3d,
                             ( int n0, int n1, int n2, fftwf_complex * in, float * out, unsigned int flags ),
                             "fftwf_plan_dft_c2r_3d(int, int, int, fftwf_complex *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru_dft_r2c,
                             ( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * in, fftwf_complex * out, unsigned int flags ),
                             "fftwf_plan_guru_dft_r2c(int, const fftwf_iodim *, int, const fftwf_iodim *, float *, fftwf_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru_dft_c2r,
                             ( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, fftwf_complex * in, float * out, unsigned int flags ),
                             "fftwf_plan_guru_dft_c2r(int, const fftwf_iodim *, int, const fftwf_iodim *, fftwf_complex *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru_split_dft_r2c,
                             ( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * in, float * ro, float * io, unsigned int flags ),
                             "fftwf_plan_guru_split_dft_r2c(int, const fftwf_iodim *, int, const fftwf_iodim *, float *, float *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru_split_dft_c2r,
                             ( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * ri, float * ii, float * out, unsigned int flags ),
                             "fftwf_plan_guru_split_dft_c2r(int, const fftwf_iodim *, int, const fftwf_iodim *, float *, float *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru64_dft_r2c,
                             ( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * in, fftwf_complex * out, unsigned int flags ),
                             "fftwf_plan_guru64_dft_r2c(int, const fftwf_iodim64 *, int, const fftwf_iodim64 *, float *, fftwf_complex *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru64_dft_c2r,
                             ( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, fftwf_complex * in, float * out, unsigned int flags ),
                             "fftwf_plan_guru64_dft_c2r(int, const fftwf_iodim64 *, int, const fftwf_iodim64 *, fftwf_complex *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru64_split_dft_r2c,
                             ( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * in, float * ro, float * io, unsigned int flags ),
                             "fftwf_plan_guru64_split_dft_r2c(int, const fftwf_iodim64 *, int, const fftwf_iodim64 *, float *, float *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru64_split_dft_c2r,
                             ( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * ri, float * ii, float * out, unsigned int flags ),
                             "fftwf_plan_guru64_split_dft_c2r(int, const fftwf_iodim64 *, int, const fftwf_iodim64 *, float *, float *, float *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_execute_dft_r2c,
                             ( const fftwf_plan p, float * in, fftwf_complex * out ),
                             "fftwf_execute_dft_r2c(const fftwf_plan, float *, fftwf_complex *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_execute_dft_c2r,
                             ( const fftwf_plan p, fftwf_complex * in, float * out ),
                             "fftwf_execute_dft_c2r(const fftwf_plan, fftwf_complex *, float *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_execute_split_dft_r2c,
                             ( const fftwf_plan p, float * in, float * ro, float * io ),
                             "fftwf_execute_split_dft_r2c(const fftwf_plan, float *, float *, float *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_execute_split_dft_c2r,
                             ( const fftwf_plan p, float * ri, float * ii, float * out ),
                             "fftwf_execute_split_dft_c2r(const fftwf_plan, float *, float *, float *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_many_r2r,
                             ( int rank, const int * n, int howmany, float * in, const int * inembed, int istride, int idist, float * out, const int * onembed, int ostride, int odist, const fftwf_r2r_kind * kind, unsigned int flags ),
                             "fftwf_plan_many_r2r(int, const int *, int, float *, const int *, int, int, float *, const int *, int, int, const fftwf_r2r_kind *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_r2r,
                             ( int rank, const int * n, float * in, float * out, const fftwf_r2r_kind * kind, unsigned int flags ),
                             "fftwf_plan_r2r(int, const int *, float *, float *, const fftwf_r2r_kind *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_r2r_1d,
                             ( int n, float * in, float * out, fftwf_r2r_kind kind, unsigned int flags ),
                             "fftwf_plan_r2r_1d(int, float *, float *, fftwf_r2r_kind, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_r2r_2d,
                             ( int n0, int n1, float * in, float * out, fftwf_r2r_kind kind0, fftwf_r2r_kind kind1, unsigned int flags ),
                             "fftwf_plan_r2r_2d(int, int, float *, float *, fftwf_r2r_kind, fftwf_r2r_kind, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_r2r_3d,
                             ( int n0, int n1, int n2, float * in, float * out, fftwf_r2r_kind kind0, fftwf_r2r_kind kind1, fftwf_r2r_kind kind2, unsigned int flags ),
                             "fftwf_plan_r2r_3d(int, int, int, float *, float *, fftwf_r2r_kind, fftwf_r2r_kind, fftwf_r2r_kind, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru_r2r,
                             ( int rank, const fftwf_iodim * dims, int howmany_rank, const fftwf_iodim * howmany_dims, float * in, float * out, const fftwf_r2r_kind * kind, unsigned int flags ),
                             "fftwf_plan_guru_r2r(int, const fftwf_iodim *, int, const fftwf_iodim *, float *, float *, const fftwf_r2r_kind *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_plan ),
                             fftwf_plan_guru64_r2r,
                             ( int rank, const fftwf_iodim64 * dims, int howmany_rank, const fftwf_iodim64 * howmany_dims, float * in, float * out, const fftwf_r2r_kind * kind, unsigned int flags ),
                             "fftwf_plan_guru64_r2r(int, const fftwf_iodim64 *, int, const fftwf_iodim64 *, float *, float *, const fftwf_r2r_kind *, unsigned int)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_execute_r2r,
                             ( const fftwf_plan p, float * in, float * out ),
                             "fftwf_execute_r2r(const fftwf_plan, float *, float *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_destroy_plan,
                             ( fftwf_plan p ),
                             "fftwf_destroy_plan(fftwf_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_forget_wisdom,
                             ( void ),
                             "fftwf_forget_wisdom()",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_cleanup,
                             ( void ),
                             "fftwf_cleanup()",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_set_timelimit,
                             ( double t ),
                             "fftwf_set_timelimit(double)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftwf_export_wisdom_to_filename,
                             ( const char * filename ),
                             "fftwf_export_wisdom_to_filename(const char *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_export_wisdom_to_file,
                             ( FILE * output_file ),
                             "fftwf_export_wisdom_to_file(FILE *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( char * ),
                             fftwf_export_wisdom_to_string,
                             ( void ),
                             "fftwf_export_wisdom_to_string()",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_export_wisdom,
                             ( fftwf_write_char_func write_char, void * data ),
                             "fftwf_export_wisdom(fftwf_write_char_func, void *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftwf_import_system_wisdom,
                             ( void ),
                             "fftwf_import_system_wisdom()",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftwf_import_wisdom_from_filename,
                             ( const char * filename ),
                             "fftwf_import_wisdom_from_filename(const char *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftwf_import_wisdom_from_file,
                             ( FILE * input_file ),
                             "fftwf_import_wisdom_from_file(FILE *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftwf_import_wisdom_from_string,
                             ( const char * input_string ),
                             "fftwf_import_wisdom_from_string(const char *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftwf_import_wisdom,
                             ( fftwf_read_char_func read_char, void * data ),
                             "fftwf_import_wisdom(fftwf_read_char_func, void *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_fprint_plan,
                             ( const fftwf_plan p, FILE * output_file ),
                             "fftwf_fprint_plan(const fftwf_plan, FILE *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_print_plan,
                             ( const fftwf_plan p ),
                             "fftwf_print_plan(const fftwf_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( char * ),
                             fftwf_sprint_plan,
                             ( const fftwf_plan p ),
                             "fftwf_sprint_plan(const fftwf_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void * ),
                             fftwf_malloc,
                             ( size_t n ),
                             "fftwf_malloc(size_t)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( float * ),
                             fftwf_alloc_real,
                             ( size_t n ),
                             "fftwf_alloc_real(size_t)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( fftwf_complex * ),
                             fftwf_alloc_complex,
                             ( size_t n ),
                             "fftwf_alloc_complex(size_t)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_free,
                             ( void * p ),
                             "fftwf_free(void *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
                             fftwf_flops,
                             ( const fftwf_plan p, double * add, double * mul, double * fmas ),
                             "fftwf_flops(const fftwf_plan, double *, double *, double *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double ),
                             fftwf_estimate_cost,
                             ( const fftwf_plan p ),
                             "fftwf_estimate_cost(const fftwf_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( double ),
                             fftwf_cost,
                             ( const fftwf_plan p ),
                             "fftwf_cost(const fftwf_plan)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

SCOREP_LIBWRAP_PROCESS_FUNC( ( int ),
                             fftwf_alignment_of,
                             ( float * p ),
                             "fftwf_alignment_of(float *)",
                             "/opt/cray/fftw/3.3.4.11/interlagos/include/fftw3.h",
                             356,
                              )

#undef SCOREP_LIBWRAP_PROCESS_FUNC
#ifdef SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#undef SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#endif

