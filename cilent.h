#ifndef CILENT_H
#define CILENT_H
#define MAX_NUM 1000 //最多存放1000件物品 
#include <cstring>
using namespace std;
typedef struct Goods {
	string name; //记录货物名
	unsigned int count;  //记录货物数量
}Goods; 
extern int total;
extern Goods g[MAX_NUM];


	///显示当前库存列表，包括商品名及其库存量
	void show_goods(); 
	//根据名字查询仓库物品，返回数字为结构体数组的下标，若为-1表示没有该商品 
	int find_goods(string name);
	//欢迎界面,根据返回的数字决定是存、取还是查询功能 
	int  welcome(); 
	//存物品,表示存入一批count数量的name商品 
	bool save_goods(); 
	//取物品,表示取出一批count数量的name商品 
	bool get_goods();
	//更新库存信息 
	bool flash_list();
#endif  
