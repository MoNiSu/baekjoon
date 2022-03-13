// https://www.acmicpc.net/problem/1260

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// DFS function
void DFS(int V, unordered_map<int, set<int>>& m, vector<int>& visited) {
    visited.push_back(V);

    for (auto it = m[V].begin(); it != m[V].end(); ++it) {
        auto find_it = find(visited.begin(), visited.end(), *it);

        if (find_it != visited.end()) {
            continue; // Skip if visited
        }

        DFS(*it, m, visited);
    }
}

// BFS function
void BFS(int V, unordered_map<int, set<int>>& m, vector<int>& visited) {
    int i = 0;

    visited.push_back(V);

    do {
        for (auto it = m[V].begin(); it != m[V].end(); ++it) {
            auto find_it = find(visited.begin(), visited.end(), *it);

            if (find_it != visited.end()) {
                continue; // Skip if visited
            }

            visited.push_back(*it);
        }

        if (++i + 1 > visited.size()) {
            break; // Exit if no more
        }

        V = visited[i];
    } while (visited.size() < m.size());
}

// Print answer
void print(vector<int>& answer) {
    for (int i = 0; i < answer.size(); ++i) {
        if (i > 0) {
            cout << " ";
        }

        cout << answer[i];
    }

    cout << endl;
}
 
int main(void) {
    int N, M, V, P, C; // P = point, C = connected point

    unordered_map<int, set<int>> m; // Store P, C
    vector<int> answer;

    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i) {
        cin >> P >> C;

        m[P].insert(C);
        m[C].insert(P);
    }

    DFS(V, m, answer);
    print(answer);

    answer.clear();

    BFS(V, m, answer);
    print(answer);

    return 0;
}
