#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    public:
        int dim;
        vector< vector< float > > mat;
        
        Matrix(int x){
            dim = x;
            for (int i = 0; i < dim; ++i){
                float input;
                vector<float> tempVec;
                for (int j = 0; j < dim; ++j) {
                    cout << "Enter matrix element " << i + 1 << " , "<< j + 1 << ": ";
                    cin >> input;
                    tempVec.push_back(input);
                }
                mat.push_back(tempVec);
            }
            this->mat > mat;
            this->dim > dim;
        }

        void augment_matrix(vector< float > vec) {
            if (vec.size() != dim) {
                cout << "vector is of in correct size";
            } else {
                for (int i = 0; i < dim; ++i) {
                    mat[i].push_back(vec[i]);
                }
            }
        }

        vector<float> get_row(int x){
            vector<float> temp = mat[x];
            return temp;
        }

        void swap_rows(int row1, int row2) {
            vector<float> temp = get_row(row1);
            mat[row1] = get_row(row2);
            mat[row2] = temp;
        }

        float get_max(vector<float> vec){
            float max = vec[0];
            for (int i = 0; i < dim; ++i) {
                if (vec[i] > max) {
                    max = vec[i];
                }
            }
            return max;
        }
        
        void normalize_rows(){
            for (int i = 0; i < dim; ++i) {
                vector<float> temp = get_row(i);
                float max = get_max(temp);
                for (int j = 0; j < temp.size(); ++j) {
                    mat[i][j] = temp[j]/max;
                }
            }
        }
};

class Solve {
    public:
        Solve(Matrix A, vector<float> b) {
            A.augment_matrix(b);
        }
};

int main(){
    Matrix A = Matrix(2);
    vector<float> vec = {5, 6};
    A.augment_matrix(vec);

    A.swap_rows(0,1);
    A.normalize_rows();
    
    cout << A.get_row(0)[0] << " " << A.get_row(0)[1] << " " << A.get_row(0)[2] << endl;
    cout << A.get_row(1)[0] << " " << A.get_row(1)[1] << " " << A.get_row(1)[2] << endl;

    return 0;
}
