#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> negative;
vector<int> positive;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp > 0)
			positive.push_back(temp);
		else
			negative.push_back(temp);
	}
	reverse(negative.begin(), negative.end());

	int doublepos = 2147483647, doubleneg = 2147483647 , doublecol = 2147483647;
	if (positive.size() >= 2)
		doublepos = positive[0] + positive[1];
	if (negative.size() >= 2)
		doubleneg = negative[0] + negative[1];

	int p = 0, n = 0, ansp = 0, ansn = 0;
	if (positive.size() && negative.size())
	{
		while (p < positive.size() || n < negative.size())
		{
			int temp = positive[p] + negative[n];
			if (abs(temp) < abs(doublecol) && p < positive.size() && n < negative.size())
			{
				doublecol = temp;
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

	if (abs(doublepos) < abs(doubleneg) && abs(doublepos) < abs(doublecol))
		cout << positive[0] << " " << positive[1];
	if (abs(doubleneg) < abs(doublepos) && abs(doubleneg) < abs(doublecol))
		cout << negative[1] << " " << negative[0];
	if (abs(doublecol) <= abs(doubleneg) && abs(doublecol) <= abs(doublepos))
		cout << negative[ansn] << " " << positive[ansp];

	return (0);
}
