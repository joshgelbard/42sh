#include "ft_sh.h"
#include "ast.h"

char	*g_cmd_symbols[] =
{
	[SEP] = ";",
	[AND] = "&&",
	[OR] = "||",
	[NEGATE] = "!",
	[PIPE] = "|",
	[CMD] = NULL
};

char	*g_cmd_names[] =
{
	[SEP] = "separator",
	[AND] = "and_list",
	[OR] = "or_list",
	[NEGATE] = "negation",
	[PIPE] = "pipe",
	[CMD] = "simple_cmd"
};

t_ast	*ast_node(void)
{
	t_ast *a;

	a = ft_memalloc(sizeof(*a));
	a->ok = 1;
	return (a);
}

t_ast	*opnode(t_cmdtype type)
{
	t_ast *a;

	a = ast_node();
	a->type = type;
	a->tokens = ft_memalloc(sizeof(char *) * 2);
	a->tokens[0] = g_cmd_symbols[type];
	return (a);
}

t_ast	*cmd_node(char **tokens)
{
	t_ast *a;

	a = ast_node();
	a->type = CMD;
	a->tokens = tokens;
	return (a);
}