// /**** Leetcode ****/
#include <fstream>
#include <iostream>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define B begin
#define E end
#define N next

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
    void reorderList(ListNode* head)
    {
        // find the second half
        auto s = head;
        auto f = head->N;
        while (f != nullptr && f->N != nullptr) {
            s = s->N;
            f = f->N->N;
        }
        // safe the second half pointer
        auto second = s->N;
        // the end of the first half point to null
        s->N = nullptr;

        // reverse right half
        ListNode* prev = nullptr;
        while (second) {
            auto tr = second->N;
            second->N = prev;
            prev = second;
            second = tr;
        }
        // take the head of the right half
        second = prev;  // the head of the reversed right half linked list

        // merge
        while (second) {
            // save the next info
            auto t1 = head->N;
            auto t2 = second->N;
            head->N = second;
            second->N = t1;

            head = t1;
            second = t2;
        }
    }
};
