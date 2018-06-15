/*
//126-�������2-��������·��
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;
struct Qitem
{
    string node;      //�������Ľڵ�
    int parent_pos;   //ǰ���ڵ��ڶ����е�λ��
    int step;         //���ﵱǰ�ڵ�Ĳ���
    Qitem(string node, int parent_pos, int step)
                : node(NULL), parent_pos(parent_pos),step(step){}
};
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
    int has_begin_word = 0;
    for(int i = 0; i < wordList.size(); i++)        //Ϊÿ���ڵ㴴��һ���ڽӱ�
    {
        if(wordList[i] == beginWord)
            has_begin_word = 1;
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
        if(has_begin_word == 0 && connect(beginWord, wordList[i]))
            graph[beginWord].push_back(wordList[i]);
    }
}
//������ȱ���ͼ
void BFS_graph(string &beginWord, string &endWord,
              map<string, vector<string> > &graph,
              vector<Qitem> &Q,
              vector<int> &end_word_pos)
{
    map<string, int> visit;                     //��¼�ѷ��ʵĶ���
    int min_step = 0;                           //�ﵽend_word_pos����С����
    Q.push_back(Qitem(beginWord.c_str(), -1, 1));       //�����ʼ�㣬ǰ��Ϊ -1������Ϊ1
    visit[beginWord] = 1;                       //��¼�����ĵ���
    int front = 0;                              //��ͷָ��Ϊ0��ָ��vector��ʾ�Ķ���ͷ
    while(front != Q.size())
    {
        const string &node = Q[front].node;           //ȡ����ͷ���ڵ�Ͳ���
        int step = Q[front].step;
        if(min_step != 0 && min_step < step)    //������ﵱǰ�Ĳ���������С������û��Ҫ���������
            break;
        if(node == endWord)                     //�������endword����¼��С����
        {
            min_step = step;
            end_word_pos.push_back(front);      //��¼��ǰ�ڵ��ڶ����е�λ��
        }
        const vector<string> &neighbors = graph[node];     //ȡnode��ȫ���ڽӵ�
        for(int i = 0; i < neighbors.size(); i++)          //��δ��ӵ����ڽڵ���ӵ�����
        {
            if(visit.find(neighbors[i]) == visit.end() ||  //�ڵ�û�б����ʻ�����һ�����·��
               visit[neighbors[i]] == step + 1)
            {
                Q.push_back(Qitem(neighbors[i], front, step + 1));//��¼ǰ���ڵ㣬��������1
                visit[neighbors[i]] = step + 1;                   //��¼�����ڽӵ�neighbors[i]�Ĳ���
            }
        }
        front++;
    }
}
class Solution
{
public:
    vector<vector<string> > ladderLength(string &beginWord, string &endWord,
                     vector<string> &wordList)
    {
        map<string, vector<string> > graph;
        construct_graph(beginWord, wordList, graph);
        vector<Qitem> Q;
        vector<int> end_word_pos;    //end_word�����������е�λ��
        BFS_graph(beginWord, endWord, graph, Q, end_word_pos);

        vector<vector<string> > result;      //���յ�·��
        for(int i = 0; i < end_word_pos.size(); i++)
        {
            int pos = end_word_pos[i];
            vector<string> path;
            while(pos != -1)
            {
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos;
            }
            result.push_back(vector<string> ());
            for(int j = path.size() - 1; j >= 0; j--)
            {
                result[i].push_back(path[j]);
            }
        }
        return result;
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
    vector<vector<string> > result = sol.ladderLength(beginWord, endWord, wordList);
    for(int i = 0; i < result.size();i++)
    {
        for(int j = 0; j < result[i].size(); j++)
        {
            printf("[%s]",result[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}
