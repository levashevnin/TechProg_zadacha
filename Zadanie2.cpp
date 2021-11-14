
#include "iostream"
#include <clocale>

#define MAX 8;
using namespace std;

struct SetOfStacks
{
/////////////
	class FirstStack {
	public:
		FirstStack(): root(nullptr){} // по умолчанию пустой стек
		void Push(int& x) {
			Node* newnode = new Node;
			newnode->data = x;
			newnode->next = root;
			root = newnode;
		}
		int Pop() {
			Node* delnode = root;
			int x = delnode->data;
			root = delnode->next;
			delete delnode;
			cout << "|1 st: ";
			return x;
		}
	private:
		struct Node {
			int data;
			Node* next;
		};
		Node* root; // вершина стека
	};
/////////////
	class SecondStack {
	public:
		SecondStack() : root(nullptr) {} // по умолчанию пустой стек
		void Push(int& x) {
			Node* newnode = new Node;
			newnode->data = x;
			newnode->next = root;
			root = newnode;
		}
		int Pop() {
			Node* delnode = root;
			int x = delnode->data;
			root = delnode->next;
			delete delnode;
			cout << "|2 st: ";
			return x;
		}
	private:
		struct Node {
			int data;
			Node* next;
		};
		Node* root; // вершина стека
	};
/////////////
	FirstStack a;
	SecondStack b;
	int nodeCount = 0;
	////
	void push(int d) {
		nodeCount++;
		if (nodeCount <= 8) {
			a.Push(d);
		}
		
		else {
			b.Push(d);
		}
	}
	////
	int pop() {
		nodeCount--;
		if (nodeCount >= 8) {
			return b.Pop();
		}
		else {
			return a.Pop();
		}
	}
};

int main()
{
	SetOfStacks st;
	for (int i = 1; i <= 16; i++) //добавляем 1,2,...,16
	{
		st.push(i);
	}

	

	while (st.nodeCount>0) //печатаем все что в стеке
	{
		cout << st.pop() << "| ";
	}
	cout << endl;
}