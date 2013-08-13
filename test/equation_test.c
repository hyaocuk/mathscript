/*
 * equation.c - testcase for equation in lib
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


/* CASE: 1 -> "two different roots" 
 *       2 -> "two same roots" 
 *       3 -> "no real roots" 
 */
#define CASE 2

#if CASE == 1
#define A 2
#define B 4
#define C -30
#endif

#if CASE == 2
#define A 1
#define B -10
#define C 25
#endif

#if CASE == 3
#define A 2
#define B 1
#define C 1
#endif

#include"../lib/equation.h"

#include"equation_test.h"

/* the code below should be absolutely the same as the one in the '../lib/' for test */
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
	return sqrt ( discriminant ( a, b, c ) );
}

/*  */
#if NO_COMPLEX == 1

/* return the final roots */
roots_quadratic_equation
*solve_quadratic_equation ( double a, double b, double c )
{
	
	roots_quadratic_equation *roots;

	roots = malloc ( sizeof ( roots_quadratic_equation ) );

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
		/* TODO */
	}
}

#elif NO_COMPLEX == 0

/* return the final roots */
roots_quadratic_equation
*solve_quadratic_equation ( double a, double b, double c )
{
	
	roots_quadratic_equation *roots;

	roots = malloc ( sizeof ( roots_quadratic_equation ) );
	roots->root1 = malloc ( sizeof ( complex_number ) );
	roots->root2 = malloc ( sizeof ( complex_number ) );

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
		roots->root2->image = 0;

		return roots;
	}
	else if ( discriminant ( a, b, c ) < 0)
	{
		roots->root1->real = -1 * b / ( 2 * a );
		roots->root1->image = sqrt ( -1 * discriminant ( a, b, c ) ) / ( 2 * a );
		roots->root2->real = roots->root1->real;
		roots->root2->image = -1 * roots->root1->image;

		return roots;
	}
}

#endif /* NO_COMPLEX */ 
/* end of copy */

/* define print style of complex numbers */
void
print_complex_numbers ( double real, double image )
{
	if ( image < 0 && real != 0 )
	{
		printf ( " %f - %f i ", real, (-1) * image );
	}
	else if ( image > 0 && real != 0)
	{
		printf ( " %f + %f i ", real, image );
	}
	else if ( real == 0 && image != 0 )
	{
		printf ( " %f i ", image );
	}
	else if ( real == 0 && image == 0 )
	{
		printf ( "0" );
	}
	else if ( real !=0 && image == 0 )
	{
		printf ( " %f ", real );
	}
}

int
main()
{
	roots_quadratic_equation *testcase;

	testcase =  malloc ( sizeof ( roots_quadratic_equation ) );

#if NO_COMPLEX == 0
	testcase->root1 = malloc ( sizeof ( complex_number ) );
	testcase->root2 = malloc ( sizeof ( complex_number ) );
#endif
	
	testcase = solve_quadratic_equation ( A, B, C );

	//printf("%f\n", solve_quadratic_equation ( A, B, C )->root1); 
	//printf("%f\n", solve_quadratic_equation ( A, B, C )->root2);

	printf ( "\ndiscriminant is: %f\n", discriminant ( A, B, C ) );
	printf ( "quadratic_equation_front is: %f\n\n", quadratic_equation_front ( A, B, C ) );

#if NO_COMPLEX == 1

	printf ( "root1 real is: %f\n", testcase->root1 );
	printf ( "root2 real is: %f\n\n", testcase->root2 );

#elif NO_COMPLEX == 0

	printf ( "root1 real is: %f\n", testcase->root1->real );
	printf ( "root1 image is: %f\n", testcase->root1->image );
	printf ( "root2 real is: %f\n", testcase->root2->real );
	printf ( "root2 image is: %f\n\n", testcase->root2->image );

	printf ( "root1 is: \n" );
	print_complex_numbers ( testcase->root1->real, testcase->root1->image );
	printf ( "\n\nroot2 is: \n" );
	print_complex_numbers ( testcase->root2->real, testcase->root2->image );
	printf ( "\n\n" );

#endif

#if NO_COMPLEX == 0

	free ( testcase->root1 );
	free ( testcase->root2 );

#endif

	free ( testcase );

	return 0;

}
