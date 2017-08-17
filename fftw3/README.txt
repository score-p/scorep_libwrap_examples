# No -I, -L, -l flags necessary since Cray's `cc` adds these automatically in this case

$ scorep-libwrap-init --name fftw3 -x c
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

    $ scorep --libwrap=fftw3 cc  app.c   -o app

For detailed instructions consult 'README.md'.

###############################################################################

# Add the directory of the fftw3 includes to the filter.
# Without this the wrapper generator would wrap every function it finds,
# including system functions.

$ vim fftw3.filter

"""
SCOREP_FILE_NAMES_BEGIN
  EXCLUDE *
  INCLUDE /opt/cray/fftw/3.3.4.11/x86_64/include/*
SCOREP_FILE_NAMES_END
"""

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

###############################################################################

$ make check
  UNCERTAIN fftw_execute
  UNCERTAIN fftw_plan_dft
  UNCERTAIN fftw_plan_dft_1d
  UNCERTAIN fftw_plan_dft_2d
  UNCERTAIN fftw_plan_dft_3d
  UNCERTAIN fftw_plan_many_dft
  UNCERTAIN fftw_plan_guru_dft
  UNCERTAIN fftw_plan_guru_split_dft
  UNCERTAIN fftw_plan_guru64_dft
  UNCERTAIN fftw_plan_guru64_split_dft
  UNCERTAIN fftw_execute_dft
  UNCERTAIN fftw_execute_split_dft
  UNCERTAIN fftw_plan_many_dft_r2c
  UNCERTAIN fftw_plan_dft_r2c
  UNCERTAIN fftw_plan_dft_r2c_1d
  UNCERTAIN fftw_plan_dft_r2c_2d
  UNCERTAIN fftw_plan_dft_r2c_3d
  UNCERTAIN fftw_plan_many_dft_c2r
  UNCERTAIN fftw_plan_dft_c2r
  UNCERTAIN fftw_plan_dft_c2r_1d
  UNCERTAIN fftw_plan_dft_c2r_2d
  UNCERTAIN fftw_plan_dft_c2r_3d
  UNCERTAIN fftw_plan_guru_dft_r2c
  UNCERTAIN fftw_plan_guru_dft_c2r
  UNCERTAIN fftw_plan_guru_split_dft_r2c
  UNCERTAIN fftw_plan_guru_split_dft_c2r
  UNCERTAIN fftw_plan_guru64_dft_r2c
  UNCERTAIN fftw_plan_guru64_dft_c2r
  UNCERTAIN fftw_plan_guru64_split_dft_r2c
  UNCERTAIN fftw_plan_guru64_split_dft_c2r
  UNCERTAIN fftw_execute_dft_r2c
  UNCERTAIN fftw_execute_dft_c2r
  UNCERTAIN fftw_execute_split_dft_r2c
  UNCERTAIN fftw_execute_split_dft_c2r
  UNCERTAIN fftw_plan_many_r2r
  UNCERTAIN fftw_plan_r2r
  UNCERTAIN fftw_plan_r2r_1d
  UNCERTAIN fftw_plan_r2r_2d
  UNCERTAIN fftw_plan_r2r_3d
  UNCERTAIN fftw_plan_guru_r2r
  UNCERTAIN fftw_plan_guru64_r2r
  UNCERTAIN fftw_execute_r2r
  UNCERTAIN fftw_destroy_plan
  UNCERTAIN fftw_forget_wisdom
  UNCERTAIN fftw_cleanup
  UNCERTAIN fftw_set_timelimit
  UNCERTAIN fftw_plan_with_nthreads
  UNCERTAIN fftw_init_threads                                                                                                                                        
  UNCERTAIN fftw_cleanup_threads
  UNCERTAIN fftw_export_wisdom_to_filename
  UNCERTAIN fftw_export_wisdom_to_file
  UNCERTAIN fftw_export_wisdom_to_string
  UNCERTAIN fftw_export_wisdom
  UNCERTAIN fftw_import_system_wisdom
  UNCERTAIN fftw_import_wisdom_from_filename
  UNCERTAIN fftw_import_wisdom_from_file
  UNCERTAIN fftw_import_wisdom_from_string
  UNCERTAIN fftw_import_wisdom
  UNCERTAIN fftw_fprint_plan
  UNCERTAIN fftw_print_plan
  UNCERTAIN fftw_sprint_plan
  UNCERTAIN fftw_malloc
  UNCERTAIN fftw_alloc_real
  UNCERTAIN fftw_alloc_complex
  UNCERTAIN fftw_free
  UNCERTAIN fftw_flops
  UNCERTAIN fftw_estimate_cost
  UNCERTAIN fftw_cost
  UNCERTAIN fftw_alignment_of
  UNCERTAIN fftwf_execute
  UNCERTAIN fftwf_plan_dft
  UNCERTAIN fftwf_plan_dft_1d
  UNCERTAIN fftwf_plan_dft_2d
  UNCERTAIN fftwf_plan_dft_3d
  UNCERTAIN fftwf_plan_many_dft
  UNCERTAIN fftwf_plan_guru_dft
  UNCERTAIN fftwf_plan_guru_split_dft
  UNCERTAIN fftwf_plan_guru64_dft
  UNCERTAIN fftwf_plan_guru64_split_dft
  UNCERTAIN fftwf_execute_dft
  UNCERTAIN fftwf_execute_split_dft
  UNCERTAIN fftwf_plan_many_dft_r2c
  UNCERTAIN fftwf_plan_dft_r2c
  UNCERTAIN fftwf_plan_dft_r2c_1d
  UNCERTAIN fftwf_plan_dft_r2c_2d
  UNCERTAIN fftwf_plan_dft_r2c_3d
  UNCERTAIN fftwf_plan_many_dft_c2r
  UNCERTAIN fftwf_plan_dft_c2r
  UNCERTAIN fftwf_plan_dft_c2r_1d
  UNCERTAIN fftwf_plan_dft_c2r_2d
  UNCERTAIN fftwf_plan_dft_c2r_3d
  UNCERTAIN fftwf_plan_guru_dft_r2c
  UNCERTAIN fftwf_plan_guru_dft_c2r
  UNCERTAIN fftwf_plan_guru_split_dft_r2c
  UNCERTAIN fftwf_plan_guru_split_dft_c2r
  UNCERTAIN fftwf_plan_guru64_dft_r2c
  UNCERTAIN fftwf_plan_guru64_dft_c2r
  UNCERTAIN fftwf_plan_guru64_split_dft_r2c
  UNCERTAIN fftwf_plan_guru64_split_dft_c2r
  UNCERTAIN fftwf_execute_dft_r2c
  UNCERTAIN fftwf_execute_dft_c2r
  UNCERTAIN fftwf_execute_split_dft_r2c
  UNCERTAIN fftwf_execute_split_dft_c2r
  UNCERTAIN fftwf_plan_many_r2r
  UNCERTAIN fftwf_plan_r2r
  UNCERTAIN fftwf_plan_r2r_1d
  UNCERTAIN fftwf_plan_r2r_2d
  UNCERTAIN fftwf_plan_r2r_3d
  UNCERTAIN fftwf_plan_guru_r2r
  UNCERTAIN fftwf_plan_guru64_r2r
  UNCERTAIN fftwf_execute_r2r
  UNCERTAIN fftwf_destroy_plan
  UNCERTAIN fftwf_forget_wisdom
  UNCERTAIN fftwf_cleanup
  UNCERTAIN fftwf_set_timelimit
  UNCERTAIN fftwf_plan_with_nthreads
  UNCERTAIN fftwf_init_threads
  UNCERTAIN fftwf_cleanup_threads
  UNCERTAIN fftwf_export_wisdom_to_filename
  UNCERTAIN fftwf_export_wisdom_to_file
  UNCERTAIN fftwf_export_wisdom_to_string
  UNCERTAIN fftwf_export_wisdom
  UNCERTAIN fftwf_import_system_wisdom
  UNCERTAIN fftwf_import_wisdom_from_filename
  UNCERTAIN fftwf_import_wisdom_from_file
  UNCERTAIN fftwf_import_wisdom_from_string
  UNCERTAIN fftwf_import_wisdom
  UNCERTAIN fftwf_fprint_plan
  UNCERTAIN fftwf_print_plan
  UNCERTAIN fftwf_sprint_plan
  UNCERTAIN fftwf_malloc
  UNCERTAIN fftwf_alloc_real
  UNCERTAIN fftwf_alloc_complex
  UNCERTAIN fftwf_free
  UNCERTAIN fftwf_flops
  UNCERTAIN fftwf_estimate_cost
  UNCERTAIN fftwf_cost
  UNCERTAIN fftwf_alignment_of
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
[Score-P] Warning: Symbols that are present without linking against the target
[Score-P]          library and its dependencies have been wrapped. It is uncertain
[Score-P]          whether calls to them can be intercepted, or perhaps you did
[Score-P]          not intend to wrap them. The filter file 'uncertain.filter'
[Score-P]          containing these symbols has been created. Maybe you want to
[Score-P]          add all or some of these symbols to fftw3.filter.
[Score-P]          Then repeat 'make' and 'make check'.
[Score-P] Error: Symbols that are not present in the target library have been
[Score-P]        wrapped. The filter file 'missing.filter' containing these
[Score-P]        symbols has been created. Reconsider your wrapper settings, or
[Score-P]        add these symbols to fftw3.filter if they should not be
[Score-P]        wrapped. Then repeat 'make' and 'make check'.
make: *** [check] Error 1

