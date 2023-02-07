#pragma once
#include <iostream>
#include <locale>
#include <vector>
#define _USE_MATH_DEFINES
#include <math.h>
#include <iomanip>

using namespace std;


//������� �� ������� �1
double f(double x) 
{ 
	return pow(sin(x), 2);
}


// 1-� ������� ��� ������� �� 1 - �� �������
double d_f(double x, double h) 
{
	return (f(x + h) - f(x - h)) / (2 * h);
}


// 2-� ������� ��� ������� �� 1 - �� �������
double d_f_2(double x, double h) 
{
	return (f(x - 2 * h) - 8 * f(x - h) + 8 * f(x + h) - f(x + 2 * h)) / (12 * h);
}


// ����� ������� �� �����
void print_vector(const vector<double>& x) 
{
	for (int i = 0; i < x.size(); i++)
		cout << setw(9) << x[i];
	cout << endl;
}
