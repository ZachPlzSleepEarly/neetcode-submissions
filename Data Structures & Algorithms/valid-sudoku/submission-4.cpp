static const int fastIO = [] {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9] = {0}, col[9] = {0}, box[9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                int bit = 1 << (c - '1');          // '1'→第0位, ..., '9'→第8位
                int b = (i / 3) * 3 + j / 3;       // 第几个 box (0~8)

                if ((row[i] | col[j] | box[b]) & bit) return false;

                row[i] |= bit;
                col[j] |= bit;
                box[b] |= bit;
            }
        }
        return true;
    }
};