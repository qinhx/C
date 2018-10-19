#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
    int NumberOf1Between1AndN_Solution(int n){
    	int count=0;
    	for(int i=0;i<=n;i++){
    		count+=getCount(i);
		}
		return count;
    }
    int getCount(int num){
    	int count =0;
    	while(num!=0){
    		if(num%10==1){
    			count++;
			}
			num/=10;
		} 
		return count;
	}
};
int main(){
	Solution solu;
	cout<<solu.NumberOf1Between1AndN_Solution(11)<<endl;
}
