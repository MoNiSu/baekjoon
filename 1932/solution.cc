// https://www.acmicpc.net/problem/1932

#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<int>> &triangle) {
    int max = 0;
    int last_index;

    vector<vector<int>> memo(triangle);

    last_index = triangle.size() - 1;

    for (int i = 0; i < last_index; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            memo[i + 1][j] = (memo[i][j] + triangle[i + 1][j] > memo[i + 1][j] ? memo[i][j] + triangle[i + 1][j] : memo[i + 1][j]);
            memo[i + 1][j + 1] = (memo[i][j] + triangle[i + 1][j + 1] > memo[i + 1][j + 1] ? memo[i][j] + triangle[i + 1][j + 1] : memo[i + 1][j + 1]);
        }
    }

    for (int i = 0; i < memo[last_index].size(); i++) {
        max = (memo[last_index][i] > max ? memo[last_index][i] : max);
    }

    return max;
}

int main(void) {
    int N, number;

    vector<vector<int>> triangle;

    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> line;

        for (int j = 0; j <= i; j++) {
            cin >> number;

            line.push_back(number);
        }

        triangle.push_back(line);
    }

    cout << solve(triangle) << endl;

    return 0;
}