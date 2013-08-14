/*
 * mathlib.c - testcase for mathlib
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


#define TEST_CASE_FAC_INT 5 

#include"../lib/mathlib.h"

unsigned int
factoring ( unsigned int integer_number )
{
	unsigned int result;
	result = 1;
	
	while ( integer_number > 0 )
	{
		result = result * integer_number;
		integer_number -= 1;
	}

	return result;
}

int
main ()
{
	printf ( "the factoring of %d is: %d\n", TEST_CASE_FAC_INT, factoring ( TEST_CASE_FAC_INT ) );

	return 0;
}
