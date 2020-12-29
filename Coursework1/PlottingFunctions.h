#include "../Matplot/matplotlibcpp.h"

namespace plt = matplotlibcpp;

std::vector<vector<double>> get_vertical_line(double x_scatter, double y_scatter, std::vector<double> x, std::vector<double> y)
{
    std::vector<vector<double>> vec_out;
    for (int i = 0; i < x.size(); ++i)
    {
        if ((x_scatter - x[i]) < 0.001) {
            
            std::vector<double> x_out = {x_scatter, x_scatter};
            std::vector<double> y_out = {y_scatter, y[i]};
            vec_out = {x_out, y_out};
            break;
        }   
    }
    return(vec_out);
}

class PlotLineScatter
{
public:

    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> x_scatter;
    std::vector<double> y_scatter;
    std::string filename;
    
    void gen_plot(){
        vector<vector<double>> line;
        plt::figure_size(1200, 780);
        plt::plot(x, y);
        plt::scatter(x_scatter, y_scatter, 10,{{"color", "red"}});
        for (int i = 0; i < x_scatter.size(); ++i)
        {
            line = get_vertical_line(x_scatter[i], y_scatter[i], x, y);
            plt::plot(line[0], line[1], "--r");
        }
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