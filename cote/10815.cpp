#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int Narr[500000];
	int Marr[500000];

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> Narr[i];
	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> Marr[i];

	sort(Narr, Narr + N);

	for (int i = 0; i < M; i++)
	{
		int left = 0;
		int right = N - 1;
		int mid;
		int flag = 0;

		while (left <= right)
		{
			mid = (left + right) / 2;
			if (Narr[mid] == Marr[i])
			{
				flag = 1;
				break;
			}
			else if (Narr[mid] > Marr[i])
				right = mid - 1;
			else
				left = mid + 1;
		}
		cout << flag << ' ';
	}

	return (0);
}
