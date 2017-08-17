# 1 "libwrap.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "libwrap.c"




# 1 "libwrap.h" 1
# 11 "libwrap.h"
# 1 "/opt/cray/fftw/3.3.4.11/x86_64/include/fftw3.h" 1
# 50 "/opt/cray/fftw/3.3.4.11/x86_64/include/fftw3.h"
# 1 "/usr/include/stdio.h" 1 3 4
# 28 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 347 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 353 "/usr/include/sys/cdefs.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 354 "/usr/include/sys/cdefs.h" 2 3 4
# 348 "/usr/include/features.h" 2 3 4
# 371 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4



# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 5 "/usr/include/gnu/stubs.h" 2 3 4




# 1 "/usr/include/gnu/stubs-64.h" 1 3 4
# 10 "/usr/include/gnu/stubs.h" 2 3 4
# 372 "/usr/include/features.h" 2 3 4
# 29 "/usr/include/stdio.h" 2 3 4





# 1 "/opt/gcc/4.9.3/snos/lib/gcc/x86_64-suse-linux/4.9.3/include/stddef.h" 1 3 4
# 212 "/opt/gcc/4.9.3/snos/lib/gcc/x86_64-suse-linux/4.9.3/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 35 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
# 131 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 132 "/usr/include/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;

typedef long int __ssize_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;
# 37 "/usr/include/stdio.h" 2 3 4
# 45 "/usr/include/stdio.h" 3 4
struct _IO_FILE;



typedef struct _IO_FILE FILE;





# 65 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 75 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/opt/gcc/4.9.3/snos/lib/gcc/x86_64-suse-linux/4.9.3/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4




# 1 "/usr/include/wchar.h" 1 3 4
# 83 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 53 "/usr/include/_G_config.h" 3 4
typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/opt/gcc/4.9.3/snos/lib/gcc/x86_64-suse-linux/4.9.3/include/stdarg.h" 1 3 4
# 40 "/opt/gcc/4.9.3/snos/lib/gcc/x86_64-suse-linux/4.9.3/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 170 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 180 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 203 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 271 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 319 "/usr/include/libio.h" 3 4
  __off64_t _offset;
# 328 "/usr/include/libio.h" 3 4
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;

  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 364 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 416 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 460 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__));

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__));
# 490 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__));
# 76 "/usr/include/stdio.h" 2 3 4
# 89 "/usr/include/stdio.h" 3 4


typedef _G_fpos_t fpos_t;




# 141 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 142 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;









extern int remove (__const char *__filename) __attribute__ ((__nothrow__));

extern int rename (__const char *__old, __const char *__new) __attribute__ ((__nothrow__));




extern int renameat (int __oldfd, __const char *__old, int __newfd,
       __const char *__new) __attribute__ ((__nothrow__));








extern FILE *tmpfile (void) ;
# 188 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__)) ;
# 206 "/usr/include/stdio.h" 3 4
extern char *tempnam (__const char *__dir, __const char *__pfx)
     __attribute__ ((__nothrow__)) __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 231 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 245 "/usr/include/stdio.h" 3 4






extern FILE *fopen (__const char *__restrict __filename,
      __const char *__restrict __modes) ;




extern FILE *freopen (__const char *__restrict __filename,
        __const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 274 "/usr/include/stdio.h" 3 4

# 285 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, __const char *__modes) __attribute__ ((__nothrow__)) ;
# 298 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes)
  __attribute__ ((__nothrow__)) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__)) ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__));








extern int fprintf (FILE *__restrict __stream,
      __const char *__restrict __format, ...);




extern int printf (__const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      __const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       __const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

# 396 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, __const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE *__restrict __stream,
     __const char *__restrict __format, ...) ;




extern int scanf (__const char *__restrict __format, ...) ;

extern int sscanf (__const char *__restrict __s,
     __const char *__restrict __format, ...) __attribute__ ((__nothrow__));
# 427 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (__const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (__const char *__restrict __s, __const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__))

                      ;
# 447 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (__const char *__restrict __s,
      __const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 478 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (__const char *__restrict __s, __const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 506 "/usr/include/stdio.h" 3 4









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 534 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 545 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 578 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;






extern char *gets (char *__s) ;

# 640 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;








extern int fputs (__const char *__restrict __s, FILE *__restrict __stream);





extern int puts (__const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s) ;

# 712 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream) ;








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);

# 748 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 767 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, __const fpos_t *__pos);
# 790 "/usr/include/stdio.h" 3 4

# 799 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__)) ;




extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;








extern void perror (__const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern __const char *__const sys_errlist[];
# 829 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__)) ;
# 848 "/usr/include/stdio.h" 3 4
extern FILE *popen (__const char *__command, __const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__));
# 888 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__));
# 918 "/usr/include/stdio.h" 3 4

# 51 "/opt/cray/fftw/3.3.4.11/x86_64/include/fftw3.h" 2
# 89 "/opt/cray/fftw/3.3.4.11/x86_64/include/fftw3.h"
enum fftw_r2r_kind_do_not_use_me {
     FFTW_R2HC=0, FFTW_HC2R=1, FFTW_DHT=2,
     FFTW_REDFT00=3, FFTW_REDFT01=4, FFTW_REDFT10=5, FFTW_REDFT11=6,
     FFTW_RODFT00=7, FFTW_RODFT01=8, FFTW_RODFT10=9, FFTW_RODFT11=10
};

struct fftw_iodim_do_not_use_me {
     int n;
     int is;
     int os;
};

