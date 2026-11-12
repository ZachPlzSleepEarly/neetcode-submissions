#include <fstream>
#include <iostream>
#include <vector>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define B begin
#define E end
#define H height

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
    int trap(vector<int>& height) {
        if (H.size() <= 2) {
            return 0;
        }
        int l = 0;
        int r = H.size() - 1;
        int mL = H[l];
        int mR = H[r];
        int v = 0;
        while (l < r) {
            if (mL <= mR) {
                l++;
                int tV = min(mL, mR) - H[l];
                v += max(0, tV);
                mL = max(mL, H[l]);
            } else {
                r--;
                int tV = min(mL, mR) - H[r];
                v += max(0, tV);
                mR = max(mR, H[r]);
            }

            // todo update l,r properly
            // todo update mL,mR properly
        }
        return v;
    }
};