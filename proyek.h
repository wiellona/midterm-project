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
int string_search(char* finder, char* target);
//function prototype end

//function untuk system ("pause") dan system("cls")
void clear()
{
	printf("\n");
	system ("pause");
	system ("cls");
}

//function untuk menambah event
void buat_event (struct Event *event, int *jumlah_database)
{
	printf("Nama Event : ");
	scanf("%s", event->nama);
	printf("Tanggal (1-31): ");
	scanf("%d", &event->tanggal);
	printf("Bulan (1-12) : ");
	scanf("%d", &event->bulan);
	printf("Tahun : ");
	scanf("%d", &event->tahun);
	printf("Deskripsi : ");
	scanf("%s", event->deskripsi);
	printf("Tipe (Pribadi/Kelompok): ");
	scanf("%s", event->tipe);
	printf("Urgensi (Mendesak/Tidak mendesak): ");
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
	printf("Nama Event : %s\n", event->nama);
	printf("Tanggal : %2d-%2d-%4d\n", event->tanggal, event->bulan, event->tahun);
	printf("Deskripsi : %s\n", event->deskripsi);
	printf("Tipe : %s\n", event->tipe);
	printf("Urgensi : %s\n", event->urgensi);
}

//function untuk menyimpan event
void simpan_event(struct Event *event, int *jumlah_database, int *database, FILE *data)
{
	fprintf(data, "\nNama Event : %s\n", event->nama);
	fprintf(data, "Tanggal : %2d-%2d-%4d\n", event->tanggal, event->bulan, event->tahun);
	fprintf(data, "Deskripsi : %s\n", event->deskripsi);
	fprintf(data, "Tipe : %s\n", event->tipe);
	fprintf(data,"Urgensi : %s\n", event->urgensi);
}

void menu_sorting(int jumlah_database, struct Event *event)
{
	int opsi_menu;

	printf("\n\n-----------------------------------\n");
	printf("|    Menu Penyortiran    |\n");
	printf("-----------------------------------\n");
	printf("| Sortir data berdasarkan         |\n");
	printf("| 1. Nama Event                   |\n");
	printf("| 2. Waktu Event                  |\n");
	printf("| 3. Tipe Event                   |\n");
	printf("| 4. Tingkat urgensi              |\n");
	printf("| 5. Kembali ke menu utama        |\n");
	printf("-----------------------------------\n");
	printf("Masukkan angka 1-5\n");
	printf("> ");
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
			case 5 :
				return;
			default:
				printf("Input tidak valid. Silahkan masukkan bilangan 1-5\n");
				break;
		}
	} while(opsi_menu<1||5);
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

//Searching Function Start
//Menu searching
void menu_searching(int jumlah_database, struct Event *event)
{
	FILE *data;
	data = fopen("data proyek.txt", "w");
	int database, opsi_menu;

	printf("\n\n-----------------------------------\n");
	printf("|    Menu Pencarian    |\n");
	printf("-----------------------------------\n");
	printf("| Cari data berdasarkan           |\n");
	printf("| 1. Nama Event                   |\n");
	printf("| 2. Waktu Event                  |\n");
	printf("| 3. Tipe Event                   |\n");
	printf("| 4. Tingkat urgensi              |\n");
	printf("| 5. Kembali ke menu utama        |\n");
	printf("-----------------------------------\n");
	printf("Masukkan angka 1-5\n");
	printf("> ");
	scanf("%d", &opsi_menu);
	do
	{
		switch (opsi_menu)
		{
			case 1 :
				searching_nama_event(&event[database], &jumlah_database, data);
				break;
			case 2 :
				searching_waktu_event(&event[database], &jumlah_database, data);
				break;
			case 3 :
				searching_tipe_event(&event[database], &jumlah_database, data);
				break;
			case 4 :
				searching_urgensi_event(&event[database], &jumlah_database, data);
				break;
			case 5 :
				return;
			default:
				printf("Input tidak valid. Silahkan masukkan bilangan 1-5\n");
				break;
		}
	} while(opsi_menu<1||opsi_menu>5);
}

//funciton untuk mencari event berdasarkan nama
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
			pencarian++;
		}

		if (pencarian == 0) {
			printf("\nEvent tidak ditemukan.\n");
			clear();
		}
	}
}

