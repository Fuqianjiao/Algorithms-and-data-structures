//设置一个虚拟的节点在进行移除节点的操作
class Solution {
public:
ListNode*removeElements(ListNode*head,int val) {
    //设置一个虚拟的头结点
    ListNode *dummyHead = new ListNode(0);
    //将虚拟的头结点指向head
    dummyHead->next = head;
    //cur指针指向虚拟的结点
    ListNode *cur = dummyHead;
    //判断cur指针是否为空
    while(cur->next!=NULL) {
        //判断元素是否相等
        if(cur->next->val==val) {
            //tmp指针指向删除元素的指针域
            ListNode *tmp = cur->next;
            //头结点的指针域指向尾结点的指针域
            cur->next = cur->next->next;
            //删除中间的元素
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