###############################################################################

$ vim -p fftw3.filter missing.filter

# Put all excludes from missing.filter into fftw3.filter under SCOREP_REGION_NAMES_BEGIN.
# Ignore uncertain.filter, because everything in there is because Cray links fftw3 automatically.
# So the wrapper generator cannot tell whether it is a function from an intentionally
# linked target library or from an automatically linked system library

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
[Score-P] Error: Could not find any shared libraries. I.e. the
[Score-P]        LW_LIBLIST variable in Makefile is empty!
[Score-P]        This can lead to a broken runtime library wrapper.
[Score-P]        If one of the libraries specified via '--libs'
[Score-P]        (Which is the same as the LIBS variable in Makefile)
[Score-P]        is not installed as a shared library, you should
[Score-P]        switch off runtime wrapping by first running
[Score-P]        'make uninstall clean', and then reinitializing the
[Score-P]        working directory by adding
[Score-P]        '--update --static-only-target-library' to your
[Score-P]        'scorep-libwrap-init'-command line.
make: *** [install-libwrap-runtime] Error 1

# The message tells us to rather explicitely specify --static-only-target-library.
# So we do that, now.

###############################################################################

$ make uninstall clean
$ make show-summary
  GEN       fftw3.summary
Configure command:
  scorep-libwrap-init           --name fftw3 \
                                --display-name 'fftw3' \
                                --prefix '/sw/xk6/scorep/4.0-dev-libwrap-r12791-svn/cle5.2_gnu4.9.3' \
                                -x c \
                                --backend vanilla \
                                --cppflags '' \
                                --ldflags '' \
                                --libs ''

