// https://www.acmicpc.net/problem/11051

#include <iostream>
#include <vector>

using namespace std;

int Combination(int n, int r, vector<vector<int>> &memo) {
    const int divisor = 10007;

    if (memo[n].size() < r + 1) memo[n].resize(r + 1);

    if (memo[n][r]) return memo[n][r];

    if (r == 0 || n == r) return memo[n][r] = 1;

    return memo[n][r] = (Combination(n - 1, r - 1, memo) + Combination(n - 1, r, memo)) % divisor;
}

int main(void) {
    int N, K;

    vector<vector<int>> memo;

    cin >> N >> K;

    memo.resize(N + 1);

    cout << Combination(N, K, memo) << '\n';

    return 0;
}