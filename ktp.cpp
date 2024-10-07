#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// DYAH RAHMA ALIFIYAH
// 2300018154
struct TTL {
    string tempat;
    string tanggal; // dd-mm-yyyy
};

struct Alamat {
    string dusun;
    string rt;
    string rw;
    string kelurahan;
    string kecamatan;
};

class KTP {
public:
    string nik;	
    string nama;
    TTL ttl;
    bool jenisKelamin; // true = Laki-laki, false = Perempuan
    string golonganDarah; // Golongan darah (misal: A, B, O, AB)
    Alamat alamat;
    string agama;
    bool statusPerkawinan; // true = Sudah menikah, false = Belum menikah
    string pekerjaan;
    bool kewarganegaraan; // true = WNI, false = WNA

    KTP() {}

    KTP(string nik, string nama, TTL ttl, bool jenisKelamin, string golonganDarah,
        Alamat alamat, string agama, bool statusPerkawinan, string pekerjaan, bool kewarganegaraan) {
        this->nik = nik;
        this->nama = nama;
        this->ttl = ttl;
        this->jenisKelamin = jenisKelamin;
        this->golonganDarah = golonganDarah;
        this->alamat = alamat;
        this->agama = agama;
        this->statusPerkawinan = statusPerkawinan;
        this->pekerjaan = pekerjaan;
        this->kewarganegaraan = kewarganegaraan;
    }

    void tampilkanData() {
        cout << "NIK                    : " << nik << endl;
        cout << "Nama                   : " << nama << endl;
        cout << "Tempat, Tanggal Lahir  : " << ttl.tempat << ", " << ttl.tanggal << endl;
        cout << "Jenis Kelamin          : " << (jenisKelamin ? "Laki-laki" : "Perempuan") << endl;
        cout << "Golongan Darah         : " << golonganDarah << endl;
        cout << "Alamat                 : " << alamat.dusun << endl;
        cout << "	RT/RW				: " << alamat.rt << "/" << alamat.rw << endl;
        cout << "   Kel/Desa			: " << alamat.kelurahan << endl;
        cout << "   Kecamatan			: " << alamat.kecamatan << endl;
        cout << "Agama                  : " << agama << endl;
        cout << "Status Perkawinan      : " << (statusPerkawinan ? "Sudah menikah" : "Belum menikah") << endl;
        cout << "Pekerjaan              : " << pekerjaan << endl;
        cout << "Kewarganegaraan        : " << (kewarganegaraan ? "WNI" : "WNA") << endl;
        cout << "Berlaku Hingga         : SEUMUR HIDUP" << endl;
        cout << "------------------------------------------------------------------" << endl;
    }
    
    
    // MUHAMMAD BINTANG GHIFFARI
    // 2300018159
    void bacaDariFile() {
	    ifstream fileIn("dataKTP.txt");
	    string line;
	    if (fileIn.is_open()) {
	        while (getline(fileIn, line)) {
	            cout << "NIK                    : " << line << endl;
	            getline(fileIn, line);
	            cout << "Nama                   : " << line << endl;
	            getline(fileIn, line);
	            cout << "Tempat, Tanggal Lahir  : " << line << ", ";
	            getline(fileIn, line);
	            cout << line << endl; // Tanggal lahir
	            getline(fileIn, line);
	            cout << "Jenis Kelamin          : " << (line == "1" ? "Laki-laki" : "Perempuan") << endl;
	            getline(fileIn, line);
	            cout << "Golongan Darah         : " << line << endl;
	            getline(fileIn, line);
	            cout << "Alamat                 : " << line << endl; // Dusun
	            getline(fileIn, line);
	            cout << "   RT/RW              	: " << line << "/"; // RT
	            getline(fileIn, line);
	            cout << line << endl; // RW
	            getline(fileIn, line);
	            cout << "   Kel/Desa          	: " << line << endl; // Kelurahan
	            getline(fileIn, line);
	            cout << "   Kecamatan         	: " << line << endl; // Kecamatan
	            getline(fileIn, line);
	            cout << "Agama                  : " << line << endl;
	            getline(fileIn, line);
	            cout << "Status Perkawinan      : " << (line == "1" ? "Sudah menikah" : "Belum menikah") << endl;
	            getline(fileIn, line);
	            cout << "Pekerjaan              : " << line << endl;
	            getline(fileIn, line);
	            cout << "Kewarganegaraan        : " << (line == "1" ? "WNI" : "WNA") << endl;
	            cout << "Berlaku Hingga         : SEUMUR HIDUP" << endl;
	            cout << "------------------------------------------------------------------" << endl;
	        }
	        fileIn.close();
	    } else {
	        cout << "File tidak dapat dibuka." << endl;
	    }
	}

	
	void simpanKeFile(KTP dataKTP[], int jumlahData) {
	    ofstream fileOut("dataKTP.txt");
	
	    if (fileOut.is_open()) {
	        for (int i = 0; i < jumlahData; i++) {
	            fileOut << dataKTP[i].nik << endl;
	            fileOut << dataKTP[i].nama << endl;
	            fileOut << dataKTP[i].ttl.tempat << endl;
	            fileOut << dataKTP[i].ttl.tanggal << endl;
	            fileOut << dataKTP[i].jenisKelamin << endl;
	            fileOut << dataKTP[i].golonganDarah << endl;
	            fileOut << dataKTP[i].alamat.dusun << endl;
	            fileOut << dataKTP[i].alamat.rt << endl;
	            fileOut << dataKTP[i].alamat.rw << endl;
	            fileOut << dataKTP[i].alamat.kelurahan << endl;
	            fileOut << dataKTP[i].alamat.kecamatan << endl;
	            fileOut << dataKTP[i].agama << endl;
	            fileOut << dataKTP[i].statusPerkawinan << endl;
	            fileOut << dataKTP[i].pekerjaan << endl;
	            fileOut << dataKTP[i].kewarganegaraan << endl;
	        }
	        fileOut.close();
	        cout << "Data berhasil disimpan ke file." << endl;
	    } else {
	        cout << "File tidak dapat dibuka." << endl;
	    }
	}
	
