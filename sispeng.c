#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mahasiswa.h"

int main(void) {

  char nama_kampus[48];
  static int jlh_mahasiswa = 0;
  int menu;
  int pilih;
  bool session_login = true;
  bool status = false;
  bool update_kampus = false;
  char user[48], pass[48];
  int kode_error = 0;

  char *name = malloc(50 * sizeof(char));
  if (name == NULL) {
    fprintf(stderr, "hey, alokasi memori untuk nama gagal!\n");
    return 1;
  }

  printf("Masukkan Nama Anda: ");
  scanf(" %49[^\n]s", name);
  system("clear");
  Mahasiswa *mh = buat_array_mahasiswa(jlh_mahasiswa);
  while (session_login) {
    printf("Selamat Datang %s\n", name);
    puts("Silahkan login untuk menggunakan program ini!");
    error_msg(kode_error);
    printf("Username: ");
    scanf(" %[^\n]s", user);
    printf("Password: ");
    scanf(" %[^\n]s", pass);
    if (strcmp(user, USER) == 0) {
      if (strcmp(pass, PASS) == 0) {
        session_login = false;
        status = true;
        update_kampus = true;
        system("clear");
      } else {
        kode_error = 1;
        system("clear");
      }
    } else {
      kode_error = 2;
      system("clear");
    }

    while (update_kampus) {
      if (strcmp(nama_kampus, "") == 0 && jlh_mahasiswa == 0) {
        printf("Nama Universitas: ");
        scanf(" %[^\n]s", nama_kampus);
        printf("Masukkan Jumlah Mahasiswa: ");
        scanf("%d", &jlh_mahasiswa);
        status = true;
        update_kampus = false;
      }
      system("clear");
      puts("=================================================================");  
      puts("=============== SISTEM PENGELOLAAN DATA MAHASISWA ===============");
      puts("=================================================================");  
   
      while (status) {
        puts("Silahkan pilih menu dibawah ini!");
        puts(" 1. Menampilkan Data Mahasiswa");
        puts(" 2. Menginput Data Awal");
        puts(" 3. Ubah Data Universitas");
        puts(" 4. Logout");
        puts(" 0. Close Program");
        printf("Pilih menu: ");
        scanf("%d", &menu);
        if (menu == 1) {
          if (mh[0].ipk == 0) {
            data_kosong(nama_kampus);
          } else {
            cetak_data_mahasiswa(mh, jlh_mahasiswa, nama_kampus);
            do {
              printf("Edit - 1.Add  | 2.Update\n"); 
              printf("Sort - 3.Name | 4.Ipk | 5.Umur | 0.Exit\nCommand: ");
              scanf("%d", &pilih);
              if (pilih == 1) {
                tambah_data_mahasiswa(mh, &jlh_mahasiswa);
              } else if (pilih == 2) {
                update_data_mahasiswa(mh, cetak_data_by_indeks);
              } else if (pilih == 3) {
                printf("\nSort by name: \n");
                qsort(mh, jlh_mahasiswa, sizeof(Mahasiswa), sort_by_name);
                cetak_data_mahasiswa(mh, jlh_mahasiswa, nama_kampus);
              } else if (pilih == 4) {
                printf("\nSort by ipk: \n");
                qsort(mh, jlh_mahasiswa, sizeof(Mahasiswa), sort_by_ipk);
                cetak_data_mahasiswa(mh, jlh_mahasiswa, nama_kampus);
              } else if (pilih == 5) {
                printf("\nSort by umur: \n");
                qsort(mh, jlh_mahasiswa, sizeof(Mahasiswa), sort_by_umur);
                cetak_data_mahasiswa(mh, jlh_mahasiswa, nama_kampus);
              } else {
                pilih = 0;
                system("clear");
              } 
            } while(pilih != 0);
          }
          
        } else if (menu == 2) {
          input_data_mahasiswa(mh, jlh_mahasiswa);
        } else if (menu == 3) {
          status = false;
          update_kampus = true;
          strcpy(nama_kampus, "");
          jlh_mahasiswa = 0;
          system("clear");
        } else if (menu == 4) {
          system("clear");
          status = false;
          session_login = true;
          kode_error = 0;
        } else {
          char exit;
          printf("Apakah Anda ingin keluar?(y/n): ");
          scanf(" %c", &exit);
          if (exit == 'y' || exit == 'Y') {
            status = false;
            session_login = false;
            update_kampus = false;
            kode_error = 0;
            system("clear");
          } else {
            status = true;
            system("clear");
          }
        }
      }
    }
  }
  free(name);
  free(mh);
  name = NULL;
  mh = NULL;
  return 0;
}
