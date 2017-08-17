#include "libwrap.h"

int
main( int   argc,
      char* argv[] )
{
    /*
     * You need to add some calls to the target library to the main function.
     * Note, this program will never be executed, only linked against the target library.
     *
     * After finishing writing this file, run 'make'
     */

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

    return 0;
}
