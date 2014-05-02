//Khamille A. Sarmiento
//CS 301, Prof. Khakpour
//Computer Exercise 9.1.2

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//This program finds the least squares line for the introductory
//example in Chapter 9 dealing with Surface Tension S as a linear
//function of temperature T.

double compute_p(double x[], int size) { //calculates the sum of all x values
	double sum = 0.0;
	for(int k = 0; k < size; k++) {
		sum += x[k];
	}
	return sum;
}

double compute_q(double y[], int size) { //calculates the sum of all y values
	double sum = 0.0;
	for(int k = 0; k < size; k++) {
		sum += y[k];
	}
	return sum;
}

double compute_r(double x[], double y[], int size) { //calculates the sum of x*y
	double sum = 0.0;
	for(int k = 0; k < size; k++) {
		sum += x[k] * y[k];
	}
	return sum;
}

double compute_s(double x[], int size) { //calculates the sum of x^2
	double sum = 0.0;
	for(int k = 0; k < size; k++) {
		sum += pow(x[k],2);
	}
	return sum;
}

int main() {

	double x[8], y[8];
	int size = sizeof(x)/sizeof(0.0); //represents m+1
	double p, q, r, s;
	double det;
	double a, b;

	x[0] = 0;
	y[0] = 68.0;
	x[1] = 10;
	y[1] = 67.1;
	x[2] = 20;
	y[2] = 66.4;
	x[3] = 30;
	y[3] = 65.6;
	x[4] = 40;
	y[4] = 64.6;
	x[5] = 80;
	y[5] = 61.8;
	x[6] = 90;
	y[6] = 61.0;
	x[7] = 95;
	y[7] = 60.0;
	
	p = compute_p(x,size);
	q = compute_q(y,size);
	r = compute_r(x,y,size);
	s = compute_s(x,size);

	det = size * s - pow(p,2);
	a = (1/det) * (size * r - p * q);
	b = (1/det) * (s * q - p * r);

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << endl;
	cout << "S = " << fixed << setprecision(2) << a << "T + " << b << "\n" << endl; 

	return 0;

}