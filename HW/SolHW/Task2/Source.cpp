#include <stdio.h>
#include <locale>
#include <time.h>
#include <string>
int main()
{
	setlocale(LC_ALL, "Russian");
	int work = 1;
	while (work != 0)
	{
		int var;
		printf("1 - ��������, 2 - �������� ���� � �����, 0 - ����� �� ���������\n");
		scanf_s("%d", &var);
		switch (var)
		{
		case 1:
		{
			int kto;
			printf("�������� ����, ��� ���������� �����\n1 - ��������� 2 - ������������\n");
			scanf_s("%d", &kto);
			switch (kto)
			{
			case 1:
			{
				srand(time(0));
				int number = 1 + rand() % 1000;
				int count = 0;
				int work1 = 1;
				while (work1 != 0)
				{
					int numberp;
					printf("������ �����\n");
					scanf_s("%d", &numberp);
					if (number > numberp)
						printf("���������� ����� ������\n");
					else
						if (number < numberp)
							printf("���������� ����� ������\n");
						else
						{
							printf("�������\n");
							work1 = 0;
						}
					count++;
				}
				printf("�� ������� ����� � %d �������\n", count);
				break;
			}
			case 2:
			{
				int number = 500;
				int shag = 250;
				int count = 0;
				int work1 = 1;
				printf("��������� ����� �� 1 �� 1000\n");
				while (work1 != 0)
				{
					char znak;
					printf("������� < ���� ��� ������ ��� %d, > - ���� ������, = - ���� �����\n", number);
					scanf_s(" %c", &znak);
					if (znak == '<')
					{
						number -= shag;
						count++;
						shag /= 2;
					}
					else
						if (znak == '>')
						{
							number += shag;
							count++;
							shag /= 2;
						}
						else
							if (znak == '=')
							{
								work1 = 0;
								count++;
							}
							else
								printf("������� �������� ��������\n");
				}
				printf("��������� ������� ����� � %d �������\n", count);
				break;
			}
			default:
				printf("������� �������� ��������\n");
				break;
			}
			break;
		}
		case 2:
		{
			char stroka[1000];
			gets_s(stroka);
			printf("%c", stroka);
			//for (int i = 0; i < );
			break;
		}
		case 0:
			work = 0;
			break;
		default:
			printf("������� �������� ��������\n");
			break;
		}
	}
}