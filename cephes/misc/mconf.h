/*							mconf.h
 *
 *	Common include file for math routines
 *
 *
 *
 * SYNOPSIS:
 *
 * #include "mconf.h"
 *
 *
 *
 * DESCRIPTION:
 *
 * This file contains definitions for error codes that are
 * passed to the common error handling routine mtherr()
 * (which see).
 *
 * The file also includes a conditional assembly definition
 * for the type of computer arithmetic (IEEE, DEC, Motorola
 * IEEE, or UNKnown).
 * 
 * For Digital Equipment PDP-11 and VAX computers, certain
 * IBM systems, and others that use numbers with a 56-bit
 * significand, the symbol DEC should be defined.  In this
 * mode, most floating point constants are given as arrays
 * of octal integers to eliminate decimal to binary conversion
 * errors that might be introduced by the compiler.
 *
 * For little-endian computers, such as IBM PC, that follow the
 * IEEE Standard for Binary Floating Point Arithmetic (ANSI/IEEE
 * Std 754-1985), the symbol IBMPC should be defined.  These
 * numbers have 53-bit significands.  In this mode, constants
 * are provided as arrays of hexadecimal 16 bit integers.
 *
 * Big-endian IEEE format is denoted MIEEE.  On some RISC
 * systems such as Sun SPARC, double precision constants
 * must be stored on 8-byte address boundaries.  Since integer
 * arrays may be aligned differently, the MIEEE configuration
 * may fail on such machines.
 *
 * To accommodate other types of computer arithmetic, all
 * constants are also provided in a normal decimal radix
 * which one can hope are correctly converted to a suitable
 * format by the available C language compiler.  To invoke
 * this mode, define the symbol UNK.
 *
 * An important difference among these modes is a predefined
 * set of machine arithmetic constants for each.  The numbers
 * MACHEP (the machine roundoff error), MAXNUM (largest number
 * represented), and several other parameters are preset by
 * the configuration symbol.  Check the file const.c to
 * ensure that these values are correct for your computer.
 *
 * Configurations NANS, INFINITIES, MINUSZERO, and DENORMAL
 * may fail on many systems.  Verify that they are supposed
 * to work on your computer.
 */
/*
Cephes Math Library Release 2.3:  June, 1995
Copyright 1984, 1987, 1989, 1995 by Stephen L. Moshier
*/
#ifndef _TORCH_CEPHES_MCONF_H_
#define _TORCH_CEPHES_MCONF_H_

/* Define if the `long double' type works.  */
#ifdef _MSC_VER
#define HAVE_LONG_DOUBLE 0
#else
#define HAVE_LONG_DOUBLE 1
#endif


/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

/* Define if you have the ANSI C header files.  */
#define STDC_HEADERS 1

/* Define if your processor stores words with the most significant
   byte first (like Motorola and SPARC, unlike Intel and VAX).  */
/* #undef WORDS_BIGENDIAN */

/* Define if floating point words are bigendian.  */
/* #undef FLOAT_WORDS_BIGENDIAN */

/* The number of bytes in a int.  */
#define SIZEOF_INT 4

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Name of package */
#define PACKAGE "cephes"

/* Version number of package */
#define VERSION "2.7"

/* Constant definitions for math error conditions
 */

#define DOMAIN		1	/* argument domain error */
#define SING		2	/* argument singularity */
#define OVERFLOW	3	/* overflow range error */
#define UNDERFLOW	4	/* underflow range error */
#define TLOSS		5	/* total loss of precision */
#define PLOSS		6	/* partial loss of precision */

#define EDOM		33
#define ERANGE		34
/* Complex numeral.  */
typedef struct
	{
	double r;
	double i;
	} cmplx;

#ifdef HAVE_LONG_DOUBLE
/* Long double complex numeral.  */
typedef struct
	{
	long double r;
	long double i;
	} cmplxl;
#endif


