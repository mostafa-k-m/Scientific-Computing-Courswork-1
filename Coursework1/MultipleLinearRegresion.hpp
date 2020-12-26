using namespace std;

class MultipleLinearRegresion : public RegressionBase
{

public:
    vector<float> element_wise_multiplication(vector<float> x1, vector<float> x2) {
        vector<float> vec;

        for (int i = 0; x1.size() < n; i++) {
            vec.push_back(x1[i]*x2[i]);
        }
        return(vec);
    }

    float sum(vector<float> vec) {
        float summation = 0;
        for (int i = 0; vec.size() < n; i++) {
            summation += vec[i];
        }
        return(summation);
    }

    void fit(vector<float> x1, vector<float> x2, vector<float> y, int solver, bool verbose=false)
    {
        vector<vector<float>> mat = dummy_mat;
        vector<float> b = dummy_vec;
        n = x1.size();

        // row1
        vector<float> row1;
        row1.push_back(n);
        row1.push_back(sum(x1));
        row1.push_back(sum(x2));
        mat.push_back(row1);

        // row2
        vector<float> row2;
        row2.push_back(sum(x1));
        row2.push_back(sum(element_wise_multiplication(x1, x1)));
        row2.push_back(sum(element_wise_multiplication(x1, x2)));
        mat.push_back(row2);

        // row3
        vector<float> row3;
        row3.push_back(sum(x2));
        row3.push_back(sum(element_wise_multiplication(x1, x2)));
        row3.push_back(sum(element_wise_multiplication(x2, x2)));
        mat.push_back(row3);

        // b
        b.push_back(sum(y));
        b.push_back(sum(element_wise_multiplication(x1, y)));
        b.push_back(sum(element_wise_multiplication(x2, y)));

        Matrix A = Matrix(mat);
        if (solver == 1) 
        {
            SolveGaussElimination sol = SolveGaussElimination(A, b, verbose);
            solution = sol.solution;
        } else if (solver == 2)
        {
            int it;
            cout << "Please Specify the number of iterations" << endl;
            cin >> it;
            SolveSeidle sol = SolveSeidle(A, b, it, verbose);
            solution = sol.solution;
        } else {
            cout << "Invalid choice for a solver (1 for Gauss Elimination, 2 for Gauss Seidle) Gauss Elimination chosen by default" << endl;
            SolveGaussElimination sol = SolveGaussElimination(A, b, verbose);
            solution = sol.solution;
        }

        this->solution > solution;
    }

    MultipleLinearRegresion()
    {
        for (int i = 0; i < 3; i++)
        {
            dummy_mat.push_back(dummy_vec);
        }
        this->dummy_mat > dummy_mat;
    }
};
