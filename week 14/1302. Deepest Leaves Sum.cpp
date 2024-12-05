// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
//  * right(right) {}
//  * };
//  */
// class Solution {
// public:
//     // Function to calculate the height of the tree
//     int height(TreeNode* root) {
//         if (root == NULL) {
//             return 0;
//         } else {
//             int lHeight = height(root->left);
//             int rHeight = height(root->right);
//             return 1 + std::max(lHeight, rHeight);  // Return the maximum height
//         }
//     }

//     // Function to calculate the sum of nodes at a specific level
//     int Sum(TreeNode* root, int level) {
//         if (root == NULL) {
//             return 0;
//         }

//         if (level == 1) {
//             return root->val;  // Return the value at the current level
//         }
        
//         // Recursively sum the left and right subtrees at the next level
//         return Sum(root->left, level - 1) + Sum(root->right, level - 1);
//     }

//     // Function to calculate the sum of deepest leaves
//     int deepestLeavesSum(TreeNode* root) {
//         int h = height(root);  // Get the height of the tree
//         return Sum(root, h);    // Calculate the sum at the deepest level
//     }
// };

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
    void dfs(TreeNode* root,int &sum,int currh, int &h )
    {
        if(!root)
            return;
        if(currh==h)
        {
            sum+=root->val;
        }
        else if(currh>h)
        {
            sum=root->val;
            h=currh;
        }
        dfs(root->left,sum,currh+1,h);
        dfs(root->right,sum,currh+1,h);
    }
    int deepestLeavesSum(TreeNode* root) {
        int sum=0,h=0;
        dfs(root,sum,1,h);
        return sum;
    }
};