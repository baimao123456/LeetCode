/*
//126-词语阶梯2-保存搜索路径
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
    string node;      //搜索到的节点
    int parent_pos;   //前驱节点在队列中的位置
    int step;         //到达当前节点的步数
    Qitem(string node, int parent_pos, int step)
                : node(NULL), parent_pos(parent_pos),step(step){}
};
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
    int has_begin_word = 0;
    for(int i = 0; i < wordList.size(); i++)        //为每个节点创建一个邻接表
    {
        if(wordList[i] == beginWord)
            has_begin_word = 1;
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
        if(has_begin_word == 0 && connect(beginWord, wordList[i]))
            graph[beginWord].push_back(wordList[i]);
    }
}
//广度优先遍历图
void BFS_graph(string &beginWord, string &endWord,
              map<string, vector<string> > &graph,
              vector<Qitem> &Q,
              vector<int> &end_word_pos)
{
    map<string, int> visit;                     //记录已访问的顶点
    int min_step = 0;                           //达到end_word_pos的最小步数
    Q.push_back(Qitem(beginWord.c_str(), -1, 1));       //添加起始点，前驱为 -1，步数为1
    visit[beginWord] = 1;                       //记录经过的单词
    int front = 0;                              //对头指针为0，指向vector表示的队列头
    while(front != Q.size())
    {
        const string &node = Q[front].node;           //取队列头部节点和步数
        int step = Q[front].step;
        if(min_step != 0 && min_step < step)    //如果到达当前的步数大于最小步数，没必要走这个单词
            break;
        if(node == endWord)                     //如果到达endword，记录最小步数
        {
            min_step = step;
            end_word_pos.push_back(front);      //记录当前节点在队列中的位置
        }
        const vector<string> &neighbors = graph[node];     //取node的全部邻接点
        for(int i = 0; i < neighbors.size(); i++)          //将未添加的相邻节点添加到队列
        {
            if(visit.find(neighbors[i]) == visit.end() ||  //节点没有被访问或者另一条最短路径
               visit[neighbors[i]] == step + 1)
            {
                Q.push_back(Qitem(neighbors[i], front, step + 1));//记录前驱节点，并步数加1
                visit[neighbors[i]] = step + 1;                   //记录到达邻接点neighbors[i]的步数
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
        vector<int> end_word_pos;    //end_word在搜索队列中的位置
        BFS_graph(beginWord, endWord, graph, Q, end_word_pos);

        vector<vector<string> > result;      //最终的路径
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
