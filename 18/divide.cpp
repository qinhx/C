#include <iostream>
#include <vector>
using namespace std;
#include <cmath>
class Solution
{
public:
    /**
     * [NumberOf1Between1AndN_Solution ͳ��1��n��������1���ֵĴ���]
     * @Author   gatieme
     * @DateTime 2016-05-01T22:03:43+0800
     * @param    n                        [����n]
     * @return                            [1��n��������1���ֵĴ���]
     */
    int NumberOf1Between1AndN_Solution(int n)
    {
        return CountOne(n);
    }

    int CountOne(int n)
    {
        long count = 0;

        if (n == 0)
        {
            count = 0;
        }
        else if (n > 1 && n < 10)
        {
            count =  1;
        }
        else
        {
            // ����n��λ��
            long highest = n;       //��ʾ���λ������
            int bit = 0;
            while (highest >= 10)
            {
                highest = highest / 10;
                bit++;
            }
            //  ѭ������ʱ, bit��ʾn��λ��, ��highest�������λ������

            //int weight = (int)Math.Pow(10, bit);//�������λ��Ȩ�أ������λһ��1����Ĵ�С
            int weight = pow(10, bit);//�������λ��Ȩ�أ������λһ��1����Ĵ�С

            if (highest == 1)
            {
                count = CountOne(weight - 1)
                      + CountOne(n - weight)
                      + (n - weight + 1);
            }
            else
            {
                count = highest * CountOne(weight - 1)
                      + CountOne(n - highest * weight)
                      + weight;
            }
        }

        return count;
    }
};
int main(){
	Solution solu;
	cout<<solu.NumberOf1Between1AndN_Solution(11)<<endl;
}
