// https://www.acmicpc.net/problem/2565

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
    int N, a, b, before, max = 0, result;

    map<int, int> line;
    vector<int> B, memo;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;

        line[a] = b;
    }

    for (auto it = line.begin(); it != line.end(); it++) {
        B.push_back(it->second);
    }

    memo.resize(B.size());

    for (int i = 0; i < B.size(); i++) {
        before = -1;

        for (int j = 0; j < i; j++) {
            if (B[j] < B[i] && (before < 0 || memo[j] > memo[before])) before = j;
        }

        memo[i] = (before < 0 ? 1 : memo[before] + 1);
        max = (memo[i] > max ? memo[i] : max);
    }

    result = N - max;

    cout << result << endl;

    return 0;
}