#include <iostream>
using namespace std;
class Page{
	private:	
		int num;  //设定页框个数
		int Num;  //设定页面数
	public:
		Page(){
			cout<<"请输入页框个数："<<endl;
			cin>>num;
			this->num=num;
			cout<<endl;
			cout<<"请输入页面个数："<<endl;
			cin>>Num;
			this->Num=Num;
		}
		void FIFO();
};
void Page::FIFO(){
	int s,i,j,m;
	float rate=0;
	int * Frame=new int[num];
	int * Page=new int[Num];
	cout<<"请输入页面访问顺序："<<endl;
	for(i=0;i<Num;i++){
		cin>>Page[i];
	}													//输入页面访问顺序
	for(i=0;i<num;i++){
		Frame[i]=-1;
	}													//给页框赋初值-1
	cout<<"----------------计算结果---------------"<<endl;
	for(i=0;i<Num;i++){
		for(j=0,s=0;j<num;j++){							// 遍历寻找页框有没有相同值，s=1表示有相同值
			if(Page[i]==Frame[j]){
				s=3;
				break;
			}
		}
		if(s==3){										//有相同值时输出的页框与上次不变
			for(m=0;m<num;m++){
				cout<<Frame[m]<<' ';		
			}	
			cout<<endl;
			continue;
		}
		for(j=0,s=2;j<num;j++){
			if(Frame[j]==-1){							//如果s=1，说明页框中有空位；s=3，说明页框已满
				s=1;
				break;
			}
		}
		if(s==1){
			Frame[j]=Page[i];
			for(m=0;m<num;m++){
				cout<<Frame[m]<<' ';		
			}	
			cout<<endl;
			rate++;
		}
		if(s==2){
			for(m=0;m<num-1;m++){
				Frame[m]=Frame[m+1];
			}
			Frame[num-1]=Page[i];
			for(m=0;m<num;m++){
				cout<<Frame[m]<<' ';
			}
			cout<<endl;
			rate++;
		}
	}
	float B=rate/Num;
	cout<<"缺页次数="<<rate<<endl;
	cout<<"缺页率="<<B<<endl;
}
void Run_YEMIAN(){
	cout<<"----------------FIFO页面替换算法----------------------"<<endl;
	Page A;
	A.FIFO();
}