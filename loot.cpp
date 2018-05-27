#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<iostream>
#include<Windows.h>
using namespace std;
vector<vector<string> > TypeList(10);
map<int, string> ItemRoll, VarityRoll,ItemNumRoll;
struct dice{
	int face;
	int num;
};
map<string, dice> dicemap;
int MakeDice(dice d){
	int num = d.num;
	int face = d.face;
	int sum=0;
	if (face != 100) {
		for(int i=0;i<num;i++){
			int tmp=rand()%(face)+1;
			sum+=tmp;
		}
	}
	else {
		for (int i = 0; i<num; i++) {
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
//	string addr = "ItemRarity.txt";
	string fdice = "./Dice/VarityDice.txt";
//	vector<string> VarityList = ReadList(addr);
//	TypeList[1]=VarityList;
	dicemap["Varity"] = ReadDice(fdice);
	VarityRoll = ReadRoll("./ItemType/VarityRoll.txt");
}
void InitItem(){
	string fdice = "./Dice/ItemTypeDice.txt";
	string ndice = "./Dice/ItemNumDice.txt";
	dicemap["ItemType"] = ReadDice(fdice);
	dicemap["ItemNum"] = ReadDice(ndice);
	ItemRoll = ReadRoll("./ItemType/ItemRoll.txt");
	ItemNumRoll = ReadRoll("./ItemType/ItemNumRoll.txt");
}
string MakeAddr() {
	dice type = dicemap["ItemType"];
	dice Varity = dicemap["Varity"];
	int ip = MakeDice(type);
	int vp = MakeDice(Varity);
	string TypeName=ItemRoll[ip];
	string VarityName=VarityRoll[vp];
	string result = "./ItemType/" + TypeName + "/" + VarityName + ".txt";
	return result;
}
void Choose(string addr) {
	ifstream In(addr);
	if (In.is_open()) {
		vector<string> It;
		string tmp;
		while (getline(In, tmp)) {
			It.push_back(tmp);
		}
		int high = It.size() - 1;
		srand((unsigned)time(NULL));
		string res=It[rand() % (high + 1)];
		cout << "获取了 " << res << endl<<endl;
	}
	else {
		printf("物品随机初始化错误，输入任意键退出\n");
		fflush(stdin);
		getchar();
		exit(-4);
	}
	
}
int main(){
	printf("搜刮软件启动\n");
	printf("正在初始化物品表~\n");
	InitItem();
	InitVarity();
	printf("物品表初始化完成,按下任意键开始\n");
	printf("**********************分割线**********************\n");
	getchar();
	srand((unsigned)time(NULL));
	unsigned int cnt = 0;
	while (1) {
		printf("冒险者~需要探索么？\n\n按下任意键开始一轮探索\n");
		getchar();
		dice d = dicemap["ItemNum"];
		int cnt=stoi(ItemNumRoll[MakeDice(d)]);
		printf("共探索出 %d 件物品\n\n", cnt);
		for (int i = 0; i < cnt; i++) {
			Choose(MakeAddr());
		}
		printf("\n\n======================分割线======================\n\n");
		cnt++;
		if (cnt > 20) {
			srand((unsigned)time(NULL)+cnt);
			cnt = 0;
		}
	}
}
