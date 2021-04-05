#include "../include/aes_128_decrypt.h"

// Decryption function
byte *decrypt_aes_128(byte *ciphertext, byte *key) {
    byte *plaintext = NULL;
    // Fill this function
    return plaintext;
}

// IS-box ( Inverse substitute a single byte )
byte inverse_substitute_byte(byte byte_to_substitute) {
    byte inverse_byte = inverse_s_box[byte_to_substitute];
    return inverse_byte;
}

// Inverse substitute the bytes of the state array
void inverse_substitute_bytes(byte *byte_array) {
     for (int x = 0; x < 16; x++) {
        byte_array[x] = inverse_substitute_byte(byte_array[x]);
    }
}

// Inverse Shift rows
void inverse_shift_rows(byte *byte_array) {
    byte temp[16];

	// Row 1
	temp[0] = byte_array[0];
    temp[4] = byte_array[4];
    temp[8] = byte_array[8];
    temp[12] = byte_array[12];
	
	// Row 2
	temp[1] = byte_array[13];
    temp[5] = byte_array[1];
    temp[9] = byte_array[5];
    temp[13] = byte_array[9];

	// Row 3
	temp[2] = byte_array[10];
    temp[6] = byte_array[14];
    temp[10] = byte_array[2];
    temp[14] = byte_array[6];
	
	// Row 4
	temp[3] = byte_array[7]; 
    temp[7] = byte_array[11]; 
    temp[11] = byte_array[15];
    temp[15] = byte_array[3];

	for (int i = 0; i < 16; i++) {
		byte_array[i] = temp[i];
	}
}

// Inverse Mix Columns
void inverse_mix_columns(byte *byte_array) {
    byte temp[16];
    
    temp[0] = (byte)gf_mul_14[byte_array[0]] ^ gf_mul_11[byte_array[1]] ^ gf_mul_13[byte_array[2]] ^ gf_mul_9[byte_array[3]];
	temp[1] = (byte)gf_mul_9[byte_array[0]] ^ gf_mul_14[byte_array[1]] ^ gf_mul_11[byte_array[2]] ^ gf_mul_13[byte_array[3]];
	temp[2] = (byte)gf_mul_13[byte_array[0]] ^ gf_mul_9[byte_array[1]] ^ gf_mul_14[byte_array[2]] ^ gf_mul_11[byte_array[3]];
	temp[3] = (byte)gf_mul_11[byte_array[0]] ^ gf_mul_13[byte_array[1]] ^ gf_mul_9[byte_array[2]] ^ gf_mul_14[byte_array[3]];

	temp[4] = (byte)gf_mul_14[byte_array[4]] ^ gf_mul_11[byte_array[5]] ^ gf_mul_13[byte_array[6]] ^ gf_mul_9[byte_array[7]];
	temp[5] = (byte)gf_mul_9[byte_array[4]] ^ gf_mul_14[byte_array[5]] ^ gf_mul_11[byte_array[6]] ^ gf_mul_13[byte_array[7]];
	temp[6] = (byte)gf_mul_13[byte_array[4]] ^ gf_mul_9[byte_array[5]] ^ gf_mul_14[byte_array[6]] ^ gf_mul_11[byte_array[7]];
	temp[7] = (byte)gf_mul_11[byte_array[4]] ^ gf_mul_13[byte_array[5]] ^ gf_mul_9[byte_array[6]] ^ gf_mul_14[byte_array[7]];

	temp[8] = (byte)gf_mul_14[byte_array[8]] ^ gf_mul_11[byte_array[9]] ^ gf_mul_13[byte_array[10]] ^ gf_mul_9[byte_array[11]];
	temp[9] = (byte)gf_mul_9[byte_array[8]] ^ gf_mul_14[byte_array[9]] ^ gf_mul_11[byte_array[10]] ^ gf_mul_13[byte_array[11]];
	temp[10] = (byte)gf_mul_13[byte_array[8]] ^ gf_mul_9[byte_array[9]] ^ gf_mul_14[byte_array[10]] ^ gf_mul_11[byte_array[11]];
	temp[11] = (byte)gf_mul_11[byte_array[8]] ^ gf_mul_13[byte_array[9]] ^ gf_mul_9[byte_array[10]] ^ gf_mul_14[byte_array[11]];

	temp[12] = (byte)gf_mul_14[byte_array[12]] ^ gf_mul_11[byte_array[13]] ^ gf_mul_13[byte_array[14]] ^ gf_mul_9[byte_array[15]];
	temp[13] = (byte)gf_mul_9[byte_array[12]] ^ gf_mul_14[byte_array[13]] ^ gf_mul_11[byte_array[14]] ^ gf_mul_13[byte_array[15]];
	temp[14] = (byte)gf_mul_13[byte_array[12]] ^ gf_mul_9[byte_array[13]] ^ gf_mul_14[byte_array[14]] ^ gf_mul_11[byte_array[15]];
	temp[15] = (byte)gf_mul_11[byte_array[12]] ^ gf_mul_13[byte_array[13]] ^ gf_mul_9[byte_array[14]] ^ gf_mul_14[byte_array[15]];

	for (int x = 0; x < 16; x++) {
		byte_array[x] = temp[x];
	}
}
