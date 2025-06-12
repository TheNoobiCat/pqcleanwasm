#include "randombytes.h"
#include <emscripten.h>
#include <stdlib.h>

// Using Emscripten API to get secure random bytes from the browser's crypto.getRandomValues
EM_JS(void, em_randombytes, (uint8_t *buf, size_t len), {
    var buffer = HEAPU8.subarray(buf, buf + len);
    crypto.getRandomValues(buffer);
});

void randombytes(uint8_t *output, size_t len) {
    // Call the JavaScript implementation for secure random bytes
    em_randombytes(output, len);
}