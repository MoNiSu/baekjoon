// https://www.acmicpc.net/problem/2606

#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// BFS function
int BFS(unordered_map<int, set<int>>& um) {
    vector<int> infected = { 1 }; // Infection starts.

    // As this loop goes on, the size of the vector increases.
    for (int i = 0; i < infected.size(); ++i) {

        // Explore nearby computers.
        for (auto jt = um[infected[i]].begin(); jt != um[infected[i]].end(); ++jt) {
            auto find_it = find(infected.begin(), infected.end(), *jt);

            if (find_it != infected.end()) {
                continue; // Skip if visited.
            }

            // This increases size of the vector.
            infected.push_back(*jt);
        }
    }

    // Returns the size of a vector (number of computers) except one (1).
    return infected.size() - 1;
}
 
int main(void) {
    // N = Number of computers, P = Pair of connected computers
    // A = Computer A, B = Computer B
    int N, P, A, B;

    unordered_map<int, set<int>> um; // Store A, B.

    cin >> N >> P;

    for (int i = 0; i < P; ++i) {
        cin >> A >> B;

        um[A].insert(B);
        um[B].insert(A);
    }

    cout << BFS(um);

    return 0;
}
