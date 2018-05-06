/*							const.c
 *
 *	Globally declared constants
 *
 *
 *
 * SYNOPSIS:
 *
 * CEPHES_API double nameofconstant;
 *
 *
 *
 *
 * DESCRIPTION:
 *
 * This file contains a number of mathematical constants and
 * also some needed size parameters of the computer arithmetic.
 * The values are supplied as arrays of hexadecimal integers
 * for IEEE arithmetic; arrays of octal constants for DEC
 * arithmetic; and in a normal decimal scientific notation for
 * other machines.  The particular notation used is determined
 * by a symbol (DEC, IBMPC, or UNK) defined in the include file
 * mconf.h.
 *
 * The default size parameters are as follows.
 *
 * For DEC and UNK modes:
 * MACHEP =  1.38777878078144567553E-17       2**-56
 * MAXLOG =  8.8029691931113054295988E1       log(2**127)
 * MINLOG = -8.872283911167299960540E1        log(2**-128)
 * MAXNUM =  1.701411834604692317316873e38    2**127
 *
 * For IEEE arithmetic (IBMPC):
 * MACHEP =  1.11022302462515654042E-16       2**-53
 * MAXLOG =  7.09782712893383996843E2         log(2**1024)
 * MINLOG = -7.08396418532264106224E2         log(2**-1022)
 * MAXNUM =  1.7976931348623158E308           2**1024
 *
 * The global symbols for mathematical constants are
 * PI     =  3.14159265358979323846           pi
 * PIO2   =  1.57079632679489661923           pi/2
 * PIO4   =  7.85398163397448309616E-1        pi/4
 * SQRT2  =  1.41421356237309504880           sqrt(2)
 * SQRTH  =  7.07106781186547524401E-1        sqrt(2)/2
 * LOG2E  =  1.4426950408889634073599         1/log(2)
 * SQ2OPI =  7.9788456080286535587989E-1      sqrt( 2/pi )
 * LOGE2  =  6.93147180559945309417E-1        log(2)
 * LOGSQ2 =  3.46573590279972654709E-1        log(2)/2
 * THPIO4 =  2.35619449019234492885           3*pi/4
 * TWOOPI =  6.36619772367581343075535E-1     2/pi
 *
 * These lists are subject to change.
 */

/*							const.c */

/*
Cephes Math Library Release 2.3:  March, 1995
Copyright 1984, 1995 by Stephen L. Moshier
*/

#include "mconf.h"

#ifndef __has_builtin
#define __has_builtin(x) 0
#endif

#ifdef UNK
#if 1
CEPHES_API double torch_cephes_MACHEP =  1.11022302462515654042E-16;   /* 2**-53 */
#else
CEPHES_API double torch_cephes_MACHEP =  1.38777878078144567553E-17;   /* 2**-56 */
#endif
CEPHES_API double torch_cephes_UFLOWTHRESH =  2.22507385850720138309E-308; /* 2**-1022 */
#ifdef DENORMAL
CEPHES_API double torch_cephes_MAXLOG =  7.09782712893383996732E2;     /* log(MAXNUM) */
/* double MINLOG = -7.44440071921381262314E2; */     /* log(2**-1074) */
CEPHES_API double torch_cephes_MINLOG = -7.451332191019412076235E2;     /* log(2**-1075) */
#else
CEPHES_API double torch_cephes_MAXLOG =  7.08396418532264106224E2;     /* log 2**1022 */
CEPHES_API double torch_cephes_MINLOG = -7.08396418532264106224E2;     /* log 2**-1022 */
#endif
CEPHES_API double torch_cephes_MAXNUM =  1.79769313486231570815E308;
       /* 2**1024*(1-MACHEP) */
