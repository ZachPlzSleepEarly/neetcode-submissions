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
    stack<int> _s;
    stack<int> _minS;
    
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (_s.empty()) {
            _s.push(val);
            _minS.push(val);
            return;
        }
        
        _s.push(val);
        _minS.push(min(_minS.top(), val));
    }
    
    void pop() {
        _s.pop();
        _minS.pop();
    }
    
    int top() {
        return _s.top();
    }
    
    int getMin() {
        return _minS.top();
    }
};