#include <iostream>
using namespace std;
const int TEN = 10, TWO = 2;

int getResult(int a)
{
	int result;
	__asm
	{
		mov eax, a
		mov ebx, 0
	beg :
		cmp eax, 0
		je end_
		cdq
        idiv TEN
		cmp edx, 1
		jne beg
        add ebx, 1
		jmp beg
	end_ :
		mov eax, ebx
		cdq
		idiv TWO
		cmp edx, 1
		je odd
		mov result, 0
		jmp total_end
    odd:
		mov result, 1
	total_end:
	}
	return result;
}

void tests(int a, int yourAnswer)
{
	if (getResult(a) == yourAnswer)
		cout << "OK" << endl;
	else
		cout << "Fail here" << endl;
}

int main()
{
	tests(12471641, 1);
	tests(32171, 0);
	tests(3473647, 1);       //0
	return 0;
}