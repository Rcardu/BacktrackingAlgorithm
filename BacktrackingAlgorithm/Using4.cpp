#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#endif
#include"Reschedule.h"
#include"NQueenQuestion.h"
#include"SolutionSudoku.h"
using namespace std;
void RescheduleFormat();//重新安排行程
void NQueenQuestionFormat();//N皇后
void SolutionSudokuFormat();//数独

//重新安排行程
void RescheduleFormat(){
    int N;
    cin>>N;
    vector<vector<string>>targets(N,vector<string>(2));
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            cin>>targets[i][j];
        }
    }
    Reschedule obj;
    vector<string>vec=obj.Reschedule_feel(targets);
    for(int i=0;i<vec.size();i++)cout<<vec[i]<<" ";
}
//N皇后
void NQueenQuestionFormat(){
    int N;
    cin>>N;
    NQueenQuestion obj;
    vector<vector<string>>vec=obj.NQueenQuestion_feel(N);
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            cout<<vec[i][j]<<endl;
        }
        cout<<endl;
    }
}
//数独
void SolutionSudokuFormat(){
    vector<vector<char>>chars(9,vector<char>(9,'.'));
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>chars[i][j];
        }
        if(getchar()=='\n')continue;
    }
    SolutionSudoku obj;
    obj.SolutionSudoku_A(chars);
}