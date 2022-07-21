// https://www.acmicpc.net/problem/1259

#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(string N) {
    for (int i = 0; i < N.size() / 2; i++) {
        if (N[i] != N[(N.size() - 1) - i]) {
            return false;
        }
    }

    return true;
}

int main(void) {
    string N;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while (true) {
        cin >> N;

        if (N == "0") break;

        cout << (IsPalindrome(N) ? "yes" : "no") << '\n';
    }

    return 0;
}