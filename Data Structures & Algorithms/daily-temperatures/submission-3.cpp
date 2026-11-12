#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define B begin
#define E end
#define T temperatures

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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> stk;
        vector<int> r(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            if (stk.empty()) {
                stk.push(MP(T[i], i));
            }
            if (T[i] < stk.top().F) {
                stk.push(MP(T[i], i));
            } else {
                while (!stk.empty() && T[i] > stk.top().F) {
                    int j = stk.top().S;
                    stk.pop();
                    r[j] = i - j;
                }
                stk.push(MP(T[i], i));
            }
        }
        return r;
    }
};