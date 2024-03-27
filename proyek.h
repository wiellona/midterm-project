#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Event{
	char nama[50], deskripsi[300], tipe[20], urgensi[20];
	int tanggal, bulan, tahun;
};

//function prototype
void clear();
void buat_event (struct Event *event, int *jumlah_database);
void lihat_event(struct Event *event, int *database);
void detail_event(struct Event *event);
void simpan_event(struct Event *event, int jumlah_database, int database, FILE *data);
void menu_searching(int jumlah_database, struct Event *event);
void menu_sorting(int jumlah_database, struct Event *event);
void sorting_nama(int jumlah_database, struct Event *event);
void sorting_waktu(int jumlah_database, struct Event *event);
void sorting_tipe(int jumlah_database, struct Event *event);
void sorting_urgensi(int jumlah_database, struct Event *event);
void swap(int urutan1, int urutan2, struct Event *event);
void searching_nama(int jumlah_database, struct Event *event);
void searching_waktu(int jumlah_database, struct Event *event);
void searching_tipe(int jumlah_database, struct Event *event);
void searching_urgensi(int jumlah_database, struct Event *event);
int string_search(char* finder, char* target);
int hapus_event(int jumlah_database, struct Event *event, int opsi);

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
	scanf(" %[^\n]s", event->nama);
	printf("Tanggal (1-31): ");
	scanf("%d", &event->tanggal);
	printf("Bulan (1-12) : ");
	scanf("%d", &event->bulan);
	printf("Tahun : ");
	scanf("%d", &event->tahun);
	printf("Deskripsi : ");
	scanf(" %[^\n]s", event->deskripsi);
	printf("Tipe (Pribadi/Kelompok) : ");
	scanf(" %[^\n]s", event->tipe);
	printf("Urgensi (Mendesak/Tidak mendesak) : ");
	scanf(" %[^\n]s", event->urgensi);
	(*jumlah_database)++;
	printf("\nEvent berhasil ditambahkan.\n");
}

//function untuk melihat event
void lihat_event(struct Event *event, int *database)
{
	printf("%d. %s\n", *database+1, event->nama);
}

//function untuk menampilkan detail event yang dipilih
void detail_event(struct Event *event)
{
	printf("Nama Event : %s\n", event->nama);
	printf("Tanggal : %2d-%2d-%4d\n", event->tanggal, event->bulan, event->tahun);
	printf("Deskripsi : %s\n", event->deskripsi);
	printf("Tipe : %s\n", event->tipe);
	printf("Urgensi : %s\n", event->urgensi);
}

//function untuk menyimpan event
void simpan_event(struct Event *event, int jumlah_database, int database, FILE *data)
{
	data = fopen("data proyek.txt", "w");
	fprintf(data, "%d\n", jumlah_database);
	for (database=0; database < jumlah_database; database++ )
	fprintf(data, "\n%s\n%d\n%d\n%d\n%s\n%s\n%s\n", event[database].nama, event[database].tanggal, event[database].bulan, event[database].tahun, event[database].deskripsi, event[database].tipe, event[database].urgensi);
	fclose(data);
}

//function untuk menampilkan menu searching
void menu_searching(int jumlah_database, struct Event *event)
{
	int opsi_menu;
	printf("\n\n-----------------------------------\n");
	printf("|          Menu Pencarian         |\n");
	printf("-----------------------------------\n");
	printf("| Cari data berdasarkan           |\n");
	printf("| 1. Nama Event                   |\n");
	printf("| 2. Waktu Event                  |\n");
	printf("| 3. Tipe Event                   |\n");
	printf("| 4. Tingkat urgensi              |\n");
	printf("-----------------------------------\n");
	printf("Masukkan pilihan Anda (1-4)\n");
	printf("> ");
	scanf("%d", &opsi_menu);
	do
	{
		switch (opsi_menu)
		{
			case 1 :
				searching_nama(jumlah_database, event);
				break;
			case 2 :
				searching_waktu(jumlah_database, event);
				break;
			case 3 :
				searching_tipe(jumlah_database, event);
				break;
			case 4 :
				searching_urgensi(jumlah_database, event);
				break;
			default:
				printf("Input tidak valid. Silahkan masukkan bilangan 1-4\n");
		}
	} while(opsi_menu<1||opsi_menu>4);
}

//function untuk menampilkan menu sorting
void menu_sorting(int jumlah_database, struct Event *event)
{
	int opsi_menu;
	printf("\n\n-----------------------------------\n");
	printf("|         Menu Penyortiran        |\n");
	printf("-----------------------------------\n");
	printf("| Sortir data berdasarkan         |\n");
	printf("| 1. Nama Event                   |\n");
	printf("| 2. Waktu Event                  |\n");
	printf("| 3. Tipe Event                   |\n");
	printf("| 4. Tingkat urgensi              |\n");
	printf("-----------------------------------\n");
	printf("Masukkan pilihan Anda (1-4)\n");
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
			default:
				printf("Input tidak valid. Silahkan masukkan bilangan 1-4\n");
		}
	} while(opsi_menu < 1 || opsi_menu > 4);
}

