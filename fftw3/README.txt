# Initialize the environment for ORNL's Titan

. ./load-modules-titan.sh

###############################################################################

$ scorep-libwrap-init --name fftw3 -x c --cppflags "-I$FFTW_INC" --ldflags "-L$FFTW_DIR" --libs "-lfftw3 -lfftw3f"
Created working directory '.' for library wrapper fftw3.

Next:

Add the #include-statements for your library to libwrap.h.

Add one or more function calls to your library into main.c.
It will be used as a linking-test.

    $ make                 # build wrapper
    $ make check           # execute tests
    $ make install         # install wrapper
    $ make installcheck    # execute more tests

To use the wrapper, link your application like this before executing it:

    $ scorep --libwrap=fftw3 cc -I/opt/cray/fftw/3.3.4.11/interlagos/include app.c -L/opt/cray/fftw/3.3.4.11/interlagos/lib -lfftw3 -lfftw3f -o app

For detailed instructions consult 'README.md'.

###############################################################################

$ vim libwrap.h

"""
#include <fftw3.h>
"""

###############################################################################

$ vim main.c

"""
    int N = 10; 
    fftwf_complex *in, *out;
    fftwf_plan p;
    in = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex)*N);
    out = (fftwf_complex*) fftwf_malloc(sizeof(fftwf_complex)*N);

    p = fftwf_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    fftwf_execute(p);
    fftwf_destroy_plan(p);
    fftwf_free(in);
    fftwf_free(out);
"""

###############################################################################

$ make
  CCLD      main
  CPP       libwrap.i
  GEN       scorep_libwrap_fftw3.c
  QUICK-CHECK
[Score-P] Error: There is mismatch between functions found in the header files
[Score-P]        and the symbols present in the target library.
[Score-P]        Use 'make check' to get a list of missing symbols and add
[Score-P]        them to fftw3.filter. After that repeat this step.
make: *** [quick-check] Error 1

###############################################################################

