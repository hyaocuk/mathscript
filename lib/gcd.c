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


#include"gcd.h"

unsigned int __gcd (unsigned int number1, unsigned int number2) {
	unsigned int remainder;
	unsigned int quotient;
		
	quotient = number1 / number2;
	remainder = number1 - number2 * quotient;
	while(remainder!=0) {
		number1 = number2;
		number2 = remainder;
		quotient = number1 / number2;
		remainder = number1 - number2 * quotient;
	}
	return number2;
}

