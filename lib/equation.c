/*
 * equation.c - evaluate different kinds of equations
 *     
 * Copyright (C) 2013  Terence Ng
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include"equation.h"

/* judge how many roots the equation has
 * discriminant > 0: two different roots
 *      ...     = 0: two same roots
 *      ...     < 0: no real roots 
 */
double
discriminant ( double a, double b, double c )
{
	return b * b - 4 * a * c;
}

/* evaluate part of the equation */
double
quadratic_equation_front ( double a, double b, double c )
{
	return sqrt (  discriminant ( a, b, c ) );
}

/*  */
#if NO_COMPLEX == 1

/* return the final roots */
roots_quadratic_equation
*solve_quadratic_equation ( double a, double b, double c )
{
	
	roots_quadratic_equation *roots;

	// roots = malloc ( sizeof ( roots_quadratic_equation ) );

	if ( discriminant ( a, b, c ) > 0 )
	{
		roots->root1 = ( -1 * b ) + quadratic_equation_front ( a, b, c );
		roots->root2 = ( -1 * b ) - quadratic_equation_front ( a, b, c );

		return roots;
	}
	else if ( discriminant ( a, b, c ) == 0 )
	{ 
		roots->root1 = -1 * b / ( 2 * a );
		roots->root2 = roots->root1;

		return roots;
	}
	else if ( discriminant ( a, b, c ) < 0)
	{
		return NULL;
	}
}

#elif NO_COMPLEX == 0

/* return the final roots */
roots_quadratic_equation
*solve_quadratic_equation ( double a, double b, double c )
{
	
	roots_quadratic_equation *roots;

	// roots = malloc ( sizeof ( roots_quadratic_equation ) );

	if ( discriminant ( a, b, c ) > 0 )
	{
		roots->root1->real = ( -1 * b ) + quadratic_equation_front ( a, b, c );
		roots->root1->image = 0;
		roots->root2->real = ( -1 * b ) - quadratic_equation_front ( a, b, c );
		roots->root2->image = 0;

		return roots;
	}
	else if ( discriminant ( a, b, c ) == 0 )
	{ 
		roots->root1->real = -1 * b / ( 2 * a );
		roots->root1->image = 0;
		roots->root2->real = roots->root1->real;
		roots->root2->image = 0

		return roots;
	}
	else if ( discriminant ( a, b, c ) < 0)
	{
		roots->root1->real = -1 * b / ( 2 * a );
		roots->root1->image = sqrt ( -1 * quadratic_equation_front( a, b, c ) ) / ( 2 * a );
		roots->root2->real = roots->root1->real;
		roots->root2->image = -1 * roots->root1->image;

		return roots;
	}
}

#endif /* NO_COMPLEX */


