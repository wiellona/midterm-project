#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "AsciiArt.h"
#include "proyek.h"

int main()
{
	
	FILE *data;
	data = fopen("data proyek.txt", "w");
	struct Event *event;
	int opsi, jumlah_database=0, database;
	char tanggal[10], bulan[2], tahun[4], jam[2], menit[2];
	time_t t;
	//dynamic memory allocation struct
	event = (struct Event *) malloc (10 * sizeof(struct Event));
	if (event == NULL) {
        printf("Alokasi memori gagal");
        exit(1);
    }
	do
	{
	t = time(NULL);
	struct tm tm = *localtime(&t);
	//menu awal
	sprintf(tanggal, "%2d-%2d-%4d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	sprintf(jam, "%2d:%2d", tm.tm_hour, tm.tm_min);
	//function di AsciiArt.h
    printAsciiArt(tanggal);
    printAsciiArt(jam);
	
	// Main Menu
	printf("\n\n-----------------------------------\n");
	printf("|    Event Planner and Tracker    |\n");
	printf("|         by Kelompok 23          |\n");
	printf("-----------------------------------\n");
	printf("|            Main Menu            |\n");
	printf("|                                 |\n");
	printf("| 1. Buat Event                   |\n");
	printf("| 2. Lihat Event                  |\n");
	printf("| 3. Edit Event                   |\n");
	printf("| 4. Keluar program               |\n");
	printf("-----------------------------------\n");
	printf("> ");

	scanf("%d", &opsi);
    switch(opsi)
	    {
	    	case 1:
	    		clear();
	    		buat_event(&event[jumlah_database], &jumlah_database);//function di proyek.h
	    		break;
	    	case 2:
	    		clear();
				searching_nama_event(&event[database], &jumlah_database, data);
	    		for (database = 0; database < jumlah_database; database++)
				{
	    			lihat_event(&event[database], &jumlah_database, &database, data);//function di proyek.h
	    		}
	    		break;
	    	case 3:
	    		
	    		break;
	    	case 4:
	    		for (database = 0; database < jumlah_database; database++)
				{
	    			simpan_event(&event[database], &jumlah_database, &database, data);//function di proyek.h
	    		}
	    		exit(0);
	    		break;
	    	default:
	    		printf("INPUT SALAH\n");
	    		break;
		}
    clear();
	}while(opsi!=4);
    exit(0);
}
