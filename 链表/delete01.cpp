//直接使用原来的链表来进行移除节点操作：
class Solution {
public:
ListNode*removeElements(ListNode*head,int val) {
    //删除头结点
    while(head!=NULL&&head->val==val){
        //tmp指针指向头结点
        ListNode *tmp = head;
        //头结点往后面移动一位
        head = head->next;
        //删除原来头结点的内存空间
        delete tmp;
    }
    //删除非头结点
    //cur指针指向头结点
    ListNode *cur = head;
    //头结点不为空以及头结点的后一个节点也不为空
    while(cur!=NULL&&cur->next!=NULL) {
        //查找到了元素
        if(cur->next->val==val) {
            //头结点的指针域指向tmp指针
            ListNode *tmp = cur->next;
            //让节点next指针直接指向下下个节点
            cur->next = cur->next->next;
            //删除tmp指针
            delete tmp;
        } else {
            //不进行删除 继续往后面遍历
            cur = cur->next;
        }
    }
    return head;
}
};
