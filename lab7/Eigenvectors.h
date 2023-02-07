#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// вывод матрицы на экран
void print_matrix(double** a) 
{ 
		for (int i = 0; i < 5; i++) 
		{
			for (int k = 0; k < 5; k++) 
			{
				cout << setw(12) << a[i][k];
			}
			cout << endl;
		}
}


// создание единичной матрицы
double** e_matrix(int n) 
{ 
	double** e = new double* [n];
	
	for (int i = 0; i < n; i++)
		e[i] = new double[n];
	
	for (int i = 0; i < n; i++) 
	{
		for (int k = 0; k < n; k++) 
		{
			if (i == k)
				e[i][k] = 1;
			else
				e[i][k] = 0;
		}
	}
	
	return e;
}


// создание нулевой матрицы
double** null_matrix(int n) 
{ 
	double** e = new double* [n];
	
	for (int i = 0; i < n; i++)
		e[i] = new double[n];
	
	for (int i = 0; i < n; i++) 
	{
		for (int k = 0; k < n; k++) 
		{
			e[i][k] = 0;
		}
	}
	
	return e;
}


// умножение матриц
double** multiple_matrix(double** a, double** b) 
{ 
	double** c = new double* [5]; // алгоритмы из прошлого семестра
	
	for (int i = 0; i < 5; i++) 
	{	
		// элементы столбцов соответственно
		c[i] = new double[5]; // умножаются на элементы строк
		
		for (int j = 0; j < 5; j++) 
		{	
			// и потом суммируются, образуя новый элемент
			c[i][j] = 0; // для	этого выделяется новая память
						
			for (int k = 0; k < 5; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}
	
	return c;
}


// заполнение матриц B и T
void matrix_b_t(double** t, double** b, double** a, const int n) 
{ 
	double s1 = 0;
	double s2 = 0;
	
	for (int i = 0; i < n; i++) 
	{
		b[i][0] = a[i][0];
	}
	
	for (int j = 0; j < n; j++) 
	{
		t[0][j] = a[0][j] / b[0][0];
	}
	
	for (int k = 1; k < n; k++) 
	{
		for (int i = k; i < n; i++) 
		{
			for (int m = 0; m < k; m++) 
			{
				s1 += b[i][m] * t[m][k];
			}
			
			b[i][k] = a[i][k] - s1;
			
			s1 = 0;
		}
		
		for (int j = k + 1; j < n; j++)
		{
			for (int m = 0; m < k; m++) 
			{
				s2 += b[k][m] * t[m][j];
			}
			
			t[k][j] = 1 / b[k][k] * (a[k][j] - s2);
			
			s2 = 0;
		}
	}
	
	for (int i = 0; i < n; i++) 
	{
		for (int k = 0; k < n; k++) 
		{
			if (i < k)
				b[i][k] = 0;
		}
	}
	
	for (int i = 0; i < n; i++) 
	{
		for (int k = 0; k < n; k++) 
		{
			if (i > k)
				t[i][k] = 0;
			if (i == k) 
			{
				t[i][k] = 1;
			}
		}
	}
}


// построение обратной матрицы B
void negative_matrix_b(double** b, double** y, int n) 
{ 
		double sum = 0;
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			if (j > i)
				y[i][j] = 0;
			
			else if (j == i)
				y[i][j] = 1 / b[i][i];
			
			else if (j < i) 
			{
				sum = 0;
				
				for (int m = j; m < i; m++)
					sum = sum + b[i][m] * y[m][j];
				
				y[i][j] = -1 / b[i][i] * sum;
			}
		}
	}
}


// заполнение обратной матрицы T
void negative_matrix_t(double** t, double** x, int n) 
{ 
	double sum = 0;
	
	for (int i = n - 1; i >= 0; i--) 
	{
		for (int j = n - 1; j >= 0; j--) 
		{
			if (j < i)
				x[i][j] = 0;
			
			else if (j == i)
				x[i][j] = 1;
			
			else if (j > i) 
			{
				x[i][j] = 0;
				
				for (int m = i + 1; m <= j; m++)
					x[i][j] = x[i][j] - t[i][m] * x[m][j];
			}
		}
	}
}


// заполнение обратной матрицы А
void negative_matrix_a(double** a, double** x, double** y, int n)
{ 
	double sum = 0;
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++) 
		{
			for (int m = 0; m < n; m++)
				sum += x[i][m] * y[m][j];
			
			a[i][j] = sum;
			
			sum = 0;
		}
	}
}
double** minV(double** A) 
{
	int n = 5;
	double** B = new double* [n];
	double** T = new double* [n];
	double** X = new double* [n];
	double** Y = new double* [n];
	double** A_neg = new double* [n];
	
	for (int i = 0; i < n; i++) 
	{
		B[i] = new double[n];
	}
	
	for (int i = 0; i < n; i++) 
	{
		T[i] = new double[n];
	}
	
	for (int i = 0; i < n; i++) 
	{
		X[i] = new double[n];
	}
	
	for (int i = 0; i < n; i++) 
	{
		Y[i] = new double[n];
	}
	
	for (int i = 0; i < n; i++) 
	{
		A_neg[i] = new double[n];
	}
	
	matrix_b_t(T, B, A, n);
	
	negative_matrix_b(B, Y, n);
	
	negative_matrix_t(T, X, n);
	
	negative_matrix_a(A_neg, X, Y, n);
	
	for (int i = 0; i < n; i++)
		delete B[i];
	
	delete[] B;
	
	for (int i = 0; i < n; i++)
		delete T[i];
	
	delete[] T;
	
	for (int i = 0; i < n; i++)
		delete X[i];
	
	delete[] X;
	
	for (int i = 0; i < n; i++)
		delete Y[i];
	
	delete[] Y;
	
	return A_neg;
}
