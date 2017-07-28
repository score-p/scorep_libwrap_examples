#include "libwrap.h"

#define SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ) \
    libwrap_qimage_region__ ## func

#define SCOREP_LIBWRAP_REGION_HANDLE( func ) \
    SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ).handle

#define SCOREP_LIBWRAP_REGION_FILTERED( func ) \
    SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ).filtered

#if defined( SCOREP_LIBWRAP_SHARED )
#define SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) \
    SCOREP_LIBWRAP_REGION_DESCRIPTOR( func ).funcptr
#endif

#include <scorep/SCOREP_Libwrap_Macros.h>

#ifdef __cplusplus
extern "C"
{
#endif

/* region descriptors */

#if defined( SCOREP_LIBWRAP_STATIC )

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    SCOREP_LIBWRAP_DECLARE_REAL_FUNC( rettype, func, args ); \
    static struct \
    { \
        SCOREP_RegionHandle handle; \
        int                 filtered; \
    } SCOREP_LIBWRAP_REGION_DESCRIPTOR( func );

#elif defined( SCOREP_LIBWRAP_SHARED )

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static struct \
    { \
        SCOREP_RegionHandle handle; \
        int                 filtered; \
        SCOREP_LIBWRAP_FUNC_TYPE( rettype, funcptr, args ); \
    } SCOREP_LIBWRAP_REGION_DESCRIPTOR( func );

#endif

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_qimage.inc.c"

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static void libwrap_qimage_init__##func( SCOREP_LibwrapHandle* handle ) \
    { \
        SCOREP_LIBWRAP_FUNC_INIT( handle, func, prettyname, file, line ); \
    }

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_qimage.inc.c"

/* region init functions */

static void
libwrap_qimage_init( SCOREP_LibwrapHandle* handle )
{
#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    ns libwrap_qimage_init__##func( handle );

#include "scorep_libwrap_qimage.inc.c"
}

#if defined( SCOREP_LIBWRAP_SHARED )

#define LIBWRAP_EARLY_INIT( func ) \
    do \
    { \
        if ( !SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) ) \
        { \
            libwrap_qimage_early_init(); \
        } \
    } while ( 0 )

/* region early init functions */

