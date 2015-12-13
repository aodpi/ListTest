// ListTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lst.h"
#include <conio.h>

struct X
{
public:
	int xx;
	int ff;
};

int main()
{
	LinkedList<X> list;
	X* dff = new X;
	dff->ff = 10;
	dff->xx = 20;
	list.Add(dff);
	dff = new X;
	dff->ff = 20;
	list.Add(dff);
	dff = new X;
	dff->ff = 30;
	list.Add(dff);
	for (int i = 0; i < list.Count; i++)
	{
		printf("%i ", list.GetAt(i).ff);
	}
	printf("\n");
	LinkedList<X> ls = list.GetRange(0, 2);
	for (int i = 0; i < ls.Count; i++)
	{
		printf("%i ", ls.GetAt(i).ff);
	}
	getch();
    return 0;
}

