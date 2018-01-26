#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "error.h"
#include "read_input.h"
#include "libft.h"

char*
read_input(void) {
	char	buf[BUFF_SIZE] = {0};
	int		ret = 0;
	char	*data = NULL;

	while ((ret = read(0, buf, BUFF_SIZE - 1)) > 0) {
		buf[ret] = 0;
		if (!data) {
			data = strdup(buf);
		} else {
			if (!(data = ft_strjoin_free(data, buf, 1, 0)))
				return ((char*)((long int)ft_error("Error", "read_input()", MALLOC_FAILED, 0)));
		}
	}
	return (data);
}
