#include <iostream>
using namespace std;

class Solution {
    public:
    string intToRoman(int num)
    {
        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};    
    
        int i= 0;
        string result = "";
        while(num>0){
            while(num>=value[i]){
                result += symbol[i];
                num -= value[i];
            } i++;
        }
        return result;
    }
    
    };


//Driver program
int main()
{
    int num = 3549;
    Solution sol;

    string result = sol.intToRoman(num);
    cout<<result;
    return 0;
}
