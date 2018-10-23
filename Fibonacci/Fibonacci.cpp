#include <iostream>
using namespace std;
#include <vector>
class Solution{
	public:
		int fibonacci(int n){
			vector<int> Memo(n+1); 
			for(int i=0;i<n+1;i++)
				Memo[i]=-1;
			return fib(n,Memo);
			
		}
		int fib(int n,vector<int> &memo){
			if(n<0)
				return memo[n];
			if(n<=2)
				memo[n] = 1;
			if(memo[n]!=-1)
				return memo[n];
			else memo[n]=fib(n-1,memo)+fib(n-2,memo);
			
			return memo[n];
				
		}
};
int main(){
	int n ;
	Solution solu;
	while(cin>>n){
		cout<<solu.fibonacci(n)<<endl;
	}
}
