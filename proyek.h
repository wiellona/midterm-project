#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Event{
	char nama[50], deskripsi[300], tipe[20], urgensi[20];
	int tanggal, bulan, tahun;
};

//function prototype start
void sorting_nama(int jumlah_database, struct Event *event);
void sorting_waktu(int jumlah_database, struct Event *event);
void sorting_tipe(int jumlah_database, struct Event *event);
void sorting_urgensi(int jumlah_database, struct Event *event);
void swap(int urutan1, int urutan2, struct Event *event);
//function prototype end

//function untuk system ("pause") dan system("cls")
void clear()
{
	system ("pause");
	system ("cls");
}

//function untuk menambah event
void buat_event (struct Event *event, int *jumlah_database)
{
	printf("Nama Event : ");
	scanf("%s", event->nama);
	printf("Tanggal : ");
	scanf("%d", &event->tanggal);
	printf("Bulan : ");
	scanf("%d", &event->bulan);
	printf("Tahun : ");
	scanf("%d", &event->tahun);
	printf("deskripsi : ");
	scanf("%s", event->deskripsi);
	printf("tipe : ");
	scanf("%s", event->tipe);
	printf("urgensi : ");
	scanf("%s", event->urgensi);
	(*jumlah_database)++;
}

//function untuk melihat event
void lihat_event(struct Event *event, int *jumlah_database, int *database, FILE *data)
{
	printf("%d. %s\n", *database+1, event->nama);
}

void detail_event(struct Event *event)
{
	printf("nama Event : %s\n", event->nama);
	printf("Tanggal : %2d-%2d-%4d\n", event->tanggal, event->bulan, event->tahun);
	printf("deskripsi : %s\n", event->deskripsi);
	printf("tipe : %s\n", event->tipe);
	printf("urgensi : %s\n", event->urgensi);
}

//function untuk menyimpan event
void simpan_event(struct Event *event, int *jumlah_database, int *database, FILE *data)
{
	fprintf(data, "nama Event : %s\n", event->nama);
	fprintf(data, "Tanggal : %2d-%2d-%4d\n", event->tanggal, event->bulan, event->tahun);
	fprintf(data, "deskripsi : %s\n", event->deskripsi);
	fprintf(data, "tipe : %s\n", event->tipe);
	fprintf(data,"urgensi : %s\n", event->urgensi);
}

void menu_sorting(int jumlah_database, struct Event *event)
{
	int opsi_menu;
	printf("1. Sorting nama\n2. Sorting waktu\n3. Sorting tipe\n4. Sorting urgensi\nmasukkan pilihan anda (1-4) : ");
	scanf("%d", &opsi_menu);
	do
	{
	switch (opsi_menu)
	{
		case 1 :
			sorting_nama(jumlah_database, event);
			break;
		case 2 :
			sorting_waktu(jumlah_database, event);
			break;
		case 3 :
			sorting_tipe(jumlah_database, event);
			break;
		case 4 :
			sorting_urgensi(jumlah_database, event);
			break;
		default:
            printf("Input tidak valid. Silahkan masukkan bilangan 1-4\n");
	}
	}while(opsi_menu<1||opsi_menu>4);
}

void sorting_nama(int jumlah_database, struct Event *event)
{
  int urutan, sorting, pilihan_urutan, tampung_urutan;
  float tampung_nilai;
  //Menu untuk menentukan apakah nama akan diurutkan ascending atau descending
        printf("\n1. Ascending (A - Z) \n2. Descending (Z - A)\nMasukkan pilihan Anda: ");
        scanf("%d", &pilihan_urutan);

        int i, j;
          switch (pilihan_urutan)
          {
          case 1:
            for (sorting = 0; sorting < jumlah_database - 1; sorting++) {
              for(urutan = 0; urutan < jumlah_database - 1; urutan++) {
                if(strcmp(event[urutan].nama, event[urutan+1].nama) > 0 ){
                	swap(urutan , urutan + 1, event);
                }
              }
            }
            break;
          case 2:
            for (sorting = 0; sorting < jumlah_database - 1; sorting++) {
              for(urutan = 0; urutan < jumlah_database - 1; urutan++) {
                if(strcmp(event[urutan].nama, event[urutan+1].nama) < 0 ){
                	swap(urutan , urutan + 1, event);
                }
              }
            }
            break;
          default:
            printf("Input tidak valid. Silahkan masukkan bilangan 1-2\n");
          }
}

void sorting_waktu(int jumlah_database, struct Event *event)
{
  int urutan, sorting, pilihan_urutan, tampung_urutan;
  float tampung_nilai;
  //Menu untuk menentukan apakah nama akan diurutkan ascending atau descending
        printf("\n1. Waktu terdekat \n2. Waktu terjauh\nMasukkan pilihan Anda: ");
        scanf("%d", &pilihan_urutan);

        int i, j;
          switch (pilihan_urutan)
          {
          case 1:
            for (sorting = 0; sorting < jumlah_database - 1; sorting++) {
              for(urutan = 0; urutan < jumlah_database - 1; urutan++) {
                if(event[urutan].tahun > event[urutan+1].tahun){
                	if(event[urutan].bulan > event[urutan+1].bulan){
                		if(event[urutan].tanggal > event[urutan+1].tanggal){
                			swap(urutan , urutan + 1, event);
                		}
                	}
                }
              }
            }
            break;
          case 2:
            for (sorting = 0; sorting < jumlah_database - 1; sorting++) {
              for(urutan = 0; urutan < jumlah_database - 1; urutan++) {
                if(event[urutan].tahun < event[urutan+1].tahun){
                	if(event[urutan].bulan < event[urutan+1].bulan){
                		if(event[urutan].tanggal < event[urutan+1].tanggal){
                			swap(urutan , urutan + 1, event);
                		}
                	}
                }
              }
            }
            break;
          default:
            printf("Input tidak valid. Silahkan masukkan bilangan 1-2\n");
          }
}

