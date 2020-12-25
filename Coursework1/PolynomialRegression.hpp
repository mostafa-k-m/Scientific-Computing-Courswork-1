#include "Matrix.hpp"
#include "SolveGaussElimination.hpp"
#include "SolveSeidle.hpp"
#include <vector>
#include <iostream>

using namespace std;

class PlynomialRegression
{

public:
    vector<float> polynomial_coeffs;
    vector<float> dummy_vec;
    vector<vector<float>> dummy_mat;

    int m; // order of polynomial
    float n;

    vector<float> solution;

    vector<float> row_algorithm_left(float x, int n_row)
    {
        vector<float> vec;
        for (int i = 0; i < m; i++)
        {
            if ((i == 0) && (n_row == 0))
            {
                vec.push_back(0);
            }
            else
            {
                float x_ = x;
                for (int j = 1; j < n_row + i; j++)
                {
                    x_ *= x;
                }
                vec.push_back(x_);
            }
        }
        return (vec);
    }

    float row_algorithm_right(float x, float y, int n_row)
    {
        if (n_row == 0)
        {
            return y;
        }
        else
        {
            float x_ = x;
            for (int j = 1; j < n_row; j++)
            {
                x_ *= x;
            }
            return x_ * y;
        }
    }

    void fit(vector<float> x, vector<float> y)
    {
        n = x.size();
        vector<vector<float>> mat = dummy_mat;
        vector<float> b = dummy_vec;

        for (int i = 0; i < n; i++)
        {
            float x_ = x[i];
            vector<float> row;

            float y_ = y[i];
            float b_;
            for (int j = 0; j < m; j++)
            {
                row = row_algorithm_left(x_, j);
                for (int k = 0; k < m; k++)
                {
                    mat[j][k] += row[k];
                }

                b_ = row_algorithm_right(x_, y_, j);
                b[j] += b_;
            }
        }
        mat[0][0] = n;
        Matrix A = Matrix(mat);

        SolveGaussElimination sol_g = SolveGaussElimination(A, b, true);
        SolveSeidle sol_s = SolveSeidle(A, b, 30);

        solution = sol_g.solution;

        this->solution > solution;
    }

    vector<float> predict(float start, float end, float step)
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
        return(y);
    }

    PlynomialRegression(int m_)
    {
        m = m_ + 1;
        for (int i = 0; i < m; i++)
        {
            dummy_vec.push_back(0);
        }
        for (int i = 0; i < m; i++)
        {
            dummy_mat.push_back(dummy_vec);
        }
        this->m > m;
        this->dummy_mat > dummy_mat;
        this->dummy_vec > dummy_vec;
    }
};
