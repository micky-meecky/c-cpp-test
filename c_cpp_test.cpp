#include <iostream>
using namespace std;
void test01(void);
void test02(void);
void test03(void);
void set(int i, int* s);


int main(void)
{
	//test01();/*c++�� new int [0] �� new int [1]������*/
	//test02();
	test03();


	//printf("����git����\n");
	return 0;
}


void test01(void)
{
	/*c++�� new int [0] �� new int [1]������*/

	/*C++���棬new int[0]����Ȼ��ָ�½���һ��ռ䣬����ȴ���ܴ��κε�Ԫ�ء�

	newִ�е�ʱ��һ������½����ڴ�ռ�֮ǰ��һ����־����������deleteʹ�ã�����������ͬ�Ŀ�ʵ��*/
	int* i = new int[0];

	printf("i = %p\n", i);
	printf("i[0] = %p\n", &i[0]);
	printf("i[1] = %p\n", &i[1]);
	//i[0] = 1; //���治�ܷŶ���
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
	/*����newһ������2��Ԫ�ص�int�������飬���ҽ���Խ��һ����λʱ����ֻ��n[2] = 3,û��n[3] = 3ʱ����������ʱ�ᱨ�ڴ����Ĵ���
	������n[3] = 3�����ͷţ�ȴû�д����ͷź����n[3]��ַ��ֵ���֣�n[3]��Ȼ������3��ֵ��
    ���ԣ���������n[2]����ڴ��ڶ�̬������ͷ�ʱ���˸�ʲô���ã�
	https://blog.csdn.net/weixin_44888382/article/details/114112850 ��ν�ġ����ڴ��ڷ���ʱ���ڱ߽�����8�ֽڵı���ֵ������ʲô��˼��*/


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

	//delete p; /*������new���ٵģ����Բ���delete*/
	printf("delete �ɹ�\n");

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
	printf("in set() new ǰ, &s = 0x%p\n", s);
	if (s != NULL)
	{
		delete[] s;
		//s = NULL;
	}

	int* l = new int[20];
	printf("l�ĵ�ַ= 0x%p\n", l);

	s = new int[i];
	printf("in set() new ��, &s = 0x%p\n", s);
	//delete[] l;
	return;

	/*
		//���¿��ٿռ䣬��ֹԽ��
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





