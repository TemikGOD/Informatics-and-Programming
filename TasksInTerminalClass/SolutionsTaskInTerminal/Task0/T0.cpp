#include <stdio.h>
#include <locale>
int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 5;
	while (n != 0)
	{
		printf("1 - �����������		2 - ������������� 	 3 - ����������		0 - ����� �� ���������\n");
		scanf_s("%d", &n);
		double a = 0;
		double b = 0;
		double S = 0;
		switch (n)
		{
		case 0:
			break;
		case 1:
		{
			printf("������� ������ � ��������� ������������\n");
			scanf_s("%lf %lf", &a, &b);
			S = a * b * 0.5;
			printf("������� ������������ = %.2lf\n", S);
			break;
		}
		case 2:
		{
			printf("������� 2 ������� ��������������\n");
			scanf_s("%lf %lf", &a, &b);
			S = a * b;
			printf("������� �������������� = %.2lf\n", S);
			break;
		}
		case 3:
		{
			printf("������� ������ ����������\n");
			scanf_s("%lf", &a);
			S = 3.14 * a * a;
			printf("������� ���������� = %.2lf\n", S);
			break;
		}
		default:
		{
			printf("������� ���� �� ������������ ����, ���������\n");
			break;
		}
		}
	}
	return 0;
}