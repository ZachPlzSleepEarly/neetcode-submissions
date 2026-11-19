#include <fstream>
#include <iostream>
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
public:
    bool hasCycle(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        
        auto s = head;
        auto f = head->next;
        
        while (f != nullptr && f->next != nullptr) {
            if (f == s) {
                return true;
            }
            s = s->next;
            f = f->next->next;
        }
        
        return false;
    }
};
