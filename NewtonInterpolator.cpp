//
//  NewtonInterpolator.cpp
//  Interpolation
//
//  Created by Wael Aboulezz on 23/12/2020.
//

#include "Coursework1/NewtonInterpolator.hpp"

#include <iostream>
#include <vector>

using namespace std;


vector<double> NewtonInterpolator::fit(const vector<double> &x, vector<double> f)    
{
    int N = x.size();
    vector<double> c(N), temp(N);

    c[0] = f[0];
    for (int i = 1; i < N; i++)
    {
      for (int j = 0; j < N - i; j++) temp[j] = (f[j+1] - f[j]) / (x[j+i] - x[j]);
      f = temp;
      c[i] = f[0];
    }
    vector<double> a(N, 0.0);
    vector<double> p(N), prev(N);
    p[0] = 1;
    a[0] = c[0] * p[0];
    for (int i = 1; i < N; i++)
    {
       prev = p;
       p[0] = -x[i-1] * prev[0];
       a[0] += c[i] * p[0];
       for (int j = 1; j <= i; j++)
       {
          p[j] = prev[j-1] - x[i-1] * prev[j];
          a[j] += c[i] * p[j];
       }
    }

    return a;
}

void NewtonInterpolator::writeNewtonPolynomial(const vector<double> &a)
{
   int N = a.size();
   cout << a[0];
   for (int i = 1; i < N; i++) cout << showpos << a[i] << "x^" << noshowpos << i;
   cout << '\n';
}


//void NewtonInterpolator::addPoints(const vector<double> &x, vector<double> f)
//{
//   int N = a.size();
//   cout << a[0];
//   for (int i = 1; i < N; i++) cout << showpos << a[i] << "x^" << noshowpos << i;
//   cout << '\n';
//}

double NewtonInterpolator::interpolate(const vector<double> &a, double xval)
{
    int N = a.size();
    double result = a[N-1];
    for (int i = N-2; i >= 0; i--) result = a[i] + xval * result;
    return result;
}
