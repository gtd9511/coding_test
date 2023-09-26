#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans1, ans2, ans3;
vector<long long> num;
long long triple = 3000000000;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());

	for (int i = 0; i < N - 2; i++)
	{
		int l = i + 1, r = N - 1;
		while (l < r)
		{
			long long temptriple = num[i] + num[l] + num[r];
			if (abs(temptriple) < triple)
			{
				triple = abs(temptriple);
				ans1 = num[i];
				ans2 = num[l];
				ans3 = num[r];
			}
			if (temptriple < 0)
				l++;
			else
			 	r--;
		}
	}
	cout << ans1 << " " << ans2 << " " << ans3;
	return (0);
}
