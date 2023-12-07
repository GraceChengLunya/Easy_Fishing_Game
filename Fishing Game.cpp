//�ɦW�G Project B_7 
//�{���W�١GMemorize Fishing Game
//�}�o�ɶ��G2020/6/20

#include <iostream>
#include <cstdlib>
#include <ctime>

#define NoR 5
#define NoC 5

using namespace std;

void printcard(int fish[NoR][NoC],int,int,int,int,int&);   //�_�l�P (�л\��)
bool checkright(int fish[NoR][NoC],int,int,int,int,int&);
// 4*4���P��
int open[NoR][NoC]={0};
bool  checkright(int fish[NoR][NoC],int r1,int r2,int cn1,int cn2,int &correct){
	if(((fish[r1][cn1]+1)/2==(fish[r2][cn2]+1)/2)&&open[r1][cn1]==1&&open[r2][cn2]==1){
		correct++; //���� && �O�Ĥ@��½�} correct++
		return 1;
	}else if((fish[r1][cn1]+1)/2==(fish[r2][cn2]+1)/2){
		return 1; //open[r1][cn1] ==2
	}else{
		return 0;  
	}
}

void printcard(int fish[NoR][NoC],int r1,int r2,int cn1,int cn2,int &correct){
	
	system("CLS");   //�M���ù� 
	cout <<endl;
	
	char c=65;   // 65=A   97=a
	cout << "   ";
	for(int j=0; j<4; j++){
		cout << (char) (c+j) << " ";
	}
	cout <<endl;
	if(open[r1][cn1]!=2) //�л\���ɭ�open=0 �Ĥ@��½�} ��open=1 �]checkright�ݬO���O�P�@�i�P 
		open[r1][cn1]=1; 
	if(open[r2][cn2]!=2) 
		open[r2][cn2]=1; 
	for (int i=0; i<4; i++){
		
		if(i+1 <5)				
			cout << " " <<i+1;
	
		string F0 = "��";
		string F1 = "��";
		string F2 = "��";
		string F3 = "��";
		string F4 = "��";
		string F5 = "��";
		string F6 = "��";
		string F7 = "��";
		string F8 = "��";	
			for(int j=1; j<NoC; j++){
				switch(open[i+1][j]){
					case 0:
					cout << F0;
					break;
					case 1:
					case 2:
					switch(fish[i+1][j]){
						case 1:
						cout << F1;
						break;
						
						case 2:
						cout << F1;
						break;
						
						case 3:
						cout << F2;
						break;
						
						case 4:
						cout << F2;
						break;
						
						case 5:
						cout << F3;
						break;
						
						case 6:
						cout << F3;
						break;
						
						case 7:
						cout << F4;
						break;
						
						case 8:
						cout << F4;
						break;
						
						case 9:
						cout << F5;
						break;
						
						case 10:
						cout << F5;
						break;
						
						case 11:
						cout << F6;
						break;
						
						case 12:
						cout << F6;
						break;
						
						case 13:
						cout << F7;
						break;
						
						case 14:
						cout << F7;
						break;
						
						case 15:
						cout << F8;
						break;
						
						case 16:
						cout << F8;
						break;
										
					}
					break;				
				}										
			}	
			cout << endl;			
	}
	if(!checkright(fish,r1,r2,cn1,cn2,correct)){
		open[r1][cn1]=0; //checkright�O������ open�ܦ�0 ��P�\�_��;  
		open[r2][cn2]=0;
	}else{
		open[r1][cn1]=2; //checright�q�L���� ��open�ܦ�2  
		open[r2][cn2]=2;
	}	
}


int main(){

	
	bool repeat=0;
	int ct=0; //½�P���� 
	int correct=-1; //����ռ� 
	int r1,r2,cn1,cn2;   //row�y�Ф�col�y�� 
	char c1,c2;   //col�y��
	int fish[NoR][NoC] = {0};
	printcard(fish,0,0,0,0,correct);
	int record[16]={0}; // �@���}�C 0-15
	srand(time(0));   //�ü�
	
	for(int i=1;i<NoR;i++){ //�ͦ�4x4�����ư}�C 
		for(int j=1;j<NoC;j++){
			fish[i][j]=rand()%16+1;  
			for(int k=0;k<16;k++){  
				if(record[k]==fish[i][j]){
					repeat=1;  
					break;
				}				
			}
			if(repeat){
				record[4*(i-1)+j-1]=fish[i][j]; //��4x4���}�C�Τ@��0-15���}�C�x�s 
				j--; //�p�G�����ƪ��ü� �^��e�@�� 
				repeat=0;  //set repeat=0 ���s�ˬd 
			}else{
				record[4*(i-1)+j-1]=fish[i][j];
			}
		}
	}
//½�P 
	while(correct<8){
		cout <<endl;
		
		cout << "�п�J�n�Ĥ@�i½��row�y��(�Ʀr):" <<endl; 
		cin >> r1; 
	    while(r1<1||r1>4){
			cout << "�d����~�A�Э��s��J�C"<<endl;	
			cin>>r1;					
		}
		
		cout << "�п�J�n�Ĥ@�i½��col�y��(�j�g�^��):" <<endl; 
		cin >> c1;
		cn1=c1-64; //cn1�O�r�� A-64 =1 
	    while(cn1<1||cn1>4){
			cout << "�d����~�A�Э��s��J�C"<<endl;	
			cin>>c1;
			cn1=c1-64;					
		}
		
		cout << "�п�J�n�ĤG�i½��row�y��:" <<endl; 
		cin >> r2;
	    while(r2<1||r2>4){
			cout << "�d����~�A�Э��s��J�C"<<endl;	
			cin>>r2;					
		}
		cout << "�п�J�n�ĤG�i½��col�y��(�j�g�^��):" <<endl; 
		cin >> c2;
		cn2=c2-64;
	    while(cn2<1||cn2>4){
			cout << "�d����~�A�Э��s��J�C"<<endl;	
			cin>>c2;
			cn2=c2-64;					
		}	
			
		if(r1==r2 && c1==c2){
			cout<<"��½��i���P���P"<<endl;
		}else{
			ct++;
			printcard(fish,r1,r2,cn1,cn2,correct);
		}
		

			
		cout<<"�w�g½�F"<<ct<<"��" ;
	}
	
	//�����P½�쥿���A�C�������A��ܤ@�@½�X�� 
	if(correct==8){
		cout<<"���߱z���\��X�Ҧ����P�A�C������!!!" << endl;
		cout<<"�`�@½�F"<<ct<<"��" ;
	}
	return 1;
} 





