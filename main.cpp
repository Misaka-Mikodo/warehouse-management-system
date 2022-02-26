#include <iostream>
#include <fstream>
#include "cilent.h" 
using namespace std;
extern Goods g[MAX_NUM];
extern int total;
int main()
{
	ifstream fin ("in.txt");
	if(!fin.is_open())
	{
		cout << " \b文件打开失败，请重试" << endl; 
		exit (1);
	}
	fin >> total;
	for(int i = 0; i < total; ++i)
	{
		fin >> g[i].name >> g[i].count; //将文件中的数据放入结构体数据中 
	}
	fin.close();
	int choice;
	string name;
	while(choice = welcome()) //选择对应的功能 若为0便退出 
	{
		switch(choice)
		{
			case 1:
				{
					if(save_goods())
					{
						cout << "\b 存入成功" << endl;
						if(flash_list())
						{
							cout << "\b列表更新成功！" << endl; 
						}
					}
					else
						cout << "\b 存入失败" << endl;
					break;
				}
			case 2:
				{
					if(get_goods())
					{
						cout << "\b 取出成功" << endl;
						if(flash_list())
						{
							cout << "\b列表更新成功！" << endl; 
						}
					}
					else 
						cout << "\b 取出失败" << endl;
					break;
				};break;
			case 3:
				{
					cout << "\b输入查询的的物品英文名字【单词间请用下划线隔开】" << endl;
					cin>>name;
					int temp = find_goods(name);
					if(temp == -1)	//说明仓库中没有该物品
					{
						cout << "\b没有找到该商品" << endl;
					}
					else if(temp < total) //说明仓库中有该类商品，直接修改数量即可
					{
						cout << g[temp].name << " " << g[temp].count << endl;
					} 
					else //find_goods返回意料之外的值，报告错误
					{
						cout << "\b查询时出现预料之外的错误" << endl;
					} 
						break; 
				}
			case 4:show_goods();break;
			};
		cout << endl << endl; 
		//刷新缓冲区 
	}
	
} 
