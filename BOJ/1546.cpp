#include <iomanip>
#include <iostream>
using namespace std;

double N, M;
double arr[1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double max = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (max < arr[i])
			max = arr[i];
	}
	double ans = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] = arr[i] * 100 / max;
		ans += arr[i];
	}
	ans /= N;
	cout << fixed << setprecision(6) << ans << "\n";
	return (0);
}
