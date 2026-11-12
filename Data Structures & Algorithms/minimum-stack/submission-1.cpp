#include <fstream>
#include <iostream>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define B begin
#define E end

typedef long long ll;

using namespace std;

// Leetcode
static const int fastIO = [] {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class MinStack {
private:
    stack<pair<int, int>> _s;

public:
    MinStack() {

    }

    void push(int val) {
        if (_s.empty()) {
            _s.push(MP(val, val));
            return;
        }

        _s.push(MP(val, min(val,_s.top().S)));
    }

    void pop() {
        _s.pop();
    }

    int top() {
        return _s.top().F;
    }

    int getMin() {
        return _s.top().S;
    }
};