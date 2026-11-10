#define F first
#define S second
#define MP make_pair
#define PB push_back

#include <vector>
#include <string>

typedef long long ll;

using namespace std;

class Solution {
public:
    string encode(vector<string>& strs)
    {
        string r;
        for (const auto& str: strs) {
            int len = str.length();
            r += to_string(len) + "#" + str;
        }
        return r;
    }

    vector<string> decode(string s)
    {
        vector<string> ret;
        size_t l = 0;
        size_t r = s.find('#');
        while (r != string::npos && r < s.length()) {
            int n = stoi(s.substr(l, r - l));
            ret.PB(s.substr(r + 1, n));
            l = r + n + 1;
            r = s.find('#', l);
        }
        return ret;
    }
};