//直接使用原结点进行删除
class Solution {
public:
ListNode*removeElements(ListNode*head,int val) {
    //删除头结点
    //判断头结点是否为空 头结点的元素是否相等
    while(head!=NULL&&head->val==val) {
        //tem指针指向头结点
        ListNode *tmp = head;
        //将头结点往后面移一位
        head = head->next;
        //删除头结点
        delete tmp;
    }
    
    //删除非头结点
    //cur指针指向头结点
    ListNode *cur = head;
    //判断头结点是否为空 后一个元素指针域是否为空
    while(cur!=NULL&&cur->next!=NULL) {
        //判断元素的值是否相等
        if(cur->next->val==val) {
            //tmp的指针指向元素的指针域
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        }
    } else {
        cur = cur->next;
    }
    return head;
}
};
