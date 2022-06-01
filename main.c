#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char vigenere_matriz[26][26] = {
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
        {'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a'},
        {'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b'},
        {'d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c'},
        {'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd'},
        {'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e'},
        {'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f'},
        {'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
        {'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
        {'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
        {'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
        {'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'},
        {'m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l'},
        {'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'},
        {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
        {'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o'},
        {'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p'},
        {'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q'},
        {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
        {'t', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's'},
        {'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't'},
        {'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'},
        {'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
        {'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w'},
        {'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x'},
        {'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'}};

typedef struct data{
    char* arqtxt;
    char* key;
}data;

void* create_data(){
    data* aux =calloc(1,sizeof(data));
    return aux;
}

char* get_arqtxt(void* info){
    data* aux = info;
    return aux->arqtxt;
}

char* get_key(void* info){
    data* aux = info;
    return aux->key;
}

void set_arqtxt(void* info, char* newData){
    data* aux = info;
    aux->arqtxt = calloc(strlen(newData) + 1, sizeof(char));
    strcpy(aux->arqtxt, newData);
}

void set_key(void* info, char* newData){
    data* aux = info;
    aux->key = calloc(strlen(newData) + 1, sizeof(char));
    strcpy(aux->key, newData);
}

void free_data(void* info){
    data* aux = info;
    if(aux->arqtxt){
        free(aux->arqtxt);
    }
    if(aux->key){
        free(aux->key);
    }
}

void get_data(void* info){
    char arq[100], key [100];

    printf("Intruções:\n");
    printf("Insira o nome do arquivo.txt na pasta: ");
    scanf("%s", arq);
    set_arqtxt(info, arq);
    printf("Insira a a palavra chave desejada: ");
    scanf("%s", key);
    set_key(info, key);
}

int menu(){
    int aux;
    
    printf("\n==========================================================\n");
    printf("1.Encrypt \t2.Decrypt \t0.Sair\n");
    printf("==========================================================\n");
    printf("O que deseja fazer: ");
    scanf(" %d", &aux);

    return aux;
}

void encrypt(void* info){
    FILE* txt = fopen(get_arqtxt(info), "r");
    FILE* encrypttxt = fopen("encrypt.txt", "w+");
    char txto, crypto;
    char* key = get_key(info);
    int sizeofKey = strlen(key);
    int feof = 1;
    int m = 0;
    int n = 0;
    int x = 0;
    int y = 0;
    int k = 0;

    while (!feof(txt)){
        txto = tolower(fgetc(txt));

        if(txto == EOF){
        feof = 0;
        }

        if(txto == ' '){
            fprintf(encrypttxt, "%c", ' ');
        }
        else{
            while (m < 26) {
            if ((txto == vigenere_matriz[m][0])) {
                x = m;
                m = 27;  // finalizar o loop já que temos o valor do indice da linha já
            }
            m++;
        }

        while (n < 26) {
            if (k == sizeofKey)
                k = 0;  // resetar a string palavra-chave para continuar lendo uma mensagem longa

            if ((key[k] == vigenere_matriz[0][n])) {
                y = n;
                k++;
                crypto = vigenere_matriz[x][y];
                if(feof == 1){
                    fprintf(encrypttxt, "%c", crypto);
                }
                n = 27;  // finalizar o loop já que temos o valor do indice da coluna já
            }
            n++;
        }
        m = 0;
        n = 0;
        }
    }

    fclose(txt);
    fclose(encrypttxt);
}

void decrypt(void* info){
    FILE* txt = fopen(get_arqtxt(info), "r");
    FILE* decrypttxt = fopen("decrypt.txt", "w+");
    char txto, decrypt;
    char* key = get_key(info);
    int sizeofKey = strlen(key);
    int feof = 1;
    int m = 0;
    int n = 0;
    int x = 0;
    int y = 0;
    int k = 0;

    while (!feof(txt)) {
        txto = tolower(fgetc(txt));

        if(txto == NULL){
            feof = 0;
        }

        if(txto == ' '){
            fprintf(decrypttxt, "%c", ' ');
        }
        else{
            while (n < 26) {
            if (k == sizeofKey)
                k = 0;  // resetar a string palavra-chave para continuar lendo uma mensagem longa

            if ((key[k] == vigenere_matriz[0][n]) && (feof == 1)) {
                y = n;
                k++;
                n = 27;  // finalizar o loop já que temos o valor do indice da coluna já
            }
            n++;
            }

            while (m < 26) {
                if ((txto == vigenere_matriz[m][y]) && (feof == 1)) {
                    x = m;
                    decrypt = vigenere_matriz[x][0];
                    fprintf(decrypttxt, "%c", decrypt);
                    m = 27;  // finalizar o loop já que temos o valor do indice da linha já
                }
                m++;
            }

            m = 0;
            n = 0;
        }
    }

    fclose(txt);
    fclose(decrypttxt);
}

int main(){
    int option = 1;
    
    void* info = create_data();
        
    do {
        option = menu();
        switch (option)
        {
        case 0:
            printf("\n==========");
            printf("\nAté logo!");
            printf("\n==========\n");
            break;
        case 1:
            get_data(info);
            encrypt(info);
            break;
        case 2:
            get_data(info);
            decrypt(info);
            break;
        default:
            printf("ERROR - Please select a valid option!");
            break;
        }
    }while (option != 0);
    
    free_data(info);
    return 0;
}