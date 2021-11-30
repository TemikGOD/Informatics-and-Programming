#include <stdio.h>
#include <malloc.h>
#include <locale>
#include <random>
#include <time.h>

int main()
{
	int* massive;
	int RangeMass = 0;
	int index = 0; 
	int NewElem = 0;
	int SummChetNum = 0;
	int SummChetIndex = 0;
	int* RevMassive;
	
	setlocale(LC_ALL, "Russian");
	printf_s("������� ����� �������\n");
	scanf_s("%d", &RangeMass);
	massive = (int*)malloc(RangeMass * sizeof(int));
	srand(time(0));
	for (int i = 0; i < RangeMass; i++)
		massive[i] = rand() % 19 - 9;
	printf_s("������:\n");
	for (int i = 0; i < RangeMass; i++)
		printf_s(" %d", massive[i]);
	
	for (int i = 0; i < RangeMass; i++)
		if (massive[i] % 2 == 0)
			SummChetNum += massive[i];
	printf_s("\n����� ������ ���������: %d\n", SummChetNum);
	
	for (int i = 0; i < RangeMass; i += 2)
		SummChetIndex += massive[i];
	printf_s("����� ��������� � ������� ���������: %d\n", SummChetIndex);
	
	printf_s("������� ������ ��������, ������� ������ ��������\n");
	scanf_s("%d", &index);
	printf_s("������� ����� �������� ��� �������� � �������� %d\n", index);
	scanf_s("%d", &NewElem);
	massive[index] = NewElem;
	printf_s("������:\n");
	for (int i = 0; i < RangeMass; i++)
		printf_s(" %d", massive[i]);
	
	printf_s("\n������� ������ ��������, � �������� ������ �������� ����\n");
	scanf_s("%d", &index);
	massive[index] = massive[index] * -1;
	printf_s("������:\n");
	for (int i = 0; i < RangeMass; i++)
		printf_s(" %d", massive[i]);
	
	for (int i = 0; i < RangeMass/2; i++)
	{
		int elem = massive[i];
		massive[i] = massive[RangeMass - 1 - i];
		massive[RangeMass - 1 - i] = elem;
	}
	printf_s("\n����������� ������:\n");
	for (int i = 0; i < RangeMass; i++)
		printf_s(" %d", massive[i]);

	RevMassive = (int*)malloc(RangeMass * sizeof(int));
	for (int i = 0; i < RangeMass; i++)
		RevMassive[i] = massive[RangeMass - 1 - i];
	printf_s("\n����������� ������:\n");
	for (int i = 0; i < RangeMass; i++)
		printf_s(" %d", RevMassive[i]);

	free(massive);
	free(RevMassive);
}