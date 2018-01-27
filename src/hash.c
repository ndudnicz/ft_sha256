#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "options.h"

#define ABS(X) X < 0 ? -X : X

int
leftrotate(uint32_t m, uint32_t const n) {
	for (uint32_t i = 0; i < n; ++i) {
		m = m << 8 | m >> 24;
	}
	return (m);
}

int
hash_this(char *data, t_opt const *options) {
	uint32_t 	h0 = 0x67452301;
	uint32_t 	h1 = 0xEFCDAB89;
	uint32_t 	h2 = 0x98BADCFE;
	uint32_t 	h3 = 0x10325476;
	uint32_t		k[64] = {0};
	uint32_t		r[64] = {
		7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
		5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
		4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
		6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
	};
	int			*w = (int*)malloc(sizeof(int) * 16);

	for (size_t i = 0; i < 64; ++i) {
		k[i] = (uint32_t)(floor(ABS(sin(i + 1))) * 4294967296);
	}
	for (__int32_t i = 0; i < options->new_size; i += 64) {
		uint32_t	a = h0;
		uint32_t	b = h1;
		uint32_t	c = h2;
		uint32_t	d = h3;
		uint32_t	f, g = 0;

		memcpy((void*)w, (void*)&data[i], 64);
		for (int i = 0; i < 16; ++i) {
			printf("%08x", w[i]);
		}
		printf("\n");
		for (__int32_t j = 0; j < 64; ++j) {
			if (i < 16) {
				f = (b & c) | ((~b) & d);
				g = j;
			} else if (i < 32) {
				f = (d & b) | ((~d) & c);
				g = (5 * j + 1) % 16;
			} else if (i < 48) {
				f = b ^ c ^ d;
				g = (3 * j + 5) % 16;
			} else {
				f = c ^ (b | (~d));
				g = (7 * j) % 16;
			}
			uint32_t	tmp = d;
			d = c;
			c = b;
			b = leftrotate((a + f + k[j] + w[g] /* swapbit(w[g]) ? */ ), r[j]) + b;
			a = tmp;
		}
		h0 += a;
		h1 += b;
		h2 += c;
		h3 += d;
	}
	printf("%x %x %x %x\n", h0, h1, h2, h3);
	return (0);
}
