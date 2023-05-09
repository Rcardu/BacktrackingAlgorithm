/*
 * @Description: 
 */
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#endif
#include<unordered_set>
using namespace std;
/*给定⼀个整型数组, 你的任务是找到所有该数组的递增⼦序列，递增⼦序列的长度⾄少是
2。
⽰例:
输⼊: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
说明:
给定数组的长度不会超过15。
数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的⼀种情况。*/
class IncrementTheSubsequence
{
private:
    /* data */
    vector<int>path;
    vector<vector<int>>result;
    void IncrementTheSubsequence_A(vector<int>&nums,int startIndex);
public:
    vector<vector<int>>IncrementTheSubsequence_feel(vector<int>&nums){
        path.clear();
        result.clear();
        IncrementTheSubsequence_A(nums,0);
        return result;
    }


};
/*同一层不能使用重复的数
vector<int>path;
vector<vector<int>>result;
void IncrementTheSubsequence_A(vector<int>&nums,int startIndex);
因为递归调用再for循环内，而需要查找所有情况，所以只需要保证所收集的集合大于2即可
if(path.size()>1){
    result.push_back(path);
}
单层搜索逻辑：
unordered_set<int>uset;
for(int i=startIndex;i<nums.size();i++){
    if((!path.empty()&&nums[i]<path.back()||uset.find(nums[i])!=uset.end()){
        continue;
    }
    uset.insert(nums[i]);//记录这个元素再本层用过了，本层后面在不能用了
    path.push_back(nums[i]);
    IncrementTheSubsequence_A(nums,i+1);
    path.pop_back();
}*/
void IncrementTheSubsequence::IncrementTheSubsequence_A(vector<int>&nums,int startIndex){
    if(path.size()>1){
        result.push_back(path);
        //这里不返回，因为还要在path中插入满足条件的集合
    }
    unordered_set<int>uset;
    for(int i=startIndex;i<nums.size();i++){//uset.find()寻找uset容器中的值，找到了就返回指向这个值的正向迭代器，否则返回end()
        if((!path.empty()&&nums[i]<path.back())||uset.find(nums[i])!=uset.end()){
            continue;
        }
        path.push_back(nums[i]);
        IncrementTheSubsequence_A(nums,i+1);
        path.pop_back();
    }
}