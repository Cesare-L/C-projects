#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>


void cipher(char *text, const char *key);
void decipher(char *hextext, const char *key);

static void xor_stream(const unsigned char *in, unsigned char *out, size_t len, const unsigned char *key, size_t keylen) {
    for (size_t i = 0; i < len; i++) {
        out[i] = in[i] ^ key[i % keylen];
    }
}

static char *hex_encode(const unsigned char *in, size_t len) {
    char *out = malloc(len * 2 + 1);
    if (!out) return NULL;
    for (size_t i = 0; i < len; i++) {
        sprintf(out + i*2, "%02x", in[i]);
    }
    out[len*2] = '\0';
    return out;
}

static unsigned char hex_val(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    return 0;
}

static unsigned char *hex_decode(const char *hex, size_t *out_len) {
    size_t hlen = strlen(hex);
    if ((hlen & 1) != 0) return NULL; // must be even
    size_t len = hlen / 2;
    unsigned char *out = malloc(len + 1);
    if (!out) return NULL;
    for (size_t i = 0; i < len; i++) {
        unsigned char hi = hex_val(hex[i*2]);
        unsigned char lo = hex_val(hex[i*2 + 1]);
        out[i] = (hi << 4) | lo;
    }
    out[len] = '\0';
    *out_len = len;
    return out;
}

int main(int argc, char *argv[]) {

    // A simple check to see if user has provided the right arguments, if not instructions are provided on program usage.
    if (argc < 2) {
        printf("//////////////////////////////////////////////////////\n");
        printf("\nThis is a program to encrypt and decrypt messages.\n");
        printf("Usage: %s <encrypt> / <decrypt> \"Your Text\" / \"Your Ciphertext\" <4096 bit passphrase>\n", argv[0]);
        printf("Need to generate a a 4096 bit passphrase? use te following ./encryption <generate>\n");
        printf("PS: The passphrase could be any length, but if you want maximum security generate a 4096 bit passphrase\n");
        printf("\n///////////////////////////////////////////////////////\n");
        return 1;
    }

    // Generates a random 4096 bit passphrase, which is 512 characters long
    if (strcmp(argv[1], "generate") == 0 || strcmp(argv[1], "Generate") == 0) {
        char passphrase[513] = "";
        srand((unsigned)time(NULL));
        const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!%@#$^&*()_+-=[]{}|;:,.<>?";
        int charset_size = (int)strlen(charset);
        for (int i = 0; i < 512; i++) {
            passphrase[i] = charset[rand() % charset_size];
        }
        passphrase[512] = '\0';
        printf("Generated Passphrase: %s\n", passphrase);
        return 0;
    }

    //strcmp is used like this to compare strings, if both strings are the same, it returns 0.
    //in this case we check both "Decrypt" and "decrypt" by using || to check both conditions.
    if (strcmp(argv[1], "decrypt") == 0 || strcmp(argv[1], "Decrypt") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s decrypt <hexciphertext> <passphrase>\n", argv[0]);
            return 2;
        }
        // last argument is key, everything between argv[2]..argv[argc-2] is hex ciphertext
        size_t needed = 1;
        for (int i = 2; i < argc - 1; i++) needed += strlen(argv[i]) + 1;
        char *combined = malloc(needed);
        if (!combined) return 3;
        combined[0] = '\0';
        for (int i = 2; i < argc - 1; i++) {
            strcat(combined, argv[i]);
            if (i < argc - 2) strcat(combined, " ");
        }
        const char *key = argv[argc - 1];
        decipher(combined, key);
        free(combined);
        return 0;
    }

    //same thing as above but for "Encrypt" and "encrypt".
    if (strcmp(argv[1], "Encrypt") == 0 || strcmp(argv[1], "encrypt") == 0) {
        if (argc < 4) {
            fprintf(stderr, "Usage: %s encrypt <plaintext> <passphrase>\n", argv[0]);
            return 2;
        }
        size_t needed = 1;
        for (int i = 2; i < argc - 1; i++) needed += strlen(argv[i]) + 1;
        char *combined = malloc(needed);
        if (!combined) return 3;
        combined[0] = '\0';
        for (int i = 2; i < argc - 1; i++) {
            strcat(combined, argv[i]);
            if (i < argc - 2) strcat(combined, " ");
        }
        const char *key = argv[argc - 1];
        cipher(combined, key);
        free(combined);
        return 0;
    }


    return 0;
}

void cipher(char *text, const char *key) {
    size_t text_len = strlen(text);
    size_t key_len = strlen(key);
    if (key_len == 0) {
        fprintf(stderr, "Error: passphrase must not be empty\n");
        return;
    }
    unsigned char *out = malloc(text_len);
    if (!out) return;
    xor_stream((unsigned char*)text, out, text_len, (unsigned char*)key, key_len);
    char *hex = hex_encode(out, text_len);
    if (hex) {
        printf("Encrypted: %s\n", hex);
        free(hex);
    }
    free(out);
}

void decipher(char *hextext, const char *key) {
    size_t key_len = strlen(key);
    if (key_len == 0) {
        fprintf(stderr, "Error: passphrase must not be empty\n");
        return;
    }
    size_t ct_len = 0;
    unsigned char *ct = hex_decode(hextext, &ct_len);
    if (!ct) {
        fprintf(stderr, "Error: invalid hex ciphertext\n");
        return;
    }
    unsigned char *pt = malloc(ct_len + 1);
    if (!pt) { free(ct); return; }
    xor_stream(ct, pt, ct_len, (unsigned char*)key, key_len);
    pt[ct_len] = '\0';
    printf("Decrypted: %s\n", (char*)pt);
    free(ct);
    free(pt);
}
