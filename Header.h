#pragma once
#include <iostream>
class stack
{
	int *p, first_index, second_index, size;
public:
	stack() {};
	stack(int _size)
	{
		size = _size;
		p = new int[size];
		first_index = -1;
		second_index = size;
	}
	stack(const stack & b)
	{
		size = b.size;
		p = new int[size];
		first_index = b.first_index;
		second_index = b.second_index;
		for (int i = 0; i <= first_index; i++)
		{
			p[i] = b.p[i];
		}
		for (int i = second_index; i < size; i++)
		{
			p[i] = b.p[i];
		}
	}
	~stack()
	{
		delete[] p;
	}
	bool is_Empty(int n)
	{
		if ((n != 0) && (n != 1)) throw 1;
		if (n == 0) return (first_index == -1);
		if (n == 1) return (second_index == size);
	}
	bool is_Full()
	{
		return (first_index + 1 == second_index);
	}
	void push(int n, int value)
	{
		if (is_Full()) throw - 1;
		if (n == 0) 
		{	
			first_index++;
			p[first_index] = value;
		}
		else if (n == 1)
		{
			second_index--;
			p[second_index] = value;
		}
		else throw - 1;
	}
	int pop(int n)
	{
		if (is_Empty(n)) throw - 1;
		if (n == 0)
		{
			first_index--;
			return p[first_index + 1];
		}
		else if (n == 1)
		{
			second_index++;
			return p[second_index - 1];
		}
		else throw - 1;
	}
	void clear(int n)
	{
		if (n == 0) first_index = -1;
		else if (n == 1) second_index = size;
		else throw - 1;
	}
};
