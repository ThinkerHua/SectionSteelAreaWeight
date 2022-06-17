# SectionSteelAW
 用于生成型钢单位面积或单位重量的动态链接库。详情参见"help.txt"文档。
 
 本项目是 https://github.com/ThinkerHua/SteelStructureCalculationTool.git 的内核重制版。
 原项目完全采用VB.net编写的，内存占用有点高。所以用C做一个动态链接库，期望能解决内存占用高的问题。
 
 未来将从原项目剥离出用户界面，用于进行外部数据交互，内核部分引用本DLL执行。