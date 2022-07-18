// https://www.acmicpc.net/problem/3036

#include <iostream>
#include <vector>

using namespace std;

int CalculateGCD(int a, int b) {
    return (a % b == 0 ? b : CalculateGCD(b, a % b));
}

int main(void) {
    int N, gcd;

    vector<int> ring;

    cin >> N;

    ring.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> ring[i];
    }

    for (int i = 1; i < N; i++) {
        if (ring[0] % ring[i] == 0) {
            cout << ring[0] / ring[i] << "/1" << '\n';

            continue;
        }

        gcd = CalculateGCD(ring[0], ring[i]);

        cout << ring[0] / gcd << '/' << ring[i] / gcd << '\n';
    }

    return 0;
}