/*
//3-无重复的最长子串
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
        int begin = 0;                  //窗口的头指针
        int result = 0;                 //最长子串个数
        string word = "";
        int char_map[128] = {0};        //用来存储某个字符是否出现过
        for(int i = 0; i < s.size(); i++)
        {
            char_map[s[i]]++;           //出现次数加1
            if(char_map[s[i]] == 1)     //如果s[i]没有出现过，加入到word中，1：没有出现重复的 >1:出现了重复的
            {
                word += s[i];
                if(result < word.size())//更新result为最大长度
                    result = word.size();
            }
            else   //如果该字符出现过，begin指向前边重复字符的后边位置
            {
                //一旦begin经过了重复字符，会停止
                while(begin < i && char_map[s[begin]] > 1)
                {
                    char_map[s[begin]]--;  //将之前的标记清除
                    begin++;
                }
                word = "";  //更新word
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
