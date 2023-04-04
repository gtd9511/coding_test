1
#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr = new int [N];
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int B, C;
	cin >> B >> C;
	long long cnt = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] -= B;
		cnt++;
		if (arr[i] > 0)
		{
			if (arr[i] % C != 0)
				cnt = cnt + (arr[i] / C) + 1;
			else
				cnt += (arr[i] / C);
		}
	}
	cout << cnt << endl;
	delete[] arr;
	return (0);
}
