#include "Coursework1/Coursework1lib.h"

using namespace std;


int main()
{
    // Multiple examples

    vector<vector<double>> v ={{2, 1, -1}, {1, 4, 3}, {-1 ,2 ,7}};
    Matrix A = Matrix(v);
    vector<double> b = {0, 14, 30};

    // vector<vector<double>> v ={{2, -1, 0}, {1, -3, 1}, {-1, 1 ,-3}};
    // Matrix A = Matrix(v);
    // vector<double> b = {2, -2, 6};

    // vector<vector<double>> v ={{5, 6, 7}, {6, 3, 9}, {7, 9, 10}};
    // Matrix A = Matrix(v);
    // vector<double> b = {18, 18, 26};

    // vector<vector<double>> v = {{10, 2, -1, 2}, {1, 5, 1, 0}, {1, -2, -5, 1}, {3, 0, 0, 9}};
    // Matrix A = Matrix(v);
    // vector<double> b = {-4, 1, 2, 10};

    // vector<vector<double>> v ={
    //     {-1,1,-1,1},
    //     {1, 1, 1, 1},
    //     {8, 4 ,2 ,1},
    //     {27, 9, 3, 1}};
    // Matrix A = Matrix(v);
    // vector<double> b = {1, 1, -2, 1};

    SolveGaussElimination x = SolveGaussElimination(A, b, true);

    SolveSeidle y = SolveSeidle(A, b, 30, true);
    return 0;
}