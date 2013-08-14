/*
 * mathlib.h - implementaion of different arithematic operations
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

#include"mathlib.h"

/* small unsigned integer factoring */
unsigned int
factoring ( double int integer_number )
{
	int result;
	result = 1;

	while (interger_number > 0)
	{
		result = result * integer_number;
		integer_number -= 1;
	}

	return result;
}

/* TODO big unsigned integer factoring */



