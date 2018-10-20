## 二叉树的遍历

##### 二叉树

二叉树是一种非常重要的数据结构，对于二叉树，有前序、中序以及后序三种遍历方法。

***前序：*** 根左右

***中序：***左根右

***后续:*** 左右根

**递归实现：**

前序：

```c++
void preOrder(TreeNode *node){
  if(node==NULL){
  	return ;
  }
  cout<<node->val;
  preOrder(node->left);
  preOrder(node->right);
}
```

中序：

```c++
void InOrder(TreeNode *Node){
  if(node==NULL)
    return ;
  InOrder(node->left);
  cout<<node->val;
  InOrder(node->right);
}
```

后序：

```C++
void PostOrder(TreeNode *node){
  if(node==NULL)
    return ;
  PostOrder(node->left);
  PostOrder(node->right);
  cout<<node->val<<endl;
}
```



**层次遍历**

```c++
int printLevel(TreeNode *root,int orderLevel,int currLevel){
  if(root==NULL||orderLevel<0){
  	return 0;
  }
  if(currLevel == orderLevel){
  	cout<<root->val;
    return 1;
   }
  if(currLevel<orderLevel){
	  return printLevel(root->left,orderLevel,currLevel+1)+printLevel(root->right,orderLevel,currLevel+1)
	}
}
```

# 下次补上非递归方式解决这些问题

