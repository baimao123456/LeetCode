/*
//3-���ظ�����Ӵ�
*/
#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
    lengthOfLongestSubstring(string s)
    {
        int begin = 0;                  //���ڵ�ͷָ��
        int result = 0;                 //��Ӵ�����
        string word = "";
        int char_map[128] = {0};        //�����洢ĳ���ַ��Ƿ���ֹ�
        for(int i = 0; i < s.size(); i++)
        {
            char_map[s[i]]++;           //���ִ�����1
            if(char_map[s[i]] == 1)     //���s[i]û�г��ֹ������뵽word�У�1��û�г����ظ��� >1:�������ظ���
            {
                word += s[i];
                if(result < word.size())//����resultΪ��󳤶�
                    result = word.size();
            }
            else   //������ַ����ֹ���beginָ��ǰ���ظ��ַ��ĺ��λ��
            {
                //һ��begin�������ظ��ַ�����ֹͣ
                while(begin < i && char_map[s[begin]] > 1)
                {
                    char_map[s[begin]]--;  //��֮ǰ�ı�����
                    begin++;
                }
                word = "";  //����word
                for(int j = begin; j <= i; j++)
                {
                    word += s[j];
                }
            }
        }
        return result;
    }
};
int main()
{
    std::string s = "abcbad";
	Solution solve;
	printf("%d\n", solve.lengthOfLongestSubstring(s));
    return 0;
}
