#include <stdio.h>
#include <string.h>
#include <ctype.h> //untuk menggunakan tolower

//function untuk print string dengan ascii art (Belom jadi)
void printAsciiArt(const char *text) {
    int i;
    char asciiArt[5000] = ""; // Assuming a maximum size for the ASCII art
    for (i = 0; text[i] != '\0'; i++) {//1
        switch (tolower(text[i])) {
            case '0':
            	strcat(asciiArt, "   ___  ");   
            	break;
	        case '1':
	            strcat(asciiArt, "  __ ");
	            break;
	        case '2':
	            strcat(asciiArt, "  ___  ");
	            break;
	        case '3':
	            strcat(asciiArt, "  ____  ");
	            break;
	        case '4':
	            strcat(asciiArt, "  _  _   ");
	            break;
	        case '5':
	            strcat(asciiArt, "  _____ ");
	            break;
	        case '6':
	            strcat(asciiArt, "    __  ");
	            break;
	        case '7':
	            strcat(asciiArt, "  ______ ");
	            break;
	        case '8':
	            strcat(asciiArt, "   ___  ");
	            break;
	        case '9':
	            strcat(asciiArt, "   ___  ");
	            break;
	        case '-':
	            strcat(asciiArt, "         ");
	            break;
	        case ':':
	            strcat(asciiArt, "    ");
	            break;
	        case 'a':
	        	strcat(asciiArt, "           ");
				break;
			case 'b':
	        	strcat(asciiArt, "  ____  "); 
				break;  
			case 'c':
	        	strcat(asciiArt, "   _____ "); 
				break;  
			case 'd':
	        	strcat(asciiArt, "  _____  "); 
				break;  
			case 'e':
	        	strcat(asciiArt, "  ______ "); 
				break;  
			case 'f':
	        	strcat(asciiArt, "  ______ "); 
				break;  
			case 'g':
	        	strcat(asciiArt, "   _____ ");
				break;  
			case 'h':
	        	strcat(asciiArt, "           ");
				break;  
			case 'i':
	        	strcat(asciiArt, "           ");
				break;  
			case 'j':
	        	strcat(asciiArt, "           ");
				break;  
			case 'k':
	        	strcat(asciiArt, "           ");
				break;  
			case 'l':
	        	strcat(asciiArt, "           ");
				break;  
			case 'm':
	        	strcat(asciiArt, "  __  __ "); 
				break;  
			case 'n':
	        	strcat(asciiArt, "  _   _ "); 
				break;  
			case 'o':
	        	strcat(asciiArt, "           ");
				break;  
			case 'p':
	        	strcat(asciiArt, "           ");
				break;  
			case 'q':
	        	strcat(asciiArt, "           ");
				break;  
			case 'r':
	        	strcat(asciiArt, "           ");
				break;  
			case 's':
	        	strcat(asciiArt, "           ");
				break;  
			case 't':
	        	strcat(asciiArt, "           ");
				break;  
			case 'u':
	        	strcat(asciiArt, "  _    _ "); 
				break;  
			case 'v':
	        	strcat(asciiArt, "           ");
				break;  
			case 'w':
	        	strcat(asciiArt, "           ");
				break;  
			case 'x':
	        	strcat(asciiArt, "           ");
				break;  
			case 'y':
	        	strcat(asciiArt, "           ");
				break;  
			case 'z':
	        	strcat(asciiArt, "           ");
				break;      
	        default:
	            strcat(asciiArt, " ");
	            break;
        }
    }
    strcat(asciiArt, "\n");
    for (i = 0; text[i] != '\0'; i++) {//2
        switch (tolower(text[i])) {
            case '0':
            	strcat(asciiArt, "  / _ \\ ");
            	break;
	        case '1':
	            strcat(asciiArt, " /_ |");
	            break;
	        case '2':
	            strcat(asciiArt, " |__ \\ ");
	            break;
	        case '3':
	            strcat(asciiArt, " |___ \\ ");
	            break;
	        case '4':
	            strcat(asciiArt, " | || |  ");
	            break;
	        case '5':
	            strcat(asciiArt, " | ____|");
	            break;
	        case '6':
	            strcat(asciiArt, "   / /  ");
	            break;
	        case '7':
	            strcat(asciiArt, " |____  |");
	            break;
	        case '8':
	            strcat(asciiArt, "  / _ \\ ");
	            break;
	        case '9':
	            strcat(asciiArt, "  / _ \\ ");
	            break;
	        case '-':
	            strcat(asciiArt, "         ");
	            break;
	        case ':':
	    		strcat(asciiArt, "  _ ");
	    		break;
	    	case 'a':
	    		 strcat(asciiArt, "     /\\    ");
				 break;
			case 'b':
	        	strcat(asciiArt, " |  _ \\ "); 
				break;  
			case 'c':
	        	strcat(asciiArt, "  / ____|"); 
				break;  
			case 'd':
	        	strcat(asciiArt, " |  __ \\ "); 
				break;  
			case 'e':
	        	strcat(asciiArt, " |  ____|"); 
				break;  
			case 'f':
	        	strcat(asciiArt, " |  ____|"); 
				break;  
			case 'g':
	        	strcat(asciiArt, "  / ____|"); 
				break;  
			case 'h':
	        	strcat(asciiArt, "           ");
				break;  
			case 'i':
	        	strcat(asciiArt, "           ");
				break;  
			case 'j':
	        	strcat(asciiArt, "           ");
				break;  
			case 'k':
	        	strcat(asciiArt, "           ");
				break;  
			case 'l':
	        	strcat(asciiArt, "           ");
				break;  
			case 'm':
	        	strcat(asciiArt, " |  \\/  |"); 
				break;  
			case 'n':
	        	strcat(asciiArt, " | \\ | |");
				break;  
			case 'o':
	        	strcat(asciiArt, "           ");
				break;  
			case 'p':
	        	strcat(asciiArt, "           ");
				break;  
			case 'q':
	        	strcat(asciiArt, "           ");
				break;  
			case 'r':
	        	strcat(asciiArt, "           ");
				break;  
			case 's':
	        	strcat(asciiArt, "           ");
				break;  
			case 't':
	        	strcat(asciiArt, "           ");
				break;  
			case 'u':
	        	strcat(asciiArt, " | |  | |"); 
				break;  
			case 'v':
	        	strcat(asciiArt, "           ");
				break;  
			case 'w':
	        	strcat(asciiArt, "           ");
				break;  
			case 'x':
	        	strcat(asciiArt, "           ");
				break;  
			case 'y':
	        	strcat(asciiArt, "           ");
				break;  
			case 'z':
	        	strcat(asciiArt, "           ");
				break;   
	        default:
	            strcat(asciiArt, " ");
	            break;
        }
    }
    strcat(asciiArt, "\n");
	for (i = 0; text[i] != '\0'; i++) {//3
        switch (tolower(text[i])) {
            case '0':
            	strcat(asciiArt, " | | | |");
            	break;
	        case '1':
	            strcat(asciiArt, "  | |");
	            break;
	        case '2':
	            strcat(asciiArt, "    ) |");
	            break;
	        case '3':
	            strcat(asciiArt, "   __) |");
	            break;
	        case '4':
	            strcat(asciiArt, " | || |_ ");
	            break;
	        case '5':
	            strcat(asciiArt, " | |__  ");
	            break;
	        case '6':
	            strcat(asciiArt, "  / /_  ");
	            break;
	        case '7':
	            strcat(asciiArt, "     / / ");
	            break;
	        case '8': 
	            strcat(asciiArt, " | (_) |");
	            break;
	        case '9':
	            strcat(asciiArt, " | (_) |");
	            break;
	        case '-':
	            strcat(asciiArt, "  ______ ");
	            break;
			case ':':
	    		strcat(asciiArt, " (_)");
	    		break;
	    	case 'a':
	        	strcat(asciiArt, "    /  \\   "); 
				break; 
			case 'b':
	        	strcat(asciiArt, " | |_) |");
				break;  
			case 'c':
	        	strcat(asciiArt, " | |     "); 
				break;  
			case 'd':
	        	strcat(asciiArt, " | |  | |");
				break;  
			case 'e':
	        	strcat(asciiArt, " | |__   ");
				break;  
			case 'f':
	        	strcat(asciiArt, " | |__   "); 
				break;  
			case 'g':
	        	strcat(asciiArt, " | |  __ ");
				break;  
			case 'h':
	        	strcat(asciiArt, "           ");
				break;  
			case 'i':
	        	strcat(asciiArt, "           ");
				break;  
			case 'j':
	        	strcat(asciiArt, "           ");
				break;  
			case 'k':
	        	strcat(asciiArt, "           ");
				break;  
			case 'l':
	        	strcat(asciiArt, "           ");
				break;  
			case 'm':
	        	strcat(asciiArt, " | \\  / |"); 
				break;  
			case 'n':
	        	strcat(asciiArt, " |  \\| |");
				break;  
			case 'o':
	        	strcat(asciiArt, "           ");
				break;  
			case 'p':
	        	strcat(asciiArt, "           ");
				break;  
			case 'q':
	        	strcat(asciiArt, "           ");
				break;  
			case 'r':
	        	strcat(asciiArt, "           ");
				break;  
			case 's':
	        	strcat(asciiArt, "           ");
				break;  
			case 't':
	        	strcat(asciiArt, "           ");
				break;  
			case 'u':
	        	strcat(asciiArt, " | |  | |"); 
				break;  
			case 'v':
	        	strcat(asciiArt, "           ");
				break;  
			case 'w':
	        	strcat(asciiArt, "           ");
				break;  
			case 'x':
	        	strcat(asciiArt, "           ");
				break;  
			case 'y':
	        	strcat(asciiArt, "           ");
				break;  
			case 'z':
	        	strcat(asciiArt, "           ");
				break;  
	        default:
	            strcat(asciiArt, " ");
	            break;
        }
    }
    strcat(asciiArt, "\n");
	for (i = 0; text[i] != '\0'; i++) {//4
        switch (tolower(text[i])) {
            case '0':
            	strcat(asciiArt, " | | | |");
            	break;
	        case '1':
	            strcat(asciiArt, "  | |");
	            break;
	        case '2':
	            strcat(asciiArt, "   / / ");
	            break;
	        case '3':
	            strcat(asciiArt, " |__ <  ");
	            break;
	        case '4':
	            strcat(asciiArt, " |__   _|");
	            break;
	        case '5':
	            strcat(asciiArt, " |___ \\ ");
	            break;
	        case '6':
	            strcat(asciiArt, " | '_ \\ ");
	            break;
	        case '7':
	            strcat(asciiArt, "    / /  ");
	            break;
	        case '8':
	            strcat(asciiArt, "  > _ < ");
	            break;
	        case '9':
	            strcat(asciiArt, "  \\__, |");
	            break;
	        case '-':
	            strcat(asciiArt, " |______|");
	            break;
	        case ':':
	    		strcat(asciiArt, "    ");
	    		break;
	    	case 'a':
	        	strcat(asciiArt, "   / /\\ \\  ");
				break; 
			case 'b':
	        	strcat(asciiArt, " |  _ < "); 
				break;  
			case 'c':
	        	strcat(asciiArt, " | |     "); 
				break;  
			case 'd':
	        	strcat(asciiArt, " | |  | |"); 
				break;  
			case 'e':
	        	strcat(asciiArt, " |  __|  "); 
				break;  
			case 'f':
	        	strcat(asciiArt, " |  __|  ");
				break;  
			case 'g':
	        	strcat(asciiArt, " | | |_ |");
				break;  
			case 'h':
	        	strcat(asciiArt, "           ");
				break;  
			case 'i':
	        	strcat(asciiArt, "           ");
				break;  
			case 'j':
	        	strcat(asciiArt, "           ");
				break;  
			case 'k':
	        	strcat(asciiArt, "           ");
				break;  
			case 'l':
	        	strcat(asciiArt, "           ");
				break;  
			case 'm':
	        	strcat(asciiArt, " | |\\/| |"); 
				break;  
			case 'n':
	        	strcat(asciiArt, " | . ` |"); 
				break;  
			case 'o':
	        	strcat(asciiArt, "           ");
				break;  
			case 'p':
	        	strcat(asciiArt, "           ");
				break;  
			case 'q':
	        	strcat(asciiArt, "           ");
				break;  
			case 'r':
	        	strcat(asciiArt, "           ");
				break;  
			case 's':
	        	strcat(asciiArt, "           ");
				break;  
			case 't':
	        	strcat(asciiArt, "           ");
				break;  
			case 'u':
	        	strcat(asciiArt, " | |  | |"); 
				break;  
			case 'v':
	        	strcat(asciiArt, "           ");
				break;  
			case 'w':
	        	strcat(asciiArt, "           ");
				break;  
			case 'x':
	        	strcat(asciiArt, "           ");
				break;  
			case 'y':
	        	strcat(asciiArt, "           ");
				break;  
			case 'z':
	        	strcat(asciiArt, "           ");
				break;  
	        default:
	            strcat(asciiArt, " ");
	            break;
        }
    }
    strcat(asciiArt, "\n");
	for (i = 0; text[i] != '\0'; i++) {//5
        switch (tolower(text[i])) {
            case '0':
            	strcat(asciiArt, " | |_| |");
            	break;
	        case '1':
	            strcat(asciiArt, "  | |");
	            break;
	        case '2':
	            strcat(asciiArt, "  / /_ ");
	            break;
	        case '3':
	            strcat(asciiArt, "  ___) |");
	            break;
	        case '4':
	            strcat(asciiArt, "    | |  ");
	            break;
	        case '5':
	            strcat(asciiArt, "  ___) |");
	            break;
	        case '6':
	            strcat(asciiArt, " | (_) |");
	            break;
	        case '7':
	            strcat(asciiArt, "   / /   ");
	            break;
	        case '8':
	            strcat(asciiArt, " | (_) |");
	            break;
	        case '9':
	            strcat(asciiArt, "    / / ");
	            break;
	        case '-':
	            strcat(asciiArt, "         ");
	            break;
	        case ':':
				strcat(asciiArt, "  _ ");
				break;
			case 'a':
	        	strcat(asciiArt, "  / ____ \\ "); 
				break; 
			case 'b':
	        	strcat(asciiArt, " | |_) |");
				break;  
			case 'c':
	        	strcat(asciiArt, " | |____ "); 
				break;  
			case 'd':
	        	strcat(asciiArt, " | |__| |");
				break;  
			case 'e':
	        	strcat(asciiArt, " | |____ "); 
				break;  
			case 'f':
	        	strcat(asciiArt, " | |     "); 
				break;  
			case 'g':
	        	strcat(asciiArt, " | |__| |");
				break;  
			case 'h':
	        	strcat(asciiArt, "           ");
				break;  
			case 'i':
	        	strcat(asciiArt, "           ");
				break;  
			case 'j':
	        	strcat(asciiArt, "           ");
				break;  
			case 'k':
	        	strcat(asciiArt, "           ");
				break;  
			case 'l':
	        	strcat(asciiArt, "           ");
				break;  
			case 'm':
	        	strcat(asciiArt, " | |  | |"); 
				break;  
			case 'n':
	        	strcat(asciiArt, " | |\\  |"); 
				break;  
			case 'o':
	        	strcat(asciiArt, "           ");
				break;  
			case 'p':
	        	strcat(asciiArt, "           ");
				break;  
			case 'q':
	        	strcat(asciiArt, "           ");
				break;  
			case 'r':
	        	strcat(asciiArt, "           ");
				break;  
			case 's':
	        	strcat(asciiArt, "           ");
				break;  
			case 't':
	        	strcat(asciiArt, "           ");
				break;  
			case 'u':
	        	strcat(asciiArt, " | |  | |"); 
				break;  
			case 'v':
	        	strcat(asciiArt, "           ");
				break;  
			case 'w':
	        	strcat(asciiArt, "           ");
				break;  
			case 'x':
	        	strcat(asciiArt, "           ");
				break;  
			case 'y':
	        	strcat(asciiArt, "           ");
				break;  
			case 'z':
	        	strcat(asciiArt, "           ");
				break;  
	        default:
	            strcat(asciiArt, " ");
	            break;
        }
    }
    strcat(asciiArt, "\n");
    for (i = 0; text[i] != '\0'; i++) {//6
        switch (tolower(text[i])) {
            case '0':
            	strcat(asciiArt, "  \\___/ ");
            	break;
	        case '1':
	            strcat(asciiArt, "  |_|");
	            break;
	        case '2':
	            strcat(asciiArt, " |____|");
	            break;
	        case '3':
	            strcat(asciiArt, " |____/ ");
	            break;
	        case '4':
	            strcat(asciiArt, "    |_|  ");
	            break;
	        case '5':
	            strcat(asciiArt, " |____/ ");
	            break;
	        case '6':
	            strcat(asciiArt, "  \\___/ ");
	            break;
	        case '7':
	            strcat(asciiArt, "  /_/    ");
	            break;
	        case '8':
	            strcat(asciiArt, "  \\___/ ");
	            break;
	        case '9':
	            strcat(asciiArt, "   /_/  ");
	            break;
	        case '-':
	            strcat(asciiArt, "         ");
	            break;
			case ':':
				strcat(asciiArt, " (_)");
				break;
			case 'a':
	        	strcat(asciiArt, " /_/    \\_\\"); 
				break; 
			case 'b':
	        	strcat(asciiArt, " |____/ "); 
				break;  
			case 'c':
	        	strcat(asciiArt, "  \\_____|");
				break;  
			case 'd':
	        	strcat(asciiArt, " |_____/ ");  
				break;  
			case 'e':
	        	strcat(asciiArt, " |______|"); 
				break;  
			case 'f':
	        	strcat(asciiArt, " |_|     "); 
				break;  
			case 'g':
	        	strcat(asciiArt, "  \\_____|"); 
				break;  
			case 'h':
	        	strcat(asciiArt, "           ");
				break;  
			case 'i':
	        	strcat(asciiArt, "           ");
				break;  
			case 'j':
	        	strcat(asciiArt, "           ");
				break;  
			case 'k':
	        	strcat(asciiArt, "           ");
				break;  
			case 'l':
	        	strcat(asciiArt, "           ");
				break;  
			case 'm':
	        	strcat(asciiArt, " |_|  |_|");
				break;  
			case 'n':
	        	strcat(asciiArt, " |_| \\_|"); 
				break;  
			case 'o':
	        	strcat(asciiArt, "           ");
				break;  
			case 'p':
	        	strcat(asciiArt, "           ");
				break;  
			case 'q':
	        	strcat(asciiArt, "           ");
				break;  
			case 'r':
	        	strcat(asciiArt, "           ");
				break;  
			case 's':
	        	strcat(asciiArt, "           ");
				break;  
			case 't':
	        	strcat(asciiArt, "           ");
				break;  
			case 'u':
	        	strcat(asciiArt, "  \\____/ "); 
				break;  
			case 'v':
	        	strcat(asciiArt, "           ");
				break;  
			case 'w':
	        	strcat(asciiArt, "           ");
				break;  
			case 'x':
	        	strcat(asciiArt, "           ");
				break;  
			case 'y':
	        	strcat(asciiArt, "           ");
				break;  
			case 'z':
	        	strcat(asciiArt, "           ");
				break;  
	        default:
	            strcat(asciiArt, " ");
	            break;
        }
    }
    printf("\n%s\n", asciiArt);
}
