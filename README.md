# AES-128
AES 128 implementation encrypting a 1GB test file. 
<br>
Create the file with ```openssl rand -out sample.txt -base64 $(( 2**30 * 3/4 ))```
<br>
Encrypt using openssl ```openssl aes-128-ecb -a -salt -in sample.txt -out sample.txt.enc```
<br>
Decrypt using openssl ```openssl aes-128-ecb -d -a -in sample.txt.enc -out sample.txt.new```

