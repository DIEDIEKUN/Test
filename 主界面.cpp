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
		cout<<"———欢迎使用小型操作系统————"<<endl;
		cout<<"	1.处理器管理（作业调度）	"<<endl;
		cout<<"	2.死锁的管理				"<<endl;
		cout<<"	3.可变分区存储管理			"<<endl;
		cout<<"	4.虚拟存储管理（页面调度）	"<<endl;
		cout<<"	5.驱动调度技术（驱动调度）	"<<endl;
		cout<<"	6.退出					 	"<<endl;
		cout<<"请选择：";
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
				cout<<"确定退出？"<<endl;
				cout<<" 1. 是   2.否"<<endl;
				cin>>m;
				if(m==1){
					cout<<"再见！"<<endl;
					break;
				}
				else if(m==2){
					desktop();
				}
				else {
					cout<<"请重新输入："<<endl;
					desktop();
				}
			default:
				cout<<"选择不符合要求，请重新输入！"<<endl;
				desktop();
		}
	}
		while(choice!=6);
}
void main(){
	desktop();
}