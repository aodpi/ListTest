#pragma once
#include <stdio.h>
#include <stdlib.h>

#define NewItem (Payload*)malloc(sizeof(Payload));
template <class Type> class LinkedList
{
private:
	struct Payload
	{
		Type data;
		Payload* next;
	};
	Payload* head = NewItem;
public:

	LinkedList();
	Type GetAt(int index);
	void Add(Type* item);
	void Delete(Type* item);
	LinkedList<Type> GetRange(int index, int count);
	void DeleteAt(int index);
	void Reverse();
	int Count;
};

template<typename Type>
inline LinkedList<Type>::LinkedList()
{
	head->next = NULL;
	Count = 0;
}

template<typename Type>
inline Type LinkedList<Type>::GetAt(int index)
{
	Payload* start = head;
	int inx = 0;
	while (start->next!=NULL)
	{
		start = start->next;
		if (inx==index)
		{
			return start->data;
		}
		inx++;
	}
	return start->data;
}

template<typename Type>
inline void LinkedList<Type>::Add(Type * item)
{
	Payload* actitem = NewItem;
	actitem->next = NULL;
	actitem->data = *item;
	Payload* start = head;
	while (start->next != NULL)
	{
		start = start->next;
	}
	start->next = actitem;
	Count++;
}

template<class Type>
inline void LinkedList<Type>::Delete(Type * item)
{
	Payload* start = head;
	while (start->next != NULL)
	{
		if (start->next->data == item)
		{
			start->next = start->next->next;
			free(start->next);
		}
	}
}

//<summary>Gets indicated range as a new list.
//<param name="index">Starting index</param>
//<param name="count">Number of elements to get</param>
//</summary>
template<class Type>
inline LinkedList<Type> LinkedList<Type>::GetRange(int index, int count)
{
	LinkedList<Type> result;
	while (index<count)
	{
		result.Add(&this->GetAt(index));
		index++;
	}
	return result;
}

template<class Type>
inline void LinkedList<Type>::DeleteAt(int index)
{
	Payload* start = head;
	int Countx = 0;
	Payload* previous = NULL;
	if (Count == index)
	{
		while (start->next != NULL)
		{
			previous = start;
			start = start->next;
		}
		free(start);
		previous->next = NULL;
	}
	else if (index == 1)
	{
		if (Count>1)
		{
			Node* temp = start->next;
			start->to = start->next->next;
			free(temp);
		}
	}
	else
	{
		while (start->next != NULL)
		{
			previous = start;
			start = start->next;
			Countx++;
			if (index == Count)
			{
				previous->next = start->next;
				free(start);
			}
			start = previous->next;
		}
	}
}

template<class Type>
inline void LinkedList<Type>::Reverse()
{
	int i = 0;
	Payload* start = head;
	if (Count % 2 == 0)
	{
		Payload** arr = new Payload*[Count];
		while (start->next != NULL)
		{
			start = start->next;
			arr[i++] = start;
		}
		for (i = 0; i < Count / 2; i++)
		{
			Payload* temp = arr[i];
			arr[i] = arr[Count - i - 1];
			arr[Count - i - 1] = temp;
		}
		start = head;
		for (int i = 0; i < Count; i++)
		{
			start->next = arr[i];
			start = start->next;
		}
		start->next = NULL;
		delete[] arr;
	}
	else
	{
		Payload** arr = new Payload*[Count];
		while (start->next != NULL)
		{
			start = start->next;
			arr[i++] = start;
		}
		for (i = 0; i < Count / 2; i++)
		{
			Payload* temp = arr[i];
			arr[i] = arr[Count - i - 1];
			arr[Count - i - 1] = temp;
		}
		start = head;
		for (i = 0; i < Count; i++)
		{
			start->next = arr[i];
			start = start->next;
		}
		start->next = NULL;
		delete[] arr;
	}
}
