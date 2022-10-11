#include <stdio.h>
#include <locale>
/// <summary>
/// Вывод фигур
/// </summary>
/// <param name="i1">координата по x 1 клетки</param>
/// <param name="i2">координата по y 1 клетки</param>
/// <param name="j1">координата по x 2 клетки</param>
/// <param name="j2">координата по y 2 клетки</param>
/// <param name="fig"></param>
void figur(int i1, int i2, int j1, int j2, int fig)
{
	printf("Выбранная фигура не может перейти из клетки %d %d в клетку %d %d за один ход\nФигуры, которые могут сделать это: ", i1, j1, i2, j2);
	int numfig = 0;
	if (abs(i1 - i2) <= 1 && abs(j1 - j2 <= 1) && fig != 1)
	{
		printf("Король ");
		numfig++;
	}
	if ((i1 == i2 || j1 == j2 || abs(i1 - i2) == abs(j1 - j2)) && fig != 2)
	{
		printf("Ферзь ");
		numfig++;
	}
	if ((i1 == i2 || j1 == j2) && fig != 3)
	{
		printf("Ладья ");
		numfig++;
	}
	if ((abs(i1 - i2) == abs(j1 - j2)) && fig != 4)
	{
		printf("Слон ");
		numfig++;
	}
	if ((abs(i1 - i2) == 2 && abs(j1 - j2) == 1 || abs(i1 - i2) == 1 && abs(j1 - j2) == 2) && fig != 5)
	{
		printf("Конь ");
		numfig++;
	}
	if (numfig == 0)
		printf("Никакие");
	printf("\n");
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int var = 1;
	while (var != 0)
	{
		printf("1 - масса шкафа, 2 - Шахматы, 0 - выход из программы\n");
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
			double wood = 700; //плотнсть ДСП = 550 кг/м3 ДВП = 820 кг/м3 дерева(берёза) = 700 кг/м3
			printf("Введите высоту в диапазоне от 1,8 до 2,2 м\n");
			scanf_s("%lf", &h);
			printf("Введите ширину в диапазоне от 0,8 до 1,2 м\n");
			scanf_s("%lf", &w);
			printf("Введите глубину в диапазоне от 0,5 до 0,9 м\n");
			scanf_s("%lf", &d);
			m = Dvp * h * w * 0.005;
			m += 2 * Dsp * h * d * 0.015;
			m += 2 * Dsp * w * d * 0.015;
			m += wood * h * w * 0.01;
			m += Dsp * int(h / 0.4) * w * d * 0.01; //толщину полок взял за 0,01м, так как в условии не указана их толщина
			printf("Масса шкафа = %.2lf кг\n", m);
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
					printf("Введите номер первой клетки по оси x от 1 до 8 или введите 0, чтобы выйти\n");
					scanf_s("%d", &i1);
					if (i1 < 0 || i1 > 8)
						printf("Введено неверное значение\n");
				} while (i1 < 0 || i1 > 8);
				if (i1 == 0)
					break;
				do
				{
					printf("Введите номер первой клетки по оси y от 1 до 8\n");
					scanf_s("%d", &j1);
					if (j1 < 1 || j1 > 8)
						printf("Введено неверное значение\n");
				} while (j1 < 1 || j1 > 8);
				do
				{
					printf("Введите номер второй клетки по оси x от 1 до 8\n");
					scanf_s("%d", &i2);
					if (i2 < 1 || i2 > 8)
						printf("Введено неверное значение\n");
				} while (i2 < 1 || i2 > 8);
				do
				{
					printf("Введите номер второй клетки по оси y от 1 до 8\n");
					scanf_s("%d", &j2);
					if (j2 < 1 || j2 > 8)
						printf("Введено неверное значение\n");
				} while (j2 < 1 || j2 > 8);
				printf("Выберите фигуру:\n 1 - король, 2 - ферзь, 3 -ладья, 4 - слон, 5 - конь\n");
				scanf_s("%d", &fig);
				switch (fig)
				{
				case 1:
					if (abs(i1 - i2) <= 1 && abs(j1 - j2 <= 1))
						printf("Выбранная фигура может перейти из клетки %d %d в клетку %d %d за один ход\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				case 2:
					if (i1 == i2 || j1 == j2 || abs(i1 - i2) == abs(j1 - j2))
						printf("Выбранная фигура может перейти из клетки %d %d в клетку %d %d за один ход\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				case 3:
					if (i1 == i2 || j1 == j2)
						printf("Выбранная фигура может перейти из клетки %d %d в клетку %d %d за один ход\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				case 4:
					if (abs(i1 - i2) == abs(j1 - j2))
						printf("Выбранная фигура может перейти из клетки %d %d в клетку %d %d за один ход\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				case 5:
					if (abs(i1 - i2) == 2 && abs(j1 - j2) == 1 || abs(i1 - i2) == 1 && abs(j1 - j2) == 2)
						printf("Выбранная фигура может перейти из клетки %d %d в клетку %d %d за один ход\n", i1, j1, i2, j2);
					else
						figur(i1, i2, j1, j2, fig);
					break;
				default:
					printf("Введено неверное значение\n");
					break;
				}
			}
			break;
		}
		default:
			printf("Введено неверное значение\n");
			break;
		}
	}
	return 0;
}