#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "options.h"
#include "error.h"

void*
map_file(t_opt *options) {
	int			fd = open(options->filename, O_RDONLY);
	struct stat	s;
	void		*ret = NULL;

	if (fd < 0) {
		return ((void*)((long int)ft_error("Error", "map_file()", OPEN_FAILED, 0)));
	} else {
		fstat(fd, &s);
		if (S_ISREG(s.st_size)) {
			options->size = s.st_size;
			ret = mmap(0, s.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
			return (ret ? ret : (void*)((long int)ft_error("Error", "map_file()", MMAP_FAILED, 0)));
		} else {
			return (ret ? ret : (void*)((long int)ft_error("Error", "map_file()", INVALID_INPUT_FILE, 0)));
		}
	}
}
