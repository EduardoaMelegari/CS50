#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        char *ptr;
        int key = strtol(argv[1], &ptr, 10);
        if (ptr[0] == '\0' && key != 0)
        {
            string texto = get_string("plaintext: ");

            int i = 0;
            int indicador;
            while (texto[i] != '\0')
            {
                int ascii = (int) texto[i];

                if (ascii >= 32 && ascii <= 63)
                { // verfica se é espaço ou caractere especial
                    i++;
                }
                else
                {
                    if (ascii >= 65 && ascii <= 90) // verifica se a letra é maiuscula
                    {
                        ascii += 32;
                        indicador = 1;
                    }
                    int nova_letra = ascii + key;
                    while (nova_letra > 122)
                    {
                        nova_letra = 96 + (nova_letra % 122);
                    }
                    if (indicador == 1)
                    {
                        texto[i] = nova_letra - 32;
                        indicador = 0;
                    }
                    else
                    {
                        texto[i] = nova_letra;
                    }
                    i++;
                }
            }
            printf("ciphertext: %s\n", texto);
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
