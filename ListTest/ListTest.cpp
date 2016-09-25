// ListTest.cpp : Defines the entry point for the console application.
//


#include "LinkedList.h"
#include <conio.h>
#include <iostream>

using namespace std;

struct X
{
public:
	int xx;
	int ff;
};
bool IsTen(X a);
int main()
{
	LinkedList<X>* list = new LinkedList<X>();
	X* dff = new X;
	dff->ff = 10;
	dff->xx = 20;
	list->Add(dff);
	dff = new X;
	dff->ff = 20;
	list->Add(dff);
	dff = new X;
	dff->ff = 30;
	list->Add(dff);
	dff = new X;
	dff->ff = 10;
	dff->xx = 400;
	list->Add(dff);
	for (int i = 0; i < list->Count; i++)
	{
		cout << list->GetAt(i).ff << " ";
	}
	printf("\n");
	LinkedList<X> ls = list->GetRange(0, 2);
	for (int i = 0; i < ls.Count; i++)
	{
		cout << ls.GetAt(i).ff << " ";
	}

	auto test = list->Where(IsTen);
	cout << "\n\n\n";
	for (int i = 0; i < test.Count; i++)
	{
		cout << test.GetAt(i).ff << " ";
	}
	cin.get();
    return 0;
}

bool IsTen(X a)
{
	if (a.xx==10||a.ff==10)
	{
		return true;
	}
	return false;
}

