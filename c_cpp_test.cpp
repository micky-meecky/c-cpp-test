#include <iostream>
using namespace std;
void test01(void);


int main(void)
{
	test01();/*c++�� new int [0] �� new int [1]������*/



	printf("����git����\n");
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