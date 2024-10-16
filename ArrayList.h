#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;

class ArrayList {
	
	public:
		ArrayList() {	
			capacity = 20;
			list = new int[capacity];
			size = 0;
		}
		
		bool isEmpty() {
			return size == 0;
		}

		bool add(int value) {
			if (isFull()) {
				resize();
			}
			list[size++] = value;	
			return true;
		}

		void add(int index, int value) {

			if (isFull()) {
				resize();
			} else if (index == size) {
				add(value);
				return;
			} else if (!indexIsValid(index)) {
				throw std::runtime_error("Índice inválido");
			} else {
				shiftRight(index);
				list[index] = value;
				size++;
			}
		}

		void set(int index, int value) {
			if (!indexIsValid(index)){
				throw std::runtime_error("Índice inválido");
			}

			list[index] = value;
		}

		int get(int index) {
			if (!indexIsValid(index)) {
				throw std::runtime_error("Índice inválido");
			}

			return list[index];
		}

		int indexOf(int value) {
			for (int i = 0; i < size; i++) {
				if (list[i] == value) {
					return i;
				}
			}
			return -1;
		}

		bool contains(int value) {
			return indexOf(value) != -1;
		}

		int remove(int index) {
			if (isEmpty()) {
				throw std::runtime_error("Lista vazia");
			} else if (!indexIsValid(index)) {
				throw std::runtime_error("Índice inválido");
			}
			
			int elem = list[index];
			shiftLeft(index);
			size--;
			return elem;
		}

		bool removeByValue(int value) {
			if (isEmpty()) {
				throw std::runtime_error("Índice inválido");
			}

			for (int i = 0; i < size; i++) {
				if (list[i] == value) {
					shiftLeft(i);
					size--;
					return true;
				}
			}
			
			return false;
		}

		string toString() {
			string msg = "";
			for (int i = 0; i < size; i++) {
				msg += to_string(list[i]) + " ";
			}
			return msg;	
		}
	
	private:
		int *list;
		int capacity;
		int size;

		bool indexIsValid(int index) {
			return (index >= 0 and index < size);
		}

		bool isFull() {
			return size == capacity;
		}	

		void resize() {

			int *newList = new int[size * 2];
			for (int i = 0; i < size; i++) {
				newList[i] = list[i];
		       	}

			delete[] list;
			list = newList;
			capacity = 2 * capacity;
		}
		
		void shiftLeft(int index) {
			if (!indexIsValid(index)) {
				throw std::runtime_error("Índice inválido");
			}

			for (int i = index; i < size-1; i++) {
				list[i] = list[i+1];
			}
		}

		void shiftRight(int index) {
			if (!indexIsValid(index)) {
				throw std::runtime_error("Índice inválido");
			}

			if (isFull()) {
				resize();
			}

			for (int i = size; i > index; i--) {
				list[i] = list[i-1];
			}

		}
};
