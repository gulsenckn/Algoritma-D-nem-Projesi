#include <stdio.h>
#include <math.h>

#define GEZEGEN_SAYISI 8  // Toplam gezegen sayısı

/* Gezegen İsimleri */
char *gezegenler[] = {
    "Merkur", "Venus", "Dunya", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptun"
};

/* İstenilen Fonksiyonlar */
void liste();
void serbest_dusme(double *g);
void yukari_atis(double *g);
void agirlik(double *g);
void potansiyel_enerji(double *g);
void hidrostatik_basinc(double *g);
void arsimet(double *g);
void sarkac(double *g);
void ip_gerilmesi(double *g);
void asansor(double *g);

int main() {

    char bilim_insani[50]; // Bilim insaninin adi
    int secim;

    // Gezegenlerin yerçekimi ivmeleri (m/s^2)
    double g[] = {3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15}; // Gezegenlere yakınlıklarına göre sıralanmıştır.
    // Kullanıcıdan bilim insanının adını girmesini ister.
    printf("Bilim insaninin adini giriniz: ");
    scanf("%s", bilim_insani);

    printf("\nHos geldiniz %s!\n", bilim_insani);

    // Seçim -1 olana kadar döngü çalışır.
    while (1) {
        liste();

        printf("Bir secim yapiniz: ");
        scanf(" %d", &secim);

        if (secim == -1) {
            printf("Program sonlandirildi.\n");
            break;
        }

        // Kullanıcının seçimine göre deney çağrılır.
        switch (secim) {
            case 1:
                serbest_dusme(g);
                break;
            case 2:
                 yukari_atis(g);
                 break;
            case 3:
                agirlik(g);
                break;
            case 4:
                potansiyel_enerji(g);
                break;
            case 5:
                hidrostatik_basinc(g);
                break;
            case 6:
                arsimet(g);
                break;
            case 7:
                sarkac(g);
                break;
            case 8:
                ip_gerilmesi(g);
                break;
            case 9:
                asansor(g);
                break;
            default: printf("Hatali bir secim yaptiniz!\n");
        }
    }

    return 0;
}

// ---------------- LİSTE ----------------
void liste() {
    printf("\n DENEY LİSTESİ \n");
    printf("1 - Serbest Dusme\n");
    printf("2 - Yukari Atis\n");
    printf("3 - Agirlik\n");
    printf("4 - Potansiyel Enerji\n");
    printf("5 - Hidrostatik Basinc\n");
    printf("6 - Arsimet Kaldirma Kuvveti\n");
    printf("7 - Basit Sarkac\n");
    printf("8 - Sabit Ip Gerilmesi\n");
    printf("9 - Asansor Deneyi\n");
    printf("-1 - Cikis\n");
}

/*DENEYLER*/
// ------------- 1. SERBEST DÜŞME -------------

void serbest_dusme(double *g) {
    double t, h;

    printf("Sureyi giriniz (s): ");
    scanf("%lf", &t);

    // Süre negatifse ternary operatörü ile mutlak değere çevrilir.
    t = (t < 0) ? -t : t;

    // Tüm gezegenler için bu hesaplamayı yapar.
    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        // h'ın formülünü tanımlar.
        // *(g+i) programda istenilen gezegenin yerçekim ivmesidir.
        h = 0.5 * (*(g + i)) * t * t;
        printf("%s icin alinan yol: %.2lf metre\n", gezegenler[i], h);
    }
}
// ------------- 2. YUKARI ATIŞ -------------
void yukari_atis(double *g) {
    double v0, hmax;

    printf("Ilk hizi giriniz (m/s): ");
    scanf("%lf", &v0);
    v0 = (v0 < 0) ? -v0 : v0;

    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        hmax = (v0 * v0) / (2 * (*(g + i)));
        printf("%s icin maksimum yukseklik: %.2lf metre\n", gezegenler[i], hmax);
    }
}
// ------------- 3. AĞIRLIK -------------
void agirlik(double *g) {
    double m, G;
    printf("Kutleyi giriniz (kg): ");
    scanf("%lf", &m);
    m = (m < 0) ? -m : m;

    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        G = m * (*(g + i));
        printf("%s icin agirlik: %.2lf Newton\n", gezegenler[i], G);
    }
}
// ------------- 4. POTANSİYEL ENERJİ -------------
void potansiyel_enerji(double *g) {
    double m, h, Ep;
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    printf("Yukseklik (m): ");
    scanf("%lf", &h);
    m = (m < 0) ? -m : m;
    h = (h < 0) ? -h : h;

    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        Ep = m * (*(g + i)) * h;
        printf("%s icin Ep: %.2lf Joule\n", gezegenler[i], Ep);
    }
}
// ------------- 5. HİDROSTATİK BASINÇ -------------
void hidrostatik_basinc(double *g) {
    double yogunluk, h, P;
    printf("Yogunluk (kg/m^3): ");
    scanf("%lf", &yogunluk);
    printf("Derinlik (m): ");
    scanf("%lf", &h);
    yogunluk = (yogunluk < 0) ? -yogunluk : yogunluk;
    h = (h < 0) ? -h : h;

    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        P = yogunluk * (*(g + i)) * h;
        printf("%s icin basinc: %.2lf Pascal\n", gezegenler[i], P);
    }
}
// ------------- 6. ARŞİMET KALDIRMA KUVVETİ -------------
void arsimet(double *g) {
    double yogunluk, V, Fk;
    // Sıvının yoğunluğu
    printf("Yogunluk (kg/m^3): ");
    scanf("%lf", &yogunluk);
    // Cismin batan hacmi
    printf("Hacim (m^3): ");
    scanf("%lf", &V);
    yogunluk = (yogunluk < 0) ? -yogunluk : yogunluk;
    V = (V < 0) ? -V : V;

    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        Fk = yogunluk * (*(g + i)) * V;
        printf("%s icin kaldirma kuvveti: %.2lf Newton\n", gezegenler[i], Fk);
    }
}
// ------------- 7. BASİT SARKAÇ -------------
void sarkac(double *g) {
    double L, T;
    // Sarkacın ip uzunluğu
    printf("Ip uzunlugu (m): ");
    scanf("%lf", &L);
    L = (L < 0) ? -L : L;

    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        T = 2 * 3.14159 * sqrt(L / (*(g + i)));
        printf("%s icin periyot: %.2lf saniye\n", gezegenler[i], T);
    }
}
// ------------- 8. SABİT İP GERİLMESİ -------------
void ip_gerilmesi(double *g) {
    double m, T;
    // Asılı cismin kütlesi
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    m = (m < 0) ? -m : m;

    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        T = m * (*(g + i));
        printf("%s icin ip gerilmesi: %.2lf Newton\n", gezegenler[i], T);
    }
}
// ------------- 9. ASANSÖR DENEYİ -------------
void asansor(double *g) {
    double m, a, N;
    //Asansördeki kişinin kütlesi
    printf("Kutle (kg): ");
    scanf("%lf", &m);
    // asansörün ivmesi
    printf("Asansor ivmesi (m/s^2): ");
    scanf("%lf", &a);
    m = (m < 0) ? -m : m;
    a = (a < 0) ? -a : a;

    for (int i = 0; i < GEZEGEN_SAYISI; i++) {
        N = m * ((*(g + i)) + a);
        printf("%s icin hissedilen agirlik: %.2lf Newton\n", gezegenler[i], N);
    }
}


















