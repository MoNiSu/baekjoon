// https://www.acmicpc.net/problem/10830

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<vector<int>> MultiplyMatrix(vector<vector<int>> &A, vector<vector<int>> &B) {
    const int DIVISOR = 1000;

    vector<vector<int>> result;

    result.resize(A.size());

    for (int i = 0; i < A.size(); i++) {
        result[i].resize(B[i].size());

        for (int j = 0; j < B[i].size(); j++) {
            for (int k = 0; k < A[i].size(); k++) {
                result[i][j] += A[i][k] * B[k][j] % DIVISOR;
            }

            result[i][j] %= 1000;
        }
    }

    return result;
}

vector<vector<int>> GetPowerOfMatrix(vector<vector<int>> &x, ll n) {
    vector<vector<int>> half, whole;
    
    if (n == 0) {
        whole.resize(x.size());

        for (int i = 0; i < x.size(); i++) {
            whole[i].resize(x[i].size());

            whole[i][i] = 1;
        }

        return whole;
    }

    if (n == 1) {
        whole.resize(x.size());

        for (int i = 0; i < x.size(); i++) {
            whole[i].resize(x[i].size());

            for (int j = 0; j < x[i].size(); j++) {
                whole[i][j] = x[i][j] % 1000;
            }
        }

        return whole;
    }

    half = GetPowerOfMatrix(x, n / 2);
    whole = MultiplyMatrix(half, half);

    if (n % 2 == 0) return whole;

    return MultiplyMatrix(whole, x);
}

int main(void) {
    int N;
    ll B;

    vector<vector<int>> A, result;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> B;

    A.resize(N);

    for (int i = 0; i < N; i++) {
        A[i].resize(N);

        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    
    result = GetPowerOfMatrix(A, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}