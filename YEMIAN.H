#include <iostream>
using namespace std;
class Page{
	private:	
		int num;  //�趨ҳ�����
		int Num;  //�趨ҳ����
	public:
		Page(){
			cout<<"������ҳ�������"<<endl;
			cin>>num;
			this->num=num;
			cout<<endl;
			cout<<"������ҳ�������"<<endl;
			cin>>Num;
			this->Num=Num;
		}
		void FIFO();
};
void Page::FIFO(){
	int s,i,j,m;
	float rate=0;
	int * Frame=new int[num];
	int * Page=new int[Num];
	cout<<"������ҳ�����˳��"<<endl;
	for(i=0;i<Num;i++){
		cin>>Page[i];
	}													//����ҳ�����˳��
	for(i=0;i<num;i++){
		Frame[i]=-1;
	}													//��ҳ�򸳳�ֵ-1
	cout<<"----------------������---------------"<<endl;
	for(i=0;i<Num;i++){
		for(j=0,s=0;j<num;j++){							// ����Ѱ��ҳ����û����ֵͬ��s=1��ʾ����ֵͬ
			if(Page[i]==Frame[j]){
				s=3;
				break;
			}
		}
		if(s==3){										//����ֵͬʱ�����ҳ�����ϴβ���
			for(m=0;m<num;m++){
				cout<<Frame[m]<<' ';		
			}	
			cout<<endl;
			continue;
		}
		for(j=0,s=2;j<num;j++){
			if(Frame[j]==-1){							//���s=1��˵��ҳ�����п�λ��s=3��˵��ҳ������
				s=1;
				break;
			}
		}
		if(s==1){
			Frame[j]=Page[i];
			for(m=0;m<num;m++){
				cout<<Frame[m]<<' ';		
			}	
			cout<<endl;
			rate++;
		}
		if(s==2){
			for(m=0;m<num-1;m++){
				Frame[m]=Frame[m+1];
			}
			Frame[num-1]=Page[i];
			for(m=0;m<num;m++){
				cout<<Frame[m]<<' ';
			}
			cout<<endl;
			rate++;
		}
	}
	float B=rate/Num;
	cout<<"ȱҳ����="<<rate<<endl;
	cout<<"ȱҳ��="<<B<<endl;
}
void Run_YEMIAN(){
	cout<<"----------------FIFOҳ���滻�㷨----------------------"<<endl;
	Page A;
	A.FIFO();
}