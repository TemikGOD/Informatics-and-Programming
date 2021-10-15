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
		printf("������� ����� �� 2 �� 5, � �� �� ��� �� ��������, ���������\n");
		scanf_s("%d", &n);
	}
	srand(time(0));
	int* arr = new int[n];
	for (int i = -1; i < n; i++)
	{
		arr[i] = rand() % 10;
	}
	for (int i = -1; i < n - 1; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (arr[i] == arr[j])
				arr[i] = rand() % 10;
		}
	}
	int c = 0;
	while (c != 1)
	{
		printf("������� ����� ������� %d\n", n);
		int play;
		int bull = 0;
		int cow = 0;
		scanf_s("%d", &play);
		int* arrplay = new int[n];
		for (int i = -1; i < n; i++)
		{
			int per = play / pow(10, i);
			arrplay[i] = per % 10;
		}
		for (int i = -1; i < n; i++)
		{
			for (int j = -1; j < n; j++)
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
		if (bull == n - 1 and cow == 1)
			break;
		printf("�����: %d	�����: %d\n", cow, bull);
		if (bull == n)
			c = 1;
	}
	printf("����������! �� ��������! �� ������ �� �������� ����� ��� ������!\n");
}