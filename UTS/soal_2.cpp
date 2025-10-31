#include <iostream>
#include <string>
using namespace std;


// Setiap node menyimpan data film dan pointer ke film berikutnya
struct film {
    string judul;
    int tahun;
    int rating;
    film* next;
};

film* head = NULL; // pointer awal linked list (kepala daftar)

//buat node baru
film* newFilm(string judul, int tahun, int rating) {
    film* baru = new film;   // alokasi node baru
    baru->judul = judul;
    baru->tahun = tahun;
    baru->rating = rating;
    baru->next = NULL;
    return baru;
}

//penambahan di belakang
// Menambahkan node di akhir daftar
void tambahBelakang(string judul, int tahun, int rating) {
    film* baru = newFilm(judul, tahun, rating);
    // kalau list masih kosong
    if (head == NULL) {
        head = baru;
        return;
    }
    // cari node terakhir
    film* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru; // sambungkan node baru di akhir
}

//penambahan di depan
// Menambahkan node di awal daftar
void tambahDepan(string judul, int tahun, int rating) {
    film* baru = newFilm(judul, tahun, rating);
    baru->next = head; // node baru menunjuk ke head lama
    head = baru;       // ubah head ke node baru
}

//menambahkan di akhir
// Menyisipkan node baru setelah film dengan judul tertentu
void tambahSetelah(string targetJudul, string judul, int tahun, int rating) {
    film* temp = head;
    // cari node yang judulnya sesuai target
    while (temp != NULL && temp->judul != targetJudul) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Film " << targetJudul << " tidak ditemukan.\n";
        return;
    }
    film* baru = newFilm(judul, tahun, rating);
    baru->next = temp->next; // sambungkan node baru ke node setelah target
    temp->next = baru;       // hubungkan node target ke node baru
}

//hapus film
// Menghapus node berdasarkan judul film
void hapusFilm(string judul) {
    if (head == NULL) { // list kosong
        cout << "Daftar film kosong.\n";
        return;
    }

    // jika film yang dihapus adalah head
    if (head->judul == judul) {
        film* hapus = head;
        head = head->next; // pindahkan head ke film berikutnya
        delete hapus;      // hapus node lama dari memori
        cout << "Film \"" << judul << "\" telah dihapus.\n";
        return;
    }

    // cari film yang akan dihapus
    film* temp = head;
    while (temp->next != NULL && temp->next->judul != judul) {
        temp = temp->next;
    }

    // kalau film tidak ditemukan
    if (temp->next == NULL) {
        cout << "Film \"" << judul << "\" tidak ditemukan.\n";
        return;
    }

    // hapus node menjadi  target
    film* hapus = temp->next;
    temp->next = hapus->next; // lewati node yang dihapus
    delete hapus;
    cout << "Film \"" << judul << "\" telah dihapus.\n";
}

//fungsi menampilkan film
void tampilkanFilm() {
    film* temp = head;
    int count = 0;

    if (temp == NULL) {
        cout << "Daftar film kosong.\n";
        return;
    }

   
    while (temp != NULL) {
        cout << temp->judul << " (" << temp->tahun << ") - Rating: " << temp->rating << endl;
        temp = temp->next;
        count++;
    }
   
    cout << "Total film tersisa: " << count << endl;
}


int main() {
    int n;
    cout << "Masukkan jumlah film awal: ";
    cin >> n;
    cin.ignore(); // membersihkan buffer

    // input film awal dari user
    for (int i = 0; i < n; i++) {
        string judul;
        int tahun, rating;
        cout << "\nFilm " << i + 1 << ":\n";
        cout << "Judul: ";
        getline(cin, judul);
        cout << "Tahun: ";
        cin >> tahun;
        cout << "Rating: ";
        cin >> rating;
        cin.ignore();

        tambahBelakang(judul, tahun, rating);
    }

    // opsi hapus film
    char hapus;
    cout << "\nApakah ingin menghapus film? (y/n): ";
    cin >> hapus;
    cin.ignore();

    if (hapus == 'y' || hapus == 'Y') {
        string target;
        cout << "Masukkan judul film yang sudah ditonton: ";
        getline(cin, target);
        hapusFilm(target);
    }

    // tampilkan hasil akhir
    
    tampilkanFilm();

    return 0;
}

