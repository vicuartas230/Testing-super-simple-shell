#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct env
{
	const char *s;
	struct env *next;
} envir;

extern char **environ;

envir *build_path(envir **head, const char *s)
{
	envir *new = NULL, *tmp = NULL;

	new = malloc(sizeof(envir));
	if (new == NULL)
		return (NULL);
	new->s = s;
	new->next = NULL;
	tmp = *head;
	if (*head == NULL)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (*head);
}

size_t print_listint(const envir *h)
{
	size_t i = 0;

	while (h != NULL)
	{
		printf("%s\n", h->s);
		h = h->next;
		i++;
	}
	return (i);
}

int main(void)
{
	envir *head = NULL;

	while(*environ)
	{
		build_path(&head, *environ);
		environ++;
	}
	print_listint(head);
	return (0);
}
