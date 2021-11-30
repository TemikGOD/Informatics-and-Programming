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
		printf("1 - Угадайка, 2 - Считалка слов и чисел, 0 - выход из программы\n");
		scanf_s("%d", &var);
		switch (var)
		{
		case 1:
		{
			int kto;
			printf("Выберите того, кто загадывает число\n1 - Программа 2 - Пользователь\n");
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
					printf("Угадай число\n");
					scanf_s("%d", &numberp);
					if (number > numberp)
						printf("Загаданное число больше\n");
					else
						if (number < numberp)
							printf("Загаданное число меньше\n");
						else
						{
							printf("Угадали\n");
							work1 = 0;
						}
					count++;
				}
				printf("Вы угадали число с %d попытки\n", count);
				break;
			}
			case 2:
			{
				int number = 500;
				int shag = 250;
				int count = 0;
				int work1 = 1;
				printf("Загадайте число от 1 до 1000\n");
				while (work1 != 0)
				{
					char znak;
					printf("Введите < если оно меньше чем %d, > - если больше, = - если равно\n", number);
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
								printf("Введено неверное значение\n");
				}
				printf("Программа угадала число с %d попытки\n", count);
				break;
			}
			default:
				printf("Введено неверное значение\n");
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
			printf("Введено неверное значение\n");
			break;
		}
	}
}