/* Type of computer arithmetic */

/* PDP-11, Pro350, VAX:
 */
/* #define DEC 1 */

/* Intel IEEE, low order words come first:
 */
/* #define IBMPC 1 */

/* Motorola IEEE, high order words come first
 * (Sun 680x0 workstation):
 */
/* #define MIEEE 1 */

/* UNKnown arithmetic, invokes coefficients given in
 * normal decimal format.  Beware of range boundary
 * problems (MACHEP, MAXLOG, etc. in const.c) and
 * roundoff problems in pow.c:
 * (Sun SPARCstation)
 */
#define UNK 1

/* If you define UNK, then be sure to set BIGENDIAN properly. */
#ifdef FLOAT_WORDS_BIGENDIAN
#define BIGENDIAN 1
#else
#define BIGENDIAN 0
#endif
/* Define this `volatile' if your compiler thinks
 * that floating point arithmetic obeys the associative
 * and distributive laws.  It will defeat some optimizations
 * (but probably not enough of them).
 *
 * #define VOLATILE volatile
 */
#define VOLATILE

/* For 12-byte long doubles on an i386, pad a 16-bit short 0
 * to the end of real constants initialized by integer arrays.
 *
 * #define XPD 0,
 *
 * Otherwise, the type is 10 bytes long and XPD should be
 * defined blank (e.g., Microsoft C).
 *
 * #define XPD
 */
#define XPD 0,

/* Define to support tiny denormal numbers, else undefine. */
#define DENORMAL 1

/* Define to ask for infinity support, else undefine. */
#define INFINITIES 1

/* Define to ask for support of numbers that are Not-a-Number,
   else undefine.  This may automatically define INFINITIES in some files. */
#define NANS 1

/* Define to distinguish between -0.0 and +0.0.  */
#define MINUSZERO 1

/* Define 1 for ANSI C atan2() function
   See atan.c and clog.c. */
#define ANSIC 1

#ifdef __cplusplus
# define CEPHES_EXTERNC extern "C"
#else
# define CEPHES_EXTERNC extern
#endif

#ifdef _WIN32
# ifdef CEPHES_EXPORTS
#  define CEPHES_API CEPHES_EXTERNC __declspec(dllexport)
# else
#  define CEPHES_API CEPHES_EXTERNC __declspec(dllimport)
# endif
#else
# define CEPHES_API CEPHES_EXTERNC
#endif

/* Get ANSI function prototypes, if you want them. */
#if 1
/* #ifdef __STDC__ */
#define ANSIPROT 1
CEPHES_API int torch_cephes_mtherr ( char *, int );
#else
int torch_cephes_mtherr();
#endif

/* Variable for error reporting.  See mtherr.c.  */
CEPHES_API int torch_cephes_merror;

