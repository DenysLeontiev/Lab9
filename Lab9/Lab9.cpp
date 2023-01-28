#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

struct List
{
	int number;
	List* next;
};

void Init(List** begin, int size);
void PrintList(List* list);
void PrintPrimeNumbers(List* head);

int main()
{
	int size = 0;
	cout << "EnterSize: "; cin >> size;
	List* begin = NULL;

	Init(&begin, size);
	PrintList(begin);
	cout << "Prime numbers: " << endl;
	PrintPrimeNumbers(begin);
}

void Init(List** begin, int size)
{
	*begin = new List;

	(*begin)->number = size;
	(*begin)->next = NULL;

	List* end = *begin;

	for (int i = 2; i <= size * size; i++)
	{
		end->next = new List;
		end = end->next;
		end->number = i;
		end->next = NULL;
	}

}

void PrintList(List* begin)
{
	List* print = begin;
	while (print)
	{
		cout << print->number << endl;
		print = print->next;
	}
}

void PrintPrimeNumbers(List* head)
{
	List* last = head->next; 
	while (last)
	{
		List** current = &last->next; 
		while ((*current))
		{
			if ((*current)->number % last->number == 0)
			{
				List* to_del = (*current);
				(*current) = (*current)->next;
				delete to_del;
			}
			else
			{
				current = &(*current)->next;
			}
		}
		cout << last->number << endl;
		last = last->next;
	}
}



