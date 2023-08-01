#include <iostream>
using namespace std;

int N, B;
string ans;
int main()
{
	cin >> N >> B;
	while (N >= B)
	{
		int temp = N % B;
		if (temp > 9)
			temp += 55;
		else
		 	temp += '0';
		ans = (char)temp + ans;
		N /= B;
	}
	if (N > 9)
		N += 55;
	else
	 	N += '0';
	ans = (char)N + ans;
	cout << ans;
	return (0);
}


