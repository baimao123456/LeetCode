/*
�Ƴ�k������
*/
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
class Solution1
{
public:
    string removeKdigits(string num, int k)
    {
        vector<int> S;  //����ʹ��vector����Ϊ���Ա���
        string result = "";  //�洢���صĽ��
        for(int i = 0; i < num.size(); i++)
        {
            int number = num[i] - '0';   //���ַ�ת��int����
            //���ջ���գ���ջ��Ԫ�ش���number����Ȼ����ɾ��Ԫ��ʱ������ѭ��
            while(S.size() != 0 && S.back() > number && k > 0)
            {
                S.pop_back();
                k--;
            }
            if(number != 0 || S.size() != 0) //���SΪ�գ���number��0�������number��
                S.push_back(number);   //������ѹ��ջ��
        }
        while(S.size() != 0 && k >0)  //���ջ���գ�����Ȼ����ɾ������
        {
            S.pop_back();   //ɾ��ջ��Ԫ��
            k--;            //ɾ�����ֺ����
        }
        for(int i = 0; i < S.size(); i++)
            result += S[i] + '0';

        if(result == "")
            result = "0";

        return result;
    }
};
class Solution2
{
    //ֱ�Ӷ�string���в���
public:
    string removeKdigits(string num, int k)
    {
        string result = "";  //�洢���صĽ��
        for(int i = 0; i < num.size(); i++)
        {
           if(num[i] > num[i + 1] && k > 0) //�����ߵ����ֱ�ǰ�ߵ�С,������ǰѭ��
           {
               k--;                         //
               continue;                    //������������������ǰѭ��
           }
           if(result.size() != 0 || num[i] != '0') //������ַ���'0'�����üӵ�result��
                result += num[i];
        }
        while(result.size() > 0 && k > 0)   //���ջ���գ�����Ȼ����ɾ������
        {
            result.erase(result.end() - 1); //ɾ���ַ���ĩβ���ַ�
            k--;
        }
        if(result == "")                    //����ǿգ�����0
            result = "0";
        return result;
    }
};
int main(void)
{
    Solution1 sol1;
    Solution2 sol2;
    string result = sol1.removeKdigits("1432219", 3);
    printf("%s\n",result.c_str());
    string result2 = sol1.removeKdigits("100200", 1);
    printf("%s\n",result2.c_str());
    string result3 = sol1.removeKdigits("14345109", 2);
    printf("%s\n",result3.c_str());

    string result4 = sol2.removeKdigits("14345109", 2);
    printf("%s\n",result4.c_str());
    return 0;
}
