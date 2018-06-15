/*
//127-�������
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;
//�ж����������Ƿ��1���ַ�
bool connect(string &word1, string &word2)
{
    int cnt = 0;
    for(int i = 0; i < word1.size(); i++)
    {
        if(word1[i] != word2[i])
            cnt++;
    }
    return cnt == 1;
}
//����ͼ
void construct_graph(string &beginWord,
                     vector<string> &wordList,
                     map<string, vector<string> > &graph)
{
    wordList.push_back(beginWord);
    for(int i = 0; i < wordList.size(); i++)        //Ϊÿ���ڵ㴴��һ���ڽӱ�
    {
        graph[wordList[i]] = vector<string>();
    }
    for(int i = 0; i < wordList.size(); i++)        //��ֻ��1���ַ���ͬ��word����
    {
        for(int j = i + 1; j < wordList.size(); j++)
        {
            if(connect(wordList[i], wordList[j]))     //������1���ַ������������
            {
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    }
}
//������ȱ���ͼ
int BFS_graph(string &beginWord, string &endWord,
              map<string, vector<string> > &graph)
{
    queue<pair<string, int> > Q;           //<����,����>
    set<string> visit;                     //��¼�ѷ��ʵĶ���
    Q.push(make_pair(beginWord, 1));       //�����ʼ�㣬����Ϊ1
    visit.insert(beginWord);               //��¼
    while(!Q.empty())
    {
        string node = Q.front().first;     //ȡ����ͷ���ڵ�Ͳ���
        int step = Q.front().second;
        Q.pop();                           //����ͷ���ڵ�
        if(node == endWord)
            return step;

        const vector<string> &neighbors = graph[node];  //ȡnode��ȫ���ڽӵ�
        for(int i = 0; i < neighbors.size(); i++)       //��δ��ӵ����ڽڵ���ӵ�����
        {
            if(visit.find(neighbors[i]) == visit.end()) //���û��
            {
                Q.push(make_pair(neighbors[i], step + 1));//��ǰ������1
                visit.insert(neighbors[i]);             //��¼
            }
        }
    }
    return 0;
}
class Solution
{
public:
    int ladderLength(string &beginWord, string &endWord,
                     vector<string> &wordList)
    {
        map<string, vector<string> > graph;
        construct_graph(beginWord, wordList, graph);
        return BFS_graph(beginWord, endWord, graph);
    }
};
int main(void)
{
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList;
    wordList.push_back("hot");
    wordList.push_back("dot");
    wordList.push_back("dog");
    wordList.push_back("lot");
    wordList.push_back("log");
    wordList.push_back("cog");
    Solution sol;
    int result = sol.ladderLength(beginWord, endWord, wordList);
    printf("result is : %d", result);
    return 0;
}
