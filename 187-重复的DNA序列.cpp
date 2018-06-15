/*
//187-重复的DNA序列
*/
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution1
{
public:
    //枚举所有的长度为10的子串，找出出现次数超过1次的
    vector<string> findRepeatedDnaSequences(string s)
    {
        map<string, int>  word_map;    //记录 <单词，单词数量>映射
        vector<string> result;
        for(int i = 0; i < s.size(); i++)
        {
            string word = s.substr(i, 10);   //取长度为10的子串
            if(word_map.find(word) != word_map.end()) //如果已经映射过
            {
                word_map[word] += 1;
            }
            else   //如果没有映射过，则添加key
            {
                word_map[word] = 1;
            }
        }
        map<string, int>::iterator it;
        for(it = word_map.begin(); it != word_map.end(); it++)
        {
            if(it->second > 1)
                result.push_back(it->first);
        }
        return result;
    }
};
int main()
{
    std::string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution1 solve;
	std::vector<std::string> result = solve.findRepeatedDnaSequences(s);
	for (int i = 0; i < result.size(); i++){
		printf("%s\n", result[i].c_str());
	}
    return 0;
}
