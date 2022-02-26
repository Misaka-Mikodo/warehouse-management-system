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
		cout << " \b�ļ���ʧ�ܣ�������" << endl; 
		exit (1);
	}
	fin >> total;
	for(int i = 0; i < total; ++i)
	{
		fin >> g[i].name >> g[i].count; //���ļ��е����ݷ���ṹ�������� 
	}
	fin.close();
	int choice;
	string name;
	while(choice = welcome()) //ѡ���Ӧ�Ĺ��� ��Ϊ0���˳� 
	{
		switch(choice)
		{
			case 1:
				{
					if(save_goods())
					{
						cout << "\b ����ɹ�" << endl;
						if(flash_list())
						{
							cout << "\b�б���³ɹ���" << endl; 
						}
					}
					else
						cout << "\b ����ʧ��" << endl;
					break;
				}
			case 2:
				{
					if(get_goods())
					{
						cout << "\b ȡ���ɹ�" << endl;
						if(flash_list())
						{
							cout << "\b�б���³ɹ���" << endl; 
						}
					}
					else 
						cout << "\b ȡ��ʧ��" << endl;
					break;
				};break;
			case 3:
				{
					cout << "\b�����ѯ�ĵ���ƷӢ�����֡����ʼ������»��߸�����" << endl;
					cin>>name;
					int temp = find_goods(name);
					if(temp == -1)	//˵���ֿ���û�и���Ʒ
					{
						cout << "\bû���ҵ�����Ʒ" << endl;
					}
					else if(temp < total) //˵���ֿ����и�����Ʒ��ֱ���޸���������
					{
						cout << g[temp].name << " " << g[temp].count << endl;
					} 
					else //find_goods��������֮���ֵ���������
					{
						cout << "\b��ѯʱ����Ԥ��֮��Ĵ���" << endl;
					} 
						break; 
				}
			case 4:show_goods();break;
			};
		cout << endl << endl; 
		//ˢ�»����� 
	}
	
} 
