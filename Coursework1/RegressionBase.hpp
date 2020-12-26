using namespace std;

class RegressionBase
{

public:
    vector<float> polynomial_coeffs;
    vector<float> dummy_vec;
    vector<vector<float>> dummy_mat;

    int m; // order of polynomial
    float n;

    vector<float> solution;

    vector<float> predict(float start, float end, float step, bool verbose=false)
    {
        vector<float> y;
        
        for (float i = start; i <= end; i += step)
        {
            float y_ = solution[0];
            for (int j = 1; j < m; j++)
            {
                float y__ = i * solution[j];
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
