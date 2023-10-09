#include <iostream>
using namespace std;

int N, dp[101][10][1024];



int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N;
	if (N < 10)
	{
		cout << 0;
		return (0);
	}



	return (0);
}

//	1	0
//	2
//	3
//	10	9876543210

//	11	89876543210
//		98765432101
//		10123456789

//	12	989876543210
// 		789876543210
//		898765432101
//		987654321010
//		987654321012

//		987876543210


//		9 8 7 6 5 4 3 2 1 0
//		0 1 2 3 4 5 6 7 8 9

//		10	2	1	1
//		11	4	1	3
//		12


#include <stdio.h>
using namespace std;

#define mod 1000000000

int n, i, j, k, ans;
int dp[101][10][1 << 10];

int main() {
    scanf("%d", &n);

    int full = (1 << 10) - 1;

    for (j = 1; j <= 9; ++j)
        dp[1][j][1 << j] = 1;

    for (i = 2; i <= n; ++i) {
        for (j = 0; j <= 9; ++j) {
            for (k = 0; k <= full; ++k) {
                if (j == 0)
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
                else {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
                }
            }
        }
    }

    for (j = 0; j <= 9; ++j)
        ans = (ans + dp[n][j][full]) % mod;

    printf("%d", ans);

    return 0;
}
