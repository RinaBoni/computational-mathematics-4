#pragma once
#include <iostream>
#include <locale>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;


// метод Лагранжа
double lagrange_method(double* mx, double* my, double x, int n) 
{ 
	double l = 0;
	
	// заключается в подборе функции y = f(x)
	for (int k = 0; k < n; k++) 
	{
		// из заданного класса функций, так чтобы выполнялись
		double ch = 1;

		// равенства f(x0) = y0, f(x1) = y1 и так далее
		double zm = 1;

		// это можно сделать через формулу из учебника
		for (int i = 0; i < n; i++) 
		{
			// и числитель, и знаменатель состоят из произведений
			if (i != k) 
			{
				// которые вычисляются через следующий цикл:
				ch *= (x - mx[i]);
				zm *= (mx[k] - mx[i]);
			}
		}
		l += my[k] * ch / zm;
		// и эта дробь умножается на сумму элементов заданной функции
	}
	return l;
}


// вывод массива на экран
void print_array(double* m, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		cout << setw(8) << m[i] << " ";
	}
	cout << endl;
}


// вывод вектора на экран
void print_vector(vector<vector<double>>& m) 
{	
	for (int i = 0; i < m.size(); i++) 
	{
		for (int j = 0; j < m[i].size(); j++)
			cout << setw(9) << m[i][j] << " ";

		cout << endl;
	}
}


// Разделённая разность для метода Ньютона
void razdel_method(vector<vector<double>>& y, double* x, double* f, int n) 
{
		for (int m = 1; m < n; m++) 
		{
			// вычисляется по формуле
			for (int k = 0; k < n - m; k++) 
			{
				// где каждый элемент заданной функции Y
				if (m == 1)
					// вычисляется отношением разности следующих
					y[k][m] = (f[k + 1] - f[k]) / (x[k + 1] - x[k]);
				
				// элементов с текущими и разности узлов
				else
					// при этом вычисляется сначала разность
					y[k][m] = (y[k + 1][m - 1] - y[k][m - 1]) / (x[k + m] - x[k]); //первого порядка в узлах xk и xk + 1, а лишь потом
			}
			// разделённая разность порядка m
		}
}


//Метод многочлена Ньютона
double newton_method(vector<vector<double>>& yy, double* ax, double* ay, double x) 
{ 
	double newt = ay[0];
	double prod = 1; // методы различаются тем, что для FN используется
	
	for (int k = 1; k < yy.size(); k++) 
	{ // только её верхняя диагональ, а для FB - только нижняя
		prod = prod * (x - ax[k - 1]); // далее вычисляется по формуле суммы из учебника
		
		newt = newt + yy[0][k] * prod;
	}
	return newt;
}


//Метод многочлена Ньютона
double newton_method_2(double* ax, double* ay, double x, vector<vector<double>>& yy) 
{ 
	double newt = ay[yy.size() - 1];
	double prod = 1;

	for (int k = 1; k < yy.size(); k++) 
	{
		prod = prod * (x - ax[yy.size() - k]);
		newt = newt + yy[yy.size() - k - 1][k] * prod;
	}
	return newt;
}
