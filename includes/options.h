#ifndef OPTIONS_H
# define OPTIONS_H

# include <sys/stat.h>
# include <stdint.h>

# define OPT_FILE		0x01
# define OPT_FILE_CHAR	'f'
# define PARAMS_STR		"f"

typedef struct	s_opt {
	char			*filename;
	uint64_t		size;
	uint64_t		new_size;
	unsigned char	options;
}				t_opt;

int		get_options(t_opt *options, int *ac, char **av);

#endif /* OPTIONS_H */
