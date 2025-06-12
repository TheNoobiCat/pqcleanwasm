#include <stdint.h>
#include <stdio.h>
#include "api.h"
#include "kem.h"

uint8_t pk[PQCLEAN_MLKEM1024_CLEAN_CRYPTO_PUBLICKEYBYTES];
uint8_t sk[PQCLEAN_MLKEM1024_CLEAN_CRYPTO_SECRETKEYBYTES];
uint8_t ct[PQCLEAN_MLKEM1024_CLEAN_CRYPTO_CIPHERTEXTBYTES];
uint8_t ss_enc[PQCLEAN_MLKEM1024_CLEAN_CRYPTO_BYTES];
uint8_t ss_dec[PQCLEAN_MLKEM1024_CLEAN_CRYPTO_BYTES];

void generate_keypair() {
    PQCLEAN_MLKEM1024_CLEAN_crypto_kem_keypair(pk, sk);
}

uint8_t* get_public_key() {
    return pk;
}

uint8_t* get_secret_key() {
    return sk;
}

void encapsulate() {
    PQCLEAN_MLKEM1024_CLEAN_crypto_kem_enc(ct, ss_enc, pk);
}

uint8_t* get_ciphertext() {
    return ct;
}

uint8_t* get_shared_secret_enc() {
    return ss_enc;
}

void decapsulate() {
    PQCLEAN_MLKEM1024_CLEAN_crypto_kem_dec(ss_dec, ct, sk);
}

uint8_t* get_shared_secret_dec() {
    return ss_dec;
}