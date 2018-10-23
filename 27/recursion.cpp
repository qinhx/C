#include <iostream>
using namespace std;
class Solution{
	public:
		int LastOne(int m, int n){
			if(n<1||m<1){
				return -1;
			}else if(n == 1){
				return 0;
			}else{
				return (LastOne(m,n-1)+m)%n;
			}
		}
		int Last(int n,int m) {
        if(n < 1 || m < 1)
        {
            return -1;
        }

        int last = 0;

        for(int step = 2; step <= n; step++)
        {
            last = (last + m) % step;
        }
        last = (last + m) % n+1;
        return last;
    }
};

int main(){
	Solution solu;
	cout<<solu.Last(8,5)<<endl;
	cout<<solu.LastOne(5,8)<<endl;
}
