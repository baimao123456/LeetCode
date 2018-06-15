/*
//187-�ظ���DNA����
*/
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution1
{
public:
    //ö�����еĳ���Ϊ10���Ӵ����ҳ����ִ�������1�ε�
    vector<string> findRepeatedDnaSequences(string s)
    {
        map<string, int>  word_map;    //��¼ <���ʣ���������>ӳ��
        vector<string> result;
        for(int i = 0; i < s.size(); i++)
        {
            string word = s.substr(i, 10);   //ȡ����Ϊ10���Ӵ�
            if(word_map.find(word) != word_map.end()) //����Ѿ�ӳ���
            {
                word_map[word] += 1;
            }
            else   //���û��ӳ����������key
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
