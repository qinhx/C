#include <iostream>
#include <vector>

using namespace std;

//  µ÷ÊÔ¿ª¹Ø
#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


class Solution
{
public:
    int GetNumberOfK(vector<int> data,int k){
        if(data.size( ) == 0){
            return 0;
        }
        int index = BinarySearch(data,0,data.size()-1,k);
        if(index ==-1){
        	return 0;
		}
        int count = 1;
        for(int i=0;i<index;i++){
        	if(data[i]==k) 
        		count++;
        	
		}
		for(int j=data.size()-1;j>index;j--){
			if(data[j]==k)
				count++;
		}
        return count;
    }
    int BinarySearch(vector<int> &data,int begin,int end,int key){
    	if(begin>end){
    		return -1;
		}
		int mid = (begin+end)/2;
		if(data[mid]==key){
			return mid;
		}else if(data[mid]>key){
			return BinarySearch(data,begin,mid-1,key);
		}else if(data[mid]<key){
			return BinarySearch(data,mid+1,end,key);
		}
		return -1;
		
	}
};

int __tmain( )
{
    Solution solu;

    int arr[] = { 1, 2, 3, 3, 3, 3,3, 4, 5 };
    vector<int> vec(arr, arr + 8);
    cout <<solu.GetNumberOfK(vec, 3) <<endl;

    return 0;
}
