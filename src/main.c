#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <zos_errors.h>
#include <zos_vfs.h>
#include <zos_video.h>

#include "qrtiny.h"

#define CH_LIGHT 0xDB
#define CH_DARK  0x20

uint8_t BUFFER[QRTINY_BUFFER_SIZE];
uint16_t format = QRTINY_FORMATINFO_MASK_000_ECC_LOW;
const char string[80] = "ZEAL8BIT.COM";

uint8_t x, y, module, c;
uint16_t size;

int main(int argc, char** argv) {
    if(argc > 0) {
        strcpy(string, argv[0]);
    }

    puts("Calculating...\n");

    uint16_t payload = 0;
    payload += QrTinyWriteAlphanumeric(BUFFER, payload, string);
    uint8_t result = QrTinyGenerate(BUFFER, payload, format);

    if(result) {
        for(y = 0; y < QRTINY_DIMENSION; y++) {
            for(x = 0; x < QRTINY_DIMENSION; x++) {
                 module = QrTinyModuleGet(BUFFER, format, x, y);
                if(module) putchar(CH_LIGHT);
                else putchar(CH_DARK);
            }
            putchar('\n');
        }
    }

    return 0;
}