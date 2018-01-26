#include <stdio.h>

int
ft_error(char const *s1, char const *s2, char const *s3, int const ret) {
	printf("%s: %s: %s\n", s1, s2, s3);
	return (ret);
}
