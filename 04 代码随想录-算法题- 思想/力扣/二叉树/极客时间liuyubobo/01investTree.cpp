
/**
 * @file 01investTree.cpp 
 * @brief: 
 * @version: v0.0.1 
 * @copyright: Rocky.houjinSong
 * @author: Rocky.houjinSong
 * @date: 2023-12-20 20:46:58
 * -------------------------------------------------------------
 * @Update更新:
 * @Remark备注:考察 递归的思想
 **/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
	//TreeNode(int x,TreeNode* left,TreeNode* right):val(x),left(left),right(right) {}
};
class Solution{
public:
	TreeNode* invertTree(TreeNode* root)
	{
		if(root == nullptr)
			return nullptr;
		TreeNode* tmpNode = root->left;
		root->left= invertTree(root->right);
		root->right = invertTree(tmpNode);
		return root;
		
	}
	
};
