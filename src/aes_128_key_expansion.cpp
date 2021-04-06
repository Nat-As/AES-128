#include <iostream>
#include "include/aes_128_key_expansion.h"
#include "include/aes_128_common.h"

using namespace std;

// Circular Left Shift (Rotate Left)
void circular_left_shift(byte *byte_word) {
    // Fill this function
	byte temp[4];
	// Shift
	temp[0] = byte_word[4];
	for (int i=1; i<4; i++){
		temp[i] = byte_word[i-1];
	}
	// Assign values back to byte_word
	for (int i=1; i<4; i++){
		byte_word[i] = temp[i];
	}
	//cout << byte_word;
}

// Add Round Constant
void add_round_constant(byte *byte_word, unsigned char round_number) {
    // Not ideal, but get's the job done.
	switch (round_number){
		case 1:
			*byte_word = 0x01;
		case 2:
			*byte_word = 0x02;
		case 3:
			*byte_word = 0x04;
		case 4:
			*byte_word = 0x08;
		case 5:
			*byte_word = 0x10;
		case 6:
			*byte_word = 0x20;
		case 7:
			*byte_word = 0x40;
		case 8:
			*byte_word = 0x80;
		case 9:
			*byte_word = 0x1B;
		case 0x0A:
			*byte_word = 0x36;
	}
}


// The g function of the AES key expansion
byte *g_function(byte *byte_word)
{
    byte *g_return_word = new byte[4];
    // Fill this function
	circular_left_shift(*byte_word);
	// XOR S Box results with Round Constant (Concatenate with last round key)
	for (unsigned char round_number = 0; round_number <= 10; round_number++){
		*g_return_word = *g_return_word | substitute_bytes(*byte_word) ^ add_round_constant(*byte_word, round_number);
	}
	
    return g_return_word;
}


// Get round key
byte *get_round_key(byte *key_bytes, unsigned char round_number) {
    byte *round_key = new byte[16];
    // Fill this function
    // Note: Don't forget to delete the return of the g_function once you are done using it
	for (unsigned char round_number = 0; round_number <= 10; round_number++){
		*round_key = substitute_bytes(*key_bytes) ^ add_round_constant(*key_bytes, round_number);
	}
    return round_key;
}

