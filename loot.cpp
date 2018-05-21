#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
vector<string> TypeList,RarityList;
void InitTypeList(ifstream &in){
	string list="1";
	if(in.is_open()){
		while(list!=""){
			getline(in,list);
			TypeList.push_back(list);
		}
		in.close();
	}
	else{
		printf("物品表初始化错误，输入任意键退出\n");
		fflush(stdin);
		getchar();
		exit(-1);
	}
}
void InitRarityList(ifstream &in){
	string list="1";
	if(in.is_open()){
		while(list!=""){
			getline(in,list);
			RarityList.push_back(list);
		}
		
		in.close();
	}
	else{
		printf("稀有度表初始化错误，输入任意键退出\n");
		fflush(stdin);
		getchar();
		exit(-1);
	}
}
int MakeDice(int face,int num){
	int sum=0;
	srand((unsigned)time(NULL));
	for(int i=0;i<num;i++){
		int tmp=rand()%(face)+1;
		sum+=tmp;
	}
	return sum;
}
void ItemType(int face,int num){
	int dice=MakeDice(face,num);
	string s=TypeList[dice-1];
	cout<<s;
}
void ItemRarity(int face,int num){
	int dice=MakeDice(face,num);
	string s=RarityList[dice-1];
	cout<<s;
}
int main(){
	printf("搜刮软件启动\n");
	printf("正在初始化物品表~\n");
	ifstream TypeIn("TypeList.txt");
	InitTypeList(TypeIn);
	ifstream RarityIn("RarityList.txt");
	InitRarityList(RarityIn);
	printf("物品表初始化完成:)\n");
	printf("*****************分割线*****************\n");
	while(1){
		int dice;
		printf("请输入玩家骰子点数\n大于8点请输入8\n");
		cin>>dice; 
		if(dice>=1&&dice<=3){
			printf("没有收获\n");
		}
		else if(dice>=4&&dice<=5){
			printf("获得了，1个");
			//one 
		}
		else if(dice>=6&&dice<=7){
			printf("获得了，2个");
			//two
		}
		else if(dice==8){
			printf("获得了，3个");
			//
		}
		else{
			printf("输入错误,请重新输入\n\n");
			continue;
		}
		ItemRarity(8,1);
		ItemType(8,1);
		printf("\n\n");
	}
}
