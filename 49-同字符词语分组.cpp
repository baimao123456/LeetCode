/*
//49-同字符词语分组
*/
#include <stdio.h>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        //key：内部排序的string，
        //value：同字符的string
        map<string, vector<string> > anagram;
        vector<vector<string> > result;      //存储最终的结果
        for(int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];            //临时存储strs[i]
            sort(str.begin(), str.end());    //对str进行内部排序
            if(anagram.find(str) == anagram.end()) //如果str没有映射过
            {
                vector<string> item;         //设置一个空的字符串向量
                anagram[str] = item;         //以排序后的str作为key
            }
            anagram[str].push_back(strs[i]); //在对应的字符向量中push结果
        }
        //遍历哈希表，将valuepush进最后的结果中
        map<string, vector<string> >::iterator it;
        for(it = anagram.begin(); it != anagram.end(); ++it)
        {
            result.push_back((*it).second);
        }
        return result;
    }
};
int main(void)
{

    return 0;
}
