// https://www.acmicpc.net/problem/1018

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int N, M, min, bw_count, wb_count;
    const int board_size = 8;

    string line;

    vector<vector<bool>> board, bw_board, wb_board;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    min = N * M;
    board.resize(N);
    bw_board.resize(board_size);
    wb_board.resize(board_size);

    for (int i = 0; i < N; i++) {
        cin >> line;

        if (i < board_size) {
            bw_board[i].resize(board_size);
            wb_board[i].resize(board_size);
        }

        board[i].resize(M);

        for (int j = 0; j < M; j++) {
            board[i][j] = (line[j] == 'W' ? true : false);

            if (i < board_size && j < board_size) {
                if (i % 2) {
                    if (j % 2) {
                        bw_board[i][j] = false;
                        wb_board[i][j] = true;
                    } else {
                        bw_board[i][j] = true;
                        wb_board[i][j] = false;
                    }
                } else {
                    if (j % 2) {
                        bw_board[i][j] = true;
                        wb_board[i][j] = false;
                    } else {
                        bw_board[i][j] = false;
                        wb_board[i][j] = true;
                    }
                }
            }
        }
    }

    for (int i = 0; i < N - (board_size - 1); i++) {
        for (int j = 0; j < M - (board_size - 1); j++) {
            bw_count = 0;
            wb_count = 0;

            for (int x = 0; x < board_size; x++) {
                for (int y = 0; y < board_size; y++) {
                    if (board[i + x][j + y] != bw_board[x][y]) bw_count++;
                    if (board[i + x][j + y] != wb_board[x][y]) wb_count++;
                }
            }

            min = (bw_count < min ? bw_count : min);
            min = (wb_count < min ? wb_count : min);
        }
    }

    cout << min << '\n';

    return 0;
}