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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*不需要单独处理这种情况
        if (l1 == nullptr && l2 == nullptr){
            return nullptr;
        }
        */

        /* 多出结构体指针的空间，以及给指针赋值的时间
        if (l1 == nullptr){
            return l2;
        }
        if (l2 == nullptr){
            return l1;
        }
        ListNode* retNodePtr = nullptr;
        if (l1->val < l2->val){
            retNodePtr = l1;
            retNodePtr->next = mergeTwoLists(l1->next, l2);
        }else{
            retNodePtr = l2;
            retNodePtr->next = mergeTwoLists(l1, l2->next);
        }
        return retNodePtr;
        */


        if (l1 == nullptr){
            return l2;
        }
        if (l2 == nullptr){
            return l1;
        }
        if (l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};