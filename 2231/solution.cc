// https://www.acmicpc.net/problem/2231

#include <iostream>

using namespace std;

int main(void) {
    int N, digit, i, sum, temp;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    digit = 0;
    temp = N;

    while (temp > 0) {
        temp /= 10;
        digit++;
    }

    for (i = N - digit * 9; i < N; i++) {
        sum = i;
        temp = i;

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (sum == N) break;
    }

    cout << (i == N ? 0 : i) << '\n';

    return 0;
}