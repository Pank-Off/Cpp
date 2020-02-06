#include <iostream>
#include <cstdlib>
using namespace std;

const int n = 13;

class Tree
{
public:
	Tree* root=0;
	Tree* left=0;
	Tree* right=0;
	int num=0;
	~Tree()
	{
		if (left)
		{
			delete left;
			if (right)
			{
				delete right;
			}
		}
		else if (right)
			delete right;
		cout << "Object with num " << num << " is deleted\n";
	}
	void show(Tree* obj)//Реализован прямой обход
	{
		cout << num << " ";
		if (left)
		{
			left->show(obj);
			if (right)
			{
				right->show(obj);
			}
		}
		else if (right)
		{
			right->show(obj);
		}
	}
};

Tree* addTree(Tree* obj, int x)
{
	if (obj == 0)//создание корня
	{
		obj = new Tree;
		obj->num = x;
		obj->left = 0;
		obj->right = 0;
	}
	else if (x < obj->num)
	{
		obj->left = addTree(obj->left, x);
	}
	else if (x > obj->num)
	{
		obj->right = addTree(obj->right, x);
	}
	return obj;
}

int main()
{
	int x;//для добавления нового объекта
	int m[n] = { 15,7,20,24,17,16,19,10,4,2,6,5,0};
	Tree* pnt=new Tree;
	Tree* p;
	p = pnt->root;
	for (int i = 0; i < n; i++)
	{
		p = addTree(p,m[i]);
	}
	p->show(p);
	cout << "\nPlease Input number to add into tree: ";
	cin >> x;
	addTree(p, x);
	cout << "New Tree:\n";
	p -> show(p);
	cout << endl;
	//Удаление дерева:
	delete p;
	system("pause>nul");
	return 0;
}
