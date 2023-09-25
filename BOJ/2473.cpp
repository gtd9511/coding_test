#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<long long> negative;
vector<long long> positive;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp >= 0)
			positive.push_back(temp);
		else
			negative.push_back(temp);
	}
	sort(positive.begin(), positive.end());
	sort(negative.begin(), negative.end());
	reverse(negative.begin(), negative.end());

	long long triplepos = 3000000000, tripleneg = 3000000000 , triplecol = 3000000000;
	if (positive.size() >= 3)
		triplepos = positive[0] + positive[1] + positive[2];
	if (negative.size() >= 3)
		tripleneg = negative[0] + negative[1] + negative[2];

	int p = 0, n = 0, ansp = 0, ansn = 0;
	if (positive.size() && negative.size())
	{
		while (p < positive.size() || n < negative.size())
		{
			long long temp = positive[p] + negative[n];
			if (abs(temp) < abs(triplecol) && p < positive.size() && n < negative.size())
			{
				triplecol = temp;
				ansp = p;
				ansn = n;
			}
			if (temp > 0)
			{
				if (n < negative.size() - 1)
					n++;
				else if(p < positive.size())
				 	p++;
			}
			else
			{
				if (p < positive.size() - 1)
					p++;
				else if (n < negative.size())
				 	n++;
			}
		}
	}

	if (abs(triplepos) < abs(tripleneg) && abs(triplepos) < abs(triplecol))
		cout << positive[0] << " " << positive[1];
	if (abs(tripleneg) < abs(triplepos) && abs(tripleneg) < abs(triplecol))
		cout << negative[1] << " " << negative[0];
	if (abs(triplecol) <= abs(tripleneg) && abs(triplecol) <= abs(triplepos))
		cout << negative[ansn] << " " << positive[ansp];

	return (0);
}
