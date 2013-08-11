/*
 * gcd_test.c  - test greatest common divisor
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
 */

#define TEST_NUMBER1 12468
#define TEST_NUMBER2 2448

#include"../lib/gcd.h"

/* the code below should be absolutely the same as the one in the '../lib/' */

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


/* test case main function */

int main() {
	unsigned int result;
	result =  __gcd(TEST_NUMBER1, TEST_NUMBER2);
	printf("greatest common divisor of %d and %d is %d\n", TEST_NUMBER1, TEST_NUMBER2, result);

	return 0;
}
