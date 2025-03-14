//解题思路：https://leetcode.cn/problems/binary-tree-right-side-view/solutions/2015061/ru-he-ling-huo-yun-yong-di-gui-lai-kan-s-r1nc
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        auto dfs=[&](this auto&& dfs,TreeNode* node,int depth)->void
        {
            if(!node) return;
            if(depth==res.size())
            {
                res.emplace_back(node->val);
            } 
            dfs(node->right,depth+1);
            dfs(node->left,depth+1);
        };
        dfs(root,0);
        return res;

    }
};
