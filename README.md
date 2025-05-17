# DNA读段纠错

[![Page Views Count](https://badges.toozhao.com/badges/01JVDW9QFDMFT9AS0HZK1EHQHE/green.svg)](https://badges.toozhao.com/stats/01JVDW9QFDMFT9AS0HZK1EHQHE "Get your own page views count badge on badges.toozhao.com")

本仓库为HZAU的C++程序设计小组 **CppGagaKill**的课题项目。

该项目主要解决DNA在测序仪器读段过程中错误读段的纠错。

本项目暂时只能解决单碱基发生替换的纠错，未来可考虑加入更多纠错类型。

如有疑问，欢迎issue.

## 使用方法

每一版包含头文件和源文件，需要自己在主函数中实现**FASTA**格式的读取，并存入**input**数组中。具体可参考**v2test.cpp**。

编译

`g++ v2test.cpp gagakill.cpp -o v2test`

## 生成测试用例

可使用**creatDNA**文件夹下的 `生成DNA.py` 程序生成用于测试的DNA序列，默认一行一条DNA。
