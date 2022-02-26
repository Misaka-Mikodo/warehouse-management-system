#include <iostream>
#include <fstream>
#include <cstring>
#include "cilent.h"
using namespace std;
Goods g[MAX_NUM];//�ýṹ�崢����Ʒ��Ϣ 
int total = 0;//�ֿ��ڵ���Ʒ���� 

void show_goods()//��ʾ�ֿ�����Ʒ��Ϣ 
{
	if(total == 0) 
	{
		cout << "\b�ֿ�������Ʒ��" << endl;
		return;
	} 
	for(int i = 0; i< total; ++i)
		cout << g[i].name << " " << g[i].count << endl;
} 
bool save_goods()
{
	int count;
	string name;
	cout << "\b ����������ƷӢ�����֡����ʼ������»��߸�������������" << endl;
	cin >> name >> count;
	int temp = find_goods(name);
	if(temp == -1)	//˵���ֿ���û�и���Ʒ���贴��һ������Ŀ 
	{
		g[total].name = name;
		g[total++].count = count;
		return true;
	}
	else if(temp < total) //˵���ֿ����и�����Ʒ��ֱ���޸���������
	{
		g[temp].count += count;
		return true;
	} 
	else //find_goods��������֮���ֵ���������
	{
		return false;
	} 
}
bool get_goods()
{
	int count;
	string name;
	cout << "\b ����ȡ���ĵ���ƷӢ�����֡����ʼ������»��߸�������ȡ������" << endl;
	cin >> name >> count;
	int temp = find_goods(name);
	if(temp == -1)	//˵���ֿ���û�и���Ʒ��ȡ��ʧ�� 
	{
		cout << "\b �ֿ���û�и���Ʒ" << endl;
		return false;
	}
	else if(temp < total) //˵���ֿ����и�����Ʒ
	{
		if(g[temp].count < count) //ȡ���������ڿ���������ܾ����� 
		{
			cout << "\b ȡ���������ڿ������" << endl;
			return false; 
		}
		else if(g[temp].count == count)// �������Ϊ�㣬ɾ������Ʒ��Ŀ
			 {
			 	for(int i = temp; i < total - 1; ++i)
			 	{
			 		g[i].name = g[i + 1].name;
			 		g[i].count = g[i + 1].count;
			 	}	
			 	total--;
			 }
			 else //�������������ȡ����������ӿ��������ȥȡ������ 
			 {
			 	g[temp].count -= count;
			 } 
		if(g[temp].count < count) //ȡ���������ڿ���������ܾ����� 
		{
			cout << "\b ȡ���������ڿ������" << endl;
			return false; 
		}
	} 
	else //find_goods��������֮���ֵ���������
	{
		return false;
	} 
}
int find_goods(string name)
{
	int i;
	for(i = 0; i < total; ++i)
		if(name == g[i].name) break;//���б���Ѱ�����޸����ֵ���Ʒ���ҵ�ʱiΪ��Ʒ��Ӧ�±� 
	if(i == total)	return -1;//-1��ʾû���ҵ�����Ʒ 
	else return i;//������Ʒ��Ӧ���±� 
		
}
int welcome()
{
	cout << "                �ֿ����ϵͳ               " << endl;
	cout << "           ����������Ҫ���еĲ������      " << endl;
	cout << " 1.����Ʒ   2.ȡ��Ʒ   3.��ѯ��Ʒ  4.չʾ�б�" << endl;
	cout << "                  0.�˳�                   " << endl;
	int choice;
	cin >> choice;
	return choice;
}
bool flash_list()
{
	ofstream fout ("in.txt");
	if(!fout.is_open())//�鿴�ļ��Ƿ�򿪳ɹ� 
	{
		cout <<  "\b��Ʒ�б����ʧ��"  << endl;
		return false;
	}
	else 
	{
		fout << total;
		for(int i = 0; i< total; ++i)
			fout << g[i].name << " " << g[i].count << endl;//���ṹ������������������� 
		return true;
	} 
	fout.close();
}
