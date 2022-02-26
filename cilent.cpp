#include <iostream>
#include <fstream>
#include <cstring>
#include "cilent.h"
using namespace std;
Goods g[MAX_NUM];//用结构体储存商品信息 
int total = 0;//仓库内的物品总数 

void show_goods()//显示仓库内商品信息 
{
	if(total == 0) 
	{
		cout << "\b仓库内无商品！" << endl;
		return;
	} 
	for(int i = 0; i< total; ++i)
		cout << g[i].name << " " << g[i].count << endl;
} 
bool save_goods()
{
	int count;
	string name;
	cout << "\b 输入存入的物品英文名字【单词间请用下划线隔开】与存放数量" << endl;
	cin >> name >> count;
	int temp = find_goods(name);
	if(temp == -1)	//说明仓库中没有该物品，需创建一个新条目 
	{
		g[total].name = name;
		g[total++].count = count;
		return true;
	}
	else if(temp < total) //说明仓库中有该类商品，直接修改数量即可
	{
		g[temp].count += count;
		return true;
	} 
	else //find_goods返回意料之外的值，报告错误
	{
		return false;
	} 
}
bool get_goods()
{
	int count;
	string name;
	cout << "\b 输入取出的的物品英文名字【单词间请用下划线隔开】与取出数量" << endl;
	cin >> name >> count;
	int temp = find_goods(name);
	if(temp == -1)	//说明仓库中没有该物品，取出失败 
	{
		cout << "\b 仓库中没有该商品" << endl;
		return false;
	}
	else if(temp < total) //说明仓库中有该类商品
	{
		if(g[temp].count < count) //取出数量大于库存数量，拒绝请求 
		{
			cout << "\b 取出数量大于库存数量" << endl;
			return false; 
		}
		else if(g[temp].count == count)// 库存数量为零，删除该商品条目
			 {
			 	for(int i = temp; i < total - 1; ++i)
			 	{
			 		g[i].name = g[i + 1].name;
			 		g[i].count = g[i + 1].count;
			 	}	
			 	total--;
			 }
			 else //若库存数量大于取出数量，则从库存数量减去取出数量 
			 {
			 	g[temp].count -= count;
			 } 
		if(g[temp].count < count) //取出数量大于库存数量，拒绝请求 
		{
			cout << "\b 取出数量大于库存数量" << endl;
			return false; 
		}
	} 
	else //find_goods返回意料之外的值，报告错误
	{
		return false;
	} 
}
int find_goods(string name)
{
	int i;
	for(i = 0; i < total; ++i)
		if(name == g[i].name) break;//在列表中寻找有无该名字的商品，找到时i为商品对应下标 
	if(i == total)	return -1;//-1表示没有找到该商品 
	else return i;//返回商品对应的下标 
		
}
int welcome()
{
	cout << "                仓库管理系统               " << endl;
	cout << "           请输入您需要进行的操作编号      " << endl;
	cout << " 1.存物品   2.取物品   3.查询物品  4.展示列表" << endl;
	cout << "                  0.退出                   " << endl;
	int choice;
	cin >> choice;
	return choice;
}
bool flash_list()
{
	ofstream fout ("in.txt");
	if(!fout.is_open())//查看文件是否打开成功 
	{
		cout <<  "\b商品列表更新失败"  << endl;
		return false;
	}
	else 
	{
		fout << total;
		for(int i = 0; i< total; ++i)
			fout << g[i].name << " " << g[i].count << endl;//将结构体数组的内容输入里面 
		return true;
	} 
	fout.close();
}
