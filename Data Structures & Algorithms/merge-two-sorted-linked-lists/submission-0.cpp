// /**** Leetcode ****/
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode dummy;
        ListNode* n = &dummy;
        
        while (list1 && list2) {
            if (list1->val < list2->val) {
                n->next = list1;
                list1 = list1->next;
            } else {
                n->next = list2;
                list2 = list2->next;
            }
            n = n->next;
        }
        
        while (list1) {
            n->next = list1;
            list1 = list1->next;
            n = n->next;
        }
        while (list2) {
            n->next = list2;
            list2 = list2->next;
            n = n->next;
        }
        
        return dummy.next;
    }
};

