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
	int opsi, opsi_detail, jumlah_database=0, database, kembali_ke_menu;
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
	kembali_ke_menu=0;
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
				simpan_event(event, &jumlah_database, database, data);
	    		break;
	    	case 2:
	    		do
	    		{
	    			clear();
		    		printf("0. Kembali\n");
		    		for (database = 0; database < jumlah_database; database++)
					{
		    			lihat_event(&event[database], &jumlah_database, &database, data);//function di proyek.h
		    		}
		    		printf("%d. Sorting\n%d. Searching\n", jumlah_database+2, jumlah_database+3);
	    			printf("Masukkan pilihan : ");
	    			scanf("%d", &opsi_detail);
	    			clear();
	    			if (opsi_detail!=0&&opsi_detail<=jumlah_database)
	    			{
	    				detail_event(&event[opsi_detail-1]);
	    				printf("\n1. Kembali\n2. Kembali ke menu\nMasukkan pilihan : ");
						scanf("%d", &opsi_detail);
						switch (opsi_detail)
						{
							case 1 :
								break;
							case 2 :
								kembali_ke_menu = 1;
								break;
						}
	    			}else if (opsi_detail>jumlah_database)
	    			{
	    				if (opsi_detail == jumlah_database+2)
	    				{
	    					menu_sorting(jumlah_database, event);
						}else if (opsi_detail == jumlah_database+3)
						{
							searching_nama_event(&event[database], &jumlah_database, data);
						}
					}
				} while(opsi_detail!=0 && kembali_ke_menu!=1);
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
	    		printf("Input tidak valid. Silahkan masukkan angka 1-4.\n");
	    		break;
		}
    clear();
	}while(opsi!=4);
    exit(0);
}
