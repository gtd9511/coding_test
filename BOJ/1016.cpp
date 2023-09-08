#include <iostream>
#include <vector>
using namespace std;
long long is_prime[1000001] = {0, };

int main()
{
	long long min, max;
	cin >> min >> max;
	for (long long i = 2; i * i <= max; i++)
	{
		long long low_v = min / (i * i);







	}
	return (0);
}


        for (long long i = 2; i * i <= max; i++) {
                long long n = min / (i * i);

                if (min % (i * i)) n++;

                while (n * i * i <= max) {		//n*i*i는 min보다 크거나 같은 i의 제곱수의 배수
                        number[n * i * i - min] = 1;
                        n++;
                }
        }

        for (int i = 0; i <= max - min; i++) {
                if (number[i] == 0) cnt++;
        }

