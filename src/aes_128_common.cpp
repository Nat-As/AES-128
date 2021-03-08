#include "../include/aes_128_common.h"

using namespace std;

// Create Byte Array From String
byte *string_to_byte_array(string str) {
    size_t m = str.length();
    byte *return_array = new byte[m];
    for (size_t i = 0; i < m; i++) {
        return_array[i] = (byte) str.at(i);
    }
    return return_array;
}

// Print Byte Array
void print_byte_array(byte *byte_array, size_t length) {
    for (size_t i = 0; i < length; i++) {
        cout << "0x" << hex << byte_array[i] << " ";
    }
    cout << endl;
}

// Print the state matrix
void print_state(byte *byte_array) {
    for (size_t i = 0; i < 4; i++) {
        cout << "0x" << hex << byte_array[i] << " " << "0x" << hex << byte_array[i + 4] << " " << "0x" << hex
             << byte_array[i + 8] << " " << "0x" << hex << byte_array[i + 12] << endl;
    }
}


// Print a new line
void newline() {
    cout << endl;
}

// Add round key
void add_round_key(byte *byte_array) {
    // Fill this function
}

// S-box ( Substitute a single byte )
byte substitute_byte(byte byte_to_substitute) {
    // Fill this function
}

// substitute the bytes of the state array
void substitute_bytes(byte *byte_array) {
    // Fill this function
}