$ make check
  FOUND     fftw_execute
  FOUND     fftw_plan_dft
  FOUND     fftw_plan_dft_1d
  FOUND     fftw_plan_dft_2d
  FOUND     fftw_plan_dft_3d
  FOUND     fftw_plan_many_dft
  FOUND     fftw_plan_guru_dft
  FOUND     fftw_plan_guru_split_dft
  FOUND     fftw_plan_guru64_dft
  FOUND     fftw_plan_guru64_split_dft
  FOUND     fftw_execute_dft
  FOUND     fftw_execute_split_dft
  FOUND     fftw_plan_many_dft_r2c
  FOUND     fftw_plan_dft_r2c
  FOUND     fftw_plan_dft_r2c_1d
  FOUND     fftw_plan_dft_r2c_2d
  FOUND     fftw_plan_dft_r2c_3d
  FOUND     fftw_plan_many_dft_c2r
  FOUND     fftw_plan_dft_c2r
  FOUND     fftw_plan_dft_c2r_1d
  FOUND     fftw_plan_dft_c2r_2d
  FOUND     fftw_plan_dft_c2r_3d
  FOUND     fftw_plan_guru_dft_r2c
  FOUND     fftw_plan_guru_dft_c2r
  FOUND     fftw_plan_guru_split_dft_r2c
  FOUND     fftw_plan_guru_split_dft_c2r
  FOUND     fftw_plan_guru64_dft_r2c
  FOUND     fftw_plan_guru64_dft_c2r
  FOUND     fftw_plan_guru64_split_dft_r2c
  FOUND     fftw_plan_guru64_split_dft_c2r
  FOUND     fftw_execute_dft_r2c
  FOUND     fftw_execute_dft_c2r
  FOUND     fftw_execute_split_dft_r2c
  FOUND     fftw_execute_split_dft_c2r
  FOUND     fftw_plan_many_r2r
  FOUND     fftw_plan_r2r
  FOUND     fftw_plan_r2r_1d
  FOUND     fftw_plan_r2r_2d
  FOUND     fftw_plan_r2r_3d
  FOUND     fftw_plan_guru_r2r
  FOUND     fftw_plan_guru64_r2r
  FOUND     fftw_execute_r2r
  FOUND     fftw_destroy_plan
  FOUND     fftw_forget_wisdom
  FOUND     fftw_cleanup
  FOUND     fftw_set_timelimit
  MISSING   fftw_plan_with_nthreads
  MISSING   fftw_init_threads
  MISSING   fftw_cleanup_threads
  FOUND     fftw_export_wisdom_to_filename
  FOUND     fftw_export_wisdom_to_file
  FOUND     fftw_export_wisdom_to_string
  FOUND     fftw_export_wisdom
  FOUND     fftw_import_system_wisdom
  FOUND     fftw_import_wisdom_from_filename
  FOUND     fftw_import_wisdom_from_file
  FOUND     fftw_import_wisdom_from_string
  FOUND     fftw_import_wisdom
  FOUND     fftw_fprint_plan
  FOUND     fftw_print_plan
  FOUND     fftw_sprint_plan
  FOUND     fftw_malloc
  FOUND     fftw_alloc_real
  FOUND     fftw_alloc_complex
  FOUND     fftw_free
  FOUND     fftw_flops
  FOUND     fftw_estimate_cost
  FOUND     fftw_cost
  FOUND     fftw_alignment_of
  FOUND     fftwf_execute
  FOUND     fftwf_plan_dft
  FOUND     fftwf_plan_dft_1d
  FOUND     fftwf_plan_dft_2d
  FOUND     fftwf_plan_dft_3d
  FOUND     fftwf_plan_many_dft
  FOUND     fftwf_plan_guru_dft
  FOUND     fftwf_plan_guru_split_dft
  FOUND     fftwf_plan_guru64_dft
  FOUND     fftwf_plan_guru64_split_dft
  FOUND     fftwf_execute_dft
  FOUND     fftwf_execute_split_dft
  FOUND     fftwf_plan_many_dft_r2c
  FOUND     fftwf_plan_dft_r2c
  FOUND     fftwf_plan_dft_r2c_1d
  FOUND     fftwf_plan_dft_r2c_2d
  FOUND     fftwf_plan_dft_r2c_3d
  FOUND     fftwf_plan_many_dft_c2r
  FOUND     fftwf_plan_dft_c2r
  FOUND     fftwf_plan_dft_c2r_1d
  FOUND     fftwf_plan_dft_c2r_2d
  FOUND     fftwf_plan_dft_c2r_3d
  FOUND     fftwf_plan_guru_dft_r2c
  FOUND     fftwf_plan_guru_dft_c2r
  FOUND     fftwf_plan_guru_split_dft_r2c
  FOUND     fftwf_plan_guru_split_dft_c2r
  FOUND     fftwf_plan_guru64_dft_r2c
  FOUND     fftwf_plan_guru64_dft_c2r
  FOUND     fftwf_plan_guru64_split_dft_r2c
  FOUND     fftwf_plan_guru64_split_dft_c2r
  FOUND     fftwf_execute_dft_r2c
  FOUND     fftwf_execute_dft_c2r
  FOUND     fftwf_execute_split_dft_r2c
  FOUND     fftwf_execute_split_dft_c2r
  FOUND     fftwf_plan_many_r2r
  FOUND     fftwf_plan_r2r
  FOUND     fftwf_plan_r2r_1d
  FOUND     fftwf_plan_r2r_2d
  FOUND     fftwf_plan_r2r_3d
  FOUND     fftwf_plan_guru_r2r
  FOUND     fftwf_plan_guru64_r2r
  FOUND     fftwf_execute_r2r
  FOUND     fftwf_destroy_plan
  FOUND     fftwf_forget_wisdom
  FOUND     fftwf_cleanup
  FOUND     fftwf_set_timelimit
  MISSING   fftwf_plan_with_nthreads
  MISSING   fftwf_init_threads
  MISSING   fftwf_cleanup_threads
  FOUND     fftwf_export_wisdom_to_filename
  FOUND     fftwf_export_wisdom_to_file
  FOUND     fftwf_export_wisdom_to_string
  FOUND     fftwf_export_wisdom
  FOUND     fftwf_import_system_wisdom
  FOUND     fftwf_import_wisdom_from_filename
  FOUND     fftwf_import_wisdom_from_file
  FOUND     fftwf_import_wisdom_from_string
  FOUND     fftwf_import_wisdom
  FOUND     fftwf_fprint_plan
  FOUND     fftwf_print_plan
  FOUND     fftwf_sprint_plan
  FOUND     fftwf_malloc
  FOUND     fftwf_alloc_real
  FOUND     fftwf_alloc_complex
  FOUND     fftwf_free
  FOUND     fftwf_flops
  FOUND     fftwf_estimate_cost
  FOUND     fftwf_cost
  FOUND     fftwf_alignment_of
  MISSING   fftwl_execute
  MISSING   fftwl_plan_dft
  MISSING   fftwl_plan_dft_1d
  MISSING   fftwl_plan_dft_2d
  MISSING   fftwl_plan_dft_3d
  MISSING   fftwl_plan_many_dft
  MISSING   fftwl_plan_guru_dft
  MISSING   fftwl_plan_guru_split_dft
  MISSING   fftwl_plan_guru64_dft
  MISSING   fftwl_plan_guru64_split_dft
  MISSING   fftwl_execute_dft
  MISSING   fftwl_execute_split_dft
  MISSING   fftwl_plan_many_dft_r2c
  MISSING   fftwl_plan_dft_r2c
  MISSING   fftwl_plan_dft_r2c_1d
  MISSING   fftwl_plan_dft_r2c_2d
  MISSING   fftwl_plan_dft_r2c_3d
  MISSING   fftwl_plan_many_dft_c2r
  MISSING   fftwl_plan_dft_c2r
  MISSING   fftwl_plan_dft_c2r_1d
  MISSING   fftwl_plan_dft_c2r_2d
  MISSING   fftwl_plan_dft_c2r_3d
  MISSING   fftwl_plan_guru_dft_r2c
  MISSING   fftwl_plan_guru_dft_c2r
  MISSING   fftwl_plan_guru_split_dft_r2c
  MISSING   fftwl_plan_guru_split_dft_c2r
  MISSING   fftwl_plan_guru64_dft_r2c
  MISSING   fftwl_plan_guru64_dft_c2r
  MISSING   fftwl_plan_guru64_split_dft_r2c
  MISSING   fftwl_plan_guru64_split_dft_c2r
  MISSING   fftwl_execute_dft_r2c
  MISSING   fftwl_execute_dft_c2r
  MISSING   fftwl_execute_split_dft_r2c
  MISSING   fftwl_execute_split_dft_c2r
  MISSING   fftwl_plan_many_r2r
  MISSING   fftwl_plan_r2r
  MISSING   fftwl_plan_r2r_1d
  MISSING   fftwl_plan_r2r_2d
  MISSING   fftwl_plan_r2r_3d
  MISSING   fftwl_plan_guru_r2r
  MISSING   fftwl_plan_guru64_r2r
  MISSING   fftwl_execute_r2r
  MISSING   fftwl_destroy_plan
  MISSING   fftwl_forget_wisdom
  MISSING   fftwl_cleanup
  MISSING   fftwl_set_timelimit
  MISSING   fftwl_plan_with_nthreads
  MISSING   fftwl_init_threads
  MISSING   fftwl_cleanup_threads
  MISSING   fftwl_export_wisdom_to_filename
  MISSING   fftwl_export_wisdom_to_file
  MISSING   fftwl_export_wisdom_to_string
  MISSING   fftwl_export_wisdom
  MISSING   fftwl_import_system_wisdom
  MISSING   fftwl_import_wisdom_from_filename
  MISSING   fftwl_import_wisdom_from_file
  MISSING   fftwl_import_wisdom_from_string
  MISSING   fftwl_import_wisdom
  MISSING   fftwl_fprint_plan
  MISSING   fftwl_print_plan
  MISSING   fftwl_sprint_plan
  MISSING   fftwl_malloc
  MISSING   fftwl_alloc_real
  MISSING   fftwl_alloc_complex
  MISSING   fftwl_free
  MISSING   fftwl_flops
  MISSING   fftwl_estimate_cost
  MISSING   fftwl_cost
  MISSING   fftwl_alignment_of
  MISSING   fftwq_execute
  MISSING   fftwq_plan_dft
  MISSING   fftwq_plan_dft_1d
  MISSING   fftwq_plan_dft_2d
  MISSING   fftwq_plan_dft_3d
  MISSING   fftwq_plan_many_dft
  MISSING   fftwq_plan_guru_dft
  MISSING   fftwq_plan_guru_split_dft
  MISSING   fftwq_plan_guru64_dft
  MISSING   fftwq_plan_guru64_split_dft
  MISSING   fftwq_execute_dft
  MISSING   fftwq_execute_split_dft
  MISSING   fftwq_plan_many_dft_r2c
  MISSING   fftwq_plan_dft_r2c
  MISSING   fftwq_plan_dft_r2c_1d
  MISSING   fftwq_plan_dft_r2c_2d
  MISSING   fftwq_plan_dft_r2c_3d
  MISSING   fftwq_plan_many_dft_c2r
  MISSING   fftwq_plan_dft_c2r
  MISSING   fftwq_plan_dft_c2r_1d
  MISSING   fftwq_plan_dft_c2r_2d
  MISSING   fftwq_plan_dft_c2r_3d
  MISSING   fftwq_plan_guru_dft_r2c
  MISSING   fftwq_plan_guru_dft_c2r
  MISSING   fftwq_plan_guru_split_dft_r2c
  MISSING   fftwq_plan_guru_split_dft_c2r
  MISSING   fftwq_plan_guru64_dft_r2c
  MISSING   fftwq_plan_guru64_dft_c2r
  MISSING   fftwq_plan_guru64_split_dft_r2c
  MISSING   fftwq_plan_guru64_split_dft_c2r
  MISSING   fftwq_execute_dft_r2c
  MISSING   fftwq_execute_dft_c2r
  MISSING   fftwq_execute_split_dft_r2c
  MISSING   fftwq_execute_split_dft_c2r
  MISSING   fftwq_plan_many_r2r
  MISSING   fftwq_plan_r2r
  MISSING   fftwq_plan_r2r_1d
  MISSING   fftwq_plan_r2r_2d
  MISSING   fftwq_plan_r2r_3d
  MISSING   fftwq_plan_guru_r2r
  MISSING   fftwq_plan_guru64_r2r
  MISSING   fftwq_execute_r2r
  MISSING   fftwq_destroy_plan
  MISSING   fftwq_forget_wisdom
  MISSING   fftwq_cleanup
  MISSING   fftwq_set_timelimit
  MISSING   fftwq_plan_with_nthreads
  MISSING   fftwq_init_threads
  MISSING   fftwq_cleanup_threads
  MISSING   fftwq_export_wisdom_to_filename
  MISSING   fftwq_export_wisdom_to_file
  MISSING   fftwq_export_wisdom_to_string
  MISSING   fftwq_export_wisdom
  MISSING   fftwq_import_system_wisdom
  MISSING   fftwq_import_wisdom_from_filename
  MISSING   fftwq_import_wisdom_from_file
  MISSING   fftwq_import_wisdom_from_string
  MISSING   fftwq_import_wisdom
  MISSING   fftwq_fprint_plan
  MISSING   fftwq_print_plan
  MISSING   fftwq_sprint_plan
  MISSING   fftwq_malloc
  MISSING   fftwq_alloc_real
  MISSING   fftwq_alloc_complex
  MISSING   fftwq_free
  MISSING   fftwq_flops
  MISSING   fftwq_estimate_cost
  MISSING   fftwq_cost
  MISSING   fftwq_alignment_of
