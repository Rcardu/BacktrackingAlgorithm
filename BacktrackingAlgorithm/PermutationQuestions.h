/*
 * @Description: 
 */
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#endif
using namespace std;
/*给定⼀个 没有重复 数字的序列，返回其所有可能的全排列。
⽰例:
输⼊: [1,2,3]
输出:
[
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
]
*/
class PermutationQuestions
{
private:
    /* data */
    vector<vector<int>>reslut;
    vector<int>path;
    void PermutationQuestions_A(vector<int>&nums,vector<bool>&used);
public:
    vector<vector<int>>PermutationQuestions_feel(vector<int>&nums){
        path.clear();
        reslut.clear();
        vector<bool>used(nums.size(),0);
        PermutationQuestions_A(nums,used);
        return reslut;
    }
    

};
/*因为在同一层可以重复使用了，但是在同一列不允许，所以需要一个使用标记bool used
vector<vector<int>>reslut;
vector<int>path;
void PermutationQuestions(vector<int>&nums,vector<bool>&used)
当path的大小与nums的大小一样时，说明找到了一个全排列，此时收集结果即可
if(path.size()==nums.size()){
    result.push_back(path);
    return;
}
3.单层逻辑：
for(int i=0;i<nums.size();i++){
    if(used[i]==true)continue;
    used[i]=true;
    path.push_back(nums[i]);
    PermutationQuestions(nums,used);
    path.pop_back();
    used[i]==false;
}*/
void PermutationQuestions::PermutationQuestions_A(vector<int>&nums,vector<bool>&used){
    if(path.size()==nums.size()){
        reslut.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false)continue;
        if(used[i]==false){
            used[i]=true;
            path.push_back(nums[i]);
            PermutationQuestions_A(nums,used);
            path.pop_back();
            used[i]=false;
        }
    }
}
