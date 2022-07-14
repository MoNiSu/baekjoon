// https://www.acmicpc.net/problem/9461

#include <iostream>
#include <vector>

using namespace std;

long long P(int N, vector<long long> &p_data) {
    if (N < 1) {
        return 0;
    }

    if (!p_data[N]) {
        if (N < 3) {
            p_data[N] = 1;
        } else {
            p_data[N] = P(N - 2, p_data) + P(N - 3, p_data);
        }

        return p_data[N];
    }

    return p_data[N];
}

int main(void) {
    int T, N;

    vector<long long> p_data(101);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        cout << P(N, p_data) << endl;
    }

    return 0;
}