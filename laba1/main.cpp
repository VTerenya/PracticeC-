#include <iostream>
#include "set.h"


int main(){
    int a = 0;

    Set<int> e = Set<int>{1,2,3};
    cout << e << endl;
    Set<int> n{1,2};
    Set<int> m(n);
    Set<int> c{4,2,3,4,4,5};
    c.Show();
    cout << "\nHello" << endl;
    cout << "Эелементы множества N:" << c;
    cout << endl;
    m.Insert(12);
    m.Insert(2);
    m.Insert(3);
    m.Show();
    cout << endl;
//    c/=m;
//    c.Show();
    m/=c;

    m.Show();

    cout << endl;
    Set<char> t = {'a','b', 'c'};
    cout << t << endl;

    Set<char> z = {'a', 'v', 'c'};
    cout << z << endl;
    Set<char> k;
    k = z/t;
    k.Show();


    Set<int> q = {1,2,3,4};
    cout << "\nQ:" <<  q << endl;
    Set<int> g = {1,2,5,7};
    cout << "G:" << g << endl;
//    g*=q;
//    cout << "G :" << g << endl;

    Set<int> h;
    h = q*g;
//    g = h;
//    cout << "G:" << g << endl;
    cout << "H:" << h << endl;
   // h = g;
    bool f = (h!=g);
    cout << f << endl;

    h.Swap(g);
    cout << "H:" << h << endl;
    cout << "G:" << g << endl;

    //g = h;

    bool f1 = (h==g);
    cout << "F1(H==G): " << f1 << endl;

    Set<int> o = {5,4,13,2};
    Set<int> b = {7,9,10,5,8};

    cout << "B: " << b << endl;
    cout << "O: " << o << endl;

//    o+=b;
//    cout << "Operation o+=b\n";
//    cout << "New O: " << o << endl;

    Set<int> d;
    d = o+b;
    cout << "D: " << d << endl;
    cout << "O: " << o << endl;
}