#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

void swapString(double **mas, int n, int a, int b) {
    double *temp = new double[n];
    for (int i = 0; i < n; ++i) {
        temp[i] = mas[a][i];
    }
    for (int i = 0; i < n; ++i) {
        if (i == a) {
            for (int j = 0; j < n; ++j) {
                mas[i][j] = mas[b][j];
            }
        }
        if (i == b) {
            for (int j = 0; j < n; ++j) {
                mas[i][j] = temp[j];
            }
        }
    }
}

int main() {
    ifstream input("C:\\Users\\teren\\Documents\\LabsProgramming\\VMALab1Task2\\input.txt");
    ofstream output("C:\\Users\\teren\\Documents\\LabsProgramming\\VMALab1Task2\\output.txt");

    int n;
    input >> n;
    double **matrix = new double *[n];
    double **reverse = new double *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[n];
        reverse[i] = new double[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                reverse[i][j] = 1;
            }else{
                reverse[i][j] = 0;
            }
        }
    }
    while (!input.eof()) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                input >> matrix[i][j];
            }
        }
    }
    double maxElement = -DBL_MAX;
    int _j = -1;
    double k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
                _j = j;
            }
        }
        for (int j = 0; j < n; ++j) {
            matrix[i][j]/=maxElement;
            reverse[i][j]/=maxElement;
        }
        for (int j = i+1; j < n; ++j) {
            k = matrix[j][_j];
            for (int l = 0; l < n; ++l) {
                matrix[j][l] -= matrix[i][l] * k;
                reverse[j][l]-=reverse[i][l]*k;
            }

        }
        maxElement = -DBL_MAX;
         _j = -1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) <<  matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) <<  reverse[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = n-1; i >=0 ; --i) {
        int _j = 0;

        for (int j = 0; j < n; ++j) {
            if(matrix[i][j] == 1){
                _j = j;

            }
        }

        for (int j = i-1; j >=0; --j) {
            double kf = matrix[j][_j];
            for (int l = 0; l < n; ++l) {
                matrix[j][l]-=matrix[i][l]*kf;
                reverse[j][l]-=reverse[i][l]*kf;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) <<  matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) <<  reverse[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(matrix[i][j]==1){
                if(i!=j){
                    swapString(matrix,n,i,j);
                    swapString(reverse,n,i,j);
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) <<  matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            output << setw(10) <<  reverse[i][j] << " ";
        }
        output << endl;
    }



    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
        delete[] reverse[i];
    }
    return 0;
}
