#include "Eigenvectors.h"

int main()
{
	system("chcp 1251");

	double** a = new double* [5];
	
	for (int i = 0; i < 5; i++)
		a[i] = new double[5];
	
	double** b_x;
	double** a_x;
	double** b;
	double** vec = null_matrix(5);
	
	a[0][0] = -1;
	a[0][1] = 1;
	a[0][2] = -5;
	a[0][3] = 2;
	a[0][4] = -4;
	a[1][0] = -5;
	a[1][1] = -3;
	a[1][2] = -3;
	a[1][3] = 0;
	a[1][4] = -1;
	a[2][0] = 2;
	a[2][1] = -1;
	a[2][2] = -5;
	a[2][3] = 0;
	a[2][4] = -5;
	a[3][0] = 0;
	a[3][1] = 4;
	a[3][2] = 1;
	a[3][3] = 2;
	a[3][4] = -1;
	a[4][0] = 5;
	a[4][1] = 1;
	a[4][2] = -3;
	a[4][3] = -3;
	a[4][4] = -5;
	
	const int n = 5;
	
	cout << "-------------------- Матрица A: --------------------" << endl;
	
	print_matrix(a);
	
	vector<double**> data;
	
	a_x = a; // Метод Фробениуса
	for (int k = 2; k <= n; k++) 
	{
		b = e_matrix(n);
		
		for (int j = 0; j < n; j++)
		{
			if (j != n - k)
				b[n - k][j] = -a_x[n - (k - 1)][j] / a_x[n - (k - 1)][n - k];

			else
				b[n - k][j] = 1 / a_x[n - (k - 1)][n - k];
		}
			b_x = minV(b);
			
			a_x = multiple_matrix(multiple_matrix(b_x, a_x), b);
			
			data.push_back(b);
	}
	
	cout << "-------------------- Пересчитанная матрица B: --------------------" << endl;
	
	print_matrix(b);
	
	cout << "-------------------- Обратная матрица B: --------------------" << endl;
	
	print_matrix(b_x);
	
	cout << "-------------------- Новая матрица A: --------------------" << endl;
	
	print_matrix(a_x);
	
	double** temp;
	double s;
	double lambda = 7.79216;
	vector<double**> lambdavectors;
	double** lambdavec = null_matrix(5);
	
	for (int i = 0; i < 5; i++)
	{
		lambdavec[i][0] = pow(lambda, 4 - i);
	}
	
	lambdavectors.push_back(lambdavec);
	
	cout << "-------------------- Лямбда-вектор: --------------------" << endl;
	
	print_matrix(lambdavec);
	
	for (int m = 2; m <= 5; m++)
	{
		temp = data.back();
		data.pop_back();
		lambdavec = lambdavectors.back();
		
		for (int i = 0; i < 5; i++)
		{
			s = 0;
			
			for (int k = 0; k < 5; k++)
			{
				s = s + temp[i][k] * lambdavec[k][0];
			}

			vec[i][0] = s;
		}

		lambdavectors.push_back(vec);
		
	}
	
	cout << "-------------------- Результат: --------------------" << endl;
	
	print_matrix(vec);
	
	for (int i = 0; i < 5; i++)
		delete[] a[i];
	
	delete[] a;
	
	for (int i = 0; i < 5; i++)
		delete[] b[i];
	
	delete[] b;
	
	for (int i = 0; i < 5; i++)
		delete[] b_x[i];
	
	delete[] b_x;
	
	for (int i = 0; i < 5; i++)
		delete[] a_x[i];
	
	delete[] a_x;
	
	for (int i = 0; i < 5; i++)
		delete[] vec[i];
	
	delete[] vec;
	
	for (int i = 0; i < 5; i++)
		delete[] temp[i];
	
	delete[] temp;
	
	system("pause");
	
	return 0;
}