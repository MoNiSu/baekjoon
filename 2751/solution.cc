// https://www.acmicpc.net/problem/2751

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Swap(vector<int>::iterator a, vector<int>::iterator b) {
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

void Merge(vector<int>::iterator begin, vector<int>::iterator middle, vector<int>::iterator end) {
    size_t size = end - begin;
    int index = 0, min = 0;

    queue<int> first_queue, second_queue;

    for (int i = 0; i < middle - begin; i++) {
        first_queue.push(*(begin + i));
    }

    for (int i = 0; i < end - middle; i++) {
        second_queue.push(*(middle + i));
    }

    while (!first_queue.empty() || !second_queue.empty()) {
        if (first_queue.empty() || (!second_queue.empty() && second_queue.front() < first_queue.front())) {
            *(begin + index++) = second_queue.front();
            second_queue.pop();

            continue;
        }

        *(begin + index++) = first_queue.front();
        first_queue.pop();
    }
}

void MergeSort(vector<int>::iterator begin, vector<int>::iterator end) {
    size_t size = end - begin;

    vector<int>::iterator middle = begin + size / 2;

    if (size < 3) {
        if (size < 2) return;
        if (*begin > *(begin + 1)) Swap(begin, begin + 1);

        return;
    }

    MergeSort(begin, middle);
    MergeSort(middle, end);
    Merge(begin, middle, end);
}

int main(void) {
    int N;

    vector<int> numbers;

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    numbers.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    MergeSort(numbers.begin(), numbers.end());

    for (int i = 0; i < N; i++) {
        cout << numbers[i] << '\n';
    }

    return 0;
}