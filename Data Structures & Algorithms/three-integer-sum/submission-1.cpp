#include <fstream>
#include <iostream>
#include <vector>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define B begin
#define E end

#define N nums

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
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ret;
        sort(N.B(), N.E());
        for (int l = 0; l < N.size() - 2; ++l) {
            if (l != 0 && N[l - 1] == N[l]) {
                continue;
            }
            int m = l + 1;
            int r = N.size() - 1;
            while (m < r) {
                int s = N[l] + N[m] + N[r];
                if (s == 0) {
                    ret.PB({N[l], N[m], N[r]});
                    int pre = N[m];
                    while (++m < N.size() - 2 && pre == N[m]);
                    pre = N[r];
                    while (--r >= l && pre == N[r]);
                } else if (s < 0) {
                    m++;
                } else {
                    r--;
                }
            }
        }
        return ret;
    }
};