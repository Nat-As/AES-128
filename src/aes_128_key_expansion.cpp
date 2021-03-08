#include "../include/aes_128_key_expansion.h"

// Circular Left Shift (Rotate Left)
void circular_left_shift(byte *byte_word) {
    // Fill this function
}

// Add Round Constant
void add_round_constant(byte *byte_word, unsigned char round_number) {
    // Fill this function
}


// The g function of the AES key expansion
byte *g_function(byte *byte_word)
{
    byte *g_return_word=new byte[4];
    // Fill this function
    return g_return_word;
}


// Get round key
byte *get_round_key(byte *key_bytes, unsigned char round_number) {
    byte *round_key = new byte[16];
    // Fill this function
    // Note: Don't forget to delete the return og the g_function once you are done using it
    return round_key;
}

