//檔名： Project B_7 
//程式名稱：Memorize Fishing Game
//開發時間：2020/6/20

#include <iostream>
#include <cstdlib>
#include <ctime>

#define NoR 5
#define NoC 5

using namespace std;

void printcard(int fish[NoR][NoC],int,int,int,int,int&);   //起始牌 (覆蓋的)
bool checkright(int fish[NoR][NoC],int,int,int,int,int&);
// 4*4的牌數
int open[NoR][NoC]={0};
bool  checkright(int fish[NoR][NoC],int r1,int r2,int cn1,int cn2,int &correct){
	if(((fish[r1][cn1]+1)/2==(fish[r2][cn2]+1)/2)&&open[r1][cn1]==1&&open[r2][cn2]==1){
		correct++; //當答對 && 是第一次翻開 correct++
		return 1;
	}else if((fish[r1][cn1]+1)/2==(fish[r2][cn2]+1)/2){
		return 1; //open[r1][cn1] ==2
	}else{
		return 0;  
	}
}

void printcard(int fish[NoR][NoC],int r1,int r2,int cn1,int cn2,int &correct){
	
	system("CLS");   //清除螢幕 
	cout <<endl;
	
	char c=65;   // 65=A   97=a
	cout << "   ";
	for(int j=0; j<4; j++){
		cout << (char) (c+j) << " ";
	}
	cout <<endl;
	if(open[r1][cn1]!=2) //覆蓋的時候open=0 第一次翻開 讓open=1 跑checkright看是不是同一張牌 
		open[r1][cn1]=1; 
	if(open[r2][cn2]!=2) 
		open[r2][cn2]=1; 
	for (int i=0; i<4; i++){
		
		if(i+1 <5)				
			cout << " " <<i+1;
	
		string F0 = "■";
		string F1 = "１";
		string F2 = "２";
		string F3 = "３";
		string F4 = "４";
		string F5 = "５";
		string F6 = "６";
		string F7 = "７";
		string F8 = "８";	
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
		open[r1][cn1]=0; //checkright是錯的的 open變成0 把牌蓋起來;  
		open[r2][cn2]=0;
	}else{
		open[r1][cn1]=2; //checright通過之後 把open變成2  
		open[r2][cn2]=2;
	}	
}


int main(){

	
	bool repeat=0;
	int ct=0; //翻牌次數 
	int correct=-1; //答對組數 
	int r1,r2,cn1,cn2;   //row座標及col座標 
	char c1,c2;   //col座標
	int fish[NoR][NoC] = {0};
	printcard(fish,0,0,0,0,correct);
	int record[16]={0}; // 一維陣列 0-15
	srand(time(0));   //亂數
	
	for(int i=1;i<NoR;i++){ //生成4x4不重複陣列 
		for(int j=1;j<NoC;j++){
			fish[i][j]=rand()%16+1;  
			for(int k=0;k<16;k++){  
				if(record[k]==fish[i][j]){
					repeat=1;  
					break;
				}				
			}
			if(repeat){
				record[4*(i-1)+j-1]=fish[i][j]; //讓4x4的陣列用一維0-15的陣列儲存 
				j--; //如果有重複的亂數 回到前一格 
				repeat=0;  //set repeat=0 重新檢查 
			}else{
				record[4*(i-1)+j-1]=fish[i][j];
			}
		}
	}
//翻牌 
	while(correct<8){
		cout <<endl;
		
		cout << "請輸入要第一張翻的row座標(數字):" <<endl; 
		cin >> r1; 
	    while(r1<1||r1>4){
			cout << "範圍錯誤，請重新輸入。"<<endl;	
			cin>>r1;					
		}
		
		cout << "請輸入要第一張翻的col座標(大寫英文):" <<endl; 
		cin >> c1;
		cn1=c1-64; //cn1是字元 A-64 =1 
	    while(cn1<1||cn1>4){
			cout << "範圍錯誤，請重新輸入。"<<endl;	
			cin>>c1;
			cn1=c1-64;					
		}
		
		cout << "請輸入要第二張翻的row座標:" <<endl; 
		cin >> r2;
	    while(r2<1||r2>4){
			cout << "範圍錯誤，請重新輸入。"<<endl;	
			cin>>r2;					
		}
		cout << "請輸入要第二張翻的col座標(大寫英文):" <<endl; 
		cin >> c2;
		cn2=c2-64;
	    while(cn2<1||cn2>4){
			cout << "範圍錯誤，請重新輸入。"<<endl;	
			cin>>c2;
			cn2=c2-64;					
		}	
			
		if(r1==r2 && c1==c2){
			cout<<"請翻兩張不同的牌"<<endl;
		}else{
			ct++;
			printcard(fish,r1,r2,cn1,cn2,correct);
		}
		

			
		cout<<"已經翻了"<<ct<<"次" ;
	}
	
	//全部牌翻到正面，遊戲結束，顯示一共翻幾次 
	if(correct==8){
		cout<<"恭喜您成功找出所有的牌，遊戲結束!!!" << endl;
		cout<<"總共翻了"<<ct<<"次" ;
	}
	return 1;
} 





