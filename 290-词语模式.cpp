/*
//290-����ģʽ
*/
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

class Solution
{
public:
    //�ж�pattern��str�Ƿ��Ӧƥ��
    wordPattern(string pattern, string str)
    {
        map<string, char> word_map;   //���ʵ��ַ���ӳ��
        char used[128] = {0};         //����Ѿ���ӳ����ַ�
        string word;                  //��ʱ�����ֳ����ĵ���
        int pos = 0;                  //��ǰָ���pattern�ַ�
        str.push_back(' ');           //��ʱ���һ���ո񣬷�����е��ʲ��ʱ����ж�
        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ' ')         //�����ո�Ͳ�ֵ���
            {
                if(pos == pattern.size()) //���pattern������str����
                    return false;

                //�������û�г����ڹ�ϣӳ�����
                if(word_map.find(word) == word_map.end())
                {
                    if(used[pattern[pos]]== 1) //����ַ��Ѿ���ʹ�ã���ƥ��
                        return false;
                    word_map[word] = pattern[pos];
                    used[pattern[pos]] = 1;    //����ַ��Ѿ�ʹ��
                }
                else                  //��������Ѿ������ڹ�ϣӳ�����
                {
                    if(word_map[word] != pattern[pos])
                        return false;
                }
                word = "";            //���һ�����ʵĲ�ѯ��ӳ������
                pos++;                //ָ����һ��ģʽ�ַ�
            }
            else
                word += str[i];       //���û�������ո���������ַ�
        }
        if(pos != pattern.size())     //���ڶ����pattern�ַ�
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
