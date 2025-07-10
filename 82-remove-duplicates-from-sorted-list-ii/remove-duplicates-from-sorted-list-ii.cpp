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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* t = head;
        while (temp && temp->next) {
            if (temp && temp->next && temp->val == temp->next->val) {
                while (temp && temp->next && temp->val == temp->next->val) {
                    temp->next = temp->next->next;
                }
                if(temp == head){
                    head = head ->next;
                    temp = head;
                    t = head;
                }
                else{
                    t->next = temp->next;
                    temp = temp->next;
                }
            }
            else{
                if(temp!=head) t = t->next;
                temp = temp->next;
            }
        }
        return head;
    }
};