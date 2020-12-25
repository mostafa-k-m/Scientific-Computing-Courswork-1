#include "Coursework1/PolynomialRegression.hpp"
#include "Coursework1/CSVReader.hpp"
#include <vector>
#include <iostream>

int main()
{
    PlynomialRegression P(2);
    CSVReader csv = CSVReader("./datasets/part_2/a/2_a_dataset_1.csv");
    P.fit(csv.data[0], csv.data[1]);
    vector<float> y = P.predict(0, 10, 0.1);
    for (int k = 0; k < 100; k++)
    {
        cout << y[k] << endl;
    }
    return (0);
}