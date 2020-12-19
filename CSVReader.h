#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class CSVReader
{
public:
    vector<vector<float>> data;
    int n_cols;
    vector<string> col_names;

    int count_cols(string s)
    {
        int count = 0;

        for (int i = 0; i < s.size(); i++)
            if (s[i] == ',')
                count++;

        return count + 1;
    }

    CSVReader(string input_file_name)
    {
        ifstream input_file(input_file_name);
        int count = 0;

        while (input_file.good())
        {
            string cell;

            if (count == 0)
            {
                getline(input_file, cell);
                n_cols = count_cols(cell);
                for (int i = 0; i < n_cols; i++)
                {
                    string header;
                    getline(input_file, header, ',');
                    col_names.push_back(header);
                }
            }
            else
            {
                vector<float> row;
                for (int i = 0; i < n_cols; i++)
                {
                    getline(input_file, cell, ',');
                    row.push_back(stod(cell));
                }
                data.push_back(row);
            }
        }
        this->data > data;
        this->col_names > col_names;
    }
};
