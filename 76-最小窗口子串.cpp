/*
//76-��С�����Ӵ�
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
        int map_s[MAX_ARRAY_LEN] = {0};  //��¼s�ַ����и��ַ��ĸ���
        int map_t[MAX_ARRAY_LEN] = {0};  //��¼t�ַ����и��ַ��ĸ���

        vector<int> vec_t;               //��¼t�ַ���������Щ�ַ�
        for(int i = 0;i < t.size();i++)
        {
            map_t[t[i]]++;
        }
        for(int i = 0; i < MAX_ARRAY_LEN;i++) //���ַ���t�г��ֵ��ַ��洢��vec_t��
        {
            if(map_t[i] > 0)
                vec_t.push_back(i);
        }
        int window_begin = 0;                //��С������ʼָ��
        string result;                       //���յ�����ַ���
        for(int i = 0; i < s.size(); i++)
        {
            map_s[s[i]]++;                   //��βָ��ָ����ַ�����ӵ���ʾ���ڵ�map��
            while(window_begin < i)          //���ڵ�ͷָ�벻�ܳ���βָ��
            {
                char begin_ch = s[window_begin];
                if(map_t[begin_ch] == 0)     //���begin_chû����t�г���
                    window_begin++;
                else if(map_s[begin_ch] > map_t[begin_ch]) //����������г���t�и��ַ��ĸ���
                {
                    map_s[begin_ch]--;       //����ǰ�ƣ�����ַ��ĸ�����1
                    window_begin++;          //����ָ��ǰ��
                }
                else                         //window_begin�������ƶ��������˳�ѭ��
                {
                    break;
                }
            }
            //����ʱ�Ĵ����Ƿ����t
            if(is_window_ok(map_s, map_t, vec_t))
            {
                int new_window_len = i - window_begin + 1;  //�����µ��ַ�������
                //���resultΪ�գ����ߴ��ڸ�С�Ӵ�ʱ�򣬸��½��
                if(result == "" || result.size() > new_window_len)
                    result = s.substr(window_begin, new_window_len);
            }
        }
        return result;

    }
private:
    //�ж�map_t�е��ַ��Ƿ������map_s��
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