# 1 "/opt/gcc/4.9.3/snos/lib/gcc/x86_64-suse-linux/4.9.3/include/stddef.h" 1 3 4
# 147 "/opt/gcc/4.9.3/snos/lib/gcc/x86_64-suse-linux/4.9.3/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 324 "/opt/gcc/4.9.3/snos/lib/gcc/x86_64-suse-linux/4.9.3/include/stddef.h" 3 4
typedef int wchar_t;
# 102 "/opt/cray/fftw/3.3.4.11/x86_64/include/fftw3.h" 2
struct fftw_iodim64_do_not_use_me {
     ptrdiff_t n;
     ptrdiff_t is;
     ptrdiff_t os;
};

typedef void (*fftw_write_char_func_do_not_use_me)(char c, void *);
typedef int (*fftw_read_char_func_do_not_use_me)(void *);
# 355 "/opt/cray/fftw/3.3.4.11/x86_64/include/fftw3.h"
typedef double fftw_complex[2]; typedef struct fftw_plan_s *fftw_plan; typedef struct fftw_iodim_do_not_use_me fftw_iodim; typedef struct fftw_iodim64_do_not_use_me fftw_iodim64; typedef enum fftw_r2r_kind_do_not_use_me fftw_r2r_kind; typedef fftw_write_char_func_do_not_use_me fftw_write_char_func; typedef fftw_read_char_func_do_not_use_me fftw_read_char_func; extern void fftw_execute(const fftw_plan p); extern fftw_plan fftw_plan_dft(int rank, const int *n, fftw_complex *in, fftw_complex *out, int sign, unsigned flags); extern fftw_plan fftw_plan_dft_1d(int n, fftw_complex *in, fftw_complex *out, int sign, unsigned flags); extern fftw_plan fftw_plan_dft_2d(int n0, int n1, fftw_complex *in, fftw_complex *out, int sign, unsigned flags); extern fftw_plan fftw_plan_dft_3d(int n0, int n1, int n2, fftw_complex *in, fftw_complex *out, int sign, unsigned flags); extern fftw_plan fftw_plan_many_dft(int rank, const int *n, int howmany, fftw_complex *in, const int *inembed, int istride, int idist, fftw_complex *out, const int *onembed, int ostride, int odist, int sign, unsigned flags); extern fftw_plan fftw_plan_guru_dft(int rank, const fftw_iodim *dims, int howmany_rank, const fftw_iodim *howmany_dims, fftw_complex *in, fftw_complex *out, int sign, unsigned flags); extern fftw_plan fftw_plan_guru_split_dft(int rank, const fftw_iodim *dims, int howmany_rank, const fftw_iodim *howmany_dims, double *ri, double *ii, double *ro, double *io, unsigned flags); extern fftw_plan fftw_plan_guru64_dft(int rank, const fftw_iodim64 *dims, int howmany_rank, const fftw_iodim64 *howmany_dims, fftw_complex *in, fftw_complex *out, int sign, unsigned flags); extern fftw_plan fftw_plan_guru64_split_dft(int rank, const fftw_iodim64 *dims, int howmany_rank, const fftw_iodim64 *howmany_dims, double *ri, double *ii, double *ro, double *io, unsigned flags); extern void fftw_execute_dft(const fftw_plan p, fftw_complex *in, fftw_complex *out); extern void fftw_execute_split_dft(const fftw_plan p, double *ri, double *ii, double *ro, double *io); extern fftw_plan fftw_plan_many_dft_r2c(int rank, const int *n, int howmany, double *in, const int *inembed, int istride, int idist, fftw_complex *out, const int *onembed, int ostride, int odist, unsigned flags); extern fftw_plan fftw_plan_dft_r2c(int rank, const int *n, double *in, fftw_complex *out, unsigned flags); extern fftw_plan fftw_plan_dft_r2c_1d(int n,double *in,fftw_complex *out,unsigned flags); extern fftw_plan fftw_plan_dft_r2c_2d(int n0, int n1, double *in, fftw_complex *out, unsigned flags); extern fftw_plan fftw_plan_dft_r2c_3d(int n0, int n1, int n2, double *in, fftw_complex *out, unsigned flags); extern fftw_plan fftw_plan_many_dft_c2r(int rank, const int *n, int howmany, fftw_complex *in, const int *inembed, int istride, int idist, double *out, const int *onembed, int ostride, int odist, unsigned flags); extern fftw_plan fftw_plan_dft_c2r(int rank, const int *n, fftw_complex *in, double *out, unsigned flags); extern fftw_plan fftw_plan_dft_c2r_1d(int n,fftw_complex *in,double *out,unsigned flags); extern fftw_plan fftw_plan_dft_c2r_2d(int n0, int n1, fftw_complex *in, double *out, unsigned flags); extern fftw_plan fftw_plan_dft_c2r_3d(int n0, int n1, int n2, fftw_complex *in, double *out, unsigned flags); extern fftw_plan fftw_plan_guru_dft_r2c(int rank, const fftw_iodim *dims, int howmany_rank, const fftw_iodim *howmany_dims, double *in, fftw_complex *out, unsigned flags); extern fftw_plan fftw_plan_guru_dft_c2r(int rank, const fftw_iodim *dims, int howmany_rank, const fftw_iodim *howmany_dims, fftw_complex *in, double *out, unsigned flags); extern fftw_plan fftw_plan_guru_split_dft_r2c( int rank, const fftw_iodim *dims, int howmany_rank, const fftw_iodim *howmany_dims, double *in, double *ro, double *io, unsigned flags); extern fftw_plan fftw_plan_guru_split_dft_c2r( int rank, const fftw_iodim *dims, int howmany_rank, const fftw_iodim *howmany_dims, double *ri, double *ii, double *out, unsigned flags); extern fftw_plan fftw_plan_guru64_dft_r2c(int rank, const fftw_iodim64 *dims, int howmany_rank, const fftw_iodim64 *howmany_dims, double *in, fftw_complex *out, unsigned flags); extern fftw_plan fftw_plan_guru64_dft_c2r(int rank, const fftw_iodim64 *dims, int howmany_rank, const fftw_iodim64 *howmany_dims, fftw_complex *in, double *out, unsigned flags); extern fftw_plan fftw_plan_guru64_split_dft_r2c( int rank, const fftw_iodim64 *dims, int howmany_rank, const fftw_iodim64 *howmany_dims, double *in, double *ro, double *io, unsigned flags); extern fftw_plan fftw_plan_guru64_split_dft_c2r( int rank, const fftw_iodim64 *dims, int howmany_rank, const fftw_iodim64 *howmany_dims, double *ri, double *ii, double *out, unsigned flags); extern void fftw_execute_dft_r2c(const fftw_plan p, double *in, fftw_complex *out); extern void fftw_execute_dft_c2r(const fftw_plan p, fftw_complex *in, double *out); extern void fftw_execute_split_dft_r2c(const fftw_plan p, double *in, double *ro, double *io); extern void fftw_execute_split_dft_c2r(const fftw_plan p, double *ri, double *ii, double *out); extern fftw_plan fftw_plan_many_r2r(int rank, const int *n, int howmany, double *in, const int *inembed, int istride, int idist, double *out, const int *onembed, int ostride, int odist, const fftw_r2r_kind *kind, unsigned flags); extern fftw_plan fftw_plan_r2r(int rank, const int *n, double *in, double *out, const fftw_r2r_kind *kind, unsigned flags); extern fftw_plan fftw_plan_r2r_1d(int n, double *in, double *out, fftw_r2r_kind kind, unsigned flags); extern fftw_plan fftw_plan_r2r_2d(int n0, int n1, double *in, double *out, fftw_r2r_kind kind0, fftw_r2r_kind kind1, unsigned flags); extern fftw_plan fftw_plan_r2r_3d(int n0, int n1, int n2, double *in, double *out, fftw_r2r_kind kind0, fftw_r2r_kind kind1, fftw_r2r_kind kind2, unsigned flags); extern fftw_plan fftw_plan_guru_r2r(int rank, const fftw_iodim *dims, int howmany_rank, const fftw_iodim *howmany_dims, double *in, double *out, const fftw_r2r_kind *kind, unsigned flags); extern fftw_plan fftw_plan_guru64_r2r(int rank, const fftw_iodim64 *dims, int howmany_rank, const fftw_iodim64 *howmany_dims, double *in, double *out, const fftw_r2r_kind *kind, unsigned flags); extern void fftw_execute_r2r(const fftw_plan p, double *in, double *out); extern void fftw_destroy_plan(fftw_plan p); extern void fftw_forget_wisdom(void); extern void fftw_cleanup(void); extern void fftw_set_timelimit(double t); extern void fftw_plan_with_nthreads(int nthreads); extern int fftw_init_threads(void); extern void fftw_cleanup_threads(void); extern int fftw_export_wisdom_to_filename(const char *filename); extern void fftw_export_wisdom_to_file(FILE *output_file); extern char *fftw_export_wisdom_to_string(void); extern void fftw_export_wisdom(fftw_write_char_func write_char, void *data); extern int fftw_import_system_wisdom(void); extern int fftw_import_wisdom_from_filename(const char *filename); extern int fftw_import_wisdom_from_file(FILE *input_file); extern int fftw_import_wisdom_from_string(const char *input_string); extern int fftw_import_wisdom(fftw_read_char_func read_char, void *data); extern void fftw_fprint_plan(const fftw_plan p, FILE *output_file); extern void fftw_print_plan(const fftw_plan p); extern char *fftw_sprint_plan(const fftw_plan p); extern void *fftw_malloc(size_t n); extern double *fftw_alloc_real(size_t n); extern fftw_complex *fftw_alloc_complex(size_t n); extern void fftw_free(void *p); extern void fftw_flops(const fftw_plan p, double *add, double *mul, double *fmas); extern double fftw_estimate_cost(const fftw_plan p); extern double fftw_cost(const fftw_plan p); extern int fftw_alignment_of(double *p); extern const char fftw_version[]; extern const char fftw_cc[]; extern const char fftw_codelet_optim[];
typedef float fftwf_complex[2]; typedef struct fftwf_plan_s *fftwf_plan; typedef struct fftw_iodim_do_not_use_me fftwf_iodim; typedef struct fftw_iodim64_do_not_use_me fftwf_iodim64; typedef enum fftw_r2r_kind_do_not_use_me fftwf_r2r_kind; typedef fftw_write_char_func_do_not_use_me fftwf_write_char_func; typedef fftw_read_char_func_do_not_use_me fftwf_read_char_func; extern void fftwf_execute(const fftwf_plan p); extern fftwf_plan fftwf_plan_dft(int rank, const int *n, fftwf_complex *in, fftwf_complex *out, int sign, unsigned flags); extern fftwf_plan fftwf_plan_dft_1d(int n, fftwf_complex *in, fftwf_complex *out, int sign, unsigned flags); extern fftwf_plan fftwf_plan_dft_2d(int n0, int n1, fftwf_complex *in, fftwf_complex *out, int sign, unsigned flags); extern fftwf_plan fftwf_plan_dft_3d(int n0, int n1, int n2, fftwf_complex *in, fftwf_complex *out, int sign, unsigned flags); extern fftwf_plan fftwf_plan_many_dft(int rank, const int *n, int howmany, fftwf_complex *in, const int *inembed, int istride, int idist, fftwf_complex *out, const int *onembed, int ostride, int odist, int sign, unsigned flags); extern fftwf_plan fftwf_plan_guru_dft(int rank, const fftwf_iodim *dims, int howmany_rank, const fftwf_iodim *howmany_dims, fftwf_complex *in, fftwf_complex *out, int sign, unsigned flags); extern fftwf_plan fftwf_plan_guru_split_dft(int rank, const fftwf_iodim *dims, int howmany_rank, const fftwf_iodim *howmany_dims, float *ri, float *ii, float *ro, float *io, unsigned flags); extern fftwf_plan fftwf_plan_guru64_dft(int rank, const fftwf_iodim64 *dims, int howmany_rank, const fftwf_iodim64 *howmany_dims, fftwf_complex *in, fftwf_complex *out, int sign, unsigned flags); extern fftwf_plan fftwf_plan_guru64_split_dft(int rank, const fftwf_iodim64 *dims, int howmany_rank, const fftwf_iodim64 *howmany_dims, float *ri, float *ii, float *ro, float *io, unsigned flags); extern void fftwf_execute_dft(const fftwf_plan p, fftwf_complex *in, fftwf_complex *out); extern void fftwf_execute_split_dft(const fftwf_plan p, float *ri, float *ii, float *ro, float *io); extern fftwf_plan fftwf_plan_many_dft_r2c(int rank, const int *n, int howmany, float *in, const int *inembed, int istride, int idist, fftwf_complex *out, const int *onembed, int ostride, int odist, unsigned flags); extern fftwf_plan fftwf_plan_dft_r2c(int rank, const int *n, float *in, fftwf_complex *out, unsigned flags); extern fftwf_plan fftwf_plan_dft_r2c_1d(int n,float *in,fftwf_complex *out,unsigned flags); extern fftwf_plan fftwf_plan_dft_r2c_2d(int n0, int n1, float *in, fftwf_complex *out, unsigned flags); extern fftwf_plan fftwf_plan_dft_r2c_3d(int n0, int n1, int n2, float *in, fftwf_complex *out, unsigned flags); extern fftwf_plan fftwf_plan_many_dft_c2r(int rank, const int *n, int howmany, fftwf_complex *in, const int *inembed, int istride, int idist, float *out, const int *onembed, int ostride, int odist, unsigned flags); extern fftwf_plan fftwf_plan_dft_c2r(int rank, const int *n, fftwf_complex *in, float *out, unsigned flags); extern fftwf_plan fftwf_plan_dft_c2r_1d(int n,fftwf_complex *in,float *out,unsigned flags); extern fftwf_plan fftwf_plan_dft_c2r_2d(int n0, int n1, fftwf_complex *in, float *out, unsigned flags); extern fftwf_plan fftwf_plan_dft_c2r_3d(int n0, int n1, int n2, fftwf_complex *in, float *out, unsigned flags); extern fftwf_plan fftwf_plan_guru_dft_r2c(int rank, const fftwf_iodim *dims, int howmany_rank, const fftwf_iodim *howmany_dims, float *in, fftwf_complex *out, unsigned flags); extern fftwf_plan fftwf_plan_guru_dft_c2r(int rank, const fftwf_iodim *dims, int howmany_rank, const fftwf_iodim *howmany_dims, fftwf_complex *in, float *out, unsigned flags); extern fftwf_plan fftwf_plan_guru_split_dft_r2c( int rank, const fftwf_iodim *dims, int howmany_rank, const fftwf_iodim *howmany_dims, float *in, float *ro, float *io, unsigned flags); extern fftwf_plan fftwf_plan_guru_split_dft_c2r( int rank, const fftwf_iodim *dims, int howmany_rank, const fftwf_iodim *howmany_dims, float *ri, float *ii, float *out, unsigned flags); extern fftwf_plan fftwf_plan_guru64_dft_r2c(int rank, const fftwf_iodim64 *dims, int howmany_rank, const fftwf_iodim64 *howmany_dims, float *in, fftwf_complex *out, unsigned flags); extern fftwf_plan fftwf_plan_guru64_dft_c2r(int rank, const fftwf_iodim64 *dims, int howmany_rank, const fftwf_iodim64 *howmany_dims, fftwf_complex *in, float *out, unsigned flags); extern fftwf_plan fftwf_plan_guru64_split_dft_r2c( int rank, const fftwf_iodim64 *dims, int howmany_rank, const fftwf_iodim64 *howmany_dims, float *in, float *ro, float *io, unsigned flags); extern fftwf_plan fftwf_plan_guru64_split_dft_c2r( int rank, const fftwf_iodim64 *dims, int howmany_rank, const fftwf_iodim64 *howmany_dims, float *ri, float *ii, float *out, unsigned flags); extern void fftwf_execute_dft_r2c(const fftwf_plan p, float *in, fftwf_complex *out); extern void fftwf_execute_dft_c2r(const fftwf_plan p, fftwf_complex *in, float *out); extern void fftwf_execute_split_dft_r2c(const fftwf_plan p, float *in, float *ro, float *io); extern void fftwf_execute_split_dft_c2r(const fftwf_plan p, float *ri, float *ii, float *out); extern fftwf_plan fftwf_plan_many_r2r(int rank, const int *n, int howmany, float *in, const int *inembed, int istride, int idist, float *out, const int *onembed, int ostride, int odist, const fftwf_r2r_kind *kind, unsigned flags); extern fftwf_plan fftwf_plan_r2r(int rank, const int *n, float *in, float *out, const fftwf_r2r_kind *kind, unsigned flags); extern fftwf_plan fftwf_plan_r2r_1d(int n, float *in, float *out, fftwf_r2r_kind kind, unsigned flags); extern fftwf_plan fftwf_plan_r2r_2d(int n0, int n1, float *in, float *out, fftwf_r2r_kind kind0, fftwf_r2r_kind kind1, unsigned flags); extern fftwf_plan fftwf_plan_r2r_3d(int n0, int n1, int n2, float *in, float *out, fftwf_r2r_kind kind0, fftwf_r2r_kind kind1, fftwf_r2r_kind kind2, unsigned flags); extern fftwf_plan fftwf_plan_guru_r2r(int rank, const fftwf_iodim *dims, int howmany_rank, const fftwf_iodim *howmany_dims, float *in, float *out, const fftwf_r2r_kind *kind, unsigned flags); extern fftwf_plan fftwf_plan_guru64_r2r(int rank, const fftwf_iodim64 *dims, int howmany_rank, const fftwf_iodim64 *howmany_dims, float *in, float *out, const fftwf_r2r_kind *kind, unsigned flags); extern void fftwf_execute_r2r(const fftwf_plan p, float *in, float *out); extern void fftwf_destroy_plan(fftwf_plan p); extern void fftwf_forget_wisdom(void); extern void fftwf_cleanup(void); extern void fftwf_set_timelimit(double t); extern void fftwf_plan_with_nthreads(int nthreads); extern int fftwf_init_threads(void); extern void fftwf_cleanup_threads(void); extern int fftwf_export_wisdom_to_filename(const char *filename); extern void fftwf_export_wisdom_to_file(FILE *output_file); extern char *fftwf_export_wisdom_to_string(void); extern void fftwf_export_wisdom(fftwf_write_char_func write_char, void *data); extern int fftwf_import_system_wisdom(void); extern int fftwf_import_wisdom_from_filename(const char *filename); extern int fftwf_import_wisdom_from_file(FILE *input_file); extern int fftwf_import_wisdom_from_string(const char *input_string); extern int fftwf_import_wisdom(fftwf_read_char_func read_char, void *data); extern void fftwf_fprint_plan(const fftwf_plan p, FILE *output_file); extern void fftwf_print_plan(const fftwf_plan p); extern char *fftwf_sprint_plan(const fftwf_plan p); extern void *fftwf_malloc(size_t n); extern float *fftwf_alloc_real(size_t n); extern fftwf_complex *fftwf_alloc_complex(size_t n); extern void fftwf_free(void *p); extern void fftwf_flops(const fftwf_plan p, double *add, double *mul, double *fmas); extern double fftwf_estimate_cost(const fftwf_plan p); extern double fftwf_cost(const fftwf_plan p); extern int fftwf_alignment_of(float *p); extern const char fftwf_version[]; extern const char fftwf_cc[]; extern const char fftwf_codelet_optim[];
typedef long double fftwl_complex[2]; typedef struct fftwl_plan_s *fftwl_plan; typedef struct fftw_iodim_do_not_use_me fftwl_iodim; typedef struct fftw_iodim64_do_not_use_me fftwl_iodim64; typedef enum fftw_r2r_kind_do_not_use_me fftwl_r2r_kind; typedef fftw_write_char_func_do_not_use_me fftwl_write_char_func; typedef fftw_read_char_func_do_not_use_me fftwl_read_char_func; extern void fftwl_execute(const fftwl_plan p); extern fftwl_plan fftwl_plan_dft(int rank, const int *n, fftwl_complex *in, fftwl_complex *out, int sign, unsigned flags); extern fftwl_plan fftwl_plan_dft_1d(int n, fftwl_complex *in, fftwl_complex *out, int sign, unsigned flags); extern fftwl_plan fftwl_plan_dft_2d(int n0, int n1, fftwl_complex *in, fftwl_complex *out, int sign, unsigned flags); extern fftwl_plan fftwl_plan_dft_3d(int n0, int n1, int n2, fftwl_complex *in, fftwl_complex *out, int sign, unsigned flags); extern fftwl_plan fftwl_plan_many_dft(int rank, const int *n, int howmany, fftwl_complex *in, const int *inembed, int istride, int idist, fftwl_complex *out, const int *onembed, int ostride, int odist, int sign, unsigned flags); extern fftwl_plan fftwl_plan_guru_dft(int rank, const fftwl_iodim *dims, int howmany_rank, const fftwl_iodim *howmany_dims, fftwl_complex *in, fftwl_complex *out, int sign, unsigned flags); extern fftwl_plan fftwl_plan_guru_split_dft(int rank, const fftwl_iodim *dims, int howmany_rank, const fftwl_iodim *howmany_dims, long double *ri, long double *ii, long double *ro, long double *io, unsigned flags); extern fftwl_plan fftwl_plan_guru64_dft(int rank, const fftwl_iodim64 *dims, int howmany_rank, const fftwl_iodim64 *howmany_dims, fftwl_complex *in, fftwl_complex *out, int sign, unsigned flags); extern fftwl_plan fftwl_plan_guru64_split_dft(int rank, const fftwl_iodim64 *dims, int howmany_rank, const fftwl_iodim64 *howmany_dims, long double *ri, long double *ii, long double *ro, long double *io, unsigned flags); extern void fftwl_execute_dft(const fftwl_plan p, fftwl_complex *in, fftwl_complex *out); extern void fftwl_execute_split_dft(const fftwl_plan p, long double *ri, long double *ii, long double *ro, long double *io); extern fftwl_plan fftwl_plan_many_dft_r2c(int rank, const int *n, int howmany, long double *in, const int *inembed, int istride, int idist, fftwl_complex *out, const int *onembed, int ostride, int odist, unsigned flags); extern fftwl_plan fftwl_plan_dft_r2c(int rank, const int *n, long double *in, fftwl_complex *out, unsigned flags); extern fftwl_plan fftwl_plan_dft_r2c_1d(int n,long double *in,fftwl_complex *out,unsigned flags); extern fftwl_plan fftwl_plan_dft_r2c_2d(int n0, int n1, long double *in, fftwl_complex *out, unsigned flags); extern fftwl_plan fftwl_plan_dft_r2c_3d(int n0, int n1, int n2, long double *in, fftwl_complex *out, unsigned flags); extern fftwl_plan fftwl_plan_many_dft_c2r(int rank, const int *n, int howmany, fftwl_complex *in, const int *inembed, int istride, int idist, long double *out, const int *onembed, int ostride, int odist, unsigned flags); extern fftwl_plan fftwl_plan_dft_c2r(int rank, const int *n, fftwl_complex *in, long double *out, unsigned flags); extern fftwl_plan fftwl_plan_dft_c2r_1d(int n,fftwl_complex *in,long double *out,unsigned flags); extern fftwl_plan fftwl_plan_dft_c2r_2d(int n0, int n1, fftwl_complex *in, long double *out, unsigned flags); extern fftwl_plan fftwl_plan_dft_c2r_3d(int n0, int n1, int n2, fftwl_complex *in, long double *out, unsigned flags); extern fftwl_plan fftwl_plan_guru_dft_r2c(int rank, const fftwl_iodim *dims, int howmany_rank, const fftwl_iodim *howmany_dims, long double *in, fftwl_complex *out, unsigned flags); extern fftwl_plan fftwl_plan_guru_dft_c2r(int rank, const fftwl_iodim *dims, int howmany_rank, const fftwl_iodim *howmany_dims, fftwl_complex *in, long double *out, unsigned flags); extern fftwl_plan fftwl_plan_guru_split_dft_r2c( int rank, const fftwl_iodim *dims, int howmany_rank, const fftwl_iodim *howmany_dims, long double *in, long double *ro, long double *io, unsigned flags); extern fftwl_plan fftwl_plan_guru_split_dft_c2r( int rank, const fftwl_iodim *dims, int howmany_rank, const fftwl_iodim *howmany_dims, long double *ri, long double *ii, long double *out, unsigned flags); extern fftwl_plan fftwl_plan_guru64_dft_r2c(int rank, const fftwl_iodim64 *dims, int howmany_rank, const fftwl_iodim64 *howmany_dims, long double *in, fftwl_complex *out, unsigned flags); extern fftwl_plan fftwl_plan_guru64_dft_c2r(int rank, const fftwl_iodim64 *dims, int howmany_rank, const fftwl_iodim64 *howmany_dims, fftwl_complex *in, long double *out, unsigned flags); extern fftwl_plan fftwl_plan_guru64_split_dft_r2c( int rank, const fftwl_iodim64 *dims, int howmany_rank, const fftwl_iodim64 *howmany_dims, long double *in, long double *ro, long double *io, unsigned flags); extern fftwl_plan fftwl_plan_guru64_split_dft_c2r( int rank, const fftwl_iodim64 *dims, int howmany_rank, const fftwl_iodim64 *howmany_dims, long double *ri, long double *ii, long double *out, unsigned flags); extern void fftwl_execute_dft_r2c(const fftwl_plan p, long double *in, fftwl_complex *out); extern void fftwl_execute_dft_c2r(const fftwl_plan p, fftwl_complex *in, long double *out); extern void fftwl_execute_split_dft_r2c(const fftwl_plan p, long double *in, long double *ro, long double *io); extern void fftwl_execute_split_dft_c2r(const fftwl_plan p, long double *ri, long double *ii, long double *out); extern fftwl_plan fftwl_plan_many_r2r(int rank, const int *n, int howmany, long double *in, const int *inembed, int istride, int idist, long double *out, const int *onembed, int ostride, int odist, const fftwl_r2r_kind *kind, unsigned flags); extern fftwl_plan fftwl_plan_r2r(int rank, const int *n, long double *in, long double *out, const fftwl_r2r_kind *kind, unsigned flags); extern fftwl_plan fftwl_plan_r2r_1d(int n, long double *in, long double *out, fftwl_r2r_kind kind, unsigned flags); extern fftwl_plan fftwl_plan_r2r_2d(int n0, int n1, long double *in, long double *out, fftwl_r2r_kind kind0, fftwl_r2r_kind kind1, unsigned flags); extern fftwl_plan fftwl_plan_r2r_3d(int n0, int n1, int n2, long double *in, long double *out, fftwl_r2r_kind kind0, fftwl_r2r_kind kind1, fftwl_r2r_kind kind2, unsigned flags); extern fftwl_plan fftwl_plan_guru_r2r(int rank, const fftwl_iodim *dims, int howmany_rank, const fftwl_iodim *howmany_dims, long double *in, long double *out, const fftwl_r2r_kind *kind, unsigned flags); extern fftwl_plan fftwl_plan_guru64_r2r(int rank, const fftwl_iodim64 *dims, int howmany_rank, const fftwl_iodim64 *howmany_dims, long double *in, long double *out, const fftwl_r2r_kind *kind, unsigned flags); extern void fftwl_execute_r2r(const fftwl_plan p, long double *in, long double *out); extern void fftwl_destroy_plan(fftwl_plan p); extern void fftwl_forget_wisdom(void); extern void fftwl_cleanup(void); extern void fftwl_set_timelimit(double t); extern void fftwl_plan_with_nthreads(int nthreads); extern int fftwl_init_threads(void); extern void fftwl_cleanup_threads(void); extern int fftwl_export_wisdom_to_filename(const char *filename); extern void fftwl_export_wisdom_to_file(FILE *output_file); extern char *fftwl_export_wisdom_to_string(void); extern void fftwl_export_wisdom(fftwl_write_char_func write_char, void *data); extern int fftwl_import_system_wisdom(void); extern int fftwl_import_wisdom_from_filename(const char *filename); extern int fftwl_import_wisdom_from_file(FILE *input_file); extern int fftwl_import_wisdom_from_string(const char *input_string); extern int fftwl_import_wisdom(fftwl_read_char_func read_char, void *data); extern void fftwl_fprint_plan(const fftwl_plan p, FILE *output_file); extern void fftwl_print_plan(const fftwl_plan p); extern char *fftwl_sprint_plan(const fftwl_plan p); extern void *fftwl_malloc(size_t n); extern long double *fftwl_alloc_real(size_t n); extern fftwl_complex *fftwl_alloc_complex(size_t n); extern void fftwl_free(void *p); extern void fftwl_flops(const fftwl_plan p, double *add, double *mul, double *fmas); extern double fftwl_estimate_cost(const fftwl_plan p); extern double fftwl_cost(const fftwl_plan p); extern int fftwl_alignment_of(long double *p); extern const char fftwl_version[]; extern const char fftwl_cc[]; extern const char fftwl_codelet_optim[];
# 373 "/opt/cray/fftw/3.3.4.11/x86_64/include/fftw3.h"
typedef __float128 fftwq_complex[2]; typedef struct fftwq_plan_s *fftwq_plan; typedef struct fftw_iodim_do_not_use_me fftwq_iodim; typedef struct fftw_iodim64_do_not_use_me fftwq_iodim64; typedef enum fftw_r2r_kind_do_not_use_me fftwq_r2r_kind; typedef fftw_write_char_func_do_not_use_me fftwq_write_char_func; typedef fftw_read_char_func_do_not_use_me fftwq_read_char_func; extern void fftwq_execute(const fftwq_plan p); extern fftwq_plan fftwq_plan_dft(int rank, const int *n, fftwq_complex *in, fftwq_complex *out, int sign, unsigned flags); extern fftwq_plan fftwq_plan_dft_1d(int n, fftwq_complex *in, fftwq_complex *out, int sign, unsigned flags); extern fftwq_plan fftwq_plan_dft_2d(int n0, int n1, fftwq_complex *in, fftwq_complex *out, int sign, unsigned flags); extern fftwq_plan fftwq_plan_dft_3d(int n0, int n1, int n2, fftwq_complex *in, fftwq_complex *out, int sign, unsigned flags); extern fftwq_plan fftwq_plan_many_dft(int rank, const int *n, int howmany, fftwq_complex *in, const int *inembed, int istride, int idist, fftwq_complex *out, const int *onembed, int ostride, int odist, int sign, unsigned flags); extern fftwq_plan fftwq_plan_guru_dft(int rank, const fftwq_iodim *dims, int howmany_rank, const fftwq_iodim *howmany_dims, fftwq_complex *in, fftwq_complex *out, int sign, unsigned flags); extern fftwq_plan fftwq_plan_guru_split_dft(int rank, const fftwq_iodim *dims, int howmany_rank, const fftwq_iodim *howmany_dims, __float128 *ri, __float128 *ii, __float128 *ro, __float128 *io, unsigned flags); extern fftwq_plan fftwq_plan_guru64_dft(int rank, const fftwq_iodim64 *dims, int howmany_rank, const fftwq_iodim64 *howmany_dims, fftwq_complex *in, fftwq_complex *out, int sign, unsigned flags); extern fftwq_plan fftwq_plan_guru64_split_dft(int rank, const fftwq_iodim64 *dims, int howmany_rank, const fftwq_iodim64 *howmany_dims, __float128 *ri, __float128 *ii, __float128 *ro, __float128 *io, unsigned flags); extern void fftwq_execute_dft(const fftwq_plan p, fftwq_complex *in, fftwq_complex *out); extern void fftwq_execute_split_dft(const fftwq_plan p, __float128 *ri, __float128 *ii, __float128 *ro, __float128 *io); extern fftwq_plan fftwq_plan_many_dft_r2c(int rank, const int *n, int howmany, __float128 *in, const int *inembed, int istride, int idist, fftwq_complex *out, const int *onembed, int ostride, int odist, unsigned flags); extern fftwq_plan fftwq_plan_dft_r2c(int rank, const int *n, __float128 *in, fftwq_complex *out, unsigned flags); extern fftwq_plan fftwq_plan_dft_r2c_1d(int n,__float128 *in,fftwq_complex *out,unsigned flags); extern fftwq_plan fftwq_plan_dft_r2c_2d(int n0, int n1, __float128 *in, fftwq_complex *out, unsigned flags); extern fftwq_plan fftwq_plan_dft_r2c_3d(int n0, int n1, int n2, __float128 *in, fftwq_complex *out, unsigned flags); extern fftwq_plan fftwq_plan_many_dft_c2r(int rank, const int *n, int howmany, fftwq_complex *in, const int *inembed, int istride, int idist, __float128 *out, const int *onembed, int ostride, int odist, unsigned flags); extern fftwq_plan fftwq_plan_dft_c2r(int rank, const int *n, fftwq_complex *in, __float128 *out, unsigned flags); extern fftwq_plan fftwq_plan_dft_c2r_1d(int n,fftwq_complex *in,__float128 *out,unsigned flags); extern fftwq_plan fftwq_plan_dft_c2r_2d(int n0, int n1, fftwq_complex *in, __float128 *out, unsigned flags); extern fftwq_plan fftwq_plan_dft_c2r_3d(int n0, int n1, int n2, fftwq_complex *in, __float128 *out, unsigned flags); extern fftwq_plan fftwq_plan_guru_dft_r2c(int rank, const fftwq_iodim *dims, int howmany_rank, const fftwq_iodim *howmany_dims, __float128 *in, fftwq_complex *out, unsigned flags); extern fftwq_plan fftwq_plan_guru_dft_c2r(int rank, const fftwq_iodim *dims, int howmany_rank, const fftwq_iodim *howmany_dims, fftwq_complex *in, __float128 *out, unsigned flags); extern fftwq_plan fftwq_plan_guru_split_dft_r2c( int rank, const fftwq_iodim *dims, int howmany_rank, const fftwq_iodim *howmany_dims, __float128 *in, __float128 *ro, __float128 *io, unsigned flags); extern fftwq_plan fftwq_plan_guru_split_dft_c2r( int rank, const fftwq_iodim *dims, int howmany_rank, const fftwq_iodim *howmany_dims, __float128 *ri, __float128 *ii, __float128 *out, unsigned flags); extern fftwq_plan fftwq_plan_guru64_dft_r2c(int rank, const fftwq_iodim64 *dims, int howmany_rank, const fftwq_iodim64 *howmany_dims, __float128 *in, fftwq_complex *out, unsigned flags); extern fftwq_plan fftwq_plan_guru64_dft_c2r(int rank, const fftwq_iodim64 *dims, int howmany_rank, const fftwq_iodim64 *howmany_dims, fftwq_complex *in, __float128 *out, unsigned flags); extern fftwq_plan fftwq_plan_guru64_split_dft_r2c( int rank, const fftwq_iodim64 *dims, int howmany_rank, const fftwq_iodim64 *howmany_dims, __float128 *in, __float128 *ro, __float128 *io, unsigned flags); extern fftwq_plan fftwq_plan_guru64_split_dft_c2r( int rank, const fftwq_iodim64 *dims, int howmany_rank, const fftwq_iodim64 *howmany_dims, __float128 *ri, __float128 *ii, __float128 *out, unsigned flags); extern void fftwq_execute_dft_r2c(const fftwq_plan p, __float128 *in, fftwq_complex *out); extern void fftwq_execute_dft_c2r(const fftwq_plan p, fftwq_complex *in, __float128 *out); extern void fftwq_execute_split_dft_r2c(const fftwq_plan p, __float128 *in, __float128 *ro, __float128 *io); extern void fftwq_execute_split_dft_c2r(const fftwq_plan p, __float128 *ri, __float128 *ii, __float128 *out); extern fftwq_plan fftwq_plan_many_r2r(int rank, const int *n, int howmany, __float128 *in, const int *inembed, int istride, int idist, __float128 *out, const int *onembed, int ostride, int odist, const fftwq_r2r_kind *kind, unsigned flags); extern fftwq_plan fftwq_plan_r2r(int rank, const int *n, __float128 *in, __float128 *out, const fftwq_r2r_kind *kind, unsigned flags); extern fftwq_plan fftwq_plan_r2r_1d(int n, __float128 *in, __float128 *out, fftwq_r2r_kind kind, unsigned flags); extern fftwq_plan fftwq_plan_r2r_2d(int n0, int n1, __float128 *in, __float128 *out, fftwq_r2r_kind kind0, fftwq_r2r_kind kind1, unsigned flags); extern fftwq_plan fftwq_plan_r2r_3d(int n0, int n1, int n2, __float128 *in, __float128 *out, fftwq_r2r_kind kind0, fftwq_r2r_kind kind1, fftwq_r2r_kind kind2, unsigned flags); extern fftwq_plan fftwq_plan_guru_r2r(int rank, const fftwq_iodim *dims, int howmany_rank, const fftwq_iodim *howmany_dims, __float128 *in, __float128 *out, const fftwq_r2r_kind *kind, unsigned flags); extern fftwq_plan fftwq_plan_guru64_r2r(int rank, const fftwq_iodim64 *dims, int howmany_rank, const fftwq_iodim64 *howmany_dims, __float128 *in, __float128 *out, const fftwq_r2r_kind *kind, unsigned flags); extern void fftwq_execute_r2r(const fftwq_plan p, __float128 *in, __float128 *out); extern void fftwq_destroy_plan(fftwq_plan p); extern void fftwq_forget_wisdom(void); extern void fftwq_cleanup(void); extern void fftwq_set_timelimit(double t); extern void fftwq_plan_with_nthreads(int nthreads); extern int fftwq_init_threads(void); extern void fftwq_cleanup_threads(void); extern int fftwq_export_wisdom_to_filename(const char *filename); extern void fftwq_export_wisdom_to_file(FILE *output_file); extern char *fftwq_export_wisdom_to_string(void); extern void fftwq_export_wisdom(fftwq_write_char_func write_char, void *data); extern int fftwq_import_system_wisdom(void); extern int fftwq_import_wisdom_from_filename(const char *filename); extern int fftwq_import_wisdom_from_file(FILE *input_file); extern int fftwq_import_wisdom_from_string(const char *input_string); extern int fftwq_import_wisdom(fftwq_read_char_func read_char, void *data); extern void fftwq_fprint_plan(const fftwq_plan p, FILE *output_file); extern void fftwq_print_plan(const fftwq_plan p); extern char *fftwq_sprint_plan(const fftwq_plan p); extern void *fftwq_malloc(size_t n); extern __float128 *fftwq_alloc_real(size_t n); extern fftwq_complex *fftwq_alloc_complex(size_t n); extern void fftwq_free(void *p); extern void fftwq_flops(const fftwq_plan p, double *add, double *mul, double *fmas); extern double fftwq_estimate_cost(const fftwq_plan p); extern double fftwq_cost(const fftwq_plan p); extern int fftwq_alignment_of(__float128 *p); extern const char fftwq_version[]; extern const char fftwq_cc[]; extern const char fftwq_codelet_optim[];
# 12 "libwrap.h" 2
# 5 "libwrap.c" 2