[Score-P] Error: Symbols that are not present in the target library have been
[Score-P]        wrapped. The filter file 'missing.filter' containing these
[Score-P]        symbols has been created. Reconsider your wrapper settings, or
[Score-P]        add these symbols to fftw3.filter if they should not be
[Score-P]        wrapped. Then repeat 'make' and 'make check'.
make: *** [check] Error 1

###############################################################################

$ vim -p fftw3.filter missing.filter

# Put all excludes from missing.filter into fftw3.filter under SCOREP_REGION_NAMES_BEGIN.

###############################################################################

$ make
  GEN       scorep_libwrap_fftw3.c
  QUICK-CHECK
  CC        libscorep_libwrap_fftw3_linktime.lo
  CCLD      libscorep_libwrap_fftw3_linktime.la
  CC        libscorep_libwrap_fftw3_runtime.lo
  CCLD      libscorep_libwrap_fftw3_runtime.la

###############################################################################

$ make install
  QUICK-CHECK
  GEN       fftw3.libwrap
  GEN       fftw3.summary
  INSTALL   libscorep_libwrap_fftw3_linktime.la
  INSTALL   libscorep_libwrap_fftw3_runtime.la
  INSTALL   fftw3.libwrap
  INSTALL   fftw3.summary
  INSTALL   fftw3.wrap
  INSTALL   fftw3.nvcc.wrap
  INSTALL   fftw3.filter

