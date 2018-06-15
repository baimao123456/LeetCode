/*
//290-词语模式
*/
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    //判断pattern和str是否对应匹配
    wordPattern(string pattern, string str)
    {
        map<string, char> word_map;   //单词到字符的映射
        char used[128] = {0};         //标记已经被映射的字符
        string word;                  //临时保存拆分出来的单词
        int pos = 0;                  //当前指向的pattern字符
        str.push_back(' ');           //临时添加一个空格，方便进行单词拆分时候的判断
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ' ')         //遇到空格就拆分单词
            {
                if(pos == pattern.size()) //如果pattern个数比str的少
                    return false;

                //如果单词没有出现在哈希映射表中
                if(word_map.find(word) == word_map.end())
                {
                    if(used[pattern[pos]]== 1) //如果字符已经被使用，则不匹配
                        return false;
                    word_map[word] = pattern[pos];
                    used[pattern[pos]] = 1;    //标记字符已经使用
                }
                else                  //如果单词已经出现在哈希映射表中
                {
                    if(word_map[word] != pattern[pos])
                        return false;
                }
                word = "";            //完成一个单词的查询和映射后，清空
                pos++;                //指向下一个模式字符
            }
            else
                word += str[i];       //如果没有遇见空格，则持续加字符
        }
        if(pos != pattern.size())     //存在多余的pattern字符
            return false;
        return true;
    }
};
int main(void)
{
    std::string pattern = "abba";
	std::string str = "dog cat cat dog";
	Solution solve;
	printf("%d\n", solve.wordPattern(pattern, str));
    return 0;
}
