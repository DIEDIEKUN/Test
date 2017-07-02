
//FCFS. SJF .HRRF模拟作业调度
#include <iostream>
#include <String>
using namespace std;
struct Project{
	string Name;
	int Arrvial_Time;					//到达时间
	int Run_Time;						//运行时间
	float Answer;						//响应比
	Project * next;
};
class Manager{
	private:
		Project * Head;
		int num;	
		float Turnover_Time;
		float Dai_Quan;					//作业数量
	public:
		Manager(){
			Head=new Project;
			Head->next=NULL;
		}
		~Manager(){
			Project * p;
			while(Head){
				p=Head;
				Head=Head->next;
				delete p;
			}
			Head=NULL;
		}
		void Set_num(int num);
		void Create();				//输入作业
		void HRRF();				//响应比高者
		void FCFS();				//先来先服务
};
void Manager::Set_num(int num){
	this->num=num;
}
void Manager::Create(){
	int i;
	int a;
	Project * p,* s;
	p=Head;
	cout<<"作业数量：";
	cin>>a;
	Set_num(a);
	cout<<endl;
	cout<<"请依次输入元素值：作业名，到达时刻，运行时长"<<endl;
	for(i=1;i<=num;i++){
		s=new Project;
		cin>>s->Name;
		cin>>s->Arrvial_Time;
		cin>>s->Run_Time;
		s->next=p->next;
		p->next=s;
		p=s;
	}
}
void Manager::FCFS(){						//先来先服务调度
	Project * p;
	for(int i=1;i<num;i++){						//冒泡排序（到达时间排序）
		Project * s=new Project;
		for(int k=0;k<num-i;k++){
			p=Head->next;
			if(	p->Arrvial_Time>p->next->Arrvial_Time){
				s->Arrvial_Time=p->Arrvial_Time;
				s->Name=p->Name;
				p->Arrvial_Time=p->next->Arrvial_Time;
				s->Run_Time=p->Run_Time;
				p->Name=p->next->Name;
				p->Run_Time=p->next->Run_Time;
				p->next->Arrvial_Time=s->Arrvial_Time;
				p->next->Name=s->Name;
				p->next->Run_Time=s->Run_Time;
			}
			p=p->next;
			//cout<<"change"<<endl;
		}
		delete s;
	}
	cout<<"作业名称    开始时刻    完成时刻    周转时间   带权周转时间"<<endl;
	p=Head->next;
	float sum=0;//所有作业运行时间之和
	float Over_Time=0;//完成时刻 or开始时刻
	float Dai_Quan=0;
	float Turnover_Time=0;
	Project * s=Head;
	for(i=1;i<=num;i++){
		sum+=p->Run_Time;
		if(i==1){
			Over_Time=p->Arrvial_Time+p->Run_Time;
			cout<<p->Name<<'\t'<<p->Arrvial_Time<<'\t'<<Over_Time<<'\t'<<p->Run_Time<<'\t'<<'1'<<endl;
		}
		else{
			cout<<p->Name<<'\t'<<Over_Time<<'\t';
			Over_Time+=p->Run_Time;
			Turnover_Time=sum-(p->Arrvial_Time-Head->next->Arrvial_Time);
			Dai_Quan=Turnover_Time/p->Run_Time;
			cout<<Over_Time<<'\t'<<Turnover_Time<<'\t'<<Dai_Quan<<endl;
		}
		p=p->next;
	}
}
void Manager::HRRF(){              //响应比高者调度算法
	Project * p;
	for(int i=1;i<num;i++){						//冒泡排序（到达时间排序）,
		Project * s=new Project;
		for(int k=0;k<num-i;k++){
			p=Head->next;
			if(	p->Arrvial_Time>p->next->Arrvial_Time){
				s->Arrvial_Time=p->Arrvial_Time;
				s->Name=p->Name;
				p->Arrvial_Time=p->next->Arrvial_Time;
				s->Run_Time=p->Run_Time;
				p->Name=p->next->Name;
				p->Run_Time=p->next->Run_Time;
				p->next->Arrvial_Time=s->Arrvial_Time;
				p->next->Name=s->Name;
				p->next->Run_Time=s->Run_Time;
			}
			p=p->next;
			//cout<<"change"<<endl;
		}
		delete s;
	}
	cout<<"作业名称    开始时刻    完成时刻  被选中时响应比  周转时间   带权周转时间  "<<endl;
	p=Head->next;
	float sum=p->Run_Time;							//之前所有作业运行时间之和
	float Over_Time=p->Arrvial_Time+p->Run_Time;		//完成时刻 or开始时刻
	float Dai_Quan=0;
	float Turnover_Time=0;							//周转时间
	cout<<p->Name<<"   "<<p->Arrvial_Time<<"    "<<Over_Time<<"     "<<1<<"       "<<p->Run_Time<<"      "<<p->Run_Time/p->Run_Time<<endl;
	p->Answer=0;									//标志位，表示已被调度运行
	Project * q;
	string name;									//响应比最大的进程名字
	int j;
	for(i=1;i<num;i++){								//需要进行几次对于响应比的大小比较
		j=0;
		q=Head->next;
		while(j<num){								//计算链表中所有未被调度进程的响应比高者
			if(q->Answer!=0){
				q->Answer=(sum-(q->Arrvial_Time-p->Arrvial_Time))/q->Run_Time;
			}
			q=q->next;
			j++;
		}
		q=Head->next;								//找出响应比最大的进程的名字
		for(j=1;j<num;j++){
			name=q->Name;
			if(q->Answer<q->next->Answer){
				name=q->next->Name;	
			}
			q=q->next;
		}
		j=0;
		q=Head->next;
		while(j<num){								//输出
			if(name==q->Name){
				//cout<<"作业名称    开始时刻    完成时刻  被选中时响应比  周转时间   带权周转时间  "<<endl;
				cout<<q->Name<<"       "<<Over_Time<<"      ";
				Over_Time=Over_Time+q->Run_Time;
				cout<<Over_Time<<"        "<<q->Answer<<"         ";
				sum+=q->Run_Time;
				Turnover_Time=sum-(q->Arrvial_Time-p->Arrvial_Time);
				Dai_Quan=Turnover_Time/q->Run_Time;
				cout<<Turnover_Time<<"           "<<Dai_Quan<<endl;
				q->Answer=0;
				break;
			}
			else{
				q=q->next;
				j++;
			}
		}
	}

}
void Run_DIAODU(){
	cout<<"--------------模拟作业调度-----------------"<<endl;
	Manager A;
	A.Create();
	int choice;
	do{
		cout<<"			1.先来先服务算法			"<<endl;
		cout<<"			2.响应比高者算法			"<<endl;
		cout<<"			3.退出						"<<endl;
		cin>>choice;
		system("cls");
		switch(choice){
			case 1:
				cout<<"-------------先来先服务算法----------------"<<endl;
				A.FCFS();
				break;
			case 2:
				cout<<"--------------响应比高者算法-----------------"<<endl;
				A.HRRF();
				break;
			case 3:
				break;
			default:
				cout<<"输入不符合要求！"<<endl;
		}
	}
	while(choice!=3);
}
