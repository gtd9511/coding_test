#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		if (r1 + r2 > (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
			cout << -1 << "\n";
		else if(r1 + r2 == (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1))
			cout << 1 << "\n";
		else if (r1 > (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) || (r2 > (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)))
			cout << 0 << "\n";
		else
			cout << 2 << "\n";
	}
	return (0);
}
