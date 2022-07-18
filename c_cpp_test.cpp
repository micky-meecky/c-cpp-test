#include <iostream>
using namespace std;
void test01(void);


int main(void)
{
	test01();/*c++中 new int [0] 与 new int [1]的区别*/



	printf("这是git测试\n");
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