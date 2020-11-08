#pragma once//
// Created by soul on 04.09.2020.
//

#include <initializer_list>
#include <iostream>

using namespace std;

template <class T>
class Set {

private:
    void FindUniqueItem() { //+
        int new_size = size;
        bool equal_finded = false;
        int i = 0, j = 0, k = 0;
        while (i < new_size)
        {
            j = i + 1;
            while (j < new_size)
            {
                if (field[i] == field[j])
                {
                    k = j;
                    while (k < new_size - 1)
                    {
                        field[k] = field[k + 1];
                        k++;
                    }
                    field[k] = INT64_MAX;
                    new_size--;
                    equal_finded = true;
                }
                if (!equal_finded)
                    j++;
                equal_finded = false;
            }
            i++;
        }
        T* _new = new T[new_size];
        for (int i = 0; i < new_size; ++i) {
            _new[i] = field[i];
        }
        Clear();
        field = _new;
        size = new_size;
    }
    T* field;
    int size = 0;

public:
    
    T Get(int index) {
        return field[index];
    }

    void Clear() { //+
        if (size != 0) {
            delete[] field;
        }
    }

    Set() { //+
        field = new T;
    };
    ~Set() { //+
        Clear();
    };
    //move
    Set(Set<T>&& A) {//+
        size = A.size;
        field = A.field;
        A.field = nullptr;
    }
    //copy
    Set(const Set<T>& A) { //+
        Clear();
        field = new T[A.size];
        for (size_t i = 0; i < A.size; ++i) {
            field[i] = A.field[i];
        }
        size = A.size;
    };


    Set(int size) { //+
        field = new T[size];
        this->size = size;
    };
    Set(T* f, int s) { //+
        Clear();
        this->field = f;
        this->size = s;
        FindUniqueItem();
    }
    Set(const std::initializer_list<T>& list) { //+
        field = new T[list.size()];
        //for_each(list.begin(), list.end(), [&](const T & __elem) {list[i] = __elem; i++; });
        int i = 0;
        for (auto& item : list) {
            field[i] = item;
            i++;
        }
        size = i;
        FindUniqueItem();
    }

    void Show() { //+
        for (size_t i = 0; i < this->size; ++i) {
            std::cout << field[i] << " ";
        }
    }


    void Insert(const T& elem) {//+
        bool flag = false;
        for (size_t i = 0; i < size; ++i) {
            if (field[i] == elem) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            T* temp = new T[size + 1];
            size_t i;
            for (i = 0; i < size; ++i) {
                temp[i] = field[i];
            }
            temp[i] = elem;
            if (size != 0) {
                delete[] field;
            }
            field = temp;
            size++;
        }
    }
    //разность
    void operator/=(const Set<T>& R) {//+
        int new_size = size;
        int i = 0, j = 0, k = 0;
        bool flag = false;
        while (i < new_size) {
            while (j < new_size) {
                if (field[i] == R.field[j]) {
                    k = j;
                    flag = true;
                    while (k < new_size - 1) {
                        field[k] = field[k + 1];
                        k++;
                    }

                    new_size--;
                    field[k] = INT64_MAX;
                }
                if (!flag)
                    j++;
                flag = false;
            }
            ++i;
            j = 0;
        }
        T* _new = new T[new_size];
        for (int i = 0; i < new_size; ++i) {
            _new[i] = field[i];
        }
        Clear();
        field = _new;
        size = new_size;
    }

    //разность
    Set<T> operator/(const Set<T>& R) {//+
        int new_size = size;
        int i = 0, j = 0, k = 0;
        bool flag = false;
        while (i < new_size) {
            while (j < new_size) {
                if (field[i] == R.field[j]) {
                    k = j;
                    flag = true;
                    while (k < new_size - 1) {
                        field[k] = field[k + 1];
                        R.field[k] = R.field[k + 1];
                        k++;
                    }

                    new_size--;
                    field[k] = INT64_MAX;
                    R.field[k] = INT64_MAX;
                }
                if (!flag)
                    j++;
                flag = false;
            }
            ++i;
            j = 0;
        }
        T* _new = new T[new_size];
        for (int i = 0; i < new_size; ++i) {
            _new[i] = field[i];
        }
        Clear();
        field = new T[new_size];
        size = new_size;
        for (size_t l = 0; l < new_size; ++l) {
            field[i] = _new[i];
        }
        return Set(_new, new_size);
    }
    //пересечение
    Set<T> operator*(const Set<T>& R) {//+
        int new_size = R.size + size;

        if ((R.size > 0) && (size > 0)) {
            T* mas = new T[new_size];
            int i = 0, j = 0, k = 0;
            while (i < size) {
                j = 0;
                while (j < R.size) {
                    if (field[i] == R.field[j]) {
                        mas[k++] = field[i];
                    }
                    j++;
                }
                i++;
            }
            Clear();
            size = k;
            field = new T[size];
            for (int l = 0; l < size; ++l) {
                field[l] = mas[l];
            }
            FindUniqueItem();
            return Set(mas, k);
        }

    }

