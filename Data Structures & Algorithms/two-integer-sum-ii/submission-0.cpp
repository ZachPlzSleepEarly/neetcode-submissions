#include <fstream>
#include <iostream>
#include <vector>
#define F first
#define S second
#define MP make_pair
#define PB push_back

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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> ret;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) {
                ret.PB(l + 1);
                ret.PB(r + 1);
                break;
            }
            if (sum < target) {
                l++;
            }
            if (sum > target) {
                r--;
            }
        }
        return ret;
    }
};