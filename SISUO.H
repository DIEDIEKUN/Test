#include<iostream>
using namespace std;
#include<String>
//定义常量，确定资源数量
//进程数量自定义
//进程结构体，结构体部分包括：名称，资源（new 一个结构体）（每个资源的已有数量，总共需要资源数 ）

#define a 3;
const int b=12;
#define c 14;
const int d=14;
struct Resource{							
	int Allocation;							//已占有数量
	int Claim;								//所需要总数量
};
struct Process{
	string Name;
	Resource A;
	Resource B;
	Resource C;
	Resource D;
	int Sign;												//标志位，判断是否被分配资源过
	Process * next;
};
class Lock{
	private:
		Process * Head;
		int num;											//进程数量
		int Available[4];									//专门建立数组，保存可用资源数量
		int ** head;
	public:
		Lock(){												//初始化，创建头结点
			Head=new Process;
			Head->next=NULL;
			Available[0]=a;
			Available[1]=b;
			Available[2]=c;
			Available[3]=d;
		}
		void Create();										//创建链表
		void Input();										//输入数据
		void Need();										//求得所有资源还需资源数
//		void Set();											//计算初次可用资源数
		void Assign(int);									//分配
		int Find();										//寻找被分配的进程
		int Output(){
			return num;
		}
};
void Lock::Create(){
	cout<<"请输入进程数量："<<endl;
	cin>>num;
	Process * p=Head;
	for(int i=1;i<num;i++){
		Process * q= new Process;
		q->next=p->next;
		p->next=q;
		p=q;
	}
	cout<<"创建成功!"<<endl;
}
void Lock::Input(){
	cout<<"请按提示依次输入数据！"<<endl;
	Process * p=Head;
	for(int i=0;i<num;i++){
		cout<<"请输入进程名称：";
		cin>>p->Name;
		cout<<endl;
		cout<<"请输入A资源的已占有数量和总需要数量：";
		cin>>p->A.Allocation;
		cin>>p->A.Claim;
		cout<<"请输入B资源的已占有数量和总需要数量：";
		cin>>p->B.Allocation;
		cin>>p->B.Claim;
		cout<<"请输入C资源的已占有数量和总需要数量：";
		cin>>p->C.Allocation;
		cin>>p->C.Claim;
		cout<<"请输入D资源的已占有数量和总需要数量：";
		cin>>p->D.Allocation;
		cin>>p->D.Claim;
		p->Sign=0;
		p=p->next;
	}
	cout<<"数据输入成功！"<<endl;
	p=Head;
	for(i=0;i<num;i++){
		Available[0]-=p->A.Allocation;
		Available[1]-=p->B.Allocation;
		Available[2]-=p->C.Allocation;
		Available[3]-=p->D.Allocation;
		p=p->next;
	}
	for(i=0;i<4;i++){
		if(Available[i]<0){
			cout<<"有资源超过总数目，请重新输入！"<<endl;
			Input();
		}
	}
	if(i==4){
		cout<<"Available数组赋初值成功！"<<endl;
	}
}
void Lock::Need(){
	head=new int*[num];
	for(int i=0;i<num;i++){
		head[i]=new int[4];
	}
	Process * p=Head;
	for(i=0;i<num;i++){
		head[i][0]=p->A.Claim-p->A.Allocation;
		head[i][1]=p->B.Claim-p->B.Allocation;
		head[i][2]=p->C.Claim-p->C.Allocation;
		head[i][3]=p->D.Claim-p->D.Allocation;
		p=p->next;
	}
}
int Lock::Find(){													//寻找被分配进程
	int j=0;
	Process * p=Head;
	for(int i=0;i<num;i++,p=p->next){
		if(p->Sign==1){
			continue;
		}
		else{
			if(Available[0]>=head[i][0]&&Available[1]>=head[i][1]&&Available[2]>=head[i][2]&&Available[3]>=head[i][3]){
				p->Sign=1;
				return i;
				break;
			}
		}
	}
	if(i==num){
			cout<<"当前系统处于危险状态，停止运行！"<<endl;
		//	return -1;
			exit(0);
	}
}
void Lock::Assign(int m){
//	cout<<"调用顺序为："<<endl;
	int j=0;
	Process * q=Head;
	while(j<num){
		if(j==m){
			cout<<q->Name<<endl;
			Available[0]+=q->A.Allocation;
			Available[1]+=q->B.Allocation;
			Available[2]+=q->C.Allocation;
			Available[3]+=q->D.Allocation;
//			cout<<"KK";
			break;
		}
		else{
			q=q->next;	
			j++;
		}
	}
}
void Run_SISUO(){
	cout<<"----------死锁----------"<<endl;
	Lock A;
	A.Create();
	A.Input();
	A.Need();
	int num,n;
	num=A.Output();									//控制分配次数
	cout<<"调用顺序为："<<endl;
	for(int i=0;i<num;i++){
		n=A.Find();
		A.Assign(n);
	}
}