CEPHES_API double torch_cephes_acosh ( double x );
CEPHES_API int torch_cephes_airy ( double, double *, double *, double *, double * );
CEPHES_API double torch_cephes_asin ( double );
CEPHES_API double torch_cephes_acos ( double );
CEPHES_API double torch_cephes_asinh ( double x );
CEPHES_API double torch_cephes_atan ( double );
CEPHES_API double torch_cephes_atan2 ( double y, double x );
CEPHES_API double torch_cephes_atanh ( double );
CEPHES_API double torch_cephes_bdtrc ( int k, int n, double p );
CEPHES_API double torch_cephes_bdtr ( int k, int n, double p );
CEPHES_API double torch_cephes_bdtri ( int k, int n, double y );
CEPHES_API double torch_cephes_beta ( double a, double b );
CEPHES_API double torch_cephes_lbeta ( double a, double b );
CEPHES_API double torch_cephes_btdtr ( double a, double b, double x );
CEPHES_API double torch_cephes_cbrt ( double );
CEPHES_API double torch_cephes_chbevl ( double, double [], int );
CEPHES_API double torch_cephes_chdtrc ( double df, double x );
CEPHES_API double torch_cephes_chdtr ( double df, double x );
CEPHES_API double torch_cephes_chdtri ( double df, double y );
CEPHES_API void torch_cephes_clog ( cmplx *z, cmplx *w );
CEPHES_API void torch_cephes_cexp ( cmplx *z, cmplx *w );
CEPHES_API void torch_cephes_csin ( cmplx *z, cmplx *w );
CEPHES_API void torch_cephes_ccos ( cmplx *z, cmplx *w );
CEPHES_API void torch_cephes_ctan ( cmplx *z, cmplx *w );
CEPHES_API void torch_cephes_ccot ( cmplx *z, cmplx *w );
CEPHES_API void torch_cephes_casin ( cmplx *z, cmplx *w );
CEPHES_API void torch_cephes_cacos ( cmplx *z, cmplx *w );
CEPHES_API void torch_cephes_catan ( cmplx *z, cmplx *w );
CEPHES_API void torch_cephes_cadd ( cmplx *a, cmplx *b, cmplx *c );
CEPHES_API void torch_cephes_csub ( cmplx *a, cmplx *b, cmplx *c );
CEPHES_API void torch_cephes_cmul ( cmplx *a, cmplx *b, cmplx *c );
CEPHES_API void torch_cephes_cdiv ( cmplx *a, cmplx *b, cmplx *c );
CEPHES_API void torch_cephes_cmov ( void *a, void *b );
CEPHES_API void torch_cephes_cneg ( cmplx *a );
CEPHES_API double torch_cephes_cabs ( cmplx *z );
CEPHES_API void torch_cephes_csqrt ( cmplx *z, cmplx *w );
CEPHES_API double torch_cephes_hypot ( double, double );
CEPHES_API double torch_cephes_cosh ( double );
CEPHES_API double torch_cephes_dawsn ( double xx );
CEPHES_API void torch_cephes_eigens ( double A[], double RR[], double E[], int N );
CEPHES_API double torch_cephes_ellie ( double, double );
CEPHES_API double torch_cephes_ellik ( double, double );
CEPHES_API double torch_cephes_ellpe ( double );
CEPHES_API int torch_cephes_ellpj ( double u, double m, double *sn, double *cn,
                                double *dn, double *ph );
CEPHES_API double torch_cephes_ellpk ( double );
CEPHES_API double torch_cephes_exp10 ( double );
CEPHES_API double torch_cephes_exp1m ( double );
CEPHES_API double torch_cephes_exp2 ( double );
CEPHES_API double torch_cephes_expx2(double x, int sign);
CEPHES_API double torch_cephes_expn ( int n, double x );
CEPHES_API double torch_cephes_fac ( int i );
CEPHES_API double torch_cephes_fdtrc ( int ia, int ib, double x );
CEPHES_API double torch_cephes_fdtr ( int ia, int ib, double x );
CEPHES_API double torch_cephes_fdtri ( int ia, int ib, double y );
CEPHES_API int torch_cephes_fftr ( double x[], int m0, double sine[] );
CEPHES_API double torch_cephes_ceil ( double x );
CEPHES_API double torch_cephes_fabs ( double );
CEPHES_API double torch_cephes_floor ( double );
CEPHES_API double torch_cephes_frexp ( double, int * );
CEPHES_API double torch_cephes_ldexp ( double, int );
CEPHES_API int torch_cephes_signbit ( double );
CEPHES_API int torch_cephes_isnan ( double );
CEPHES_API int torch_cephes_isfinite ( double );
CEPHES_API double torch_cephes_polevl ( double, double[], int );
CEPHES_API double torch_cephes_p1evl ( double, double[], int );
CEPHES_API double torch_cephes_exp ( double );
CEPHES_API double torch_cephes_log ( double );
CEPHES_API double torch_cephes_sin ( double );
CEPHES_API double torch_cephes_cos ( double );
CEPHES_API double torch_cephes_sqrt ( double );
CEPHES_API int torch_cephes_fresnl ( double xxa, double *ssa, double *cca );
CEPHES_API double torch_cephes_gamma ( double );
CEPHES_API double torch_cephes_lgam ( double );
CEPHES_API double torch_cephes_gdtr ( double a, double b, double x );
CEPHES_API double torch_cephes_gdtrc ( double a, double b, double x );
CEPHES_API int torch_cephes_gels ( double A[], double R[], int M, double EPS,
                               double AUX[] );
