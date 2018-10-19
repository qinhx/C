#include <iostream>
#include <vector>
using namespace std;
class Solution{
	int dp[1000];
	public:
		int FindTheBestSumOfSubArray(vector<int> array){
			if(array.size()==0){
				return 0;
			}
			int maxSum = INT_MIN;
			dp[0] = array[0];
			for(int i=1;i<array.size();i++){
				if(dp[i-1]<0){
					dp[i] = array[i];
				}else{
					dp[i]=dp[i-1]+array[i];
				}
				if(dp[i]>maxSum){
					maxSum = dp[i];
				}
			}
			return maxSum;
		}
};

int main( )
{


    Solution solu;

    int arr1[] = { 6, -3, -2, 7, -15, 1, 2, 2};
    vector<int> vec1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
    cout <<"maxSum = " <<solu.FindTheBestSumOfSubArray(vec1) <<endl;

    int arr2[] = { -2, -8, -1, -5, -9 };
    vector<int> vec2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));
    cout <<"maxSum = " <<solu.FindTheBestSumOfSubArray(vec2) <<endl;

    return 0;
}
