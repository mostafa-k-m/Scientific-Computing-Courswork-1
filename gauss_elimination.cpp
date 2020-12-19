#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Matrix
{
public:
    int dim;
    vector<vector<float>> mat;

    Matrix(int x)
    {
        dim = x;
        for (int i = 0; i < dim; ++i)
        {
            float input;
            vector<float> tempVec;
            for (int j = 0; j < dim; ++j)
            {
                cout << "Enter matrix element " << i + 1 << " , " << j + 1 << ": ";
                cin >> input;
                tempVec.push_back(input);
            }
            mat.push_back(tempVec);
        }
        this->mat > mat;
        this->dim > dim;
    }

    void augment_matrix(vector<float> vec)
    {
        if (vec.size() != dim)
        {
            cout << "vector is of in correct size";
        }
        else
        {
            for (int i = 0; i < dim; ++i)
            {
                mat[i].push_back(vec[i]);
            }
        }
    }

    vector<float> get_row(int x)
    {
        vector<float> temp = mat[x];
        return temp;
    }

    vector<float> get_column(int x)
    {
        vector<float> temp;
        for (int i = 0; i < dim; ++i)
        {
            temp.push_back(mat[i][x]);
        }
        return temp;
    }

    void swap_rows(int row1, int row2)
    {
        vector<float> temp = get_row(row1);
        mat[row1] = get_row(row2);
        mat[row2] = temp;
    }

    float get_abs_max(vector<float> vec)
    {
        float max;
        float temp;

        if (vec[0] >= 0)
        {
            max = vec[0];
        }
        else
        {
            max = vec[0] * -1;
        }

        for (int i = 0; i < dim; ++i)
        {

            if (vec[i] >= 0)
            {
                temp = vec[i];
            }
            else
            {
                temp = vec[i] * -1;
            }

            if (temp > max)
            {
                max = temp;
            }
        }

        return max;
    }

    void scale_matrix()
    {
        for (int i = 0; i < dim; ++i)
        {
            vector<float> temp = get_row(i);
            float max = get_abs_max(temp);
            for (int j = 0; j < temp.size(); ++j)
            {
                mat[i][j] = temp[j] / max;
            }
        }
    }

    void matrix_row_operation(float coeff, int pivot_row_ix, int target_row_ix)
    {
        for (int i = 0; i < dim + 1; ++i)
        {
            mat[target_row_ix][i] += coeff * mat[pivot_row_ix][i];
        }
    }

    void row_echelon_form()
    {
        for (int i = 0; i < dim; ++i)
        {
            if (mat[i][i] != 1 && mat[i][i] != 0)
            {
                float coeff = 1 / mat[i][i];
                for (int j = 0; j < dim + 1; ++j)
                {
                    if (mat[i][j] != 0)
                    {
                        mat[i][j] = coeff * mat[i][j];
                    }
                }
            }
        }
    }

    bool flag_singular()
    {
        for (int i = 0; i < dim - 1; ++i)
        {
            for (int j = i + 1; j < dim; ++j)
            {
                if (mat[i] == mat[j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool flag_ill_conditioned()
    {
        vector<float> temp;
        for (int i = 0; i < dim - 1; ++i)
        {
            for (int j = i + 1; j < dim; ++j)
            {
                for (int k = 0; k < dim; ++k)
                {
                    temp.push_back(mat[i][k] - mat[j][k]);
                }
            }
            if (get_abs_max(temp) <= .001)
            {
                return false;
            }
            temp.clear();
        }
        return true;
    }
};

class Solve
{
public:
    float get_abs_max_index(vector<float> vec, int dim, int row_ix)
    {
        float max = vec[row_ix];

        if (vec[row_ix] >= 0)
        {
            max = vec[row_ix];
        }
        else
        {
            max = vec[row_ix] * -1;
        }

        float temp;
        int max_ix = row_ix;

        for (int i = row_ix; i < dim; ++i)
        {
            if (vec[i] >= 0)
            {
                temp = vec[i];
            }
            else
            {
                temp = vec[i] * -1;
            }

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
                temp += -1 * A.get_row(i)[j] * temp_vec[-1 * (j + 1 - 3)];
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

    Solve(Matrix A, vector<float> b)
    {
        bool singular_flag = A.flag_singular();
        bool ill_conditioned_flag = A.flag_ill_conditioned();
        bool valid_solution = (singular_flag && ill_conditioned_flag);

        if (valid_solution)
        {
            A.augment_matrix(b);
            A = rearrange_rows(A, A.dim);

            cout << "Matrix Rearranged" << endl;
            print_aug_matrix(A);

            A.scale_matrix();
            cout << "Matrix Scaled" << endl;
            print_aug_matrix(A);

            A = convert_to_triangular(A);

            cout << "Matrix in Triangular Form" << endl;
            print_aug_matrix(A);

            cout << "Matrix in Row Echelon Form" << endl;
            A.row_echelon_form();
            print_aug_matrix(A);

            vector<float> solution;
            solution = get_solution(A);
            cout << "The Solution is: " << endl
                 << "(";
            print_solution(solution, A.dim);
        }
        else if (A.flag_singular())
        {
            cout << "This Matrix is ill-conditioned";
        }
        else
        {
            cout << "This Matrix is Singular";
        }
    }
};

int main()
{
    Matrix A = Matrix(3);
    vector<float> vec = {0, 14, 30};
    Solve x = Solve(A, vec);
    return 0;
}
