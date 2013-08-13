/*
 * complex.c - complex numbers evaluations
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

#include"complex.h"

/* list of operations on complex numbers */
complex_number
*complex_number_conjugate ( complex_number *number )
{
	complex_number *result;

	result->real = number->real;
	result->image = (-1) * number->image;

	return result;
}

complex_number
*complex_number_addition ( complex_number *number1, complex_number *number2 )
{
	complex_number *result;

	result->real = number1->real + number2->real;
	result->image = number1->image + number2->image;

	return result;
}

complex_number
*complex_number_subtraction ( complex_number *number1, complex_number *number2 )
{
	complex_number *result;

	result->real = number->real + number2->real;
	result->image = number1->image + number->image;

	return result;
}

complex_number
*complex_number_multiplication ( complex_number *number1, complex_number *number2 )
{
	complex_number *result;

	result->real = a * c - b * d;
	result->image = a * d + b * c;

	return result;
}

complex_number
*complex_number_multiplication ( complex_number *number1, complex_number *number2 )
{
	complex_number *result;

	result->real = ( a * c + b * d ) / ( c * c + d * d );
	result->image = ( b * c - a * d ) / ( c * c + d * d );

	return result;
}
