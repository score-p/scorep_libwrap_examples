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

    QApplication app(argc, argv);
    QWidget w;
    QImage i;
    w.show();
    return app.exec();
}
