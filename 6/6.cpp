#include <iostream>
#include <cmath>
using namespace std;

class Solution{
	public:
		double Power(double base,int exponent){
			if(exponent ==0){
				return 0;
			}
			double res =1.0;
			if(exponent >0.0){
				res = PowerNormal(base,exponent);
			}else{
				res = PowerNormal(base,-exponent);
				res = 1/res;
			}
			return res;
		}
		
	private:
		double PowerNormal(double base,int exponent){
			double res =1;
			for(int i=0;i<exponent;i++){
				res*=base;
			}
			return res;
		}
};
 
 int main(){
    Solution solu;
    cout <<solu.Power(2, 0) <<endl;
    cout <<solu.Power(2, -3) <<endl;
    return 0;	
 }
