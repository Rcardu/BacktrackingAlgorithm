/*
 * @Description: 
 */
#ifndef _BASESMOOTHINGALGORITHM_H_
#define _BASESMOOTHINGALGORITHM_H_
#include<iostream>
#include<vector>
#endif

using namespace std;
/*给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。*/
class Combination
{
private:
    /* data */
    vector<int>path;
public:
    vector<vector<int>>result;
    /*回溯求组合*//*组合问题再剪剪枝*/
    void Combination_Back(int n,int k,int startIndex);
    /*组合总和*/
    void Combination_BackSum(int targetSum,int k,int sum,int startIndex);

    

};
/*1.递归函数的返回值及参数：两个全局变量，一个用来存放符合条件的单一结果，一个用来存放符合条件的集合
vector<vector<int>>result;//存放集合
vector<int>path;//单一结果
传入参数n与k，还需要一个startIndex参数用来记录在本层递归中集合从哪里开始遍历
void Combination_Back(int n,int k,int startIndex);
2.回溯函数终止条件：
当path这个数组的大小达到k，那么就说明找到了一个子集大小为k的集合
if(path.size()==k){
    result.push_back(path);
    return ;
}
3.单层搜索过程：使用for来进行横向遍历，使用递归来进行纵向查找
for(int i=stratIndex;i<=n;i++){
    path.push_back(i);//处理结点
    Combination_Back(n,k,i+1);//递归：控制对树的纵向遍历
    path.pop_back();//回溯
}*/
void Combination::Combination_Back(int n,int k,int startIndex){
    if(path.size()==k){
        result.push_back(path);
        return;
    }
    /*
    for(int i=startIndex;i<=n;i++){
        path.push_back(i);
        Combination_Back(n,k,i+1);
        path.pop_back();
    }
    枝剪前
    */
   for(int i=startIndex;i<=n-(k-path.size())+1;i++){
    path.push_back(i);
    Combination_Back(n,k,i+1);
    path.pop_back();
   }
    
}
/*组合问题再剪剪枝,
1.已经选择的元素个数path.size()
2.还需要选择的元素个数k-path.size()
3.在集合n中至多要从该起始位置：n-(k-path.size())+1,开始遍历*/

/*组合总和
1.确定递归函数参数：一个数组来存放单一结果，一个数组来存放结果集合
传入targetSum目标和，k要求的个数的集合，sum已经收集的元素的总和，也就是path里元素的总和，startIndex为下一层for循环的起始位置
void Combination_BackSum(int targetSum,int k,int sum,int startIndex);
2.回溯函数终止条件：当到达最后k层时，开始判断次元素是否满足目标值，满足则收集
if(path.size()==k){
    if(sum==targetSum){
        result.push_back(path);
    }
    return ;
}
因为在固定的九个数，中寻找，并且9个数从1-9，所以for使用i<=9循环
for(int i=startIndex;i<=9;i++){
    sum+=i;
    path.push_back(i);
    Combination_BackSum(targetSum,k,sum,i+1);
    path.pop_back();
    sum-=i;
}*/
void Combination::Combination_BackSum(int targetSum,int k,int sum,int startIndex){
    if(sum>targetSum)return;//枝剪，若和已经大于总和了，就不需要了
    if(path.size()==k){//当已经收集到三个数时，判断总和，否则返回，也就是不会收集到三个数以上的组合 
        if(targetSum==sum)result.push_back(path);
        return;
    }
    for(int i=startIndex;i<=9-(k-path.size())+1;i++){//若剩余的数已经不能再凑成三个数了，那么就进行枝剪
        sum+=i;
        path.push_back(i);
        Combination_BackSum(targetSum,k,sum,i+1);
        path.pop_back();
        sum-=i;
    }
}