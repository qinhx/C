#include <iostream>
#include <cmath>
using namespace std;
class Solution{
	public:
	double PowerNormal(double base,int exponent){
		if(exponent==0){
			return 1;
		}
		if(exponent==1){
			return base;
		}
		double res =1 ,temp =base;
		if(exponent>0){
			while(exponent!=0){
				if((exponent&1)==1){
					res *=temp;
				}
				temp*=temp;
				exponent>>=1;
				}
				}else{ 
					exponent=-exponent;
			while(exponent!=0){
				if((exponent&1)==1){
					res *=temp;
				}
				temp*=temp;
				exponent>>=1;
				}
				res =1/res;
	}
		return res;
	}

};
 
 int main(){
    Solution solu;
    cout <<solu.PowerNormal(2, 0) <<endl;
    cout <<solu.PowerNormal(2, -3) <<endl;
    return 0;	
 }
