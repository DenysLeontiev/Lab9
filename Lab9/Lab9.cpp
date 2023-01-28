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
void PrintNumbers(List* begin, int size);
//void l_delete(List* head, int n);
void l_delete(List* head);

int main()
{
	int size = 0;
	cout << "EnterSize: "; cin >> size;

	List* begin = NULL;

	Init(&begin, size);
	PrintList(begin);
	cout << "Odd numbers: " << endl;
	//PrintNumbers(begin, size);
	l_delete(begin);
}

void Init(List** begin, int size)
{
	*begin = new List;

	(*begin)->number = 2;
	(*begin)->next = NULL;

	List* end = *begin;

	for (int i = 3; i <= size; i++)
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

void PrintNumbers(List* begin, int size)
{
	List* print = begin;
	for (int i = 2; i * i < size; i++)
	{
		if (print->number != 0)
		{
			for (int j = i * i; j <= size; j += i)
			{
				print->number = 0;

			}

		}
	}
}

void l_delete(List* head)
{
	List* last = head->next; // track the last known prime node. skip node 2. 
	// note this will blow up if there is no node 2.
	while (last) // for every node still in the list
	{
		List** current = &last->next; // similar to trick above.
		// if we have a pointer to the next to be 
		// updated, we don't need to track the previous node   
		while ((*current)) // look at every node after the last prime
		{
			if ((*current)->number % last->number == 0) // if it's a multiple, remove it.
			{
				List* to_del = (*current); //save node to delete
				(*current) = (*current)->next; // link previous node to next node. 
				// effectively automatically advances the node
				delete to_del;
			}
			else // proceed to next node
			{
				current = &(*current)->next;
			}
		}
		cout << last->number << endl;
		last = last->next; // advance to next prime number
	}
}

//void l_delete(List* head,int n)
//{
//	List* temp = head;
//	for (int i = 2; i < sqrt(n); i++)
//	{
//		while (temp->next != 0)
//		{
//			if (temp->next->number % i == 0 && temp->next->number != i)
//			{
//				List* temp2 = temp->next->next;
//				delete temp->next;
//				temp->next = temp2;
//			}
//			if (temp->next == 0) break;
//			temp = temp->next;
//		}
//		temp = head;
//		if (temp->number % i == 0 && temp->number != i)
//		{
//			head = temp->next;
//			delete temp;
//			temp = head;
//		}
//	}
//}



