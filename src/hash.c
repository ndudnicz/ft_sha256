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
#define RIGHTROTATE(X,Y) ((X) >> (Y) | (X) << (32 - (Y)))
#define RIGHTSH(X, N) (X >> N)
#define CH(X, Y, Z) ((X & Y) ^ (~X & Z))
#define MAJ(X, Y, Z) ((X & Y) ^ (X & Z) ^ (Y & Z))
#define SIG0(X) (RIGHTROTATE(X, 2) ^ RIGHTROTATE(X, 13) ^ RIGHTROTATE(X, 22))
#define SIG1(X) (RIGHTROTATE(X, 6) ^ RIGHTROTATE(X, 11) ^ RIGHTROTATE(X, 25))
#define SIG2(X) (RIGHTROTATE(X, 7) ^ RIGHTROTATE(X, 18) ^ RIGHTSH(X, 3))
#define SIG3(X) (RIGHTROTATE(X, 17) ^ RIGHTROTATE(X, 19) ^ RIGHTSH(X, 10))

int
hash_this(uint8_t *const data, t_opt *const options) {
	if (options->options & OPT_FILE)
		munmap((void*)data, options->size);
	else
		free((void*)data);
	return (0);
}
