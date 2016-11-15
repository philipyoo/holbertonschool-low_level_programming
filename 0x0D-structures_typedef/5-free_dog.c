#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - free the dogs
 * @d: pointer to dog struct
 */

void free_dog(dog_t *d)
{
	free(d->name);
	free(d->age);
	free(d->owner);

	free(d);
}
