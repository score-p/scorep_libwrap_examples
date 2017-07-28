- Same basic structure as ../qimage/README.md
- Additionally we need `fix-type-scopes.sh`
    - It provides a mapping that tells for each type that is locally declared in which class scope it is. This works around a technical limitation of the library wrapper generator / libclang
    - Edit `wrapper_name` in `fix-type-scopes.sh`
    - Source `fix-type-scopes.sh` every time you generate the wrapper newly. I.e. after `make,` if it shows `GEN scorep_libwrap_\*.cc`.
    - If more errors turn up you might need to look up where these types come from, I.e. google "qt UndeclaredType", and add them to the list

-------------------------------------------------------------------------------
$ scorep-libwrap-init --name qtgui_and_qtwidgets --display-name "Qt Gui & Widgets" -x c++ --cppflags "-fPIC -I/usr/include/x86_64-linux-gnu/qt5/" --ldflags "-fPIC" --libs "-lQt5Widgets -lQt5Gui -lQt5Core"
Created working directory '.' for library wrapper qtgui_and_qtwidgets.

Next:

Add the #include-statements for your library to libwrap.h.

Add one or more function calls to your library into main.c.
It will be used as a linking-test.

    $ make                 # build wrapper
    $ make check           # execute tests
    $ make install         # install wrapper
    $ make installcheck    # execute more tests

To use the wrapper, link your application like this before executing it:

    $ scorep --libwrap=qtgui_and_qtwidgets g++ -fPIC -I/usr/include/x86_64-linux-gnu/qt5/ app.cc -fPIC -lQt5Widgets -lQt5Gui -lQt5Core -o app

For detailed instructions consult 'README.md'.

-------------------------------------------------------------------------------
$ vim libwrap.h 
$ cat libwrap.h 
#ifndef LIBWRAP_H
#define LIBWRAP_H

/*
 * You need to  put any needed #include statements to successfully compile a mini program against the
 * to-be-wrapped library in this file.
 *
 * After you are finished, start editing the `main.c` file.
 */

#include <QtGui/QtGui>
#include <QtWidgets/QtWidgets>

#endif /* LIBWRAP_H */

-------------------------------------------------------------------------------
$ vim main.cc 
$ cat main.cc 
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

