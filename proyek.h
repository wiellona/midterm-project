#include <stdio.h>
#include <stdlib.h>

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
	printf("\nama Event : %s\n", event->nama);
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
