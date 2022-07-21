// https://www.acmicpc.net/problem/1085

#include <iostream>

using namespace std;

int main(void) {
    int X, Y, W, H, compare_result_1, compare_result_2;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> X >> Y >> W >> H;

    compare_result_1 = (X < W - X ? X : W - X);
    compare_result_2 = (Y < H - Y ? Y : H - Y);

    cout << (compare_result_1 < compare_result_2 ? compare_result_1 : compare_result_2) << '\n';

    return 0;
}