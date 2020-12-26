//
//  NewtonInterpolator.hpp
//  Interpolation
//
//  Created by Wael Aboulezz on 23/12/2020.
//

#ifndef NewtonInterpolator_hpp
#define NewtonInterpolator_hpp

#include <stdio.h>
#include <vector>
using namespace std;

class NewtonInterpolator
{
public:
    vector<double> fit(const vector<double> &x, vector<double> f);
    void writeNewtonPolynomial(const vector<double> &a);
    double interpolate(const vector<double> &a, double xval);
};
#endif /* NewtonInterpolator_hpp */
