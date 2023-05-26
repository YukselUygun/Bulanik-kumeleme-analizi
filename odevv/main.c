#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// �lkelerin verilerini temsil eden sturct yap�s�
struct Ulke {
    char ad[30];// boyutunu 30 karakter olarak se�tik
	 double gelir;
    double nufus;
    double yuzolcumu;
};

int i = 0;
int j = 0;

// Bulan�k k�meleme analizi fonksiyonu tan�mlad�k
void bulanikKumeleme(struct Ulke ulkeler[], int ulkeSayisi) {
	
	 // Parametrelerin ve k�melerin say�s�n� tan�mlad�k
    int parametreSayisi = 3;
    int kumeSayisi = 3;
    
// �lkelerin k�meye atanaca�� indislerin tutulaca�� dizi tan�mlad�k
    int kumeAtama[ulkeSayisi];
    
 // K�melerin merkezlerini tutan dizi tan�mlad�k
    struct Ulke kumeMerkezleri[kumeSayisi];
    
 // K�melerin merkezlerini rastgele ba�latt�k
    for (i = 0; i < kumeSayisi; i++) {
        kumeMerkezleri[i] = ulkeler[i];
    }

// �terasyon say�s� tan�mlad�k
    int iterasyon = 0;
    int maxIterasyon = 10;

// Ana d�ng�
     while (iterasyon < maxIterasyon) {
     	
     	  // Her �lkenin k�meye atanma i�lemini yapt�k
        for (i = 0; i < ulkeSayisi; i++) {
            double enYakinUzaklik = INFINITY;
            int enYakinKume = 0;
            
// Her k�meyi kontrol etme d�ng�s�n� olu�turduk
        for (j = 0; j < kumeSayisi; j++) {
        	// �lkenin k�meye uzakl���n� hesaplad�k
                double uzaklik = fabs(ulkeler[i].gelir - kumeMerkezleri[j].gelir)
                    + fabs(ulkeler[i].nufus - kumeMerkezleri[j].nufus)
                    + fabs(ulkeler[i].yuzolcumu - kumeMerkezleri[j].yuzolcumu);
                    
// En yak�n k�meyi ve uzakl���n� g�ncelledik
                if (uzaklik < enYakinUzaklik) {
                    enYakinUzaklik = uzaklik;
                    enYakinKume = j;
                }
            }

             // �lkeyi en yak�n k�meye atad�k
			 kumeAtama[i] = enYakinKume;
        }

        // K�melerin merkezlerini g�ncelledik
		for (i = 0; i < kumeSayisi; i++) {
            double yeniGelir = 0.0;
            double yeniNufus = 0.0;
            double yeniYuzolcumu = 0.0;
            int ulkeSayac = 0;

              // K�meye atanm�� �lkelerin verilerini toplad�k
        for (j = 0; j < ulkeSayisi; j++) {
                if (kumeAtama[j] == i) {
                    yeniGelir += ulkeler[j].gelir;
                    yeniNufus += ulkeler[j].nufus;
                    yeniYuzolcumu += ulkeler[j].yuzolcumu;
                    ulkeSayac++;
                }
            }

             // K�melerin merkezlerini g�ncelledik
        if (ulkeSayac > 0) {
                kumeMerkezleri[i].gelir = yeniGelir / ulkeSayac;
                kumeMerkezleri[i].nufus = yeniNufus / ulkeSayac;
                kumeMerkezleri[i].yuzolcumu = yeniYuzolcumu / ulkeSayac;
            }
        }

        iterasyon++;
    }
    
 // K�melerin sonu�lar�n� ekrana yazd�rma i�lemini yapt�k
    for (i = 0; i < kumeSayisi; i++) {
        printf("Kume %d:\n", i + 1);

                // K�meye atanm�� �lkeleri g�sterdik
    for (j = 0; j < ulkeSayisi; j++) {
            if (kumeAtama[j] == i) {
                printf("- %s\n", ulkeler[j].ad);
            }
        }

        printf("------------------------\n");
    }
}

int main() {
	// �lke verileri
    struct Ulke ulkeler[15] = {
        {"Turkiye", 10000, 80000000, 780000},
        {"Almanya", 50000, 82000000, 357000},
        {"Fransa", 60000, 67000000, 640000},
        {"Ingiltere", 45000, 66000000, 240000},
        {"Italya", 40000, 60000000, 300000},
        {"Cin", 15000, 1400000000, 9600000},
        {"Japonya", 48000, 126000000, 377835},
        {"Rusya", 11000, 144000000, 17098246},
        {"Brezilya", 9000, 210000000, 8515767},
        {"Kanada", 52000, 37000000, 9976140},
        {"Avustralya", 55000, 25000000, 7692024},
        {"Meksika", 10000, 130000000, 1964375},
        {"Guney Kore", 40000, 52000000, 100363},
        {"Hindistan", 5000, 1366000000, 3287263},
        {"Guney Afrika", 13000, 58000000, 1219090}
    };

     // Bulan�k k�meleme analizini uygula
    bulanikKumeleme(ulkeler, 15);

	return 0;
}
