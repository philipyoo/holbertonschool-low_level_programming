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

	doge->name = _strcpy(n, name);
	doge->age = age;
	doge->owner = _strcpy(o, owner);

	return (doge);
}

char *_strcpy(char *d, char *s)
{
	int i;

	for (i = 0; d[i] != '\0'; i++)
		d[i] = s[i];
	d[i] = '\0';

	return (d);
}
