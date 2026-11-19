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

typedef long long ll;

using namespace std;

// Leetcode
static const int fastIO = [] {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    static bool customSort(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.F > b.F;
    }
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        if (position.size() == 1) {
            return 1;
        }

        vector<pair<int, int>> p;
        for (int i = 0; i < position.size(); ++i) {
            p.PB(MP(position[i], speed[i]));
        }
        sort(p.begin(), p.end(), Solution::customSort);
        stack<float> s;
        s.push((target - p[0].F) / static_cast<float>(p[0].S));

        for (int i = 1; i < p.size(); ++i) {
            float t = (target - p[i].F) / static_cast<float>(p[i].S);
            if (s.empty()) {
                s.push(t);
                continue;
            }

            if (t > s.top()) {
                s.push(t);
            }
        }

        return s.size();
    }
};