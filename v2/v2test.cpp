#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "gagakill.hpp"
using namespace std;

std::vector<std::vector<std::string>> correct_group(23000, std::vector<std::string>(150)); // 二维数组，存储正确的序列
// string false_group [MAX]={""};            
std::vector<std::string> false_group(1000); //一维数组：用于储存错误的序列
int c_len = 0, f_len = 0; // 记录correct_group,false_group已储存字符串数量
int ninput = 0;

int main(){
    ifstream fo;
    fo.open("dna.txt");
    string data;
    std::vector<std::string> input(1003000);
    bool nrow = false;
    ninput = 0;
    while (!fo.eof())
    {
        fo >> data;
        if (nrow == true)
        {
            input[ninput] = data;
            ninput++;
        }
        nrow = !nrow;
    }
    classify(input.data(),ninput );
    cout<<"共找到 "<<f_len<<" 个错误DNA序列: \n"<<endl;
    correctionEnd();

}