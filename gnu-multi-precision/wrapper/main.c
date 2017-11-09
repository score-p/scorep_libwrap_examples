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

    mpz_t a, b, c;
    mpz_init_set_str(a, "1", 10);
    mpz_init_set_str(b, "2", 10);
    mpz_add (c, a, b);

    printf("%s + %s = %s\n", mpz_get_str (NULL, 10, a), mpz_get_str (NULL, 10, b), mpz_get_str (NULL, 10, c));

    return 0;
}
