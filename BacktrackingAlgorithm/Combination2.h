/*
 * @Description: 
 */
/*给定⼀个⽆重复元素的数组 candidates 和⼀个⽬标数 target ，找出 candidates 中所有可以
使数字和为 target 的组合。candidates 中的数字可以⽆限制重复被选取。
所有数字（包括 target）都是正整数。解集不能包含重复的组合。
⽰例 1：
输⼊：candidates = [2,3,6,7], target = 7,
所求解集为：
[
 [7],
 [2,2,3]
]
⽰例 2：
输⼊：candidates = [2,3,5], target = 8,
所求解集为：
[
 [2,2,2,2],
 [2,3,3],
 [3,5]
]*/
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#endif
#include<algorithm>
using namespace std;
class Combination2
{
private:
    /* data */
    vector<int>path;
    vector<vector<int>>result;
    void Combination2_back_feel(vector<int>&candidates,int target,int sum,int startIndex);
    /*在给定数组中选取目标值的组合，可以重复使用数组里的数*/
public:
    vector<vector<int>>Combination2_back(vector<int>&candidates,int target){
        result.clear();
        path.clear();
        sort(candidates.begin(),candidates.end());//排序
        Combination2_back_feel(candidates,target,0,0);
        return result;
    }


};
/*在给定数组中选取目标值的组合，可以重复使用数组里的数
1. 确定递归函数参数及返回值，全局变量来存放结果集与结果
传入给定数组与目标和，使用int sum来记录当前组合的总和，int stratIndex来记录下次的取值位置
vector<int>path;
vector<vector<int>>result;
void Combination2_back(vector<int>&candidates,int target,int sum,int startIndex);
2.确定回溯函数终止条件：即当sum>target时不收集，直接返回，当sum=target时收集
if(sum>target)return;
if(sum==target){
    result.push_back(path);
    return;
}
3.确定单层搜索逻辑：startIndex从本身开始搜索，（因为可以重复使用）
for(int i=startIndex;i<candidates.size();i++){
    path.push_back(candidates[i]);
    sum+=candidates[i];
    Combination2_back(candidates,target,sum,i);
    sum-=candidates[i];
    path.pop_back();
}*/
void Combination2::Combination2_back_feel(vector<int>&candidates,int target,int sum,int startIndex){
    if(sum==target){
        result.push_back(path);
        return ;
    }
    for(int i=startIndex;i<candidates.size()&&candidates[i]+sum<=target;i++){
        path.push_back(candidates[i]);
        sum+=candidates[i];
        Combination2_back_feel(candidates,target,sum,i);
        sum-=candidates[i];
        path.pop_back();
    }
}