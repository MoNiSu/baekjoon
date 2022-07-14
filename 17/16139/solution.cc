// https://www.acmicpc.net/problem/16139

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    char a;
    int q, l, r;

    const int alphabet_size = 26;

    string S;

    vector<vector<int>> memo;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> S >> q;

    memo.resize(S.size());
    memo[0].resize(alphabet_size);

    for (int i = 0; i < S.size(); i++) {
        if (i > 0) memo[i].assign(memo[i - 1].begin(), memo[i - 1].end());

        memo[i][S[i] - 'a']++;
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> l >> r;

        cout << memo[r][a - 'a'] - (l - 1 < 0 ? 0 : memo[l - 1][a - 'a']) << '\n';
    }

    return 0;
}