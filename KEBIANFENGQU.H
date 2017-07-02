//        报告要求
// 设计一个小型的操作系统
// 目的和意义
// 实现处理器/存储器/动态存储的管理和虚拟存储的管理，死锁的管理，磁盘调度优化管理等功能
// 说明 ，分别用了哪些算法（分解）
// 二：主要设计流程图（修改）
// 总的界面——分支（画小一点）
// 设计的主流程图
// 课程设计主要功能模块分析（每一个流程图）
// 图必须黑白，无阴影 每一个框图必须顺序编号
// 算法思想和框图 结合在一起
// 全部源代码
// 4.小型操作系统实现界面及其分析
// 5.课程设计的总结与体会
// 目录  表明页码
// 处理器存储管理P101   *虚拟存储器管理P230  动态存储管理P201   死锁的管理P161  *磁盘调度优化P270  多道程序调度
#include <iostream>
using namespace std;
//可变分区
class Changed{
	private:
		int num1;							//内存空闲区的数量
		int num2;							//请求数量
		int * Q;							//指针Q指向Space
		int * P;							//指针P指向Ask
	public:
		void Create();						//构造两个数组，以安放内存空闲区，以及请求
		void Input();						//输入数据
		void First_Fit();					//最先适应分配算法
		void Next_Fit();					//下次适应分配算法

};
void Changed::Create(){
	cout<<"请输入内存空闲区的数量："<<endl;
	cin>>num1;
	int * Space=new int[num1];				//内存空闲区数组Space
	Q=Space;
//	cout<<"Space创建成功"<<endl;
	cout<<"请输入请求的数量："<<endl;
	cin>>num2;
	int * Ask=new int[num2];				//请求数组Ask
	P=Ask;
//	cout<<"Ask创建成功"<<endl;
}
void Changed::Input(){
	int i;
	int *p=P;
	int * q=Q;
	cout<<"请按地址排列依次输入内存空闲区大小,单位为KB："<<endl;
	for(i=0;i<num1;i++){
		cin>>*q++;
	}
//	for(i=0;i<num1;i++){
//		cout<<*q++<<' ';
//	}
	cout<<"请按顺序输入请求，单位为KB："<<endl;
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
	cout<<"最先适应优先法："<<endl;
//	cout<<"请求-------———分配至—————————空闲区"<<endl;
	for(int i=0;i<num2;i++){				//外层循环ASK数组
		cout<<*p;
		for(int j=0;j<num1;j++){			//内存循环Space数组	
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
	cout<<"下次适应分配法："<<endl;
	cout<<"请求-------———分配至———————空闲区"<<endl;
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
			cout<<*p<<"                 "<<"没有可用空间"<<endl;
			j++;
		}
	}
}
void Run_KEBIANFENGQU(){
	cout<<"--------------可变分区的存储管理-----------------"<<endl;
	Changed A;
	A.Create();
	A.Input();
	int choice;
	do{
		cout<<"			1.最先适应分配算法			"<<endl;
		cout<<"			2.下次适应分配算法			"<<endl;
		cout<<"			3.退出						"<<endl;
		cin>>choice;
		system("cls");
		switch(choice){
			case 1:
				cout<<"-------------最先适应分配算法----------------"<<endl;
				A.First_Fit();
				break;
			case 2:
				cout<<"--------------下次适应分配算法-----------------"<<endl;
				A.Next_Fit();
				break;
			case 3:
				break;
			default:
				cout<<"输入不符合要求！"<<endl;
		}
	}
	while(choice!=3);
}