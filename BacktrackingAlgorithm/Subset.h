#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#endif
using namespace std;
/*给定⼀组不含重复元素的整数数组 nums，返回该数组所有可能的⼦集（幂集）。
说明：解集不能包含重复的⼦集。
⽰例:
输⼊: nums = [1,2,3]
输出:
[[3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[]]*/
class Subset
{
private:
    /* data */
    vector<int>path;
    vector<vector<int>>result;
    void Subset_A(vector<int>&nums,int startIndex);//实现模块
public:
    vector<vector<int>>Subset_feel(vector<int>&nums){
        path.clear();
        result.clear();
        Subset_A(nums,0);
        return result;
    }
   

};
/*result为结果集合，path为子集
vector<int>path;
vector<vector<int>>result;
void Subset_A(vector<int>&nums,int startIndex);
当到达叶子结点时，也就是剩余集合为空就可以返回了
if(stratIndex>=nums.size())return;
单层搜索逻辑：
for(int i=startIndex;i<nums.size();i++){
    path.push_back(nums[i]);
    Subset_A(nums,i+1);
    path.pop_back();
}*/
void Subset::Subset_A(vector<int>&nums,int startIndex){
    result.push_back(path);//直接收集结果
    if(startIndex>=nums.size())return;
    for(int i=startIndex;i<nums.size();i++){
        path.push_back(nums[i]);
        Subset_A(nums,i+1);
        path.pop_back();
    }
}