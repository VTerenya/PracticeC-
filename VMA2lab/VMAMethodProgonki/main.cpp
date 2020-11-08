#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool TridiagonalLeft(const vector<double>& lower, const vector<double>& diagonal, const vector<double>& upper, const vector<double>& f, vector<double>& X)
{
    const int N = diagonal.size();
    vector<double> A(N), B(N);
    A[N - 1] = lower[N - 2] / diagonal[N - 1];
    B[N - 1] = f[N - 1] / diagonal[N - 1];
    for (int i = N - 2; i > 0; i--)
    {
        double mid = diagonal[i] - A[i + 1] * upper[i];
        if (mid == 0)
            return false;
        A[i] = lower[i - 1] / mid;
        B[i] = (f[i] - B[i + 1] * upper[i]) / mid;
    }
    if (diagonal[0] - A[1] * upper[0] == 0)
        return false;
    B[0] = (f[0] - B[1] * upper[0]) / (diagonal[0] - A[1] * upper[0]);
    X[0] = B[0];
    for (int i = 1; i < N; i++)
        X[i] = B[i] - X[i - 1] * A[i];
    return true;
}

int main()
{
    ifstream fin("C:\\Users\\teren\\Documents\\VMA2lab\\VMAMethodProgonki\\Input7.txt");
    ofstream fout("C:\\Users\\teren\\Documents\\VMA2lab\\VMAMethodProgonki\\Output7.txt");
    int n;
    fin >> n;
    vector<double> lower(n), diagonal(n), upper(n), f(n), X(n);
    for (int i = 0; i < n - 1; i++)
        fin >> upper[i];
    for (int i = 0; i < n; i++)
        fin >> diagonal[i];
    for (int i = 0; i < n - 1; i++)
        fin >> lower[i];
    for (int i = 0; i < n; i++)
        fin >> f[i];
    vector<double> det(n);

    det[0] = diagonal[0];

    for (int i = 1; i < n; ++i) {
        if(i==1) {
            det[i] = diagonal[i] * det[i - 1] - lower[i - 1] * upper[i - 1];
            continue;
        }
        det[i] = diagonal[i]*det[i-1]-lower[i-1]*upper[i-1]*det[i-2];
    }

    if (TridiagonalLeft(lower, diagonal, upper, f, X))
    {
        for (int i = 0; i < n; i++)
            fout << fixed << setprecision(5) << setw(7) << X[i] << " ";
        fout << endl;
        fout << det[n-1];
    }
    else
        fout << "NO\n";
}