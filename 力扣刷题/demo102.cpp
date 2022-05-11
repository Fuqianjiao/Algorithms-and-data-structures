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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //建立一个队列
        queue<TreeNode *> que;
        //判断是否合法
        if(root!=NULL)que.push(root);
        //定义一个二维数组
        vector<vector<int>> result;
        //单层遍历的执行
        while(!que.empty()) {
            //定义队列的大小
            int size = que.size();
            //定义一个数组
            vector<int> vec;
            //循环
            for (int i = 0; i < size;i++) {
                //建立一个头结点
                TreeNode *node = que.front();
                //出栈
                que.pop();
                //把值放进数组集里面
                vec.push_back(node->val);
                //处理左孩子和右孩子
                if(node->left) que.push(node->left);
                if(node->right)que.push(node->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
