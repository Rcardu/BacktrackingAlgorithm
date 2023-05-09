#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#include<algorithm>
#endif
using namespace std;

/*给定⼀个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），
整数之间⽤ '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是
"0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 ⽆效的 IP 地址。
⽰例 1：
输⼊：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]
⽰例 2：
输⼊：s = "0000"
输出：["0.0.0.0"]
⽰例 3：
输⼊：s = "1111"
输出：["1.1.1.1"]
⽰例 4：
输⼊：s = "010010"
输出：["0.10.0.10","0.100.1.0"]
⽰例 5：
输⼊：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
提⽰：
0 <= s.length <= 3000
s 仅由数字组成*/
class ResetIPConfigNumbers
{
private:
    /* data */
    vector<string>result;//结果集
    void ResetIPConfigNumbers_A(string&s,int startIndex,int pointNum);//模块函数
    bool isValiid(string&s,int start,int end){//计算是否合法
        if(start>end)return false;
        if(s[start]=='0'&&start!=end)return false;//说明这个字符由0开头，不合法
        int num=0;
        for(int i=start;i<=end;i++){
            if(s[i]>'9'||s[i]<'0')return false;//若字符不在0-9之间则不合法
            num=num*10+(s[i]-'0');//提取字字符
            if(num>255){//如果大于255则不合法
                return false;
            }
        }
        return true;
    }
public:
    vector<string>ResetIPConfigNumbers_feel(string&s){
        result.clear();
        int pointNum=0;
        ResetIPConfigNumbers_A(s,0,pointNum);
        return result;
    }
   


};
/*1.递归参数及返回值：
传入字符串s，int startIndex来确定截取下标，int pointNum记录添加逗点的数量
vector<string>result;
void ResetIPConfigNumbers(string&s,int startIndex,int pointNum);
2.终止条件：pointNum代表逗点的数量，当其为3时说明分割为四个了，然后再判断剩下的是否合法
if(pointNum==3){
    if(isValid(s,startIndex,s.size()-1)){
        result.push_back(s);
    }
    return ;
}
3.单层逻辑：判断[startIndex,i]这个区间的字符串是否合法，合法就加上逗点，不合法就结束本层循环
递归调用时从i+2开始，因为原字符串中加入了逗点，当回溯时删掉此逗点即可
for(int i=startIndex;i<s.size();i++){
    if(isValid(s,startIndex,i)){
        s.insert(s.begin()+i+1,'.');
        pointNum++;
        ResetIPConfigNumbers(s,i+2,point);
        pointNum--;
        s.erase(s.begin()+i+1);
    }else break;
}*/
void ResetIPConfigNumbers::ResetIPConfigNumbers_A(string&s,int startIndex,int pointNum){
    if(pointNum==3){//若已经有三个逗点，说明分割成了四份，只需要判断最后一份是否合法
        if(isValiid(s,startIndex,s.size()-1)){
            result.push_back(s);
        }
        return;
    }
    for(int i=startIndex;i<s.size();i++){
        if(isValiid(s,startIndex,i)){//判断[startIndex,i]这个区间内的字符是否合法
            s.insert(s.begin()+i+1,'.');
            pointNum++;
            ResetIPConfigNumbers_A(s,i+2,pointNum);//进入下一组判断，因为加了逗点，所以从i+2的位置开始
            pointNum--;
            s.erase(s.begin()+i+1);//回溯，将已经加入的逗点删除
        }else break;//不合法，直接推出本层循环
    }
}