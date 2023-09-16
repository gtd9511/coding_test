#include <iostream>
#include <sys/types.h>
using namespace std;

long long n;

long long fibo(long long n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 1;
	if (n == 2)
		return 2;

}

int main()
{
	cin >> n;


	return (0);
}


// A % N + B % N 9 7 16 7 25 7 4 2 2
//
//1 1
//2 1
//3 2
//4 3
//5 5
//6 8
//7 13
//8 21
//9 34
//10 55

//1	1
//2	1
//4	3
//8	21
//16 987
// p(2 * n) = p(n)

//34 21 13
//	13 8 8 5
//	5 8 8 8 5

//F[2n] = F[n]x(2F[n-1] + F[n])
//F[2n+1] = F[n+1]^2 + F[n]^2
