#include <stdio.h>
#include <stdlib.h>

#include "png.h"

/* TODO: Remove. */
#include "deflate.h"

#define MIN(a, b)   ((a) < (b) ? (a) : (b))

void main(int argc, char **argv)
{
    FILE *deflatedata = fopen(argv[1], "r");
    char *data = calloc(1000, sizeof(char));
    fread(data, sizeof(char), atoi(argv[2]), deflatedata);
    fread(data, sizeof(char), 1000, deflatedata);
    deflate_decompress(data, 1000, 10000);
    exit(0);
    FILE *file = fopen(argv[1], "r");

    png_t *png = png_read(file);
    fclose(file);

    if (!png) {
        printf("Invalid png.\n");
        exit(1);
    }

    png_print_information(png);
    png_get_data(png);

    for (int row = 0; row < MIN(10, png->height); row++) {
        for (int col = 0; col < MIN(10, png->width); col++) {
            printf("#%02hhx%02hhx%02hhx ",
                png->data[3 * (row * png->width + col)],
                png->data[3 * (row * png->width + col) + 1],
                png->data[3 * (row * png->width + col) + 2]);
        }
        printf("\n");
    }

    exit(0);
}