-------------------------------------------------------------------------------
$ make
  CCLD      main
  CPP       libwrap.i
  GEN       scorep_libwrap_qtgui_and_qtwidgets.cc
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:96: Warning: Ignoring variadic function: 'QMessageLogger::debug(const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger5debugEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:99: Warning: Ignoring variadic function: 'QMessageLogger::info(const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger4infoEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:100: Warning: Ignoring variadic function: 'QMessageLogger::warning(const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger7warningEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:101: Warning: Ignoring variadic function: 'QMessageLogger::critical(const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger8criticalEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:105: Warning: Ignoring variadic function: 'QMessageLogger::debug(const QLoggingCategory &, const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger5debugERK16QLoggingCategoryPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:106: Warning: Ignoring variadic function: 'QMessageLogger::debug(CategoryFunction, const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger5debugEPFRK16QLoggingCategoryvEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:107: Warning: Ignoring variadic function: 'QMessageLogger::info(const QLoggingCategory &, const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger4infoERK16QLoggingCategoryPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:108: Warning: Ignoring variadic function: 'QMessageLogger::info(CategoryFunction, const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger4infoEPFRK16QLoggingCategoryvEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:109: Warning: Ignoring variadic function: 'QMessageLogger::warning(const QLoggingCategory &, const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger7warningERK16QLoggingCategoryPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:110: Warning: Ignoring variadic function: 'QMessageLogger::warning(CategoryFunction, const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger7warningEPFRK16QLoggingCategoryvEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:111: Warning: Ignoring variadic function: 'QMessageLogger::critical(const QLoggingCategory &, const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger8criticalERK16QLoggingCategoryPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:112: Warning: Ignoring variadic function: 'QMessageLogger::critical(CategoryFunction, const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger8criticalEPFRK16QLoggingCategoryvEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:117: Warning: Ignoring variadic function: 'QMessageLogger::fatal(const char *, ...)'. If this function has a 'va_list' variant, add '_ZNK14QMessageLogger5fatalEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:182: Warning: Ignoring variadic function: 'qErrnoWarning(int, const char *, ...)'. If this function has a 'va_list' variant, add '_Z13qErrnoWarningiPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qlogging.h:183: Warning: Ignoring variadic function: 'qErrnoWarning(const char *, ...)'. If this function has a 'va_list' variant, add '_Z13qErrnoWarningPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qbytearray.h:107: Warning: Ignoring variadic function: 'qsnprintf(char *, size_t, const char *, ...)'. If this function has a 'va_list' variant, add '_Z9qsnprintfPcmPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qstring.h:312: Warning: Ignoring variadic function: 'QString::sprintf(const char *, ...)'. If this function has a 'va_list' variant, add '_ZN7QString7sprintfEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtCore/qstring.h:314: Warning: Ignoring variadic function: 'QString::asprintf(const char *, ...)'. If this function has a 'va_list' variant, add '_ZN7QString8asprintfEPKcz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtGui/qpolygon.h:90: Warning: Ignoring variadic function: 'QPolygon::setPoints(int, int, int, ...)'. If this function has a 'va_list' variant, add '_ZN8QPolygon9setPointsEiiiz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtGui/qpolygon.h:92: Warning: Ignoring variadic function: 'QPolygon::putPoints(int, int, int, int, ...)'. If this function has a 'va_list' variant, add '_ZN8QPolygon9putPointsEiiiiz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
  QUICK-CHECK
[Score-P] Error: There is mismatch between functions found in the header files
[Score-P]        and the symbols present in the target library.
[Score-P]        Use 'make check' to get a list of missing symbols and add
[Score-P]        them to qtgui_and_qtwidgets.filter. After that repeat this step.
Makefile:169: recipe for target 'quick-check' failed
make: *** [quick-check] Error 1

-------------------------------------------------------------------------------
$ make check
[Score-P] Warning: Checking 13878 symbols. This may take a while.
  FOUND     _ZN9QtPrivate20QContainerImplHelper3midEiPiS1_
  FOUND     _ZN9QtPrivate19QByteArrayList_joinEPK5QListI10QByteArrayEPKci
  FOUND     _ZN9QtPrivate16QStringList_sortEP11QStringListN2Qt15CaseSensitivityE
  FOUND     _ZN9QtPrivate28QStringList_removeDuplicatesEP11QStringList
  FOUND     _ZN9QtPrivate16QStringList_joinEPK11QStringListPK5QChari
  FOUND     _ZN9QtPrivate18QStringList_filterEPK11QStringListRK7QStringN2Qt15CaseSensitivityE
  FOUND     _ZN9QtPrivate20QStringList_containsEPK11QStringListRK7QStringN2Qt15CaseSensitivityE
  FOUND     _ZN9QtPrivate28QStringList_replaceInStringsEP11QStringListRK7QStringS4_N2Qt15CaseSensitivityE
  FOUND     _ZN9QtPrivate28QStringList_replaceInStringsEP11QStringListRK7QRegExpRK7QString
  FOUND     _ZN9QtPrivate18QStringList_filterEPK11QStringListRK7QRegExp
^CMakefile:283: recipe for target 'check' failed
make: *** [check] Interrupt

$ wc -l qtgui_and_qtwidgets.wrap 
13878 qtgui_and_qtwidgets.wrap

$ grep "QByteArray" qtgui_and_qtwidgets.wrap  # QByteArray class is part of QtCore not Widgets or Gui
$ grep "QString" qtgui_and_qtwidgets.wrap     # QString class is part of QtCore not Widgets or Gui

-------------------------------------------------------------------------------
$ vim qtgui_and_qtwidgets.filter 
$ cat qtgui_and_qtwidgets.filter 
# See Score-P Manual on Filtering for infos

SCOREP_FILE_NAMES_BEGIN
  EXCLUDE *
  INCLUDE /usr/include/x86_64-linux-gnu/qt5/QtGui/*
  INCLUDE /usr/include/x86_64-linux-gnu/qt5/QtWidget/*
  #EXCLUDE */asd?.*
  #INCLUDE */folder/asdf.c */qwerty.*
  #        /etc/bash.bashrc
  #EXCLUDE */querty.h
SCOREP_FILE_NAMES_END

SCOREP_REGION_NAMES_BEGIN
  #EXCLUDE
  #INCLUDE foo*
  #EXCLUDE foo*bar foo*baz
  #        main
  #INCLUDE foo123bar
SCOREP_REGION_NAMES_END

-------------------------------------------------------------------------------
$ make check
[Score-P] Warning: Checking 4587 symbols. This may take a while.
  FOUND     _ZN9QtPrivate22QPixelFormat_createYUVEN12QPixelFormat9YUVLayoutEhNS0_10AlphaUsageENS0_13AlphaPositionENS0_18AlphaPremultipliedENS0_18TypeInterpretationENS0_9ByteOrderE
  FOUND     _ZN2Qt15mightBeRichTextERK7QString
  FOUND     _ZN2Qt20convertFromPlainTextERK7QStringNS_14WhiteSpaceModeE

[..]

  FOUND     _ZNK27QRegularExpressionValidator17regularExpressionEv
  FOUND     _ZN27QRegularExpressionValidator20setRegularExpressionERK18QRegularExpression
  FOUND     _ZN27QRegularExpressionValidator24regularExpressionChangedERK18QRegularExpression
[Score-P] Error: Symbols that are not present in the target library have been
[Score-P]        wrapped. The filter file 'missing.filter' containing these
[Score-P]        symbols has been created. Reconsider your wrapper settings, or
[Score-P]        add these symbols to qtgui_and_qtwidgets.filter if they should not be
[Score-P]        wrapped. Then repeat 'make' and 'make check'.
Makefile:283: recipe for target 'check' failed
make: *** [check] Error 1

-------------------------------------------------------------------------------
$ vim -p qtgui_and_qtwidgets.filter missing.filter

# Put everything from missing.filter to math.filter

-------------------------------------------------------------------------------
$ make
  GEN       scorep_libwrap_qtgui_and_qtwidgets.cc
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtGui/qpolygon.h:90: Warning: Ignoring variadic function: 'QPolygon::setPoints(int, int, int, ...)'. If this function has a 'va_list' variant, add '_ZN8QPolygon9setPointsEiiiz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
[Score-P] /usr/include/x86_64-linux-gnu/qt5/QtGui/qpolygon.h:92: Warning: Ignoring variadic function: 'QPolygon::putPoints(int, int, int, int, ...)'. If this function has a 'va_list' variant, add '_ZN8QPolygon9putPointsEiiiiz:valistvariantfunction' to the LIBWRAP_ELLIPSIS_MAPPING_SYMBOLS variable in the Makefile.
  QUICK-CHECK
  CC        libscorep_libwrap_qtgui_and_qtwidgets_linktime.lo
In file included from scorep_libwrap_qtgui_and_qtwidgets.cc:17:0:
scorep_libwrap_qtgui_and_qtwidgets.inc.c:3479:32: error: ‘InfoFlags’ does not name a type
 SCOREP_LIBWRAP_PROCESS_FUNC( ( InfoFlags ),
                                ^
/opt/scorep-libwrap/include/scorep/SCOREP_Libwrap_Macros.h:146:40: note: in definition of macro ‘_SCOREP_LIBWRAP_RETTYPE’
 #define _SCOREP_LIBWRAP_RETTYPE( ... ) __VA_ARGS__
                                        ^~~~~~~~~~~
scorep_libwrap_qtgui_and_qtwidgets.cc:29:5: note: in expansion of macro ‘SCOREP_LIBWRAP_DECLARE_REAL_FUNC’
     SCOREP_LIBWRAP_DECLARE_REAL_FUNC( rettype, func, args ); \
     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
scorep_libwrap_qtgui_and_qtwidgets.inc.c:3479:1: note: in expansion of macro ‘SCOREP_LIBWRAP_PROCESS_FUNC’
 SCOREP_LIBWRAP_PROCESS_FUNC( ( InfoFlags ),
 ^
scorep_libwrap_qtgui_and_qtwidgets.inc.c:3649:63: error: ‘InfoFlags’ has not been declared
                              ( void *scorep_libwrap_arg_this, InfoFlags flags ),
                                                               ^
/opt/scorep-libwrap/include/scorep/SCOREP_Libwrap_Macros.h:190:74: note: in definition of macro ‘SCOREP_LIBWRAP_DECLARE_REAL_FUNC’
     _SCOREP_LIBWRAP_RETTYPE rettype SCOREP_LIBWRAP_FUNC_REAL_NAME( func )argtypes
                                                                          ^~~~~~~~
scorep_libwrap_qtgui_and_qtwidgets.inc.c:3647:1: note: in expansion of macro ‘SCOREP_LIBWRAP_PROCESS_FUNC’
 SCOREP_LIBWRAP_PROCESS_FUNC( ( void ),
 ^
scorep_libwrap_qtgui_and_qtwidgets.inc.c:3953:32: error: variable or field ‘__real__ZN11QAccessible14installFactoryEPFP20QAccessibleInterfaceRK7QStringP7QObjectE’ declared void
                              ( InterfaceFactory scorep_libwrap_arg_1 ),
                                ^

[..]

/opt/scorep-libwrap/include/scorep/SCOREP_Libwrap_Macros.h:190:74: note: in definition of macro ‘SCOREP_LIBWRAP_DECLARE_REAL_FUNC’
     _SCOREP_LIBWRAP_RETTYPE rettype SCOREP_LIBWRAP_FUNC_REAL_NAME( func )argtypes
                                                                          ^~~~~~~~
scorep_libwrap_qtgui_and_qtwidgets.inc.c:28343:1: note: in expansion of macro ‘SCOREP_LIBWRAP_PROCESS_FUNC’
 SCOREP_LIBWRAP_PROCESS_FUNC( ( QTextCursor ),
 ^
scorep_libwrap_qtgui_and_qtwidgets.cc:7210:1: error: ‘InfoFlags’ does not name a type
 InfoFlags
 ^~~~~~~~~
scorep_libwrap_qtgui_and_qtwidgets.cc:7549:123: error: ‘InfoFlags’ has not been declared
 SCOREP_LIBWRAP_FUNC_NAME( _ZN11QTouchEvent10TouchPoint8setFlagsE6QFlagsINS0_8InfoFlagEE )( void *scorep_libwrap_arg_this, InfoFlags flags )
                                                                                                                           ^~~~~~~~~
scorep_libwrap_qtgui_and_qtwidgets.cc:8168:109: error: variable or field ‘__wrap__ZN11QAccessible14installFactoryEPFP20QAccessibleInterfaceRK7QStringP7QObjectE’ declared void
 SCOREP_LIBWRAP_FUNC_NAME( _ZN11QAccessible14installFactoryEPFP20QAccessibleInterfaceRK7QStringP7QObjectE )( InterfaceFactory scorep_libwrap_arg_1 )
                                                                                                             ^~~~~~~~~~~~~~~~
scorep_libwrap_qtgui_and_qtwidgets.cc:8168:109: error: ‘InterfaceFactory’ was not declared in this scope
scorep_libwrap_qtgui_and_qtwidgets.cc:64587:1: error: expected ‘}’ at end of input
 }
 ^
Makefile:212: recipe for target 'libscorep_libwrap_qtgui_and_qtwidgets_linktime.lo' failed
make: *** [libscorep_libwrap_qtgui_and_qtwidgets_linktime.lo] Error 1

-------------------------------------------------------------------------------
$ . ../fix-type-scopes.sh
$ cat ../fix-type-scopes.sh
wrapper_name=qtgui_and_qtwidgets

prepend_type_scope() {
    if [ $# != 2 ]; then
        echo "Error: Wrong number of parameters. Has to be 2: $*" >&2
        return
    fi

    sed -i "s/^$1$/$2::$1/g" scorep_libwrap_$wrapper_name.cc
    sed -i "s/ $1 / $2::$1 /g" scorep_libwrap_$wrapper_name.cc
    sed -i "s/ $1 / $2::$1 /g" scorep_libwrap_$wrapper_name.inc.c
}

prepend_type_scope InfoFlags           QTouchEvent::TouchPoint
prepend_type_scope InterfaceFactory    QAccessible
prepend_type_scope UpdateHandler       QAccessible
prepend_type_scope RootObjectHandler   QAccessible
prepend_type_scope Id                  QAccessible
prepend_type_scope FormatOptions       QSurfaceFormat
prepend_type_scope FindFlags           QTextDocument
prepend_type_scope RenderFlags         QTextItem
prepend_type_scope RenderHints         QPainter
prepend_type_scope PaintEngineFeatures QPaintEngine
prepend_type_scope PixmapFragmentHints QPainter
prepend_type_scope LayoutFlags         QRawFont
prepend_type_scope PixmapFragmentHints QPainter
prepend_type_scope GlyphRunFlags       QGlyphRun
prepend_type_scope ShaderType          QOpenGLShader

-------------------------------------------------------------------------------
$ make
  QUICK-CHECK
  CC        libscorep_libwrap_qtgui_and_qtwidgets_linktime.lo
  CCLD      libscorep_libwrap_qtgui_and_qtwidgets_linktime.la
ar: `u' modifier ignored since `D' is the default (see `U')
  CC        libscorep_libwrap_qtgui_and_qtwidgets_runtime.lo
  CCLD      libscorep_libwrap_qtgui_and_qtwidgets_runtime.la
ar: `u' modifier ignored since `D' is the default (see `U')

-------------------------------------------------------------------------------
$ make install
  QUICK-CHECK
  GEN       qtgui_and_qtwidgets.libwrap
  GEN       qtgui_and_qtwidgets.summary
  INSTALL   libscorep_libwrap_qtgui_and_qtwidgets_linktime.la
  INSTALL   libscorep_libwrap_qtgui_and_qtwidgets_runtime.la
  INSTALL   qtgui_and_qtwidgets.libwrap
  INSTALL   qtgui_and_qtwidgets.summary
  INSTALL   qtgui_and_qtwidgets.wrap
  INSTALL   qtgui_and_qtwidgets.nvcc.wrap
  INSTALL   qtgui_and_qtwidgets.filter

-------------------------------------------------------------------------------
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

-------------------------------------------------------------------------------
$ ./main_linktime_wrapped && mv scorep-2* scorep-linktime
$ ./main_runtime_wrapped && mv scorep-2* scorep-runtime

-------------------------------------------------------------------------------
$ cube_info -m visits:excl scorep-linktime/profile.cubex
|      Visits (E) | Diff-Calltree
|               1 |  * int main(int, char**)
|               1 |  |  * QImage::QImage()

-------------------------------------------------------------------------------
$ cube_info -m visits:excl scorep-runtime/profile.cubex 
|      Visits (E) | Diff-Calltree
|               1 |  * int main(int, char**)
|               1 |  |  * QTouchDevice::QTouchDevice()
|               1 |  |  * QTouchDevice::setName(const QString &)
|               1 |  |  * QTouchDevice::setType(QTouchDevice::DeviceType)
|               1 |  |  * QTouchDevice::setMaximumTouchPoints(int)
|               2 |  |  * QGuiApplication::desktopSettingsAware()
|               2 |  |  * QDesktopServices::setUrlHandler(const QString &, QObject *, const char *)
|               7 |  |  * QPalette::QPalette()
|             666 |  |  * QBrush::QBrush()
|             915 |  |  * QColor::setRgb(int, int, int, int)
|            1184 |  |  * QBrush::QBrush(const QColor &, Qt::BrushStyle)
|            1971 |  |  * QBrush::~QBrush()
|           11718 |  |  * QColor::blueF()
|           11718 |  |  * QColor::greenF()
|           11718 |  |  * QColor::redF()
|            8524 |  |  * QColor::alphaF()
|            5702 |  |  * QColor::fromRgbF(qreal, qreal, qreal, qreal)
|             119 |  |  * QBrush::QBrush(const QBrush &)
|               3 |  |  * QGuiApplication::platformName()
|               1 |  |  * QGuiApplication::topLevelWindows()
|               2 |  |  * QGuiApplication::primaryScreen()
|               1 |  |  * QScreen::depth()
|               4 |  |  * QFont::QFont(const QString &, int, int, bool)
|               4 |  |  * QFont::setStyleHint(QFont::StyleHint, QFont::StyleStrategy)
|               4 |  |  * QFont::fromString(const QString &)
|              22 |  |  * QFont::QFont(const QFont &)
|               4 |  |  * QIcon::QIcon()
|              18 |  |  * QBrush::QBrush()
|               2 |  |  * QGuiApplication::platformNativeInterface()
|               4 |  |  * QGuiApplication::styleHints()
|               2 |  |  * QStyleHints::startDragDistance()
|               2 |  |  * QStyleHints::startDragTime()
|               9 |  |  * QBrush::QBrush(const QBrush &)
|              27 |  |  * QBrush::~QBrush()
|               9 |  |  * QBrush::operator=(const QBrush &)
|               4 |  |  * QGuiApplication::palette()
|              14 |  |  * QPalette::~QPalette()
|               1 |  |  * QGuiApplication::devicePixelRatio()
|               1 |  |  * QPixmap::QPixmap(int, int)
|              10 |  |  * QPixmap::setDevicePixelRatio(qreal)
|               1 |  |  * QColor::QColor(Qt::GlobalColor)
|               1 |  |  * QPixmap::fill(const QColor &)
|               1 |  |  * QRadialGradient::QRadialGradient(qreal, qreal, qreal)
|              11 |  |  * QColor::setAlpha(int)
|              11 |  |  * QGradient::setColorAt(qreal, const QColor &)
|               1 |  |  * QPainter::QPainter(QPaintDevice *)
|               1 |  |  * QPainter::setRenderHint(QPainter::RenderHint, bool)
|               1 |  |  * QBrush::QBrush(const QGradient &)
|               1 |  |  * QPixmap::rect()
|               1 |  |  * QPainter::fillRect(const QRect &, const QBrush &)
|               1 |  |  * QPainter::setPen(Qt::PenStyle)
|               1 |  |  * QBrush::QBrush(Qt::GlobalColor, Qt::BrushStyle)
|               1 |  |  * QPainter::setBrush(const QBrush &)
|               1 |  |  * QPainter::setCompositionMode(QPainter::CompositionMode)
|               1 |  |  * QPainter::drawRoundedRect(const QRectF &, qreal, qreal, Qt::SizeMode)
|               1 |  |  * QPainter::end()
|               1 |  |  * QPixmap::isNull()
|               1 |  |  * QPixmap::width()
|              11 |  |  * QPixmap::devicePixelRatio()
|               1 |  |  * QPixmap::height()
|               9 |  |  * QPixmap::copy(const QRect &)
|               9 |  |  * QPixmap::QPixmap(const QPixmap &)
|              10 |  |  * QPixmap::~QPixmap()
|               1 |  |  * QPainter::~QPainter()
|               1 |  |  * QPalette::resolve(const QPalette &)
|               2 |  |  * QPalette::operator=(const QPalette &)
|               2 |  |  * QPalette::QPalette(const QPalette &)
|               3 |  |  * QPalette::isCopyOf(const QPalette &)
|               1 |  |  * QAccessible::installFactory(InterfaceFactory)
|              17 |  |  * QRegion::QRegion()
|               3 |  |  * QFont::QFont()
|               1 |  |  * QGuiApplication::layoutDirection()
|               4 |  |  * QBrush::isOpaque()
|               3 |  |  * QFont::QFont(const QFont &, QPaintDevice *)
|               2 |  |  |  * QGuiApplication::primaryScreen()
|               3 |  |  |  * QScreen::logicalDotsPerInchY()
|               2 |  |  |  * QWindow::screen()
|              30 |  |  * QFont::~QFont()
|               1 |  |  * QImage::QImage()
|               3 |  |  * QSurfaceFormat::QSurfaceFormat()
|               4 |  |  * QCursor::QCursor(Qt::CursorShape)
|               3 |  |  * QWindow::setSurfaceType(QSurface::SurfaceType)
|               3 |  |  * QWindow::setFlags(Qt::WindowFlags)
|               3 |  |  * QWindow::resize(const QSize &)
|               5 |  |  * QWindow::isTopLevel()
|               7 |  |  * QGuiApplication::screens()
|               4 |  |  * QWindow::setScreen(QScreen *)
|               3 |  |  * QWindow::requestedFormat()
|               3 |  |  * QWindow::surfaceType()
|               3 |  |  * QWindow::setFormat(const QSurfaceFormat &)
|               3 |  |  * qt_window_private(QWindow *)
|               3 |  |  * QWindow::create()
|               3 |  |  |  * QWindow::screen()
|               3 |  |  |  * QScreen::handle()
|              10 |  |  |  * QWindow::type()
|               3 |  |  |  * QSurfaceFormat::QSurfaceFormat()
|               3 |  |  |  * QRegion::QRegion()
|               4 |  |  |  * QWindow::isTopLevel()
|               3 |  |  |  * QGuiApplication::desktopFileName()
|               2 |  |  |  * QSurface::supportsOpenGL()
|               1 |  |  |  * QWindow::requestedFormat()
|               2 |  |  |  * QSurfaceFormat::QSurfaceFormat(const QSurfaceFormat &)
|               3 |  |  |  * QSurfaceFormat::redBufferSize()
|               2 |  |  |  * QSurfaceFormat::setRedBufferSize(int)
|               3 |  |  |  * QSurfaceFormat::greenBufferSize()
|               2 |  |  |  * QSurfaceFormat::setGreenBufferSize(int)
|               3 |  |  |  * QSurfaceFormat::blueBufferSize()
|               2 |  |  |  * QSurfaceFormat::setBlueBufferSize(int)
|               1 |  |  |  * QSurfaceFormat::operator=(const QSurfaceFormat &)
|               3 |  |  |  * QSurfaceFormat::~QSurfaceFormat()
|               2 |  |  |  * QSurfaceFormat::alphaBufferSize()
|               1 |  |  |  * QSurfaceFormat::swapBehavior()
|               1 |  |  |  * QSurfaceFormat::testOption(QSurfaceFormat::FormatOption)
|               1 |  |  |  * QSurfaceFormat::depthBufferSize()
|               1 |  |  |  * QSurfaceFormat::stencilBufferSize()
|               1 |  |  |  * QSurfaceFormat::samples()
|               1 |  |  |  * QSurfaceFormat::setAlphaBufferSize(int)
|               1 |  |  |  * QSurfaceFormat::setDepthBufferSize(int)
|               1 |  |  |  * QSurfaceFormat::setStencilBufferSize(int)
|               1 |  |  |  * QSurfaceFormat::setStereo(bool)
|               5 |  |  |  * QWindow::flags()
|               2 |  |  |  * qt_window_private(QWindow *)
|               1 |  |  |  * QGuiApplication::sessionId()
|               1 |  |  |  * QWindow::windowState()
|               1 |  |  |  * QWindow::title()
|               1 |  |  |  * QWindow::icon()
|               1 |  |  |  * QIcon::isNull()
|               1 |  |  |  * QIcon::~QIcon()
|               3 |  |  * QWindow::flags()
|              13 |  |  * QWindow::handle()
|               3 |  |  * QWindow::setTitle(const QString &)
|               3 |  |  * QGuiApplication::platformFunction(const QByteArray &)
|               3 |  |  * QWindow::winId()
|               3 |  |  * QSurfaceFormat::~QSurfaceFormat()
|               3 |  |  * QWindow::setModality(Qt::WindowModality)
|               3 |  |  * QWindow::frameMargins()
|               3 |  |  * QScreen::geometry()
|               2 |  |  * QWindow::setVisible(bool)
|               1 |  |  |  * QWindow::qt_metacast(const char *)
|               2 |  |  |  * QWindow::handle()
|               2 |  |  |  * QCursor::shape()
|               1 |  |  |  * QWindow::isTopLevel()
|               3 |  |  |  * QWindow::windowState()
|               5 |  |  |  * QWindow::flags()
|               2 |  |  |  * qt_window_private(QWindow *)
|               7 |  |  |  * QWindow::type()
|               2 |  |  |  * QWindow::modality()
|               1 |  |  |  * QGuiApplication::modalWindow()
|               1 |  |  * QHideEvent::QHideEvent()
|               1 |  |  * QHideEvent::~QHideEvent()
|               2 |  |  * QRegion::operator+=(const QRect &)
|               1 |  |  * QRegion::boundingRect()
|              15 |  |  * QRegion::~QRegion()
|               2 |  |  * QScreen::virtualSiblings()
|               2 |  |  * QWindow::screen()
|               1 |  |  * QScreen::handle()
|               1 |  |  * QBackingStore::QBackingStore(QWindow *)
|               1 |  |  |  * QImage::QImage()
|               1 |  |  |  * QWindow::screen()
|               1 |  |  |  * QScreen::handle()
|               1 |  |  * QGuiApplication::windowIcon()
|               1 |  |  * QWindow::setIcon(const QIcon &)
|               1 |  |  |  * QIcon::isNull()
|               2 |  |  * QIcon::~QIcon()
|               2 |  |  * QGuiApplication::font()
|               1 |  |  * QFont::isCopyOf(const QFont &)
|               1 |  |  * QMoveEvent::QMoveEvent(const QPoint &, const QPoint &)
|               2 |  |  * QGuiApplication::focusObject()
|               1 |  |  * QMoveEvent::~QMoveEvent()
|               1 |  |  * QResizeEvent::QResizeEvent(const QSize &, const QSize &)
|               1 |  |  * QResizeEvent::~QResizeEvent()
|               1 |  |  * QShowEvent::QShowEvent()
|               1 |  |  * QRegion::QRegion(const QRect &, QRegion::RegionType)
|               1 |  |  * QRegion::QRegion(const QRegion &)
|               2 |  |  * QWindow::geometry()
|               1 |  |  * QWindow::setCursor(const QCursor &)
|               2 |  |  |  * QWindow::handle()
|               2 |  |  |  * QCursor::shape()
|               1 |  |  * QCursor::~QCursor()
|               1 |  |  * qt_region_strictContains(const QRegion &, const QRect &)
|               1 |  |  * QAccessible::updateAccessibility(QAccessibleEvent *)
|               1 |  |  |  * QAccessibleObject::QAccessibleObject(QObject *)
|               3 |  |  |  * QAccessibleObject::object()
|               1 |  |  |  * QAccessibleObject::isValid()
|               1 |  |  |  * QGuiApplication::platformNativeInterface()
|               1 |  |  * QAccessibleEvent::~QAccessibleEvent()
|               1 |  |  * QShowEvent::~QShowEvent()
|               1 |  |  * QGuiApplication::exec()
|              72 |  |  |  * QColor::setRgb(int, int, int, int)
|               1 |  |  |  * QIcon::themeName()
|               4 |  |  |  * QGuiApplication::font()
|               2 |  |  |  * QFont::isCopyOf(const QFont &)
|               4 |  |  |  * QFont::~QFont()
|               4 |  |  |  * QGuiApplication::palette()
|               2 |  |  |  * QPalette::isCopyOf(const QPalette &)
|               4 |  |  |  * QPalette::~QPalette()
|               8 |  |  |  * QRegion::QRegion(const QRect &, QRegion::RegionType)
|              63 |  |  |  * QRegion::~QRegion()
|               2 |  |  |  * QRegion::operator|=(const QRegion &)
|              18 |  |  |  * QRegion::QRegion()
|              11 |  |  |  * QWindow::parent()
|              14 |  |  |  * QWindow::handle()
|               1 |  |  |  * QRegion::operator&(const QRect &)
|               6 |  |  |  * qt_region_strictContains(const QRegion &, const QRect &)
|               1 |  |  |  * QAccessible::queryAccessibleInterface(QObject *)
|               1 |  |  |  * QWindow::windowState()
|               3 |  |  |  * QWindow::geometry()
|               2 |  |  |  * QWindow::frameMargins()
|               2 |  |  |  * QWindow::isExposed()
|               2 |  |  |  * QRegion::isNull()
|               8 |  |  |  * QRegion::operator+=(const QRegion &)
|               5 |  |  |  * QBackingStore::size()
|               1 |  |  |  * QRegion::QRegion(int, int, int, int, QRegion::RegionType)
|               1 |  |  |  * QBackingStore::resize(const QSize &)
|               1 |  |  |  |  * QWindow::screen()
|               1 |  |  |  |  * QScreen::handle()
|               1 |  |  |  |  * QWindow::handle()
|               1 |  |  |  |  * QImage::QImage()
|               2 |  |  |  |  * QRegion::QRegion()
|               2 |  |  |  |  * QImage::toPixelFormat(QImage::Format)
|               1 |  |  |  |  * QImage::QImage(uchar *, int, int, int, QImage::Format, QImageCleanupFunction, void *)
|               1 |  |  |  |  * QImage::format()
|               1 |  |  |  |  * QImage::size()
|              22 |  |  |  * QRegion::QRegion(const QRegion &)
|               4 |  |  |  * qt_window_private(QWindow *)
|               4 |  |  |  * QBackingStore::beginPaint(const QRegion &)
|               4 |  |  |  |  * QRegion::QRegion(const QRegion &)
|               4 |  |  |  |  * QRegion::~QRegion()
|               4 |  |  |  |  * QRegion::intersects(const QRegion &)
|               3 |  |  |  |  * QRegion::QRegion()
|               4 |  |  |  * QBackingStore::paintDevice()
|               7 |  |  |  * QRegion::operator&=(const QRect &)
|               4 |  |  |  * QPainter::QPainter(QPaintDevice *)
|               2 |  |  |  |  * QGuiApplication::focusWindow()
|               4 |  |  |  |  * QWindow::handle()
|               4 |  |  |  |  * QPen::QPen(const QBrush &, qreal, Qt::PenStyle, Qt::PenCapStyle, Qt::PenJoinStyle)
|               4 |  |  |  |  * QPen::~QPen()
|               4 |  |  |  |  * QBrush::operator=(const QBrush &)
|               4 |  |  |  |  * QFont::QFont(const QFont &, QPaintDevice *)
|               4 |  |  |  |  |  * QWindow::screen()
|               4 |  |  |  |  |  * QScreen::logicalDotsPerInchY()
|               8 |  |  |  |  * QFont::operator=(const QFont &)
|               4 |  |  |  |  * QFont::~QFont()
|               6 |  |  |  * QGuiApplication::focusWindow()
|               8 |  |  |  * QBrush::QBrush(const QBrush &)
|               4 |  |  |  * QPainter::compositionMode()
|               8 |  |  |  * QPainter::setCompositionMode(QPainter::CompositionMode)
|               4 |  |  |  * QBrush::gradient()
|               4 |  |  |  * QRegion::rects()
|               4 |  |  |  * QPainter::fillRect(const QRect &, const QBrush &)
|               8 |  |  |  * QBrush::~QBrush()
|               4 |  |  |  * QPainter::~QPainter()
|               4 |  |  |  * QRegion::translated(int, int)
|               9 |  |  |  * QTransform::QTransform()
|               8 |  |  |  * QTransform::scale(qreal, qreal)
|               8 |  |  |  * QTransform::map(const QRegion &)
|               4 |  |  |  * QPaintEvent::QPaintEvent(const QRegion &)
|               4 |  |  |  * QPaintEvent::~QPaintEvent()
|               4 |  |  |  * QBackingStore::endPaint()
|               4 |  |  |  |  * QRegion::QRegion(const QRegion &)
|               8 |  |  |  |  * QRegion::~QRegion()
|               4 |  |  |  |  * QRegion::intersects(const QRegion &)
|               4 |  |  |  |  * QWindow::handle()
|               5 |  |  |  * QBackingStore::flush(const QRegion &, QWindow *, const QPoint &)
|              10 |  |  |  |  * QImage::size()
|               5 |  |  |  |  * QRegion::QRegion(const QRegion &)
|               5 |  |  |  |  * QWindow::geometry()
|              10 |  |  |  |  * QRegion::operator&=(const QRect &)
|              10 |  |  |  |  * QRegion::boundingRect()
|               5 |  |  |  |  * QWindow::handle()
|               5 |  |  |  |  * QRegion::rects()
|               5 |  |  |  |  * QRegion::translated(int, int)
|               5 |  |  |  |  * QRegion::operator|=(const QRegion &)
|              15 |  |  |  |  * QRegion::~QRegion()
|               5 |  |  |  |  * QRegion::QRegion()
|               4 |  |  |  * QFocusEvent::reason()
|               4 |  |  |  * QAccessible::updateAccessibility(QAccessibleEvent *)
|              16 |  |  |  |  * QAccessibleObject::object()
|               8 |  |  |  |  * QAccessibleObject::isValid()
|               3 |  |  |  * QAccessibleStateChangeEvent::~QAccessibleStateChangeEvent()
|               2 |  |  |  * QWindow::isTopLevel()
|               4 |  |  |  * QPalette::isEqual(QPalette::ColorGroup, QPalette::ColorGroup)
|               4 |  |  |  * QRegion::operator=(const QRegion &)
|               2 |  |  |  * QGuiApplication::styleHints()
|               2 |  |  |  * QStyleHints::tabFocusBehavior()
|               1 |  |  |  * QGuiApplication::focusObject()
|               1 |  |  |  * QTransform::translate(qreal, qreal)
|               3 |  |  |  * QGuiApplication::inputMethod()
|               1 |  |  |  * QInputMethod::setInputItemTransform(const QTransform &)
|               1 |  |  |  * QInputMethod::setInputItemRectangle(const QRectF &)
|               1 |  |  |  * QInputMethod::update(Qt::InputMethodQueries)
|               3 |  |  |  * QRegion::boundingRect()
|               3 |  |  |  * QRegion::intersects(const QRect &)
|               1 |  |  |  * QKeyEvent::QKeyEvent(QEvent::Type, int, Qt::KeyboardModifiers, quint32, quint32, quint32, const QString &, bool, ushort)
|               1 |  |  |  * QKeyEvent::~QKeyEvent()
|               1 |  |  |  * QCloseEvent::QCloseEvent()
|               1 |  |  |  * QCloseEvent::~QCloseEvent()
|               1 |  |  |  * QRegion::operator+=(const QRect &)
|               1 |  |  |  * QWindow::setVisible(bool)
|               1 |  |  |  |  * QWindow::isModal()
|               1 |  |  |  * QHideEvent::QHideEvent()
|               1 |  |  |  * QAccessibleEvent::~QAccessibleEvent()
|               1 |  |  |  * QHideEvent::~QHideEvent()
|               3 |  |  * QWindow::focusObjectChanged(QObject *)
|               1 |  |  * QAccessibleActionInterface::~QAccessibleActionInterface()
|               1 |  |  * QBackingStore::~QBackingStore()
|               2 |  |  |  * QRegion::~QRegion()
|               3 |  |  * QWindow::destroy()
|               3 |  |  |  * QWindow::type()
|               2 |  |  |  * QWindow::parent()
|               3 |  |  |  * QRegion::~QRegion()
|               3 |  |  |  * QSurfaceFormat::~QSurfaceFormat()
|               3 |  |  * QWindow::~QWindow()
|               3 |  |  |  * QCursor::~QCursor()
|               3 |  |  |  * QRegion::~QRegion()
|               3 |  |  |  * QIcon::~QIcon()
|               3 |  |  |  * QSurfaceFormat::~QSurfaceFormat()
|               3 |  |  * QPaintDevice::~QPaintDevice()
|               1 |  |  * QPixmapCache::clear()
|               1 |  |  * QGuiApplication::~QGuiApplication()
|               1 |  |  |  * QGuiApplication::notify(QObject *, QEvent *)
|               4 |  |  |  * QFont::~QFont()
|               1 |  |  |  * QPalette::~QPalette()

-------------------------------------------------------------------------------
$ export SCOREP_ENABLE_UNWINDING=yes
$ sudo bash -c "echo 1 > /proc/sys/kernel/perf_event_paranoid"
$ export SCOREP_PROFILING_MAX_CALLPATH_DEPTH=50                 # needed here to avoid an error
$ export SCOREP_SAMPLING_EVENTS=perf_cycles@1000000             # 10x higher sampling rate than default

$ scorep g++ -fPIC -I/usr/include/x86_64-linux-gnu/qt5/ main.cc -lQt5Widgets -lQt5Gui -lQt5Core -o main_no_libwrap

$ ./main_no_libwrap && mv scorep-2* scorep-sampling      
$ cube_info -m visits:excl scorep-sampling/profile.cubex 
|      Visits (E) | Diff-Calltree
|             185 |  * main
|              88 |  |  * QApplicationPrivate.init()
|              62 |  |  |  * QGuiApplicationPrivate.init()
|              62 |  |  |  |  * QCoreApplicationPrivate.init()
|              57 |  |  |  |  |  * QGuiApplicationPrivate.createEventDispatcher()
|              57 |  |  |  |  |  |  * QGuiApplicationPrivate.createPlatformIntegration()
|              13 |  |  |  |  |  |  |  * QPlatformIntegrationFactory.create(QString const&, QStringList const&, int&, byte, QString const&)
|               2 |  |  |  |  |  |  |  |  * QFactoryLoader.QFactoryLoader(byte const, QString const&, Qt.CaseSensitivity)
|               2 |  |  |  |  |  |  |  |  |  * QFactoryLoader.update()
|               2 |  |  |  |  |  |  |  |  |  |  * QCoreApplication.libraryPaths()
|               2 |  |  |  |  |  |  |  |  |  |  |  * QCoreApplicationPrivate.appendApplicationPathToLibraryPaths()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * QDir.canonicalPath() const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * QFSFileEngine.drives()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDir.cleanPath(QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDir.match(QStringList const&, QString const&)
|               7 |  |  |  |  |  |  |  |  * QFactoryLoader.instance(int) const
|               7 |  |  |  |  |  |  |  |  |  * QUuid.QUuid(byte const)
|               7 |  |  |  |  |  |  |  |  |  |  * qt_linux_find_symbol_sys(byte const)
|               7 |  |  |  |  |  |  |  |  |  |  |  * dlopen
|               7 |  |  |  |  |  |  |  |  |  |  |  |  * dlerror
|               7 |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               7 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bb84b2e90,0x7f8bb84b2f45)
|               7 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               7 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               7 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bbd273a00,0x7f8bbd274699)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_debug_state
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_debug_state
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_debug_state
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               4 |  |  |  |  |  |  |  |  * _init
|               4 |  |  |  |  |  |  |  |  |  * QXcbIntegration.QXcbIntegration(QStringList const&, int&, byte)
|               4 |  |  |  |  |  |  |  |  |  |  * QXcbConnection.QXcbConnection(QXcbNativeInterface, boolean, unsigned, byte const)
|               2 |  |  |  |  |  |  |  |  |  |  |  * QXcbConnection.initializeScreens()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * QXcbScreen.QXcbScreen(QXcbConnection, QXcbVirtualDesktop, unsigned, xcb_randr_get_output_info_reply_t, xcb_xinerama_screen_info_t const, int)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbNativeInterface.addHandler(QXcbNativeInterfaceHandler)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QLibrary.load()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qt_linux_find_symbol_sys(byte const)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * dlopen
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * dlerror
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bb84b2e90,0x7f8bb84b2f45)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  * QXcbConnection.xi2HandleEvent(xcb_ge_event_t)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * QXcbConnection.xi2HandleEvent(xcb_ge_event_t)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * QFactoryLoader.instance(int) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QUuid.QUuid(byte const)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qt_linux_find_symbol_sys(byte const)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * dlopen
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * dlerror
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bb84b2e90,0x7f8bb84b2f45)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bbd273a00,0x7f8bbd274699)
|              44 |  |  |  |  |  |  |  * QPlatformTheme.keyBindings(QKeySequence.StandardKey) const
|              32 |  |  |  |  |  |  |  |  * QFactoryLoader.instance(int) const
|              32 |  |  |  |  |  |  |  |  |  * QUuid.QUuid(byte const)
|              32 |  |  |  |  |  |  |  |  |  |  * qt_linux_find_symbol_sys(byte const)
|              32 |  |  |  |  |  |  |  |  |  |  |  * dlopen
|              32 |  |  |  |  |  |  |  |  |  |  |  |  * dlerror
|              32 |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|              32 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bb84b2e90,0x7f8bb84b2f45)
|              32 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|              32 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|              32 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bbd273a00,0x7f8bbd274699)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|              17 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bbd273a00,0x7f8bbd274699)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bbd271360,0x7f8bbd272900)
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qAddPreRoutine(void ()())
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * Sonnet.SpellCheckDecorator.eventFilter(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * Sonnet.SpellCheckDecorator.eventFilter(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QStandardPaths.locate(QStandardPaths.StandardLocation, QString const&, QFlags<QStandardPaths.LocateOption>)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QStandardPaths.standardLocations(QStandardPaths.StandardLocation)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QProcessEnvironment.systemEnvironment()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QtPrivate.QStringList_removeDuplicates(QStringList)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qHash(QString const&, unsigned)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KShell.splitArgs(QString const&, QFlags<KShell.Option>, KShell.Errors)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KShell.splitArgs(QString const&, QFlags<KShell.Option>, KShell.Errors)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QStandardPaths.locate(QStandardPaths.StandardLocation, QString const&, QFlags<QStandardPaths.LocateOption>)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QFileInfo.~QFileInfo()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_debug_state
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_debug_state
|              12 |  |  |  |  |  |  |  |  * qt_plugin_instance
|              12 |  |  |  |  |  |  |  |  |  * _init
|              12 |  |  |  |  |  |  |  |  |  |  * _init
|               6 |  |  |  |  |  |  |  |  |  |  |  * KIconEngine.~KIconEngine()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.openConfig(QString const&, QFlags<KConfig.OpenFlag>, QStandardPaths.StandardLocation)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.KSharedConfig(QString const&, QFlags<KConfig.OpenFlag>, QStandardPaths.StandardLocation)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.reparseConfiguration()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.isConfigWritable(boolean)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.checkUpdate(QString const&, QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qstrcmp(QByteArray const&, QByteArray const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __nss_passwd_lookup
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.isConfigWritable(boolean)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QFileInfo.absolutePath() const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QFileSystemWatcher.qt_metacall(QMetaObject.Call, int, void)
|               5 |  |  |  |  |  |  |  |  |  |  |  |  * KIconEngine.~KIconEngine()
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  * KColorScheme.createApplicationPalette(QExplicitlySharedDataPointer<KSharedConfig> const&)
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KColorScheme.KColorScheme(QPalette.ColorGroup, KColorScheme.ColorSet, QExplicitlySharedDataPointer<KSharedConfig>)
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KColorScheme.shade(QColor const&, KColorScheme.ShadeRole)
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KStatefulBrush.KStatefulBrush(QBrush const&, QBrush const&, QExplicitlySharedDataPointer<KSharedConfig>)
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KColorUtils.tint(QColor const&, QColor const&, double)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * pow
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __log10_finite
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __cosh_finite
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KColorUtils.mix(QColor const&, QColor const&, double)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QColor.fromRgbF(double, double, double, double)
|               3 |  |  |  |  |  * QGuiApplicationPrivate.eventDispatcherReady()
|               3 |  |  |  |  |  |  * QXcbIntegration.initialize()
|               3 |  |  |  |  |  |  |  * QPlatformInputContextFactory.create(QString const&)
|               2 |  |  |  |  |  |  |  |  * QFactoryLoader.QFactoryLoader(byte const, QString const&, Qt.CaseSensitivity)
|               2 |  |  |  |  |  |  |  |  |  * QFactoryLoader.update()
|               2 |  |  |  |  |  |  |  |  |  |  * QDir.exists(QString const&) const
|               2 |  |  |  |  |  |  |  |  |  |  |  * QFileInfo.exists(QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * QFSFileEngine.drives()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * QFileSystemWatcher.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.toLocal8Bit_helper(QChar const, int)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QTextCodec.availableCodecs()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QTextCodec.availableCodecs()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QByteArray.QByteArray(int, Qt.Initialization)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QArrayData.allocate(unsigned long, unsigned long, unsigned long, QFlags<QArrayData.AllocationOption>)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __libc_malloc
|               1 |  |  |  |  |  |  |  |  * QFactoryLoader.instance(int) const
|               1 |  |  |  |  |  |  |  |  |  * QUuid.QUuid(byte const)
|               1 |  |  |  |  |  |  |  |  |  |  * qt_linux_find_symbol_sys(byte const)
|               1 |  |  |  |  |  |  |  |  |  |  |  * dlopen
|               1 |  |  |  |  |  |  |  |  |  |  |  |  * dlerror
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bb84b2e90,0x7f8bb84b2f45)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  * KLocalizedContext.xi18ndcp(QString const&, QString const&, QString const&, QString const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&) const
|               2 |  |  |  |  |  |  * KLocalizedContext.xi18ndcp(QString const&, QString const&, QString const&, QString const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&, QVariant const&) const
|               2 |  |  |  |  |  |  |  * QTranslator.load(QLocale const&, QString const&, QString const&, QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  * QTimer.singleShot(int, QObject const, byte const)
|               2 |  |  |  |  |  |  |  |  |  * QFileInfo.isFile() const
|               2 |  |  |  |  |  |  |  |  |  |  * QFSFileEngine.drives()
|               2 |  |  |  |  |  |  |  |  |  |  |  * QFileSystemWatcher.qt_metacall(QMetaObject.Call, int, void)
|              26 |  |  |  * QApplicationPrivate.initialize()
|              26 |  |  |  |  * QApplication.style()
|               2 |  |  |  |  |  * QApplicationPrivate.desktopStyleKey()
|               2 |  |  |  |  |  |  * QStyleFactory.keys()
|              18 |  |  |  |  |  * QStyleFactory.create(QString const&)
|               8 |  |  |  |  |  |  * QFactoryLoader.instance(int) const
|               8 |  |  |  |  |  |  |  * QUuid.QUuid(byte const)
|               8 |  |  |  |  |  |  |  |  * qt_linux_find_symbol_sys(byte const)
|               8 |  |  |  |  |  |  |  |  |  * dlopen
|               8 |  |  |  |  |  |  |  |  |  |  * dlerror
|               8 |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               8 |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bb84b2e90,0x7f8bb84b2f45)
|               8 |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               8 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               8 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bbd273a00,0x7f8bbd274699)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bbd273a00,0x7f8bbd274699)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|              10 |  |  |  |  |  |  * KConfigGroup.readEntry<boolean>(byte const, boolean const&) constboolean
|              10 |  |  |  |  |  |  |  * KConfigGroup.readEntry<QColor>(byte const, QColor const&) constQColor
|               4 |  |  |  |  |  |  |  |  * KConfigGroup.readEntry<boolean>(byte const, boolean const&) constboolean
|               2 |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry<boolean>(byte const, boolean const&) constboolean
|               2 |  |  |  |  |  |  |  |  |  |  * KConfigSkeleton.KConfigSkeleton(QString const&, QObject)
|               2 |  |  |  |  |  |  |  |  |  |  |  * KCoreConfigSkeleton.KCoreConfigSkeleton(QString const&, QObject)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.openConfig(QString const&, QFlags<KConfig.OpenFlag>, QStandardPaths.StandardLocation)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.KSharedConfig(QString const&, QFlags<KConfig.OpenFlag>, QStandardPaths.StandardLocation)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.reparseConfiguration()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.isConfigWritable(boolean)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QHashData.allocateNode(int)
|               2 |  |  |  |  |  |  |  |  |  * KCoreConfigSkeleton.read()
|               2 |  |  |  |  |  |  |  |  |  |  * KCoreConfigSkeleton.ItemStringList.readConfig(KConfig)
|               2 |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.KConfigGroup(KConfigBase, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.isGroupImmutable(QString const&) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.isGroupImmutableImpl(QByteArray const&) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               6 |  |  |  |  |  |  |  |  * KConfigGroup.readEntry<QColor>(byte const, QColor const&) constQColor
|               6 |  |  |  |  |  |  |  |  |  * _init
|               3 |  |  |  |  |  |  |  |  |  |  * KStatefulBrush.KStatefulBrush(KColorScheme.ColorSet, KColorScheme.DecorationRole, QExplicitlySharedDataPointer<KSharedConfig>)
|               3 |  |  |  |  |  |  |  |  |  |  |  * KColorScheme.KColorScheme(QPalette.ColorGroup, KColorScheme.ColorSet, QExplicitlySharedDataPointer<KSharedConfig>)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  * KColorScheme.shade(QColor const&, KColorScheme.ShadeRole)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  * KStatefulBrush.KStatefulBrush(QBrush const&, QBrush const&, QExplicitlySharedDataPointer<KSharedConfig>)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KColorUtils.tint(QColor const&, QColor const&, double)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KColorUtils.mix(QColor const&, QColor const&, double)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QColor.greenF() const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * pow
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __log10_finite
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QColor.fromRgbF(double, double, double, double)
|               3 |  |  |  |  |  |  |  |  |  |  * KStatefulBrush.KStatefulBrush(KColorScheme.ColorSet, KColorScheme.ForegroundRole, QExplicitlySharedDataPointer<KSharedConfig>)
|               3 |  |  |  |  |  |  |  |  |  |  |  * KColorScheme.KColorScheme(QPalette.ColorGroup, KColorScheme.ColorSet, QExplicitlySharedDataPointer<KSharedConfig>)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  * KColorScheme.shade(QColor const&, KColorScheme.ShadeRole)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  * KStatefulBrush.KStatefulBrush(QBrush const&, QBrush const&, QExplicitlySharedDataPointer<KSharedConfig>)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry<QColor>(byte const, QColor const&) constQColor
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(byte const, QVariant const&) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.forceGlobal() const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QByteArray.QByteArray(byte const, int)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QArrayData.allocate(unsigned long, unsigned long, unsigned long, QFlags<QArrayData.AllocationOption>)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __libc_malloc
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _IO_str_seekoff
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KColorUtils.tint(QColor const&, QColor const&, double)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * pow
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __log10_finite
|               6 |  |  |  |  |  * QApplicationPrivate.setSystemPalette(QPalette const&)
|               6 |  |  |  |  |  |  * KStyle.standardPalette() const
|               6 |  |  |  |  |  |  |  * KColorScheme.createApplicationPalette(QExplicitlySharedDataPointer<KSharedConfig> const&)
|               6 |  |  |  |  |  |  |  |  * KColorScheme.KColorScheme(QPalette.ColorGroup, KColorScheme.ColorSet, QExplicitlySharedDataPointer<KSharedConfig>)
|               6 |  |  |  |  |  |  |  |  |  * KColorScheme.shade(QColor const&, KColorScheme.ShadeRole)
|               5 |  |  |  |  |  |  |  |  |  |  * KStatefulBrush.KStatefulBrush(QBrush const&, QBrush const&, QExplicitlySharedDataPointer<KSharedConfig>)
|               3 |  |  |  |  |  |  |  |  |  |  |  * KColorUtils.tint(QColor const&, QColor const&, double)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  * pow
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __log10_finite
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __cosh_finite
|               1 |  |  |  |  |  |  |  |  |  |  |  |  * pow
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  * __log10_finite
|               1 |  |  |  |  |  |  |  |  |  |  |  * QBrush.~QBrush()
|               1 |  |  |  |  |  |  |  |  |  |  |  * KColorScheme.~KColorScheme()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  * KColorScheme.~KColorScheme()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  * KColorUtils.darken(QColor const&, double, double)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * pow
|               1 |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry<QColor>(byte const, QColor const&) constQColor
|               1 |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(byte const, QVariant const&) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.forceGlobal() const
|              28 |  |  * QWidget.setVisible(boolean)
|              24 |  |  |  * QWidget.create(unsigned long long, boolean, boolean)
|              22 |  |  |  |  * QWidgetPrivate.create_sys(unsigned long long, boolean, boolean)
|               2 |  |  |  |  |  * QApplication.desktop()
|               2 |  |  |  |  |  |  * QDesktopWidget.QDesktopWidget()
|               2 |  |  |  |  |  |  |  * QWidgetPrivate.init(QWidget, QFlags<Qt.WindowType>)
|               2 |  |  |  |  |  |  |  |  * QWidget.create(unsigned long long, boolean, boolean)
|               2 |  |  |  |  |  |  |  |  |  * QWidgetPrivate.create_sys(unsigned long long, boolean, boolean)
|               2 |  |  |  |  |  |  |  |  |  |  * QWindowPrivate.create(boolean)
|               2 |  |  |  |  |  |  |  |  |  |  |  * QXcbIntegration.createPlatformWindow(QWindow) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * QXcbWindow.create()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * QWindow.type() const
|              20 |  |  |  |  |  * QWindowPrivate.create(boolean)
|              20 |  |  |  |  |  |  * QXcbIntegration.createPlatformWindow(QWindow) const
|              20 |  |  |  |  |  |  |  * QXcbWindow.create()
|              15 |  |  |  |  |  |  |  |  * qt_plugin_instance
|              15 |  |  |  |  |  |  |  |  |  * qt_plugin_instance
|              15 |  |  |  |  |  |  |  |  |  |  * qt_plugin_instance
|              15 |  |  |  |  |  |  |  |  |  |  |  * glXChooseFBConfig
|              15 |  |  |  |  |  |  |  |  |  |  |  |  * glXGetFBConfigs
|              15 |  |  |  |  |  |  |  |  |  |  |  |  |  * glXMakeCurrent
|              15 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * glXGetDriverConfig
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * glXGetDriverConfig
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * glXGetDriverConfig
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * XML_ParseBuffer
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __libc_malloc
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _IO_str_seekoff
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * glAreTexturesResidentEXT
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * dlopen
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * dlerror
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bb84b2e90,0x7f8bb84b2f45)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bbd273a00,0x7f8bbd274699)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_debug_state
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|              10 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               9 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __driDriverGetExtensions_i915
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * XML_ParseBuffer
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               8 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __driDriverGetExtensions_i965
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __driDriverGetExtensions_i965
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __driDriverGetExtensions_i965
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __libc_malloc
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * XML_ParseBuffer
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               5 |  |  |  |  |  |  |  |  * QXcbWindow.setWindowTitle(QString const&)
|               5 |  |  |  |  |  |  |  |  |  * XmbTextListToTextProperty
|               5 |  |  |  |  |  |  |  |  |  |  * _XlcCurrentLC
|               5 |  |  |  |  |  |  |  |  |  |  |  * _XOpenLC
|               5 |  |  |  |  |  |  |  |  |  |  |  |  * _XlcUtf8Loader
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  * _XlcCreateLC
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XlcDbg_printValue
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XlcCreateLC
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XlcResolveLocaleName
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XlcCreateLocaleDataBase
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * fgets
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _IO_getline_info
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * memchr
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XlcCreateLocaleDataBase
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XlcResetConverter
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XlcDbg_printValue
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XlcGetLocaleDataBase
|               2 |  |  |  |  * QWidgetPrivate.setWindowIcon_sys()
|               2 |  |  |  |  |  * QWindow.setIcon(QIcon const&)
|               2 |  |  |  |  |  |  * QCoreApplication.notifyInternal2(QObject, QEvent)
|               2 |  |  |  |  |  |  |  * QApplication.notify(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  * QApplicationPrivate.notify_helper(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  * QCoreApplicationPrivate.sendThroughApplicationEventFilters(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  * KActionCollection.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  * QMetaObject.cast(QObject const) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * QDesktopWidget.qt_metacall(QMetaObject.Call, int, void)
|               4 |  |  |  * QWidgetPrivate.show_helper()
|               2 |  |  |  |  * QWidgetPrivate.show_sys()
|               2 |  |  |  |  |  * QWidgetPrivate.naturalWidgetFont(unsigned) const
|               2 |  |  |  |  |  |  * QWindowPrivate.setCursor(QCursor const)
|               2 |  |  |  |  |  |  |  * QXcbNativeInterface.addHandler(QXcbNativeInterfaceHandler)
|               2 |  |  |  |  |  |  |  |  * QXcbNativeInterface.addHandler(QXcbNativeInterfaceHandler)
|               2 |  |  |  |  |  |  |  |  |  * XcursorLibraryLoadCursor
|               2 |  |  |  |  |  |  |  |  |  |  * XcursorGetDefaultSize
|               2 |  |  |  |  |  |  |  |  |  |  |  * _XcursorGetDisplayInfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * XGetDefault
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * XAllocNamedColor
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * XrmGetStringDatabase
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XGetRequest
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _XrmInternalStringToQuark
|               2 |  |  |  |  * QAccessible.updateAccessibility(QAccessibleEvent)
|               2 |  |  |  |  |  * QAccessible.isActive()
|               2 |  |  |  |  |  |  * QXcbIntegration.accessibility() const
|               2 |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  * QDBusAbstractInterface.QDBusAbstractInterface(QString const&, QString const&, byte const, QDBusConnection const&, QObject)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * QDBusAbstractInterface.disconnectNotify(QMetaMethod const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * QDBusUtil.isValidBusName(QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.splitRef(QChar, QString.SplitBehavior, Qt.CaseSensitivity) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.splitRef(QRegularExpression const&, QString.SplitBehavior) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.multiArg(int, QString const) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.multiArg(int, QString const) const
|              63 |  |  * QCoreApplication.exec()
|              63 |  |  |  * QEventLoop.exec(QFlags<QEventLoop.ProcessEventsFlag>)
|              63 |  |  |  |  * QEventDispatcherGlib.processEvents(QFlags<QEventLoop.ProcessEventsFlag>)
|              63 |  |  |  |  |  * g_main_context_iteration
|              63 |  |  |  |  |  |  * g_main_context_dispatch
|              59 |  |  |  |  |  |  |  * g_main_context_dispatch
|              46 |  |  |  |  |  |  |  |  * QEventDispatcherGlibPrivate.runTimersOnceWithNormalPriority()
|              46 |  |  |  |  |  |  |  |  |  * QCoreApplicationPrivate.sendPostedEvents(QObject, int, QThreadData)
|              46 |  |  |  |  |  |  |  |  |  |  * QCoreApplication.notifyInternal2(QObject, QEvent)
|              46 |  |  |  |  |  |  |  |  |  |  |  * QApplication.notify(QObject, QEvent)
|              46 |  |  |  |  |  |  |  |  |  |  |  |  * QApplicationPrivate.notify_helper(QObject, QEvent)
|              44 |  |  |  |  |  |  |  |  |  |  |  |  |  * QObject.event(QEvent)
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbConnection.processXcbEvents()
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbConnection.handleXcbEvent(xcb_generic_event_t)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qt_plugin_instance
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * XLockDisplay
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * XUnlockDisplay
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * pthread_mutex_lock
|              38 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconEngine.~KIconEngine()
|              37 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconLoader.global()
|              37 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconLoader.KIconLoader(QString const&, QStringList const&, QObject)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconEffect.init()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry<QColor>(byte const, QColor const&) constQColor
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(byte const, QVariant const&) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGui.sessionConfigName()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * cfree
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _IO_str_seekoff
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconLoader.loadAnimated(QString const&, KIconLoader.Group, int) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconLoader.qt_metacall(QMetaObject.Call, int, void)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QElapsedTimer.hasExpired(long) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QHashData.rehash(int)
|              33 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconLoader.~KIconLoader()
|              33 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconLoader.queryIconsByDir(QString const&) const
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconTheme.KIconTheme(QString const&, QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.openConfig(QString const&, QFlags<KConfig.OpenFlag>, QStandardPaths.StandardLocation)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.KSharedConfig(QString const&, QFlags<KConfig.OpenFlag>, QStandardPaths.StandardLocation)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.reparseConfiguration()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.isConfigWritable(boolean)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.checkUpdate(QString const&, QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qstrcmp(QByteArray const&, QByteArray const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __nss_passwd_lookup
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconTheme.querySizes(KIconLoader.Group) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry<int>(byte const, int const&) constint
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(byte const, QVariant const&) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.forceGlobal() const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * cfree
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _IO_str_seekoff
|              30 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconLoader.queryIconsByDir(QString const&) const
|              30 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconLoader.queryIconsByDir(QString const&) const
|              30 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconTheme.KIconTheme(QString const&, QString const&, QString const&)
|               7 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.openConfig(QString const&, QFlags<KConfig.OpenFlag>, QStandardPaths.StandardLocation)
|               7 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.KSharedConfig(QString const&, QFlags<KConfig.OpenFlag>, QStandardPaths.StandardLocation)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.KConfig(QString const&, QFlags<KConfig.OpenFlag>, QStandardPaths.StandardLocation)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.mainConfigName()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QFileInfo.size() const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QResource.data() const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QResource.data() const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qUncompress(unsigned char const, int)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * uncompress
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * uncompress2
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * inflate
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * inflateBackEnd
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.reparseConfiguration()
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.isConfigWritable(boolean)
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.checkUpdate(QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qstrcmp(QByteArray const&, QByteArray const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBackend.create(QString const&, QString const&)
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KIconTheme.querySizes(KIconLoader.Group) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(QString const&, QString const&) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(byte const, QString const&) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.forceGlobal() const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.checkUpdate(QString const&, QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(QString const&, byte const) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(byte const, byte const) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(byte const, QString const&) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.forceGlobal() const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.checkUpdate(QString const&, QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qstrcmp(QByteArray const&, QByteArray const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __nss_passwd_lookup
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry<int>(byte const, int const&) constint
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry(byte const, QVariant const&) const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.forceGlobal() const
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigBase.KConfigBase()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.checkUpdate(QString const&, QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qstrcmp(QByteArray const&, QByteArray const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.toUtf8_helper(QString const&)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QTextCodec.availableCodecs()
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QByteArray.resize(int)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QByteArray.reallocData(unsigned, QFlags<QArrayData.AllocationOption>)
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               5 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDir.exists() const
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QFSFileEngine.drives()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QFileSystemWatcher.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.toLocal8Bit_helper(QChar const, int)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QTextCodec.availableCodecs()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QTextCodec.availableCodecs()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QByteArray.resize(int)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QByteArray.reallocData(unsigned, QFlags<QArrayData.AllocationOption>)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qCalculateGrowingBlockSize(unsigned long, unsigned long, unsigned long)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QResource.isDir() const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QResource.isValid() const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QResource.~QResource()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QResource.~QResource()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QResource.searchPaths()
|               9 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDir.QDir(QString const&)
|               6 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDir.operator==(QDir const&) const
|               6 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDir.rename(QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.resize(int)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.reallocData(unsigned, boolean)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QFileSystemWatcher.qt_metacall(QMetaObject.Call, int, void)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QFileSystemWatcher.qt_metacall(QMetaObject.Call, int, void)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * operator new(unsigned long)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __libc_malloc
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _IO_str_seekoff
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * operator new(unsigned long)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __libc_malloc
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _IO_str_seekoff
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDir.~QDir()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QTemporaryFile.createNativeFile(QFile&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QResource.registerResource(QString const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * cfree
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _IO_str_seekoff
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * cfree
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _IO_str_seekoff
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.KConfigGroup(QExplicitlySharedDataPointer<KSharedConfig> const&, QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QString.toUtf8_helper(QString const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QTextCodec.availableCodecs()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QByteArray.resize(int)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QByteArray.reallocData(unsigned, QFlags<QArrayData.AllocationOption>)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * realloc
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * qDBusAddSpyHook(void ()(QDBusMessage const&))
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QMetaObject.activate(QObject, int, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDBusAbstractAdaptor.QDBusAbstractAdaptor(QObject)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QMetaObject.invokeMethod(QObject, byte const, Qt.ConnectionType, QGenericReturnArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument, QGenericArgument)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QMetaObject.indexOfMethod(byte const) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidget.event(QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.syncBackingStore()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.repaint_sys(QRegion const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.repaint_sys(QRegion const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.drawWidget(QPaintDevice, QRegion const&, QPoint const&, int, QPainter, QWidgetBackingStore)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.paintBackground(QPainter, QRegion const&, int) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QPainter.fillRect(QRect const&, QBrush const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QRasterPaintEngine.fillRect(QRectF const&, QSpanData)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QRasterPaintEngine.rasterBuffer()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QStandardItemModel.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  * QEventDispatcherGlib.registerSocketNotifier(QSocketNotifier)
|               2 |  |  |  |  |  |  |  |  |  * QCoreApplication.notifyInternal2(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  * QApplication.notify(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  * QApplicationPrivate.notify_helper(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * QSocketNotifier.event(QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * QSocketNotifier.activated(int, QSocketNotifier.QPrivateSignal)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QMetaObject.activate(QObject, int, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * IceProcessMessages
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _SmcProcessMessage
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbConnection.xi2HandleEvent(xcb_ge_event_t)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QXcbConnection.xi2HandleEvent(xcb_ge_event_t)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * getpwuid_r
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __nss_lookup
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __nss_lookup_function
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __gai_sigqueue
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __libc_dlopen_mode
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_mcount_wrapper_check
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_find_dso_for_object
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * UNKNOWN@[0x7f8bbd273a00,0x7f8bbd274699)
|               9 |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               9 |  |  |  |  |  |  |  |  |  * QWindowSystemInterface.sendWindowSystemEvents(QFlags<QEventLoop.ProcessEventsFlag>)
|               9 |  |  |  |  |  |  |  |  |  |  * QGuiApplicationPrivate.processWindowSystemEvent(QWindowSystemInterfacePrivate.WindowSystemEvent)
|               7 |  |  |  |  |  |  |  |  |  |  |  * QGuiApplicationPrivate.processExposeEvent(QWindowSystemInterfacePrivate.ExposeEvent)
|               7 |  |  |  |  |  |  |  |  |  |  |  |  * QCoreApplication.notifyInternal2(QObject, QEvent)
|               7 |  |  |  |  |  |  |  |  |  |  |  |  |  * QApplication.notify(QObject, QEvent)
|               7 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QApplicationPrivate.notify_helper(QObject, QEvent)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QCoreApplicationPrivate.sendThroughApplicationEventFilters(QObject, QEvent)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfigGroup.readEntry<QColor>(byte const, QColor const&) constQColor
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDesktopWidget.qt_metacall(QMetaObject.Call, int, void)
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDesktopWidget.qt_metacall(QMetaObject.Call, int, void)
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.repaint_sys(QRegion const&)
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.repaint_sys(QRegion const&)
|               4 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.drawWidget(QPaintDevice, QRegion const&, QPoint const&, int, QPainter, QWidgetBackingStore)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.paintBackground(QPainter, QRegion const&, int) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QPainter.fillRect(QRect const&, QBrush const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QRasterPaintEngine.fillRect(QRectF const&, QSpanData)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QRasterPaintEngine.rasterBuffer()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QStandardItemModel.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidgetPrivate.setSystemClip(QPaintDevice, QRegion const&)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QTransform.scale(double, double)
|               2 |  |  |  |  |  |  |  |  |  |  |  * QGuiApplicationPrivate.processMouseEvent(QWindowSystemInterfacePrivate.MouseEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * QCoreApplication.notifyInternal2(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * QApplication.notify(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QApplicationPrivate.notify_helper(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDesktopWidget.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QDesktopWidget.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QApplicationPrivate.sendMouseEvent(QWidget, QMouseEvent, QWidget, QWidget, QWidget, QPointer<QWidget>&, boolean)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QCoreApplication.notifyInternal2(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QApplication.notify(QObject, QEvent)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWidget.mapFromGlobal(QPoint const&) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QWindow.mapFromGlobal(QPoint const&) const
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * non-virtual thunk to QXcbWindow.isEmbedded(QPlatformWindow const) const
|               1 |  |  |  |  |  |  |  |  * g_list_sort_with_data
|               1 |  |  |  |  |  |  |  |  |  * g_private_get
|               1 |  |  |  |  |  |  |  |  * g_ptr_array_set_size
|               4 |  |  |  |  |  |  |  * g_main_context_check
|               2 |  |  |  |  |  |  |  |  * QXcbGlIntegrationPlugin.qt_metacall(QMetaObject.Call, int, void)
|               2 |  |  |  |  |  |  |  |  |  * QWindowSystemInterfacePrivate.windowSystemEventsQueued()
|               2 |  |  |  |  |  |  |  |  * QTimerInfoList.activateTimers()
|               2 |  |  |  |  |  |  |  |  |  * QTimerInfoList.updateCurrentTime()
|               2 |  |  |  |  |  |  |  |  |  |  * QElapsedTimer.isMonotonic()
|               6 |  |  * QApplication.~QApplication()
|               2 |  |  |  * QGuiApplication.~QGuiApplication()
|               2 |  |  |  |  * QFontDatabase.removeAllApplicationFonts()
|               2 |  |  |  |  |  * __cxa_guard_acquire
|               4 |  |  |  * QCoreApplication.~QCoreApplication()
|               4 |  |  |  |  * QObject.~QObject()
|               4 |  |  |  |  |  * QApplicationPrivate.~QApplicationPrivate()
|               4 |  |  |  |  |  |  * QGuiApplicationPrivate.~QGuiApplicationPrivate()
|               2 |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  * KIconEngine.~KIconEngine()
|               2 |  |  |  |  |  |  |  |  |  |  * KIconEngine.~KIconEngine()
|               2 |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.~KSharedConfig()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * KSharedConfig.~KSharedConfig()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.~KConfig()
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QMapDataBase.freeTree(QMapNodeBase, int)
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * QMapDataBase.freeTree(QMapNodeBase, int)
|               2 |  |  |  |  |  |  |  * QXcbIntegration.~QXcbIntegration()
|               2 |  |  |  |  |  |  |  |  * QXcbIntegration.~QXcbIntegration()
|               2 |  |  |  |  |  |  |  |  |  * QXcbConnection.~QXcbConnection()
|               2 |  |  |  |  |  |  |  |  |  |  * QXcbConnection.~QXcbConnection()
|               2 |  |  |  |  |  |  |  |  |  |  |  * XCloseDisplay
|               2 |  |  |  |  |  |  |  |  |  |  |  |  * glXMakeCurrent
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  * glXMakeCurrent
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  * glXMakeCurrent
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * glXGetDriverConfig
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * __driDriverGetExtensions_i915
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               2 |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  * _init
|               1 |  * UNKNOWN@[0x696e752d3131582e,0x696e752d3131582f)
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  * UNKNOWN@[0xff00,0xff01)
|               1 |  |  * _init
|               4 |  * _dl_find_dso_for_object
|               4 |  |  * _dl_rtld_di_serinfo
|               4 |  |  |  * _dl_rtld_di_serinfo
|               4 |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  * UNKNOWN@[0x7ffc16411cff,0x7ffc16411d00)
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  * _dl_debug_state
|               1 |  |  |  |  |  |  |  * realloc
|               1 |  * _init
|               1 |  * UNKNOWN@[0x7f8bbca0a410,0x7f8bbca0a411)
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  * _fini
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               1 |  * UNKNOWN@[0x55f8c15852e0,0x55f8c15852e1)
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               1 |  * UNKNOWN@[0x7ffc16411fd0,0x7ffc16411fd1)
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               3 |  * UNKNOWN@[0x296d0700abf9d700,0x296d0700abf9d701)
|               3 |  |  * _dl_find_dso_for_object
|               3 |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  * UNKNOWN@[0x1df0000027f,0x1df00000280)
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  |  * realloc
|               1 |  * UNKNOWN@[0x1,0x2)
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  * UNKNOWN@[0x7f8b06200004,0x7f8b06200005)
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               1 |  * UNKNOWN@[0x143,0x144)
|               1 |  |  * _dl_find_dso_for_object
|               1 |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  * UNKNOWN@[0x7ffc16412210,0x7ffc16412211)
|               2 |  |  * _dl_find_dso_for_object
|               2 |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  * UNKNOWN@[0x7ffc16411940,0x7ffc16411941)
|               2 |  |  * _dl_find_dso_for_object
|               2 |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  |  |  |  |  * _dl_rtld_di_serinfo
|               2 |  * UNKNOWN@[0x7ffc16411860,0x7ffc16411861)
|               2 |  |  * _dl_find_dso_for_object
|               2 |  |  |  * _dl_rtld_di_serinfo
|               1 |  * UNKNOWN@[0x55f8c15bfe70,0x55f8c15bfe71)
|               1 |  |  * UNKNOWN@[0x7ffc16412300,0x7ffc16412301)
|               1 |  |  |  * _dl_find_dso_for_object
|               1 |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  * _dl_rtld_di_serinfo
|               1 |  |  |  |  |  |  * _dl_rtld_di_serinfo
|               5 |  * _start
|               5 |  |  * __libc_start_main
|               5 |  |  |  * __libc_secure_getenv
|               3 |  |  |  |  * KIconLoader.~KIconLoader()
|               3 |  |  |  |  |  * KIconLoader.~KIconLoader()
|               3 |  |  |  |  |  |  * uintToHex(unsigned, QChar)
|               3 |  |  |  |  |  |  |  * KIconTheme.~KIconTheme()
|               3 |  |  |  |  |  |  |  |  * KSharedConfig.~KSharedConfig()
|               3 |  |  |  |  |  |  |  |  |  * KSharedConfig.~KSharedConfig()
|               3 |  |  |  |  |  |  |  |  |  |  * KConfig.~KConfig()
|               3 |  |  |  |  |  |  |  |  |  |  |  * KConfig.checkUpdate(QString const&, QString const&)
|               3 |  |  |  |  |  |  |  |  |  |  |  |  * KConfig.checkUpdate(QString const&, QString const&)
|               2 |  |  |  |  * QPlatformInputContextFactory.keys()
|               2 |  |  |  |  |  * QFactoryLoader.~QFactoryLoader()
|               2 |  |  |  |  |  |  * QObject.~QObject()
|               2 |  |  |  |  |  |  |  * QFactoryLoader.indexOf(QString const&) const
|               2 |  |  |  |  |  |  |  |  * QFactoryLoader.indexOf(QString const&) const
|               2 |  |  |  |  |  |  |  |  |  * QFactoryLoader.keyMap() const
|               2 |  |  |  |  |  |  |  |  |  |  * cfree
|               2 |  |  |  |  |  |  |  |  |  |  |  * _IO_str_seekoff
