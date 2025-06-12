#ifndef RANDOMBYTES_H
#define RANDOMBYTES_H

#include <stdint.h>
#include <stddef.h>

/**
 * Generates random bytes and stores them in the output buffer.
 *
 * @param[out] output  The output buffer where random bytes will be stored
 * @param[in]  len     Number of random bytes to generate
 */
void randombytes(uint8_t *output, size_t len);

#endif