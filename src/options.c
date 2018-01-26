#include <string.h>

#include "options.h"
#include "error.h"

/*
** Moves NULLs argv to the end of the array. Options are set in config
** and doesn't exist anymore in argv.
*/

static void
del_null_params(int *ac, char **av, int offset) {
	int		i;
	int		n;
	char	*tmp;

	n = 1;
	while (n < *ac)
	{
		i = 1;
		while (i < *ac - 1)
		{
			if (av[i] == NULL)
			{
				tmp = av[i];
				av[i] = av[i + 1];
				av[i + 1] = tmp;
			}
			i++;
		}
		n++;
	}
	*ac -= offset;
}

static int
set_filename(char const *exec_name, char const *param, t_opt *options) {
	options->options |= OPT_FILE;
	if (!param)
		return (ft_error(exec_name, "", INVALID_ARG, 1));
	else
		return ((options->filename = strdup(param)) ? 0 : ft_error(exec_name, "", MALLOC_FAILED, 1));
}

static int
switch_set_options(char const *exec_name, char const *arg, char const *param, t_opt *options) {
	if (!arg)
		return (0);
	else
		arg++;
	while (arg && *arg)
	{
		if (*arg && strchr(PARAMS_STR, (int)(*arg)))
		{
			switch (*arg) {
				case OPT_FILE_CHAR:
					return (set_filename(exec_name, param, options));
				default:
					return (ft_error(exec_name, "", UNKNOW_ARG, 1));
			}
		}
		else
			return (ft_error(exec_name, "", UNKNOW_ARG, 1));
		arg++;
	}
	return (0);
}

/*
** Parse argv and set argv[i] & argv[i + 1] at NULL if an options was found.
*/

int
get_options(t_opt *options, int *ac, char **av) {
	int		i;
	int		n;

	i = 1;
	n = 0;
	while (i < *ac)
	{
		if (av[i][0] == '-')
		{
			if (switch_set_options(av[0], av[i], av[i + 1], options) > 0)
				return (1);
			av[i] = NULL;
			av[i + 1] = NULL;
			n += 2;
			i += 2;
		}
		else
			i++;
	}
	del_null_params(ac, av, n);
	return (0);
}
