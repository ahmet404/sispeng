#ifndef MAHASISWA_H
#define MAHASISWA_H

typedef struct {
  char name[48];
  char jurusan[32];
  int umur;
  float ipk;
  int no_mhs;
} Mahasiswa;

int sort_by_ipk(const void *a, const void *b);
int sort_by_name(const void *a, const void *b);
int sort_by_umur(const void *a, const void *b);
Mahasiswa *buat_array_mahasiswa(int jlh_mahasiswa); 
void cetak_data_mahasiswa(Mahasiswa *mhs, int jlh_mahasiswa, char *nama_kampus);
void input_data_mahasiswa(Mahasiswa *mhs, int jlh_mahasiswa); 

void cetak_data_by_indeks(Mahasiswa *mhs, int indeks);

void update_data_mahasiswa(Mahasiswa *mhs, void (*cetak_data)(Mahasiswa *, int));

void data_kosong(char *nama_kampus);
void error_msg(int kode_error);

void tambah_data_mahasiswa(Mahasiswa *mh, int *jlh_mahasiswa);

#endif
