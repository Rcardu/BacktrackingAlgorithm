#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#endif
#include<unordered_map>
#include<map>
using namespace std;
/*给定⼀个机票的字符串⼆维数组 [from, to]，⼦数组中的两个成员分别表⽰飞机出发和降落
的机场地点，对该⾏程进⾏重新规划排序。所有这些机票都属于⼀个从 JFK（肯尼迪国际机
场）出发的先⽣，所以该⾏程必须从 JFK 开始。
提⽰：
如果存在多种有效的⾏程，请你按字符⾃然排序返回最⼩的⾏程组合。例如，⾏程
["JFK", "LGA"] 与 ["JFK", "LGB"] 相⽐就更⼩，排序更靠前
所有的机场都⽤三个⼤写字母表⽰（机场代码）。
假定所有机票⾄少存在⼀种合理的⾏程。
所有的机票必须都⽤⼀次 且 只能⽤⼀次。
⽰例 1：
输⼊：[["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
输出：["JFK", "MUC", "LHR", "SFO", "SJC"]
⽰例 2：
输⼊：[["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
输出：["JFK","ATL","JFK","SFO","ATL","SFO"]
解释：另⼀种有效的⾏程是 ["JFK","SFO","ATL","JFK","ATL","SFO"]。但是它⾃然排序更⼤更靠
后。*/
class Reschedule
{
private:
    /* data */
    unordered_map<string ,map<string ,int>>targets;
    bool Reschedule_back(int tickenNum,vector<string>&result);

public:
    vector<string>Reschedule_feel(vector<vector<string>>&tickets){
        targets.clear();
        vector<string>result;
        for(const vector<string>&vec:tickets){//将tickets中的所有字符串放到vec容器中
            targets[vec[0]][vec[1]]++;//再用targets来存放对应的string key和map<string ,int>默认为int 为1
            /*创建映射表：使起飞位置与降落位置对应，一个起飞位置可以对应多个降落位置*/
        }
        result.push_back("JFK");
        Reschedule_back(tickets.size(),result);
        return result;
    }
    


};
/*使用unorder_map<string ,map<string ,int>>targets来记录出发机场，以及到达的机场，如果到达的机场重复则用int标记
tickenNum来记录有多少个航班
unorder_map<string ,map<string ,int>>targets
bool Reschedule_back(int tickenNum,vector<string>&result)
for(const vector<string>&vec:tickenNum){
    targets[vec[0],vec[1]]++;
}
result.push_back("JFK");
返回最小行程，也就是走过每个机场即可，即航班数+1，当已经收集的机场数量==航班数+1，就说明找到了
if(result.size()==tickenNum+1){
    return true;
}
for(pair<const string,int>&target:targets[result[result.size()-1]]){
    if(target.second>0){
        result.push_back(target.first);
        target.second--;
        if(backtracking(tickenNum,result))return true;
        result.pop_back();
        target.second++;
    }
}*/
bool Reschedule::Reschedule_back(int tickenNum,vector<string>&result){
    if(result.size()==tickenNum+1){
        return true;
    }
    for(pair<const string,int>&target:targets[result[result.size()-1]]){ //将target按升序位置的第一个key对应的map放入target中遍历
        if(target.second>0){
            result.push_back(target.first);
            target.second--;
            if(Reschedule_back(tickenNum,result))return true;
            result.pop_back();
            target.second++;
        }
    }
    return false;
}