#include <iostream>
#include <cmath>
using namespace std;
struct Node{
	int No;
	Node * next;
	Node * forword;
};
class Schedule{
private:
	Node * Head;
	int num;									//柱面数量
	int Loc;									//当前柱面位置
public:	
	Schedule();
	~Schedule();
	void create();								//创建链表
	void FIFO();								//先来先服务算法
	void LOOK();								//电梯调度算法

};
Schedule::Schedule(){
	Head=new Node;
	Head->next=NULL;
	Head->forword=NULL;
	int num;
	cout<<"请输入柱面号数量：";
	cin>>num;
	this->num=num;
	cout<<endl;
	cout<<"请输入当前柱面位置：";
	int Loc;
	cin>>Loc;
	this->Loc=Loc;
	cout<<endl;
}
Schedule::~Schedule(){
	Node * p,* q;
	p=Head;
	q=p->next;
	while(q){
		delete p;
		p=q;
		q=q->next;
	}
	delete p;
	delete q;
}
void Schedule::create(){ 	
	Node * p;
	p=Head;
	for(int i=1;i<num;i++){
		Node * q=new Node;
		q->next=p->next;
		p->next=q;
		q->forword=p;
		p=q;
	}
	cout<<"请输入柱面访问请求序列：";
	p=Head;
	for(i=0;i<num;i++){
		cin>>p->No;
		p=p->next;
	}
}
void Schedule::FIFO(){
	int Sum=0;							//移动臂移动柱面总数
	int Last=Loc;						//上一个柱面号
	Node * p=Head;
	cout<<"访问顺序为：";
	for(int i=0;i<num;i++){
		cout<<p->No<<' ';
		Sum+=abs(Last-p->No);
		Last=p->No;
		p=p->next;
	}
	cout<<endl;
	cout<<"移动臂柱面总数："<<Sum<<endl;
}
void Schedule::LOOK(){
	Node * p=Head;											
	Node * q;				
	for(int i=1;i<num;i++){
		Node * m=p;
		for(int j=0;j<num-i;j++){
			q=m->next;
			if(m->No>q->No){
				Node * s=new Node;
				s->No=m->No;
				m->No=q->No;
				q->No=s->No;
			}
			m=q;
		}
	}	
	int choice;
	do{		
		cout<<"1. 磁头向柱面号增大的方向移动"<<endl;
		cout<<"2. 磁头向柱面号减小的方向移动"<<endl;
		cout<<"3. 退出 "<<endl;
		cin>>choice;
		if(choice==1){
			int sum=0;
			int Last=Loc;
			cout<<"访问顺序为：";
			for(p=Head;p->next!=NULL;p=p->next){
				if(p->No<Loc&&p->next->No>=Loc){
					break;
				}
			}
			q=p;
			p=p->next;
			while(p){
				cout<<p->No<<' ';
				sum+=abs(Last-p->No);
				Last=p->No;
				p=p->next;
			}
			while(q){
				cout<<q->No<<' ';
				sum+=abs(Last-q->No);
				Last=q->No;
				q=q->forword;
			}
			cout<<endl;
			cout<<"移动臂移动柱面总数："<<sum<<endl<<endl;
		}
		else if(choice==2){
			int sum=0;
			int Last=Loc;
			cout<<"访问顺序为：";
			for(p=Head;p->next!=NULL;p=p->next){
				if(p->No<Loc&&p->next->No>=Loc){
					break;
				}
			}
			q=p;
			while(p){
				cout<<p->No<<' ';
				sum+=abs(Last-p->No);
				Last=p->No;
				p=p->forword;
			}
			q=q->next;
			while(q){
				cout<<q->No<<' ';
				sum+=abs(Last-q->No);
				Last=q->No;
				q=q->next;
			}
			cout<<endl;
			cout<<"移动臂移动柱面总数："<<sum<<endl<<endl;
		}
	else if(choice==3)
			break;
		}
	while(choice!=3);
}	
void Run_QUDONG(){
	cout<<"--------------驱动调度的管理-----------------"<<endl;
	Schedule A;
	A.create();
	int choice;
	do{
		cout<<"			1.先来先服务算法			"<<endl;
		cout<<"			2.电梯算法					"<<endl;
		cout<<"			3.退出						"<<endl;
		cin>>choice;
		system("cls");
		switch(choice){
			case 1:
				cout<<"-------------先来先服务算法----------------"<<endl;
				A.FIFO();
				break;
			case 2:
				cout<<"--------------电梯算法-----------------"<<endl;
				A.LOOK();
				break;
			case 3:
				break;
			default:
				cout<<"输入不符合要求！"<<endl;
		}
	}
	while(choice!=3);
}
