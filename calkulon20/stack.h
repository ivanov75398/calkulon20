#pragma once;

#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

class stack
{
	int Size;
	int Index;
	int j;
	int *mem;
public:
	int GetVAL() { return mem[Index]; }
	stack(int _Size);
	stack(const stack &b);
	void push(int val, int n);
	int pop(int n);
	void refreshIndex() { j = Size; }
	void show();
	stack &operator=(const stack &b);
	bool stackFULL();
	bool stackEMPTY(int n);

	friend istream& operator >> (istream &in, stack &v)
	{
		for (int i = 0; i <= v.Index; i++)
			in >> v.mem[i];
		return in;
	}
	friend ostream& operator<<(ostream &out, const stack &v)
	{
		for (int i = 0; i <= v.Index; i++)
			out << v.mem[i] << ' ';
		return out;
	}
};