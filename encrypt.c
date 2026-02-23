#include <stdio.h>
#include <string.h> 


void cipher(char *text);
void decipher(char *text);

int main(int argc, char *argv[]) {

    // A simple check to see if user has provided the right arguments, if not instructions are provided on program usage.
    if (argc < 3) {
        printf("//////////////////////////////////////////////////////\n");
        printf("\nThis is a program to encrypt and decrypt messages.\n");
        printf("Usage: %s <encrypt> / <decrypt> \"Your Text\" / \"Your Ciphertext\"\n", argv[0]);
        printf("\n///////////////////////////////////////////////////////\n");
        return 1;
    }

    //strcmp is used like this to compare strings, if both strings are the same, it returns 0.
    //in this case we check both "Decrypt" and "decrypt" by using || to check both conditions.
    if (strcmp(argv[1],"decrypt") == 0 || strcmp(argv[1],"Decrypt") == 0) { 
        char combined[1024] = "";
        for (int i = 2; i < argc; i++) {
            strcat(combined, argv[i]);
            if (i < argc - 1) {
                strcat(combined, " ");
            }
        }
        decipher(combined);
        return 1;
    }

    //same thing as above but for "Encrypt" and "encrypt".
    if (strcmp(argv[1],"Encrypt") == 0 || strcmp(argv[1],"encrypt") == 0) { 
        char combined[1024] = "";
        for (int i = 2; i < argc; i++) {
            strcat(combined, argv[i]);
            if (i < argc - 1) {
                strcat(combined, " ");
            }
        }
        cipher(combined);
        return 1;
    }


    return 0;
}

void cipher(char *text) {
    printf("It would encrypt \"%s\"..... implement your own decryption logic in the cipher function\n", text);
}

void decipher(char *text) {
    printf("It would decrypt \"%s\"..... implement your own decryption logic in the decipher function\n", text);
}
