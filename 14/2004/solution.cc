// https://www.acmicpc.net/problem/2004

#include <iostream>

using namespace std;

int main(void) {
    bool should_add = false;
    int n, m, divisor, temp, two_number = 0, five_number = 0, zero_number;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m;

    if (n == m || m == 0) {
        cout << 0 << '\n';

        return 0;
    }

    for (int i = 0; i < 2; i++) {
        switch (i) {
        case 0:
            divisor = 2;

            break;
        case 1:
            divisor = 5;

            break;
        }

        for (int j = 0; j < 3; j++) {
            switch (j) {
            case 0:
                temp = n;
                should_add = true;
                
                break;
            case 1:
                temp = m;
                should_add = false;
                
                break;
            case 2:
                temp = n - m;
                should_add = false;
                
                break;
            }

            while (temp >= divisor) {
                temp /= divisor;

                switch (divisor) {
                case 2:
                    if (should_add) two_number += temp;
                    else two_number -= temp;

                    break;
                case 5:
                    if (should_add) five_number += temp;
                    else five_number -= temp;

                    break;
                }
            }
        }
    }

    zero_number = (two_number < five_number ? two_number : five_number);
    zero_number = (zero_number < 0 ? 0 : zero_number);

    cout << zero_number << '\n';

    return 0;
}