CEPHES_API double torch_cephes_PI     =  3.14159265358979323846;       /* pi */
CEPHES_API double torch_cephes_PIO2   =  1.57079632679489661923;       /* pi/2 */
CEPHES_API double torch_cephes_PIO4   =  7.85398163397448309616E-1;    /* pi/4 */
CEPHES_API double torch_cephes_SQRT2  =  1.41421356237309504880;       /* sqrt(2) */
CEPHES_API double torch_cephes_SQRTH  =  7.07106781186547524401E-1;    /* sqrt(2)/2 */
CEPHES_API double torch_cephes_LOG2E  =  1.4426950408889634073599;     /* 1/log(2) */
CEPHES_API double torch_cephes_SQ2OPI =  7.9788456080286535587989E-1;  /* sqrt( 2/pi ) */
CEPHES_API double torch_cephes_LOGE2  =  6.93147180559945309417E-1;    /* log(2) */
CEPHES_API double torch_cephes_LOGSQ2 =  3.46573590279972654709E-1;    /* log(2)/2 */
CEPHES_API double torch_cephes_THPIO4 =  2.35619449019234492885;       /* 3*pi/4 */
CEPHES_API double torch_cephes_TWOOPI =  6.36619772367581343075535E-1; /* 2/pi */
#ifdef INFINITIES
#if __has_builtin(__builtin_inf)
CEPHES_API double torch_cephes_INFINITY = __builtin_inf();  /* 99e999; */
#else
CEPHES_API double torch_cephes_INFINITY = 1.0/0.0;  /* 99e999; */
#endif
#else
CEPHES_API double torch_cephes_INFINITY =
    1.79769313486231570815E308;    /* 2**1024*(1-MACHEP) */
#endif
#ifdef NANS
#if __has_builtin(__builtin_nan)
CEPHES_API double torch_cephes_NAN = __builtin_nan("0");
#else
CEPHES_API double torch_cephes_NAN = 1.0/0.0 - 1.0/0.0;
#endif
#else
CEPHES_API double torch_cephes_NAN = 0.0;
#endif
#ifdef MINUSZERO
CEPHES_API double torch_cephes_NEGZERO = -0.0;
#else
CEPHES_API double torch_cephes_NEGZERO = 0.0;
#endif
#endif

#ifdef IBMPC
			/* 2**-53 =  1.11022302462515654042E-16 */
CEPHES_API unsigned short torch_cephes_MACHEP[4] = {0x0000,0x0000,0x0000,0x3ca0};
CEPHES_API unsigned short torch_cephes_UFLOWTHRESH[4] = {0x0000,0x0000,0x0000,0x0010};
#ifdef DENORMAL
			/* log(MAXNUM) =  7.09782712893383996732224E2 */
CEPHES_API unsigned short torch_cephes_MAXLOG[4] = {0x39ef,0xfefa,0x2e42,0x4086};
			/* log(2**-1074) = - -7.44440071921381262314E2 */
/*unsigned short MINLOG[4] = {0x71c3,0x446d,0x4385,0xc087};*/
CEPHES_API unsigned short torch_cephes_MINLOG[4] = {0x3052,0xd52d,0x4910,0xc087};
#else
			/* log(2**1022) =   7.08396418532264106224E2 */
CEPHES_API unsigned short torch_cephes_MAXLOG[4] = {0xbcd2,0xdd7a,0x232b,0x4086};
			/* log(2**-1022) = - 7.08396418532264106224E2 */
CEPHES_API unsigned short torch_cephes_MINLOG[4] = {0xbcd2,0xdd7a,0x232b,0xc086};
#endif
			/* 2**1024*(1-MACHEP) =  1.7976931348623158E308 */
CEPHES_API unsigned short torch_cephes_MAXNUM[4] = {0xffff,0xffff,0xffff,0x7fef};
CEPHES_API unsigned short torch_cephes_PI[4]     = {0x2d18,0x5444,0x21fb,0x4009};
CEPHES_API unsigned short torch_cephes_PIO2[4]   = {0x2d18,0x5444,0x21fb,0x3ff9};
CEPHES_API unsigned short torch_cephes_PIO4[4]   = {0x2d18,0x5444,0x21fb,0x3fe9};
CEPHES_API unsigned short torch_cephes_SQRT2[4]  = {0x3bcd,0x667f,0xa09e,0x3ff6};
CEPHES_API unsigned short torch_cephes_SQRTH[4]  = {0x3bcd,0x667f,0xa09e,0x3fe6};
CEPHES_API unsigned short torch_cephes_LOG2E[4]  = {0x82fe,0x652b,0x1547,0x3ff7};
CEPHES_API unsigned short torch_cephes_SQ2OPI[4] = {0x3651,0x33d4,0x8845,0x3fe9};
CEPHES_API unsigned short torch_cephes_LOGE2[4]  = {0x39ef,0xfefa,0x2e42,0x3fe6};
CEPHES_API unsigned short torch_cephes_LOGSQ2[4] = {0x39ef,0xfefa,0x2e42,0x3fd6};
CEPHES_API unsigned short torch_cephes_THPIO4[4] = {0x21d2,0x7f33,0xd97c,0x4002};
CEPHES_API unsigned short torch_cephes_TWOOPI[4] = {0xc883,0x6dc9,0x5f30,0x3fe4};
#ifdef INFINITIES
CEPHES_API unsigned short torch_cephes_INFINITY[4] = {0x0000,0x0000,0x0000,0x7ff0};
#else
CEPHES_API unsigned short torch_cephes_INFINITY[4] = {0xffff,0xffff,0xffff,0x7fef};
#endif
#ifdef NANS
CEPHES_API unsigned short torch_cephes_NAN[4] = {0x0000,0x0000,0x0000,0x7ffc};
#else
CEPHES_API unsigned short torch_cephes_NAN[4] = {0x0000,0x0000,0x0000,0x0000};
#endif
#ifdef MINUSZERO
CEPHES_API unsigned short torch_cephes_NEGZERO[4] = {0x0000,0x0000,0x0000,0x8000};
#else
CEPHES_API unsigned short torch_cephes_NEGZERO[4] = {0x0000,0x0000,0x0000,0x0000};
#endif
#endif

