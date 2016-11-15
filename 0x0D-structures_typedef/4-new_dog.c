#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - create a new dog
 * @name: char string name
 * @age: int age
 * @owner: char string owner
 * Return: pointer to new dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	struct dog *doge;
	int i, j;
	char *n, *o;

	doge = malloc(sizeof(struct dog));
	if (doge == NULL)
		return (NULL);

	for (i = 0; name[i] != '\0'; i++)
		;
	for (j = 0; owner[j] != '\0'; j++)
		;

	n = malloc(sizeof(char) * i + 1);
	if (n == NULL)
		return (NULL);
	o = malloc(sizeof(char) * j + 1);
	if (o == NULL)
		return (NULL);

	doge->name = _strncpy(n, name, i);
	doge->age = age;
	doge->owner = _strncpy(o, owner, j);

	return (doge);
}

char *_strncpy(char *d, char *s, int n)
{
	int i;

	for (i = 0; i < n; i++)
		d[i] = s[i];
	d[i++] = s[i];

	return (d);
}
