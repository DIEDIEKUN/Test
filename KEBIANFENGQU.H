//        ����Ҫ��
// ���һ��С�͵Ĳ���ϵͳ
// Ŀ�ĺ�����
// ʵ�ִ�����/�洢��/��̬�洢�Ĺ���������洢�Ĺ����������Ĺ��������̵����Ż������ȹ���
// ˵�� ���ֱ�������Щ�㷨���ֽ⣩
// ������Ҫ�������ͼ���޸ģ�
// �ܵĽ��桪����֧����Сһ�㣩
// ��Ƶ�������ͼ
// �γ������Ҫ����ģ�������ÿһ������ͼ��
// ͼ����ڰף�����Ӱ ÿһ����ͼ����˳����
// �㷨˼��Ϳ�ͼ �����һ��
// ȫ��Դ����
// 4.С�Ͳ���ϵͳʵ�ֽ��漰�����
// 5.�γ���Ƶ��ܽ������
// Ŀ¼  ����ҳ��
// �������洢����P101   *����洢������P230  ��̬�洢����P201   �����Ĺ���P161  *���̵����Ż�P270  ����������
#include <iostream>
using namespace std;
//�ɱ����
class Changed{
	private:
		int num1;							//�ڴ������������
		int num2;							//��������
		int * Q;							//ָ��Qָ��Space
		int * P;							//ָ��Pָ��Ask
	public:
		void Create();						//�����������飬�԰����ڴ���������Լ�����
		void Input();						//��������
		void First_Fit();					//������Ӧ�����㷨
		void Next_Fit();					//�´���Ӧ�����㷨

};
void Changed::Create(){
	cout<<"�������ڴ��������������"<<endl;
	cin>>num1;
	int * Space=new int[num1];				//�ڴ����������Space
	Q=Space;
//	cout<<"Space�����ɹ�"<<endl;
	cout<<"�����������������"<<endl;
	cin>>num2;
	int * Ask=new int[num2];				//��������Ask
	P=Ask;
//	cout<<"Ask�����ɹ�"<<endl;
}
void Changed::Input(){
	int i;
	int *p=P;
	int * q=Q;
	cout<<"�밴��ַ�������������ڴ��������С,��λΪKB��"<<endl;
	for(i=0;i<num1;i++){
		cin>>*q++;
	}
//	for(i=0;i<num1;i++){
//		cout<<*q++<<' ';
//	}
	cout<<"�밴˳���������󣬵�λΪKB��"<<endl;
	for(i=0;i<num2;i++){
		cin>>*p++;
	}
//	for(i=0;i<num2;i++){
//		cout<<*P++;
//	}
}
void Changed::First_Fit(){
	int *q=Q;
	int *p=P;
	cout<<"������Ӧ���ȷ���"<<endl;
//	cout<<"����-------������������������������������������"<<endl;
	for(int i=0;i<num2;i++){				//���ѭ��ASK����
		cout<<*p;
		for(int j=0;j<num1;j++){			//�ڴ�ѭ��Space����	
			if(*p<=*q){
				cout<<"                  "<<*q;
				*q-=*p;
				break;
			}
			q++;
		}
		q=Q;
		cout<<endl;
		p++;
	}
}
void Changed::Next_Fit(){
	int * q=Q;
	int * p=P;
	cout<<"�´���Ӧ���䷨��"<<endl;
	cout<<"����-------��������������������������������"<<endl;
	int i=0;
	int j=0;
	while(i<num1&&j<num2){
		if(*p<=*q){
				cout<<*p<<"                 "<<*q<<endl;
				p++;
				j++;
			}
		q++;
		i++;
	}
	if(j<num2){
		while(j<num2){
			cout<<*p<<"                 "<<"û�п��ÿռ�"<<endl;
			j++;
		}
	}
}
void Run_KEBIANFENGQU(){
	cout<<"--------------�ɱ�����Ĵ洢����-----------------"<<endl;
	Changed A;
	A.Create();
	A.Input();
	int choice;
	do{
		cout<<"			1.������Ӧ�����㷨			"<<endl;
		cout<<"			2.�´���Ӧ�����㷨			"<<endl;
		cout<<"			3.�˳�						"<<endl;
		cin>>choice;
		system("cls");
		switch(choice){
			case 1:
				cout<<"-------------������Ӧ�����㷨----------------"<<endl;
				A.First_Fit();
				break;
			case 2:
				cout<<"--------------�´���Ӧ�����㷨-----------------"<<endl;
				A.Next_Fit();
				break;
			case 3:
				break;
			default:
				cout<<"���벻����Ҫ��"<<endl;
		}
	}
	while(choice!=3);
}