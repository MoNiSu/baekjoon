// https://www.acmicpc.net/problem/1181

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool Compare(string a, string b) {
    if (a.length() == b.length()) return a < b;

    return a.length() < b.length();
}

int main(void) {
    int N;

    vector<string> words;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    words.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    sort(words.begin(), words.end(), Compare);
    words.erase(unique(words.begin(), words.end()), words.end());

    for (size_t i = 0; i < words.size(); i++) {
        cout << words[i] << '\n';
    }

    return 0;
}