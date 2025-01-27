#include <iostream>
#include <vector>
using namespace std;

struct Menu {
    string nama_menu;
    float harga;
};

struct Item_pembelian {
    string nama_menu;
    int qty;
};

struct Data_pemebelian {
    int id_customer;
    string nama_customer;
    vector<Item_pembelian> items;
};

int main() {
    vector<Menu> menu_resto;
    vector<Data_pemebelian> data_beli;

    Menu menu01, menu02, menu03;
    menu01.nama_menu = "NasiGoreng";
    menu01.harga = 10000;
    menu_resto.push_back(menu01);

    menu02.nama_menu = "SateAyam";
    menu02.harga = 15000;
    menu_resto.push_back(menu02);

    menu03.nama_menu = "Salad";
    menu03.harga = 13000;
    menu_resto.push_back(menu03);

    bool lanjut = true;
    int pilihan;
    Menu tmpmenu;
    Data_pemebelian tmpbeli;
    bool lanjut_tambah_beli;
    Item_pembelian tmpitem;
    string is_lanjut_tambah_beli;
    float tmpharga;
    float total;
    string nama_menu;
    float harga_baru;
    int id_customer;

    while (lanjut) {
        cout << "Menu aplikasi" << endl;
        cout << "1. Tambah menu baru" << endl;
        cout << "2. Tampilkan menu" << endl;
        cout << "3. Tambah pembelian" << endl;
        cout << "4. Tampilkan pembelian" << endl;
        cout << "5. Edit harga menu" << endl;
        cout << "6. Tambah item pada pembelian" << endl;
        cout << "7. Exit" << endl;

        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 7) {
            lanjut = false;
        } else if (pilihan == 1) {
            cout << "Masukkan nama menu: ";
            cin >> tmpmenu.nama_menu;
            bool harga_menu = true;
            while (harga_menu) {
                cout << "Masukkan harga menu: ";
                cin >> tmpmenu.harga;
                if (tmpmenu.harga > 0) {
                     harga_menu = false;
                } else {
                    cout << "Harga harus lebih besar dari 0!" << endl;
                }   
            }
                menu_resto.push_back(tmpmenu);
                cout << "Menu berhasil ditambahkan!" << endl;

        }else if (pilihan == 2) {
            cout << "-------------------------------" << endl;
            cout << "Daftar Menu Restoran" << endl;
            cout << "-------------------------------" << endl;
            for (Menu m : menu_resto) {
                cout << "Menu: " << m.nama_menu << endl;
                cout << "Harga: " << m.harga << endl;
                cout << "------------------------------------" << endl;
            }

        } else if (pilihan == 3) {
            cout << "ID Customer: ";
            cin >> tmpbeli.id_customer;
            cout << "Nama Customer: ";
            cin >> tmpbeli.nama_customer;

            lanjut_tambah_beli = true;
            while (lanjut_tambah_beli) {
                cout << "Menu yang dibeli: ";
                cin >> tmpitem.nama_menu;
                bool valid_qty = true;
                while (valid_qty) {
                    cout << "Qty: ";
                    cin >> tmpitem.qty;
                    if (tmpitem.qty > 0) {
                        valid_qty = false;
                    } else {
                        cout << "Masukkan kauntitas yang valid!" << endl;
                    }
                }

                tmpbeli.items.push_back(tmpitem);

                cout << "Sudah? (y/n): ";
                cin >> is_lanjut_tambah_beli;
                if (is_lanjut_tambah_beli == "y") {
                    lanjut_tambah_beli = false;
                    data_beli.push_back(tmpbeli);
                    tmpbeli.items.clear();
                }
            }

        } else if (pilihan == 4) {
            for (Data_pemebelian dp : data_beli) {
                cout << "-------------------------------------" << endl;
                cout << "ID Customer: " << dp.id_customer << endl;
                cout << "Nama Customer: " << dp.nama_customer << endl;
                cout << "Item yang dibeli: " << endl;
                total = 0;
                for (Item_pembelian ip : dp.items) {
                    cout << " - " << ip.nama_menu << ", qty: " << ip.qty;
                    tmpharga = 0;
                    for (Menu m : menu_resto) {
                        if (m.nama_menu == ip.nama_menu) {
                            tmpharga = m.harga;
                            break;
                        }
                    }
                    if (tmpharga > 0) {
                        cout << ", harga: " << tmpharga;
                        total += ip.qty * tmpharga;
                    } else {
                        cout << " - (menu tidak ditemukan)";
                    }
                    cout << endl;
                }
                cout << "Total Harga: " << total << endl;
                cout << "-------------------------------------" << endl;
            }

        } if (pilihan == 5) {
            bool ditemukan = false;
            while (ditemukan == false) {
                cout << "Menu yang ingin diedit: ";
                cin >> nama_menu;

            for (int i = 0; i < menu_resto.size(); i++) {
                if (menu_resto[i].nama_menu == nama_menu) {
                    cout << "Harga lama: " << menu_resto[i].harga << endl;
                    cout << "Masukkan harga baru: ";
                    cin >> harga_baru;

                while (harga_baru <= 0) {
                    cout << "Harga baru harus lebih besar dari 0!" << endl;
                    cout << "Masukkan harga baru: ";
                    cin >> harga_baru;
                }

                    menu_resto[i].harga = harga_baru;
                    cout << "Harga menu berhasil diperbarui!" << endl;
                    ditemukan = true;
                    break;
                }
            }

                if (ditemukan == false) {
                cout << "Menu tidak ditemukan, silakan coba lagi!" << endl;
                }
            }
        } else if (pilihan == 6) {
            cout << "Masukkan ID customer: ";
            cin >> id_customer;

            bool pembelian_ditemukan = false;

            for (int i = 0; i < data_beli.size(); i++) {
                if (data_beli[i].id_customer == id_customer) {
                    pembelian_ditemukan = true;

                bool lanjut_tambah_beli = true;
                while (lanjut_tambah_beli == true) {
                    cout << "Menu yang ingin ditambahkan: ";
                    cin >> tmpitem.nama_menu;

                bool menu_valid = false;
                for (int j = 0; j < menu_resto.size(); j++) {
                    if (menu_resto[j].nama_menu == tmpitem.nama_menu) {
                        menu_valid = true;
                        break;
                    }
                }

                if (menu_valid == false) {
                    cout << "Menu tidak ditemukan di restoran. Silakan coba lagi!" << endl;
                    continue;
                }

                bool valid_qty = false;
                while (valid_qty == false) {
                    cout << "Qty: ";
                    cin >> tmpitem.qty;
                    if (tmpitem.qty > 0) {
                        valid_qty = true;
                    } else {
                        cout << "Masukkan kuantitas yang valid!" << endl;
                    }
                }

                    data_beli[i].items.push_back(tmpitem);
                    cout << "Item berhasil ditambahkan!" << endl;

                    cout << "Tambah item lagi? (y/n): ";
                    cin >> is_lanjut_tambah_beli;
                    if (is_lanjut_tambah_beli == "n") {
                        lanjut_tambah_beli = false;
                    }
                }
                break;
                }
            }

            if (pembelian_ditemukan == false) {
                cout << "Data pembelian dengan ID customer ini tidak ditemukan!" << endl;
            }
        }
    }
    return 0;
}