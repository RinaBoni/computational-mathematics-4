#pragma once
#include <iostream>
#include <locale>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;


// ����� ��������
double lagrange_method(double* mx, double* my, double x, int n) 
{ 
	double l = 0;
	
	// ����������� � ������� ������� y = f(x)
	for (int k = 0; k < n; k++) 
	{
		// �� ��������� ������ �������, ��� ����� �����������
		double ch = 1;

		// ��������� f(x0) = y0, f(x1) = y1 � ��� �����
		double zm = 1;

		// ��� ����� ������� ����� ������� �� ��������
		for (int i = 0; i < n; i++) 
		{
			// � ���������, � ����������� ������� �� ������������
			if (i != k) 
			{
				// ������� ����������� ����� ��������� ����:
				ch *= (x - mx[i]);
				zm *= (mx[k] - mx[i]);
			}
		}
		l += my[k] * ch / zm;
		// � ��� ����� ���������� �� ����� ��������� �������� �������
	}
	return l;
}


// ����� ������� �� �����
void print_array(double* m, int n) 
{
	for (int i = 0; i < n; i++) 
	{
		cout << setw(8) << m[i] << " ";
	}
	cout << endl;
}


// ����� ������� �� �����
void print_vector(vector<vector<double>>& m) 
{	
	for (int i = 0; i < m.size(); i++) 
	{
		for (int j = 0; j < m[i].size(); j++)
			cout << setw(9) << m[i][j] << " ";

		cout << endl;
	}
}


// ���������� �������� ��� ������ �������
void razdel_method(vector<vector<double>>& y, double* x, double* f, int n) 
{
		for (int m = 1; m < n; m++) 
		{
			// ����������� �� �������
			for (int k = 0; k < n - m; k++) 
			{
				// ��� ������ ������� �������� ������� Y
				if (m == 1)
					// ����������� ���������� �������� ���������
					y[k][m] = (f[k + 1] - f[k]) / (x[k + 1] - x[k]);
				
				// ��������� � �������� � �������� �����
				else
					// ��� ���� ����������� ������� ��������
					y[k][m] = (y[k + 1][m - 1] - y[k][m - 1]) / (x[k + m] - x[k]); //������� ������� � ����� xk � xk + 1, � ���� �����
			}
			// ���������� �������� ������� m
		}
}


//����� ���������� �������
double newton_method(vector<vector<double>>& yy, double* ax, double* ay, double x) 
{ 
	double newt = ay[0];
	double prod = 1; // ������ ����������� ���, ��� ��� FN ������������
	
	for (int k = 1; k < yy.size(); k++) 
	{ // ������ � ������� ���������, � ��� FB - ������ ������
		prod = prod * (x - ax[k - 1]); // ����� ����������� �� ������� ����� �� ��������
		
		newt = newt + yy[0][k] * prod;
	}
	return newt;
}


//����� ���������� �������
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
