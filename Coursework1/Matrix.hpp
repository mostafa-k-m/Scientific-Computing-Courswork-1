using namespace std;

class Matrix
{
public:
    int dim;
    vector<vector<float>> mat;

    // constructor that takes input from the CLI
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

    // contructor that takes a vector of vectors of floats
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