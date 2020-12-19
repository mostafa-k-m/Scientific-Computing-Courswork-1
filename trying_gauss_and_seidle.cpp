#include "Coursework1/Matrix.h"
#include "Coursework1/SolveGaussElimination.h"
#include "Coursework1/SolveSeidle.h"

using namespace std;


int main()
{
    // Multiple examples

    // vector<vector<float>> v ={{2, 1, -1}, {1, 4, 3}, {-1 ,2 ,7}};
    // Matrix A = Matrix(v);
    // vector<float> b = {0, 14, 30};

    // vector<vector<float>> v ={{2, -1, 0}, {1, -3, 1}, {-1, 1 ,-3}};
    // Matrix A = Matrix(v);
    // vector<float> b = {2, -2, 6};

    // vector<vector<float>> v ={{5, 6, 7}, {6, 3, 9}, {7, 9, 10}};
    // Matrix A = Matrix(v);
    // vector<float> b = {18, 18, 26};

    // vector<vector<float>> v = {{10, 2, -1, 2}, {1, 5, 1, 0}, {1, -2, -5, 1}, {3, 0, 0, 9}};
    // Matrix A = Matrix(v);
    // vector<float> b = {-4, 1, 2, 10};

    vector<vector<float>> v ={{-1,1,-1,1}, {1, 1, 1, 1}, {8, 4 ,2 ,1}, {27, 9, 3, 1}};
    Matrix A = Matrix(v);
    vector<float> b = {1, 1, -2, 1};

    SolveGaussElimination x = SolveGaussElimination(A, b, true);
    cout << endl
         << endl;

    SolveSeidle y = SolveSeidle(A, b, 30);
    return 0;
}