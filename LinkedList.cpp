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
		cout << endl;
	}

	void additem(int d); // добавление элемента
	void display();       // показ данных
	linklist& operator=(linklist& L);
};
///////////////////////////////////////////////////////////
void linklist::additem(int d) // добавление элемента
{
	link* newlink = new link;
	if (!first) //если элемент первый
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
	cout << endl;
}
///////////////////////////////////////////////////////////
linklist& linklist::operator=(linklist& L)
{
	link* oldlink = L.first;
	first = new link;
	link* current = first;
	while (true) {
		link* nextlink = new link;
		current->data = oldlink->data;
		if (oldlink->next) {
			current->next = nextlink;
			current = current->next; 
			oldlink = oldlink->next;
			continue;
		}
		current->next = NULL; break;
	}
	return *this;
}
///////////////////////////////////////////////////////////
int main()
{
	linklist li, li2;       // создаем переменную-список

	li.additem(25); // добавляем туда несколько чисел
	li.additem(36);
	li.additem(49);
	li.additem(64);
	li.display();    // показываем список
	li2 = li;
	li2.display();
	li.~linklist();
	li2.display();
	system("pause>nul");
	return 0;
}


