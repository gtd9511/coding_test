#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, ans = 0;
	int temp = 0;
	cin >> n;
	for (int i = 1; i <= static_cast<int>(sqrt(n)); i++)
	{
		ans += n / i;
		ans += i;
		if (i == 1)
			temp = n / i;
		else
		{
		 	ans += (temp - (n / i) - 1) * i;
			cout << (temp - (n / i) - 1) * i << endl;
			temp = n / i;
		}


		cout << "i : " << i << " " << n / i << " " << ans << endl;
		if (n % i != 0)
			ans++;
	}
	// ans += (n / 2) * 2 + 1;
	cout << ans;
	return (0);
}

//1 3
//2 2
//3 1

// 12 1 10 6 2 3
// 1 12 d
// 2 6 d
// 3 4

// 4 3
// 5 3 d

// 6 2 d

// 7 2 d
// 8 2 d
// 9 2 d
// 10 2 d
// 11 2 d
// 12 1 d

//41
//20
//13
//10
//8
//8

// 1 12
// 2 6
// 3 4
// 4 3
// 6 2
// 12 1

//1 9
//2 4
//3 3


//41
//1 41
//2 21
//3 14
//4 11
//5 9
//6 7

//7 6
//8 6

//9 5
//10 5

//11 4
//12 4
//13 4

//14 3
//15 3
//16 3
//17 3
//18 3
//19 3
//20 3

//21 2
//40 2


//41 1
