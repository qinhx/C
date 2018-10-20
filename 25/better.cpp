#include <iostream>
using namespace std;
#include<vector>
#include <cmath>
class Solution{
	public:
		vector<vector<int> > FindContinuousSequence(int sum){
			vector<vector<int> > arr;
			if(sum<2){
				return arr;
			}
			int n =(int)sqrt(2*sum);
			for(int i=n;i>2;i--){
				if((i&1)==1&&sum%i==0){
					vector<int> tmp;
					int k = sum/i;
					for(int j = k-(i-1)/2;j<=k+(i-1)/2;j++){
						tmp.push_back(j);
					} 
					arr.push_back(tmp); 
				}
				if((sum%i)*2==i){
					int k = sum/i;
					vector<int> tmp2;
					for(int j = k-(i-1)/2;j<=k+(i-1)/2;j++){
						tmp2.push_back(j);
					}
					arr.push_back(tmp2);
				}	
			}
			return arr;
		}
};


int main( )
{
    Solution solu;

    vector< vector<int> > res = solu.FindContinuousSequence(100);

    cout <<"Total Count = "<<res.size( ) <<endl;
    for(unsigned int i = 0; i < res.size( ); i++)
    {
        cout <<"Count = " <<i <<", Size = "<<res[i].size( ) <<endl;
        for(unsigned int j = 0; j < res[i].size( ); j++)
        {
            cout <<res[i][j] <<" ";
        }
        cout <<endl;
    }

    return 0;
}
