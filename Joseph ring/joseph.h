#ifndef _JOSEPH_H_
#define _JOSEPH_H_

#define MaxSize 100

#include <iostream>
using namespace std;
#include <vector>


enum status{
	Die,    //0
	Live    //1
};

typedef struct element{

	size_t index;
	enum status stu;

}element;



//应该是不需要先完整的实现循环队列的操作，目前分析并不涉及到队列的重新插入操作

class Joseph{

//typedef struct element element;


public:
	Joseph(int value);
	int calc(int index,int M);    //计算每一轮需要淘汰的index
	void clean(int index,int &step);   //清除需要淘汰项
	bool check(int num);     //检查是否退出
	void func(int M,int num);// 核心函数；M是间隔数字
	bool IsLegal(size_t Index); //判断元素合法性
	int add(int& Index);    //合法的+1
	void print();
private:
	vector<element> _arr;
	vector<int> _res;
	int N;
	

};      






#endif