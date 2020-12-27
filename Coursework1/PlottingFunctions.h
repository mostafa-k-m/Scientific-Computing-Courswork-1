#include "../Matplot/matplotlibcpp.h"
namespace plt = matplotlibcpp;

class PlotLineScatter
{
    vector<double> x;
    vector<double> y;
    vector<double> x_scatter;
    vector<double> y_scatter;
    string filename;
    
    void gen_plot(){
        plt::figure_size(1200, 780);
        plt::plot(x, y);
        plt::scatter(x_scatter, y_scatter_, 10,{{"color", "red"}});
        plt::legend();
        plt::save("./" + filename);
    }

    PlotLineScatter(vector<double>  x_, vector<double>  y_, vector<double>  x_scatter_, vector<double>  y_scatter_, string filename_)
    {
        x = x_;
        y = y_;
        x_scatter = x_scatter_;
        y_scatter = y_scatter_;
        filename = filename_;
    }
}