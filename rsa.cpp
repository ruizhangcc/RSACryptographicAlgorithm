#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char stri[100],stro[100];
	int prime(int a);
	int cf(long long int a,int b);
	int rand();
	int p=4, q=4,f,n,i,j=1,k,e1=3,e2,flag=1,c,a[100],o;
	long long int mwi[100], mwo[100];
	
	
	while (flag == 1)
	{
		while (p == 0 || p == 1 || prime(p) == 0)
		{
			p = rand() % 12 ;
		}
		while (q == 0 || q == 1 || prime(q) == 0)
		{
			q = rand() % 12;
		}
		printf("p=%d,q=%d", p, q);           /*�����������0-25������*/
		n = p*q;
		f = (p - 1)*(q - 1);                 /*����n��f��ֵ*/
		for (e2 = 1; e2 <1000; e2++)                  /*����һ��e2��ʹ��e1*e2��f������Ϊ1*/
		{
			/*printf("e2=%d",e2);*/
			if ((e1*e2) % f == 1)
				break;
		}
		
		if (e2 == 1000)flag = 1;
		else flag = 0;
	}
	printf("\ngong(%d,%d),si(%d,%d),%d\n",e1,n,e2,n,f);    /*�õ���Կ��e1��n����˽Կ��e2��n��*/
	printf("���������ģ�");
	gets_s(stri);
	for (i = 0; i < 100; i++)
	{
		if (stri[i] == NULL)break;
		for (j = 1;; j++)
		{
			mwi[i] = j;
			if (mwi[i] % n == cf(int(stri[i])-96, e1) % n)
				break;
		}
	}
	printf("\n����Ϊ��");
	for (j = 0; j < i; j++)
	{
		printf("%d ", mwi[j]);
	}
	printf("\n");
	printf("����������������֣�\n");
	for (k = 1; k <= i; k++)
	{
		scanf_s("%d", &mwo[k]);
	}
	for (k = 1; k <= i; k++)
		printf("%d ",mwo[k]);

	printf("\n����Ϊ��");
	printf("%d,%d\n",n,e2);
	for (o = 1; o <= i; o++)
	{
		for (j = 1; j < 10000; j++)
		{
			a[o] = j;
			if (a[o] % n ==(cf(mwo[o], e2) % n))
				break;
		}
	}
	for (o = 1; o <= i; o++)
	{
		printf("%d ", a[o]);
	}
	printf("\n");
	return 0;
}

int prime(int a)
{
	int i;
	for (i = 2; i <= (a / 2);i++)
	if (a%i == 0)break;
	if (i > (a / 2))return 1;
	else return 0;
}

int cf(long long int a, int b)
{
	int i;
	long long int m = 1;
	for (i = 1; i <= b; i++)
		m = m*a;
	return m;
}