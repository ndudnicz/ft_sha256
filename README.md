### sha256 implementation in C.
```bash
$> ./ft_256 < <text_file> OR ./ft_256 -f <binary_file>
```

#### Performance on debian 9, FX-8320 8 core:
* me vs OpenSSL (1.1.0f, sha256 C code compiled) vs OpenSSL (1.1.0f, sha256 ASM code compiled)
* on commit 8a504fae42d1498afbfb07726f5a9e494863a288

```bash
$> bash sha256 debian-9.4.0-amd64-netinst.iso
SHA256(debian-9.4.0-amd64-netinst.iso)= 124d270006703f2111224dec3bf7a9d01450168be41d4834f88fdd035552b044
real	0m2.142s
user	0m1.972s
sys	0m0.168s
SHA256(debian-9.4.0-amd64-netinst.iso)= 124d270006703f2111224dec3bf7a9d01450168be41d4834f88fdd035552b044
real	0m2.289s
user	0m2.172s
sys	0m0.112s
SHA256(debian-9.4.0-amd64-netinst.iso)= 124d270006703f2111224dec3bf7a9d01450168be41d4834f88fdd035552b044
real	0m1.212s
user	0m1.168s
sys	0m0.036s
```
