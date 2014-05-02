//Khamille A. Sarmiento
//CS 301, Khakpour
//Computer Exercise 5.1.2b

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const float e = 2.718281828459045235f;

float compute_f(float x)
{
	return pow(e,x);
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

T(f;P) = 1.71829
Press any key to continue . . .

Compared to the true value of integral e^x from [0,1]
which is e - 1 = 1.71828..., my program calculated an estimate
that is very close using 150 points. Relative error for this
computation is .000005.