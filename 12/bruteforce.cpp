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
};

class Solution{
	public:
		RandomListNode* FindInNew(RandomListNode *oldHead,RandomListNode *newHead){
			RandomListNode *currNode = oldHead;
			RandomListNode *goalNode = currNode->randNext;
			RandomListNode *newNode = newHead;
			while(currNode!=NULL&&newNode!=NULL){
				if(currNode==goalNode){
					return newNode;
				}
				currNode =  currNode->next;
				newNode = newNode->next;
			}
			return NULL;
		}
		RandomListNode* Clone(RandomListNode *pHead){
			if(pHead==NULL){
				return NULL;
			}
			RandomListNode *cpyNodeRoot = NULL;
			RandomListNode *currNode = pHead;
			RandomListNode *currCpyNode = NULL;
			cpyNodeRoot =  new RandomListNode(pHead->val);
			currCpyNode =  cpyNodeRoot;
			while(currNode!=NULL){
				currNode = currNode->next;
				RandomListNode *curr = new RandomListNode(currNode->val);
				currCpyNode->next = curr;
				currCpyNode = currCpyNode->next;
			}
			currNode =  pHead;
			currCpyNode =  cpyNodeRoot;
			while(currNode!=NULL){
				RandomListNode *randNode =  FindInNew(currNode,cpyNodeRoot);
				currCpyNode->randNext =randNode;
				currCpyNode =  currCpyNode->next;
				currNode = currNode->next;
			}
			return cpyNodeRoot;
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
	while(root!=NULL){
		cout<<root->val<<endl;
		root = root->next;
	}
}
 
