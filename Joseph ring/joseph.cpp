
#include "joseph.h"



Joseph::Joseph(int value)
{

	_arr.resize(value);
    N=value;

	 for(int i=0;i<value;++i){
	 	_arr[i].index=i+1;
		_arr[i].stu=Live;

	}

}


bool Joseph::check(int num){

	int count=0;
	for(int i=0;i<_arr.size();++i){

		if(_arr[i].stu==Live){
			++count;
		} 


	}
	if(count>num)
		return false;
	if(count==num)
		return true;

}


bool Joseph::IsLegal(size_t Index){
	if(_arr[Index-1].stu==Live)
		return true;
	return false;

}





//���add����ҲӦ�ÿ���ʣ��Ԫ�ص�״̬

int Joseph::add(int& Index){  //6 ---��1
	
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
	
	//step���ܵ�����++��Ҫ�Ƚ����ж�
   
	step=add(index);                              //ÿ��λ�õ�+1��������Ҫ��add()�ӿ�ȥ�滻
    while(_arr[step-1].stu==Die){
		int temp=add(step);
	}

}

void Joseph::print(){
	/*for(int i=0;i<_res.size();++i){
	cout<<_res[i]<<" ";
	} */

    //cout<<_res.back()<<endl;
    //N=6 M=5 ��ʼ��1 2 3 4 5 6     ���:5 4 6 2 3 1
    vector<int>v(100);
	for(int i=0;i<_res.size();++i){
		v[ _res[i] ]++;	
	}
	int j=0;
	for(j=1;j<=N;++j){
		if(v[j]==0){
			cout<<j<<" ";
			continue;
		}
		
	}

}

int Joseph::calc(int index,int M){  //6,5--->4     //ȷ����һ��Ҫɱ�����˵�λ��

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

void Joseph::func(int M,int num){   //num�������������

	//��Ϸ��ʼֱ��ֻʣ��һ���˴�����
	int _count=N-num;
    int _step=1;    //��һ�ֱ����ĵ�һ����
	int _index=0; 
	int N=_arr.size();
    int tmp=M;
		//N=6 M=5 ��ʼ��1 2 3 4 5 6     ���:5 4 6 2 3 1
		//41 ��3   tip�������±��Ǵ�0��ʼ����Ӧ��index+1;
		
	//123456789     2 4 6 8 

	//Bug: ���˵M=1
	while(M<N && _count<=1){     //ѭ��������num������Ҳ�й�ϵ
		  clean(M,_step);
		  //2468   369
		  M=M+tmp;  
		  ++_count;
	     	
	}


   while(!check(num)){
		
	    _index=calc(_step,tmp);  //Ԥ�ڣ�_index=4    _step=6 ,tmp=5 
		clean(_index,_step);     //_step=1

	}

}