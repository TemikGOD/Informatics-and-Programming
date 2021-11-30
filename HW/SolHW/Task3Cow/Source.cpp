#include <stdio.h>
#include <locale>
#include <time.h>
#include <math.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("������� ����� ������������� ����� � ��������� �� 2 �� 5\n");
	int n;
	scanf_s("%d", &n);
	while (n < 2 || n >5)
	{
		printf("������� ����� ������� �� 2 �� 5, � �� �� ��� �� ��������, ���������\n");
		scanf_s("%d", &n);
	}
	srand(time(0));
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = rand() % 10;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((arr[i] == arr[j]) && (i != j))
				arr[i] = rand() % 10;
		}
	}
	int c = 0;
	while (c != 1)
	{
		int play;
		int bull = 0;
		int cow = 0;
		printf("������� ����� ������� %d ��� ������� 0, ����� �������\n", n);
		scanf_s("%d", &play);
		if (play == 0)
		{
			printf("������");
			break;
		}
		int* arrplay = new int[n];
		for (int i = 0; i < n; ++i)
		{
			int per = play / pow(10, n - i - 1);
			if (per < 10)
				arrplay[i] = per;
			else 
				arrplay[i] = per % 10;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i] == arrplay[j])
				{
					if (i == j)
						bull += 1;
					else
						cow += 1;
				}
			}
		}
		delete[] arrplay;
		printf("�����: %d	�����: %d\n", cow, bull);
		if (bull == n)
		{
			c = 1;
			printf("����������! �� ��������! �� ������ �� �������� ����� ��� ������!\n");
		}
	}
	delete[] arr;
}