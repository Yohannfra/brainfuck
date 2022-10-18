/**
 * @file main.c
 * @brief brainfuck interpretor
 * @author Assouline Yohann
 * @date 2022-02-16
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#define BRAINFUCK_VM_MEMORY_SIZE 30000

static char *read_file(const char *fp)
{
    char *fc;
    FILE *file;

    struct stat sb;
    if (stat(fp, &sb) == -1) {
        return NULL;
    }

    fc = (char*)calloc(sb.st_size, sizeof(char));
    if (!fc) {
        return NULL;
    }

    file = fopen(fp, "r");
    if (!file) {
        return NULL;
    }
    if (!fread(fc, sb.st_size, 1, file)) {
        free(fc);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return fc;
}

static void start_brainfuck(const char *fc)
{
    size_t head = 0;
    size_t data_ptr = 0;
    unsigned char memory[BRAINFUCK_VM_MEMORY_SIZE] = {0};

    while (fc[head] != '\0') {
        switch (fc[head]) {
            case '>':
                if (data_ptr == BRAINFUCK_VM_MEMORY_SIZE - 1) {
                    data_ptr = 0;
                }
                data_ptr += 1;
                break;

            case '<':
                if (data_ptr == 0) {
                    data_ptr = BRAINFUCK_VM_MEMORY_SIZE - 1;
                }
                data_ptr -= 1;
                break;

            case '+':
                memory[data_ptr] += 1;
                break;

            case '-':
                memory[data_ptr] -= 1;
                break;

            case '.':
                putchar(memory[data_ptr]);
                break;

            case ',':
                memory[data_ptr] = getchar();
                break;

            case '[':
                if (memory[data_ptr] == 0) {
                    while (fc[head] != ']') {
                        head++;
                    }
                }
                break;

            case ']':
                if (memory[data_ptr]) {
                    while (fc[head] != '[') {
                        head--;
                    }
                }
                break;
        }
        head++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "USAGE: ./brainfuck file.bf\n");
        return EXIT_FAILURE;
    }

    char *fc = read_file(argv[1]);
    if (!fc) {
        fprintf(stderr, "Error reading file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    start_brainfuck(fc);
    free(fc);
    return EXIT_SUCCESS;
}
