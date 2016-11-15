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

	doge = &dog;
	doge->name = name;
	doge->age = age;
	doge->owner = owner;

	if (doge == NULL)
		return (NULL);

	return (doge);
}
