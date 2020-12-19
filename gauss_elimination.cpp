#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Matrix
{
public:
    int dim;
    vector<vector<float>> mat;

    // Matrix(int x)
    // {
    //     dim = x;
    //     for (int i = 0; i < dim; ++i)
    //     {
    //         float input;
    //         vector<float> tempVec;
    //         for (int j = 0; j < dim; ++j)
    //         {
    //             cout << "Enter matrix element " << i + 1 << " , " << j + 1 << ": ";
    //             cin >> input;
    //             tempVec.push_back(input);
    //         }
    //         mat.push_back(tempVec);
    //     }
    //     this->mat > mat;
    //     this->dim > dim;
    // }
    
    Matrix(vector<vector<float>> in_mat)
    {   
        mat = in_mat;
        dim = mat.size();
        this->mat > mat;
        this->dim > dim;
    }

    bool augment_matrix(vector<float> vec)
    {
        if (vec.size() != dim)
        {
            cout << "vector is of in correct size";
            return false;
        }
        else
        {
            for (int i = 0; i < dim; ++i)
            {
                mat[i].push_back(vec[i]);
            }
        }
        return true;
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

        max = abs(vec[0]);

        for (int i = 0; i < dim; ++i)
        {
            temp = abs(vec[i]);

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

    bool flag_diagonally_dominant()
    { 
        for (int i = 0; i < dim; i++) 
    {         
            float sum = 0; 
            for (int j = 0; j < dim; j++)              
                sum += abs(mat[i][j]);         
    
            sum -= abs(mat[i][i]); 
    
            if (abs(mat[i][i]) < sum)  
                return false;  
        } 
        return true; 
    } 
};

class Solve
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

    Solve(Matrix A, vector<float> b)
    {
        bool singular_flag = A.flag_singular();
        bool ill_conditioned_flag = A.flag_ill_conditioned();
        bool size_correct = A.augment_matrix(b);

        bool valid_solution = (singular_flag && ill_conditioned_flag && size_correct);



        if (valid_solution)
        {
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

            solution = get_solution(A);
            cout << "The Solution is: " << endl;
            print_solution(solution, A.dim);
        }
        else if (!size_correct)
        {
            cout << "The sizes of the vector and Matrix provided do not match" << endl;
        }
        else if (!ill_conditioned_flag)
        {
            cout << "This Matrix is ill-conditioned";
        }
        else
        {
            cout << "This Matrix is Singular";
        }
        this-> solution > solution;
    }
};

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
            for  (int i = 0; i < A.dim; i++)
            {
                x.push_back(0);
                solution.push_back(0);
            }
            while (n_iterations > 0)
            {
                cout << "iteration " << (n-n_iterations+1) << ": " << endl;
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
                cout << endl << endl;
                --n_iterations;
            }
            this->solution > solution;
        } else {
            cout << "This matrix is not in diagonally dominant form. Convergence is not guaranteed!" << endl;
        }
    }
};

int main()
{
    // vector<vector<float>> v ={{2, 1, -1}, {1, 4, 3}, {-1 ,2 ,7}};
    // Matrix A = Matrix(v);
    // vector<float> b = {0, 14, 30};

    // vector<vector<float>> v ={{2, -1, 0}, {1, -3, 1}, {-1, 1 ,-3}};
    // Matrix A = Matrix(v);
    // vector<float> b = {2, -2, 6};

    // vector<vector<float>> v ={{5, 6, 7}, {6, 3, 9}, {7, 9, 10}};
    // Matrix A = Matrix(v);
    // vector<float> b = {18, 18, 26};

    // vector<vector<float>> v ={{-1,1,-1,1}, {1, 1, 1, 1}, {8, 4 ,2 ,1}, {27, 9, 3, 1}};
    // Matrix A = Matrix(v);
    // vector<float> b = {1, 1, -2, 1};

    vector<vector<float>> v ={{10, 2, -1, 2}, {1, 5, 1, 0}, {1, -2 ,-5 ,1}, {3, 0, 0, 9}};
    Matrix A = Matrix(v);
    vector<float> b = {-4, 1, 2, 10};
    
    Solve x = Solve(A, b);
    cout << endl << endl;

    SolveSeidle y = SolveSeidle(A, b, 30);
    return 0;
}
