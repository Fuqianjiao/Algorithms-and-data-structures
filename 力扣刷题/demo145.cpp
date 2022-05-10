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
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        //建立一个栈和数组
        stack<TreeNode *> st;
        vector<int> result;
        //判断是否合法
        if(root==NULL)
            return result;
            //根结点入栈
        st.push(root);
        while(!st.empty()) {
            //建立一个头结点
            TreeNode *node = st.top();
            //弹栈
            st.pop();
            //存入数组中
            result.push_back(node->val);
            if(node->left)
                st.push(node->left);
                if(node->right)
                    st.push(node->right);
        }
        //将结果的中右左反转为左右中
        reverse(result.begin(), result.end());
        return result;
    }
};
