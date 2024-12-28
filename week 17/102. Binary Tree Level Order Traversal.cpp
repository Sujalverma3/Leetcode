// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */

// class Solution {
// public:
//     void solve(vector<vector<int>>& ans, TreeNode* temp, int level) {
//         if (temp == NULL) return;  // Base case: Null node
//         if (ans.size() <= level) ans.push_back({}); // Add a new level if needed
//         ans[level].push_back(temp->val);           // Add the current node's value
//         solve(ans, temp->left, level + 1);         // Recur for left subtree
//         solve(ans, temp->right, level + 1);        // Recur for right subtree
//     }

//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         solve(ans, root, 0);  // Start recursion with level 0
//         return ans;
//     }
// };
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode *node=q.front();
                q.pop();
                if(node->left!=NULL) q.push(node->left);
                if(node->right!=NULL) q.push(node->right);
                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};