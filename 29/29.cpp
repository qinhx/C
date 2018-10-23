#include <iostream>
using namespace std;
class Solution{
	public:
		vector<int> multply(const vector<int>& A){
			int n =A.size(;
			vector<int>res(n);
			for(int i=0,temp=1;i<n;i++){
				res[i] = temp;
				temp *=A[i];
			} 
			for(int i=n-1,temp=1;i>=0;i--){
				res[i]*=temp;
				temp *= A[i];
			}
			return res;
		}
};

int main(){
	return 0;
}
