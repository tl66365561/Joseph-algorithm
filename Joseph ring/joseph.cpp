
#include "joseph.h"



Joseph::Joseph(int value){
	_arr.resize(value);
	for(int i=0;i<value;++i){
		_arr[i].index=i+1;
		_arr[i].stu=Live;

	}


}


bool Joseph::check(){

	int count=0;
	for(int i=0;i<_arr.size();++i){

		if(_arr[i].stu==Live){
			++count;
		} 


	}
	if(count>1)
		return false;
	if(count==1)
		return true;

}


bool Joseph::IsLegal(size_t Index){
	if(_arr[Index-1].stu==Live)
		return true;
	return false;

}





//这个add操作也应该考虑剩余元素的状态

int Joseph::add(int& Index){  //6 ---》1
	
	int N=_arr.size();
	Index=++Index;
	if(Index>N){
		Index%=N;
	}

	while(_arr[Index-1].stu==Die){
		++Index;
		if(Index>N){
			Index%=N;
		}
	}
	return Index;
}

void Joseph::clean(int index,int &step){

	_arr[index-1].stu=Die;
	_res.push_back(index);
	
	//step不能单纯的++，要先进行判断
   
	step=add(index);                              //每个位置的+1操作都需要用add()接口去替换
    while(_arr[step-1].stu==Die){
		int temp=add(step);
	}

}

void Joseph::print(){
	for(int i=0;i<_res.size();++i){
		cout<<_res[i]<<" ";
	} 

}

int Joseph::calc(int index,int M){  //6,5--->4     //确定下一个要杀死的人的位置

int count=1;
int tmp=0;

while(1){
	  if(_arr[index-1].stu==Live){
	     tmp=add(index);                                
         ++count;                
    }

	  if(IsLegal(tmp) && count==M )
			break;
 }

	return index;

}

void Joseph::func(int M){

	//游戏开始直到只剩下一个人存活结束
	int _count=1;
    int _step=1;    //下一轮报数的第一个人
	int _index=0; 
	int N=_arr.size();
    int tmp=M;
		//N=6 M=5 开始：1 2 3 4 5 6     结果:5 4 6 2 3 1
		//41 ：3   tip：数组下标是从0开始，对应的index+1;
		
	while(M<N){
		  clean(M,_step);
		  ++_count;
		  M=M*_count;  
		}


   while(!check()){
		
	    _index=calc(_step,tmp);  //预期：_index=4    _step=6 ,tmp=5 
		clean(_index,_step);     //_step=1

	}

}