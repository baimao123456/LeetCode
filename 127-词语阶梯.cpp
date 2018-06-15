/*
//127-词语阶梯
*/
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
using namespace std;
//判断两个单词是否差1个字符
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
//构造图
void construct_graph(string &beginWord,
                     vector<string> &wordList,
                     map<string, vector<string> > &graph)
{
    wordList.push_back(beginWord);
    for(int i = 0; i < wordList.size(); i++)        //为每个节点创建一个邻接表
    {
        graph[wordList[i]] = vector<string>();
    }
    for(int i = 0; i < wordList.size(); i++)        //将只有1个字符不同的word连接
    {
        for(int j = i + 1; j < wordList.size(); j++)
        {
            if(connect(wordList[i], wordList[j]))     //如果相差1个字符，则进行相连
            {
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    }
}
//广度优先遍历图
int BFS_graph(string &beginWord, string &endWord,
              map<string, vector<string> > &graph)
{
    queue<pair<string, int> > Q;           //<顶点,步数>
    set<string> visit;                     //记录已访问的顶点
    Q.push(make_pair(beginWord, 1));       //添加起始点，步数为1
    visit.insert(beginWord);               //记录
    while(!Q.empty())
    {
        string node = Q.front().first;     //取队列头部节点和步数
        int step = Q.front().second;
        Q.pop();                           //弹出头部节点
        if(node == endWord)
            return step;

        const vector<string> &neighbors = graph[node];  //取node的全部邻接点
        for(int i = 0; i < neighbors.size(); i++)       //将未添加的相邻节点添加到队列
        {
            if(visit.find(neighbors[i]) == visit.end()) //如果没有
            {
                Q.push(make_pair(neighbors[i], step + 1));//当前步数加1
                visit.insert(neighbors[i]);             //记录
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
