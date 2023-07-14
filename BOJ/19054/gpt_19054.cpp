#include <iostream>
#include <vector>

std::vector<int> numlist;

bool process(int l, int r) {
    int num = 0;
    for (int i = l; i <= r; i++) {
        if (numlist[i] == 1) {
            num += 1;
        }
    }
    if (num & 2) {
        return false;
    }
    while (l < r && numlist[l] == numlist[r]) {
        l += 1;
        r -= 1;
    }
    while (l <= r) {
        if (numlist[l] ^ numlist[l + 1]) {
            return false;
        }
        l += 2;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        numlist.resize(n);
        for (int j = 0; j < n; j++) {
            std::cin >> numlist[j];
        }
        int Sum = 0;
        for (int j = 0; j < n; j++) {
            Sum ^= numlist[j];
        }
        if (Sum == 0) {
            std::cout << "Draw" << std::endl;
            continue;
        }
        if (n == 1) {
            std::cout << "First" << std::endl;
            continue;
        }
        if (n % 2 == 0) {
            std::cout << "First" << std::endl;
            continue;
        }
        int m = 0;
        for (int j = 31; j >= 0; j--) {
            if ((Sum >> j) & 1) {
                m = j;
                break;
            }
        }
        for (int j = 0; j < n; j++) {
            numlist[j] = (numlist[j] >> m) & 1;
        }
        if (numlist[0] == 1 && process(1, n - 1)) {
            std::cout << "First" << std::endl;
            continue;
        }
        if (numlist[n - 1] == 1 && process(0, n - 2)) {
            std::cout << "First" << std::endl;
            continue;
        }
        std::cout << "Second" << std::endl;
    }

    return 0;
}
