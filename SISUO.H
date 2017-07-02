#include<iostream>
using namespace std;
#include<String>
//���峣����ȷ����Դ����
//���������Զ���
//���̽ṹ�壬�ṹ�岿�ְ��������ƣ���Դ��new һ���ṹ�壩��ÿ����Դ�������������ܹ���Ҫ��Դ�� ��

#define a 3;
const int b=12;
#define c 14;
const int d=14;
struct Resource{							
	int Allocation;							//��ռ������
	int Claim;								//����Ҫ������
};
struct Process{
	string Name;
	Resource A;
	Resource B;
	Resource C;
	Resource D;
	int Sign;												//��־λ���ж��Ƿ񱻷�����Դ��
	Process * next;
};
class Lock{
	private:
		Process * Head;
		int num;											//��������
		int Available[4];									//ר�Ž������飬���������Դ����
		int ** head;
	public:
		Lock(){												//��ʼ��������ͷ���
			Head=new Process;
			Head->next=NULL;
			Available[0]=a;
			Available[1]=b;
			Available[2]=c;
			Available[3]=d;
		}
		void Create();										//��������
		void Input();										//��������
		void Need();										//���������Դ������Դ��
//		void Set();											//������ο�����Դ��
		void Assign(int);									//����
		int Find();										//Ѱ�ұ�����Ľ���
		int Output(){
			return num;
		}
};
void Lock::Create(){
	cout<<"���������������"<<endl;
	cin>>num;
	Process * p=Head;
	for(int i=1;i<num;i++){
		Process * q= new Process;
		q->next=p->next;
		p->next=q;
		p=q;
	}
	cout<<"�����ɹ�!"<<endl;
}
void Lock::Input(){
	cout<<"�밴��ʾ�����������ݣ�"<<endl;
	Process * p=Head;
	for(int i=0;i<num;i++){
		cout<<"������������ƣ�";
		cin>>p->Name;
		cout<<endl;
		cout<<"������A��Դ����ռ������������Ҫ������";
		cin>>p->A.Allocation;
		cin>>p->A.Claim;
		cout<<"������B��Դ����ռ������������Ҫ������";
		cin>>p->B.Allocation;
		cin>>p->B.Claim;
		cout<<"������C��Դ����ռ������������Ҫ������";
		cin>>p->C.Allocation;
		cin>>p->C.Claim;
		cout<<"������D��Դ����ռ������������Ҫ������";
		cin>>p->D.Allocation;
		cin>>p->D.Claim;
		p->Sign=0;
		p=p->next;
	}
	cout<<"��������ɹ���"<<endl;
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
			cout<<"����Դ��������Ŀ�����������룡"<<endl;
			Input();
		}
	}
	if(i==4){
		cout<<"Available���鸳��ֵ�ɹ���"<<endl;
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
int Lock::Find(){													//Ѱ�ұ��������
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
			cout<<"��ǰϵͳ����Σ��״̬��ֹͣ���У�"<<endl;
		//	return -1;
			exit(0);
	}
}
void Lock::Assign(int m){
//	cout<<"����˳��Ϊ��"<<endl;
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
	cout<<"----------����----------"<<endl;
	Lock A;
	A.Create();
	A.Input();
	A.Need();
	int num,n;
	num=A.Output();									//���Ʒ������
	cout<<"����˳��Ϊ��"<<endl;
	for(int i=0;i<num;i++){
		n=A.Find();
		A.Assign(n);
	}
}