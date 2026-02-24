# C-projects
Repository for my C language programs, focus is on highlighting concepts of the C language to utilize for future brush ups and reviews.

- Farenheit-to-Celcius.c: a classic example of a program, inspired by "The C Programming Language" book
  
- output.c: a simple program to output the command line argument inputed, useful to learn/teach command line arguments 

- encrypt.c: a boilerplate for a command line encryption and decryption program, you must implement your own logic for the cipher() and dechiper() functions

- 8092.c: this program will generate a pseudorandom 8092 bit passphrase (over 1000 characters) utilizing the rand() function, don't use it for anything actually related to security, as it can be cracked in a few seconds if someone estimates the second (time seed of rand()) you created even by a 100 year window and checks all the seeds to regenerate it.

- XOR-cipher.c: A XOR cipher implemented in C with a psuedorandom 4096 bit passphrase generator, it is mostly educational and has significant vulnerabilties such as the usage of rand() function which is pseudorandom and can potentially be brute forced, frequency analysis vulnerabilities if re-using the same keys, key recovery vulnerabilties if using the same key etc..., use it at your own risk
