// https://www.acmicpc.net/problem/2740

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, M, K;

    vector<vector<int>> A, B, result;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    A.resize(N);

    for (int i = 0; i < N; i++) {
        A[i].resize(M);

        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    cin >> M >> K;

    B.resize(M);

    for (int i = 0; i < M; i++) {
        B[i].resize(K);

        for (int j = 0; j < K; j++) {
            cin >> B[i][j];
        }
    }

    result.resize(N);

    for (int i = 0; i < N; i++) {
        result[i].resize(K);

        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }

            cout << result[i][j] << ' ';
        }

        cout << '\n';
    }

    return 0;
}