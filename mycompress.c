#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress_file(const char *input_filename, const char *output_filename);
void decompress_file(const char *input_filename, const char *output_filename);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <-c|-d> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-c") == 0) {
        compress_file(argv[2], argv[3]);
    } else if (strcmp(argv[1], "-d") == 0) {
        decompress_file(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid mode. Use -c to compress or -d to decompress.\n");
        return 1;
    }

    printf("Operation completed successfully.\n");
    return 0;
}

void compress_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        exit(1);
    }

    int current_char;
    int next_char;
    unsigned char run_count = 1;

    current_char = fgetc(input_file);
    if (current_char == EOF) {
        fclose(input_file);
        fclose(output_file);
        return;
    }

    while ((next_char = fgetc(input_file)) != EOF) {
        if (next_char == current_char && run_count < 255) {
            run_count++;
        } else {
            fputc(run_count, output_file);
            fputc(current_char, output_file);
            current_char = next_char;
            run_count = 1;
        }
    }

    fputc(run_count, output_file);
    fputc(current_char, output_file);

    fclose(input_file);
    fclose(output_file);
}

void decompress_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        exit(1);
    }

    int run_count;
    int data_char;

    while ((run_count = fgetc(input_file)) != EOF) {
        data_char = fgetc(input_file);
        for (int i = 0; i < run_count; i++) {
            fputc(data_char, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}