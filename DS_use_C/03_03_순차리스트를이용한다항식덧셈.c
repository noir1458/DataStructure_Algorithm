/*
다항식은 항을 나열한 것이므로 선형 리스트를 사용하여 표현할수 있고, 연산 처리 가능

지수가 n인 다항식은, 최다항 개수가 n+1개 이므로
원소가 n+1인 배열을 사욯하여 순차 자료구조로 표현 가능
배열 idx는 다항식 항의 지수 표현, 원소는 계수 저장
인덱스 i는 지수가 n-i인 항에 대응되는 배열원소,
p[i]는 지수가 n-i인 항의 계수


다항식의 각 항의 계수를 정해진 인덱스의 배열 원소에 저장하여 사용하는 방법은
지수를 따로 저장하지 않기 때문에 표현하기 쉽고 간단하다
그러나 차수와 항의 개수차이가 심한 희소다항식은 메모리가 낭비된다
ex) B(x) = 3x^1000 + x + 4
지수는 1000이지만 항의 개수는 3개 뿐인 희소 다항식
순차 자료구조로 저장하려면 배열 크기가 1001인 배열을 사용해야 한다
실제 사용하는건 3개 뿐, 나머지 998개 공간은 낭비된다

이 경우에는 항의 개수에 따라 배열 크기를 결정하는것이 메모리 사용면에서 효율적
<지수, 계수> 쌍을 2차원 배열로 저장한다

*/
#include <stdio.h>
#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial addPoly(polynomial, polynomial);
void printPoly(polynomial);
void main() {
	polynomial A = { 3, {4,3,5,0} };
	polynomial B = { 4, {3,1,0,2,1} };

	polynomial C;
	C = addPoly(A, B);

	printf("\n A(x) = "); printPoly(A);
	printf("\n B(x) = "); printPoly(B);
	printf("\n C(x) = "); printPoly(C);
	getchar();
}

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree)
	{
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++];
			A.degree--;
		}
		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else {
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;
}

void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i < P.degree; i++)
	{
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" +");
	}
	printf(" \n");
}