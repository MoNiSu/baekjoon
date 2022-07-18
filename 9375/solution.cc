// https://www.acmicpc.net/problem/9375

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(void) {
    int T, N, cases;

    string costume, type;

    map<string, set<string>> closet;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cases = 1;
        closet.clear();

        cin >> N;

        for (int j = 0; j < N; j++) {
            cin >> costume >> type;

            closet[type].insert(costume);
        }

        for (auto it = closet.begin(); it != closet.end(); it++) {
            cases *= it->second.size() + 1;
        }

        cout << cases - 1 << '\n';
    }

    return 0;
}