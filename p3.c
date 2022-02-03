#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void push_swap3(int a[])
{
	if ((a[0] < a[1]) && (a[1] > a[2]) && (a[0] < a[2]))
	write(STDOUT_FILENO, "rra\nsa\n", 7);
	if ((a[0] > a[1]) && (a[1] < a[2]) && (a[0] < a[2]))
	write(STDOUT_FILENO, "sa\n", 3);	
	if ((a[0] < a[1]) && (a[1] > a[2]) && (a[0] > a[2]))
	write(STDOUT_FILENO, "rra\n", 4);
	if ((a[0] > a[1]) && (a[1] < a[2]) && (a[0] > a[2]))
	write(STDOUT_FILENO, "ra\n", 3);
	if ((a[0] > a[1]) && (a[1] > a[2]) && (a[0] > a[2]))
	write(STDOUT_FILENO, "ra\nsa\n", 6);
}

int main(int argc, char *argv[])
{
	int n[3];
	n[0] = atoi(argv[1]);
	n[1] = atoi(argv[2]);
	n[2] = atoi(argv[3]);
	push_swap3(n);
	return 0;
}



void	pb(int **a, int **b, int **tops)
{
	write(STDOUT_FILENO, "pb\n", 3);
	(*b)[(*tops)[1]] = (*a)[(*tops)[0]];
	(*a)[(*tops)[0]] = -1;
	(*tops)[0] = (*tops)[0] + 1;
	(*tops)[1] = (*tops)[0] - 1;
}

void	initialize(int **a, int **b, int **tops, int n[])
{
	int	i;

	*a = (int *)malloc(5 * sizeof(int));
	*b = (int *)malloc(5 * sizeof(int));
	*tops = (int *)malloc(2 * sizeof(int));
	if (!a || !b || !tops)
		exit(-1);
	i = 0;
	while (i < 5)
	{
		(*a)[i] = n[i];
		(*b)[i] = -1;
	}
	(*tops)[0] = 0;
	(*tops)[1] = 4;
}

void	ra(int **a)
{
	int aux;

	write(STDOUT_FILENO, "ra\n", 3);
	aux = (*a)[4];
	(*a)[4] = (*a)[2];
	(*a)[2] = (*a)[3];
	(*a)[3] = aux;
}

void	rra(int **a)
{
	int aux;

	write(STDOUT_FILENO, "rra\n", 4);
	aux = (*a)[2];
	(*a)[2] = (*a)[4];
	(*a)[3] = (*a)[2];
	(*a)[4] = aux;

}

void	sa(int **a)
{
	int aux;

	write(STDOUT_FILENO, "sa\n", 3);
	aux = (*a)[2];
	(*a)[2] = (*a)[3];
	(*a)[3] = aux;

}

void push_swap3_5(int **a)
{
	if ((a[0] < a[1]) && (a[1] > a[2]) && (a[0] < a[2]))
	{
		rra(a);
		sa(a);
	}
	if ((a[0] > a[1]) && (a[1] < a[2]) && (a[0] < a[2]))
		sa(a);	
	if ((a[0] < a[1]) && (a[1] > a[2]) && (a[0] > a[2]))
		rra(a);
	if ((a[0] > a[1]) && (a[1] < a[2]) && (a[0] > a[2]))
		ra(a);
	if ((a[0] > a[1]) && (a[1] > a[2]) && (a[0] > a[2]))
	{
		ra(a);
		sa(a);
	}
}

void	push_swap5(int n[])
{
	int *a;
	int *b;
	int *tops;

	initialize(&a, &b, &tops, n);
	pb(&a, &b, &tops);
	pb(&a, &b, &tops);
	push_swap3_5(&a);

}