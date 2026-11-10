class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> M1;
        // iterate string 1
        for (auto c : s) {
            M1[c]++;
        }

        unordered_map<char, int> M2;
        for (auto c : t) {
            M2[c]++;
        }
        
        return M1 == M2;
    }
};