CEPHES_API double torch_cephes_hyp2f1 ( double a, double b, double c, double x );
CEPHES_API double torch_cephes_hyperg ( double, double, double );
CEPHES_API double torch_cephes_hyp2f0 ( double a, double b, double x, int type,
                                    double *err );
CEPHES_API double torch_cephes_i0 ( double );
CEPHES_API double torch_cephes_i0e ( double x );
CEPHES_API double torch_cephes_i1 ( double );
CEPHES_API double torch_cephes_i1e ( double x );
CEPHES_API double torch_cephes_igamc ( double, double );
CEPHES_API double torch_cephes_igam ( double, double );
CEPHES_API double torch_cephes_igami ( double, double );
CEPHES_API double torch_cephes_incbet ( double, double, double );
CEPHES_API double torch_cephes_incbi ( double, double, double );
CEPHES_API double torch_cephes_iv ( double v, double x );
CEPHES_API double torch_cephes_j0 ( double );
CEPHES_API double torch_cephes_y0 ( double );
CEPHES_API double torch_cephes_j1 ( double );
CEPHES_API double torch_cephes_y1 ( double );
CEPHES_API double torch_cephes_jn ( int n, double x );
CEPHES_API double torch_cephes_jv ( double, double );
CEPHES_API double torch_cephes_k0 ( double x );
CEPHES_API double torch_cephes_k0e ( double x );
CEPHES_API double torch_cephes_k1 ( double x );
CEPHES_API double torch_cephes_k1e ( double x );
CEPHES_API double torch_cephes_kn ( int nn, double x );
CEPHES_API int torch_cephes_levnsn ( int n, double r[], double a[],
                                 double e[], double refl[] );
CEPHES_API double torch_cephes_log10 ( double );
CEPHES_API double torch_cephes_log2 ( double );
CEPHES_API long torch_cephes_lrand ( void );
CEPHES_API long torch_cephes_lsqrt ( long x );
CEPHES_API int torch_cephes_minv ( double A[], double X[], int n, double B[],
                               int IPS[] );
CEPHES_API int torch_cephes_mmmpy ( int r, int c, double *A, double *B, double *Y );
CEPHES_API int torch_cephes_mtherr ( char *name, int code );
CEPHES_API int torch_cephes_mtransp ( int n, double *A, double *T );
CEPHES_API int torch_cephes_mvmpy ( int r, int c, double *A, double *V, double *Y );
CEPHES_API double torch_cephes_nbdtrc ( int k, int n, double p );
CEPHES_API double torch_cephes_nbdtr ( int k, int n, double p );
CEPHES_API double torch_cephes_nbdtri ( int k, int n, double p );
CEPHES_API double torch_cephes_ndtr ( double a );
CEPHES_API double torch_cephes_erfc ( double );
CEPHES_API double torch_cephes_erf ( double );
CEPHES_API double torch_cephes_ndtri ( double );
CEPHES_API double torch_cephes_pdtrc ( int k, double m );
CEPHES_API double torch_cephes_pdtr ( int k, double m );
CEPHES_API double torch_cephes_pdtri ( int k, double y );
CEPHES_API double torch_cephes_pow ( double, double );
CEPHES_API double torch_cephes_powi ( double, int );
CEPHES_API double torch_cephes_psi ( double );
CEPHES_API void torch_cephes_revers ( double y[], double x[], int n );
CEPHES_API double torch_cephes_rgamma ( double x );
CEPHES_API double torch_cephes_round ( double );
CEPHES_API int torch_cephes_sprec ( void );
CEPHES_API int torch_cephes_dprec ( void );
CEPHES_API int torch_cephes_ldprec ( void );
CEPHES_API int torch_cephes_shichi ( double x, double *si, double *ci );
CEPHES_API int torch_cephes_sici ( double x, double *si, double *ci );
CEPHES_API double torch_cephes_simpsn ( double f[], double delta );
CEPHES_API int torch_cephes_simq ( double A[], double B[], double X[],
                               int n, int flag, int IPS[] );
