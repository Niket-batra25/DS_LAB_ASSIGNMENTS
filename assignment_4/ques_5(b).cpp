#include <iostream>
#include <queue>
using namespace std;
class StackOneQ {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front()); q.pop();
        }
    }

    void pop() {
        if (q.empty()) { cout << "Stack Empty\n"; return; }
        q.pop();
    }

    int top() {
        if (q.empty()) { cout << "Stack Empty\n"; return -1; }
        return q.front();
    }

    bool empty() { return q.empty(); }
};
