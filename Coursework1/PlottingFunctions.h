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
        x_ = x;
        y_ = y;
        x_scatter_ = x_scatter;
        y_scatter_ = y_scatter;
        filename_ = filename;
    }
}
// Set the size of output image to 1200x780 pixels

// Plot line from given x and y data. Color is selected automatically.

// Plot a red dashed line from given x and y data.

// Plot a line whose name will show up as "log(x)" in the legend.
// Set x-axis to interval [0,1000000]
// Add graph title
plt::title("Sample figure");
// Enable legend.

// Save the image (file format is determined by the extension)
