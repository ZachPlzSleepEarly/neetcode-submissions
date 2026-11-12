#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
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

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (string s : tokens) {
            if (s == "+") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a + b);
            } else if (s == "-") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a - b);
            } else if (s == "*") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a * b);
            } else if (s == "/") {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                stk.push(a / b);
            } else {
                stk.push(stoi(s));
            }
        }
        return stk.top();
    }
};