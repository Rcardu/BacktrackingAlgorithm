#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#endif
using namespace std;
/*解数独*/
class SolutionSudoku
{
private:
    bool backtracking(vector<vector<char>>&borad);
    /* data */
    //判断填入的数是否合法
    bool isValid(int row,int col,char val,vector<vector<char>>&borad){
        for(int i=0;i<9;i++){//判断一行里是否重复
            if(borad[row][i]==val)return false;
        }
        for(int j=0;j<9;j++){//判断一列里是否重复
            if(borad[j][col]==val)return false;
        }
        int startRow=(row/3)*3;//棋盘从（0，0）到（8，8），所以0-2都在第一行第一列,以此类推
        int startCol=(col/3)*3;
        //9宫格是否重复
        for(int i=startRow;i<startRow+3;i++){//从第一行开始
            for(int j=startCol;j<startCol+3;j++){//从第一列开始
                if(borad[i][j]==val)return false;
            }
        }
        return true;
    }
public:
    void SolutionSudoku_A(vector<vector<char>>&borad){
        if(backtracking(borad))cout<<"true";
        else cout<<"false";
    }
    


};
bool SolutionSudoku::backtracking(vector<vector<char>>&borad){
    for(int i=0;i<borad.size();i++){//遍历行
        for(int j=0;j<borad[i].size();j++){//遍历列
            if(borad[i][j]!='.')continue;
            for(char k='1';k<='9';k++){//(i,j)这个位置放k是否合适
                if(isValid(i,j,k,borad)){//判断合理性
                    borad[i][j]=k;
                    if(backtracking(borad))return true;
                    borad[i][j]='.';//回溯
                }
            }
            return false;
        }
    }
}
