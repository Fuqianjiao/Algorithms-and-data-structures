/**
 * Definition for a binary tree node
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //首先定义一个数组存放处理的元素
        vector<int> result;
        //定义一个栈访问元素
        stack<TreeNode *> st;
        //定义一个指针 来解决访问和处理顺序不同
        TreeNode *cur = root;
        while(cur!=NULL||!st.empty()) {
            if(cur!=NULL) {
                st.push(cur);//将访问的节点入栈里面
                cur = cur->left;//左
            }else{
                cur = st.top();//弹出的节点
                st.pop();//做弹出的操作
                result.push_back(cur->val);//中
                cur = cur->right;//右
            }
        }
        return result;
    }
};
