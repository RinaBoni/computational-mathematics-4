#pragma once
#include <iostream>
#include <locale>
#include <cmath>
#include <cstdlib>

using namespace std;


//������� ��� ������ �
double f(double x) 
{ 
		return 1 / sqrt(pow(x, 2) + 0.5);
}


// ���������� ��������� �� ������� ��������
double first_method(double a, double b, int n) 
{ 
	double h = (b - a) / n; // ����� �������� ����������� ��������� �� �������� �������
	
	double w = 0;
	
	for (int k = 0; k < n; k++) 
	{
		double x = a + k * h; // ��� ����� ��� ������������ ������ � ��������
		
		w = w + f(x);
	}
	
	w = (2 * w + f(a) + f(b)) * h / 2; // <-- �������� ��������� ��������� ���
	
	return w;
}


void first_task() 
{
	cout << "-------------------- ������� ��: --------------------" << endl;
	cout << "f = 1 / sqrt(pow(x, 2) + 0.5)\na = 1.2\nb = 2.4" << endl;
	
	double a = 1.2, b = 2.4;
	int n = 1;
	double answer = first_method(a, b, n);
	n++;
	
	while (true) 
	{
		double dop = first_method(a, b, n);
		
		if (answer - dop > 0.001) 
		{
			answer = dop;
			n++;
		}
		else 
		{
			cout << "��������� = " << dop << endl;
			break;
		}
	}
}


//������� ��� ������ �
double f2(double x) 
{ 
	return cos(x) / (x + 2);
}


// ���������� �� ������� ��������
double second_method(double a, double b, int m) 
{ 
	double h = (b - a) / (2 * m); // ��� ������� ������������ ��������
	
	double s = 0, s1 = 0, s2 = 0; // ����� ����� �������� �����, ��������������
	
	double x;
	
	// ����� �� 2 * m
	for (int k = 1; k <= m; k++) 
	{
		x = a + (2 * k - 1) * h; // ����� ����� �����

		s1 = s1 + f2(x); //������ ����� ������
	}

	// ����� �� ����������� �� ��������
	for (int k = 1; k < m; k++) 
	{
		x = a + 2 * k * h;
		
		s2 = s2 + f2(x);
		
		s = (4 * s1 + 2 * s2 + f2(a) + f2(b)) * h / 3;
	}
	
	return s;
}
void second_task() 
{
	cout << "-------------------- ������� ��: --------------------" << endl;
	cout << "f = cos(x) / (x + 2)\na = 0.4\nb = 1.2" << endl;
	
	double a = 0.4, b = 1.2;
	
	int m = 4;
	
	cout << "��������� = " << second_method(a, b, m) << endl;
}
