#include "Interpolation.h"

int main() 
{
	system("chcp 1251");

	double x = -0.2;
	
	const int n = 6;
	
	double m_x[n] = { -1.3, -0.3, 0, 1.4, 1.9, 3.1 };
	
	double m_y[n] = { 5.04777, -3.88773, 0, 29.24544, 26.00169, 0.64821 };
	
	vector<vector<double>> y(n, vector<double>(n));
	
	cout << "-------------------- Входные данные: --------------------"
		<< endl << "x = " << x << endl << "Массив x[i]: ";
	
	print_array(m_x, n);
	
	cout << "Массив y[i]: ";
	
	print_array(m_y, n);
	
	cout << "-------------------- Метод Лагранжа: --------------------"
		<< endl << "Результат: " << lagrange_method(m_x, m_y, x, n) << endl;
	
	razdel_method(y, m_x, m_y, n);
	
	cout << "-------------------- Разделённая разность: --------------------" << endl;
	
	print_vector(y);
	
	cout << "-------------------- Метод многочлена Ньютона на Fn(x): --------------------"
		<< endl << "Результат: " << newton_method(y, m_x, m_y, x) << endl
		<< "-------------------- Метод многочлена Ньютона на Bn(x): --------------------"
		<< endl << "Результат: " << newton_method_2(m_x, m_y, x, y) << endl;
	
	system("pause");
	
	return 0;
}