#include <stdio.h>
#include <string.h>

//Nama : Dealova Quaybah
//NRP : 162024005

int pangkat(int basis, int pangkat) {
    int hasil = 1;
    for(int i = 0; i < pangkat; i++) {
        hasil *= basis;
    }
    return hasil;
}

int strToDec(char s[]) {
    int d;
    sscanf(s, "%d", &d);
    return d;
}

int binToDec(char biner[]) {
    int panjang = strlen(biner);
    int desimal = 0;

    for(int i = 0; i < panjang; i++) {
        int bin;

        if (biner[i] == '1') {
            bin = 1;
        } else {
            bin = 0;
        }

        int posisiKanan = panjang - 1 - i;
        desimal += bin * pangkat(2, posisiKanan);
    }
    return desimal;
}

int octToDec(char oktal[]) {
    int panjang = strlen(oktal);
    int desimal = 0;

    for(int i = 0; i < panjang; i++) {
        int digit;
        switch (oktal[i]) {
            case '0': digit = 0; break;
            case '1': digit = 1; break;
            case '2': digit = 2; break;
            case '3': digit = 3; break;
            case '4': digit = 4; break;
            case '5': digit = 5; break;
            case '6': digit = 6; break;
            case '7': digit = 7; break;
            default:
                printf("Error. Karakter bukan angka oktal\n");
                return -1;
        }

        int posisiKanan = panjang - 1 - i;
        desimal += digit * pangkat(8, posisiKanan);
    }
    return desimal;
}

int hexToDec(char heksa[]) {
    int panjang = strlen(heksa);
    int desimal = 0;

    for(int i = 0; i < panjang; i++) {
        int nilai;
        switch (heksa[i]) {
            case '0': nilai = 0; break;
            case '1': nilai = 1; break;
            case '2': nilai = 2; break;
            case '3': nilai = 3; break;
            case '4': nilai = 4; break;
            case '5': nilai = 5; break;
            case '6': nilai = 6; break;
            case '7': nilai = 7; break;
            case '8': nilai = 8; break;
            case '9': nilai = 9; break;

            case 'A': case 'a': nilai = 10; break;
            case 'B': case 'b': nilai = 11; break;
            case 'C': case 'c': nilai = 12; break;
            case 'D': case 'd': nilai = 13; break;
            case 'E': case 'e': nilai = 14; break;
            case 'F': case 'f': nilai = 15; break;

            default:
                printf("Error. Karakter bukan Hexadecimal\n");
                return -1;
        }

        int posisiKanan = panjang - 1 - i;
        desimal += nilai * pangkat(16, posisiKanan);
    }
    return desimal;
}


void decToBin(int desimal) {
    int sisa[50], indeks = 0;
    if (desimal == 0) { printf("0"); return; }

   while (desimal > 0) {
        sisa[indeks] = desimal % 2; 
        indeks++;                    
        desimal = desimal / 2;       
    }

    for(int j = indeks-1; j >= 0; j--) {
        printf("%d", sisa[j]);
    }
}


void decToOct(int desimal) {
    int sisa[50], indeks = 0;
    if (desimal == 0) { printf("0"); return; }

     while (desimal > 0) {
        sisa[indeks] = desimal % 8; 
        indeks++;                    
        desimal = desimal / 8;       
    }

    for(int j = indeks-1; j >= 0; j--) {
        printf("%d", sisa[j]);
    }
}


void decToHex(int desimal) {
    char hex[50];
    int indeks = 0;

    if (desimal == 0) {
        printf("0");
        return;
    }

    while (desimal > 0) {
        int sisa = desimal % 16;
        char digitHex;

        if (sisa < 10) {
            digitHex = '0' + sisa;
        } else {
            digitHex = 'A' + (sisa - 10);
        }

        hex[indeks] = digitHex;
        indeks++;
        desimal = desimal / 16;
    }

    for (int i = indeks - 1; i >= 0; i--) {
        printf("%c", hex[i]);
    }
}


int main() {
    int p;
    char s[50];

    do {
        printf("\n==== KONVERSI SISTEM BILANGAN ===\n");
        printf(" 1. Biner ke Desimal\n");
        printf(" 2. Biner ke Oktal\n");
        printf(" 3. Biner ke Heksadesimal\n");
        printf(" 4. Desimal ke Biner\n");
        printf(" 5. Desimal ke Oktal\n");
        printf(" 6. Desimal ke Heksadesimal\n");
        printf(" 7. Heksa ke Desimal\n");
        printf(" 8. Heksa ke Biner\n");
        printf(" 9. Heksa ke Oktal\n");
        printf("10. Oktal ke Desimal\n");
        printf("11. Oktal ke Biner\n");
        printf("12. Oktal ke Heksadesimal\n");
        printf("13. Keluar\n");
        printf("===================================\n\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &p);

        if(p == 13) break;

        printf("Masukkan nilai: ");
        scanf("%s", s);

        int d;

        switch(p) {
            case 1:  d = binToDec(s); printf("%d", d); break;
            case 2:  d = binToDec(s); decToOct(d); break;
            case 3:  d = binToDec(s); decToHex(d); break;
            case 4:  d = strToDec(s); decToBin(d); break;
            case 5:  d = strToDec(s); decToOct(d); break;
            case 6:  d = strToDec(s); decToHex(d); break;
            case 7:  d = hexToDec(s); printf("%d", d); break;
            case 8:  d = hexToDec(s); decToBin(d); break;
            case 9:  d = hexToDec(s); decToOct(d); break;
            case 10: d = octToDec(s); printf("%d", d); break;
            case 11: d = octToDec(s); decToBin(d); break;
            case 12: d = octToDec(s); decToHex(d); break;
            default: printf("Pilihan tidak valid!");
        }

        printf("\n");

    } while(p != 13);

    return 0;
}
