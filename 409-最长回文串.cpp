/*
//409-����Ĵ�
*/
#include <stdio.h>
#include <string>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int char_map[128] = {0};   //�ַ�hash
        int max_length = 0;        //���Ĵ������
        int flag = 0;              //�Ƿ������ĵ�
        for(int i = 0; i < s.size(); i++)  //ͳ���ַ��ĸ���
        {
            char_map[s[i]]++;
        }
        for(int i = 0; i < 128; i++)
        {
            if((char_map[i] & 0x1) == 0)   //����ַ�����Ϊż�����������е��ַ��������ڻ��Ĵ���ʹ��
                max_length += char_map[i];
            else //���Ϊ������������һ������ʣ�µ�ż��������ʹ�ã�ʣ�µ�һ��������Ϊ���ĵ�
            {
                max_length += char_map[i] - 1;
                flag = 1;
            }
        }
        return max_length + flag; //��󳤶Ȱ���ż�����ֵ���󳤶�+���ĵ�
    }
};
int main(void)
{
    Solution sol;
    printf("the max length is : %d", sol.longestPalindrome("abccccddaa"));
    return 0;
}
