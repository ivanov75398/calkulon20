#include "stack.h"

stack::stack(int _Size)
{
	Size = _Size;
	mem = new int[Size];
	Index = -1;
	j = Size;
}

void stack::show()
{
	if (stackEMPTY(1) == false)
	for (int k = j; k < Size; k++)
	{
		cout << mem[k] << " ";
	}
}

stack::stack(const stack &b)
{
	Size = b.Size;
	mem = new int[Size];
	Index = b.Index;
	j = b.j;
	for (int i = 0; i < Index; i++)
	{
		mem[i] = b.mem[i];
	}
	for (int p = j; p < Size; p++)
	{
		mem[p] = b.mem[p];
	}
}

void stack::push(int val, int n)
{
	if (stackFULL()) { throw - 1; }
	if (n == 0)
	{
		Index++;
		mem[Index] = val;
	}
	else
	{
		if (n == 1)
		{
			j--;
			mem[j] = val;
		}
		else
		{
			throw - 10;
		}
	}
}

int stack::pop(int n)
{
	if (stackEMPTY(n)) { throw - 2; }
	if (n == 0)
	{
		Index--;
		return mem[Index + 1];
	}
	else
	{
		if (n == 1)
		{
			j++;
			return mem[j - 1];
		}
		else
		{
			throw - 15;
		}
	}
}

bool stack::stackEMPTY(int n)
{
	if ((n != 0) && (n != 1)) {throw - 5;}
	if (n == 0) return Index == -1;
	if (n == 1) return j == Size;
}

bool stack::stackFULL()
{
	return ((Index + 1) == j);
}

stack &stack:: operator=(const stack &b)
{
	if (this == &b) return *this;
	Size = b.Size;
	Index = b.Index;
	delete[]mem;
	mem = new int[Size];
	for (int i = 0; i < Index; i++)
	{
		mem[i] = b.mem[i];
	}
	for (int p = j; p < Size; p++)
	{
		mem[p] = b.mem[p];
	}
	return *this;
}