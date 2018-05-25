#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
vector<vector<string> > TypeList(10);
//map<string, vector<string>> ;
map<int, string> ItemRoll, VarityRoll;
struct dice{
	int face;
	int num;
};
map<string, dice> dicemap;
int MakeDice(int num,int face){
	int sum=0;
	srand((unsigned)time(NULL));
	if (face != 100) {
		for(int i=0;i<num;i++){
			srand((unsigned)time(NULL));
			int tmp=rand()%(face)+1;
			sum+=tmp;
		}
	}
	else {
		for (int i = 0; i<num; i++) {
			srand((unsigned)time(NULL));
			int tmp = rand() % (face + 1);
			sum += tmp;
		}
	}
	return sum;
}
dice ReadDice(string addr) {
	int num, face;
	ifstream In(addr);
	if (In.is_open()) {
		string sface, snum;
		getline(In, snum);
		getline(In, sface);
		num = stoi(snum);
		face = stoi(sface);
		dice tmp;
		tmp.face = face;
		tmp.num = num;
		In.close();
		return tmp;
	}
	else {
		printf("骰子初始化错误，输入任意键退出\n");
		fflush(stdin);
		getchar();
		exit(-2);
	}
}
vector<string> ReadList(string addr) {
	ifstream In(addr);
	string ItemType;
	vector<string> ItemList;
	if(In.is_open()){
		while(getline(In,ItemType)){
			ItemList.push_back(ItemType);
		}
		In.close();
		return ItemList;
	}
	else {
		printf("物品表初始化错误，输入任意键退出\n");
		fflush(stdin);
		getchar();
		exit(-1);
	}
}
map<int, string> ReadRoll(string addr) {
	ifstream In(addr);
	string RollLine;
	map<int, string> m;
	if (In.is_open()) {
		while (getline(In, RollLine)) {
			int low, high;
			low = stoi(RollLine.substr(0, 1));
			high = stoi(RollLine.substr(2, 1));
			string name =RollLine.substr(4);
			for (int i = low; i <= high; i++) {
				m[i] = name;
			}
		}
		In.close();
		return m;
	}
	else {
		printf("物品roll表初始化错误，输入任意键退出\n");
		fflush(stdin);
		getchar();
		exit(-1);
	}
}
void InitVarity() {
	string addr = "ItemRarity.txt";
	string fdice = "./ItemType/VarityDice.txt";
	vector<string> VarityList = ReadList(addr);
	TypeList[1]=VarityList;
	dicemap["Varity"] = ReadDice(fdice);
	VarityRoll = ReadRoll("./ItemType/VarityRoll.txt");
}
void InitItem(){
	string addr="ItemType.txt";
	string fdice = "./ItemType/ItemTypeDice.txt";
	vector<string> ItemList=ReadList(addr);
	TypeList[0]=ItemList;
	dicemap["Itemtype"] = ReadDice(fdice);
	ItemRoll = ReadRoll("./ItemType/ItemRoll.txt");
}
int main(){
	printf("搜刮软件启动\n");
	printf("正在初始化物品表~\n");
	InitItem();
	InitVarity();
	printf("物品表初始化完成:)\n");
	printf("**********************分割线**********************\n");
	getchar();
}
