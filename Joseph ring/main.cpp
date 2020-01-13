
//算法——探讨约瑟夫环问题
//n个人围成一圈（编号从1到n），从第1个人开始报数，报到m的人出列，从下一个人再重新报数，报到m的人出列，如此下去，直至所有人都出列。求最后一个出列的人的编号。
//N=6 M=5 开始：1 2 3 4 5 6     结果:5 4 6 2 3 1


//重点是：每一次剔除的元素的index怎么确定？：利用循环队列去做







#include <iostream>
#include "joseph.h"
//using namespace std;



int main(){


    Joseph jos(6);
	jos.func(5);
    jos.print();
	system("pause");
	return 0;
}



