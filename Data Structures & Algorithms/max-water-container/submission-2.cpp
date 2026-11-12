#include <fstream>
#include <iostream>
#include <vector>
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
    int maxArea(vector<int>& heights) {
        int l = 0;
        int lb = INT_MIN;
        int rb = INT_MIN;
        int v = 0;
        while (l < heights.size() - 1) {
            int r = l + 1;
            bool isSet = false;
            int nI = INT_MIN;
            while (r < heights.size()) {
                // exploration
                if (!isSet && heights[r] > heights[l]) {
                    isSet = true;
                    nI = r;
                }
                
                if (heights[r] >= lb || heights[r] >= rb) {
                    int cV = min(heights[l], heights[r]) * (r - l);
                    if (cV > v) {
                        v = cV;
                        lb = l;
                        rb = r;
                    }
                }
                
                r++;
            }
            if (nI == INT_MIN) {
                break;
            }
            l = nI;
        }
        return v;
    }
};