	// ALDRION WIJAYA ZR
	// 2300018162
	void masuk (){
		int jumlahData;

	    cout << "Masukkan jumlah data KTP: ";
	    cin >> jumlahData;
	    cin.ignore();
	
	    KTP dataKTP[jumlahData];
	    
	    for (int i = 0; i < jumlahData; i++) {
	        string nik, nama, golonganDarah, pekerjaan, agama;
	        TTL ttl;
	        Alamat alamat;
	        bool jenisKelamin, statusPerkawinan, kewarganegaraan;
	
	        cout << "Masukkan NIK: ";
	        getline(cin, nik);
	        cout << "Masukkan Nama: ";
	        getline(cin, nama);
	        cout << "Masukkan Tempat Lahir: ";
	        getline(cin, ttl.tempat);
	        cout << "Masukkan Tanggal Lahir (dd-mm-yyyy): ";
	        getline(cin, ttl.tanggal);
	        cout << "Masukkan Jenis Kelamin (1 = Laki-laki, 0 = Perempuan): ";
	        cin >> jenisKelamin;
	        cin.ignore();
	        cout << "Masukkan Golongan Darah: ";
	        getline(cin, golonganDarah);
	        cout << "Masukkan Alamat (Dusun): ";
	        getline(cin, alamat.dusun);
	        cout << "Masukkan RT: ";
	        getline(cin, alamat.rt);
	        cout << "Masukkan RW: ";
	        getline(cin, alamat.rw);
	        cout << "Masukkan Kelurahan: ";
	        getline(cin, alamat.kelurahan);
	        cout << "Masukkan Kecamatan: ";
	        getline(cin, alamat.kecamatan);
	        cout << "Masukkan Agama: ";
	        getline(cin, agama);
	        cout << "Masukkan Status Perkawinan (1 = Sudah menikah, 0 = Belum menikah): ";
	        cin >> statusPerkawinan;
	        cin.ignore();
	        cout << "Masukkan Pekerjaan: ";
	        getline(cin, pekerjaan);
	        cout << "Masukkan Kewarganegaraan (1 = WNI, 0 = WNA): ";
	        cin >> kewarganegaraan;
	        cin.ignore();
	
	        dataKTP[i] = KTP(nik, nama, ttl, jenisKelamin, golonganDarah, alamat, agama, statusPerkawinan, pekerjaan, kewarganegaraan);
	    }
	    cout << endl;
	
	    simpanKeFile(dataKTP, jumlahData);
	    bacaDariFile();

	}
};

int main() {
	KTP ktp;
    ktp.masuk(); // Menjalankan proses input
    cout << endl;
	cout << "MENAMPILKAN DATA KTP" << endl;
	cout << endl;
    ktp.bacaDariFile(); // Menampilkan data yang telah dimasukkan
	
    return 0;
}
