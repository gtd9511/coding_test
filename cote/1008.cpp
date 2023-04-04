#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	double A, B;
	cin >> A >> B;
	cout << fixed << setprecision(16) << A/B << endl;
	return (0);
}
