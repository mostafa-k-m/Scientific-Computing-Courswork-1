#include "Coursework1/PolynomialRegression.hpp"
#include <vector>
#include <iostream>



int main() {
    PlynomialRegression P(2);
    vector<float> vec_x = {0, 1, 2, 3, 4, 5};
    vector<float> vec_y = {2.1, 7.7, 13.6, 27.2, 40.9, 61.1};
    vector<float> x = P.fit(vec_x, vec_y);
    // for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cout << x[j] << " ";
        }
        cout << endl;
    // }
    return(0);
}