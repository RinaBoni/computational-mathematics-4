#pragma once
#include <iostream>
#include <locale>
#include <cmath>
#include <cstdlib>

using namespace std;


//функция под буквой А
double f(double x) 
{ 
		return 1 / sqrt(pow(x, 2) + 0.5);
}


// вычисление интеграла по формуле трапеций
double first_method(double a, double b, int n) 
{ 
	double h = (b - a) / n; // можно заменить вычислением интеграла от линейной функции
	
	double w = 0;
	
	for (int k = 0; k < n; k++) 
	{
		double x = a + k * h; // сам метод был благополучно списан с учебника
		
		w = w + f(x);
	}
	
	w = (2 * w + f(a) + f(b)) * h / 2; // <-- интеграл приобретёт следующий вид
	
	return w;
}


void first_task() 
{
	cout << "-------------------- Задание №А: --------------------" << endl;
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
			cout << "Результат = " << dop << endl;
			break;
		}
	}
}


//функция под буквой Б
double f2(double x) 
{ 
	return cos(x) / (x + 2);
}


// вычисление по формуле Симпсона
double second_method(double a, double b, int m) 
{ 
	double h = (b - a) / (2 * m); // или формула параболичных трапеций
	
	double s = 0, s1 = 0, s2 = 0; // пусть число отрезков чётно, соответственно
	
	double x;
	
	// делим на 2 * m
	for (int k = 1; k <= m; k++) 
	{
		x = a + (2 * k - 1) * h; // метод очень похож

		s1 = s1 + f2(x); //только везде двойки
	}

	// опять же скопировано из учебника
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
	cout << "-------------------- Задание №Б: --------------------" << endl;
	cout << "f = cos(x) / (x + 2)\na = 0.4\nb = 1.2" << endl;
	
	double a = 0.4, b = 1.2;
	
	int m = 4;
	
	cout << "Результат = " << second_method(a, b, m) << endl;
}
