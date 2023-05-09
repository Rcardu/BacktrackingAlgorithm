#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#endif
#include"IncrementTheSubsequence.h"
#include"PermutationQuestions.h"
using namespace std;

void IncrementTheSubsequenceFormat();//递增子序列
void PermutationQuestionsFormat();//所有排列数

//递增子序列
void IncrementTheSubsequenceFormat(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(int i=0;i<N;i++)cin>>nums[i];
    IncrementTheSubsequence obj;
    vector<vector<int>>vec=obj.IncrementTheSubsequence_feel(nums);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}
//所有排列数
void PermutationQuestionsFormat(){
    int N;
    cin>>N;
    vector<int>nums(N);
    for(int i=0;i<N;i++)cin>>nums[i];
    PermutationQuestions obj;
    vector<vector<int>>vec=obj.PermutationQuestions_feel(nums);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}