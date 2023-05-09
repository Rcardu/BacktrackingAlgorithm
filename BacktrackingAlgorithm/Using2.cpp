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
#include"Combination2.h"
#include"Combination3.h"
#include"SplitPalindromicStrings.h"
using namespace std;

void Combination2Format();//组合总和II
void Combination3Format();//组合总和III
void SplitPalinForamt();//判断回文字串的个数
//组合总和II
void Combination2Format(){
    int N,M;
    cin>>N>>M;
    vector<int>candidater(N);
    for(int i=0;i<N;i++)cin>>candidater[i];

    Combination2 obj;
    vector<vector<int>>vec=obj.Combination2_back(candidater,M);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}
//组合总和III
void Combination3Format(){
    int N,M;
    cin>>N>>M;
    vector<int>candidates(N);
    for(int i=0;i<N;i++)cin>>candidates[i];

    Combination3 ibj;
    vector<vector<int>>vec=ibj.Combination3_back(candidates,M);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}

void SplitPalinForamt(){
    string s;
    cin>>s;

    SplitPalindromicStrings obj;
    vector<vector<string>>vec=obj.SplitPalindromicStrings_Show(s);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
}