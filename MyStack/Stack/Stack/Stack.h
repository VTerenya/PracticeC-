#pragma once
#include <fstream>
template <class T>

class Stack {
private:
	T* field;                      // указатель на стек
	int size = 10;
	int top;

	/*void  StayDefaultValue() {
		for (int i = 0; i < this->size; i++)
		{
			field[i] = 0;
		}
	}*/
public:

	Stack() {
		field = new T[size];
		top = 0;
	};
	Stack(T* ptr) {
		field = ptr;
		top = 0;
	};
	Stack(T* ptr, long long s) {
		if (s > size) {
			size = s;
		}
		field = ptr;
		top = 0;
	};
	Stack(const Stack<T>& S) {
		Clear();
		field = new T[S.size];
		for (int i = 0; i < S.top; i++) {
			field[i] = S[i];
		}
		field = S.field;
		top = S.top;
	};

	~Stack() {
		delete[] field;
	};
	
   
	int Top() {
		
		return field[top-1];
	}
	
	int Size() {
		return top;
	}

	void Push(T value) {
		field[top] = value;
		if (size < (top + 1)) {
			size += 10;
		}
		top++;
	}

	int MaxSize() {
		return size;
	}
	
	void Pop() {
		top--;
	}
	
	void Swap(Stack<T>& s) {
		T* temp = new T[s.GetMaxSize()];
		for (int i = 0; i < s.GetTopSize(); i++) {
			temp[i] = s[i];
		}
		int t = s.Size();
		int max = s.GetMaxSize();
		

		s.Clear();

		s.field = new T[GetMaxSize()];
		for (int i = 0; i < top; i++) {
			s.field[i] = field[i];
		}
		s.top = top;
		s.size = size;
		
		Clear();
		field = new T[max];
		for (int i = 0; i < t; i++) {
			field[i] = temp[i];
		}
		top = t;
		delete[] temp;
	}
	int GetMaxSize() {
		return size;
	}

	int GetTopSize() {
		return top;
	}

	bool IsEmpty() {
		if (top == 0) {
			return true;
		}
		return false;
	}
	void Clear() {
		if (top != 0)
			delete[] field;
		field = new T[10];
		top = 0;
	}


	T GetValue(int index){
		return field[index];
	}

	T operator[](int index) const {
		return field[index];
	}

	
};

template < class T>
std::ostream& operator<<(std::ostream& out,  Stack<T>& S) {
	for (int i = S.Size()-1; i >= 0; i--) {
		out  << '[' << i << ']' << ':'<< S.GetValue(i) << ' ';
	}
	return out;
}

template <class T>
std::istream& operator>>(std::istream& in, Stack<T>& S) {
	int t;
	in >> t;
	for (size_t i = 0; i < t; i++)
	{
		T r;
		in >> r;
		S.Push(r);
	}
	return in;
}

template <class T>
bool operator< (Stack<T>& L, Stack<T>& R) {
	return L.Size() < R.Size();
}