//function searching berdasarkan tingkat urgensi
void searching_urgensi_event(struct Event *event, int *jumlah_database, FILE *data) {
	int counter, status_pencarian, pencarian = 0;
	char target[50];

	printf("Masukkan tingkat urgensi (Mendesak/Tidak mendesak): ");
	scanf("%s", target);

	// searching data di data proyek.txt
	for (counter = 0; counter < *jumlah_database; counter++) {
		fseek(data, counter * sizeof(struct Event), SEEK_SET);
		fread(&event[counter], sizeof(struct Event), 1, data);

		status_pencarian = string_search(target, event[counter].urgensi);

		if (status_pencarian == 0) {
			pencarian++;
		}

		if (pencarian == 0) {
			printf("\nEvent tidak ditemukan.\n");
			clear();
		}
	}
}

//function searching berdasarkan tipe event
void searching_tipe_event(struct Event *event, int *jumlah_database, FILE *data) {
	int counter, status_pencarian, pencarian = 0;
	char target_tipe[50];

	printf("Masukkan tipe event yang ingin dicari: (Pribadi/Kelompok)");
	scanf("%s", target_tipe);

	// searching data di data proyek.txt
	for (counter = 0; counter < *jumlah_database; counter++) {
		fseek(data, counter * sizeof(struct Event), SEEK_SET);
		fread(&event[counter], sizeof(struct Event), 1, data);

		status_pencarian = string_search(target_tipe, event[counter].tipe);

		if (status_pencarian == 0) {
			pencarian++;
		}

		if (pencarian == 0) {
			printf("\nTidak ditemukan event dengan tipe tersebut.\n");
			clear();
		}
	}
}

//Function searching berdasarkan waktu
void searching_waktu_event(struct Event *event, int *jumlah_database, FILE *data) {
	int counter, status_pencarian, pencarian = 0, pilihan;
	char target_tipe[50];

	do
	{
		printf("\nCari event berdasarkan: \n");
		printf("1. Bulan\n");
		printf("2. Tahun\n");
		printf("3. Kembali ke menu utama");
		printf("Masukkan pilihan Anda\n");
		printf("> ");
		scanf("%d", &pilihan);
		clear();
	} while (pilihan != 3);
	
	if (pilihan == 1) {
		int bulan;
		char namaBulan[20];
		printf("Masukkan bulan: ");
		if (fgets(namaBulan, sizeof(namaBulan), stdin) != NULL) {
			if (sscanf(namaBulan, "%d", &bulan) == 1) {
				//Jika input berupa int
				if (bulan >= 1 && bulan <= 12) {
					for (counter = 0; counter < *jumlah_database; counter++) {
						fseek(data, counter * sizeof(struct Event), SEEK_SET);
						fread(&event[counter], sizeof(struct Event), 1, data);

						if (event[counter].bulan == bulan) {
                            pencarian++;
                            lihat_event(&event[counter], jumlah_database, &counter, data);
                        }

						if (pencarian == 0) {
                        printf("\nTidak ada event dalam bulan ini.\n");
                    	}
					}
				} else {
					printf("Input tidak valid. Silahkan masukkan angka 1-12 atau nama bulan.\n");
				} 
			} else {
				//Jika input berupa string
				if(strcasecmp(namaBulan, "Januari") == 0) {
						bulan = 1;
					} else if(strcasecmp(namaBulan, "Februari") == 0) {
						bulan = 2;
					} else if(strcasecmp(namaBulan, "Maret") == 0) {
						bulan = 3;
					} else if(strcasecmp(namaBulan, "April") == 0) {
						bulan = 4;
					} else if(strcasecmp(namaBulan, "Mei") == 0) {
						bulan = 5;
					} else if(strcasecmp(namaBulan, "Juni") == 0) {
						bulan = 6;
					} else if(strcasecmp(namaBulan, "Juli") == 0) {
						bulan = 7;
					} else if(strcasecmp(namaBulan, "Agustus") == 0) {
						bulan = 8;
					} else if(strcasecmp(namaBulan, "September") == 0) {
						bulan = 9;
					} else if(strcasecmp(namaBulan, "Oktober") == 0) {
						bulan = 10;
					} else if(strcasecmp(namaBulan, "November") == 0) {
						bulan = 11;
					} else if(strcasecmp(namaBulan, "Desember") == 0) {
						bulan = 12;
					}
				
			}
			if (bulan >= 1 && bulan <= 12) {
					for (counter = 0; counter < *jumlah_database; counter++) {
						fseek(data, counter * sizeof(struct Event), SEEK_SET);
						fread(&event[counter], sizeof(struct Event), 1, data);

						if (event[counter].bulan == bulan) {
                            pencarian++;
                            lihat_event(&event[counter], jumlah_database, &counter, data);
                        }

						if (pencarian == 0) {
                        printf("\nTidak ada event dalam bulan ini.\n");
                    	}
					}
			}
		}
	}
}
//Searching Function End

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