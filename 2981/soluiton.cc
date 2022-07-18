// https://www.acmicpc.net/problem/2981

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int CalculateGCD(int a, int b) {
    return (a % b == 0 ? b : CalculateGCD(b, a % b));
}

int main(void) {
    int N, gcd, sqrt_gcd;

    vector<int> numbers;
    set<int> memo;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    numbers.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 1; i < N; i++) {
        numbers[i] = numbers[i] - numbers[0];
    }

    numbers.erase(numbers.begin());

    gcd = numbers[0];

    for (int i = 1; i < numbers.size(); i++) {
        gcd = CalculateGCD(gcd, numbers[i]);
    }

    sqrt_gcd = sqrt(gcd);

    memo.insert(gcd);

    for (int i = 2; i <= sqrt_gcd; i++) {
        if (gcd % i == 0) {
            memo.insert(i);
            memo.insert(gcd / i);
        }
    }

    for (auto it = memo.begin(); it != memo.end(); it++) {
        cout << *it << '\n';
    }

    return 0;
}