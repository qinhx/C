class Solution
{
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
    {
		int i=0;
		ListNode *Right = pListHead;
		while(i<k){
			pListHead= pListHead->next;
		}
		ListNode *Left = pListHead;
		while(Right!=null){
			Right = Right->next;
			Left =Left->next;
		}
	return Left;
    }
};
