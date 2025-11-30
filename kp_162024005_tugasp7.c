#include <stdio.h>
#include <string.h>

//Nama : Dealova Quaybah
//NRP : 162024005

long long pangkat(long long basis, long long pangkat) {
    long long hasil = 1;
    for(long long i = 0; i < pangkat; i++) {
        hasil *= basis;
    }
    return hasil;
}

long long strKeDec(char s[]) {
    long long d;
    sscanf(s, "%lld", &d);
    return d;
}

long long binKeDec(char biner[]) {
    long long panjang = strlen(biner);
    long long desimal = 0;

    for(long long i = 0; i < panjang; i++) {
        int bin;

        if (biner[i] == '1') bin = 1;
        else bin = 0;

        long long posisiKanan = panjang - 1 - i;
        desimal += bin * pangkat(2, posisiKanan);
    }
    return desimal;
}

long long octKeDec(char oktal[]) {
    long long panjang = strlen(oktal);
    long long desimal = 0;

    for(long long i = 0; i < panjang; i++) {
        long long digit;
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
                printf("Error. Karakter bukan angka oktal");
                return -1;
        }

        long long posisiKanan = panjang - 1 - i;
        desimal += digit * pangkat(8, posisiKanan);
    }
    return desimal;
}

long long hexKeDec(char heksa[]) {
    long long panjang = strlen(heksa);
    long long desimal = 0;

    for(long long i = 0; i < panjang; i++) {
        long long nilai;
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
                printf("Error. Karakter bukan Hexadecimal");
                return -1;
        }

        long long posisiKanan = panjang - 1 - i;
        desimal += nilai * pangkat(16, posisiKanan);
    }
    return desimal;
}

void decKeBin(long long desimal) {
    long long sisa[70], indeks = 0;
    if (desimal == 0) { printf("0"); return; }

    while (desimal > 0) {
        sisa[indeks] = desimal % 2;
        indeks++;
        desimal /= 2;
    }

    for(long long j = indeks - 1; j >= 0; j--) printf("%lld", sisa[j]);
}

void decKeOct(long long desimal) {
    long long sisa[70], indeks = 0;
    if (desimal == 0) { printf("0"); return; }

    while (desimal > 0) {
        sisa[indeks] = desimal % 8;
        indeks++;
        desimal /= 8;
    }

    for(long long j = indeks - 1; j >= 0; j--) printf("%lld", sisa[j]);
}

void decKeHex(long long desimal) {
    char hex[70];
    long long indeks = 0;

    if (desimal == 0) { printf("0"); return; }

    while (desimal > 0) {
        long long sisa = desimal % 16;
        char digitHex;

        if (sisa < 10) digitHex = '0' + sisa;
        else digitHex = 'A' + (sisa - 10);

        hex[indeks] = digitHex;
        indeks++;
        desimal /= 16;
    }

    for(long long j = indeks - 1; j >= 0; j--) printf("%c", hex[j]);
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

        long long d;

        switch(p) {
            case 1:  d = binKeDec(s); printf("%lld", d); break;
            case 2:  d = binKeDec(s); decKeOct(d); break;
            case 3:  d = binKeDec(s); decKeHex(d); break;
            case 4:  d = strKeDec(s); decKeBin(d); break;
            case 5:  d = strKeDec(s); decKeOct(d); break;
            case 6:  d = strKeDec(s); decKeHex(d); break;
            case 7:  d = hexKeDec(s); printf("%lld", d); break;
            case 8:  d = hexKeDec(s); decKeBin(d); break;
            case 9:  d = hexKeDec(s); decKeOct(d); break;
            case 10: d = octKeDec(s); printf("%lld", d); break;
            case 11: d = octKeDec(s); decKeBin(d); break;
            case 12: d = octKeDec(s); decKeHex(d); break;
            default: printf("Pilihan tidak valid");
        }

        printf("\n");

    } while(p != 13);

    return 0;
}
