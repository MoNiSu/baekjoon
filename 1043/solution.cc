// https://www.acmicpc.net/problem/1043

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main(void) {
    bool party_truth;
    int N, M, people_number, person;

    vector<bool> people;
    vector<set<int>> party;
    queue<int> truth_known_people;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    people.resize(N);
    party.resize(M);

    cin >> people_number;

    for (int i = 0; i < people_number; i++) {
        cin >> person;

        people[person - 1] = true;
        truth_known_people.push(person);
    }

    for (int i = 0; i < M; i++) {
        cin >> people_number;

        for (int j = 0; j < people_number; j++) {
            cin >> person;

            party[i].insert(person);
        }
    }

    for (int i = 0; i < truth_known_people.size(); i++) {
        for (int j = 0; j < party.size(); j++) {
            party_truth = false;

            for (auto it = party[j].begin(); it != party[j].end(); it++) {
                if (*it == truth_known_people.front()) {
                    party_truth = true;

                    break;
                }
            }


            if (party_truth) {
                for (auto it = party[j].begin(); it != party[j].end(); it++) {
                    if (people[*it - 1]) continue;

                    people[*it - 1] = true;
                    truth_known_people.push(*it);
                }

                party.erase(party.begin() + j--);
            }
        }

        truth_known_people.pop();
        i--;
    }

    cout << party.size() << '\n';

    return 0;
}