
class Solution {
public:
    int getHeight(TreeNode* root) {
        if(root == NULL ) {
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int maxHeight = max(left, right);
        int totalHeight = maxHeight + 1;
        return totalHeight;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = getHeight(root->left) + getHeight(root->right);
        int maxDiameter = max(option1, max(option2, option3));
        return maxDiameter;
    }
};



class Solution {
public:
    int maxDepth(TreeNode* root) {
        //base case
        if(root == NULL) {
            return 0;
        }
        int leftSubtreeHeight = maxDepth(root->left);
        int rightSubtreeHeight = maxDepth(root->right);
        int maxHeight = max(leftSubtreeHeight, rightSubtreeHeight);
        int totalHeight = maxHeight + 1;
        return totalHeight;
    }
};