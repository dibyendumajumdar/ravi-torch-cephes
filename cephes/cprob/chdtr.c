/*							chdtr.c
 *
 *	Chi-square distribution
 *
 *
 *
 * SYNOPSIS:
 *
 * double df, x, y, chdtr();
 *
 * y = chdtr( df, x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns the area under the left hand tail (from 0 to x)
 * of the Chi square probability density function with
 * v degrees of freedom.
 *
 *
 *                                  inf.
 *                                    -
 *                        1          | |  v/2-1  -t/2
 *  P( x | v )   =   -----------     |   t      e     dt
 *                    v/2  -       | |
 *                   2    | (v/2)   -
 *                                   x
 *
 * where x is the Chi-square variable.
 *
 * The incomplete gamma integral is used, according to the
 * formula
 *
 *	y = chdtr( v, x ) = igam( v/2.0, x/2.0 ).
 *
 *
 * The arguments must both be positive.
 *
 *
 *
 * ACCURACY:
 *
 * See igam().
 *
 * ERROR MESSAGES:
 *
 *   message         condition      value returned
 * chdtr domain   x < 0 or v < 1        0.0
 */
/*							chdtrc()
 *
 *	Complemented Chi-square distribution
 *
 *
 *
 * SYNOPSIS:
 *
 * double v, x, y, chdtrc();
 *
 * y = chdtrc( v, x );
 *
 *
 *
 * DESCRIPTION:
 *
 * Returns the area under the right hand tail (from x to
 * infinity) of the Chi square probability density function
 * with v degrees of freedom:
 *
 *
 *                                  inf.
 *                                    -
 *                        1          | |  v/2-1  -t/2
 *  P( x | v )   =   -----------     |   t      e     dt
 *                    v/2  -       | |
 *                   2    | (v/2)   -
 *                                   x
 *
 * where x is the Chi-square variable.
 *
 * The incomplete gamma integral is used, according to the
 * formula
 *
 *	y = chdtr( v, x ) = igamc( v/2.0, x/2.0 ).
 *
 *
 * The arguments must both be positive.
 *
 *
 *
 * ACCURACY:
 *
 * See igamc().
 *
 * ERROR MESSAGES:
 *
 *   message         condition      value returned
 * chdtrc domain  x < 0 or v < 1        0.0
 */
/*							chdtri()
 *
 *	Inverse of complemented Chi-square distribution
 *
 *
 *
 * SYNOPSIS:
 *
 * double df, x, y, chdtri();
 *
 * x = chdtri( df, y );
 *
 *
 *
 *
 * DESCRIPTION:
 *
 * Finds the Chi-square argument x such that the integral
 * from x to infinity of the Chi-square density is equal
 * to the given cumulative probability y.
 *
 * This is accomplished using the inverse gamma integral
 * function and the relation
 *
 *    x/2 = igami( df/2, y );
 *
 *
 *
 *
 * ACCURACY:
 *
 * See igami.c.
 *
 * ERROR MESSAGES:
 *
 *   message         condition      value returned
 * chdtri domain   y < 0 or y > 1        0.0
 *                     v < 1
 *
 */

/*								chdtr() */


/*
Cephes Math Library Release 2.8:  June, 2000
Copyright 1984, 1987, 2000 by Stephen L. Moshier
*/

#include "mconf.h"
#ifdef ANSIPROT
CEPHES_API double torch_cephes_igamc ( double, double );
CEPHES_API double torch_cephes_igam ( double, double );
CEPHES_API double torch_cephes_igami ( double, double );
CEPHES_API double torch_cephes_chdtrc(double, double);
CEPHES_API double torch_cephes_chdtr(double, double);
CEPHES_API double torch_cephes_chdtri(double, double);
#else
double torch_cephes_igamc(), torch_cephes_igam(), torch_cephes_igami();
#endif

double torch_cephes_chdtrc(df,x)
double df, x;
{

if( (x < 0.0) || (df < 1.0) )
	{
	torch_cephes_mtherr( "chdtrc", DOMAIN );
	return(0.0);
	}
return( torch_cephes_igamc( df/2.0, x/2.0 ) );
}



double torch_cephes_chdtr(df,x)
double df, x;
{

if( (x < 0.0) || (df < 1.0) )
	{
	torch_cephes_mtherr( "chdtr", DOMAIN );
	return(0.0);
	}
return( torch_cephes_igam( df/2.0, x/2.0 ) );
}



double torch_cephes_chdtri( df, y )
double df, y;
{
double x;

if( (y < 0.0) || (y > 1.0) || (df < 1.0) )
	{
	torch_cephes_mtherr( "chdtri", DOMAIN );
	return(0.0);
	}

x = torch_cephes_igami( 0.5 * df, y );
return( 2.0 * x );
}
