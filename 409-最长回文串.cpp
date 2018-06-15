/*
//409-最长回文串
*/
#include <stdio.h>
#include <string>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int char_map[128] = {0};   //字符hash
        int max_length = 0;        //回文串最长长度
        int flag = 0;              //是否有中心点
        for(int i = 0; i < s.size(); i++)  //统计字符的个数
        {
            char_map[s[i]]++;
        }
        for(int i = 0; i < 128; i++)
        {
            if((char_map[i] & 0x1) == 0)   //如果字符个数为偶数个，则所有的字符均可以在回文串中使用
                max_length += char_map[i];
            else //如果为奇数个，丢弃一个，则剩下的偶数个可以使用，剩下的一个可以作为中心点
            {
                max_length += char_map[i] - 1;
                flag = 1;
            }
        }
        return max_length + flag; //最大长度包括偶数部分的最大长度+中心点
    }
};
int main(void)
{
    Solution sol;
    printf("the max length is : %d", sol.longestPalindrome("abccccddaa"));
    return 0;
}
