/*
 * equation.h - evaluate different kinds of equations
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

#ifndef _EQUATION_H
#define _EQUATION_H

/*
 * NO_COMPLEX = 0: use complex numbers
 *    ...     = 1: use real numbers
 */
#define NO_COMPLEX 0

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#include"complex.h"

#if NO_COMPLEX == 1

typedef struct
__roots_quadratic_equation
{
	double root1;
	double root2;
} roots_quadratic_equation;

#elif NO_COMPLEX == 0

typedef struct
__roots_quadratic_equation
{
	complex_number *root1;
	complex_number *root2;
} roots_quadratic_equation;

#endif /* NO_COMPLEX */

/* evaluate part of the equation */
double
quadratic_equation_front ( double, double, double );

/* judge how many roots equation has */
double
discriminant ( double, double, double );

/* get the final roots */
roots_quadratic_equation
*solve_quadratic_equation ( double, double, double );

#endif /* _EQUATION_H */


