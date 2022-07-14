// https://www.acmicpc.net/problem/2559

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    bool max_status = false;
    int N, K, sum = 0, max = 0;

    vector<int> temperatures, temperatures_sum;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    K--;

    temperatures.resize(N);
    temperatures_sum.resize(N - K);

    for (int i = 0; i < N; i++) {
        cin >> temperatures[i];

        sum += temperatures[i];

        if (i >= K) {
            if (!max_status) {
                max = sum;
                max_status = true;
            }

            temperatures_sum[i - K] = sum;
            sum -= temperatures[i - K];
            max = (temperatures_sum[i - K] > max ? temperatures_sum[i - K] : max);
        }
    }

    cout << max << '\n';

    return 0;
}