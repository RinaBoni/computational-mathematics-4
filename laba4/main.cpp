#include "Derivatives.h"

int main() 
{
	system("chcp 1251");

	double x_0 = M_PI_4, M_1 = 8, M_2 = 32;
	double e = 0.001;
	double h;
	
	cout << "-------------------- Задание №1: --------------------" << endl
		<< "f(x) = sin^2(x)\nx_0 = 1\nM_1 = 8\nM_2 = 32" << endl;
	cout << "-------------------- Решение №1: --------------------";
	
	h = sqrt(e * 6 / M_1);
	
	cout << endl << "h = " << h << endl;
	cout << "Формула №1: " << d_f(x_0, h) << endl;
	
	h = pow(e * 30 / M_2, 0.25);
	
	cout << "h = " << h << endl;
	cout << "Формула №2: " << d_f_2(x_0, h) << endl;
	
	vector<double> x = { -1.8, -0.2, 1.4, 3.0, 4.6, 6.2, 7.8, 9.4 };
	vector<double> y = { -1.56371, -0.15789, 1.00336, 1.95001, 2.70976, 3.30707, 3.76434, 4.10153};
	
	cout << "-------------------- Задание №2: --------------------" << endl;
	cout << "x[]: ";
	
	print_vector(x);
	
	cout << "y[]: ";
	
	print_vector(y);
	
	vector<vector<double>> delta_y(y.size(), vector<double>(y.size()));
	
	for (int i = 0; i < y.size() - 1; i++) 
	{
		// вычисление конечных разностей
		for (int j = 0; j < y.size() - i - 1; j++) 
		{
			if (i == 0)
				delta_y[i][j] = y[j + 1] - y[j];
			// <-- строчка с величиной, называемой конечной
			else 
			{
				// разностью первого порядка, вычисляемой по формуле
					delta_y[i][j] = delta_y[i - 1][j + 1] - delta_y[i - 1][j]; //< --величина конечной разности m - го порядка
			}
		}
	}
	
	cout << "-------------------- Решение №2: --------------------" << endl;
	cout << "------------ Таблица конечных разностей: ------------" << endl;
	
	for (int j = 0; j < y.size(); j++) 
	{
		for (int i = 0; i < y.size() - j - 1; i++) 
		{
			if (delta_y[i][j] > 0)
				cout << setw(9) << delta_y[i][j];
			else
				cout << setw(9) << delta_y[i][j];
		}
		if (j != y.size() - 1)
			cout << endl;
	}
	
	cout << "Результат: ";
	
	vector<double> deriv_y(y.size() - 3);
	
	for (int m = 0; m < deriv_y.size(); m++) //вычисление производной первого порядка
	{
		for (int i = 0; i <= m; i++)
			deriv_y[m] += pow(-1, i) * delta_y[i][1] / (i + 1);
		cout << setw(9) << deriv_y[m] / x[1];
	}

	cout << endl;

	system("pause");
	
	return 0;
}