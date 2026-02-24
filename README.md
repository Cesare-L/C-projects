# C-projects
Repository for my C language projects

- Farenheit-to-Celcius.c: a classic example of a program, inspired by "The C Programming Language" book
  
- output.c: a simple program to output the command line argument inputed, useful to learn/teach command line arguments 

- encrypt.c: a boilerplate for a command line encryption and decryption program, you must implement your own logic for the cipher() and dechiper() functions

- XOR-cipher.c: A XOR cipher implemented in C with a psuedorandom 4092 bit passphrase generator, it is mostly educational and has significant vulnerabilties such as the usage of rand() function which is pseudorandom and can potentially be brute forced, frequency analysis vulnerabilities if re-using the same keys, key recovery vulnerabilties if using the same key etc..., use it at your own risk
