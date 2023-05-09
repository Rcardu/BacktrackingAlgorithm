#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#endif
/*给定⼀个数组 candidates 和⼀个⽬标数 target ，找出 candidates 中所有可以使数字和为
target 的组合。candidates 中的每个数字在每个组合中只能使⽤⼀次。
说明：
所有数字（包括⽬标数）都是正整数。
解集不能包含重复的组合*/
using namespace std;
class Combination3
{
private:
    /* data */
    vector<int>path;
    vector<vector<int>>result;
    void Combination3_back_feel(vector<int>&candidates,int target,int sum,int startIndex,vector<bool>&used);
public:
    vector<vector<int>>Combination3_back(vector<int>&candidates,int target){
        path.clear();
        result.clear();
        vector<bool>used(candidates.size(),0);
        sort(candidates.begin(),candidates.end());
        Combination3_back_feel(candidates,target,0,0,used);
        return result;
    }




};
/*区别在于有数组中有重复的数
1.确定递归函数参数及返回值：
加入一个bool used数组来标记在同一树枝上的元素是否被重复使用
vector<int>path;
vector<vector<int>>result;
void Combination3_back_feel(vector<int>&candidates,int target,int sum,int startIndex,vector<bool>&used);
2.终止条件：当总和相等时直接压入
if(target==sum){
    result.push_back(path);
    return;
}
3.单层搜索逻辑：如果candidates[i]=candidates[i-1]&&used[i-1]==false,那就说明前一个树枝使用了candidates[i-1]
此时for循环里就应该做continue操作。*/
void Combination3::Combination3_back_feel(vector<int>&candidates,int target,int sum,int startIndex,vector<bool>&used){
    if(target==sum){
        result.push_back(path);
        return;
    }
    for(int i=startIndex;i<candidates.size()&&sum+candidates[i]<=target;i++){
        if(i>0&&candidates[i]==candidates[i-1]&&used[i-1]==false){
            continue;
        }
        path.push_back(candidates[i]);
        sum+=candidates[i];
        used[i]=true;
        Combination3_back_feel(candidates,target,sum,i+1,used);
        used[i]=false;
        sum-=candidates[i];
        path.pop_back();
    }
}
