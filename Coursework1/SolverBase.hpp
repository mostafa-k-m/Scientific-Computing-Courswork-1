using namespace std;

class SolverBase
{
public:
    vector<float> solution;

    float get_abs_max_index(vector<float> vec, int dim, int row_ix)
    {
        float max = vec[row_ix];

        max = abs(vec[row_ix]);

        float temp;
        int max_ix = row_ix;

        for (int i = row_ix; i < dim; ++i)
        {
            temp = abs(vec[i]);

            if (temp > max)
            {
                max = temp;
                max_ix = i;
            }
        }
        return max_ix;
    }

    Matrix find_pivot(Matrix A, int row_ix)
    {
        vector<float> col = A.get_column(row_ix);
        int ix_of_pivot = get_abs_max_index(col, A.dim, row_ix);
        if (ix_of_pivot != row_ix)
        {
            A.swap_rows(ix_of_pivot, row_ix);
        }
        return A;
    }

    Matrix rearrange_rows(Matrix A, int dim)
    {
        for (int i = 0; i < dim - 1; ++i)
        {
            A = find_pivot(A, i);
            vector<float> temp;
        }
        return A;
    }

    void print_aug_matrix(Matrix A)
    {
        vector<float> temp;
        cout << setw(10) << " ";
        for (int i = 0; i < A.dim + 1; ++i)
        {
            cout << setw(10) << "col " << i;
        }
        cout << endl
             << endl;
        for (int i = 0; i < A.dim; ++i)
        {
            temp = A.get_row(i);
            cout << setw(10) << "Row " << i << ": ";
            for (int j = 0; j < A.dim + 1; ++j)
            {
                cout << setw(10) << temp[j];
            }
            cout << endl
                 << endl;
        }
        cout << endl
             << endl;
    }

    Matrix convert_to_triangular(Matrix A)
    {
        int ix_of_pivot;
        for (int ix = 0; ix < A.dim; ++ix)
        {
            ix_of_pivot = ix;
            float pivot = A.get_row(ix_of_pivot)[ix_of_pivot];
            for (int i = ix_of_pivot + 1; i < A.dim; ++i)
            {
                float number_to_remove = A.get_row(i)[ix_of_pivot];
                float coeff = -1 * number_to_remove / pivot;
                A.matrix_row_operation(coeff, ix_of_pivot, i);
            }
        }
        return A;
    }

    vector<float> get_solution(Matrix A)
    {
        vector<float> temp_vec;
        float temp;
        temp_vec.push_back(A.get_row(A.dim - 1)[A.dim]);
        for (int i = A.dim - 2; i >= 0; --i)
        {
            temp = A.get_row(i)[A.dim];
            for (int j = A.dim - 1; j > i; --j)
            {
                temp += -1 * A.get_row(i)[j] * temp_vec[-1 * (j + 1 - A.dim)];
            }
            temp_vec.push_back(temp);
        }

        vector<float> solution;
        for (int i = A.dim - 1; i >= 0; --i)
        {
            solution.push_back(temp_vec[i]);
        }

        return solution;
    }

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

    bool determinant_check(Matrix A)
    {
        float determinant_value = 1;
        for (int i = 0; i < A.dim; ++i)
        {
            determinant_value *= A.get_row(i)[i];
        }

        if (determinant_value != 0)
        {
            return (true);
        }
        else
        {
            return (false);
        }
    }
};
