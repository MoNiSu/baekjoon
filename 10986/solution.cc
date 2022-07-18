// https://www.acmicpc.net/problem/10986

#include <iostream>
#include <map>

using namespace std;

int main(void) {
    int N, M, input, temp = 0;
    long long result = 0;

    map<int, int> memo;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> input;

        temp += input;
        temp %= M;

        memo[temp]++;
    }

    result += memo[0];

    for (auto it = memo.begin(); it != memo.end(); it++) {
        result += (long long)it->second * (it->second - 1) / 2;
    }

    cout << result << '\n';

    return 0;
}