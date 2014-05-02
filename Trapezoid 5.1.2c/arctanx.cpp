//Khamille A. Sarmiento
//CS 301, Khakpour
//Computer Exercise 5.1.2c

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

float compute_f(float x)
{
	return atan(x);
}

int main()
{
	float h, sum = 0, x; //h = step, x = current x value
	int n = 149; //number of subintervals
	float a = 0, b = 1; //interval [a,b]

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


T(f;P) = 0.438823
Press any key to continue . . .

After computing the definite integral of arctan(x) from [0,1],
I got the answer 0.438825. Using my trapezoid program and setting
n = 149, I calculated the answer .438823. This answer is very
close to the true answer of the definite integral and has 5 correct
digits.