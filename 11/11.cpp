#include <iostream>
using namespace std;
struct TreeNode{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
void swap(TreeNode *left,TreeNode *right){
	TreeNode *temp;
	temp=left;
	left=right;
	right= temp;
}
class Solution{
	public:
		void Mirror(TreeNode *pRoot){
			if(pRoot==NULL){
				return;
			}
			swap(pRoot->left,pRoot->right);
			Mirror(pRoot->left);
			Mirrot(pRoot->right);
		}
};
/*递归实现 树的镜像生成 */ 

