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
    vector<double> averageOfLevels(TreeNode* root) {
        //建立一个队列
        queue<TreeNode *> que;
        //建立一个存放答案集合的数组
        vector<double> result;
        //判断是否合法
        if(root!=NULL) que.push(root);
        //单层遍历的步骤
        while(!que.empty()) {
            //确立队列的大小
            int size = que.size();
            //统计每一层的和
            double sum = 0;
            //循环
            for (int i = 0; i < size;i++) {
                //确立树的头结点
                TreeNode *node = que.front();
                //队列出队
                que.pop();
                //用一个指针存放每一层元素的和
                sum += node->val;
                //遍历左孩子
                if(node->left) que.push(node->left);
                //遍历右孩子
                if(node->right) que.push(node->right);
            }
            //将每一层的均值放入结果值中
            result.push_back(sum / size);
        }
         return result;
        
    }
};
