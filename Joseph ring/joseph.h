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



//Ӧ���ǲ���Ҫ��������ʵ��ѭ�����еĲ�����Ŀǰ���������漰�����е����²������

class Joseph{

//typedef struct element element;


public:
	Joseph(int value);
	int calc(int index,int M);    //����ÿһ����Ҫ��̭��index
	void clean(int index,int &step);   //�����Ҫ��̭��
	bool check(int num);     //����Ƿ��˳�
	void func(int M,int num);// ���ĺ�����M�Ǽ������
	bool IsLegal(size_t Index); //�ж�Ԫ�غϷ���
	int add(int& Index);    //�Ϸ���+1
	void print();
private:
	vector<element> _arr;
	vector<int> _res;
	int N;
	

};      






#endif