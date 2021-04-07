#include "../include/aes_128_encrypt.h"
#include "../include/aes_128_common.h"
#include "../include/aes_128_key_expansion.h"

// Shift rows
void shift_rows(byte* byte_array) {
    unsigned char temp[16];

	//Column 1
	temp[0] = byte_array[0];
	temp[1] = byte_array[5];
	temp[2] = byte_array[10];
	temp[3] = byte_array[15];

	//Column 2
	temp[4] = byte_array[4];
	temp[5] = byte_array[9];
	temp[6] = byte_array[14];
	temp[7] = byte_array[3];

	//Column 3
	temp[8] = byte_array[8];
	temp[9] = byte_array[13];
	temp[10] = byte_array[2];
	temp[11] = byte_array[7];

	//Column 4
	temp[12] = byte_array[12];
	temp[13] = byte_array[1];
	temp[14] = byte_array[6];
	temp[15] = byte_array[11];

	for (int i = 0; i < 16; i++) {
		byte_array[i] = temp[i];
	}

}

// Mix Columns
void mix_columns(byte* byte_array) {
	unsigned char temp[16];

	temp[0] = (unsigned char)galois_mul_2[byte_array[0]] ^ galois_mul_3[byte_array[1]] ^ byte_array[2] ^ byte_array[3];
	temp[1] = (unsigned char)byte_array[0] ^ galois_mul_2[byte_array[1]] ^ galois_mul_3[byte_array[2]] ^ byte_array[3];
	temp[2] = (unsigned char)byte_array[0] ^ byte_array[1] ^ galois_mul_2[byte_array[2]] ^ galois_mul_3[byte_array[3]];
	temp[3] = (unsigned char)galois_mul_3[byte_array[0]] ^ byte_array[1] ^ byte_array[2] ^ galois_mul_2[byte_array[3]];

	temp[4] = (unsigned char)galois_mul_2[byte_array[4]] ^ galois_mul_3[byte_array[5]] ^ byte_array[6] ^ byte_array[7];
	temp[5] = (unsigned char)byte_array[4] ^ galois_mul_2[byte_array[5]] ^ galois_mul_3[byte_array[6]] ^ byte_array[7];
	temp[6] = (unsigned char)byte_array[4] ^ byte_array[5] ^ galois_mul_2[byte_array[6]] ^ galois_mul_3[byte_array[7]];
	temp[7] = (unsigned char)galois_mul_3[byte_array[4]] ^ byte_array[5] ^ byte_array[6] ^ galois_mul_2[byte_array[7]];

	temp[8] = (unsigned char)galois_mul_2[byte_array[8]] ^ galois_mul_3[byte_array[9]] ^ byte_array[10] ^ byte_array[11];
	temp[9] = (unsigned char)byte_array[8] ^ galois_mul_2[byte_array[9]] ^ galois_mul_3[byte_array[10]] ^ byte_array[11];
	temp[10] = (unsigned char)byte_array[8] ^ byte_array[9] ^ galois_mul_2[byte_array[10]] ^ galois_mul_3[byte_array[11]];
	temp[11] = (unsigned char)galois_mul_3[byte_array[8]] ^ byte_array[9] ^ byte_array[10] ^ galois_mul_2[byte_array[11]];

	temp[12] = (unsigned char)galois_mul_2[byte_array[12]] ^ galois_mul_3[byte_array[13]] ^ byte_array[14] ^ byte_array[15];
	temp[13] = (unsigned char)byte_array[12] ^ galois_mul_2[byte_array[13]] ^ galois_mul_3[byte_array[14]] ^ byte_array[15];
	temp[14] = (unsigned char)byte_array[12] ^ byte_array[13] ^ galois_mul_2[byte_array[14]] ^ galois_mul_3[byte_array[15]];
	temp[15] = (unsigned char)galois_mul_3[byte_array[12]] ^ byte_array[13] ^ byte_array[14] ^ galois_mul_2[byte_array[15]];

	for (int i = 0; i < 16; i++) {
		byte_array[i] = temp[i];
	}
}

//first rounds of encryption, number of rounds specified in main encryption function
void round(byte* byte_array, byte* key) {
	substitute_bytes(byte_array);
	shift_rows(byte_array);
	mix_columns(byte_array);
	
}

//Same as Round but without Mix Column
void final_round(byte* byte_array, byte* key) {
	substitute_bytes(byte_array);
	shift_rows(byte_array);
	
}

// Encryption function
byte* encrypt_aes_128(byte* plaintext, byte* key, byte* byte_array) {
	byte* ciphertext = NULL;

	for (int i = 0; i < 16; i++) {
		byte_array[i] = plaintext[i];
	}

	int numberOfRounds = 10;

	add_round_key(byte_array, get_round_key(key, 0x0A));

	for (int i = 0; i < numberOfRounds; i++) {
		round(byte_array, key + (16 * (i + 1)));
		add_round_key(byte_array, get_round_key(key, numberOfRounds));
	}

	final_round(byte_array, key + 160);
	add_round_key(byte_array, get_round_key(key, 0));

	for (int i = 0; i < 16; i++) {
		ciphertext[i] = byte_array[i];
	}

	return ciphertext;
}