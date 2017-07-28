#include "libwrap.h"

#include <stdio.h>

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

    printf("%lf\n", sqrt(argc));

    return 0;
}
