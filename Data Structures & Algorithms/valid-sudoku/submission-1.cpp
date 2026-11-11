#include <iostream>
#include <unordered_set>

#define F first
#define S second
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;

static const int fastIO = [] {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();


class Solution {
public:
    bool isDuplicate(const vector<char> &f, unordered_set<char> &s, int i)
    {
        if (f[i] == '.') {
            return false;
        }
        if (s.find(f[i]) == s.end()) {
            s.insert(f[i]);
        } else {
            return true;
        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        vector<char> f;
        // flatter 2d to 1d array
        for (const auto & v : board) {
            for (char c : v) {
                f.PB(c);
            }
        }

        unordered_set<char> s;

        // check rows
        int i = 0;
        while (i < f.size()) {
            if (i % 9 == 0) {
                s.clear();
            }
            bool value;
            if (isDuplicate(f, s, i)) {
                return false;
            }

            ++i;
        }

        // check cols
        i = 0;
        while (i <= 8) {
            s.clear();
            int k = 0;
            while (k <= 8) {
                int idx = i + 9 * k;
                if (isDuplicate(f, s, idx)) {
                    return false;
                }

                ++k;
            }

            ++i;
        }

        // check 3x3 boxes
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                s.clear();
                int start = 27 * r + 3 * c;   // box 左上角的 index
                for (int n = 0; n < 3; ++n) {
                    for (int m = 0; m < 3; ++m) {
                        int idx = start + 9 * n + m;
                        if (isDuplicate(f, s, idx)) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};