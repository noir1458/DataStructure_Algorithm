#include <stdio.h>
void main() {
	int i = 10, j = 20;
	int* ptr;
	printf("\n i의 값 = %d \n j의 값 = %d", i, j);
	printf("\n i의 메모리 주소(&i) = %u", &i);
	printf("\n j의 메모리 주소(&j) = %u", &j);

	ptr = &i;
	printf("\n\n << ptr=&i 실행 >>");
	printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 참조값(*ptr) = %d", *ptr);

	ptr = &j;
	printf("\n\n << ptr=&j 실행 >>");
	printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 참조값(*ptr) = %d", *ptr);

	i = *ptr;
	printf("\n\n << i=*ptr 실행 >> ");
	printf("\n i의 값 = %d", i);

	getchar();
}
/*
포인터 초기화 방법
1. 주소 연산자를 사용하여 변수 주소를 지정한다.
int i;
int *ptr = &i;

2. 동적 메모리를 할당하고 그 시작 주소를 포인터값으로 지정한다
char *ptr = (char*)malloc(100);

3. 문자형 포인터에 문자열의 시작 주소를 지정한다
char *ptr = "korea";

4. 배열 이름을 이용하여 배열 시작 주소를 지정한다
char A[100];
char *ptr = A;

5. 배열의 첫 번째 요소의 주소를 이용하여 배열 시작 주소를 지정한다
char A[100];
char *ptr = &A[0]

변수 주소를 주거나, 배열 시작주소를 주거나 둘중 하나.
배열의 경우 0번 주소를 주거나 그냥 배열자체를 지정하면 시작주소를 지정하게 되는
*/