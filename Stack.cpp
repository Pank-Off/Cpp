
#include <iostream>
#include <cassert>
using namespace std;

const int n = 10;
class Stack {
private:
	int m[n];
	int length;
public:
	void reset()
	{
		length = 0;
		for (int i=0;i<n;i++)
			m[i] = 0;
	}
	bool push(int x) {
		if (length == 10)
			return false;
		m[length++] = x;
		return true;
	}
	int pop() {
		assert(length > 0);
		return m[--length];
	}
	void print() {
		cout << "( ";
		for (int i = 0; i < length; i++)
			cout << m[i] << " ";
		cout << ")\n";
	}
};
int main()
{
	Stack stack;
	stack.reset();  

	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();
	system("pause>nul");
	return 0;
}
