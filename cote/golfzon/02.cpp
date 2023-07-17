#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int max = 0;
    int temp = 0;
    if (n == 1)
        return 1;
    for (int i = 1; i < 100000; i++)
    {
        temp = temp + i;
        if (max < (i + 1) * (n - temp))
        {
            max = (i + 1) * (n - temp);
        }
        if (temp >= n)
        {
            break;
        }
    }
    answer = max;

    return answer;
}
