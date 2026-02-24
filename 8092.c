#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("///////////////////////////////////////////////////////\n");
        printf("\nThis program will generate a random 8092 bit string of text (PASSPHRASE)");
        printf("\nUsage: %s <generate>\n", argv[0]);
        printf("\n///////////////////////////////////////////////////////\n");
        return 1;
    }

    if (strcmp(argv[1], "generate") == 0 || strcmp(argv[1], "Generate") == 0) {
        char passphrase[1350] = "";
        srand((unsigned)time(NULL));
        const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!%@#$^&*()_+-=[]{}|;:,.<>?|~";
        int charset_size = (int)strlen(charset);
        for (int i = 0; i < 1349; i++) {
            passphrase[i] = charset[rand() % charset_size];
        }
        passphrase[1349] = '\0';
        printf("GENERATED PASSPHRASE: %s\n", passphrase);
        return 0;
    }
    
    for(int i = 0; i < argc; i++) {
        printf(" %s", argv[i]);
    }

    printf("\n");

}