###############################################################################

$ make installcheck
  SCOREP    main_linktime_wrapped
/sw/xk6/scorep/4.0-dev-libwrap-r12791-svn/cle5.2_gnu4.9.3/lib/backend/libscorep_measurement.a(libscorep_measurement_libwrap_la-SCOREP_Libwrap.o): In function `SCOREP_Libwrap_Create':
/ccs/home/brendel/sources/scorep/svn-libwrap/build-backend/../src/measurement/SCOREP_Libwrap.c:211: warning: Using 'dlopen' in statically linked applications requires at runtime the shared libraries from the glibc version used for linking
/usr/bin/sha1sum: a.out: No such file or directory
  SCOREP    main_runtime_wrapped
/sw/xk6/scorep/4.0-dev-libwrap-r12791-svn/cle5.2_gnu4.9.3/lib/backend/libscorep_measurement.a(libscorep_measurement_libwrap_la-SCOREP_Libwrap.o): In function `SCOREP_Libwrap_Create':
/ccs/home/brendel/sources/scorep/svn-libwrap/build-backend/../src/measurement/SCOREP_Libwrap.c:211: warning: Using 'dlopen' in statically linked applications requires at runtime the shared libraries from the glibc version used for linking
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

$ qsub ./job-titan.pbs
3596607

