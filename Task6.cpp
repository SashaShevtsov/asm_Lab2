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
			idiv TWO
			cmp edx, 1
			jne beg
			add ebx, 1
			jmp beg
	end_ :
		mov result, ebx	
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
	tests(247, 7);
	tests(1235, 6);
	tests(932, 4);   //5
	return 0;
}