// https://www.acmicpc.net/problem/1010

#include <iostream>
#include <vector>

using namespace std;

int Combination(int n, int r, vector<vector<int>> &memo) {
    if (memo[n].size() < r + 1) memo[n].resize(r + 1);

    if (memo[n][r]) return memo[n][r];

    if (r == 0 || n == r) return memo[n][r] = 1;

    return memo[n][r] = Combination(n - 1, r - 1, memo) + Combination(n - 1, r, memo);
}

int main(void) {
    int T, N, M;

    vector<vector<int>> memo;

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N >> M;

        if (memo.size() < M + 1) memo.resize(M + 1);

        cout << Combination(M, N, memo) << '\n';
    }

    return 0;
}