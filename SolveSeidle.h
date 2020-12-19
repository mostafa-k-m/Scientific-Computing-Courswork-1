using namespace std;

class SolveSeidle
{
public:
    int n_iterations;
    vector<float> solution;

    void print_solution(vector<float> solution, int dim)
    {
        cout << "(";
        for (int i = 0; i < dim; ++i)
        {
            if (i == dim - 1)
            {
                cout << solution[i];
            }
            else
            {
                cout << solution[i] << ", ";
            }
        }
        cout << ")" << endl;
    }

    Matrix put_in_diagonal(Matrix A)
    {
        float result;
        for (int i = 0; i < A.dim; i++)
        {

            float sum = 0;
            for (int j = 0; j < A.dim; j++)
                sum += abs(A.get_row(i)[j]);

            sum -= abs(A.get_row(i)[i]);

            if (abs(A.get_row(i)[i]) < abs(sum))
                result += abs(abs(A.get_row(i)[i]) - abs(sum));
        }
    }

    SolveSeidle(Matrix A, vector<float> b, int n)
    {
        vector<float> x;

        bool valid_solution = A.flag_diagonally_dominant();

        if (valid_solution)
        {
            n_iterations = n;
            for (int i = 0; i < A.dim; i++)
            {
                x.push_back(0);
                solution.push_back(0);
            }
            while (n_iterations > 0)
            {
                cout << "iteration " << (n - n_iterations + 1) << ": " << endl;
                for (int i = 0; i < A.dim; i++)
                {
                    solution[i] = (b[i] / A.get_row(i)[i]);
                    for (int j = 0; j < A.dim; j++)
                    {
                        if (j != i)
                        {
                            solution[i] = solution[i] - ((A.get_row(i)[j] / A.get_row(i)[i]) * x[j]);
                            x[i] = solution[i];
                        }
                    }
                }
                print_solution(x, A.dim);
                cout << endl
                     << endl;
                --n_iterations;
            }
            this->solution > solution;
        }
        else
        {
            cout << "This matrix is not in diagonally dominant form. Convergence is not guaranteed!" << endl;
        }
    }
};