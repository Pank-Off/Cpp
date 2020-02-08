// parse.cpp
// программа разбора арифметических выражений

/*
Используемые упрощения:
1) Не используются скобки
2) Ввод данных обязательно в виде x.x, если требуется целое число вводим 6.0
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;
const int LEN = 80;       // максимальная длина выражения
const int MAX = 100;    
///////////////////////////////////////////////////////////
class Token
{
public:
	virtual float getNumber() = 0;
	virtual char getOperator() = 0;
};

class Operator :public Token
{
private:
	char oper;
public:
	Operator() :oper('\0'){};
	Operator(char ch)
	{
		oper = ch;
	}
	char getOperator()
	{
		return oper;
	}
	float getNumber() { return 0.0; }
};

class Number :public Token
{
private:
	float fnum;
public:
	Number() :fnum(0.0) {};
	Number(float n)
	{
		fnum = n;
	}
	float getNumber()
	{
		return fnum;
	}
	char getOperator() { return '\0'; }
};

class Stack
{
private:
	Token* atoken[100];
	int top;
public:
	Stack() :top(0) {};
	void push(Token* A)
	{
		atoken[++top] = A;
	}
	Token* pop()
	{
		return atoken[top--];
	}
	int gettop()
	{
		return top;
	}
};

///////////////////////////////////////////////////////////
class express
{
private:
	Stack s;
	char* pStr;                // строка для ввода
	int len;                   // длина строки
public:
	express(char* ptr)      // конструктор
	{
		pStr = ptr;            // запоминаем указатель на строку
		len = strlen(pStr); // устанавливаем длину
	}
	void parse();            // разбор выражения
	float solve();             // получение результата
};
///////////////////////////////////////////////////////////

void express::parse() // добавляем данные в стек
{
	char ch;              // символ из строки
	Token* lastval;         // последнее значение
	Token* lastop;          // последний оператор
	char num[100];
	int i = 0;
	for (int j = 0; j <= len; j++) // для всех символов в строке
	{
		ch = pStr[j];    // получаем символ
		if (ch >= '0' && ch <= '9' || ch == ',' || ch == '.') // если это цифра,
			num[i++] = ch;
		else
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				s.push(new Number(atof(num)));
				i = 0;
				if (s.gettop() == 1)
					s.push(new Operator(ch));
				else
				{
					lastval = s.pop();
					lastop = s.pop();
					if((ch == '*' || ch=='/') && (lastop->getOperator() == '+' || lastop->getOperator() == '-'))
					{
						s.push(lastop);
						s.push(lastval);
					}
					else
					{
						switch (lastop->getOperator())
						{
						case '+':s.push(new Number(s.pop()->getNumber() + lastval->getNumber())); break;
						case '-':s.push(new Number(s.pop()->getNumber() - lastval->getNumber())); break;
						case '*':s.push(new Number(s.pop()->getNumber() * lastval->getNumber())); break;
						case '/':s.push(new Number(s.pop()->getNumber() / lastval->getNumber())); break;
						default: cout << "\nНеизвестный оператор"; exit(1);
						}
					}
					s.push(new Operator(ch));
				}
			}
			else if(ch == '\0')
				s.push(new Number(atof(num)));
			else               // какая-то ерунда...
			{
				cout << "\nНеизвестный символ";
				exit(1);
			}
	}
}
///////////////////////////////////////////////////////////
float express::solve() // убираем данные из стека
{
	Token* lastval;        // предыдущее значение
	
	while (s.gettop() > 1)
	{
		lastval = s.pop();	// получаем предыдущее значение
		switch(s.pop()->getOperator())	// получаем предыдущий оператор
		{
		case '+':s.push(new Number(s.pop()->getNumber() + lastval->getNumber())); break;
		case '-':s.push(new Number(s.pop()->getNumber() - lastval->getNumber())); break;
		case '*':s.push(new Number(s.pop()->getNumber() * lastval->getNumber())); break;
		case '/':s.push(new Number(s.pop()->getNumber() / lastval->getNumber())); break;
		default: cout << "\nНеизвестный оператор"; exit(1);
		}
	}
	return s.pop()->getNumber(); // последний оператор в стеке – это результат
	
}

///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251>nul");
	char ans;            // 'д' или 'н'
	char string[LEN]; // строка для разбора

	cout << "\nВведите арифметическое выражение в виде 2.4+3.3*4.4/3.2-2.3"
		"\nЧисла должны быть из одной цифры"
		"\nНе используйте пробелы";

	do
	{
		cout << "\nВыражение: ";
		cin >> string;                          // вводим строку
		express* eptr = new express(string); // создаем объект для разбора
		eptr->parse();                        // разбираем
		cout << "\nРезультат: "
			<< eptr->solve();                // решаем
		delete eptr;                            // удаляем объект
		cout << "\nЕще одно выражение (д/н)? ";
		cin >> ans;
	} while (ans == 'д');
	getchar();
	return 0;
}


