using namespace std;

class RegressionBase
{

public:
    vector<double> polynomial_coeffs;
    vector<double> dummy_vec;
    vector<vector<double>> dummy_mat;

    int m; // order of polynomial
    double n;

    vector<double> solution;

    RegressionBase()
    {

    }
};
