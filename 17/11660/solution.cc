// https://www.acmicpc.net/problem/11660

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N, M, x1, y1, x2, y2;

    vector<vector<int>> table;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    table.resize(N + 1);
    table[0].resize(N + 1);

    for (int i = 0; i < N; i++) {
        table[i + 1].resize(N + 1);

        for (int j = 0; j < N; j++) {
            cin >> table[i + 1][j + 1];

            table[i + 1][j + 1] += table[i][j + 1] + table[i + 1][j] - table[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << table[x2][y2] - table[x2][y1 - 1] - table[x1 - 1][y2] + table[x1 - 1][y1 - 1] << '\n';
    }

    return 0;
}