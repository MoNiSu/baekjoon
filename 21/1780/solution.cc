// https://www.acmicpc.net/problem/1780

#include <iostream>
#include <vector>

using namespace std;

bool Check(int x, int y, int size, vector<vector<int>> &paper) {
    int first_element = paper[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != first_element) return false;
        }
    }

    return true;
}

vector<int> DividePaper(int x, int y, int size, vector<vector<int>> &paper) {
    vector<int> result(3), temp;

    if (Check(x, y, size, paper)) {
        result[paper[x][y] + 1]++;

        return result;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp = DividePaper(x + size / 3 * i, y + size / 3 * j, size / 3, paper);

            for (int k = 0; k < 3; k++) {
                result[k] += temp[k];
            }
        }
    }

    return result;
}

int main(void) {
    int N;

    vector<vector<int>> paper;
    vector<int> result;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    paper.resize(N);

    for (int i = 0; i < N; i++) {
        paper[i].resize(N);

        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    result = DividePaper(0, 0, N, paper);

    cout << result[0] << '\n' << result[1] << '\n' << result[2] << '\n';

    return 0;
}