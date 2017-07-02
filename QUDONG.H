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
	int num;									//��������
	int Loc;									//��ǰ����λ��
public:	
	Schedule();
	~Schedule();
	void create();								//��������
	void FIFO();								//�����ȷ����㷨
	void LOOK();								//���ݵ����㷨

};
Schedule::Schedule(){
	Head=new Node;
	Head->next=NULL;
	Head->forword=NULL;
	int num;
	cout<<"�����������������";
	cin>>num;
	this->num=num;
	cout<<endl;
	cout<<"�����뵱ǰ����λ�ã�";
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
	cout<<"��������������������У�";
	p=Head;
	for(i=0;i<num;i++){
		cin>>p->No;
		p=p->next;
	}
}
void Schedule::FIFO(){
	int Sum=0;							//�ƶ����ƶ���������
	int Last=Loc;						//��һ�������
	Node * p=Head;
	cout<<"����˳��Ϊ��";
	for(int i=0;i<num;i++){
		cout<<p->No<<' ';
		Sum+=abs(Last-p->No);
		Last=p->No;
		p=p->next;
	}
	cout<<endl;
	cout<<"�ƶ�������������"<<Sum<<endl;
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
		cout<<"1. ��ͷ�����������ķ����ƶ�"<<endl;
		cout<<"2. ��ͷ������ż�С�ķ����ƶ�"<<endl;
		cout<<"3. �˳� "<<endl;
		cin>>choice;
		if(choice==1){
			int sum=0;
			int Last=Loc;
			cout<<"����˳��Ϊ��";
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
			cout<<"�ƶ����ƶ�����������"<<sum<<endl<<endl;
		}
		else if(choice==2){
			int sum=0;
			int Last=Loc;
			cout<<"����˳��Ϊ��";
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
			cout<<"�ƶ����ƶ�����������"<<sum<<endl<<endl;
		}
	else if(choice==3)
			break;
		}
	while(choice!=3);
}	
void Run_QUDONG(){
	cout<<"--------------�������ȵĹ���-----------------"<<endl;
	Schedule A;
	A.create();
	int choice;
	do{
		cout<<"			1.�����ȷ����㷨			"<<endl;
		cout<<"			2.�����㷨					"<<endl;
		cout<<"			3.�˳�						"<<endl;
		cin>>choice;
		system("cls");
		switch(choice){
			case 1:
				cout<<"-------------�����ȷ����㷨----------------"<<endl;
				A.FIFO();
				break;
			case 2:
				cout<<"--------------�����㷨-----------------"<<endl;
				A.LOOK();
				break;
			case 3:
				break;
			default:
				cout<<"���벻����Ҫ��"<<endl;
		}
	}
	while(choice!=3);
}