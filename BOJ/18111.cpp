#include <iostream>
using namespace std;

int arr[500][500];

int N, M, B, avg = 0, res = 2147483647;

int main()
{
	cin >> N >> M >> B;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	for (int height = 0; height < 257; height++)
	{
		int put = 0;
		int remove = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int temp = arr[i][j] - height;
				if (temp > 0)
					remove += temp;
				else
					put -= temp;
			}
		}
		if (remove + B >= put)
		{
			int time = remove * 2 + put;
			if (res >= time)
			{
				res = time;
				avg = height;
			}
		}
	}
	cout << res << " " << avg;
	return (0);
}
