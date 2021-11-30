#include <stdio.h>
#include <locale>

int main()
{
	setlocale(LC_ALL, "Russian");
	int num;
	int end = 1;
	while (end)
	{
		printf_s("¬ведите положительное целое число дл€ инверсии или 0 дл€ выхода\n");
		scanf_s("%d", &num);
		while (num < 0)
		{
			printf_s("¬ведите ѕќЋќ∆»“≈Ћ№Ќќ≈ число\n");
			scanf_s("%d", &num);
		}
		if (num == 0)
			break;
		while (num % 10 == 0)
			num = num / 10;
		while(num)
		{
			printf("%d", num % 10);
			num = num / 10;
		}
		printf_s("\n");
	}
}