#include<iostream>
using namespace std;
#include"DIAODU.h"
#include"SISUO.h"
#include"KEBIANFENGQU.h"
#include"YEMIAN.h"
#include"QUDONG.h"
static desktop(){
	int choice;
	do{
		cout<<"��������ӭʹ��С�Ͳ���ϵͳ��������"<<endl;
		cout<<"	1.������������ҵ���ȣ�	"<<endl;
		cout<<"	2.�����Ĺ���				"<<endl;
		cout<<"	3.�ɱ�����洢����			"<<endl;
		cout<<"	4.����洢����ҳ����ȣ�	"<<endl;
		cout<<"	5.�������ȼ������������ȣ�	"<<endl;
		cout<<"	6.�˳�					 	"<<endl;
		cout<<"��ѡ��";
		cin>>choice;
		system("cls");
		switch(choice){
			case 1:
				Run_DIAODU();
				break;
			case 2:
				Run_SISUO();
				break;
			case 3:
				Run_KEBIANFENGQU();
				break;
			case 4:
				Run_YEMIAN();
				break;
			case 5:
				Run_QUDONG();
				break;
			case 6:
				int m;
				cout<<"ȷ���˳���"<<endl;
				cout<<" 1. ��   2.��"<<endl;
				cin>>m;
				if(m==1){
					cout<<"�ټ���"<<endl;
					break;
				}
				else if(m==2){
					desktop();
				}
				else {
					cout<<"���������룺"<<endl;
					desktop();
				}
			default:
				cout<<"ѡ�񲻷���Ҫ�����������룡"<<endl;
				desktop();
		}
	}
		while(choice!=6);
}
void main(){
	desktop();
}