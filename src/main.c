#include <string.h>

#include "options.h"
#include "map_file.h"
#include "read_input.h"
#include "fit_data.h"
#include "hash.h"

int
main(int ac, char **av) {
	t_opt	opt;
	char	*data;

	data = NULL;
	bzero(&opt, sizeof(t_opt));
	get_options(&opt, &ac, av);
	if (opt.options & OPT_FILE) {
		data = (char*)map_file(&opt);
	} else {
		data = read_input();
		opt.size = (__int32_t)strlen(data);
	}
	data = fit_data(data, &opt);
	// while (1);
	return (hash_this((int*)data, &opt));
	// return (0);
}
