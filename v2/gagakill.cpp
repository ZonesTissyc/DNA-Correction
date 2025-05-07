#include<iostream>
#include<string>
#include<vector>
#include "gagakill.hpp"
using namespace std;

int hamming(const string &a,const string &b){        //函数接受两个string DNA序列 a和b
    int alen=a.length();                // 分别获取a,b序列的长度
    int blen=b.length();
    int hamming_num=0;                  // 初始化hamming距离为0
    if (alen!=blen || alen==0)          // 判断a,b长度是否相等,不相等或为空，返回异常值-1
    {
        return -1;
    }
    for(int i=0;i<alen;i++){            // 从左往右判断a,b序列的相同位置字符是否相同
        if(a[i]!=b[i]){
            hamming_num++;              // 发现一个不同，hamming距离+1
        }
    }
    return hamming_num;                 //返回hamming距离
    
}

// 单字符的互补函数
char complement(char s){
    char compstr;
    switch (s){
        case 'A': compstr='T';break;
        case 'G': compstr='C';break;
        case 'C': compstr='G';break;
        case 'T': compstr='A';break;
    }
    return compstr;
}

// 反向互补序列生成函数
string reverseDNA(const string &a){
    string b="";                    // 初始化b字符串为空
    int alen=a.length();            // 获取a序列长度
    
    // 从右往左，调用互补函数,将互补字符增加到b中
    for(int i=alen-1;i>=0;i--){       
        b+= complement(a[i]);
    }
    return b;
}

bool check(const string &a,const string &b)           // 函数定义：检查两个序列是否相同或者互补
{
    if (a == b) // 判断a与b是否完全相同
        return true;
    if (a.length() != b.length()) // 如果a与b长度不一样，一定不互补
        return false;
    for (int i = 0; i < a.length(); i++) // 遍历a的每一个字符

    {
        int j = b.length()  - 1 - i; // 根据i计算在序列b中对应的反向索引j
        char ca = a[i];
        char cb = b[j];
        if ((ca == 'A' && cb != 'T') || (ca == 'T' && cb != 'A') || (ca == 'C' && cb != 'G') || (ca == 'G' && cb != 'C')) // 判断a与b是否不满足反向互补
        {

            return false;
        }
    }
    return true;
}


void classify(string input[], int size) // 函数定义：对输入的DNA序列进行分类
{
    int i = 0;
    int j = 0;
    bool isCorrect = false;        // 假设当前此序列为假
    for (i; i < size; i++) // 外层循环，从0开始，遍历input数组
    {
        isCorrect = false;
        j = 0;
        // 用于分组数组的下标索引
        for (j = 0; j < size; j++) // 内层循环，从0开始，再次遍历input数组
        {
            if (input[j]!="" && i != j && check(input[i], input[j])) // 确保不与自身匹配，并调用check函数判断input[i]与input[j]是否相同或者互补
            {
                isCorrect = true;
                for (int m = 0; m < 23000; m++)
                {
                    if (correct_group[m][0] == "")
                    {
                        correct_group[m][0] = input[i];
                        break;
                    }
                    if (check(input[i], correct_group[m][0]) != true)
                    {
                        continue;
                    }

                    // 将当前序列input[i]放入当前分组的第一个位置
                    int k = 1;
                    while (correct_group[m][k] != "") // 当当前分组索引为k的位置不为空字符串，说明该位置已被占用，继续寻找下一个位置
                    {
                        k++;
                    }
                    // cout<<i<<' '<<j<<' '<<m<<' '<<k<<endl; //测试用
                    correct_group[m][k] = input[i]; // 将与input[i]相同或者互补的序列一一对应
                    input[i]="";
                    break;                          // 跳出存储循环
                }
                break;  // 跳出内层循环
            }
            // cout<<i<<' '<<j<<endl; 
        }

        if (isCorrect) // 如果此序列为真，correct_group的字符串数量+1
        {
            c_len++;
        }
        else
        {
            false_group[f_len] = input[i]; // 否则，该序列为假，并加入到false_group且该组数量加1
            f_len++;
        }
    }
}

void correctionEnd(){
    for (int i = 0; i < 1000; i++) // 依次调出错误数组的序列
    {
        if (false_group[i] == "")
            break;
        for (int j = 0; j < 23000; j++) // 再依次调出正确数组的序列
        {
            if (hamming(false_group[i], correct_group[j][0]) == 1)
            {
                cout << false_group[i] << "->" << correct_group[j][0] << endl; // 判断正序汉明距离为1就输出
            }
            else if (hamming(false_group[i], reverseDNA(correct_group[j][0])) == 1) // 判断反序汉明距离是否为1
            {
                cout << false_group[i] << "->" << reverseDNA(correct_group[j][0]) << endl; // 判断反序汉明距离为1就输出
            }
            else
            {
                continue;
            }
        }
    }
}


   
    