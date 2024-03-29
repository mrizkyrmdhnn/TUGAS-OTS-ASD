#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 2024
#define MIN_LENGTH 1945

void lessThanRequired(int *lengthOfText) {
    printf("The length of your text is less than specified, please update your text\n");
    *lengthOfText = MIN_LENGTH;
}

void equalThanRequired() {
    printf("Thank you, Your text length is correct\n");
}

void moreThanRequired(int *lengthOfText) {
    printf("Your text is too long, please reduce the text\n");
    *lengthOfText = MIN_LENGTH;
}

int checkLengthRequirement(char* text) {
    int length = strlen(text);
    if (length < MIN_LENGTH)
        return 0;
    else if (length == MIN_LENGTH)
        return 1;
    else
        return 2;
}

int main() {
    int lengthOfText, selectOption;
    FILE *fptr = NULL;
    char text[MAX_LENGTH];

    fptr = fopen("file.txt", "r");

    if (fptr == NULL) {
        printf("Error");
        exit(1);
    }

    fgets(text, MAX_LENGTH, fptr);

    fclose(fptr);

    selectOption = checkLengthRequirement(text);
     // TODO
    // Pada fungsi checkLenghtRequirement akan mengembalikan sebuah angka
    // angka tersebut digunakan untuk memilih secara otomatis salah satu fungsi yang harus diisi
    // jika fungsi checkLenghtRequirement() mengembalikan nilai 0, maka
    //      tampilkan - > The length of your text is less than specified, please update your text
    //      update nilai lengthOfText ke minimum requirement melalui pointer menggunakan operasi aritmatika

    // jika fungsi checkLenghtRequirement() mengembalikan nilai 1, maka
    //      tampilkan - > Thank you, Your text length is correct

    // jika fungsi checkLenghtRequirement() mengembalikan nilai 2, maka
    //      tampilkan - > Your text is to long, please reduce the text
    //      update nilai lengthOfText ke minimum requirement melalui pointer menggunakan operasi aritmatika
    //
    // Catatan :
    //      - tidak diperkenankan menggunakan if atau switch dalam perpindahan fungsi
    //        sesuai dengan requirement diatas.
    //      - baris kode tidak lebih dari 100 (include comment ini)
    //      - tidak diperkenankan mengganti yang tertera pada starter code dalam alasan apapun


    // Function pointers to avoid using if or switch
    void (*options[3])(int *) = {lessThanRequired, equalThanRequired, moreThanRequired};
    options[selectOption](&lengthOfText);

    printf("\nThe Length is updated to %d", lengthOfText);

    return 0;
    
}


    //Penjelasan :
    //Kode diatas digunakan untuk membaca teks dari sebuah file, memeriksa panjang teks tersebut, dan memberikan respons sesuai dengan panjang teks yang dibaca. Respons yang diberikan tergantung pada apakah panjang teks sesuai dengan panjang yang diharapkan, terlalu pendek, atau terlalu panjang.
    //Pada baris 1-3,Mendefinisikan tiga direktif penghubung yang diperlukan dan konstanta-konstanta untuk panjang maksimum dan minimum teks.
    //Pada baris 5-18,Mendefinisikan tiga fungsi yaitu lessThanRequired(), equalThanRequired(), dan moreThanRequired(), masing-masing menangani kasus panjang teks kurang dari, sama dengan, atau lebih dari panjang yang diharapkan.
    //Pada baris 20-32,Mendefinisikan fungsi checkLengthRequirement() yang memeriksa panjang teks yang diberikan dan mengembalikan nilai yang sesuai berdasarkan kondisi panjang teks.
    //Pada baris 34-53,Fungsi main() membuka file "file.txt", membaca teks dari file tersebut, menutup file, memeriksa panjang teks menggunakan checkLengthRequirement(), dan kemudian memanggil salah satu dari tiga fungsi yang didefinisikan sebelumnya berdasarkan hasil pemeriksaan panjang teks.
    //Pada baris 56-59,Array options yang merupakan array dari tiga pointer ke fungsi, yang digunakan untuk memilih fungsi yang sesuai tanpa menggunakan struktur kontrol seperti if atau switch.
    //Pada baris 56-59,fungsi options[selectOption](&lengthOfText); akan memilih fungsi yang sesuai sesuai dengan nilai yang dikembalikan oleh checkLengthRequirement().
