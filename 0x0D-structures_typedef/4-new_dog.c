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
	struct dog dog;
	struct dog *doge;

	doge = malloc(sizeof(struct dog));
	if (doge == NULL)
		return (NULL);

	doge->name = name;
	doge->age = age;
	doge->owner = owner;

	return (doge);
}
