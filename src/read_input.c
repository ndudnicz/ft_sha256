#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "error.h"
#include "read_input.h"
#include "libft.h"

uint8_t*
read_input(void) {
	char	buf[BUFF_SIZE] = {0};
	int		ret = 0;
	uint8_t	*data = NULL;

	while ((ret = read(0, buf, BUFF_SIZE - 1)) > 0) {
		buf[ret] = 0;
		if (!data) {
			data = (uint8_t*)strdup(buf);
		} else {
			if (!(data = (uint8_t*)ft_strjoin_free((char*)data, buf, 1, 0)))
				return ((uint8_t*)((long int)ft_error("Error", "read_input()", MALLOC_FAILED, 0)));
		}
	}
	return (data);
}
