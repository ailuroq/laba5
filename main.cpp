#include <iostream>
#include <conio.h>
#include <complex>
using namespace std;


template<class type>
class CListTemplate

{

	struct SNode

	{

		type* data;

		SNode* next;

	};

	SNode* head, * p;

public:

	CListTemplate() { head = p = 0; }

	void AddElem(type* d);

	bool RemoveElem(type* d);
	void insert(type &d, type &Pos);
	void DisplayList();

	void clear();

	~CListTemplate() { clear(); }

};

template<class type>
void CListTemplate<type>::AddElem(type* d)

{

	if (head)

	{

		p->next = (SNode*)malloc(sizeof(SNode));

		p = p->next;

	}

	else

	{

		head = (SNode*)malloc(sizeof(SNode));

		p = head;

	}

	p->data = d;

	p->next = 0;

}
template<class type>
void CListTemplate<type>::insert(type &d, type &Pos)
{
	
	SNode* current = head;

	for (int i = 0; i < Pos-1; i++) {
		current = current->next;
		
	}

	SNode* newElement = new SNode();
	newElement->data = &d;
	newElement->next = current->next;
	current->next = newElement;
}
	

template<class type>
bool CListTemplate<type>::RemoveElem(type* d)

{

	SNode* curr = head;

	SNode* p1;

	if (*(head->data) == *d)

	{

		p1 = head;

		head = head->next;

		delete p1;

		return true;

	}

	while (curr->next && *(curr->next->data) != *d)

		curr = curr->next;

	if (curr->next)

	{

		p1 = curr->next;

		curr->next = curr->next->next;

		delete p1;

		return true;

	}

	return false;

}

template<class type>

void CListTemplate<type>::DisplayList()

{

	SNode* curr = head;

	while (curr)

	{

		cout << *(curr->data) << " ";

		curr = curr->next;

	}

	cout << endl;

}


template<class type>
void CListTemplate<type>::clear()

{

	SNode* curr = head;

	while (head)

	{

		curr = head;

		head = head->next;

		delete curr;

	}

}

int main()

{
	setlocale(LC_ALL, "Russian");

	CListTemplate<double> cl;

	CListTemplate<int> c_int;
	int key, counter = 0;
	double n;
	double y;
	double val;
	
	do

	{

		printf("\n1 - добавление элемента\n");

		printf("2 - вывод списка на экран\n");

		printf("3 - вставить элемент \n");

		printf("ESC - выход\n");

		printf("Ваш выбор: \n");

		key = _getch();

		switch (key)

		{

		case '1':

			printf("Введите элемент списка: ");
			cin >> val;
		

			cl.AddElem(new double(val));
			counter++;
			break;

		case '2':

			cl.DisplayList();

			break;

		case '3':
		
			cout << "Элементов в списке: " << counter << endl;
			cout << "Enter N" << endl;
			cin >> n;
			cout << "Enter Y" << endl;
			cin >> y;
			if (n > counter)
			{
				cout << "Вы ввели слишком большое значение n" << endl;
				cout << "Элементов в списке: " << counter << endl;
				break;
				
			}
			std::cout << "Вставляем элемент в позицию " << n << std::endl;
			
			cl.insert(y, n);

			break;
		}

	} while (key != 27);
	


	return 0;

}