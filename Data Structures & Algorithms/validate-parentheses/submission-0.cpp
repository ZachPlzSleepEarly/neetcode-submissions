#include <fstream>
#include <iostream>
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
static const int fastIO = []
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (c == ')') {
                    if (stk.top() != '(') {
                        return false;
                    }
                    stk.pop();
                } else if (c == ']') {
                    if (stk.top() != '[') {
                        return false;
                    }
                    stk.pop();
                } else {
                    if (stk.top() != '{') {
                        return false;
                    }
                    stk.pop();
                }
            }
        }
        return stk.empty();
    }
};