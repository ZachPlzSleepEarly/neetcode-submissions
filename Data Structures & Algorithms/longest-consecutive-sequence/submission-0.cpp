#define F first
#define S second
#define MP make_pair
#define PB push_back

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
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.empty()) {
            return 0;
        }
        
        unordered_set<int> s;
        for (int i : nums) {
            s.insert(i);
        }
        int ml = 1;//max len

        for (int i : nums) {
            if (!s.contains(i - 1)) {
                int n = 1;//nums of right neighbors
                while (s.contains(i + 1)) {
                    n++;
                    i++;
                }
                ml = max(ml, n);
            }
        }
        return ml;
    }
};