//function untuk melakukan sorting nama
void sorting_nama(int jumlah_database, struct Event *event)
{
  int urutan, sorting, pilihan_urutan, tampung_urutan;
  float tampung_nilai;
  //Menu untuk menentukan apakah nama akan diurutkan ascending atau descending
		printf("\nBerikut adalah menu penyortiran untuk mengurutkan event berdasarkan nama.\n");
        printf("\n1. Ascending (A - Z) \n2. Descending (Z - A)\nMasukkan pilihan Anda (1-2)\n> ");
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

//function untuk melakukan sorting waktu
void sorting_waktu(int jumlah_database, struct Event *event)
{
  int urutan, sorting, pilihan_urutan, tampung_urutan;
  float tampung_nilai;
  //Menu untuk menentukan apakah waktu akan diurutkan ascending atau descending
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

//function untuk melakukan sorting tipe
void sorting_tipe(int jumlah_database, struct Event *event)
{
  int urutan, sorting, pilihan_urutan, tampung_urutan;
  float tampung_nilai;
  //Menu untuk menentukan apakah tipe akan diurutkan ascending atau descending
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

//function untuk melakukan sorting urgensi
void sorting_urgensi(int jumlah_database, struct Event *event)
{
  int urutan, sorting, pilihan_urutan, tampung_urutan;
  float tampung_nilai;
  //Menu untuk menentukan apakah urgensi akan diurutkan ascending atau descending
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

//function untuk melakukan swap event
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

//function untuk melakukan searching nama
void searching_nama(int jumlah_database, struct Event *event) {
	int counter, status_pencarian, pencarian = 0;
	char target_name[50];

	printf("Masukkan nama event yang ingin dicari: ");
	scanf(" %[^\n]s", target_name);
	printf("Hasil pencarian\n");

	// searching data di struct event
	for (counter = 0; counter < jumlah_database; counter++) {
		status_pencarian = string_search(target_name, event[counter].nama);

		if (status_pencarian == 0) {
			lihat_event(&event[counter], &pencarian) ;
			pencarian++;
		}
	}
	if (pencarian == 0) {
			printf("\nEvent tidak ditemukan.\n");
	}
}

//function untuk melakukan searching waktu
void searching_waktu(int jumlah_database, struct Event *event) {
	int counter, status_pencarian, pencarian = 0, opsi, target_month, target_year, error=0;
	do
	{
		error = 0;
		printf("Masukkan opsi pencarian\n1. Search bulan event\n2. Search tahun event\n3. Search bulan dan tahun event\n> ");
		scanf("%d", &opsi);
		//searching data di struct event
		switch (opsi)
		{
			case 1 :
				printf("Masukkan bulan event yang ingin dicari: ");
				scanf("%d", &target_month);
				printf("Hasil pencarian\n");
				
				for (counter = 0; counter < jumlah_database; counter++) {
					if (target_month == event[counter].bulan) {
						lihat_event(&event[counter], &pencarian) ;
						pencarian++;
					}
				}
				if (pencarian == 0) {
					printf("\nEvent tidak ditemukan.\n");
				}
				break;
			case 2 :
				printf("Masukkan tahun event yang ingin dicari: ");
				scanf("%d", &target_year);
				printf("Hasil pencarian\n");

				for (counter = 0; counter < jumlah_database; counter++) {
					if (target_year == event[counter].tahun) {
						lihat_event(&event[counter], &pencarian) ;
						pencarian++;
					}
				}
				if (pencarian == 0) {
					printf("\nEvent tidak ditemukan.\n");
				}
				break;
			case 3 :
				printf("Masukkan bulan event yang ingin dicari: ");
				scanf("%d", &target_month);
				printf("Masukkan tahun event yang ingin dicari: ");
				scanf("%d", &target_year);
				printf("Hasil pencarian\n");

				for (counter = 0; counter < jumlah_database; counter++) {
					if (target_month == event[counter].bulan && target_year == event[counter].tahun) {
						lihat_event(&event[counter], &pencarian) ;
						pencarian++;
					}
				}
				if (pencarian == 0) {
					printf("\nEvent tidak ditemukan.\n");
				}
				break;
			default :
				printf("Input tidak valid. Silahkan masukkan bilangan 1-3\n");
		}
	}while(error==1);
}

//function untuk melakukan searching tipe
void searching_tipe(int jumlah_database, struct Event *event) {
	int counter, status_pencarian, pencarian = 0;
	char target_name[50];

	printf("\nBerikut adalah menu untuk mencari event berdasarkan tipenya. Silahkan masukkan tipe event yang ingin Anda cari (pribadi/kelompok)\nMasukkan tipe event yang ingin dicari: ");
	scanf("%s", target_name);
	printf("Hasil pencarian\n");

	// searching data di struct event
	for (counter = 0; counter < jumlah_database; counter++) {
		status_pencarian = string_search(target_name, event[counter].tipe);

		if (status_pencarian == 0) {
			lihat_event(&event[counter], &pencarian) ;
			pencarian++;
		}
	}
	if (pencarian == 0) {
			printf("\nEvent tidak ditemukan.\n");
	}
}

//function untuk melakukan searching urgensi
void searching_urgensi(int jumlah_database, struct Event *event) {
	int counter, status_pencarian, pencarian = 0;
	char target_name[50];

	printf("\n\nBerikut adalah menu untuk mencari event berdasarkan tingkat urgensinya. Silahkan masukkan event yang ingin Anda cari berdasarkan tingkat urgensinya (Mendesak/Tidak)\nMasukkan urgensi event yang ingin dicari: ");
	scanf("%s", target_name);
	printf("Hasil pencarian\n");

	// searching data di struct event
	for (counter = 0; counter < jumlah_database; counter++) {
		status_pencarian = string_search(target_name, event[counter].urgensi);

		if (status_pencarian == 0) {
			lihat_event(&event[counter], &pencarian) ;
			pencarian++;
		}
	}
	if (pencarian == 0) {
			printf("\nEvent tidak ditemukan.\n");
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

//function untuk menghapus event yang dipilih
int hapus_event(int jumlah_database, struct Event *event, int opsi)
{
	int urutan;
	for(urutan=opsi-1; urutan<jumlah_database; urutan++)
	{
		swap(urutan, urutan+1, event);
	}
	jumlah_database--;
	printf("\n%d\n", jumlah_database);
	return jumlah_database;
	printf("\nEvent berhasil dihapus\n");
}