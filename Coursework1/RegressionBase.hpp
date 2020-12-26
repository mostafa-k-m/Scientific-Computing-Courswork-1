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

    vector<double> predict(double start, double end, double step, bool verbose=false)
    {
        vector<double> y;
        
        for (double i = start; i <= end; i += step)
        {
            double y_ = solution[0];
            for (int j = 1; j < m; j++)
            {
                double y__ = i * solution[j];
                for (int k = 1; k < j; k++)
                {
                    y__ *= i;
                }
                y_ += y__;
            }
            y.push_back(y_);
        }
        if (verbose)
        {
            cout << "( ";
            for (int k = 0; k < 100; k++)
            {
                cout << y[k] << ", ";
            }
            cout << ")" << endl;
        }
        return(y);
    }

    RegressionBase()
    {

    }
};