CEPHES_API double torch_cephes_radian ( double d, double m, double s );

CEPHES_API int torch_cephes_sincos ( double x, double *s, double *c, int flg );

CEPHES_API double torch_cephes_sindg ( double x );
CEPHES_API double torch_cephes_cosdg ( double x );
CEPHES_API double torch_cephes_sinh ( double );
CEPHES_API double torch_cephes_spence ( double );
CEPHES_API double torch_cephes_stdtr ( int k, double t );
CEPHES_API double torch_cephes_stdtri ( int k, double p );
CEPHES_API double torch_cephes_onef2 ( double a, double b, double c,
                                   double x, double *err );
CEPHES_API double torch_cephes_threef0 ( double a, double b, double c,
                                     double x, double *err );
CEPHES_API double torch_cephes_struve ( double v, double x );
CEPHES_API double torch_cephes_tan ( double );
CEPHES_API double torch_cephes_cot ( double );
CEPHES_API double torch_cephes_tandg ( double x );
CEPHES_API double torch_cephes_cotdg ( double x );
CEPHES_API double torch_cephes_tanh ( double );
CEPHES_API double torch_cephes_log1p ( double );
CEPHES_API double torch_cephes_exmp1 ( double );
CEPHES_API double torch_cephes_cosm1 ( double x );
CEPHES_API double torch_cephes_yn ( int, double );
CEPHES_API double torch_cephes_zeta ( double x, double q );
CEPHES_API double torch_cephes_zetac ( double );
CEPHES_API int torch_cephes_drand ( double *a );
CEPHES_API double torch_cephes_smirnov ( int, double );
CEPHES_API double torch_cephes_smirnovi ( int, double );
CEPHES_API double torch_cephes_kolmogorov ( double );
CEPHES_API double torch_cephes_kolmogi ( double );

/* polyn.c */
CEPHES_API void torch_cephes_polini ( int maxdeg );
CEPHES_API void torch_cephes_polprt ( double a[], int na, int d );
CEPHES_API void torch_cephes_polclr ( double *a, int n );
CEPHES_API void torch_cephes_polmov ( double *a, int na, double *b );
CEPHES_API void torch_cephes_polmul ( double a[], int na, double b[],
                                  int nb, double c[] );
CEPHES_API void torch_cephes_poladd ( double a[], int na, double b[],
                                  int nb, double c[] );
CEPHES_API void torch_cephes_polsub ( double a[], int na, double b[],
                                  int nb, double c[] );
CEPHES_API int torch_cephes_poldiv ( double a[], int na, double b[],
                                 int nb, double c[] );
CEPHES_API void torch_cephes_polsbt ( double a[], int na, double b[],
                                  int nb, double c[] );
CEPHES_API double torch_cephes_poleva ( double a[], int na, double x );
/* polmisc.c */
CEPHES_API void torch_cephes_polatn ( double num[], double den[], double ans[],
                                  int nn );
CEPHES_API void torch_cephes_polsqt ( double pol[], double ans[], int nn );
CEPHES_API void torch_cephes_polsin ( double x[], double y[], int nn );
CEPHES_API void torch_cephes_polcos ( double x[], double y[], int nn );

#endif