void sorting_tipe(int jumlah_database, struct Event *event)
{
  int urutan, sorting, pilihan_urutan, tampung_urutan;
  float tampung_nilai;
  //Menu untuk menentukan apakah nama akan diurutkan ascending atau descending
        printf("\n1. Ascending (A - Z) \n2. Descending (Z - A)\nMasukkan pilihan Anda: ");
        scanf("%d", &pilihan_urutan);

        int i, j;
          switch (pilihan_urutan)
          {
          case 1:
            for (sorting = 0; sorting < jumlah_database - 1; sorting++) {
              for(urutan = 0; urutan < jumlah_database - 1; urutan++) {
                if(strcmp(event[urutan].tipe, event[urutan+1].tipe) > 0 ){
                	swap(urutan , urutan + 1, event);
                }
              }
            }
            break;
          case 2:
            for (sorting = 0; sorting < jumlah_database - 1; sorting++) {
              for(urutan = 0; urutan < jumlah_database - 1; urutan++) {
                if(strcmp(event[urutan].tipe, event[urutan+1].tipe) < 0 ){
                	swap(urutan , urutan + 1, event);
                }
              }
            }
            break;
          default:
            printf("Input tidak valid. Silahkan masukkan bilangan 1-2\n");
          }
}

void sorting_urgensi(int jumlah_database, struct Event *event)
{
  int urutan, sorting, pilihan_urutan, tampung_urutan;
  float tampung_nilai;
  //Menu untuk menentukan apakah nama akan diurutkan ascending atau descending
        printf("\n1. Ascending (A - Z) \n2. Descending (Z - A)\nMasukkan pilihan Anda: ");
        scanf("%d", &pilihan_urutan);

        int i, j;
          switch (pilihan_urutan)
          {
          case 1:
            for (sorting = 0; sorting < jumlah_database - 1; sorting++) {
              for(urutan = 0; urutan < jumlah_database - 1; urutan++) {
                if(strcmp(event[urutan].urgensi, event[urutan+1].urgensi) > 0 ){
                	swap(urutan , urutan + 1, event);
                }
              }
            }
            break;
          case 2:
            for (sorting = 0; sorting < jumlah_database - 1; sorting++) {
              for(urutan = 0; urutan < jumlah_database - 1; urutan++) {
                if(strcmp(event[urutan].urgensi, event[urutan+1].urgensi) < 0 ){
                	swap(urutan , urutan + 1, event);
                }
              }
            }
            break;
          default:
            printf("Input tidak valid. Silahkan masukkan bilangan 1-2\n");
          }
}

void swap(int urutan1, int urutan2, struct Event *event)
{
	int tampung_nilai;
	char temp[300]; // variabel sementara untuk mengambil string dari user
	
	strcpy(temp, event[urutan1].nama);
    strcpy(event[urutan1].nama, event[urutan2].nama);
	strcpy(event[urutan2].nama, temp);
    
    strcpy(temp, event[urutan1].deskripsi);
    strcpy(event[urutan1].deskripsi, event[urutan2].deskripsi);
	strcpy(event[urutan2].deskripsi, temp);
	
	strcpy(temp, event[urutan1].tipe);
    strcpy(event[urutan1].tipe, event[urutan2].tipe);
	strcpy(event[urutan2].tipe, temp);
    
    strcpy(temp, event[urutan1].urgensi);
    strcpy(event[urutan1].urgensi, event[urutan2].urgensi);
	strcpy(event[urutan2].urgensi, temp);
    
    tampung_nilai = event[urutan1].tanggal;
    event[urutan1].tanggal = event[urutan2].tanggal;
    event[urutan2].tanggal = tampung_nilai;
    
    tampung_nilai = event[urutan1].bulan;
    event[urutan1].bulan = event[urutan2].bulan;
    event[urutan2].bulan = tampung_nilai;
    
    tampung_nilai = event[urutan1].tahun;
    event[urutan1].tahun = event[urutan2].tahun;
    event[urutan2].tahun = tampung_nilai;
}

void searching_nama_event(struct Event *event, int *jumlah_database, FILE *data) {
	int counter, status_pencarian, pencarian = 0;
	char target_name[50];

	printf("Masukkan nama event yang ingin dicari: ");
	scanf("%s", target_name);

	// searching data di data proyek.txt
	for (counter = 0; counter < *jumlah_database; counter++) {
		fseek(data, counter * sizeof(struct Event), SEEK_SET);
		fread(&event[counter], sizeof(struct Event), 1, data);

		status_pencarian = string_search(target_name, event[counter].nama);

		if (status_pencarian == 0) {
			// lihat_event(&event[pencarian], jumlah_database, &pencarian, data);
			pencarian++;
		}

		if (pencarian == 0) {
			printf("\nEvent tidak ditemukan.\n");
			clear();
		}
	}
}

// Function untuk un case sensitive
int string_search(char* finder, char* target)
{
	while (*finder != '\0' || *target != '\0') {
	    if ((*finder == *target) || (*finder - *target == 32) || (*finder - *finder == -32)) {
	    	finder++;
	        target++;
	    } else if(*finder == '\0' && *target != '\0')
	    {
	    	return 0;
		} else {
			return 1;
		}
	}
	return 0;
}