Loaded modules:
  module load                   modules/3.2.10.5 \
                                nodestat/2.2-1.0502.60539.1.31.gem \
                                sdb/1.1-1.0502.63652.4.27.gem \
                                alps/5.2.4-2.0502.9950.37.1.gem \
                                lustre-cray_gem_s/2.8.0_3.0.101_0.46.1_1.0502.8871-1.0502.0.6.1 \
                                udreg/2.3.2-1.0502.10518.2.17.gem \
                                ugni/6.0-1.0502.10863.8.28.gem \
                                gni-headers/4.0-1.0502.10859.7.8.gem \
                                dmapp/7.0.1-1.0502.11080.8.74.gem \
                                xpmem/0.1-2.0502.64982.5.3.gem \
                                hss-llm/7.2.0 \
                                Base-opts/1.0.2-1.0502.60680.2.4.gem \
                                cray-mpich/7.5.2 \
                                gcc/4.9.3 \
                                craype-network-gemini \
                                craype-interlagos \
                                craype/2.5.9 \
                                lustredu/1.4 \
                                xalt/0.7.5 \
                                module_msg/0.1 \
                                modulator/1.2.0 \
                                hsi/5.0.2.p1 \
                                DefApps \
                                vim/7.4 \
                                git/2.3.2 \
                                tmux/2.2 \
                                cray-libsci/16.11.1 \
                                pmi/5.0.11 \
                                atp/2.0.5 \
                                PrgEnv-gnu/5.2.82 \
                                papi/5.5.0.2 \
                                pdtoolkit/3.21 \
                                rca/1.0.0-2.0502.60530.1.63.gem \
                                scorep/.4.0-dev-libwrap \
                                fftw/3.3.4.11

