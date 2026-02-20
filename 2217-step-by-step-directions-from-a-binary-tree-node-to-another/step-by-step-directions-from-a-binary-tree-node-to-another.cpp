class Solution {
public:
    // Helper function to find the path from root to a target value
    bool findPath(TreeNode* root, int target, string& path) {
        if (!root) return false;
        if (root->val == target) return true;

        // Try Left
        path.push_back('L');
        if (findPath(root->left, target, path)) return true;
        path.pop_back(); // Backtrack

        // Try Right
        path.push_back('R');
        if (findPath(root->right, target, path)) return true;
        path.pop_back(); // Backtrack

        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        string destPath = "";

        // 1. Get paths from root to both nodes
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        // 2. Find the common prefix length (LCA point)
        int i = 0;
        while (i < startPath.length() && i < destPath.length() && startPath[i] == destPath[i]) {
            i++;
        }

        // 3. Build the final path
        string result = "";
        
        // Everything left in startPath after prefix needs to go 'U'
        for (int j = i; j < startPath.length(); j++) {
            result += 'U';
        }

        // Everything left in destPath after prefix is the downward path
        result += destPath.substr(i);

        return result;
    }
};