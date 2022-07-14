// https://www.acmicpc.net/problem/11401

#include <iostream>

using namespace std;

typedef long long ll;

ll GetPowerOfX(ll x, int n) {
    const int DIVISOR = 1000000007;

    ll half, whole;

    if (n == 0) return 1;
    if (n == 1) return x;

    half = GetPowerOfX(x, n / 2) % DIVISOR;
    whole = half * half % DIVISOR;

    if (n % 2 == 0) return whole;

    return whole * x % DIVISOR;
}

int main(void) {
    int N, K;
    const int DIVISOR = 1000000007;

    ll a = 1, b = 1, result;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        a *= i;
        a %= DIVISOR;
    }

    for (int i = 1; i <= K; i++) {
        b *= i;
        b %= DIVISOR;
    }

    for (int i = 1; i <= N - K; i++) {
        b *= i;
        b %= DIVISOR;
    }

    result = a * GetPowerOfX(b, DIVISOR - 2) % DIVISOR;

    cout << result << '\n';

    return 0;
}