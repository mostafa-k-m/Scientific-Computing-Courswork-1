//
//  CubicSpline.hpp
//  Interpolation
//
//  Created by Wael Aboulezz on 25/12/2020.
//

#ifndef CubicSpline_hpp
#define CubicSpline_hpp

#include <vector>
using namespace std;


class band_matrix
{
private:
    std::vector< std::vector<double> > m_upper;
    std::vector< std::vector<double> > m_lower;
public:
    band_matrix() {};
    band_matrix(int dim, int n_u, int n_l);
    ~band_matrix() {};
    void resize(int dim, int n_u, int n_l);
    int dim() const;
    int num_upper() const
    {
        return m_upper.size()-1;
    }
    int num_lower() const
    {
        return m_lower.size()-1;
    }

    double & operator () (int i, int j);
    double   operator () (int i, int j) const;
    double& saved_diag(int i);
    double  saved_diag(int i) const;
    void lu_decompose();
    std::vector<double> r_solve(const std::vector<double>& b) const;
    std::vector<double> l_solve(const std::vector<double>& b) const;
    std::vector<double> lu_solve(const std::vector<double>& b,
                                 bool is_lu_decomposed=false);

};

class Spline
{
public:
    enum bd_type {
        first_deriv = 1,
        second_deriv = 2
    };

private:
    std::vector<double> m_x,m_y;
    std::vector<double> m_a,m_b,m_c;
    double  m_b0, m_c0;
    bd_type m_left, m_right;
    double  m_left_value, m_right_value;
    bool    m_force_linear_extrapolation;

public:

    Spline(): m_left(second_deriv), m_right(second_deriv),
        m_left_value(0.0), m_right_value(0.0),
        m_force_linear_extrapolation(false)
    {
        ;
    }

    std::vector<vector<double>> fitSpline(const std::vector<double>& x,const std::vector<double>& y);
    double interpolateSpline (double x) const;
    double deriv(int order, double x) const;
};

#endif
