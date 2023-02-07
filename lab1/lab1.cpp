#include <iostream>
#include <math.h>

using namespace std;

float f(float x);               //f(x)
float df(float x);              //производная первого порядка f'(x)
float ddf(float x);             //производная второго порядка f''(x)
float g(float x);               //g(x)
float dg(float x);              //производная первого порядка g'(x)
float ddg(float x);             //производная второго порядка g''(x)
float half(float a, float b, float k);   //Метод половинного деления
float comb(float a, float b, float k);   //Комбинированный метод хорд и касательных

int main()
{
    system("chcp 1251");
    float a, b, i, j;

    cout << "enter a and b";
    cin >> a >> b;
    
    cout << "Метод половинного деления: " << half(a, b, i);
    cout << "Комбинированный метод хорд и касательных: " << comb(a, b, j);
    if (i > j)
        cout << "для метода половинного деления потреболвалось больше итераций";
    else
        cout << "для Комбинированного метода хорд и касательных потребовалось больше итераций";
}

//g(x)
float g(float x)
{
    return -2 * pow(x, 3) - pow(x, 2) + 5 * x + 1;
}

////производная первого порядка g'(x)
float dg(float x)
{
    return -6 * pow(x, 2) - 2 * x + 5;
}

//производная второго порядка g''(x)
float ddg(float x)
{
    return -12 * x - 2;
}

//f(x)
float f(float x)
{
    return x + pow(2, x) + 5;
}

//производная первого порядка f'(x)
float df(float x)
{
    return 1 + log(2) * pow(2, x);
}

//производная второго порядка f''(x)
float ddf(float x)
{
    return pow(log(2), 2) * pow(2, x);
}

//Метод половинного деления
float half(float a, float b, float k)
{
    float c, e = 0.0001;
    k = 0;
    while ((b - a) > (2 * e))
    {
        c = (a + b) / 2;
        if ((f(a) * f(c)) < 0)
            b = c;
        else
        {
            if ((f(b) * f(c)) < 0)
                a = c;
            else
                return (a + b) / 2;
        }
        k++;
    }

    return (a + b) / 2;
}

// Комбинированный метод хорд и касательных
float comb(float a, float b, float k)
{
    float d, c, e = 0.0001;
    k = 0;
    while ((b - a) > (2 * e))
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if ((f(a) * ddf(a)) > 0)
        {
            d = a - f(a) / df(a);
            a = d;
            b = c;
        }
        else
            if ((f(b) * ddf(b)) > 0)
            {
                d = b - f(b) / df(b);
                b = d;
                a = c;
            }
    }
    k++;
    return (a + b) / 2;
}

