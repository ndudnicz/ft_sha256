#include <string.h>

#include "options.h"
#include "map_file.h"
#include "read_input.h"

int		main(int ac, char **av)
{
	t_opt	opt;
	char	*data;

	data = NULL;
	bzero(&opt, sizeof(t_opt));
	get_options(&opt, &ac, av);
	if (opt.options & OPT_FILE) {
		data = (char*)map_file(&opt);
	} else {
		data = read_input();
	}
	// printf("%s\n", data);
	return (0);
}
