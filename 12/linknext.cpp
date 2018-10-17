#include <iostream>
using namespace std;

struct RandomListNode {
	int val;
	 RandomListNode *next;
	 RandomListNode *randNext;
	RandomListNode(int data){
		val = data;
		next=NULL;
		randNext=NULL;
	}
	RandomListNode(){
	}
};
class Solution{
	public:
		RandomListNode* Clone(RandomListNode *pHead){
			RandomListNode *currNode = pHead;
			RandomListNode *cpyHead = NULL, *newNode = NULL;
			cpyHead = newNode;
			while(currNode!=NULL){
				newNode =new RandomListNode(currNode->val);
				newNode->next = currNode->next;
				currNode ->next = newNode;
				currNode = newNode->next;
			} 
			currNode = pHead;
			while(currNode!=NULL){
				newNode = currNode->next;
				newNode->randNext = currNode->randNext->next;
				currNode = newNode->next;
			}
			currNode = pHead;
			while(currNode!=NULL){
				newNode = currNode->next;
				currNode->next = newNode->next;
				currNode = newNode->next;
				newNode->next=currNode->next;
			}
			return newNode;
		}
};
int main(){
	RandomListNode *node[4];
	node[0] = new RandomListNode(03);
	node[1] = new RandomListNode(14);
	node[2] = new RandomListNode(21);
	node[3] = new RandomListNode(30);
	node[0]->next = node[1];
	node[0]->randNext = node[3];
	node[1]->next = node[2];
	node[1]->randNext = node[4];
	node[2]->next = node[3];
	node[2]->randNext = node[1];
	node[3]->randNext = node[0];
	RandomListNode *root = node[0];
	Solution solu;
	RandomListNode * newNode = solu.Clone(root);
	while(newNode!=NULL){
		cout<<root->val<<endl;
		root = root->next;
	}
}
