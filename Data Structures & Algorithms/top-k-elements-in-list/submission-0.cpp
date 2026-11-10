#define F first
#define S second
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto i : nums) {
            m[i]++;
        }
        vector<pair<int, int>> vp(m.begin(), m.end());
        sort(vp.begin(), vp.end(), Solution::customSort);

        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.PB(vp[i].F);
        }
        return ret;
    }

private:
    static bool customSort(const pair<int, int>& p1, const pair<int, int>& p2)
    {
        return p1.S > p2.S;
    }
};