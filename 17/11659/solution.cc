// https://www.acmicpc.net/problem/11659

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, M, a, b, number, sum = 0;

    vector<int> numbers;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    numbers.push_back(0);

    for (int i = 0; i < N; i++) {
        cin >> number;

        sum += number;

        numbers.push_back(sum);
    }

    for (int i = 0; i < M; i++) {
        cin >> a >> b;

        cout << numbers[b] - numbers[a - 1] << '\n';
    }

    return 0;
}