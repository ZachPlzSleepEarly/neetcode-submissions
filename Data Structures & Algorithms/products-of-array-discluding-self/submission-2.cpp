#define F first
#define S second
#define MP make_pair
#define PB push_back

#include <vector>

typedef long long ll;

using namespace std;

static const int fastIO = [] {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n0 = 0;
        int mAll = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (n0 > 1) {
                break;
            }
            if (nums[i] == 0) {
                mAll = 0;
                n0++;
            } else {
                mAll *= nums[i];
            }
        }

        vector<int> r;
        if (n0 > 1) {
            for (int i = 0; i < nums.size(); ++i) {
                r.PB(0);
            }
            return r;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (n0 == 0) {
                r.PB(mAll / nums[i]);
            } else {
                if (nums[i] != 0) {
                    r.PB(0);
                } else {
                    int mAllLeft = 1;
                    for (int j = 0; j < i; ++j) {
                        mAllLeft *= nums[j];
                    }
                    int mAllRight = 1;
                    for (int j = i + 1; j < nums.size(); ++j) {
                       mAllRight *= nums[j];
                    }
                    r.PB(mAllLeft * mAllRight);
                }
            }
        }
        return r;
    }
};