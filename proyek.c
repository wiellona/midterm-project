#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "AsciiArt.h"
#include "proyek.h"

int main()
{
	int opsi, opsi_detail, jumlah_database=0, database, kembali_ke_menu;
	struct Event *event;
	char tanggal[10], bulan[2], tahun[4], jam[2], menit[2];
	time_t t;
	//dynamic memory allocation struct
	event = (struct Event *) malloc (10 * sizeof(struct Event));
	if (event == NULL) {
        printf("Alokasi memori gagal");
        exit(1);
    }
	FILE *data;
	data = fopen("data proyek.txt", "r");
	fscanf(data, "%d", &jumlah_database);
	for (database=0; database<jumlah_database; database++)
	fscanf(data, "%s %d %d %d %s %s %s", event[database].nama, &event[database].tanggal, &event[database].bulan, &event[database].tahun, event[database].deskripsi, event[database].tipe, event[database].urgensi);
	fclose(data);
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
	    		break;
	    	case 2:
	    		do
	    		{
	    			clear();
		    		printf("0. Kembali\n");
		    		for (database = 0; database < jumlah_database; database++)
					{
		    			lihat_event(&event[database], &database);//function di proyek.h
		    		}
		    		printf("%d. Sorting\n%d. Searching\n", jumlah_database+2, jumlah_database+3);
	    			printf("Masukkan pilihan : ");
	    			scanf("%d", &opsi_detail);
	    			if (opsi_detail!=0&&opsi_detail<=jumlah_database)
	    			{
	    				clear();
	    				detail_event(&event[opsi_detail-1]);
	    				printf("\n1. kembali\n2. Beranda\nmasukkan pilihan : ");
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
	    				clear();
	    				if (opsi_detail == jumlah_database+2)
	    				{
	    					menu_sorting(jumlah_database, event);
						}else if (opsi_detail == jumlah_database+3)
						{
							menu_searching(jumlah_database, event);
						}
					}
				}while(opsi_detail!=0 && kembali_ke_menu!=1);
	    		break;
	    	case 3:
	    		do{
	    		clear();
		    	printf("0. Kembali\n");
		    	for (database = 0; database < jumlah_database; database++)
				{
	    			lihat_event(&event[database], &database);//function di proyek.h
	    		}
	    		printf("Pilih event yang ingin diubah : ");
			scanf("%d", &opsi);
			if(opsi!=0)
			clear();
			if (opsi!=0)
			    {
			    	do
			    	{
			    	detail_event(&event[opsi-1]);
			    	printf("\n0. Kembali\n1. Ubah nama event\n2. Ubah tanggal event\n3. Ubah deskripsi event\n4. Ubah tipe event\n5. Ubah urgensi event\n6. Hapus event\n> ");
			    	scanf("%d", &opsi_detail);
					switch (opsi_detail)
					{
						case 0 :
							break;
						case 1 :
							printf("Masukkan nama event yang baru : ");
							scanf("%s",event[opsi-1].nama);
							break;
						case 2 :
							printf("Masukkan tanggal event yang baru : ");
							scanf("%d", &event[opsi-1].tanggal);
							printf("Masukkan bulan event yang baru : ");
							scanf("%d", &event[opsi-1].bulan);
							printf("Masukkan tahun event yang baru : ");
							scanf("%d", &event[opsi-1].tahun);
							break;
						case 3 :
							printf("Masukkan deskripsi event yang baru : ");
							scanf("%s", event[opsi-1].deskripsi);
							break;
						case 4 :
							printf("Masukkan tipe event yang baru : ");
							scanf("%s", event[opsi-1].tipe);
							break;
						case 5 :
							printf("Masukkan urgensi event yang baru : ");
							scanf("%s", event[opsi-1].urgensi);
							break;
						case 6 :
							jumlah_database = hapus_event(jumlah_database, &event[opsi], opsi);
							break;
					}
					}while(opsi_detail!=0);
			    }else kembali_ke_menu = 1;
			    }while(kembali_ke_menu != 1);
			    break;
	    	case 4:
	    		simpan_event(event, jumlah_database, database, data);//function di proyek.h
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