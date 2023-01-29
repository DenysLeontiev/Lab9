#include <iostream>

using namespace std;

struct List
{
	int number;
	List* next;
};

int setValue(const char v[]);
void Init(List** begin, int size);
void PrintList(List* list);
void PrintPrimeNumbers(List* head, int size);

int main()
{
	int size = 0;
	while (size <= 1)
	{
		cout << "size must be greater than 1" << endl;
		size = setValue("size");
	}
	List* begin = NULL;

	Init(&begin, size);
	cout << "List: " << endl;
	PrintList(begin);
	cout << "Prime numbers: " << endl;
	PrintPrimeNumbers(begin, size);
}

void Init(List** begin, int size)
{
	*begin = new List;

	(*begin)->number = 2;
	(*begin)->next = NULL;

	List* end = *begin;

	for (int i = 3; i <= size * size; i++)
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

void PrintPrimeNumbers(List* head, int size)
{
	List* last = head; 
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
		if (last->number >= size)
		{
			cout << last->number << endl;
		}
		last = last->next;
	}
}

int setValue(const char v[])
{
	int error;
	int value;
	do
	{
		error = 0;
		cout << "Please enter " << v << " = ";
		cin >> value;
		if (cin.fail())
		{
			cout.clear();
			cout << "Please enter a valid number" << endl;
			error = 1;
			cin.clear();
			cin.ignore(80, '\n');
		}
	} while (error == 1);

	return value;
}