###############################################################################

$ watch qstat -u $USER # until the job is complete

###############################################################################

$ cube_info -m visits:excl scorep-fftw3-test-linktime-3632913/profile.cubex
|      Visits (E) | Diff-Calltree
|               1 |  * main
|               2 |  |  * fftwf_malloc(size_t)
|               1 |  |  * fftwf_plan_dft_1d(int, fftwf_complex *, fftwf_complex *, int, unsigned int)
|               1 |  |  |  * fftwf_plan_dft(int, const int *, fftwf_complex *, fftwf_complex *, int, unsigned int)
|               1 |  |  |  |  * fftwf_plan_many_dft(int, const int *, int, fftwf_complex *, const int *, int, int, fftwf_complex *, const int *, int, int, int, unsigned int)
|               8 |  |  |  |  |  * fftwf_alignment_of(float *)
|               1 |  |  * fftwf_execute(const fftwf_plan)
|               1 |  |  * fftwf_destroy_plan(fftwf_plan)
|               2 |  |  * fftwf_free(void *)

$ cube_info -m visits:excl scorep-fftw3-test-runtime-3632913/profile.cubex
|      Visits (E) | Diff-Calltree
|               1 |  * main
|               2 |  |  * fftwf_malloc(size_t)
|               1 |  |  * fftwf_plan_dft_1d(int, fftwf_complex *, fftwf_complex *, int, unsigned int)
|               1 |  |  * fftwf_execute(const fftwf_plan)
|               1 |  |  * fftwf_destroy_plan(fftwf_plan)
|               2 |  |  * fftwf_free(void *)

###############################################################################

$ ls
3632913-fftw3-test.err  fftw3.wrap                           libscorep_libwrap_fftw3_runtime.lo  main                   README.md
3632913-fftw3-test.out  job-titan.pbs                        libscorep_libwrap_fftw3_runtime.o   main.c                 scorep-fftw3-test-linktime-3632913
fftw3.filter            libscorep_libwrap_fftw3_linktime.la  libwrap.c                           main_linktime_wrapped  scorep-fftw3-test-runtime-3632913
fftw3.libwrap           libscorep_libwrap_fftw3_linktime.lo  libwrap.h                           main_runtime_wrapped   scorep_libwrap_fftw3.c
fftw3.nvcc.wrap         libscorep_libwrap_fftw3_linktime.o   libwrap.i                           Makefile               scorep_libwrap_fftw3.inc.c
fftw3.summary           libscorep_libwrap_fftw3_runtime.la   load-modules-titan.sh               missing.filter

$ ls $SCOREP_DIR/share/scorep/ | grep fftw3
fftw3.filter
fftw3.libwrap
fftw3.nvcc.wrap
fftw3.summary
fftw3.wrap

$ ls $SCOREP_DIR/lib/backend | grep fftw3
libscorep_libwrap_fftw3_linktime.a
libscorep_libwrap_fftw3_linktime.la
libscorep_libwrap_fftw3_linktime.so
libscorep_libwrap_fftw3_runtime.a
libscorep_libwrap_fftw3_runtime.la
libscorep_libwrap_fftw3_runtime.so
