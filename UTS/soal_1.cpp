#include<iostream>
#include<vector>
#include <string>
#include<limits>
using namespace std;


// Struct pasien digunakan untuk menyimpan data tiap pasien (hewan)
struct pasien {
    string nama;            // nama pasien/hewan
    string jenis;           // jenis hewan
    int umur;               // umur hewan
    int tingkat_darurat;    // tingkat darurat (1–5)
};


// Menambahkan satu data pasien ke dalam antrean (vector)
void tambah_hewan(vector<pasien> & antrean, pasien p){
    antrean.push_back(p);
};


// Mengurutkan antrean berdasarkan tingkat darurat secara descending
// Artinya, pasien dengan tingkat darurat paling tinggi akan berada di atas.
// Bubble sort dipakai di sini.
void urutkanAntrean(vector<pasien>&antrean){
    for(int i=0; i<antrean.size()-1; i++){
        for (int j=0; j<antrean.size()-i-1; j++){
            if(antrean[j].tingkat_darurat<antrean[j+1].tingkat_darurat){
                swap(antrean[j], antrean[j+1]); // tukar posisi jika perlu
            }
        }
    }
}


// Menampilkan seluruh daftar pasien yang sudah diurutkan
void tampilkanAntrean(const vector<pasien>& antrean) {
    cout << "Daftar Pasien" << endl;
    for (int i = 0; i < antrean.size(); i++) {
        cout << i + 1 << ". " 
             << antrean[i].nama 
             << " (" << antrean[i].umur << " tahun) - "
             << "Darurat " << antrean[i].tingkat_darurat 
             << endl;
    }
}



// Program utama: input data pasien, urutkan, lalu tampilkan hasilnya
int main(){
    int jumlah;
    cout <<"Masukkan Jumlah Pasien:"; // input banyaknya pasien
    cin>> jumlah;

    // Membersihkan buffer agar getline tidak tertinggal oleh '\n'
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<pasien> antrean; // deklarasi vector untuk menyimpan antrean

    // Input data tiap pasien
    for (int i=0;i<jumlah; i++){
        pasien p;
        cout<<"\nPasien:"<<i+1<<":\n";

        cout<<"Nama hewan:";          // input nama
        getline(cin, p.nama);

        cout<<"Jenis hewan:";         // input jenis
        getline(cin, p.jenis);

        cout<<"umur:";                // input umur dengan validasi angka
        while(!(cin>>p.umur)){
            cout<<"masukkan umur:";   // jika salah input, minta ulang
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // bersihkan buffer sebelum input berikutnya
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout<<"Tingkat darurat(1-5):"; // input tingkat darurat
        while(!(cin>>p.tingkat_darurat)){
            cout<<"masukkan  tingkat darurat:"; // validasi angka juga
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // bersihkan buffer lagi sebelum lanjut
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Tambahkan pasien ke antrean
        tambah_hewan(antrean, p);
     }

     // Urutkan berdasarkan tingkat darurat
     urutkanAntrean(antrean);

     // Tampilkan hasil antrean yang sudah diurutkan
     tampilkanAntrean(antrean);

     return 0;
}

