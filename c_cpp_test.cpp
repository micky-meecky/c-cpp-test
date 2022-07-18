#include <iostream>
using namespace std;
void test01(void);
void test02(void);
void test03(void);
void set(int i, int* s);


int main(void)
{
	//test01();/*c++中 new int [0] 与 new int [1]的区别*/
	//test02();
	test03();


	//printf("这是git测试\n");
	return 0;
}


void test01(void)
{
	/*c++中 new int [0] 与 new int [1]的区别*/

	/*C++里面，new int[0]那自然是指新建了一块空间，里面却不能存任何的元素。

	new执行的时候，一般会在新建的内存空间之前加一个标志，用来将来delete使用，具体依赖不同的库实现*/
	int* i = new int[0];

	printf("i = %p\n", i);
	printf("i[0] = %p\n", &i[0]);
	printf("i[1] = %p\n", &i[1]);
	//i[0] = 1; //里面不能放东西
	printf("\ni = %p\n", i);
	printf("i[0] = %p\n", &i[0]);
	printf("i[1] = %p\n", &i[1]);
	delete[] i;
	printf("\ni = %p\n", i);
	printf("i[0] = %p\n", &i[0]);
	printf("i[1] = %p\n", &i[1]);
	


}

void test02(void)
{
	/*当我new一个包含2各元素的int类型数组，在我仅仅越界一个单位时，即只有n[2] = 3,没有n[3] = 3时，程序运行时会报内存管理的错误，
	而加上n[3] = 3后，再释放，却没有错误，释放后输出n[3]地址的值发现，n[3]依然保存着3的值。
    所以，问题在于n[2]这个内存在动态分配和释放时起了个什么作用？
	https://blog.csdn.net/weixin_44888382/article/details/114112850 所谓的“堆内存在分配时会在边界设置8字节的保护值”又是什么意思？*/


	int i[2];
	i[0] = 1;
	i[1] = 1;
	printf("i[0] = %p, i[1] = %p, i[2] = %p\n", &i[0], &i[1], &i[2]);
	printf("i[0] = %d, i[1] = %d, i[2] = %d\n", i[0], i[1],i[2]);

	int* n = new int[2];
	n[0] = 1;
	printf("n[0] = %p,n[1] = %p, n[2] = %p, n[3] = %p\n", &n[0], &n[1], &n[2], &n[3]);
	printf("n[0] = %d,n[1] = %d, n[2] = %d, n[3] = %d\n", n[0], n[1], n[2], n[3]);
	n[1] = 2;

	n[3] = 3;
	printf("n[0] = %p,n[1] = %p, n[2] = %p, n[3] = %p\n", &n[0], &n[1],&n[2], &n[3]);
	printf("n[0] = %d,n[1] = %d, n[2] = %d, n[3] = %d\n", n[0], n[1], n[2], n[3]);
	int* p = &n[3];
	delete[] n;
	printf("p = %p, *p = %d\n", p, *p);

	//delete p; /*不是用new开辟的，所以不能delete*/
	printf("delete 成功\n");

}

void test03(void)
{
	/**/
	int* s = new int[3];
	
	printf("in test(), &s = 0x%p\n", s);
	set(10, s);
	printf("msize = %zu\n", _msize(s));
	printf("in show(), &s = 0x%p\n", s);
}

void set(int i, int* s)
{
	printf("in set() new 前, &s = 0x%p\n", s);
	if (s != NULL)
	{
		delete[] s;
		//s = NULL;
	}

	int* l = new int[20];
	printf("l的地址= 0x%p\n", l);

	s = new int[i];
	printf("in set() new 后, &s = 0x%p\n", s);
	//delete[] l;
	return;

	/*
		//重新开辟空间，防止越界
	if (l != NULL)
	{
		delete[] l;
		l = NULL;
	}

	int* tmp = new int[i];

	for (int j = 0; j < i; j++)
	{
		tmp[j] = i;
	}
	return tmp;
	*/

}