#ifdef MIEEE
			/* 2**-53 =  1.11022302462515654042E-16 */
CEPHES_API unsigned short torch_cephes_MACHEP[4] = {0x3ca0,0x0000,0x0000,0x0000};
CEPHES_API unsigned short torch_cephes_UFLOWTHRESH[4] = {0x0010,0x0000,0x0000,0x0000};
#ifdef DENORMAL
			/* log(2**1024) =   7.09782712893383996843E2 */
CEPHES_API unsigned short torch_cephes_MAXLOG[4] = {0x4086,0x2e42,0xfefa,0x39ef};
			/* log(2**-1074) = - -7.44440071921381262314E2 */
/* unsigned short MINLOG[4] = {0xc087,0x4385,0x446d,0x71c3}; */
CEPHES_API unsigned short torch_cephes_MINLOG[4] = {0xc087,0x4910,0xd52d,0x3052};
#else
			/* log(2**1022) =  7.08396418532264106224E2 */
CEPHES_API unsigned short torch_cephes_MAXLOG[4] = {0x4086,0x232b,0xdd7a,0xbcd2};
			/* log(2**-1022) = - 7.08396418532264106224E2 */
CEPHES_API unsigned short torch_cephes_MINLOG[4] = {0xc086,0x232b,0xdd7a,0xbcd2};
#endif
			/* 2**1024*(1-MACHEP) =  1.7976931348623158E308 */
CEPHES_API unsigned short torch_cephes_MAXNUM[4] = {0x7fef,0xffff,0xffff,0xffff};
CEPHES_API unsigned short torch_cephes_PI[4]     = {0x4009,0x21fb,0x5444,0x2d18};
CEPHES_API unsigned short torch_cephes_PIO2[4]   = {0x3ff9,0x21fb,0x5444,0x2d18};
CEPHES_API unsigned short torch_cephes_PIO4[4]   = {0x3fe9,0x21fb,0x5444,0x2d18};
CEPHES_API unsigned short torch_cephes_SQRT2[4]  = {0x3ff6,0xa09e,0x667f,0x3bcd};
CEPHES_API unsigned short torch_cephes_SQRTH[4]  = {0x3fe6,0xa09e,0x667f,0x3bcd};
CEPHES_API unsigned short torch_cephes_LOG2E[4]  = {0x3ff7,0x1547,0x652b,0x82fe};
CEPHES_API unsigned short torch_cephes_SQ2OPI[4] = {0x3fe9,0x8845,0x33d4,0x3651};
CEPHES_API unsigned short torch_cephes_LOGE2[4]  = {0x3fe6,0x2e42,0xfefa,0x39ef};
CEPHES_API unsigned short torch_cephes_LOGSQ2[4] = {0x3fd6,0x2e42,0xfefa,0x39ef};
CEPHES_API unsigned short torch_cephes_THPIO4[4] = {0x4002,0xd97c,0x7f33,0x21d2};
CEPHES_API unsigned short torch_cephes_TWOOPI[4] = {0x3fe4,0x5f30,0x6dc9,0xc883};
#ifdef INFINITIES
CEPHES_API unsigned short torch_cephes_INFINITY[4] = {0x7ff0,0x0000,0x0000,0x0000};
#else
CEPHES_API unsigned short torch_cephes_INFINITY[4] = {0x7fef,0xffff,0xffff,0xffff};
#endif
#ifdef NANS
CEPHES_API unsigned short torch_cephes_NAN[4] = {0x7ff8,0x0000,0x0000,0x0000};
#else
CEPHES_API unsigned short torch_cephes_NAN[4] = {0x0000,0x0000,0x0000,0x0000};
#endif
#ifdef MINUSZERO
CEPHES_API unsigned short torch_cephes_NEGZERO[4] = {0x8000,0x0000,0x0000,0x0000};
#else
CEPHES_API unsigned short torch_cephes_NEGZERO[4] = {0x0000,0x0000,0x0000,0x0000};
#endif
#endif

