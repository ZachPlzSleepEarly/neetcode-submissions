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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* l = nullptr;
        ListNode* m = head;
        
        if (m == nullptr || m->next == nullptr) {
            return head;
        }
        
        while (m != nullptr) {
            ListNode* r = m->next;
            m->next = l;
            l = m;
            m = r;
        }
        
        return l;
    }
};