// https://www.acmicpc.net/problem/1912

#include <iostream>
#include <vector>

using namespace std;

int find_max(vector<int> &sequence, vector<int> &max_sequence) {
    int max = max_sequence[0] = sequence[0];

    for (int i = 1; i < sequence.size(); i++) {
        max_sequence[i] = (max_sequence[i - 1] < 0 ? sequence[i] : max_sequence[i - 1] + sequence[i]);
        max = (max_sequence[i] > max ? max_sequence[i] : max);
    }

    return max;
}

int main(void) {
    int N, number;

    vector<int> sequence;
    vector<int> max_sequence;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> number;

        sequence.push_back(number);
    }

    max_sequence.resize(N);

    cout << find_max(sequence, max_sequence) << endl;

    return 0;
}