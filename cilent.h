#ifndef CILENT_H
#define CILENT_H
#define MAX_NUM 1000 //�����1000����Ʒ 
#include <cstring>
using namespace std;
typedef struct Goods {
	string name; //��¼������
	unsigned int count;  //��¼��������
}Goods; 
extern int total;
extern Goods g[MAX_NUM];


	///��ʾ��ǰ����б�������Ʒ����������
	void show_goods(); 
	//�������ֲ�ѯ�ֿ���Ʒ����������Ϊ�ṹ��������±꣬��Ϊ-1��ʾû�и���Ʒ 
	int find_goods(string name);
	//��ӭ����,���ݷ��ص����־����Ǵ桢ȡ���ǲ�ѯ���� 
	int  welcome(); 
	//����Ʒ,��ʾ����һ��count������name��Ʒ 
	bool save_goods(); 
	//ȡ��Ʒ,��ʾȡ��һ��count������name��Ʒ 
	bool get_goods();
	//���¿����Ϣ 
	bool flash_list();
#endif  
