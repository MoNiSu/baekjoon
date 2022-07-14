// https://www.acmicpc.net/problem/10757

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    bool carry = false;

    int number;

    string A, B, temp;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> A >> B;

    if (B.size() > A.size()) {
        temp = A;
        A = B;
        B = temp;

        temp.clear();
    }

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    for (int i = 0; i < B.size(); i++) {
        number = (A[i] - '0') + (B[i] - '0');

        if (carry) {
            number++;

            carry = false;
        }

        if (number > 9) {
            number -= 10;

            carry = true;
        }

        A[i] = (char)(number + '0');
    }

    for (int i = B.size(); i < A.size(); i++) {
        if (!carry) break;

        number = (A[i] - '0') + 1;

        carry = false;

        if (number > 9) {
            number -= 10;

            carry = true;
        }

        A[i] = (char)(number + '0');
    }

    if (carry) A.push_back('1');

    reverse(A.begin(), A.end());

    cout << A << '\n';

    return 0;
}