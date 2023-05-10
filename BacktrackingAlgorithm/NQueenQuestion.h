#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#endif
using namespace std;
class NQueenQuestion
{
private:
    /* data */
    vector<vector<string>>result;
    void NQueenQuestion_A(int n,int row,vector<string>&chessboard);
    //棋盘是否合法，行，列，棋盘，棋盘大小
    bool isValid(int row,int col,vector<string>&chessboard,int n){
        //检查列
        for(int i=0;i<row;i++){
            if(chessboard[i][col]=='Q')return false;
        }
        //检查45°角
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(chessboard[i][j]=='Q')return false;
        }
        //检查135°角
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(chessboard[i][j]=='Q')return false;
        }
        return true;
    }
public:
    vector<vector<string>>NQueenQuestion_feel(int n){
        result.clear();
        vector<string>chessboard(n,string(n,'#'));
        NQueenQuestion_A(n,0,chessboard);
        return result;
    }


};
/*给定⼀个整数 n，返回所有不同的 n 皇后问题的解决⽅案。
每⼀种解法包含⼀个明确的 n 皇后问题的棋⼦放置⽅案，该⽅案中 'Q' 和 '.' 分别代表了皇后
和空位。
⽰例:
输⼊: 4
输出: [
 [".Q..", // 解法 1
 "...Q",
 "Q...",
 "..Q."],
n是棋盘的大小，row来记录到第几层了
vector<vector<string>>result;
void NQueenQuestion_A(int n,int row,vector<string>&chessboard)
if(row==n){
    result.push_back(chessboard);
    return;
}
for(int i=0;i<n;i++){
    if(isValid(row,i,chessboard)){
        chessboard[row][i]='Q';
        NQueenQuestion_A(n,row+1,chessboard);
        chessboard[row][i]='.';
    }
}*/
void NQueenQuestion::NQueenQuestion_A(int n,int row,vector<string>&chessboard){
    if(row==n){
        result.push_back(chessboard);
        return;
    }
    for(int i=0;i<n;i++){
        if(isValid(row,i,chessboard,n)){
            chessboard[row][i]='Q';
            NQueenQuestion_A(n,row+1,chessboard);
            chessboard[row][i]='#';
        }
    }
}
