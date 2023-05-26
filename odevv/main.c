#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Ülkelerin verilerini temsil eden sturct yapýsý
struct Ulke {
    char ad[30];// boyutunu 30 karakter olarak seçtik
	 double gelir;
    double nufus;
    double yuzolcumu;
};

int i = 0;
int j = 0;

// Bulanýk kümeleme analizi fonksiyonu tanýmladýk
void bulanikKumeleme(struct Ulke ulkeler[], int ulkeSayisi) {
	
	 // Parametrelerin ve kümelerin sayýsýný tanýmladýk
    int parametreSayisi = 3;
    int kumeSayisi = 3;
    
// Ülkelerin kümeye atanacaðý indislerin tutulacaðý dizi tanýmladýk
    int kumeAtama[ulkeSayisi];
    
 // Kümelerin merkezlerini tutan dizi tanýmladýk
    struct Ulke kumeMerkezleri[kumeSayisi];
    
 // Kümelerin merkezlerini rastgele baþlattýk
    for (i = 0; i < kumeSayisi; i++) {
        kumeMerkezleri[i] = ulkeler[i];
    }

// Ýterasyon sayýsý tanýmladýk
    int iterasyon = 0;
    int maxIterasyon = 10;

// Ana döngü
     while (iterasyon < maxIterasyon) {
     	
     	  // Her ülkenin kümeye atanma iþlemini yaptýk
        for (i = 0; i < ulkeSayisi; i++) {
            double enYakinUzaklik = INFINITY;
            int enYakinKume = 0;
            
// Her kümeyi kontrol etme döngüsünü oluþturduk
        for (j = 0; j < kumeSayisi; j++) {
        	// Ülkenin kümeye uzaklýðýný hesapladýk
                double uzaklik = fabs(ulkeler[i].gelir - kumeMerkezleri[j].gelir)
                    + fabs(ulkeler[i].nufus - kumeMerkezleri[j].nufus)
                    + fabs(ulkeler[i].yuzolcumu - kumeMerkezleri[j].yuzolcumu);
                    
// En yakýn kümeyi ve uzaklýðýný güncelledik
                if (uzaklik < enYakinUzaklik) {
                    enYakinUzaklik = uzaklik;
                    enYakinKume = j;
                }
            }

             // Ülkeyi en yakýn kümeye atadýk
			 kumeAtama[i] = enYakinKume;
        }

        // Kümelerin merkezlerini güncelledik
		for (i = 0; i < kumeSayisi; i++) {
            double yeniGelir = 0.0;
            double yeniNufus = 0.0;
            double yeniYuzolcumu = 0.0;
            int ulkeSayac = 0;

              // Kümeye atanmýþ ülkelerin verilerini topladýk
        for (j = 0; j < ulkeSayisi; j++) {
                if (kumeAtama[j] == i) {
                    yeniGelir += ulkeler[j].gelir;
                    yeniNufus += ulkeler[j].nufus;
                    yeniYuzolcumu += ulkeler[j].yuzolcumu;
                    ulkeSayac++;
                }
            }

             // Kümelerin merkezlerini güncelledik
        if (ulkeSayac > 0) {
                kumeMerkezleri[i].gelir = yeniGelir / ulkeSayac;
                kumeMerkezleri[i].nufus = yeniNufus / ulkeSayac;
                kumeMerkezleri[i].yuzolcumu = yeniYuzolcumu / ulkeSayac;
            }
        }

        iterasyon++;
    }
    
 // Kümelerin sonuçlarýný ekrana yazdýrma iþlemini yaptýk
    for (i = 0; i < kumeSayisi; i++) {
        printf("Kume %d:\n", i + 1);

                // Kümeye atanmýþ ülkeleri gösterdik
    for (j = 0; j < ulkeSayisi; j++) {
            if (kumeAtama[j] == i) {
                printf("- %s\n", ulkeler[j].ad);
            }
        }

        printf("------------------------\n");
    }
}

int main() {
	// ülke verileri
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

     // Bulanýk kümeleme analizini uygula
    bulanikKumeleme(ulkeler, 15);

	return 0;
}
