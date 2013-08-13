/*
 * complex.h - complex numbers evaluations
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

#ifndef _COMPLEX_H
#define _COMPLEX_H

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct
__complex_number
{
	double real;
	double image;
} complex_number;

/* list of operations on complex numbers */
complex_number
*complex_number_conjugate( complex_number * );

complex_number
*complex_number_addition ( complex_number *, complex_number * );

complex_number
*complex_number_subtraction ( complex_number *, complex_number * );

complex_number
*complex_number_multiplication ( complex_number *, complex_number * );

complex_number
*complex_number_division ( complex_number *, complex_number * );

#endif /* _COMPLEX_H */