#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    static void libwrap_qimage_early_init__##func() \
    { \
        SCOREP_Libwrap_EarlySharedPtrInit( #func, ( void** )&SCOREP_LIBWRAP_FUNC_REAL_NAME( func ) ); \
    }

#define SCOREP_LIBWRAP_PROCESS_FUNC_WITH_NAMESPACE
#include "scorep_libwrap_qimage.inc.c"

static void
libwrap_qimage_early_init()
{
#define SCOREP_LIBWRAP_PROCESS_FUNC( rettype, func, args, prettyname, file, line, ns ) \
    ns libwrap_qimage_early_init__##func();

#include "scorep_libwrap_qimage.inc.c"
}

#else

#define LIBWRAP_EARLY_INIT( func ) do { } while ( 0 )

#endif

static const char* libwrap_qimage_libnames[] = {
    "libQt5Widgets.so",
    "libQt5Gui.so",
    "libQt5Core.so",
    "libpthread.so",
    "libpng.so",
    "libjpeg.so",
    "libpcre16.so",
    "libdl.so"
};
static SCOREP_LibwrapHandle*          libwrap_qimage_handle;
static const SCOREP_LibwrapAttributes libwrap_qimage_attributes =
{
    SCOREP_LIBWRAP_VERSION,
    "qimage",
    "QImage",
    SCOREP_LIBWRAP_MODE,
    libwrap_qimage_init,
    8,
    libwrap_qimage_libnames
};


#undef _ZN6QImageC2Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC2ERK5QSizeNS_6FormatE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2ERK5QSizeNS_6FormatE )( void *scorep_libwrap_arg_this, const QSize & size, QImage::Format format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2ERK5QSizeNS_6FormatE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2ERK5QSizeNS_6FormatE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2ERK5QSizeNS_6FormatE, ( scorep_libwrap_arg_this, size, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2ERK5QSizeNS_6FormatE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1ERK5QSizeNS_6FormatE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1ERK5QSizeNS_6FormatE )( void *scorep_libwrap_arg_this, const QSize & size, QImage::Format format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1ERK5QSizeNS_6FormatE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1ERK5QSizeNS_6FormatE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1ERK5QSizeNS_6FormatE, ( scorep_libwrap_arg_this, size, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1ERK5QSizeNS_6FormatE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC2EiiNS_6FormatE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2EiiNS_6FormatE )( void *scorep_libwrap_arg_this, int width, int height, QImage::Format format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2EiiNS_6FormatE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2EiiNS_6FormatE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2EiiNS_6FormatE, ( scorep_libwrap_arg_this, width, height, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2EiiNS_6FormatE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1EiiNS_6FormatE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1EiiNS_6FormatE )( void *scorep_libwrap_arg_this, int width, int height, QImage::Format format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1EiiNS_6FormatE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1EiiNS_6FormatE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1EiiNS_6FormatE, ( scorep_libwrap_arg_this, width, height, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1EiiNS_6FormatE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC2EPhiiNS_6FormatEPFvPvES2_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2EPhiiNS_6FormatEPFvPvES2_ )( void *scorep_libwrap_arg_this, uchar * data, int width, int height, QImage::Format format, QImageCleanupFunction cleanupFunction, void * cleanupInfo )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2EPhiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2EPhiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2EPhiiNS_6FormatEPFvPvES2_, ( scorep_libwrap_arg_this, data, width, height, format, cleanupFunction, cleanupInfo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2EPhiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1EPhiiNS_6FormatEPFvPvES2_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1EPhiiNS_6FormatEPFvPvES2_ )( void *scorep_libwrap_arg_this, uchar * data, int width, int height, QImage::Format format, QImageCleanupFunction cleanupFunction, void * cleanupInfo )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1EPhiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1EPhiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1EPhiiNS_6FormatEPFvPvES2_, ( scorep_libwrap_arg_this, data, width, height, format, cleanupFunction, cleanupInfo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1EPhiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC2EPKhiiNS_6FormatEPFvPvES3_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2EPKhiiNS_6FormatEPFvPvES3_ )( void *scorep_libwrap_arg_this, const uchar * data, int width, int height, QImage::Format format, QImageCleanupFunction cleanupFunction, void * cleanupInfo )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2EPKhiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2EPKhiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2EPKhiiNS_6FormatEPFvPvES3_, ( scorep_libwrap_arg_this, data, width, height, format, cleanupFunction, cleanupInfo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2EPKhiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1EPKhiiNS_6FormatEPFvPvES3_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1EPKhiiNS_6FormatEPFvPvES3_ )( void *scorep_libwrap_arg_this, const uchar * data, int width, int height, QImage::Format format, QImageCleanupFunction cleanupFunction, void * cleanupInfo )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1EPKhiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1EPKhiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1EPKhiiNS_6FormatEPFvPvES3_, ( scorep_libwrap_arg_this, data, width, height, format, cleanupFunction, cleanupInfo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1EPKhiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC2EPhiiiNS_6FormatEPFvPvES2_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2EPhiiiNS_6FormatEPFvPvES2_ )( void *scorep_libwrap_arg_this, uchar * data, int width, int height, int bytesPerLine, QImage::Format format, QImageCleanupFunction cleanupFunction, void * cleanupInfo )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2EPhiiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2EPhiiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2EPhiiiNS_6FormatEPFvPvES2_, ( scorep_libwrap_arg_this, data, width, height, bytesPerLine, format, cleanupFunction, cleanupInfo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2EPhiiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1EPhiiiNS_6FormatEPFvPvES2_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1EPhiiiNS_6FormatEPFvPvES2_ )( void *scorep_libwrap_arg_this, uchar * data, int width, int height, int bytesPerLine, QImage::Format format, QImageCleanupFunction cleanupFunction, void * cleanupInfo )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1EPhiiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1EPhiiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1EPhiiiNS_6FormatEPFvPvES2_, ( scorep_libwrap_arg_this, data, width, height, bytesPerLine, format, cleanupFunction, cleanupInfo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1EPhiiiNS_6FormatEPFvPvES2_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC2EPKhiiiNS_6FormatEPFvPvES3_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2EPKhiiiNS_6FormatEPFvPvES3_ )( void *scorep_libwrap_arg_this, const uchar * data, int width, int height, int bytesPerLine, QImage::Format format, QImageCleanupFunction cleanupFunction, void * cleanupInfo )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2EPKhiiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2EPKhiiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2EPKhiiiNS_6FormatEPFvPvES3_, ( scorep_libwrap_arg_this, data, width, height, bytesPerLine, format, cleanupFunction, cleanupInfo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2EPKhiiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1EPKhiiiNS_6FormatEPFvPvES3_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1EPKhiiiNS_6FormatEPFvPvES3_ )( void *scorep_libwrap_arg_this, const uchar * data, int width, int height, int bytesPerLine, QImage::Format format, QImageCleanupFunction cleanupFunction, void * cleanupInfo )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1EPKhiiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1EPKhiiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1EPKhiiiNS_6FormatEPFvPvES3_, ( scorep_libwrap_arg_this, data, width, height, bytesPerLine, format, cleanupFunction, cleanupInfo ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1EPKhiiiNS_6FormatEPFvPvES3_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC2EPKPKc
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2EPKPKc )( void *scorep_libwrap_arg_this, const char *const xpm[] )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2EPKPKc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2EPKPKc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2EPKPKc, ( scorep_libwrap_arg_this, xpm ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2EPKPKc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1EPKPKc
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1EPKPKc )( void *scorep_libwrap_arg_this, const char *const xpm[] )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1EPKPKc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1EPKPKc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1EPKPKc, ( scorep_libwrap_arg_this, xpm ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1EPKPKc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC2ERK7QStringPKc
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2ERK7QStringPKc )( void *scorep_libwrap_arg_this, const QString & fileName, const char * format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2ERK7QStringPKc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2ERK7QStringPKc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2ERK7QStringPKc, ( scorep_libwrap_arg_this, fileName, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2ERK7QStringPKc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1ERK7QStringPKc
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1ERK7QStringPKc )( void *scorep_libwrap_arg_this, const QString & fileName, const char * format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1ERK7QStringPKc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1ERK7QStringPKc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1ERK7QStringPKc, ( scorep_libwrap_arg_this, fileName, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1ERK7QStringPKc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC2ERKS_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC2ERKS_ )( void *scorep_libwrap_arg_this, const QImage & scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC2ERKS_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC2ERKS_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC2ERKS_, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC2ERKS_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageC1ERKS_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageC1ERKS_ )( void *scorep_libwrap_arg_this, const QImage & scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageC1ERKS_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageC1ERKS_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageC1ERKS_, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageC1ERKS_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImageaSERKS_
QImage &
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImageaSERKS_ )( void *scorep_libwrap_arg_this, const QImage & scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN6QImageaSERKS_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImageaSERKS_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage & scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImageaSERKS_, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImageaSERKS_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage7devTypeEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage7devTypeEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage7devTypeEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage7devTypeEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage7devTypeEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage7devTypeEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImageeqERKS_
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImageeqERKS_ )( void *scorep_libwrap_arg_this, const QImage & scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImageeqERKS_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImageeqERKS_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImageeqERKS_, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImageeqERKS_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImageneERKS_
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImageneERKS_ )( void *scorep_libwrap_arg_this, const QImage & scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImageneERKS_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImageneERKS_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImageneERKS_, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImageneERKS_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage6detachEv
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage6detachEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage6detachEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage6detachEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage6detachEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage6detachEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage10isDetachedEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage10isDetachedEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage10isDetachedEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage10isDetachedEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage10isDetachedEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage10isDetachedEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage4copyERK5QRect
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage4copyERK5QRect )( void *scorep_libwrap_arg_this, const QRect & rect )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage4copyERK5QRect );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage4copyERK5QRect );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage4copyERK5QRect, ( scorep_libwrap_arg_this, rect ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage4copyERK5QRect );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage6formatEv
QImage::Format
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage6formatEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage6formatEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage6formatEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage::Format scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage6formatEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage6formatEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage15convertToFormatENS_6FormatERK7QVectorIjE6QFlagsIN2Qt19ImageConversionFlagEE
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage15convertToFormatENS_6FormatERK7QVectorIjE6QFlagsIN2Qt19ImageConversionFlagEE )( void *scorep_libwrap_arg_this, QImage::Format f, const QVector<QRgb> & colorTable, Qt::ImageConversionFlags flags )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage15convertToFormatENS_6FormatERK7QVectorIjE6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage15convertToFormatENS_6FormatERK7QVectorIjE6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage15convertToFormatENS_6FormatERK7QVectorIjE6QFlagsIN2Qt19ImageConversionFlagEE, ( scorep_libwrap_arg_this, f, colorTable, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage15convertToFormatENS_6FormatERK7QVectorIjE6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage5widthEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage5widthEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage5widthEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage5widthEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage5widthEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage5widthEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage6heightEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage6heightEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage6heightEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage6heightEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage6heightEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage6heightEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage4sizeEv
QSize
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage4sizeEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage4sizeEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage4sizeEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QSize scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage4sizeEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage4sizeEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage4rectEv
QRect
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage4rectEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage4rectEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage4rectEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QRect scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage4rectEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage4rectEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage5depthEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage5depthEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage5depthEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage5depthEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage5depthEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage5depthEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage10colorCountEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage10colorCountEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage10colorCountEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage10colorCountEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage10colorCountEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage10colorCountEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage13bitPlaneCountEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage13bitPlaneCountEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage13bitPlaneCountEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage13bitPlaneCountEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage13bitPlaneCountEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage13bitPlaneCountEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage5colorEi
QRgb
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage5colorEi )( void *scorep_libwrap_arg_this, int i )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage5colorEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage5colorEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QRgb scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage5colorEi, ( scorep_libwrap_arg_this, i ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage5colorEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage8setColorEij
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage8setColorEij )( void *scorep_libwrap_arg_this, int i, QRgb c )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage8setColorEij );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage8setColorEij );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage8setColorEij, ( scorep_libwrap_arg_this, i, c ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage8setColorEij );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImage13setColorCountEi
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage13setColorCountEi )( void *scorep_libwrap_arg_this, int scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage13setColorCountEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage13setColorCountEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage13setColorCountEi, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage13setColorCountEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage7allGrayEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage7allGrayEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage7allGrayEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage7allGrayEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage7allGrayEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage7allGrayEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage11isGrayscaleEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage11isGrayscaleEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage11isGrayscaleEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage11isGrayscaleEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage11isGrayscaleEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage11isGrayscaleEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage4bitsEv
uchar *
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage4bitsEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage4bitsEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage4bitsEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    uchar * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage4bitsEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage4bitsEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage4bitsEv
const uchar *
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage4bitsEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage4bitsEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage4bitsEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    const uchar * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage4bitsEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage4bitsEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage9constBitsEv
const uchar *
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage9constBitsEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage9constBitsEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage9constBitsEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    const uchar * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage9constBitsEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage9constBitsEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage9byteCountEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage9byteCountEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage9byteCountEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage9byteCountEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage9byteCountEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage9byteCountEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage8scanLineEi
uchar *
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage8scanLineEi )( void *scorep_libwrap_arg_this, int scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage8scanLineEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage8scanLineEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    uchar * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage8scanLineEi, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage8scanLineEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage8scanLineEi
const uchar *
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage8scanLineEi )( void *scorep_libwrap_arg_this, int scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage8scanLineEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage8scanLineEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    const uchar * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage8scanLineEi, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage8scanLineEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage13constScanLineEi
const uchar *
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage13constScanLineEi )( void *scorep_libwrap_arg_this, int scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage13constScanLineEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage13constScanLineEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    const uchar * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage13constScanLineEi, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage13constScanLineEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage12bytesPerLineEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage12bytesPerLineEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage12bytesPerLineEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage12bytesPerLineEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage12bytesPerLineEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage12bytesPerLineEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage5validEii
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage5validEii )( void *scorep_libwrap_arg_this, int x, int y )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage5validEii );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage5validEii );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage5validEii, ( scorep_libwrap_arg_this, x, y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage5validEii );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage10pixelIndexEii
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage10pixelIndexEii )( void *scorep_libwrap_arg_this, int x, int y )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage10pixelIndexEii );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage10pixelIndexEii );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage10pixelIndexEii, ( scorep_libwrap_arg_this, x, y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage10pixelIndexEii );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage5pixelEii
QRgb
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage5pixelEii )( void *scorep_libwrap_arg_this, int x, int y )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage5pixelEii );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage5pixelEii );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QRgb scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage5pixelEii, ( scorep_libwrap_arg_this, x, y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage5pixelEii );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage8setPixelEiij
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage8setPixelEiij )( void *scorep_libwrap_arg_this, int x, int y, uint index_or_rgb )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage8setPixelEiij );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage8setPixelEiij );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage8setPixelEiij, ( scorep_libwrap_arg_this, x, y, index_or_rgb ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage8setPixelEiij );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage10pixelColorEii
QColor
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage10pixelColorEii )( void *scorep_libwrap_arg_this, int x, int y )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage10pixelColorEii );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage10pixelColorEii );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QColor scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage10pixelColorEii, ( scorep_libwrap_arg_this, x, y ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage10pixelColorEii );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage13setPixelColorEiiRK6QColor
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage13setPixelColorEiiRK6QColor )( void *scorep_libwrap_arg_this, int x, int y, const QColor & c )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage13setPixelColorEiiRK6QColor );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage13setPixelColorEiiRK6QColor );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage13setPixelColorEiiRK6QColor, ( scorep_libwrap_arg_this, x, y, c ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage13setPixelColorEiiRK6QColor );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage10colorTableEv
QVector<QRgb>
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage10colorTableEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage10colorTableEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage10colorTableEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QVector<QRgb> scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage10colorTableEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage10colorTableEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage13setColorTableE7QVectorIjE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage13setColorTableE7QVectorIjE )( void *scorep_libwrap_arg_this, const QVector<QRgb> colors )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage13setColorTableE7QVectorIjE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage13setColorTableE7QVectorIjE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage13setColorTableE7QVectorIjE, ( scorep_libwrap_arg_this, colors ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage13setColorTableE7QVectorIjE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage16devicePixelRatioEv
qreal
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage16devicePixelRatioEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage16devicePixelRatioEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage16devicePixelRatioEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    qreal scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage16devicePixelRatioEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage16devicePixelRatioEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage19setDevicePixelRatioEd
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage19setDevicePixelRatioEd )( void *scorep_libwrap_arg_this, qreal scaleFactor )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage19setDevicePixelRatioEd );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage19setDevicePixelRatioEd );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage19setDevicePixelRatioEd, ( scorep_libwrap_arg_this, scaleFactor ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage19setDevicePixelRatioEd );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImage4fillEj
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage4fillEj )( void *scorep_libwrap_arg_this, uint pixel )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage4fillEj );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage4fillEj );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage4fillEj, ( scorep_libwrap_arg_this, pixel ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage4fillEj );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImage4fillERK6QColor
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage4fillERK6QColor )( void *scorep_libwrap_arg_this, const QColor & color )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage4fillERK6QColor );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage4fillERK6QColor );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage4fillERK6QColor, ( scorep_libwrap_arg_this, color ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage4fillERK6QColor );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImage4fillEN2Qt11GlobalColorE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage4fillEN2Qt11GlobalColorE )( void *scorep_libwrap_arg_this, Qt::GlobalColor color )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage4fillEN2Qt11GlobalColorE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage4fillEN2Qt11GlobalColorE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage4fillEN2Qt11GlobalColorE, ( scorep_libwrap_arg_this, color ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage4fillEN2Qt11GlobalColorE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage15hasAlphaChannelEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage15hasAlphaChannelEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage15hasAlphaChannelEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage15hasAlphaChannelEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage15hasAlphaChannelEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage15hasAlphaChannelEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage15setAlphaChannelERKS_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage15setAlphaChannelERKS_ )( void *scorep_libwrap_arg_this, const QImage & alphaChannel )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage15setAlphaChannelERKS_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage15setAlphaChannelERKS_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage15setAlphaChannelERKS_, ( scorep_libwrap_arg_this, alphaChannel ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage15setAlphaChannelERKS_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage12alphaChannelEv
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage12alphaChannelEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage12alphaChannelEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage12alphaChannelEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage12alphaChannelEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage12alphaChannelEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage15createAlphaMaskE6QFlagsIN2Qt19ImageConversionFlagEE
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage15createAlphaMaskE6QFlagsIN2Qt19ImageConversionFlagEE )( void *scorep_libwrap_arg_this, Qt::ImageConversionFlags flags )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage15createAlphaMaskE6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage15createAlphaMaskE6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage15createAlphaMaskE6QFlagsIN2Qt19ImageConversionFlagEE, ( scorep_libwrap_arg_this, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage15createAlphaMaskE6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage19createHeuristicMaskEb
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage19createHeuristicMaskEb )( void *scorep_libwrap_arg_this, bool clipTight )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage19createHeuristicMaskEb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage19createHeuristicMaskEb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage19createHeuristicMaskEb, ( scorep_libwrap_arg_this, clipTight ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage19createHeuristicMaskEb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage19createMaskFromColorEjN2Qt8MaskModeE
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage19createMaskFromColorEjN2Qt8MaskModeE )( void *scorep_libwrap_arg_this, QRgb color, Qt::MaskMode mode )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage19createMaskFromColorEjN2Qt8MaskModeE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage19createMaskFromColorEjN2Qt8MaskModeE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage19createMaskFromColorEjN2Qt8MaskModeE, ( scorep_libwrap_arg_this, color, mode ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage19createMaskFromColorEjN2Qt8MaskModeE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage6scaledERK5QSizeN2Qt15AspectRatioModeENS3_18TransformationModeE
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage6scaledERK5QSizeN2Qt15AspectRatioModeENS3_18TransformationModeE )( void *scorep_libwrap_arg_this, const QSize & s, Qt::AspectRatioMode aspectMode, Qt::TransformationMode mode )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage6scaledERK5QSizeN2Qt15AspectRatioModeENS3_18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage6scaledERK5QSizeN2Qt15AspectRatioModeENS3_18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage6scaledERK5QSizeN2Qt15AspectRatioModeENS3_18TransformationModeE, ( scorep_libwrap_arg_this, s, aspectMode, mode ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage6scaledERK5QSizeN2Qt15AspectRatioModeENS3_18TransformationModeE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage13scaledToWidthEiN2Qt18TransformationModeE
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage13scaledToWidthEiN2Qt18TransformationModeE )( void *scorep_libwrap_arg_this, int w, Qt::TransformationMode mode )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage13scaledToWidthEiN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage13scaledToWidthEiN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage13scaledToWidthEiN2Qt18TransformationModeE, ( scorep_libwrap_arg_this, w, mode ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage13scaledToWidthEiN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage14scaledToHeightEiN2Qt18TransformationModeE
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage14scaledToHeightEiN2Qt18TransformationModeE )( void *scorep_libwrap_arg_this, int h, Qt::TransformationMode mode )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage14scaledToHeightEiN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage14scaledToHeightEiN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage14scaledToHeightEiN2Qt18TransformationModeE, ( scorep_libwrap_arg_this, h, mode ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage14scaledToHeightEiN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage11transformedERK7QMatrixN2Qt18TransformationModeE
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage11transformedERK7QMatrixN2Qt18TransformationModeE )( void *scorep_libwrap_arg_this, const QMatrix & matrix, Qt::TransformationMode mode )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage11transformedERK7QMatrixN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage11transformedERK7QMatrixN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage11transformedERK7QMatrixN2Qt18TransformationModeE, ( scorep_libwrap_arg_this, matrix, mode ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage11transformedERK7QMatrixN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage10trueMatrixERK7QMatrixii
QMatrix
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage10trueMatrixERK7QMatrixii )( const QMatrix & scorep_libwrap_arg_1, int w, int h )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage10trueMatrixERK7QMatrixii );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage10trueMatrixERK7QMatrixii );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QMatrix scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage10trueMatrixERK7QMatrixii, ( scorep_libwrap_arg_1, w, h ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage10trueMatrixERK7QMatrixii );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage11transformedERK10QTransformN2Qt18TransformationModeE
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage11transformedERK10QTransformN2Qt18TransformationModeE )( void *scorep_libwrap_arg_this, const QTransform & matrix, Qt::TransformationMode mode )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage11transformedERK10QTransformN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage11transformedERK10QTransformN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage11transformedERK10QTransformN2Qt18TransformationModeE, ( scorep_libwrap_arg_this, matrix, mode ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage11transformedERK10QTransformN2Qt18TransformationModeE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage10trueMatrixERK10QTransformii
QTransform
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage10trueMatrixERK10QTransformii )( const QTransform & scorep_libwrap_arg_1, int w, int h )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage10trueMatrixERK10QTransformii );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage10trueMatrixERK10QTransformii );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QTransform scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage10trueMatrixERK10QTransformii, ( scorep_libwrap_arg_1, w, h ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage10trueMatrixERK10QTransformii );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage12invertPixelsENS_10InvertModeE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage12invertPixelsENS_10InvertModeE )( void *scorep_libwrap_arg_this, QImage::InvertMode scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage12invertPixelsENS_10InvertModeE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage12invertPixelsENS_10InvertModeE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage12invertPixelsENS_10InvertModeE, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage12invertPixelsENS_10InvertModeE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImage4loadEP9QIODevicePKc
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage4loadEP9QIODevicePKc )( void *scorep_libwrap_arg_this, QIODevice * device, const char * format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage4loadEP9QIODevicePKc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage4loadEP9QIODevicePKc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage4loadEP9QIODevicePKc, ( scorep_libwrap_arg_this, device, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage4loadEP9QIODevicePKc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage4loadERK7QStringPKc
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage4loadERK7QStringPKc )( void *scorep_libwrap_arg_this, const QString & fileName, const char * format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage4loadERK7QStringPKc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage4loadERK7QStringPKc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage4loadERK7QStringPKc, ( scorep_libwrap_arg_this, fileName, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage4loadERK7QStringPKc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage12loadFromDataEPKhiPKc
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage12loadFromDataEPKhiPKc )( void *scorep_libwrap_arg_this, const uchar * buf, int len, const char * format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage12loadFromDataEPKhiPKc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage12loadFromDataEPKhiPKc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage12loadFromDataEPKhiPKc, ( scorep_libwrap_arg_this, buf, len, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage12loadFromDataEPKhiPKc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage4saveERK7QStringPKci
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage4saveERK7QStringPKci )( void *scorep_libwrap_arg_this, const QString & fileName, const char * format, int quality )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage4saveERK7QStringPKci );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage4saveERK7QStringPKci );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage4saveERK7QStringPKci, ( scorep_libwrap_arg_this, fileName, format, quality ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage4saveERK7QStringPKci );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage4saveEP9QIODevicePKci
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage4saveEP9QIODevicePKci )( void *scorep_libwrap_arg_this, QIODevice * device, const char * format, int quality )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage4saveEP9QIODevicePKci );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage4saveEP9QIODevicePKci );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage4saveEP9QIODevicePKci, ( scorep_libwrap_arg_this, device, format, quality ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage4saveEP9QIODevicePKci );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage8fromDataEPKhiPKc
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage8fromDataEPKhiPKc )( const uchar * data, int size, const char * format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage8fromDataEPKhiPKc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage8fromDataEPKhiPKc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage8fromDataEPKhiPKc, ( data, size, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage8fromDataEPKhiPKc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage8cacheKeyEv
qint64
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage8cacheKeyEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage8cacheKeyEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage8cacheKeyEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    qint64 scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage8cacheKeyEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage8cacheKeyEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage11paintEngineEv
QPaintEngine *
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage11paintEngineEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage11paintEngineEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage11paintEngineEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QPaintEngine * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage11paintEngineEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage11paintEngineEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage13dotsPerMeterXEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage13dotsPerMeterXEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage13dotsPerMeterXEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage13dotsPerMeterXEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage13dotsPerMeterXEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage13dotsPerMeterXEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage13dotsPerMeterYEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage13dotsPerMeterYEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage13dotsPerMeterYEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage13dotsPerMeterYEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage13dotsPerMeterYEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage13dotsPerMeterYEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage16setDotsPerMeterXEi
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage16setDotsPerMeterXEi )( void *scorep_libwrap_arg_this, int scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage16setDotsPerMeterXEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage16setDotsPerMeterXEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage16setDotsPerMeterXEi, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage16setDotsPerMeterXEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QImage16setDotsPerMeterYEi
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage16setDotsPerMeterYEi )( void *scorep_libwrap_arg_this, int scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage16setDotsPerMeterYEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage16setDotsPerMeterYEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage16setDotsPerMeterYEi, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage16setDotsPerMeterYEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage6offsetEv
QPoint
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage6offsetEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage6offsetEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage6offsetEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QPoint scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage6offsetEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage6offsetEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage9setOffsetERK6QPoint
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage9setOffsetERK6QPoint )( void *scorep_libwrap_arg_this, const QPoint & scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage9setOffsetERK6QPoint );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage9setOffsetERK6QPoint );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage9setOffsetERK6QPoint, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage9setOffsetERK6QPoint );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage8textKeysEv
QStringList
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage8textKeysEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage8textKeysEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage8textKeysEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QStringList scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage8textKeysEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage8textKeysEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK6QImage4textERK7QString
QString
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage4textERK7QString )( void *scorep_libwrap_arg_this, const QString & key )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage4textERK7QString );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage4textERK7QString );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QString scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage4textERK7QString, ( scorep_libwrap_arg_this, key ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage4textERK7QString );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage7setTextERK7QStringS2_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage7setTextERK7QStringS2_ )( void *scorep_libwrap_arg_this, const QString & key, const QString & value )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage7setTextERK7QStringS2_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage7setTextERK7QStringS2_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage7setTextERK7QStringS2_, ( scorep_libwrap_arg_this, key, value ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage7setTextERK7QStringS2_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK6QImage11pixelFormatEv
QPixelFormat
SCOREP_LIBWRAP_FUNC_NAME( _ZNK6QImage11pixelFormatEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK6QImage11pixelFormatEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK6QImage11pixelFormatEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QPixelFormat scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK6QImage11pixelFormatEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK6QImage11pixelFormatEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage13toPixelFormatENS_6FormatE
QPixelFormat
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage13toPixelFormatENS_6FormatE )( QImage::Format format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage13toPixelFormatENS_6FormatE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage13toPixelFormatENS_6FormatE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QPixelFormat scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage13toPixelFormatENS_6FormatE, ( format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage13toPixelFormatENS_6FormatE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QImage13toImageFormatE12QPixelFormat
QImage::Format
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QImage13toImageFormatE12QPixelFormat )( QPixelFormat format )
{
    LIBWRAP_EARLY_INIT( _ZN6QImage13toImageFormatE12QPixelFormat );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QImage13toImageFormatE12QPixelFormat );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage::Format scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN6QImage13toImageFormatE12QPixelFormat, ( format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QImage13toImageFormatE12QPixelFormat );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZrsR11QDataStreamR6QImage
QDataStream &
SCOREP_LIBWRAP_FUNC_NAME( _ZrsR11QDataStreamR6QImage )( QDataStream & scorep_libwrap_arg_1, QImage & scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( _ZrsR11QDataStreamR6QImage );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZrsR11QDataStreamR6QImage );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QDataStream & scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZrsR11QDataStreamR6QImage, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZrsR11QDataStreamR6QImage );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _Zls6QDebugRK6QImage
QDebug
SCOREP_LIBWRAP_FUNC_NAME( _Zls6QDebugRK6QImage )( QDebug scorep_libwrap_arg_1, const QImage & scorep_libwrap_arg_2 )
{
    LIBWRAP_EARLY_INIT( _Zls6QDebugRK6QImage );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _Zls6QDebugRK6QImage );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QDebug scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _Zls6QDebugRK6QImage, ( scorep_libwrap_arg_1, scorep_libwrap_arg_2 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _Zls6QDebugRK6QImage );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN7QPixmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE
QPixmap
SCOREP_LIBWRAP_FUNC_NAME( _ZN7QPixmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE )( const QImage & image, Qt::ImageConversionFlags flags )
{
    LIBWRAP_EARLY_INIT( _ZN7QPixmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN7QPixmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QPixmap scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN7QPixmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE, ( image, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN7QPixmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN7QPixmap15fromImageReaderEP12QImageReader6QFlagsIN2Qt19ImageConversionFlagEE
QPixmap
SCOREP_LIBWRAP_FUNC_NAME( _ZN7QPixmap15fromImageReaderEP12QImageReader6QFlagsIN2Qt19ImageConversionFlagEE )( QImageReader * imageReader, Qt::ImageConversionFlags flags )
{
    LIBWRAP_EARLY_INIT( _ZN7QPixmap15fromImageReaderEP12QImageReader6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN7QPixmap15fromImageReaderEP12QImageReader6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QPixmap scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN7QPixmap15fromImageReaderEP12QImageReader6QFlagsIN2Qt19ImageConversionFlagEE, ( imageReader, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN7QPixmap15fromImageReaderEP12QImageReader6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN7QPixmap16convertFromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN7QPixmap16convertFromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE )( void *scorep_libwrap_arg_this, const QImage & img, Qt::ImageConversionFlags flags )
{
    LIBWRAP_EARLY_INIT( _ZN7QPixmap16convertFromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN7QPixmap16convertFromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN7QPixmap16convertFromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE, ( scorep_libwrap_arg_this, img, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN7QPixmap16convertFromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN7QBitmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE
QBitmap
SCOREP_LIBWRAP_FUNC_NAME( _ZN7QBitmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE )( const QImage & image, Qt::ImageConversionFlags flags )
{
    LIBWRAP_EARLY_INIT( _ZN7QBitmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN7QBitmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QBitmap scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN7QBitmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE, ( image, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN7QBitmap9fromImageERK6QImage6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN7QBitmap8fromDataERK5QSizePKhN6QImage6FormatE
QBitmap
SCOREP_LIBWRAP_FUNC_NAME( _ZN7QBitmap8fromDataERK5QSizePKhN6QImage6FormatE )( const QSize & size, const uchar * bits, QImage::Format monoFormat )
{
    LIBWRAP_EARLY_INIT( _ZN7QBitmap8fromDataERK5QSizePKhN6QImage6FormatE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN7QBitmap8fromDataERK5QSizePKhN6QImage6FormatE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QBitmap scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN7QBitmap8fromDataERK5QSizePKhN6QImage6FormatE, ( size, bits, monoFormat ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN7QBitmap8fromDataERK5QSizePKhN6QImage6FormatE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN15QImageIOHandlerC2Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandlerC2Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandlerC2Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandlerC2Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandlerC2Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandlerC2Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN15QImageIOHandlerD2Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandlerD2Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandlerD2Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandlerD2Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandlerD2Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandlerD2Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN15QImageIOHandlerD1Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandlerD1Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandlerD1Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandlerD1Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandlerD1Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandlerD1Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN15QImageIOHandlerD0Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandlerD0Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandlerD0Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandlerD0Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandlerD0Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandlerD0Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN15QImageIOHandler9setDeviceEP9QIODevice
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandler9setDeviceEP9QIODevice )( void *scorep_libwrap_arg_this, QIODevice * device )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandler9setDeviceEP9QIODevice );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandler9setDeviceEP9QIODevice );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandler9setDeviceEP9QIODevice, ( scorep_libwrap_arg_this, device ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandler9setDeviceEP9QIODevice );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK15QImageIOHandler6deviceEv
QIODevice *
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler6deviceEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler6deviceEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler6deviceEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QIODevice * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler6deviceEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler6deviceEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN15QImageIOHandler9setFormatERK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandler9setFormatERK10QByteArray )( void *scorep_libwrap_arg_this, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandler9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandler9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandler9setFormatERK10QByteArray, ( scorep_libwrap_arg_this, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandler9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK15QImageIOHandler9setFormatERK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler9setFormatERK10QByteArray )( void *scorep_libwrap_arg_this, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler9setFormatERK10QByteArray, ( scorep_libwrap_arg_this, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK15QImageIOHandler6formatEv
QByteArray
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler6formatEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler6formatEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler6formatEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QByteArray scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler6formatEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler6formatEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK15QImageIOHandler4nameEv
QByteArray
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler4nameEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler4nameEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler4nameEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QByteArray scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler4nameEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler4nameEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN15QImageIOHandler5writeERK6QImage
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandler5writeERK6QImage )( void *scorep_libwrap_arg_this, const QImage & image )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandler5writeERK6QImage );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandler5writeERK6QImage );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandler5writeERK6QImage, ( scorep_libwrap_arg_this, image ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandler5writeERK6QImage );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK15QImageIOHandler6optionENS_11ImageOptionE
QVariant
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler6optionENS_11ImageOptionE )( void *scorep_libwrap_arg_this, QImageIOHandler::ImageOption option )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler6optionENS_11ImageOptionE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler6optionENS_11ImageOptionE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QVariant scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler6optionENS_11ImageOptionE, ( scorep_libwrap_arg_this, option ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler6optionENS_11ImageOptionE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN15QImageIOHandler9setOptionENS_11ImageOptionERK8QVariant
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandler9setOptionENS_11ImageOptionERK8QVariant )( void *scorep_libwrap_arg_this, QImageIOHandler::ImageOption option, const QVariant & value )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandler9setOptionENS_11ImageOptionERK8QVariant );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandler9setOptionENS_11ImageOptionERK8QVariant );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandler9setOptionENS_11ImageOptionERK8QVariant, ( scorep_libwrap_arg_this, option, value ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandler9setOptionENS_11ImageOptionERK8QVariant );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK15QImageIOHandler14supportsOptionENS_11ImageOptionE
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler14supportsOptionENS_11ImageOptionE )( void *scorep_libwrap_arg_this, QImageIOHandler::ImageOption option )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler14supportsOptionENS_11ImageOptionE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler14supportsOptionENS_11ImageOptionE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler14supportsOptionENS_11ImageOptionE, ( scorep_libwrap_arg_this, option ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler14supportsOptionENS_11ImageOptionE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN15QImageIOHandler15jumpToNextImageEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandler15jumpToNextImageEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandler15jumpToNextImageEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandler15jumpToNextImageEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandler15jumpToNextImageEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandler15jumpToNextImageEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN15QImageIOHandler11jumpToImageEi
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN15QImageIOHandler11jumpToImageEi )( void *scorep_libwrap_arg_this, int imageNumber )
{
    LIBWRAP_EARLY_INIT( _ZN15QImageIOHandler11jumpToImageEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN15QImageIOHandler11jumpToImageEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN15QImageIOHandler11jumpToImageEi, ( scorep_libwrap_arg_this, imageNumber ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN15QImageIOHandler11jumpToImageEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK15QImageIOHandler9loopCountEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler9loopCountEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler9loopCountEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler9loopCountEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler9loopCountEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler9loopCountEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK15QImageIOHandler10imageCountEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler10imageCountEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler10imageCountEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler10imageCountEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler10imageCountEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler10imageCountEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK15QImageIOHandler14nextImageDelayEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler14nextImageDelayEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler14nextImageDelayEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler14nextImageDelayEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler14nextImageDelayEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler14nextImageDelayEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK15QImageIOHandler18currentImageNumberEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler18currentImageNumberEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler18currentImageNumberEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler18currentImageNumberEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler18currentImageNumberEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler18currentImageNumberEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK15QImageIOHandler16currentImageRectEv
QRect
SCOREP_LIBWRAP_FUNC_NAME( _ZNK15QImageIOHandler16currentImageRectEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK15QImageIOHandler16currentImageRectEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK15QImageIOHandler16currentImageRectEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QRect scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK15QImageIOHandler16currentImageRectEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK15QImageIOHandler16currentImageRectEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK14QImageIOPlugin10metaObjectEv
const QMetaObject *
SCOREP_LIBWRAP_FUNC_NAME( _ZNK14QImageIOPlugin10metaObjectEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK14QImageIOPlugin10metaObjectEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK14QImageIOPlugin10metaObjectEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    const QMetaObject * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK14QImageIOPlugin10metaObjectEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK14QImageIOPlugin10metaObjectEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN14QImageIOPlugin11qt_metacastEPKc
void *
SCOREP_LIBWRAP_FUNC_NAME( _ZN14QImageIOPlugin11qt_metacastEPKc )( void *scorep_libwrap_arg_this, const char * scorep_libwrap_arg_1 )
{
    LIBWRAP_EARLY_INIT( _ZN14QImageIOPlugin11qt_metacastEPKc );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN14QImageIOPlugin11qt_metacastEPKc );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    void * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN14QImageIOPlugin11qt_metacastEPKc, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN14QImageIOPlugin11qt_metacastEPKc );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN14QImageIOPlugin11qt_metacallEN11QMetaObject4CallEiPPv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZN14QImageIOPlugin11qt_metacallEN11QMetaObject4CallEiPPv )( void *scorep_libwrap_arg_this, QMetaObject::Call scorep_libwrap_arg_1, int scorep_libwrap_arg_2, void ** scorep_libwrap_arg_3 )
{
    LIBWRAP_EARLY_INIT( _ZN14QImageIOPlugin11qt_metacallEN11QMetaObject4CallEiPPv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN14QImageIOPlugin11qt_metacallEN11QMetaObject4CallEiPPv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN14QImageIOPlugin11qt_metacallEN11QMetaObject4CallEiPPv, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1, scorep_libwrap_arg_2, scorep_libwrap_arg_3 ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN14QImageIOPlugin11qt_metacallEN11QMetaObject4CallEiPPv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN14QImageIOPluginC2EP7QObject
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN14QImageIOPluginC2EP7QObject )( void *scorep_libwrap_arg_this, QObject * parent )
{
    LIBWRAP_EARLY_INIT( _ZN14QImageIOPluginC2EP7QObject );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN14QImageIOPluginC2EP7QObject );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN14QImageIOPluginC2EP7QObject, ( scorep_libwrap_arg_this, parent ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN14QImageIOPluginC2EP7QObject );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN14QImageIOPluginD2Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN14QImageIOPluginD2Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN14QImageIOPluginD2Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN14QImageIOPluginD2Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN14QImageIOPluginD2Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN14QImageIOPluginD2Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN14QImageIOPluginD1Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN14QImageIOPluginD1Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN14QImageIOPluginD1Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN14QImageIOPluginD1Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN14QImageIOPluginD1Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN14QImageIOPluginD1Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN14QImageIOPluginD0Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN14QImageIOPluginD0Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN14QImageIOPluginD0Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN14QImageIOPluginD0Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN14QImageIOPluginD0Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN14QImageIOPluginD0Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageReaderC2Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReaderC2Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReaderC2Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReaderC2Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReaderC2Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReaderC2Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageReaderC1Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReaderC1Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReaderC1Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReaderC1Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReaderC1Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReaderC1Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageReaderC2EP9QIODeviceRK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReaderC2EP9QIODeviceRK10QByteArray )( void *scorep_libwrap_arg_this, QIODevice * device, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReaderC2EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReaderC2EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReaderC2EP9QIODeviceRK10QByteArray, ( scorep_libwrap_arg_this, device, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReaderC2EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageReaderC1EP9QIODeviceRK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReaderC1EP9QIODeviceRK10QByteArray )( void *scorep_libwrap_arg_this, QIODevice * device, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReaderC1EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReaderC1EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReaderC1EP9QIODeviceRK10QByteArray, ( scorep_libwrap_arg_this, device, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReaderC1EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageReaderC2ERK7QStringRK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReaderC2ERK7QStringRK10QByteArray )( void *scorep_libwrap_arg_this, const QString & fileName, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReaderC2ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReaderC2ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReaderC2ERK7QStringRK10QByteArray, ( scorep_libwrap_arg_this, fileName, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReaderC2ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageReaderC1ERK7QStringRK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReaderC1ERK7QStringRK10QByteArray )( void *scorep_libwrap_arg_this, const QString & fileName, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReaderC1ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReaderC1ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReaderC1ERK7QStringRK10QByteArray, ( scorep_libwrap_arg_this, fileName, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReaderC1ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageReaderD2Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReaderD2Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReaderD2Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReaderD2Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReaderD2Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReaderD2Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageReaderD1Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReaderD1Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReaderD1Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReaderD1Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReaderD1Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReaderD1Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageReader9setFormatERK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader9setFormatERK10QByteArray )( void *scorep_libwrap_arg_this, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader9setFormatERK10QByteArray, ( scorep_libwrap_arg_this, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader6formatEv
QByteArray
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader6formatEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader6formatEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader6formatEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QByteArray scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader6formatEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader6formatEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader24setAutoDetectImageFormatEb
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader24setAutoDetectImageFormatEb )( void *scorep_libwrap_arg_this, bool enabled )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader24setAutoDetectImageFormatEb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader24setAutoDetectImageFormatEb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader24setAutoDetectImageFormatEb, ( scorep_libwrap_arg_this, enabled ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader24setAutoDetectImageFormatEb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader21autoDetectImageFormatEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader21autoDetectImageFormatEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader21autoDetectImageFormatEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader21autoDetectImageFormatEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader21autoDetectImageFormatEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader21autoDetectImageFormatEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader26setDecideFormatFromContentEb
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader26setDecideFormatFromContentEb )( void *scorep_libwrap_arg_this, bool ignored )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader26setDecideFormatFromContentEb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader26setDecideFormatFromContentEb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader26setDecideFormatFromContentEb, ( scorep_libwrap_arg_this, ignored ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader26setDecideFormatFromContentEb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader23decideFormatFromContentEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader23decideFormatFromContentEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader23decideFormatFromContentEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader23decideFormatFromContentEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader23decideFormatFromContentEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader23decideFormatFromContentEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader9setDeviceEP9QIODevice
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader9setDeviceEP9QIODevice )( void *scorep_libwrap_arg_this, QIODevice * device )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader9setDeviceEP9QIODevice );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader9setDeviceEP9QIODevice );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader9setDeviceEP9QIODevice, ( scorep_libwrap_arg_this, device ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader9setDeviceEP9QIODevice );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader6deviceEv
QIODevice *
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader6deviceEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader6deviceEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader6deviceEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QIODevice * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader6deviceEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader6deviceEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader11setFileNameERK7QString
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader11setFileNameERK7QString )( void *scorep_libwrap_arg_this, const QString & fileName )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader11setFileNameERK7QString );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader11setFileNameERK7QString );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader11setFileNameERK7QString, ( scorep_libwrap_arg_this, fileName ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader11setFileNameERK7QString );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader8fileNameEv
QString
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader8fileNameEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader8fileNameEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader8fileNameEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QString scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader8fileNameEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader8fileNameEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader4sizeEv
QSize
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader4sizeEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader4sizeEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader4sizeEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QSize scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader4sizeEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader4sizeEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader11imageFormatEv
QImage::Format
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader11imageFormatEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader11imageFormatEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader11imageFormatEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage::Format scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader11imageFormatEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader11imageFormatEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader8textKeysEv
QStringList
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader8textKeysEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader8textKeysEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader8textKeysEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QStringList scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader8textKeysEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader8textKeysEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader4textERK7QString
QString
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader4textERK7QString )( void *scorep_libwrap_arg_this, const QString & key )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader4textERK7QString );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader4textERK7QString );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QString scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader4textERK7QString, ( scorep_libwrap_arg_this, key ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader4textERK7QString );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader11setClipRectERK5QRect
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader11setClipRectERK5QRect )( void *scorep_libwrap_arg_this, const QRect & rect )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader11setClipRectERK5QRect );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader11setClipRectERK5QRect );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader11setClipRectERK5QRect, ( scorep_libwrap_arg_this, rect ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader11setClipRectERK5QRect );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader8clipRectEv
QRect
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader8clipRectEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader8clipRectEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader8clipRectEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QRect scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader8clipRectEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader8clipRectEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader13setScaledSizeERK5QSize
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader13setScaledSizeERK5QSize )( void *scorep_libwrap_arg_this, const QSize & size )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader13setScaledSizeERK5QSize );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader13setScaledSizeERK5QSize );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader13setScaledSizeERK5QSize, ( scorep_libwrap_arg_this, size ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader13setScaledSizeERK5QSize );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader10scaledSizeEv
QSize
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader10scaledSizeEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader10scaledSizeEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader10scaledSizeEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QSize scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader10scaledSizeEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader10scaledSizeEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader10setQualityEi
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader10setQualityEi )( void *scorep_libwrap_arg_this, int quality )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader10setQualityEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader10setQualityEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader10setQualityEi, ( scorep_libwrap_arg_this, quality ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader10setQualityEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader7qualityEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader7qualityEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader7qualityEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader7qualityEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader7qualityEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader7qualityEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader17setScaledClipRectERK5QRect
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader17setScaledClipRectERK5QRect )( void *scorep_libwrap_arg_this, const QRect & rect )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader17setScaledClipRectERK5QRect );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader17setScaledClipRectERK5QRect );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader17setScaledClipRectERK5QRect, ( scorep_libwrap_arg_this, rect ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader17setScaledClipRectERK5QRect );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader14scaledClipRectEv
QRect
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader14scaledClipRectEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader14scaledClipRectEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader14scaledClipRectEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QRect scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader14scaledClipRectEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader14scaledClipRectEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader18setBackgroundColorERK6QColor
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader18setBackgroundColorERK6QColor )( void *scorep_libwrap_arg_this, const QColor & color )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader18setBackgroundColorERK6QColor );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader18setBackgroundColorERK6QColor );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader18setBackgroundColorERK6QColor, ( scorep_libwrap_arg_this, color ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader18setBackgroundColorERK6QColor );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader15backgroundColorEv
QColor
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader15backgroundColorEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader15backgroundColorEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader15backgroundColorEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QColor scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader15backgroundColorEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader15backgroundColorEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader17supportsAnimationEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader17supportsAnimationEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader17supportsAnimationEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader17supportsAnimationEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader17supportsAnimationEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader17supportsAnimationEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader14transformationEv
QImageIOHandler::Transformations
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader14transformationEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader14transformationEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader14transformationEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImageIOHandler::Transformations scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader14transformationEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader14transformationEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader16setAutoTransformEb
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader16setAutoTransformEb )( void *scorep_libwrap_arg_this, bool enabled )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader16setAutoTransformEb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader16setAutoTransformEb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader16setAutoTransformEb, ( scorep_libwrap_arg_this, enabled ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader16setAutoTransformEb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader13autoTransformEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader13autoTransformEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader13autoTransformEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader13autoTransformEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader13autoTransformEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader13autoTransformEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader8setGammaEf
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader8setGammaEf )( void *scorep_libwrap_arg_this, float gamma )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader8setGammaEf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader8setGammaEf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader8setGammaEf, ( scorep_libwrap_arg_this, gamma ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader8setGammaEf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageReader5gammaEv
float
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader5gammaEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader5gammaEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader5gammaEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    float scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader5gammaEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader5gammaEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader7subTypeEv
QByteArray
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader7subTypeEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader7subTypeEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader7subTypeEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QByteArray scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader7subTypeEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader7subTypeEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader17supportedSubTypesEv
QList<QByteArray>
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader17supportedSubTypesEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader17supportedSubTypesEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader17supportedSubTypesEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QList<QByteArray> scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader17supportedSubTypesEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader17supportedSubTypesEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader7canReadEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader7canReadEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader7canReadEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader7canReadEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader7canReadEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader7canReadEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader4readEv
QImage
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader4readEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader4readEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader4readEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImage scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader4readEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader4readEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader4readEP6QImage
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader4readEP6QImage )( void *scorep_libwrap_arg_this, QImage * image )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader4readEP6QImage );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader4readEP6QImage );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader4readEP6QImage, ( scorep_libwrap_arg_this, image ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader4readEP6QImage );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader15jumpToNextImageEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader15jumpToNextImageEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader15jumpToNextImageEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader15jumpToNextImageEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader15jumpToNextImageEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader15jumpToNextImageEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader11jumpToImageEi
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader11jumpToImageEi )( void *scorep_libwrap_arg_this, int imageNumber )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader11jumpToImageEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader11jumpToImageEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader11jumpToImageEi, ( scorep_libwrap_arg_this, imageNumber ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader11jumpToImageEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader9loopCountEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader9loopCountEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader9loopCountEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader9loopCountEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader9loopCountEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader9loopCountEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader10imageCountEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader10imageCountEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader10imageCountEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader10imageCountEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader10imageCountEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader10imageCountEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader14nextImageDelayEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader14nextImageDelayEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader14nextImageDelayEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader14nextImageDelayEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader14nextImageDelayEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader14nextImageDelayEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader18currentImageNumberEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader18currentImageNumberEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader18currentImageNumberEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader18currentImageNumberEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader18currentImageNumberEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader18currentImageNumberEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader16currentImageRectEv
QRect
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader16currentImageRectEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader16currentImageRectEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader16currentImageRectEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QRect scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader16currentImageRectEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader16currentImageRectEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader5errorEv
QImageReader::ImageReaderError
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader5errorEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader5errorEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader5errorEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImageReader::ImageReaderError scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader5errorEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader5errorEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader11errorStringEv
QString
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader11errorStringEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader11errorStringEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader11errorStringEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QString scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader11errorStringEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader11errorStringEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageReader14supportsOptionEN15QImageIOHandler11ImageOptionE
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageReader14supportsOptionEN15QImageIOHandler11ImageOptionE )( void *scorep_libwrap_arg_this, QImageIOHandler::ImageOption option )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageReader14supportsOptionEN15QImageIOHandler11ImageOptionE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageReader14supportsOptionEN15QImageIOHandler11ImageOptionE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageReader14supportsOptionEN15QImageIOHandler11ImageOptionE, ( scorep_libwrap_arg_this, option ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageReader14supportsOptionEN15QImageIOHandler11ImageOptionE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader11imageFormatERK7QString
QByteArray
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader11imageFormatERK7QString )( const QString & fileName )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader11imageFormatERK7QString );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader11imageFormatERK7QString );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QByteArray scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader11imageFormatERK7QString, ( fileName ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader11imageFormatERK7QString );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader11imageFormatEP9QIODevice
QByteArray
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader11imageFormatEP9QIODevice )( QIODevice * device )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader11imageFormatEP9QIODevice );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader11imageFormatEP9QIODevice );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QByteArray scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader11imageFormatEP9QIODevice, ( device ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader11imageFormatEP9QIODevice );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader21supportedImageFormatsEv
QList<QByteArray>
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader21supportedImageFormatsEv )( void )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader21supportedImageFormatsEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader21supportedImageFormatsEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QList<QByteArray> scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader21supportedImageFormatsEv, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader21supportedImageFormatsEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageReader18supportedMimeTypesEv
QList<QByteArray>
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageReader18supportedMimeTypesEv )( void )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageReader18supportedMimeTypesEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageReader18supportedMimeTypesEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QList<QByteArray> scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageReader18supportedMimeTypesEv, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageReader18supportedMimeTypesEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriterC2Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriterC2Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriterC2Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriterC2Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriterC2Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriterC2Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageWriterC1Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriterC1Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriterC1Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriterC1Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriterC1Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriterC1Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageWriterC2EP9QIODeviceRK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriterC2EP9QIODeviceRK10QByteArray )( void *scorep_libwrap_arg_this, QIODevice * device, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriterC2EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriterC2EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriterC2EP9QIODeviceRK10QByteArray, ( scorep_libwrap_arg_this, device, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriterC2EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageWriterC1EP9QIODeviceRK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriterC1EP9QIODeviceRK10QByteArray )( void *scorep_libwrap_arg_this, QIODevice * device, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriterC1EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriterC1EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriterC1EP9QIODeviceRK10QByteArray, ( scorep_libwrap_arg_this, device, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriterC1EP9QIODeviceRK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageWriterC2ERK7QStringRK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriterC2ERK7QStringRK10QByteArray )( void *scorep_libwrap_arg_this, const QString & fileName, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriterC2ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriterC2ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriterC2ERK7QStringRK10QByteArray, ( scorep_libwrap_arg_this, fileName, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriterC2ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageWriterC1ERK7QStringRK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriterC1ERK7QStringRK10QByteArray )( void *scorep_libwrap_arg_this, const QString & fileName, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriterC1ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriterC1ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriterC1ERK7QStringRK10QByteArray, ( scorep_libwrap_arg_this, fileName, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriterC1ERK7QStringRK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageWriterD2Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriterD2Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriterD2Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriterD2Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriterD2Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriterD2Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageWriterD1Ev
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriterD1Ev )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriterD1Ev );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriterD1Ev );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriterD1Ev, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriterD1Ev );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageWriter9setFormatERK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter9setFormatERK10QByteArray )( void *scorep_libwrap_arg_this, const QByteArray & format )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter9setFormatERK10QByteArray, ( scorep_libwrap_arg_this, format ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter9setFormatERK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter6formatEv
QByteArray
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter6formatEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter6formatEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter6formatEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QByteArray scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter6formatEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter6formatEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter9setDeviceEP9QIODevice
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter9setDeviceEP9QIODevice )( void *scorep_libwrap_arg_this, QIODevice * device )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter9setDeviceEP9QIODevice );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter9setDeviceEP9QIODevice );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter9setDeviceEP9QIODevice, ( scorep_libwrap_arg_this, device ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter9setDeviceEP9QIODevice );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter6deviceEv
QIODevice *
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter6deviceEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter6deviceEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter6deviceEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QIODevice * scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter6deviceEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter6deviceEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter11setFileNameERK7QString
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter11setFileNameERK7QString )( void *scorep_libwrap_arg_this, const QString & fileName )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter11setFileNameERK7QString );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter11setFileNameERK7QString );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter11setFileNameERK7QString, ( scorep_libwrap_arg_this, fileName ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter11setFileNameERK7QString );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter8fileNameEv
QString
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter8fileNameEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter8fileNameEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter8fileNameEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QString scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter8fileNameEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter8fileNameEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter10setQualityEi
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter10setQualityEi )( void *scorep_libwrap_arg_this, int quality )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter10setQualityEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter10setQualityEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter10setQualityEi, ( scorep_libwrap_arg_this, quality ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter10setQualityEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter7qualityEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter7qualityEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter7qualityEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter7qualityEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter7qualityEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter7qualityEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter14setCompressionEi
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter14setCompressionEi )( void *scorep_libwrap_arg_this, int compression )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter14setCompressionEi );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter14setCompressionEi );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter14setCompressionEi, ( scorep_libwrap_arg_this, compression ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter14setCompressionEi );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter11compressionEv
int
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter11compressionEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter11compressionEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter11compressionEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    int scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter11compressionEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter11compressionEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter8setGammaEf
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter8setGammaEf )( void *scorep_libwrap_arg_this, float gamma )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter8setGammaEf );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter8setGammaEf );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter8setGammaEf, ( scorep_libwrap_arg_this, gamma ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter8setGammaEf );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter5gammaEv
float
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter5gammaEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter5gammaEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter5gammaEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    float scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter5gammaEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter5gammaEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter10setSubTypeERK10QByteArray
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter10setSubTypeERK10QByteArray )( void *scorep_libwrap_arg_this, const QByteArray & type )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter10setSubTypeERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter10setSubTypeERK10QByteArray );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter10setSubTypeERK10QByteArray, ( scorep_libwrap_arg_this, type ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter10setSubTypeERK10QByteArray );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter7subTypeEv
QByteArray
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter7subTypeEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter7subTypeEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter7subTypeEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QByteArray scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter7subTypeEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter7subTypeEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageWriter17supportedSubTypesEv
QList<QByteArray>
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter17supportedSubTypesEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter17supportedSubTypesEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter17supportedSubTypesEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QList<QByteArray> scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter17supportedSubTypesEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter17supportedSubTypesEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter17setOptimizedWriteEb
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter17setOptimizedWriteEb )( void *scorep_libwrap_arg_this, bool optimize )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter17setOptimizedWriteEb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter17setOptimizedWriteEb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter17setOptimizedWriteEb, ( scorep_libwrap_arg_this, optimize ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter17setOptimizedWriteEb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter14optimizedWriteEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter14optimizedWriteEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter14optimizedWriteEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter14optimizedWriteEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter14optimizedWriteEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter14optimizedWriteEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter23setProgressiveScanWriteEb
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter23setProgressiveScanWriteEb )( void *scorep_libwrap_arg_this, bool progressive )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter23setProgressiveScanWriteEb );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter23setProgressiveScanWriteEb );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter23setProgressiveScanWriteEb, ( scorep_libwrap_arg_this, progressive ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter23setProgressiveScanWriteEb );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter20progressiveScanWriteEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter20progressiveScanWriteEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter20progressiveScanWriteEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter20progressiveScanWriteEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter20progressiveScanWriteEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter20progressiveScanWriteEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageWriter14transformationEv
QImageIOHandler::Transformations
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter14transformationEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter14transformationEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter14transformationEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImageIOHandler::Transformations scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter14transformationEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter14transformationEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter17setTransformationE6QFlagsIN15QImageIOHandler14TransformationEE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter17setTransformationE6QFlagsIN15QImageIOHandler14TransformationEE )( void *scorep_libwrap_arg_this, QImageIOHandler::Transformations orientation )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter17setTransformationE6QFlagsIN15QImageIOHandler14TransformationEE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter17setTransformationE6QFlagsIN15QImageIOHandler14TransformationEE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter17setTransformationE6QFlagsIN15QImageIOHandler14TransformationEE, ( scorep_libwrap_arg_this, orientation ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter17setTransformationE6QFlagsIN15QImageIOHandler14TransformationEE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QImageWriter14setDescriptionERK7QString
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter14setDescriptionERK7QString )( void *scorep_libwrap_arg_this, const QString & description )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter14setDescriptionERK7QString );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter14setDescriptionERK7QString );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter14setDescriptionERK7QString, ( scorep_libwrap_arg_this, description ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter14setDescriptionERK7QString );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter11descriptionEv
QString
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter11descriptionEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter11descriptionEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter11descriptionEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QString scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter11descriptionEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter11descriptionEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter7setTextERK7QStringS2_
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter7setTextERK7QStringS2_ )( void *scorep_libwrap_arg_this, const QString & key, const QString & text )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter7setTextERK7QStringS2_ );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter7setTextERK7QStringS2_ );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter7setTextERK7QStringS2_, ( scorep_libwrap_arg_this, key, text ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter7setTextERK7QStringS2_ );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZNK12QImageWriter8canWriteEv
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter8canWriteEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter8canWriteEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter8canWriteEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter8canWriteEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter8canWriteEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter5writeERK6QImage
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter5writeERK6QImage )( void *scorep_libwrap_arg_this, const QImage & image )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter5writeERK6QImage );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter5writeERK6QImage );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter5writeERK6QImage, ( scorep_libwrap_arg_this, image ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter5writeERK6QImage );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageWriter5errorEv
QImageWriter::ImageWriterError
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter5errorEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter5errorEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter5errorEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QImageWriter::ImageWriterError scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter5errorEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter5errorEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageWriter11errorStringEv
QString
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter11errorStringEv )( void *scorep_libwrap_arg_this )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter11errorStringEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter11errorStringEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QString scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter11errorStringEv, ( scorep_libwrap_arg_this ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter11errorStringEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZNK12QImageWriter14supportsOptionEN15QImageIOHandler11ImageOptionE
bool
SCOREP_LIBWRAP_FUNC_NAME( _ZNK12QImageWriter14supportsOptionEN15QImageIOHandler11ImageOptionE )( void *scorep_libwrap_arg_this, QImageIOHandler::ImageOption option )
{
    LIBWRAP_EARLY_INIT( _ZNK12QImageWriter14supportsOptionEN15QImageIOHandler11ImageOptionE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZNK12QImageWriter14supportsOptionEN15QImageIOHandler11ImageOptionE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    bool scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZNK12QImageWriter14supportsOptionEN15QImageIOHandler11ImageOptionE, ( scorep_libwrap_arg_this, option ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZNK12QImageWriter14supportsOptionEN15QImageIOHandler11ImageOptionE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter21supportedImageFormatsEv
QList<QByteArray>
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter21supportedImageFormatsEv )( void )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter21supportedImageFormatsEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter21supportedImageFormatsEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QList<QByteArray> scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter21supportedImageFormatsEv, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter21supportedImageFormatsEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN12QImageWriter18supportedMimeTypesEv
QList<QByteArray>
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QImageWriter18supportedMimeTypesEv )( void )
{
    LIBWRAP_EARLY_INIT( _ZN12QImageWriter18supportedMimeTypesEv );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QImageWriter18supportedMimeTypesEv );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    QList<QByteArray> scorep_libwrap_var_ret = SCOREP_LIBWRAP_FUNC_CALL( _ZN12QImageWriter18supportedMimeTypesEv, (  ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QImageWriter18supportedMimeTypesEv );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
    return scorep_libwrap_var_ret;
}

#undef _ZN6QMovie5errorEN12QImageReader16ImageReaderErrorE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QMovie5errorEN12QImageReader16ImageReaderErrorE )( void *scorep_libwrap_arg_this, QImageReader::ImageReaderError error )
{
    LIBWRAP_EARLY_INIT( _ZN6QMovie5errorEN12QImageReader16ImageReaderErrorE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QMovie5errorEN12QImageReader16ImageReaderErrorE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QMovie5errorEN12QImageReader16ImageReaderErrorE, ( scorep_libwrap_arg_this, error ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QMovie5errorEN12QImageReader16ImageReaderErrorE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QBrushC2ERK6QImage
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QBrushC2ERK6QImage )( void *scorep_libwrap_arg_this, const QImage & image )
{
    LIBWRAP_EARLY_INIT( _ZN6QBrushC2ERK6QImage );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QBrushC2ERK6QImage );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QBrushC2ERK6QImage, ( scorep_libwrap_arg_this, image ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QBrushC2ERK6QImage );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QBrushC1ERK6QImage
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QBrushC1ERK6QImage )( void *scorep_libwrap_arg_this, const QImage & image )
{
    LIBWRAP_EARLY_INIT( _ZN6QBrushC1ERK6QImage );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QBrushC1ERK6QImage );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QBrushC1ERK6QImage, ( scorep_libwrap_arg_this, image ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QBrushC1ERK6QImage );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN6QBrush15setTextureImageERK6QImage
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN6QBrush15setTextureImageERK6QImage )( void *scorep_libwrap_arg_this, const QImage & image )
{
    LIBWRAP_EARLY_INIT( _ZN6QBrush15setTextureImageERK6QImage );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN6QBrush15setTextureImageERK6QImage );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN6QBrush15setTextureImageERK6QImage, ( scorep_libwrap_arg_this, image ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN6QBrush15setTextureImageERK6QImage );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN10QClipboard8setImageERK6QImageNS_4ModeE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN10QClipboard8setImageERK6QImageNS_4ModeE )( void *scorep_libwrap_arg_this, const QImage & scorep_libwrap_arg_1, QClipboard::Mode mode )
{
    LIBWRAP_EARLY_INIT( _ZN10QClipboard8setImageERK6QImageNS_4ModeE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN10QClipboard8setImageERK6QImageNS_4ModeE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN10QClipboard8setImageERK6QImageNS_4ModeE, ( scorep_libwrap_arg_this, scorep_libwrap_arg_1, mode ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN10QClipboard8setImageERK6QImageNS_4ModeE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN8QPainter9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN8QPainter9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE )( void *scorep_libwrap_arg_this, const QRectF & targetRect, const QImage & image, const QRectF & sourceRect, Qt::ImageConversionFlags flags )
{
    LIBWRAP_EARLY_INIT( _ZN8QPainter9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN8QPainter9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN8QPainter9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE, ( scorep_libwrap_arg_this, targetRect, image, sourceRect, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN8QPainter9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN8QPainter9drawImageERK7QPointFRK6QImage
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN8QPainter9drawImageERK7QPointFRK6QImage )( void *scorep_libwrap_arg_this, const QPointF & p, const QImage & image )
{
    LIBWRAP_EARLY_INIT( _ZN8QPainter9drawImageERK7QPointFRK6QImage );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN8QPainter9drawImageERK7QPointFRK6QImage );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN8QPainter9drawImageERK7QPointFRK6QImage, ( scorep_libwrap_arg_this, p, image ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN8QPainter9drawImageERK7QPointFRK6QImage );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN12QPaintEngine9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN12QPaintEngine9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE )( void *scorep_libwrap_arg_this, const QRectF & r, const QImage & pm, const QRectF & sr, Qt::ImageConversionFlags flags )
{
    LIBWRAP_EARLY_INIT( _ZN12QPaintEngine9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN12QPaintEngine9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN12QPaintEngine9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE, ( scorep_libwrap_arg_this, r, pm, sr, flags ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN12QPaintEngine9drawImageERK6QRectFRK6QImageS2_6QFlagsIN2Qt19ImageConversionFlagEE );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#undef _ZN11QTextCursor11insertImageERK6QImageRK7QString
void
SCOREP_LIBWRAP_FUNC_NAME( _ZN11QTextCursor11insertImageERK6QImageRK7QString )( void *scorep_libwrap_arg_this, const QImage & image, const QString & name )
{
    LIBWRAP_EARLY_INIT( _ZN11QTextCursor11insertImageERK6QImageRK7QString );
    SCOREP_LIBWRAP_ENTER_MEASUREMENT();
    SCOREP_LIBWRAP_INIT( libwrap_qimage_handle,
                         libwrap_qimage_attributes );
    SCOREP_LIBWRAP_FUNC_ENTER( _ZN11QTextCursor11insertImageERK6QImageRK7QString );
    SCOREP_LIBWRAP_ENTER_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_CALL( _ZN11QTextCursor11insertImageERK6QImageRK7QString, ( scorep_libwrap_arg_this, image, name ) );
    SCOREP_LIBWRAP_EXIT_WRAPPED_REGION();
    SCOREP_LIBWRAP_FUNC_EXIT( _ZN11QTextCursor11insertImageERK6QImageRK7QString );
    SCOREP_LIBWRAP_EXIT_MEASUREMENT();
}

#ifdef __cplusplus
}
#endif
