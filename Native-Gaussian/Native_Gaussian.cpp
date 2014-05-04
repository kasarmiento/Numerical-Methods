//Khamille S.
//CS 301 Khakpour
//Chapter 2.1, #10

#include <iostream>
#include <math.h>

using namespace std;

void Naive_Gauss(int n, float a[5][5], float b[5], float x[5])
{
	float sum, xmult;
//	float a[n][n], b[n], x[n];

	for(int k = 1; k <= n-1; k++)
	{
		for(int i = k + 1; i <= n; i++)
		{
			xmult = a[i][k]/a[k][k];
			a[i][k] = xmult;
			for(int j = k + 1; j <= n; j++)
			{
				a[i][j] = a[i][j] - xmult * a[k][j];
			}
			b[i] = b[i] - xmult * b[k];
		}
	}
	x[n] = b[n] / a[n][n];
	for(int i = n - 1; i <= 1; i--)
	{
		sum = b[i];
		for(int j = i + 1; j <= n; j++)
		{
			sum = sum - a[i][j] * x[j];
		}
		x[i] = sum / a[i][i];
	}
}


int main(){

	float a[][5] = {
		{0, 0, 0, 0, 0},
		{0, 15, -2, -6, 0},
		{0, -2, 12, -4, -1},
		{0, -6, -4, 19, -9},
		{0, 0, -1, -9, 2}};
	float b[5];
	float x[5];
	for(int n = 4; n <= 5; n++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				a[i][j] = pow((float) (i + 1), (float) (j-1));
				cout << "a" << i << "," << j << " = " << a[i][j] << endl;
			}
			b[i] = (pow((float) (i + 1), (float) n) - 1) / i;
			cout << "b" << i << " = " << b[i] << endl;
		}
		Naive_Gauss(n, a, b, x);
		cout << "n = " << n << endl;
	}

	return 0;
}



