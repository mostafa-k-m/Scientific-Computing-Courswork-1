#include "CSVReader.h"


int main()
{
    CSVReader reader = CSVReader("datasets/part_2/a/2_a_dataset_1.csv");
    for (int i=0; i<reader.col_names.size(); i++)
    {
        cout << reader.col_names[i] << endl;
        for (int j=0; j<reader.data[i].size(); j++)
        {
            cout << reader.data[i][j] << endl;
        }
    }
    return 0;
}