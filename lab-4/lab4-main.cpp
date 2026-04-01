#include <iostream>
#include <string>

using namespace std;

// --- Veri Yapıları ---
struct Package {
    string id, city;
    int dim[3];
    Package* next;
};

struct Courier {
    string name, type;
};

// Global Değişkenler (İsimleri çakışmaması için değiştirdik)
Package* top = nullptr; 
Courier kuryeSira[5]; // "queue" yerine "kuryeSira" yaptık
int front = -1, rear = -1, kapasite = 5;

// 1. Arrival (Push)
void push() {
    Package* yeni = new Package;
    cout << "Paket ID: "; cin >> yeni->id;
    cout << "Sehir: "; cin >> yeni->city;
    yeni->dim[0] = 10; yeni->dim[1] = 10; yeni->dim[2] = 10;
    yeni->next = top;
    top = yeni;
    cout << "Paket yigina eklendi.\n";
}

// 2. Courier Register (Enqueue)
void enqueue() {
    if ((front = (rear + 1) % kapasite)) {
        cout << "Kuyruk dolu!\n";
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % kapasite;
    cout << "Kurye Ismi: "; cin >> kuryeSira[rear].name;
    cout << "Arac Tipi: "; cin >> kuryeSira[rear].type;
    cout << "Kurye siraya eklendi.\n";
}

// 3. Dispatch (Pop & Dequeue)
void dispatch() {
    if (top == nullptr || front == -1) {
        cout << "Hata: Paket veya kurye eksik!\n";
        return;
    }
    // Stackten çıkar (Pop)
    Package* p = top;
    top = top->next;

    // Kuyruktan çıkar (Dequeue)
    Courier c = kuryeSira[front];
    if (front == rear) { front = -1; rear = -1; }
    else { front = (front + 1) % kapasite; }

    cout << "Gonderim yapildi: " << c.name << " -> " << p->id << endl;
    delete p;
}

// 4. Display
void display() {
    cout << "\n--- DURUM ---" << endl;
    cout << "Paketler (Stack): ";
    Package* t = top;
    while(t) { cout << t->id << " "; t = t->next; }

    cout << "\nKuryeler (Queue): ";
    if(front != -1) {
        int i = front;
        while(true) {
            cout << kuryeSira[i].name << " ";
            if(i == rear) break;
            i = (i + 1) % kapasite;
        }
    }
    cout << "\n-------------\n";
}

int main() {
    string komut;
    cout << "Komutlar: push, enqueue, dispatch, display, exit" << endl;

    while (true) {
        cout << "Komut: "; cin >> komut;
        if (komut == "push") push();
        else if (komut == "enqueue") enqueue();
        else if (komut == "dispatch") dispatch();
        else if (komut == "display") display();
        else if (komut == "exit") break;
        else cout << "Gecersiz komut!\n";
    }
    return 0;
}