/*
 * gcd.c - implementation of greatest common divisor 
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
#define CASE 1 

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

/* the code below should be absolutely the same as the one in the '../lib/' for test */
double
discriminant ( double a, double b, double c )
{
	return b * b - 4 * a * c;
}

double
quadratic_equation_front ( double a, double b, double c )
{
	return sqrt ( discriminant ( a, b, c ) );
}

roots_quadratic_equation *solve_quadratic_equation ( double a, double b, double c )
{
	
	roots_quadratic_equation *roots;

	roots = malloc ( sizeof ( roots_quadratic_equation ) );
	
	if ( discriminant ( a, b, c ) > 0 )
	{
		roots->root1 = (( -1 * b ) + quadratic_equation_front ( a, b, c )) / ( 2 * a );
		roots->root2 = (( -1 * b ) - quadratic_equation_front ( a, b, c )) / ( 2 * a );;
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
		/* TODO: add complex number structure to fix it */
	}
} /* end copy */

int
main()
{
	roots_quadratic_equation *testcase;

	testcase = malloc ( sizeof ( roots_quadratic_equation ) );

	testcase = solve_quadratic_equation ( A, B, C );

	//printf("%f\n", solve_quadratic_equation ( A, B, C )->root1); 
	//printf("%f\n", solve_quadratic_equation ( A, B, C )->root2);

	printf("\ndiscriminant is: %f\n", discriminant ( A, B, C ));
	printf("quadratic_equation_front is: %f\n\n", quadratic_equation_front ( A, B, C ));
	printf("root1 is: %f\n", testcase->root1);
	printf("root2 is: %f\n\n", testcase->root2);

	return 0;
}
