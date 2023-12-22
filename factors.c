#include <stdio.h>

/**
 * factorize - Finds and prints the factorization of a number
 * @num: The number to factorize
 */
void factorize(int num)
{
	int i;

	for (i = 2; i <= num; ++i)
	{
		while (num % i == 0)
		{
			/* i is a factor, print the factorization */
			printf("%d=%d*", num, i);
			num /= i;
		}
	}
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (1);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	int num;

	while (fscanf(file, "%d", &num) == 1)
	{
		factorize(num);
		printf("\n");
	}

	fclose(file);

	return (0);
}
