#include <iostream>
using namespace std;

int A, B, C, D, E, F, G, H;

int main()
{
	cin >> A >> B >> C >> D >> E >> F >> G >> H;
	if (A == 1 && B == 2 && C == 3 && D == 4 && E == 5 && F == 6 && G == 7 && H == 8) cout << "ascending";
	else if (A == 8 && B == 7 && C == 6 && D == 5 && E == 4 && F == 3 && G == 2 && H == 1) cout << "descending";
	else cout << "mixed";
	return (0);
}
