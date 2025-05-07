#ifndef GAGAKILL_H
 #define  GAGAKILL_H

#include <string>
#include <vector>

 int hamming(const std::string &a,const std::string &b); // 计算hamming距离函数
 std::string reverseDNA(const std::string &a);  // 反向互补DNA函数

 void classify(std::string input[], int size); // 对输入的DNA进行分类函数
 
 void correctionEnd();  // 最后纠错并输出函数

 extern std::vector<std::vector<std::string>> correct_group;
 extern std::vector<std::string> false_group;
 extern int c_len;
 extern int f_len;
 
 #endif