#pragma once
#include <fstream>
template <class T>
class List {
private:
	T* field;
	int size = 0;

public:
	List() {
		field = new T[10];
	};
	List(T n) {
		field = new T[n];
		for (int i = 0; i < n; i++)
			field[i] = 0;
		size = n;
	}
	List(List<T>& list) {
		Clear();
		field = list.field;
		for (int i = 0; i < list.size; i++) {
			field[i] = list.field[i];
		}
		size = list.size;
	}

	void Clear() {
		if (size != 0) {
			delete[] field;
		}
		size = 0;
	}

	~List() {
		Clear();
	}

	bool IsEmpty() {
		if (!size)
			return false;
		return true;
	}

	int Size() {
		return size;
	}

	T Front() {
		return field[0];
	}

	T Back() {
		return field[size - 1];
	}

	void PushBack(T value) {
		size++;
		field[size - 1] = value;
	}

	void PushFront(int value) {
		T* temp = new T[size];
		for (int i = 0; i < Size(); i++) {
			temp[i] = field[i];
		}
		int temp_size = Size();
		Clear();
		field = new T[temp_size + 1];
		field[0] = value;
		for (int i = 1; i < temp_size+1; i++)
			field[i] = temp[i];
		size = temp_size + 1;
		delete[] temp;
	}

	void PopFront() {
		size--;
	}

	void PopBack() {
		T* temp = field;
		for (int i = 0; i < Size(); i++) {
			temp[i] = field[i];
		}
		int temp_size = Size();
		Clear();
		field = new T[temp_size - 1];
		for (int i = 1, j = 0; j < temp_size; j++, i++) {
			field[j] = temp[i];
		}
	}
	
	template<class T>
	friend std::istream& operator>>(std::istream& in, List<T>& list) {
		int value;
		in >> value;
		for (size_t i = 0; i < value; i++)
		{
			T t;
			in >> t;
			list.PushBack(t);
		}
		return in;
	}
	 
	T GetValueIndex(int index) {
		return field[index];
	}

	T operator[](int index) {
		return field[index];
	}

	
};

template<class T>
std::ostream& operator<<(std::ostream& out,  List<T>& list) {
	for (int i = 0; i < list.Size(); i++)
		out << list.GetValueIndex(i) << " ";
	return out;
}



template<class T>
bool operator<(const List<T>& l, const List<T>& r) {
	return l.size < r.size;
}
