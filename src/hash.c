#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <stdint.h>

#include "options.h"

/*
** https://fr.wikipedia.org/wiki/SHA-2
*/

#define SWAP(X) (X << 24 | ((X & 0x0000ff00) << 8) | ((X & 0x00ff0000) >> 8) | X >> 24)
#define RIGHTROTATE(X,Y) ((X) >> (Y) | (X) << (32 - Y))
#define RIGHTSH(X,N) ((X) >> (N))
#define CH(X, Y, Z) (((X) & (Y)) ^ ((~X) & (Z)))
#define MAJ(X, Y, Z) (((X) & (Y)) ^ ((X) & (Z)) ^ ((Y) & (Z)))
#define SIG0(X) (((X) >> 2 | (X) << 30) ^ ((X) >> 13 | (X) << 19) ^ ((X) >> 22 | (X) << 10))
#define SIG1(X) (((X) >> 6 | (X) << 26) ^ ((X) >> 11 | (X) << 21) ^ ((X) >> 25 | (X) << 7))
#define SIG2(X) (((X) >> 7 | (X) << 25) ^ ((X) >> 18 | (X) << 14) ^ ((X) >> 3))
#define SIG3(X) (((X) >> 17 | (X) << 15) ^ ((X) >> 19 | (X) << 13) ^ ((X) >> 10))

static uint32_t const	k[64] = {
	0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
	0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
	0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
	0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
	0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
	0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
	0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
	0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

#define YOLO(i, a, b, c, d, e, f, g, h, t1, t2, k, w) { \
	t1 = h + SIG1(e) + CH(e, f, g) + k[i] + w[i]; \
	t2 = SIG0(a) + MAJ(a, b, c); \
	h = g; \
	g = f; \
	f = e; \
	e = d + t1; \
	d = c; \
	c = b; \
	b = a; \
	a = t1 + t2; \
}

#define STEP0_15(i, offset, w, data) { \
	w[i] = SWAP(((uint32_t*)data)[offset + i]); \
}

#define STEP16_63(i, w, j, k, l, m) { \
	w[i] = SIG3(w[j]) + w[k] + SIG2(w[l]) + w[m]; \
}

int
hash_this(uint8_t *const data, t_opt *const options) {
	uint32_t		a, b, c, d, e, f, g, h, t1, t2;
	uint32_t		h0 = 0x6a09e667;
	uint32_t		h1 = 0xbb67ae85;
	uint32_t		h2 = 0x3c6ef372;
	uint32_t		h3 = 0xa54ff53a;
	uint32_t		h4 = 0x510e527f;
	uint32_t		h5 = 0x9b05688c;
	uint32_t		h6 = 0x1f83d9ab;
	uint32_t		h7 = 0x5be0cd19;
	uint32_t		w[64] = {0};
	uint32_t		p[64][4];
	for (int i = 15; i < 64; ++i){
		p[i][0] = i - 2;
		p[i][1] = i - 7;
		p[i][2] = i - 15;
		p[i][3] = i - 16;
	}
	for (uint64_t offset = 0; offset < options->new_size / 4; offset += 16) {
		for (uint32_t i = 0; i < 64; i += 16) {
			if (i < 16) {
				STEP0_15(i, offset, w, data)
				STEP0_15(i+1, offset, w, data)
				STEP0_15(i+2, offset, w, data)
				STEP0_15(i+3, offset, w, data)
				STEP0_15(i+4, offset, w, data)
				STEP0_15(i+5, offset, w, data)
				STEP0_15(i+6, offset, w, data)
				STEP0_15(i+7, offset, w, data)
				STEP0_15(i+8, offset, w, data)
				STEP0_15(i+9, offset, w, data)
				STEP0_15(i+10, offset, w, data)
				STEP0_15(i+11, offset, w, data)
				STEP0_15(i+12, offset, w, data)
				STEP0_15(i+13, offset, w, data)
				STEP0_15(i+14, offset, w, data)
				STEP0_15(i+15, offset, w, data)
			} else {
				STEP16_63(i, w, p[i][0], p[i][1], p[i][2], p[i][3])
				STEP16_63(i+1, w, p[i+1][0], p[i+1][1], p[i+1][2], p[i+1][3])
				STEP16_63(i+2, w, p[i+2][0], p[i+2][1], p[i+2][2], p[i+2][3])
				STEP16_63(i+3, w, p[i+3][0], p[i+3][1], p[i+3][2], p[i+3][3])
				STEP16_63(i+4, w, p[i+4][0], p[i+4][1], p[i+4][2], p[i+4][3])
				STEP16_63(i+5, w, p[i+5][0], p[i+5][1], p[i+5][2], p[i+5][3])
				STEP16_63(i+6, w, p[i+6][0], p[i+6][1], p[i+6][2], p[i+6][3])
				STEP16_63(i+7, w, p[i+7][0], p[i+7][1], p[i+7][2], p[i+7][3])
				STEP16_63(i+8, w, p[i+8][0], p[i+8][1], p[i+8][2], p[i+8][3])
				STEP16_63(i+9, w, p[i+9][0], p[i+9][1], p[i+9][2], p[i+9][3])
				STEP16_63(i+10, w, p[i+10][0], p[i+10][1], p[i+10][2], p[i+10][3])
				STEP16_63(i+11, w, p[i+11][0], p[i+11][1], p[i+11][2], p[i+11][3])
				STEP16_63(i+12, w, p[i+12][0], p[i+12][1], p[i+12][2], p[i+12][3])
				STEP16_63(i+13, w, p[i+13][0], p[i+13][1], p[i+13][2], p[i+13][3])
				STEP16_63(i+14, w, p[i+14][0], p[i+14][1], p[i+14][2], p[i+14][3])
				STEP16_63(i+15, w, p[i+15][0], p[i+15][1], p[i+15][2], p[i+15][3])
			}
		}
		a = h0, b = h1, c = h2, d = h3, e = h4, f = h5, g = h6, h = h7;
		for (uint32_t i = 0; i < 64; i+=16) {
			YOLO(i, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+1, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+2, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+3, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+4, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+5, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+6, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+7, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+8, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+9, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+10, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+11, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+12, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+13, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+14, a, b, c, d, e, f, g, h, t1, t2, k, w);
			YOLO(i+15, a, b, c, d, e, f, g, h, t1, t2, k, w);
		}
		h0 += a; h1 += b; h2 += c; h3 += d; h4 += e; h5 += f; h6 += g; h7 += h;
	}
	if (options->options & OPT_FILE) {
		printf("SHA256(%s)= %08x%08x%08x%08x%08x%08x%08x%08x\n", options->filename, h0, h1, h2, h3, h4, h5, h6, h7);
		munmap((void*)data, options->size);
	}
	else {
		printf("%08x%08x%08x%08x%08x%08x%08x%08x\n", h0, h1, h2, h3, h4, h5, h6, h7);
		free((void*)data);
	}
	return (0);
}
