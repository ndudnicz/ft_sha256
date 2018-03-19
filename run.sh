#!/bin/sh
export LD_PRELOAD="./libcrypto.so"
$@;
