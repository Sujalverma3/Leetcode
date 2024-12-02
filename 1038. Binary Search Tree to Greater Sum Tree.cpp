/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), , right(right) {}
 * }
 *//**
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

               int sum = 0;
                   TreeNode* bstToGst(TreeNode* root) {
                           trav(root);
                                   makegst(root,0);
                                           return root;
                                               }

                                                   void trav(TreeNode* root){
                                                           if(root == nullptr)return;
                                                                   trav(root->left);
                                                                           sum += root->val;
                                                                                   trav(root->right);
                                                                                       }

                                                                                           int makegst(TreeNode* root, int give){
                                                                                                   if(root == nullptr)return 0;
                                                                                                           int left = makegst(root->left,give);
                                                                                                                   int right = makegst(root->right,give+root->val+left);
                                                                                                                           int ret = root->val + left + right;
                                                                                                                                   root->val = sum - left - give;
                                                                                                                                           return ret;
                                                                                                                                               }
                                                                                                                                               };



