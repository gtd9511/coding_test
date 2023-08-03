#include <iostream>
using namespace std;

int x, y, w, h;

int main()
{
	cin >> x >> y >> w >> h;
	int min = x;
	if (min > y) min = y;
	if (min > w - x) min = w - x;
	if (min > h - y) min = h - y;
	cout << min << '\n';
	return (0);
}
