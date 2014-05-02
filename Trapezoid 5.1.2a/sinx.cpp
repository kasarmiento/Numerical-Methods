//Khamille A. Sarmiento
//CS 301, Khakpour
//Computer Exercise 5.1.2a

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const float pi = 3.1415926535898f;

float compute_f(float x)
{
	return sin(x);
}

int main()
{
	float h, sum = 0, x; //where h = step, and x = current x value
	int n = 149; //number of subintervals
	float a = 0, b = pi; //interval [a,b]

	h = (b - a) / n;
	
	float sum_term_2 = (h/2) * ( compute_f(a) + compute_f(b) ); 

	for(int i = 1; i <= n-1; i++) {
		x = a + i * h;
		sum = sum + compute_f(x);
	}

	sum = sum * h + sum_term_2;

	cout << "T(f;P) = " << sum << endl;

	return 0;
}

T(f;P) = 1.99993
Press any key to continue . . .

Compared to the definite integral's true answer, 2,
using the trapezoid rule on this function with 150 points
returns an estimate that is very close (1.9993 vs. 2) with
.00035 relative error.