#include <fstream>
#include <iostream>
#include <cmath>
#include <iomanip>
#define SIZE 3
using namespace std;

void GetMatr(double **mas, double **p, int i, int j, int m) {
    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<m - 1; ki++) { // проверка индекса строки
        if (ki == i) di = 1;
        dj = 0;
        for (kj = 0; kj<m - 1; kj++) { // проверка индекса столбца
            if (kj == j) dj = 1;
            p[ki][kj] = mas[ki + di][kj + dj];
        }
    }
}

double Determinant(double **mas, int m) {
    int i, j, n;
    double d , k;
    double **p;
    p = new double*[m];
    for (i = 0; i<m; i++)
        p[i] = new double[m];
    j = 0; d = 0;
    k = 1; //(-1) в степени i
    n = m - 1;
    if (m<1) cout << "Определитель вычислить невозможно!";
    if (m == 1) {
        d = mas[0][0];
        return(d);
    }
    if (m == 2) {
        d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
        return(d);
    }
    if (m>2) {
        for (i = 0; i<m; i++) {
            GetMatr(mas, p, i, 0, m);
            d = d + k * mas[i][0] * Determinant(p, n);
            k = -k;
        }
    }
    return(d);
}

int main() {
    string input_file = "C:\\Users\\teren\\Documents\\LabsProgramming\\GaussVMA\\Input7.txt";
    string output_file = "C:\\Users\\teren\\Documents\\LabsProgramming\\GaussVMA\\output7.txt";
    ofstream output(output_file);
    ifstream input(input_file);

    int n;
    input >> n;
    double **matrix = new double*[n];
    for(int i = 0; i < n; i++){
        matrix[i] = new double[n];
    }

    double *b = new double[n];
    for (int i = 0; i <n; ++i) {
        b[i] = 0;
    }
    int i = 0, j = 0;
    while(!input.eof()){
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                input>>matrix[i][j];
            }
        }
        for(i = 0; i < n; ++i){
            input >> b[i];
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
            cout << matrix[k][l] << " ";
        }
        cout << endl;
    }
    for (int k = 0; k < n; ++k) {
        cout << b[k] << " ";
    }
    cout << endl;
    double det = Determinant(matrix,n);
    if(abs(det)<0.0001){
        output << "Determinant = 0!" << endl;
        return 0;
    }else{
        output << det << endl;
    }
    input.close();

    double max_in_string = -DBL_MAX;
    int max_j = -1;
    double k = 0;
    for(i = 0; i < n; i++){
        //нахожу максимум в строке
        for(j = 0; j < n; j++){
            if(matrix[i][j]==0) continue;
            if(max_in_string < matrix[i][j]){
                max_in_string = matrix[i][j];
                max_j = j;
            }
        }
        //int temp_i = i;
        //изменяю исходную строку и вектор значений
        b[i]/=max_in_string;
        for (int l = 0; l < n; ++l) {
            matrix[i][l]/=max_in_string;
        }
        //изменяю остальные строки и вектор значений
        for (int l = i+1; l < n; ++l) {
            k = matrix[l][max_j];
            for (int m = 0; m < n; ++m) {
                matrix[l][m]-=matrix[i][m]*k;
            }
            b[l]-=b[i]*k;
        }
        max_in_string = -DBL_MAX;
        max_j = -1;
    }
    for (int k = 0; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
            cout << setw(10) <<  matrix[k][l] << " ";
        }
        cout << endl;
    }
    for (int k = 0; k < n; ++k) {
        cout << b[k] << " ";
    }
    cout << endl;
    //определитель
    double* result = new double[n];

    for (int l = 0; l < n; ++l) {
        result[l] = 0;
    }

    for (int l = n-1; l >=0; --l) {
        for (int m = 0; m < n; ++m) {
            if(matrix[l][m]==1){
                double c  = 0;
                for (int i1 = 0; i1 < n; ++i1) {
                    if (i1==m) continue;
                    c+=result[i1]*matrix[l][m];
                }
                result[m] = b[l]-c;
            }
        }
    }

    for (int l = 0; l < n; ++l) {
        output << result[l] << " ";
    }


    for (int l = 0; l < n; ++l) {
        delete[] matrix[l];
    }
    delete[] b;
    delete[] result;
    return 0;
}
