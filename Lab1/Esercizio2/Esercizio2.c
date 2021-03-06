/*Utilizzando l’ambiente di sviluppo creare un nuovo progetto e creare il seguente file di te-sto all’interno della cartella del progetto.
Dopo averlo compilato, eseguire il codice ed esercitarsi testando i vari case.

Approfondimento: Cosa succede nella stampa su file se non viene inserita la riga if
(!feof(fp_read))? Perché si verifica?

Guide.txt
"Quarantadue!" urlo' Loonquawl. "Questo e' tutto cio' che sai dire dopo un lavoro di sette milioni e mezzo di anni?"
"Ho controllato molto approfonditamente," disse il computer, "e questa e' sicuramente la risposta.
Ad essere sinceri, penso che il problema sia che voi non abbiate mai saputo veramente
qual e' la domanda."

Scrivere il seguente programma in linguaggio C e verificare che non siano presenti errori in
fase di compilazione.*/

#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write;
    char file_char, choice;

    if ((fp_read = fopen("Guide.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write = fopen("Output.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }

    printf("Print on console (C) or on file (F):");
    choice = getchar();

    while (!feof(fp_read)) {
        file_char = fgetc(fp_read);
        if (!feof(fp_read)){
            switch (choice) {
                case 'C':
                    printf("\nChar printed on the console: %c",
                           file_char);
                    break;
                case 'F':
                    fputc(file_char, fp_write);
                    printf("\nChar saved on file: ");
                    putchar(file_char);
                    break;
                default:
                    printf("Wrong choice\n");
                    return 3;
            }
        }
    }

    fclose(fp_read);
    fclose(fp_write);

    return 0;
}