###############################################################################

# Take the commands from the above `make show-summary` and modify them

$ scorep-libwrap-init --name fftw3 -x c --update --static-only-target-library                                   
Warning: ./fftw3.filter has not been overwritten.
         If your -I include flags have changed, you might want to update the
         include rules for files with the new/removed directories.
         Detected include directories: .
         
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

    $ scorep --libwrap=fftw3 cc  app.c   -o app

For detailed instructions consult 'README.md'.

###############################################################################

$ make
  CCLD      main
  CPP       libwrap.i
  GEN       scorep_libwrap_fftw3.c
  QUICK-CHECK
  CC        libscorep_libwrap_fftw3_linktime.lo
  CCLD      libscorep_libwrap_fftw3_linktime.la

###############################################################################

$ make install
  QUICK-CHECK
  GEN       fftw3.libwrap
  GEN       fftw3.summary
  INSTALL   libscorep_libwrap_fftw3_linktime.la
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
[Score-P] To further check, please execute the generated binaries:
[Score-P]
[Score-P]     $ ./main_linktime_wrapped
[Score-P]
[Score-P] If available, verify the output via:
[Score-P]
[Score-P]     $ cube_info -m visits:excl scorep-*/profile.cubex
[Score-P]
[Score-P] It should display numbers you would expect from intercepting
[Score-P] main.c's calls to the target library.

###############################################################################

$ qsub ./job-titan.pbs 
3569327

###############################################################################

$ watch qstat -u brendel # until the job is complete

###############################################################################

$ cube_info -m visits:excl scorep-fftw3-test-3569327/profile.cubex
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

###############################################################################

$ ls
3569327-fftw3-test.err  fftw3.nvcc.wrap  libscorep_libwrap_fftw3_linktime.la  libwrap.h              main.c                 README.md                   uncertain.filter
3569327-fftw3-test.out  fftw3.summary    libscorep_libwrap_fftw3_linktime.lo  libwrap.i              main_linktime_wrapped  scorep-fftw3-test-3569327
fftw3.filter            fftw3.wrap       libscorep_libwrap_fftw3_linktime.o   load-modules-titan.sh  Makefile               scorep_libwrap_fftw3.c
fftw3.libwrap           job-titan.pbs    libwrap.c                            main                   missing.filter         scorep_libwrap_fftw3.inc.c

$ ls $SCOREP_DIR/share/scorep/ | grep fftw3
fftw3.filter
fftw3.libwrap
fftw3.nvcc.wrap
fftw3.summary
fftw3.wrap

$ ls $SCOREP_DIR/lib/backend | grep fftw3
libscorep_libwrap_fftw3_linktime.a
libscorep_libwrap_fftw3_linktime.la
