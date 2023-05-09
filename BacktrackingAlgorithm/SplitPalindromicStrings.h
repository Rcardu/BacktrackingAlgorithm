/*
 给定⼀个字符串 s，将 s 分割成⼀些⼦串，使每个⼦串都是回⽂串。
返回 s 所有可能的分割⽅案。
⽰例:
输⼊: "aab"
输出:
[
 ["aa","b"],
 ["a","a","b"]
] 
 */
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#endif
using namespace std;

class SplitPalindromicStrings
{
private:
    /* data */
    vector<vector<string>>result;
    vector<string> path;
    void SplitPalindromicStrings_A(string&s,int startIndx);
    bool isPalindrome(string&s,int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            if(s[i]!=s[j])return false;
        }
        return true;
    }
public:
    vector<vector<string>>SplitPalindromicStrings_Show(string&s){
        result.clear();
        path.clear();
        SplitPalindromicStrings_A(s,0);
        return result;
    }
    

    
};
/*1.确定递归函数参数及返回值：
使用全局reslut来存放结果集，path来存放结果
传入字符串与切割下标
vector<vector<string>>result;
vector<string> path;
void SplitPalindromicStrings_A(string&s,int startIndx);
2.递归终止条件：当切割线到了最后一个位置，说明已经找到了此树枝上的所有回文子串
if(startIndex>=s.size()){
    result.push_back(path);
    return;
}
3.单层搜索逻辑：
for(int i=startIndex;i<s.size();i++){
    if(isPalindrome(s,startIndex,i)){
        string str=s.subter(startIndex,i-startIndex+1);
        path.push_bask(str);
    }else{
        continue;
    }
    SplitPalindromicStrings_A(s,i+1);
    path.pop_back();
}
*/
void SplitPalindromicStrings::SplitPalindromicStrings_A(string&s,int startIndx){
    if(startIndx>=s.size()){
        result.push_back(path);
        return;
    }
    for(int i=startIndx;i<s.size();i++){
        //判断回文字串
        if(isPalindrome(s,startIndx,i)){
            string str=s.substr(startIndx,i-startIndx+1);//复制回文字串
            path.push_back(str);
        }else{
            continue;
        }
        SplitPalindromicStrings_A(s,i+1);
        path.pop_back();
    }
}