#include <iostream>
using namespace std;
#include <string>
#include <stack>
#include <vector>
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(NULL),right(NULL){
	}
	
	static void PreOrder(TreeNode *root){
		if(root == NULL){
			return ;
		}
		cout<<root->val;
		PreOrder(root->left);
		PreOrder(root->right);
	}
	static void InOrder(TreeNode *root){
		if(root == NULL){
			return ;
		}
		InOrder(root->left);
		cout<<root->val;
		InOrder(root->right);
	}
};

class Solution {
	public:
		struct TreeNode* reConstructBinaryTree(vector<int>pre,vector<int>in){
			int length = pre.size();
			int value = pre[0];
			TreeNode *root = new TreeNode(value);
			int rootIndex =  0;
			for (rootIndex=0;rootIndex <length;rootIndex++){
				if(in[rootIndex]==value){
					break;
				}
			}
			if(rootIndex>length){
				return NULL;
			}
			int leftLength = rootIndex;
			int rightLength = length-1- rootIndex;
			vector<int> preLeft(leftLength),inLeft(leftLength);
			vector<int>preRight(rightLength),inRight(rightLength);
			for(int i = 0;i<length;i++){
				if(i<rootIndex){
					preLeft[i]=pre[i+1];
					inRight[i]=in[i+1];
				}
				if(i>rootIndex){
					preRight[i-rootIndex-1]=pre[i];
					inRight[i-rootIndex-1]=in[i];
				}
			}
			
			root->left = reConstructBinaryTree(preLeft,inLeft);
			root->right = reConstructBinaryTree(preRight,inRight);
			return root;
		} 
};
 int main(){
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

    vector<int> preOrder(pre, pre + 8);
    vector<int>  inOrder( in,  in + 8);

    Solution solu;
    TreeNode *root = solu.reConstructBinaryTree(preOrder, inOrder);

    cout <<"PreOrder";
    TreeNode::PreOrder(root);
    cout <<endl;

    cout <<"InOrder ";
    TreeNode::InOrder(root);
    cout <<endl;

    return 0;
}



