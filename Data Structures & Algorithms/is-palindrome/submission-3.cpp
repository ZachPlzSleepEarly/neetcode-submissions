#include <fstream>
#include <iostream>
#include <string>
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
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.length() - 1;
        while (l <= r) {
            while (l < s.length() && !isAlphNum(s[l])) {
                l++;
            }
            while (r >= 0 && !isAlphNum(s[r])) {
                r--;
            }
            if (l > r) {
                break;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }
        return true;
    }

private:
    bool isAlphNum(char c)
    {
        return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
    }
};