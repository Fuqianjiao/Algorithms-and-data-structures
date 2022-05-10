/**
 * Definition for a binary tree node.
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
    vector<int> preorderTraversal(TreeNode* root) {
        //建立一个栈
        stack<TreeNode *> st;
        //建立一个数组
        vector<int>result;
        //判断是否合法
        if(root==NULL)
            return result;
            //根结点入栈
        st.push(root);
        //循环
        while(!st.empty()) {
            //建立一个头节点
            TreeNode *node = st.top();
            //弹栈
            st.pop();
            //把中节点的值传入数组
            result.push_back(node->val);
            if(node->right)
                st.push(node->right);
                if(node->left)
                    st.push(node->left);
        }
        return result;
    }
};
