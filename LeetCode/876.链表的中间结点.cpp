/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int all=0;
        ListNode * h=head;
        while(head->next!=nullptr)
        {
            all++;
            head=head->next;
        }
        int half=all/2;
        while(half--)
        {
            h=h->next;
        }
        if(all%2==1)
            h=h->next;
        return h;
    }
};
// @lc code=end

