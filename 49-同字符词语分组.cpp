/*
//49-ͬ�ַ��������
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
        //key���ڲ������string��
        //value��ͬ�ַ���string
        map<string, vector<string> > anagram;
        vector<vector<string> > result;      //�洢���յĽ��
        for(int i = 0; i < strs.size(); i++)
        {
            string str = strs[i];            //��ʱ�洢strs[i]
            sort(str.begin(), str.end());    //��str�����ڲ�����
            if(anagram.find(str) == anagram.end()) //���strû��ӳ���
            {
                vector<string> item;         //����һ���յ��ַ�������
                anagram[str] = item;         //��������str��Ϊkey
            }
            anagram[str].push_back(strs[i]); //�ڶ�Ӧ���ַ�������push���
        }
        //������ϣ����valuepush�����Ľ����
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
