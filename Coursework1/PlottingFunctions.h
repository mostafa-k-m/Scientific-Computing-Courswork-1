#include "../Matplot/matplotlibcpp.h"
namespace plt = matplotlibcpp;

class PlotLineScatter
{
public:

    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> x_scatter;
    std::vector<double> y_scatter;
    std::string filename;
    
    void gen_plot(){
        plt::figure_size(1200, 780);
        plt::plot(x, y);
        plt::scatter(x_scatter, y_scatter, 10,{{"color", "red"}});
        plt::legend();
        plt::save("./" + filename);
    }

    PlotLineScatter(std::vector<double>  x_, std::vector<double>  y_, std::vector<double>  x_scatter_, std::vector<double>  y_scatter_, std::string filename_)
    {
        x = x_;
        y = y_;
        x_scatter = x_scatter_;
        y_scatter = y_scatter_;
        filename = filename_;
    }
};