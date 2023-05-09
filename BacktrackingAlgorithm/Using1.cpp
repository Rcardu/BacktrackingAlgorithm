/*
 * @Description: 
 */
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<string>
#endif
#include"Combination.h"
#include"ThePhonenumberCom.h"

using namespace std;

void Combination_Format();//组合
void ThePhonenumberComFormat();//电话数字键


void Combination_Format(){
    int n,k;
    cin>>n>>k;

    Combination obj;
    obj.Combination_BackSum(n,k,0,1);
    for(int i=0;i<obj.result.size();i++){
        for(int j=0;j<obj.result[i].size();j++)
            cout<<obj.result[i][j]<<", ";
        cout<<endl;
    }
}

void ThePhonenumberComFormat(){
    string digits;
    cin>>digits;
    ThePhonenumberCom obj;
    obj.ThePhonenumberCom_Rec(digits,0);
    for(int i=0;i<obj.result.size();i++){
        cout<<obj.result[i]<<"  ";
    }
    
}