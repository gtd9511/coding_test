#include <iostream>

using namespace std;

static int a = 0;
void add()
{
	a++;
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		add();
		cout << a << endl;
	}
	return 0;
}
