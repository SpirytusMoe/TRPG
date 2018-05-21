#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
vector<string> ItemList,TypeList,RarityList;
map<string, vector<string>> ;
int MakeDice(int face,int num){
	int sum=0;
	srand((unsigned)time(NULL));
	for(int i=0;i<num;i++){
		int tmp=rand()%(face)+1;
		sum+=tmp;
	}
	return sum;
}
void InitItem(){
	string addr="ItemType.txt";
	string ItemType;
	ifstream In(addr);
	if(In.is_open()){
		while(getline(In,ItemType)){
			ItemList.push_back(ItemType);
			cout<<ItemType<<endl;
		}
		In.close();
	}
	else {
		printf("物品表初始化错误，输入任意键退出\n");
		fflush(stdin);
		getchar();
		exit(-1);
	}
}
int main(){
	printf("搜刮软件启动\n");
	printf("正在初始化物品表~\n");
	printf("物品表初始化完成:)\n");
	printf("**********************分割线**********************\n");
	getchar();
}
