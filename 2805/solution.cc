// https://www.acmicpc.net/problem/2805

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M, start, middle, end;
    long long height;

    vector<int> trees;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    trees.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> trees[i];
    }

    sort(trees.begin(), trees.end(), greater<int>());

    start = 0;
    end = trees[0];

    while (start < end) {
        height = 0;
        middle = (start + end) / 2;

        for (int i = 0; i < N; i++) {
            if (trees[i] <= middle) break;

            height += trees[i] - middle;
        }

        if (height < M) end = middle;
        else start = middle + 1;
    }

    cout << start - 1 << '\n';

    return 0;
}