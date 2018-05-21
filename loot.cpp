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
		printf("��Ʒ���ʼ����������������˳�\n");
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
		printf("ϡ�жȱ��ʼ����������������˳�\n");
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
	printf("�ѹ��������\n");
	printf("���ڳ�ʼ����Ʒ��~\n");
	ifstream TypeIn("TypeList.txt");
	InitTypeList(TypeIn);
	ifstream RarityIn("RarityList.txt");
	InitRarityList(RarityIn);
	printf("��Ʒ���ʼ�����:)\n");
	printf("*****************�ָ���*****************\n");
	while(1){
		int dice;
		printf("������������ӵ���\n����8��������8\n");
		cin>>dice; 
		if(dice>=1&&dice<=3){
			printf("û���ջ�\n");
		}
		else if(dice>=4&&dice<=5){
			printf("����ˣ�1��");
			//one 
		}
		else if(dice>=6&&dice<=7){
			printf("����ˣ�2��");
			//two
		}
		else if(dice==8){
			printf("����ˣ�3��");
			//
		}
		else{
			printf("�������,����������\n\n");
			continue;
		}
		ItemRarity(8,1);
		ItemType(8,1);
		printf("\n\n");
	}
}
