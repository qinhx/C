#include <iostream>
using namespace std;
#include <vector>
class Solution{
	public:
		void reOrderArray(vector<int>&array){
			
			vector<int> temp;
			vector<int>::iterator ib1,ie1;
			ib1 = array.begin();
			for(;ib1!=array.end();){
				if(*ib1%2==0){
					temp.push_back(*ib1);
					ib1 = array.erase(ib1);
				}else{
					ib1++;
				}
			}
			vector<int>::iterator ib2,ie2;
			ib2 = temp.begin();
			ie2 = temp.end();
			for(;ib2!=ie2;ib2++){
				array.push_back(*ib2);
			}
		}
}; 
int main(){
	int array[] = { 1, 2, 3, 4, 5, 6, 7};
	vector<int> vec(array, array + 7);
    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    Solution solu;
    solu.reOrderArray(vec);

    for(int i = 0; i < 7; i++)
    {
        cout <<vec[i] <<" ";
    }
    cout <<endl;
    return 0;
}
