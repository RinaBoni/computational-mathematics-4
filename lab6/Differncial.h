#pragma once
#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


// �������� ��������� �������
double f(double x, double y) 
{ 
	return (5 * pow(x, 2) - 2) * cos(y);
}



// ����� ������
void euler_method(double x0, double y0, double h, double e) 
{ 
	double x = x0, y = y0;
	// �������� ������������������ ��������
	
	for (int i = 0; i < 11; i++) {
		
		// ��������� xk = x0 + k * h.
		cout << setw(9) << y;
		
		// � � � ������� �������� ������������������
		y = y + h * f(x, y);
		
		// <-- �������� yk+1 = yk + h * f(xk,yk);
		x = x + h;
		
		// <-- ���������� ������������������ xk
	}
}



//���������������� ����� ������
void euler_method_mod(double x0, double y0, double h, double e) 
{ 
	double x = x0, y = y0;
	// ����� ���������� ����

	for (int i = 0; i < 11; i++) 
	{
		// ������� ����� ������� �������
		cout << setw(9) << y;

		// �������� ������� ���������
		y = y + h * f(x + h / 2, y + h / 2 * f(x, y));

		x = x + h;
	}
}



// ����� ����������
void runge_kutta_method(double x0, double y0, double h, double e) 
{
	vector<double> z(4);
	// ����������� ������� ������ ����
	double x = x0, y = y0;
	
	for (int i = 0; i < 11; i++) 
	{	// ����������� ������������ �� ����� k(k = 1, n)
		z[0] = h * f(x, y);
		z[1] = h * f(x + h / 2, y + z[0] / 2);
		z[2] = h * f(x + h / 2, y + z[1] / 2);
		z[3] = h * f(x + h, y + z[2]);

		cout << setw(9) << y;

		// <-- ����� ���������� �������������� �������
		y = y + (z[0] + 2 * z[1] + 2 * z[2] + z[3]) / 6; 
		x = x + h;
	}
	return;
}



// ����� ������
void adams_method(double x0, double y0, double h, double e) 
{ 
	vector<double> z(4), y_k(4), x_k(4);
	double x = x0, y = y0;
	double t = 0;
	y_k[0] = y0;
	x_k[0] = x0;
	cout << setw(9) << y0;

	// ���������� ������ ����� - ����� ��������� ������������
	for (int i = 1; i < 11; i++) 
	{ 
			if (i < 4) 
			{
				z[0] = h * f(x, y);
				z[1] = h * f(x + h / 2, y + z[0] / 2);
				z[2] = h * f(x + h / 2, y + z[1] / 2);
				z[3] = h * f(x + h, y + z[2]);
				y = y + (z[0] + 2 * z[1] + 2 * z[2] + z[3]) / 6;
				x = x + h;
				y_k[i] = y; // �� ���������� ������ �����-�����
				x_k[i] = x; // ����� ���� ���������� ������������ �� �������� ����
			}
			else 
			{
				t = 55 * f(x_k[3], y_k[3]) - 59 * f(x_k[2], y_k[2]) + 37 * f(x_k[1], y_k[1]) - 9 * f(x_k[0], y_k[0]);
				y = y + (h / 24) * t;
				x_k[0] = x_k[0] + h;
				x_k[1] = x_k[1] + h;
				x_k[2] = x_k[2] + h;
				x_k[3] = x_k[3] + h;
				y_k[0] = y_k[1];
				y_k[1] = y_k[2];
				y_k[2] = y_k[3];
				y_k[3] = y;
			}
		cout << setw(9) << y;
	}
	return;
}
