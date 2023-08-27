#include <iostream>
using namespace std;

int count_zero[41];
int count_one[41];

void set_fibo()
{
	count_zero[0] = 1;
	count_zero[1] = 0;
	count_one[0] = 0;
	count_one[1] = 1;
	for(int i = 2; i < 41; i++)
	{
		count_zero[i] = count_zero[i - 1] + count_zero[i - 2];
		count_one[i] = count_one[i - 1] + count_one[i - 2];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	set_fibo();
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		cout << count_zero[temp] << " " << count_one[temp] << "\n";
	}
	// for (int i = 0; i < 40; i++)
		// cout << count_zero[i] << " " << count_one[i] << "\n";
	return (0);
}
