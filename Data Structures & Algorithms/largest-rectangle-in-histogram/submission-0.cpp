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
#define H heights

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
    int largestRectangleArea(vector<int>& heights)
    {
        // create a stack s, pair(h,idx)
        stack<pair<int, int>> s;
        // creat an A
        int a = 0;

        // iterate i: 0->size()-1
        for (int i = 0; i < heights.size(); ++i) {
            // if s.empty(): push pair(h[i],i)
            if (s.empty()) {
                s.push(MP(H[i], i));
                continue;
            }
            // else: cmp h[i] with top().F
            // ==: continue;
            int th = s.top().F;
            int ti = s.top().S;
            if (H[i] == th) {
                continue;
            }
            // >: push pair(h[i],i) | continue;
            if (H[i] > th) {
                s.push(MP(H[i], i));
                continue;
            }
            // start = i
            int start = i;
            // cmp h[i] w/ top().F: while loop(!s.empty())
            while (!s.empty()) {
                th = s.top().F;
                ti = s.top().S;
                // if (h[i]>=top().F): break;
                if (H[i] >= th) {
                    break;
                }
                // # h[i] < top().F: tH,ti = top() | pop() | a = max(a, th * (i - ti)) | start = ti
                s.pop();
                a = max(a, th * (i - ti));
                start = ti;
            }
            // push pair(h[i],start)
            s.push(MP(H[i], start));
        }

        // r = size()
        int r = heights.size();
        // while (!s.empty())
        while (!s.empty()) {
            // h,i = top() | pop()
            int h = s.top().F;
            int i = s.top().S;
            s.pop();
            // a = max(a, h * (r - i))
            a = max(a, h * (r - i));
        }
        // return a
        return a;
    }
};
