#include <stdio.h>
#include <locale>
/// <summary>
/// ����� �����
/// </summary>
/// <param name="i1">���������� �� x 1 ������</param>
/// <param name="i2">���������� �� y 1 ������</param>
/// <param name="j1">���������� �� x 2 ������</param>
/// <param name="j2">���������� �� y 2 ������</param>
/// <param name="fig"></param>
void figur(int i1, int i2, int j1, int j2, int fig)
{
	printf("��������� ������ �� ����� ������� �� ������ %d %d � ������ %d %d �� ���� ���\n������, ������� ����� ������� ���: ", i1, j1, i2, j2);
	int numfig = 0;
	if (abs(i1 - i2) <= 1 && abs(j1 - j2 <= 1) && fig != 1)
	{
		printf("������ ");
		numfig++;
	}
	if ((i1 == i2 || j1 == j2 || abs(i1 - i2) == abs(j1 - j2)) && fig != 2)
	{
		printf("����� ");
		numfig++;
	}
	if ((i1 == i2 || j1 == j2) && fig != 3)
	{
		printf("����� ");
		numfig++;
	}
	if ((abs(i1 - i2) == abs(j1 - j2)) && fig != 4)
	{
		printf("���� ");
		numfig++;
	}
	if ((abs(i1 - i2) == 2 && abs(j1 - j2) == 1 || abs(i1 - i2) == 1 && abs(j1 - j2) == 2) && fig != 5)
	{
		printf("���� ");
		numfig++;
	}
	if (numfig == 0)
		printf("�������");
	printf("\n");
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int var = 1;
	while (var != 0)
	{
		printf("1 - ����� �����, 2 - �������, 0 - ����� �� ���������\n");
		scanf_s("%d", &var);
		switch (var)
		{
		case 0:
			break;
		case 1:
		{
			double h, w, d, m;
			double Dsp = 550;
			double Dvp = 820;
			double wood = 700; //�������� ��� = 550 ��/�3 ��� = 820 ��/�3 ������(�����) = 700 ��/�3
			printf("������� ������ � ��������� �� 1,8 �� 2,2 �\n");
			scanf_s("%lf", &h);
			printf("������� ������ � ��������� �� 0,8 �� 1,2 �\n");
			scanf_s("%lf", &w);
			printf("������� ������� � ��������� �� 0,5 �� 0,9 �\n");
			scanf_s("%lf", &d);
			m = Dvp * h * w * 0.005;
			m += 2 * Dsp * h * d * 0.015;
			m += 2 * Dsp * w * d * 0.015;
			m += wood * h * w * 0.01;
			m += Dsp * int(h / 0.4) * w * d * 0.01; //������� ����� ���� �� 0,01�, ��� ��� � ������� �� ������� �� �������
			printf("����� ����� = %.2lf ��\n", m);
		}
		break;
		case 2:
		{
			int i1 = 1, i2 = 1, j1 = 1, j2 = 1, fig;
			int sbeve = 1;
			while (sbeve != 0)
			{
				do
				{
					printf("������� ����� ������ ������ �� ��� x �� 1 �� 8 ��� ������� 0, ����� �����\n");
					scanf_s("%d", &i1);
					if (i1 < 0 || i1 > 8)
						printf("������� �������� ��������\n");
				} while (i1 < 0 || i1 > 8);
				if (i1 == 0)
					break;
				do
				{
					printf("������� ����� ������ ������ �� ��� y �� 1 �� 8\n");
					scanf_s("%d", &j1);
					if (j1 < 1 || j1 > 8)
						printf("������� �������� ��������\n");
				} while (j1 < 1 || j1 > 8);
				do
				{
					printf("������� ����� ������ ������ �� ��� x �� 1 �� 8\n");
					scanf_s("%d", &i2);
					if (i2 < 1 || i2 > 8)
						printf("������� �������� ��������\n");
				} while (i2 < 1 || i2 > 8);
				do
				{
					printf("������� ����� ������ ������ �� ��� y �� 1 �� 8\n");
					scanf_s("%d", &j2);
					if (j2 < 1 || j2 > 8)
						printf("������� �������� ��������\n");
				} while (j2 < 1 || j2 > 8);
				printf("�������� ������:\n 1 - ������, 2 - �����, 3 -�����, 4 - ����, 5 - ����\n");
				scanf_s("%d", &fig);
				switch (fig)
				{
				case 1:
					if (abs(i1 - i2) <= 1 && abs(j1 - j2 <= 1))
						printf("��������� ������ ����� ������� �� ������ %d %d � ������ %d %d �� ���� ���\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				case 2:
					if (i1 == i2 || j1 == j2 || abs(i1 - i2) == abs(j1 - j2))
						printf("��������� ������ ����� ������� �� ������ %d %d � ������ %d %d �� ���� ���\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				case 3:
					if (i1 == i2 || j1 == j2)
						printf("��������� ������ ����� ������� �� ������ %d %d � ������ %d %d �� ���� ���\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				case 4:
					if (abs(i1 - i2) == abs(j1 - j2))
						printf("��������� ������ ����� ������� �� ������ %d %d � ������ %d %d �� ���� ���\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				case 5:
					if (abs(i1 - i2) == 2 && abs(j1 - j2) == 1 || abs(i1 - i2) == 1 && abs(j1 - j2) == 2)
						printf("��������� ������ ����� ������� �� ������ %d %d � ������ %d %d �� ���� ���\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				default:
					printf("������� �������� ��������\n");
					break;
				}
			}
			break;
		}
		default:
			printf("������� �������� ��������\n");
			break;
		}
	}
	return 0;
}