    void operator*=(const Set<T>& R) {//+
        int new_size = R.size + size;

        if ((R.size > 0) && (size > 0)) {
            T* mas = new T[new_size];
            int i = 0, k = 0;
            while (i < size) {
                int j = 0;
                while (j < R.size) {
                    if (field[i] == R.field[j]) {
                        mas[k++] = field[i];
                    }
                    j++;
                }
                i++;
            }
            Clear();
            size = k;
            field = new T[size];
            for (int l = 0; l < size; ++l) {
                field[l] = mas[l];
            }
            FindUniqueItem();
            delete[] mas;
        }

    }
    //объединение
    void operator+=(const Set<T>& R) {//+
        int sum_size = size + R.size;
        T* mas = new T[sum_size];
        for (size_t i = 0; i < size; ++i) {
            mas[i] = field[i];
        }
        for (size_t i = size, j = 0; i < sum_size && j < R.size; ++i, ++j) {
            mas[i] = R.field[j];
        }
        Clear();
        field = mas;
        size = sum_size;
        FindUniqueItem();
    }

    Set<T> operator+(const Set<T>& R) {//+
        int sum_size = size + R.size;
        T* mas = new T[sum_size];
        for (size_t i = 0; i < size; ++i) {
            mas[i] = field[i];
        }
        for (size_t i = size, j = 0; i < sum_size && j < R.size; ++i, ++j) {
            mas[i] = R.field[j];
        }
        return Set(mas, sum_size);
    }


    Set<T>& operator=(const Set<T>& R) {//+
        Clear();
        if (this != &R) {
            field = new T[R.size];
            size = R.size;
            for (size_t i = 0; i < size; ++i) {
                field[i] = R.field[i];
            }
        }

        return *this;
    }

    Set<T>& operator=(Set<T>&& R) {
        Clear();
        if (this != &R) {
            size = R.size;
            field = R.field;
            R.field = nullptr;
        }
        return *this;
    }

    bool operator!=(const Set<T>& R) { //+
        if (size != R.size)
            return true;
        else {
            int k = 0;
            for (size_t i = 0; i < this->size; ++i) {
                for (size_t j = 0; j < R.size; ++j) {
                    if (field[i] == R.field[j]) {
                        k++;
                    }

                }
                if (k == 0)
                    return true;
                k = 0;
            }
            return false;
        }
    }



    bool operator==(const Set<T>& R) {//+
        bool flag = true;
        int k = 0;
        if (size != R.size) {
            return false;
        }
        for (size_t i = 0; i < size; ++i) {
            for (size_t j = 0; j < R.size; ++j) {
                if (field[i] != R.field[j]) {
                    k++;
                }
            }
            if (k != 0) {
                flag = true;
            }
            else {
                flag = false;
                break;
            }

        }
        return flag;
    }

    T operator[](const int  n) {//+
        if (n >= 0 || n < size)
            return field[n];
    }

    friend std::ostream& operator<<(std::ostream& out, const Set<T>& set) {//+

        for (size_t i = 0; i < set.size; i++) {
            out << (*(set.field + i)) << " "; ;
        }

        return out;
    }

        friend std::istream& operator>>(std::istream &in, Set<T> set){
            int f;
            in >> f;
            for (int i = 0; i < f; i++)
            {
                T t;
                in >> t;
                set.Insert(t);
            }
            return in;
        }

    Set<T>& Swap(Set<T>& R) { //+
        T* temp = R.field;
        T s = R.size;
        R.field = field;
        R.size = size;
        field = temp;
        size = s;
    }

    int Size() {//+
        return size;
    }
};

