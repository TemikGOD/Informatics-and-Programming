#include <stdio.h>
#include <locale>
int main()
{
	setlocale(LC_ALL, "Russian");
	int num, a, b;
	printf("������� �����\n");
	scanf_s("%d", &num);
	printf("�������� ��������� ���� �����: ");
	do
	{
		a = num % 10;
		printf("%d", a);
		num = num / 10;
	} while (num != 0);
	return 0;
}