#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mahasiswa.h"

int sort_by_ipk(const void *a, const void *b) {
  const Mahasiswa *x = a;
  const Mahasiswa *y = b;
  return (x->ipk < y->ipk) - (x->ipk > y->ipk); // menghasilkan nilai -1
}

int sort_by_name(const void *a, const void *b) {
  const Mahasiswa *x = a;
  const Mahasiswa *y = b;
  return strcmp(x->name, y->name);
}

int sort_by_umur(const void *a, const void *b) {
  const Mahasiswa *x = a;
  const Mahasiswa *y = b;
  return (x->umur < y->umur) - (x->umur > y->umur); // menghasilkan nilai -1
}

Mahasiswa *buat_array_mahasiswa(int jlh_mahasiswa) {
  return malloc( jlh_mahasiswa * sizeof(Mahasiswa));

}

void cetak_data_mahasiswa(Mahasiswa *mhs, int jlh_mahasiswa, char *nama_kampus) {
  printf("========================== Data Mahasiswa %s ============================\n", nama_kampus);
  for (int i=0;i < jlh_mahasiswa; i++) {
    printf("%d. %s \t%s     \t%d Tahun  \t%.2f\n", i+1, mhs[i].name, mhs[i].jurusan, mhs[i].umur, mhs[i].ipk);
  }
  printf("==========================================================================\n\n");
}
void input_data_mahasiswa(Mahasiswa *mhs, int jlh_mahasiswa) {
  for (int i=0; i<jlh_mahasiswa; i++) {
    printf("\nInput Data Mahasiswa ke - %d\n", i+1);
    printf("Nama: ");
    scanf(" %[^\n]s", mhs[i].name);
    printf("Jurusan: ");
    scanf(" %[^\n]s", mhs[i].jurusan);
    printf("Umur: ");
    scanf("%d", &mhs[i].umur);
    printf("Nilai IPK: ");
    scanf("%f", &mhs[i].ipk);
  }
  system("clear");
}

void cetak_data_by_indeks(Mahasiswa *mhs, int indeks) {
  printf("Data indeks ke - %d sekarang!\n", indeks);
  printf(" Nama\t\t: %s\n", mhs[indeks].name);
  printf(" Jurusan\t: %s\n", mhs[indeks].jurusan);
  printf(" Umur\t\t: %d\n", mhs[indeks].umur);
  printf(" Nilai IPK\t: %.2f\n", mhs[indeks].ipk);
}

void update_data_mahasiswa(Mahasiswa *mhs, void (*cetak_data)(Mahasiswa *, int)) {
  int indeks;
  char pilih;
  printf("\nPilih Indeks Data: ");
  scanf("%d", &indeks);
  cetak_data(mhs, indeks);
  printf("Ubah (y/n): ");
  scanf(" %c", &pilih);
  if (pilih == 'Y' || pilih == 'y') {
    printf("\nUbah Data - [%s]\n",mhs[indeks].name);
    printf("Nama: ");
    scanf(" %[^\n]s", mhs[indeks].name);
    printf("Jurusan: ");
    scanf(" %[^\n]s", mhs[indeks].jurusan);
    printf("Umur: ");
    scanf("%d", &mhs[indeks].umur);
    printf("Nilai IPK: ");
    scanf("%f", &mhs[indeks].ipk);
  } 
  system("clear");
}


void data_kosong(char *nama_kampus) {
  printf("\n========================== Data Mahasiswa %s ============================\n", nama_kampus);
  printf("                            Tidak ada data!\n");
  printf("==========================================================================\n\n");
}
void error_msg(int kode_error) {
  if (kode_error == 1) {
    printf("Password Anda salah!\n");
  } else if (kode_error == 2) {
    printf("Username Anda salah!\n");
  } else {
    printf("");
  }
}

void tambah_data_mahasiswa(Mahasiswa *mh, int *jlh_mahasiswa) {
  int size_data;
  printf("Tambah Data: ");
  scanf("%d", &size_data);
  Mahasiswa *tmp = realloc(mh, (*jlh_mahasiswa * 3) * sizeof(Mahasiswa));
  if (tmp != NULL) {
    mh = tmp;
    *jlh_mahasiswa += size_data;
  }
  int indeks = *jlh_mahasiswa - size_data;
  for (int i=indeks; i < *jlh_mahasiswa; i++) {
    printf("\nInput Data Mahasiswa ke - %d\n", indeks++);
    printf("Nama: ");
    scanf(" %[^\n]s", mh[i].name);
    printf("Jurusan: ");
    scanf(" %[^\n]s", mh[i].jurusan);
    printf("Umur: ");
    scanf("%d", &mh[i].umur);
    printf("Nilai IPK: ");
    scanf("%f", &mh[i].ipk);
  }
}


