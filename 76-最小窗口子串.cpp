/*
//76-最小窗口子串
*/
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        const int MAX_ARRAY_LEN = 128;
        int map_s[MAX_ARRAY_LEN] = {0};  //记录s字符串中各字符的个数
        int map_t[MAX_ARRAY_LEN] = {0};  //记录t字符串中各字符的个数

        vector<int> vec_t;               //记录t字符串中有哪些字符
        for(int i = 0;i < t.size();i++)
        {
            map_t[t[i]]++;
        }
        for(int i = 0; i < MAX_ARRAY_LEN;i++) //将字符串t中出现的字符存储到vec_t中
        {
            if(map_t[i] > 0)
                vec_t.push_back(i);
        }
        int window_begin = 0;                //最小窗口起始指针
        string result;                       //最终的最短字符串
        for(int i = 0; i < s.size(); i++)
        {
            map_s[s[i]]++;                   //将尾指针指向的字符，添加到表示窗口的map中
            while(window_begin < i)          //窗口的头指针不能超多尾指针
            {
                char begin_ch = s[window_begin];
                if(map_t[begin_ch] == 0)     //如果begin_ch没有在t中出现
                    window_begin++;
                else if(map_s[begin_ch] > map_t[begin_ch]) //如果窗口内有超多t中该字符的个数
                {
                    map_s[begin_ch]--;       //窗口前移，则该字符的个数减1
                    window_begin++;          //窗口指针前移
                }
                else                         //window_begin不满足移动条件，退出循环
                {
                    break;
                }
            }
            //检查此时的窗口是否包含t
            if(is_window_ok(map_s, map_t, vec_t))
            {
                int new_window_len = i - window_begin + 1;  //计算新的字符串长度
                //如果result为空，或者存在更小子串时候，更新结果
                if(result == "" || result.size() > new_window_len)
                    result = s.substr(window_begin, new_window_len);
            }
        }
        return result;

    }
private:
    //判断map_t中的字符是否出现在map_s中
    bool is_window_ok(int map_s[], int map_t[], vector<int> &vec_t)
    {
        for(int i = 0; i < vec_t.size();i++)
        {
            if(map_s[vec_t[i]] < map_t[vec_t[i]])
                return false;
        }
        return true;
    }
};
int main(void)
{
    Solution solve;
	std::string result = solve.minWindow("ADOBECODEBANC", "ABC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("MADOBCCABEC", "ABCC");
	printf("%s\n", result.c_str());
	result = solve.minWindow("aa", "aa");
	printf("%s\n", result.c_str());
    return 0;
}
