# Verifying with OpenSSL
AES 128 implementation encrypting a 1GB test file. 
<br>
1. Create the file with ```openssl rand -out sample.txt -base64 $(( 2**30 * 3/4 ))```
2. Encrypt using openssl ```openssl aes-128-ecb -a -salt -in sample.txt -out sample.txt.enc```
3. Decrypt using openssl ```openssl aes-128-ecb -d -a -in sample.txt.enc -out sample.txt.new```
4. Veryfy the plaintext is the same when decrypted ```hexdump -n64 sample.txt```
5. Veryfy the plaintext is the same when decrypted ```hexdump -n64 sample.txt.new```

# Using this implementation
1. ``` cd .. ```
2. ``` cmake AES-128 ```
3. ``` make ```
