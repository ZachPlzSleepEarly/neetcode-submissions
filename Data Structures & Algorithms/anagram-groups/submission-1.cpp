class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        // create unordered_map<vector<int>, vector<string>>
        unordered_map<string, vector<string>> m;

        // loop through the Input
        for (auto s : strs) {
            // count
            vector<int> v(26, 0);
            for (auto c : s) {
                v[c - 'a']++;
            }
            // construct string
            string k = to_string(v[0]);
            for (int i = 1; i < 26; ++i) {
                k += "," + to_string(v[i]);
            }
            // place the key-value pair at the end of the map
            m[k].push_back(s);
        }

        // extract value from the map in terms of vector of strings.
        vector<vector<string>> ret;
        for (const auto& pair : m) {
            ret.push_back(pair.second);
        }
        return ret;
    }
};