#include "ft_sh.h"

t_ast	*fake_ast();

extern char		*g_cmd_symbols[MAX_CMDTYPE + 1];

char			*g_cmd_symbols[] = {
	[SEP] = ";",
	[AND] = "&&",
	[OR] = "||",
	[NEGATE] = "!",
	[PIPE] = "|",
	[CMD] = NULL
};

extern char		*g_cmd_names[MAX_CMDTYPE + 1];

char			*g_cmd_names[] = {
	[SEP] = "separator",
	[AND] = "and_list",
	[OR] = "or_list",
	[NEGATE] = "negation",
	[PIPE] = "pipe",
	[CMD] = "simple_cmd"
};

void	print_tokens(char **tokens)
{
	if (!tokens)
	{
		fprintf(stderr, "(null)");
		return;
	}
	fprintf(stderr, "%s", "[");
	int i = 0;
	while (tokens[i])
	{
		fprintf(stderr, "'%s'%s", tokens[i], tokens[i + 1] ? ", " : "]");
		++i;
	}
}

void	print_node(t_ast *a)
{
	if (!a)
		fprintf(stderr, "%s", NULL);
	else
		print_tokens(a->tokens);
}

t_ast	*ast_node()
{
	t_ast *ast = ft_memalloc(sizeof(*ast));
	return (ast);
}

void	examine_tree(t_ast *a)
{
	if (a == NULL)
		return ;
	print_tokens(a->tokens);fprintf(stderr, ": My type is '%s'!", g_cmd_names[a->type]);
	if (a->lchild == NULL && a->rchild == NULL)
		fprintf(stderr, "\n\tNo children. :(\n");
	else
	{
		fprintf(stderr, "\n\tMy left child is "); print_node(a->lchild);
		fprintf(stderr, "\n\tand my right child is "); print_node(a->rchild); fputs(".", stderr);
	}
	examine_tree(a->lchild);
	examine_tree(a->rchild);
}

void	interpret_command(t_ast *a)
{
	printf("interpret command: "); print_node(a);
}

int		interpret_pipe(t_ast *a)
{
	pid_t		pid;
	int			status;

	if (a->type == NEGATE)
		return (!(interpret_pipe(a->lchild)));
	status = 0;
	pid = fork();
	/* actually set up a pipe tho. */
	if (pid < 0)
	{
		//report failure somehow
	}
	else if (pid == 0)
	{
		if (a->type == CMD)
			interpret_command(a);
		else
			interpret_command(a->lchild);
		_exit(1); // fail if we ever return. better than exit(1) for some reason
	}
	else
	{
		if (waitpid(pid, &status, 0) != pid)
			status = -1;
	}
	return (status);
}

void	interpret_list(t_ast *a, int ok_to_execute)
{
	if (a->type < LIST_PRECEDENCE)
	{
		interpret_pipe(a);
		return ;
	}
	if (ok_to_execute)
		ok_to_execute = interpret_pipe(a->lchild);
	ok_to_execute = (ok_to_execute && a->type != AND)
		|| (!ok_to_execute && a->type == OR)
		|| a->type == SEP;
	interpret_list(a->rchild, ok_to_execute);
}

int	main(void)
{
	return (0);
}
