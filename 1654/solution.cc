// https://www.acmicpc.net/problem/1654

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int CountCable(ll length, vector<int> &lan_cable) {
    int cable_number = 0;

    for (int i = 0; i < lan_cable.size(); i++) {
        cable_number += lan_cable[i] / length;
    }

    return cable_number;
}

ll FindLength(int N, vector<int> &lan_cable) {
    ll start = 1, middle = 0, end = *max_element(lan_cable.begin(), lan_cable.end());

    while (start <= end) {
        middle = (start + end) / 2;

        if (CountCable(middle, lan_cable) < N) end = middle - 1;
        else start = middle + 1;
    }

    return end;
}

int main(void) {
    int K, N;

    vector<int> lan_cable;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> K >> N;

    lan_cable.resize(K);

    for (int i = 0; i < K; i++) {
        cin >> lan_cable[i];
    }

    cout << FindLength(N, lan_cable) << '\n';

    return 0;
}