#ifdef DEC
			/* 2**-56 =  1.38777878078144567553E-17 */
CEPHES_API unsigned short torch_cephes_MACHEP[4] = {0022200,0000000,0000000,0000000};
CEPHES_API unsigned short torch_cephes_UFLOWTHRESH[4] = {0x0080,0x0000,0x0000,0x0000};
			/* log 2**127 = 88.029691931113054295988 */
CEPHES_API unsigned short torch_cephes_MAXLOG[4] = {041660,007463,0143742,025733,};
			/* log 2**-128 = -88.72283911167299960540 */
CEPHES_API unsigned short torch_cephes_MINLOG[4] = {0141661,071027,0173721,0147572,};
			/* 2**127 = 1.701411834604692317316873e38 */
CEPHES_API unsigned short torch_cephes_MAXNUM[4] = {077777,0177777,0177777,0177777,};
CEPHES_API unsigned short torch_cephes_PI[4]     = {040511,007732,0121041,064302,};
CEPHES_API unsigned short torch_cephes_PIO2[4]   = {040311,007732,0121041,064302,};
CEPHES_API unsigned short torch_cephes_PIO4[4]   = {040111,007732,0121041,064302,};
CEPHES_API unsigned short torch_cephes_SQRT2[4]  = {040265,002363,031771,0157145,};
CEPHES_API unsigned short torch_cephes_SQRTH[4]  = {040065,002363,031771,0157144,};
CEPHES_API unsigned short torch_cephes_LOG2E[4]  = {040270,0125073,024534,013761,};
CEPHES_API unsigned short torch_cephes_SQ2OPI[4] = {040114,041051,0117241,0131204,};
CEPHES_API unsigned short torch_cephes_LOGE2[4]  = {040061,071027,0173721,0147572,};
CEPHES_API unsigned short torch_cephes_LOGSQ2[4] = {037661,071027,0173721,0147572,};
CEPHES_API unsigned short torch_cephes_THPIO4[4] = {040426,0145743,0174631,007222,};
CEPHES_API unsigned short torch_cephes_TWOOPI[4] = {040042,0174603,067116,042025,};
/* Approximate infinity by MAXNUM.  */
CEPHES_API unsigned short torch_cephes_INFINITY[4] = {077777,0177777,0177777,0177777,};
CEPHES_API unsigned short torch_cephes_NAN[4] = {0000000,0000000,0000000,0000000};
#ifdef MINUSZERO
CEPHES_API unsigned short torch_cephes_NEGZERO[4] = {0000000,0000000,0000000,0100000};
#else
CEPHES_API unsigned short torch_cephes_NEGZERO[4] = {0000000,0000000,0000000,0000000};
#endif
#endif

#ifndef UNK
CEPHES_API unsigned short torch_cephes_MACHEP[];
CEPHES_API unsigned short torch_cephes_UFLOWTHRESH[];
CEPHES_API unsigned short torch_cephes_MAXLOG[];
CEPHES_API unsigned short torch_cephes_UNDLOG[];
CEPHES_API unsigned short torch_cephes_MINLOG[];
CEPHES_API unsigned short torch_cephes_MAXNUM[];
CEPHES_API unsigned short torch_cephes_PI[];
CEPHES_API unsigned short torch_cephes_PIO2[];
CEPHES_API unsigned short torch_cephes_PIO4[];
CEPHES_API unsigned short torch_cephes_SQRT2[];
CEPHES_API unsigned short torch_cephes_SQRTH[];
CEPHES_API unsigned short torch_cephes_LOG2E[];
CEPHES_API unsigned short torch_cephes_SQ2OPI[];
CEPHES_API unsigned short torch_cephes_LOGE2[];
CEPHES_API unsigned short torch_cephes_LOGSQ2[];
CEPHES_API unsigned short torch_cephes_THPIO4[];
CEPHES_API unsigned short torch_cephes_TWOOPI[];
CEPHES_API unsigned short torch_cephes_INFINITY[];
CEPHES_API unsigned short torch_cephes_NAN[];
CEPHES_API unsigned short torch_cephes_NEGZERO[];
#endif
