/******************************************************************************************
* Data Structures in C++ -- BTree ��������
* ���ϼ������� 2017/5/22 16:55
* @author ������, xtwyzh@gmail.com, xtwroot.com
* xtwroot Copyright (c) 2017. All rights reserved.
******************************************************************************************/

/******************************************************************************************
* Test of B-Tree
******************************************************************************************/
#include"BTree.h"
#include "../_share/rand.h"
#include"../UniPrint/print.h"

/******************************************************************************************
* Test a BTree
******************************************************************************************/
template <typename T> void testBTree(int order,int n)
{
	BTree<T> bt(order);
	while(bt.size() < n)
	{
		T e = dice(static_cast<T>(n) * 3); // [0,3n)��Χ�ڵ�e
		switch (dice(3))
		{
		case 0: // ���ң��ɹ��� <= 33.3%
			{
			printf("Searching for "); print(e); printf(" ... ");
			BTNodePosi(T) p = bt.search(e);
			printf(p ? "Found\n" : "Not found\n");
			break;
			}
		case 1: // ���룬�ɹ��� <= 33.3%
			{
			printf("Removing "); print(e); printf(" ... ");
			bt.insert(e) ?
				printf("Done\n"), print(bt) :
				printf("Not exists\n");
			break;
			}
		default: // ���룬�ɹ��� == 100%
			{
			printf("Inserting "); print(e); printf(" ... ");
			int oldsize = bt.size();
			bt.insert(e) ?
				printf("Done\n"), print(bt) :
				printf("Dup key\n");
			break;
			}
		}
	}
	while (bt.size() > 0)
	{
		T e = dice(static_cast<T>(n) * 3); // 
		printf(" Removing "); print(e); printf(" ... ");
		bt.remove(e) ?
			printf("Done\n"), print(bt) :
			printf("not exists\n");
	}
}

/******************************************************************************************
* ���������
******************************************************************************************/
int main(int argc,char * argv[])
{
	/*if(3 > argc)
	{
		printf("Usage: %s <order of B-Tree> <size of test>\a\a\n", argv[0]);
		return 1;
	}
	int order = atoi(argv[1]);
	if(order < 3)
	{
		printf("Make sure the order (%d) is no less than 3.\a\a\n", order);
		return 1;
	}
	int size = atoi(argv[2]);
	if(size < 0)
	{
		printf("Make sure the size (%d) is no less than 0.\a\a\n", size);
		return 1;
	}*/
	srand(static_cast<unsigned int>(time(nullptr)));
	testBTree<int>(4, 30);
	system("pause");
	return 0;
}