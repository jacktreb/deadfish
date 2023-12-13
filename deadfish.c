#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if ( argc != 2 )
    {
        fprintf(stderr, "Usage: ./deadfish <filename>\n");
        return 1;
    }

    int accumulator = 0;
    FILE* file = NULL;

    file = fopen(argv[1], "r");
    if ( file == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        return 2;
    }
    
    char c;
    while ( (c = fgetc(file)) != EOF)
    {
        switch (c)
        {
            case 'i':
                accumulator++;
                if ( accumulator == 256 || accumulator == -1 ) accumulator = 0;
                break;
            case 'd':
                accumulator--;
                if ( accumulator == 256 || accumulator == -1 ) accumulator = 0;
                break;
            case 's':
                accumulator = accumulator * accumulator;
                if ( accumulator == 256 || accumulator == -1 ) accumulator = 0;
                break;
            case 'o':
                fprintf(stdout, "%d\n", accumulator);
                if ( accumulator == 256 || accumulator == -1 ) accumulator = 0;
                break;
            default:
                fprintf(stderr, "Invalid character in %s.\n", argv[1]);
                return 3;
                break;
        }
    }   
    fclose(file);
    return 0;
}
