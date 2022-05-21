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
    ListNode* removeElements(ListNode* head, int val) {
        //设置一个虚拟的头结点
        ListNode *dummyHead = new ListNode(0);
        //将虚拟的头结点指向head,这样后面做删除操作
        dummyHead->next = head;
        //cur指针指向头结点
        ListNode*cur = dummyHead;
        while(cur->next!=NULL) {
            if(cur->next->val==val) {
                //tmp指针指向要删除的元素
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
