#include "aes_128_common.h"

#ifndef AES_128_DECRYPT_H
#define AES_128_DECRYPT_H

byte *decrypt_aes_128(byte *ciphertext, byte *key);

void inverse_substitute_bytes(byte *byte_array);

void inverse_shift_rows(byte *byte_array);

byte inverse_substitute_byte(byte byte_to_substitute);

void inverse_mix_columns(byte *byte_array);

#endif //AES_128_DECRYPT_H
