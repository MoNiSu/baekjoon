// https://www.acmicpc.net/problem/9251

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    string A, B;
    vector<vector<int>> memo;

    cin >> A >> B;

    memo.resize(B.size() + 1);

    for (int i = 0; i < B.size() + 1; i++) {
        memo[i].resize(A.size() + 1);

        if (i == 0) continue;

        for (int j = 1; j < A.size() + 1; j++) {
            if (A[j - 1] == B[i - 1]) memo[i][j] = memo[i - 1][j - 1] + 1;
            else memo[i][j] = max(memo[i][j - 1], memo[i - 1][j]);
        }
    }

    cout << memo[B.size()][A.size()] << endl;

    return 0;
}