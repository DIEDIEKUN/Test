
//FCFS. SJF .HRRFģ����ҵ����
#include <iostream>
#include <String>
using namespace std;
struct Project{
	string Name;
	int Arrvial_Time;					//����ʱ��
	int Run_Time;						//����ʱ��
	float Answer;						//��Ӧ��
	Project * next;
};
class Manager{
	private:
		Project * Head;
		int num;	
		float Turnover_Time;
		float Dai_Quan;					//��ҵ����
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
		void Create();				//������ҵ
		void HRRF();				//��Ӧ�ȸ���
		void FCFS();				//�����ȷ���
};
void Manager::Set_num(int num){
	this->num=num;
}
void Manager::Create(){
	int i;
	int a;
	Project * p,* s;
	p=Head;
	cout<<"��ҵ������";
	cin>>a;
	Set_num(a);
	cout<<endl;
	cout<<"����������Ԫ��ֵ����ҵ��������ʱ�̣�����ʱ��"<<endl;
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
void Manager::FCFS(){						//�����ȷ������
	Project * p;
	for(int i=1;i<num;i++){						//ð�����򣨵���ʱ������
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
	cout<<"��ҵ����    ��ʼʱ��    ���ʱ��    ��תʱ��   ��Ȩ��תʱ��"<<endl;
	p=Head->next;
	float sum=0;//������ҵ����ʱ��֮��
	float Over_Time=0;//���ʱ�� or��ʼʱ��
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
void Manager::HRRF(){              //��Ӧ�ȸ��ߵ����㷨
	Project * p;
	for(int i=1;i<num;i++){						//ð�����򣨵���ʱ������,
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
	cout<<"��ҵ����    ��ʼʱ��    ���ʱ��  ��ѡ��ʱ��Ӧ��  ��תʱ��   ��Ȩ��תʱ��  "<<endl;
	p=Head->next;
	float sum=p->Run_Time;							//֮ǰ������ҵ����ʱ��֮��
	float Over_Time=p->Arrvial_Time+p->Run_Time;		//���ʱ�� or��ʼʱ��
	float Dai_Quan=0;
	float Turnover_Time=0;							//��תʱ��
	cout<<p->Name<<"   "<<p->Arrvial_Time<<"    "<<Over_Time<<"     "<<1<<"       "<<p->Run_Time<<"      "<<p->Run_Time/p->Run_Time<<endl;
	p->Answer=0;									//��־λ����ʾ�ѱ���������
	Project * q;
	string name;									//��Ӧ�����Ľ�������
	int j;
	for(i=1;i<num;i++){								//��Ҫ���м��ζ�����Ӧ�ȵĴ�С�Ƚ�
		j=0;
		q=Head->next;
		while(j<num){								//��������������δ�����Ƚ��̵���Ӧ�ȸ���
			if(q->Answer!=0){
				q->Answer=(sum-(q->Arrvial_Time-p->Arrvial_Time))/q->Run_Time;
			}
			q=q->next;
			j++;
		}
		q=Head->next;								//�ҳ���Ӧ�����Ľ��̵�����
		for(j=1;j<num;j++){
			name=q->Name;
			if(q->Answer<q->next->Answer){
				name=q->next->Name;	
			}
			q=q->next;
		}
		j=0;
		q=Head->next;
		while(j<num){								//���
			if(name==q->Name){
				//cout<<"��ҵ����    ��ʼʱ��    ���ʱ��  ��ѡ��ʱ��Ӧ��  ��תʱ��   ��Ȩ��תʱ��  "<<endl;
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
	cout<<"--------------ģ����ҵ����-----------------"<<endl;
	Manager A;
	A.Create();
	int choice;
	do{
		cout<<"			1.�����ȷ����㷨			"<<endl;
		cout<<"			2.��Ӧ�ȸ����㷨			"<<endl;
		cout<<"			3.�˳�						"<<endl;
		cin>>choice;
		system("cls");
		switch(choice){
			case 1:
				cout<<"-------------�����ȷ����㷨----------------"<<endl;
				A.FCFS();
				break;
			case 2:
				cout<<"--------------��Ӧ�ȸ����㷨-----------------"<<endl;
				A.HRRF();
				break;
			case 3:
				break;
			default:
				cout<<"���벻����Ҫ��"<<endl;
		}
	}
	while(choice!=3);
}