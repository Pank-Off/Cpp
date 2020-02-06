// linklist.cpp
// список
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
struct link   // один элемент списка
{
	int data;
	link* next;
};
///////////////////////////////////////////////////////////
class linklist // список
{
private:
	link* first;
public:
	linklist()
	{
		first = NULL;
	}

	~linklist()
	{
		link* current = first;
		while(current)
		{
			link* tmp = current;
			cout << "Obj " << tmp->data << " are deleted;\n";
			current = tmp->next;
			delete tmp;
		}
		system("pause>nul");
	}

	void additem(int d); // добавление элемента
	void display();       // показ данных
};
///////////////////////////////////////////////////////////
void linklist::additem(int d) // добавление элемента
{
	link* newlink = new link;
	if (!first)
	{
		newlink->data = d;
		newlink->next = NULL;
		first = newlink;
	}
	else
	{
		link* current = first;
		while (true)
		{
			if (!current->next)
			{
				current->next = newlink;
				newlink->data = d;
				newlink->next = NULL;
				current = current->next;
				break;
			}
			current = current->next;
		}
	}
}
///////////////////////////////////////////////////////////
void linklist::display()
{
	link* current = first;
	while (current)
	{
		cout << current->data << endl;
		current = current->next;
	}
}
///////////////////////////////////////////////////////////
int main()
{
	linklist li;       // создаем переменную-список

	li.additem(25); // добавляем туда несколько чисел
	li.additem(36);
	li.additem(49);
	li.additem(64);
	li.display();    // показываем список
	return 0;
}
