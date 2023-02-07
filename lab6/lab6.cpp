#include "Differncial.h"


int main() 
{
	system("chcp 1251");

	cout << "-------------------- Условие: --------------------" << endl;
	cout << "y' = (5 * x^2 - 2) * cos(y);\nx_0 = 0;\ny_0 = 1;\nh = 0.1;\ne = 0.001;" << endl;
	
	double x_0 = 0, y_0 = 1, h = 0.1, e = 0.001;
	
	cout << "-------------------- Решение: --------------------" << endl;
	cout << "Метод Эйлера:" << endl;
	
	euler_method(x_0, y_0, h, e);
	
	cout << endl;
	cout << "Модифицированный метод Эйлера:" << endl;
	
	euler_method_mod(x_0, y_0, h, e);
	
	cout << endl;
	cout << "Метод Рунге-Кутта:" << endl;
	
	runge_kutta_method(x_0, y_0, h, e);
	
	cout << endl;
	cout << "Метод Адамса:" << endl;
	
	adams_method(x_0, y_0, h, e);
	
	cout << endl;
	
	system("pause");
	
	return 0;
}