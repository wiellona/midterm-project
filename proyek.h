#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Event{
	char nama[50], deskripsi[300], tipe[20], urgensi[20];
	int tanggal, bulan, tahun;
};


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
	printf("Deskripsi : ");
	scanf("%s", event->deskripsi);
	printf("Tipe : ");
	scanf("%s", event->tipe);
	printf("Urgensi : ");
	scanf("%s", event->urgensi);
	(*jumlah_database)++;
}

//function untuk melihat event
void lihat_event(struct Event *event, int *jumlah_database, int *database, FILE *data)
{
	printf("\nNama Event : %s\n", event->nama);
	printf("Tanggal : %2d-%2d-%4d\n", event->tanggal, event->bulan, event->tahun);
	printf("deskripsi : %s\n", event->deskripsi);
	printf("tipe : %s\n", event->tipe);
	printf("urgensi : %s\n", event->urgensi);
}

//function untuk menyimpan event
void simpan_event(struct Event *event, int *jumlah_database, int *database, FILE *data)
{
	fprintf(data, "\nama Event : %s\n", event->nama);
	fprintf(data, "Tanggal : %2d-%2d-%4d\n", event->tanggal, event->bulan, event->tahun);
	fprintf(data, "deskripsi : %s\n", event->deskripsi);
	fprintf(data, "tipe : %s\n", event->tipe);
	fprintf(data,"urgensi : %s\n", event->urgensi);
}

//function untuk searching
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