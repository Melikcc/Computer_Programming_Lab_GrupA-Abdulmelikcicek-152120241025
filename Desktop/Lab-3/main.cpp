#include <iostream>
#include <string>
using namespace std;
struct Sarki {
    string ad, sarkici;
    int puanlar[3];
    Sarki *sonraki, *onceki;
};

Sarki *bas = NULL;
Sarki *suanki = NULL;
void ekle(string sarkiAd, string sarkiciAd, int p1, int p2, int p3) {
    Sarki *yeni = new Sarki;
    yeni->ad = sarkiAd;
    yeni->sarkici = sarkiciAd;
    yeni->puanlar[0] = p1;
    yeni->puanlar[1] = p2;
    yeni->puanlar[2] = p3;
    yeni->sonraki = NULL;
    yeni->onceki = NULL;

    if (bas == NULL) {
        bas = suanki = yeni;
    } else {
        Sarki *gecici = bas;
        while (gecici->sonraki != NULL) gecici = gecici->sonraki;
        gecici->sonraki = yeni;
        yeni->onceki = gecici;
    }
}

// 3. Silme Fonksiyonu
void sil() {
    if (suanki == NULL) return;
    Sarki *silinecek = suanki;

    if (silinecek->onceki != NULL) silinecek->onceki->sonraki = silinecek->sonraki;
    else bas = silinecek->sonraki;

    if (silinecek->sonraki != NULL) {
        silinecek->sonraki->onceki = silinecek->onceki;
        suanki = silinecek->sonraki;
    } else {
        suanki = silinecek->onceki;
    }
    delete silinecek;
}
void listele() {
    Sarki *t = bas;
    while (t != NULL) {
        if (t == suanki) cout << "-> ";
        else cout << "   ";
        cout << t->ad << " [" ;
        for (int i = 0; i < 3; i++) cout << t->puanlar[i] << (i < 2 ? "," : "");
        cout << "]" << endl;

        t = t->sonraki;
    }
}
int main() {
    ekle("Sarki 1", "Sarkici 1", 5, 4, 3);
    ekle("Sarki 2", "Sarkici 2", 2, 3, 5);
    ekle("Sarki 3", "Sarkici 3", 1, 1, 1);

    listele();
    if (suanki->sonraki != NULL) suanki = suanki->sonraki;
    
    cout << "\nSarki 2 siliniyor...\n";
    sil();
    listele();

    return 0;
}