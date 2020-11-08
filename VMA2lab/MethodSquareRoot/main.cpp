#include <iostream>
#include <fstream>

using namespace std;


int main() {
    //считывание
    ifstream in("C:\\Users\\teren\\Documents\\VMA2lab\\MethodSquareRoot\\Input4.txt");
    ofstream out("C:\\Users\\teren\\Documents\\VMA2lab\\MethodSquareRoot\\Output4.txt");
    int n = 0;
    if (in.is_open()) {
        in >> n;
    }
    double **matrix = new double *[n];
    double *b = new double[n];
    int n1;
    for (int i = 0; i < n; ++i) {
        matrix[i] = new double[n];
    }
    for (int k = 0; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
            matrix[k][l] = DBL_MAX;
        }
    }
    for (int i = 0; i < n; ++i) {
        b[i] = 0;
    }
    int i = 0;
    int j = 0;
    if (in.is_open()) {
        n1 = n;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n1; ++j) {
                in >> matrix[i][j];
            }
            n1--;
        }
        for (i = 0; i < n; i++) {
            in >> b[i];
        }
    }

    double **matrix1 = new double *[n];
    n1 = n;
    for (int k = 0; k < n; ++k) {
        matrix1[k] = new double[n];
    }
    for (int k = 0; k < n; ++k) {
        for (int l = 0; l < n; ++l) {
            matrix1[k][l] = DBL_MAX;
        }
    }



    //транспонирование
    n1 = 1;
    for (i = n - 1; i >= 0; --i) {
        for (j = 0; j < n1; ++j) {
            matrix1[n - 1 - i][j] = matrix[i][j];
        }
        n1++;
    }
    //проверка на считывание
//    for (int k = 0; k < n; ++k) {
//        for (int l = 0; l < n; ++l) {
//            if (matrix[k][l] != DBL_MAX) {
//                out << matrix[k][l] << " ";
//            }
//        }
//        out << endl;
//    }
//    for (int k = 0; k <n ; ++k) {
//        for (int l = 0; l < n ; ++l) {
//            if(matrix1[k][l]!=DBL_MAX){
//                out << matrix1[k][l] << " ";
//            }
//        }
//        out << endl;
//    }
    //определитель
    double det = matrix[n - 1][0];
    for (int k = 1; k < n; ++k) {

        det *= matrix[n - 1 - k][k];
    }
    if (det != 0) {
        //подсчет Utx=b
        double *x = new double[n];
        if (matrix1[0][0] == 0 && b[0] != 0) {
            out << "No";
            return 1;
        }
        x[0] = b[0] / matrix1[0][0];
        n1 = 1;
        for (int k = 1; k < n; ++k) {
            double c = 0;
            for (int l = 0; l < n1; ++l) {
                c += matrix1[k][l] * x[l];
            }
            n1++;
            if (matrix1[k][k] == 0 && (b[k] - c != 0)) {
                //cout << k << " " << (b[k]-c) << " " << matrix1[k][k];
                out << "No";
                return 1;
            }
            x[k] = (b[k] - c) / matrix1[k][k];
        }

        //Uy = x
        double *y = new double[n];
        y[n - 1] = x[n - 1] / matrix[n - 1][0];

        n1 = 1;
        for (int k = n - 2; k >= 0; --k) {
            double c = 0;
            for (int l = 0, g = n-1; l < n1; ++l, g--) {
                c += matrix[k][l] * y[g];
            }
            y[k] = (x[k] - c) / matrix[k][n1];
            n1++;
        }
        out << "Yes" << endl;
        for (int k = 0; k < n; ++k) {
            out << y[k] << " ";
        }
        out << endl;
        out << det;
    } else {
        out << "No" << endl;
        out << det;
    }


    out.close();
    in.close();
    return 0;
}
