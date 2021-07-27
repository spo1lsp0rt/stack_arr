// Ниже представлен программный код реализации стека на базе статического массива.
// Необходимо было обеспечить работу следующих функций: push, pop, top, size, empty, swap.

#include <iostream>

template <class T>
class stack {
private:
	static const int arr_size = 20;
	T arr[arr_size];
	int i = -1;

public:
	stack() {}
	bool empty() {
		return i == -1;
	}
	void push(T el) {
		if (i < arr_size) {
			i += 1;
			arr[i] = el;
		}
		else {
			throw "error: overloaded stack";
			return;
		}
	}
	void pop() {
		if (!empty()) {
			i -= 1;
		}
		else {
			throw "error: empty stack";
			return;
		}
	}
	T top() {
		if (!empty()) {
			return arr[i];
		}
		else {
			throw "error: empty stack";
		}
	}
	size_t size() {
		return i + 1;
	}
	void swap(stack<T>& t_stack) {
		i = t_stack.i;
		for (unsigned int j = 0; j <= i; j++) {
			arr[j] = t_stack.arr[j];
		}
	}
};

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Введите количество элементов стека: ";
	unsigned int size;
	cin >> size;
	stack<int> s_arr;
	cout << endl << "(push) Введите " << size << " элементов последовательно." << endl;
	for (unsigned i = size; i > 0; i--) {
		int a;
		cout << i << "й элемент: ";
		cin >> a;

		s_arr.push(a);
	}

	cout << endl << "(top) Верхний элемент: " << s_arr.top() << endl;
	cout << "(size) Размер стека: " << s_arr.size() << " = " << size << endl;
	s_arr.pop();
	cout << "(pop) Верхний элемент после удаления: " << s_arr.top() << endl;
	cout << "Создадим временный стек и перенесем в него элементы старого стека.";
	stack <int> temp;
	for (unsigned int i = s_arr.size(); i > 0; i--) {
		cout << endl << "Удалили " << s_arr.top();
		temp.push(s_arr.top());
		s_arr.pop();
	}
	cout << endl << "(empty) Полностью очистили старый стек. Пуст ли он? [" << s_arr.empty() << "]." << endl;
	s_arr.swap(temp);
	cout << "(swap) Перенесли элементы временного стека обратно в старый.";
	for (unsigned int i = s_arr.size(); i > 0; i--) {
		cout << endl << 5 - i << "й элемент: " << s_arr.top();
		s_arr.pop();
	}
	return 0;
}