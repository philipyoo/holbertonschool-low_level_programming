#include "holberton.h"

#define MAXSIZE 1204

/**
 * main - create the copy bash script
 * @ac: argument count
 * @av: arguments as strings
 * Return: 0
 */
int main(int ac, char *av[])
{
	int input_fd, output_fd, istatus, ostatus;
	char buf[MAXSIZE];

	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n"); exit(97);
	}

	input_fd = open(av[1], O_RDONLY);
	if (input_fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	output_fd = open(av[2], O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (output_fd == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}

	do {
		istatus = read(input_fd, buf, MAXSIZE);
		if (istatus == -1)
		{
			dprintf(2, "Error: Can't read from file %s\n", av[1]);
			exit(98);
		}
		ostatus = write(output_fd, buf, (ssize_t) istatus);
		if (ostatus == -1)
		{
			dprintf(2, "Error: Can't write to %s\n", av[2]);
			exit(99);
		}
	} while (istatus > 0);

	close(input_fd);
	close(output_fd);
	return (0);
}
