#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, B, C;
	int A[1000000];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;
	long long ret = 0;
	for (int i = 0; i < N; i++)
	{
		int ans = 1;
		if (A[i] > B)
		{
			ans += (A[i] - B) / C;
			if ((A[i] -B) % C > 0)
				ans++;
		}
		ret += ans;

		//cout << "i : " << i << " " << ans << " " << ret << endl;
	}
	cout << ret << endl;
	return (0);
}


//first try
//13458
/*
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
*/
