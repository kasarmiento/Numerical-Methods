//Khamille A. Sarmiento
//CS 301, Fall 2013, A. Khakpour

#include <iostream>
#include <cmath>

using namespace std;

float compute_f (float x)
{
	float func_f;
	//func_f = pow(x, 3.f) + 3 * x - 1;
	//func_f = pow(x, 3.f) - 2 * sin(x);
	func_f = x + 10 - x * cosh(50.f/x);
	return (func_f);
}

void bisection (float a, float b, int nmax, float e)
{  
	int n = 0; //step number
	float c = 0.f; //midpoint
	float fa = 0.f; //f(a) 
	float fb = 0.f; //f(b)
	float fc = 0.f; //f(c)
	float error = 0.f; //error here is computed as the difference between b and a

	fa = compute_f(a);
	fb = compute_f(b);

	float signCheck = fa * fb;

	if( signCheck > 0.f ) //if f(a) and f(b) have the same sign
	{
		cout << "a = " << a << "; b = " << b << "; f(a) = " << fa << "; f(b) = " << fb << endl;
		cout << "f(a) and f(b) have the same sign" << endl;
		return;
	}

	error = b - a; 

	for (n = 0; n <= nmax; n++)
	{
		error = error / 2.f;
		c = a + error;
		fc = compute_f(c);
		
		//cout << "a = " << a << "; b = " << b << endl;
		cout << "step number n = " << n << "; c = " << c << "; f(c) = " << fc << "; error (b - a)/2 = " << error << endl;

		if ( abs(error) < e )
		{
			cout << "convergence" << endl; 
			return;
		}

		if ( (fa * fb < 0.f) || (fa * fb == 0.f) ) //if f(a) and f(b) have different signs
		{
			//cout << "diff sign" << endl;
			b = c;
			fb = fc;
		}
		else
		{
			//cout << "same sign" << endl;
			a = c;
			fa = fc; 
		}
	}
	
}

int main ()
{
	//float aVal = 0.f
	//float bVal = 1.f
	//float aVal = 0.5f
	//float bVal = 2.f
	float aVal = 120.f;
	float bVal = 130.f;
	int maxSteps = 20;
	float error = .5f * pow(10.f,-6.f);

	//will call compute_f for function f within Bisection method
	bisection (aVal, bVal, maxSteps, error);

	return 0;
}
