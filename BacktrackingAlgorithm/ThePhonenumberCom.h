/*
 * @Description: 
 */
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<string>
#endif
using namespace std;

class ThePhonenumberCom
{
private:
    /* data */
    const string letterMap[10]={
        "",//0
        "",//1
        "abc",//2
        "def",//3
        "ghi",//4
        "jkl",//5
        "mno",//6
        "pqrs",//7
        "tuv",//8
        "wxyz",//9
    };
    string s;
public:
    vector<string>result;
    /*给定⼀个仅包含数字 2-9 的字符串，返回所有它能表⽰的字母组合。*/
    void ThePhonenumberCom_Rec(string digits,int index);
};
/*给定⼀个仅包含数字 2-9 的字符串，返回所有它能表⽰的字母组合。
例如输入：23
                        集合abc取字母
            a：                 b:                  c:
        集合def取字母   集合def取字母           集合def取字母
    ad  ae  af          bd  be  bf              cd      ce      cf
1.确定递归函数参数及返回值：传入string digits,需要一个参数index来记录层数
使用字符串来保存单一结果，字符串数组来保存结果集合
srting s;
vector<string>results;
void ThePhonenumberCom_Rec(string digits,int index);
2.确定回溯函数终止条件：如果递归到指定深度，那么就将结果放入结果集中
if(s.size()==index){
    result.push_back(s);
    return;
}
3.确定单层遍历逻辑：
首先取index指向的数字，再找到对应的数字集，再对字符集进行循环
int degit=digits[index]-'0';
string letters=letterMap[degit];
for(int i=0;i<letters.size();i++){
    s.push_back(letters[i]);
    ThePhonenumberCom_Rec(digits,index+1);
    s.pop_back(letters[i]);
}
*/
void ThePhonenumberCom::ThePhonenumberCom_Rec(string digits,int index){
    if(digits.size()==index){
        result.push_back(s);
        return;
    }
    int digit=digits[index]-'0';//将输入的字符串数字转化为int类型的数字
    string letters=letterMap[digit];//获取第一个数字在集合中对应的字符串
    for(int i=0;i<letters.size();i++){//遍历字符串
        s.push_back(letters[i]);//进入单一结果
        ThePhonenumberCom_Rec(digits,index+1);//进入下一个数字
        s.pop_back();//回溯，从下一个字符开始
    }
}

