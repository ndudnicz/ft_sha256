#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "options.h"

#define SWAP(X) (X << 24 | ((X & 0x0000ff00) << 8) | ((X & 0x00ff0000) >> 8) | X >> 24)

int
leftrotate(int32_t m, int32_t const n) {
	return (m << n | m >> (32 - n));
}
#include <stdio.h>
int
hash_this(int *data, t_opt const *options) {
	int32_t		g, f;
	int32_t 	h0 = 0x67452301;
	int32_t 	h1 = 0xEFCDAB89;
	int32_t 	h2 = 0x98BADCFE;
	int32_t 	h3 = 0x10325476;
	int32_t		k[64] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
	};
	int32_t		r[64] = {
		7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,  7, 12, 17, 22,
		5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,  5,  9, 14, 20,
		4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,  4, 11, 16, 23,
		6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21,  6, 10, 15, 21
	};
	for (int32_t i = 0; i < options->new_size / (int32_t)sizeof(int); i += 16) {
		int32_t	a = h0;
		int32_t	b = h1;
		int32_t	c = h2;
		int32_t	d = h3;

		for (int32_t j = 0; j < 64; j++) {
			printf("%d %d %d\n", i, r[j], j);
			if (j <= 15) {
				f = (b & c) | ((~b) & d);
				g = j;
			} else if (j >= 16 && j <= 31) {
				f = (d & b) | ((~d) & c);
				g = ((5 * j) + 1) % 16;
			} else if (j>= 32 && j <= 47) {
				f = b ^ c ^ d;
				g = ((3 * j) + 5) % 16;
			} else {
				f = c ^ (b | (~d));
				g = (7 * j) % 16;
			}
			f = f + a + k[j] + data[i + g];
			a = d;
			d = c;
			c = b;
			b += leftrotate(f, r[j]);
		}
		h0 += a;
		h1 += b;
		h2 += c;
		h3 += d;
	}
	printf("%08x%08x%08x%08x\n", h0, h1, h2, h3);
	// free(w);
	return (0);
}
