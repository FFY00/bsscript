/*lsferreira programming*/

/*
                                              _       _   
                                             (_)     | |  
  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_ 
 / __|/ _ \| | | | '__/ __/ _ \/ __|/ __| '__| | '_ \| __|
 \__ \ (_) | |_| | | | (_|  __/\__ \ (__| |  | | |_) | |_ 
 |___/\___/ \__,_|_|  \___\___||___/\___|_|  |_| .__/ \\__|
                                               | |        
                                               |_|        
*/

//Include libraries
#include "libs.hpp"
#include "pilib.hpp"
#include "stdutils.hpp"
#include "stdfile.hpp"
//#include "printdef.hpp"

//Used namespaces
using namespace std;

//Predeclaration functions
void logo(void);
void help(void);
// ...



//Main Function
int main(int argc, char *argv[]) {/*Variables*/ int choise;
utils utils; //Create a object utils by utils
  if(argc > 1) { //If arguments is more than one
    if(string(argv[1]) == "--pi") {
      logo();
      int i=atoi(argv[2]);
      printf("[+] Calculating pi number with %d cases\n",i);
      printf("==============================\n\n");
      i=i;
      pi(i);
      printf("\n[-] Done.\n");
    }
    else if (string(argv[1]) == "--download") {
      logo(); //Print logo
      printf("[+] Downloading file from, \n");
      printf("[-]URL: %s\n",argv[2]);
      printf("[-]OUTPUT: %s\n",argv[3]);
      printf("==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      char cmd[] = "python wget.py --output "; //Add "python" word
      #else //If support, then...
      char cmd[] = "wget.py --output ";
      #endif //end if !(_WIN32)
      strcat(cmd, argv[3]);
      strcat(cmd, " ");
      strcat(cmd, argv[2]);
      system(cmd);
      printf("\n[-] Done.\n");
	  exit(0);
    }
    else if (string(argv[1]) == "--speedtest") {
      logo(); //Print logo
      printf("[+] Doing a speedtest... \n");
      printf("==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      system("python speedtest.py"); // ...
      #else //If support, then...
      system("speedtest.py");
      #endif //end if !(_WIN32)
      printf("\n[-] Done.\n");
	  exit(0);
    }
    else if (string(argv[1]) == "-c") {
      if(string(argv[2]) == "-ww") {
	  }
	  else logo(); //Print logo
	  
	  utils.unix_sysclear();
	}
    else if (string(argv[1]) == "-l") {
      logo(); //Print logo
	  exit(0);
	}
    else if (string(argv[1]) == "--gisocket") {
      logo();
	  
    }
    else if (string(argv[1]) == "--os") {
      logo(); //Print logo
      printf("[+] Operation System Information... \n");
      printf("==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      system("python os.py"); // ...
      #else //If support, then...
      system("os.py");
      #endif //end if !(_WIN32)
      printf("\n[-] Done.\n");
    }
    else if (string(argv[1]) == "--readfile") {
      if(strcmp(argv[3], "-ww")==0) {
      	
	  }
	  else logo(); printf("==============================\n\n");
	  
      readfile(argv[2]);
	}
	else if (string(argv[1]) == "--delfile") {
      logo(); printf("==============================\n\n");
	  
      delfile(argv[2]);
	}
	else if (string(argv[1]) == "--copyfile") {
      logo(); printf("==============================\n\n");
      copyfile(argv[2], argv[3]);
	}
	else if (string(argv[1]) == "--sourcecode") {
      logo(); //Print logo
      printf("[+] Downloading file from, \n");
      printf("[-]URL: %s\n",argv[2]);
      printf("[-]OUTPUT: temp.text\n");
      printf("==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      char cmd[] = "python wget.py --output "; //Add "python" word
      #else //If support, then...
      char cmd[] = "wget.py --output ";
      #endif //end if !(_WIN32)
      strcat(cmd, "temp.text");
      strcat(cmd, " ");
      strcat(cmd, argv[2]);
      system(cmd);
      printf("\n==============================\n\n");
      readfile("temp.text");
      printf("\n[-] Done.\n\n");
      delfile("temp.text");
	  exit(0);
    }
    else if (string(argv[1]) == "--whosts") {
      logo(); //print logo
      printf("[+] Changing windows hosts file...\n");
      printf("[-] IP: %s\n", argv[2]);
      printf("[-] HOST: %s\n", argv[3]);
	  printf("\n==============================\n\n");
	  whostfile(argv[2],argv[3]);
	  exit(0);
    }
    else if (string(argv[1]) == "--sckt") {
      logo(); //print logo
      printf("[+] Connect to a socket with...\n");
      if (strcmp(argv[2], "--this")==0) printf("[-] IP: socket localhost\n");
      else printf("[-] IP: %s\n", argv[2]);
      printf("[-] Port: %s\n", argv[3]);
      printf("[-] Length: %s\n", argv[4]);
      printf("\n==============================\n\n");
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      char cmd[] = "python client.py "; //Add "python" word
      #else //If support, then...
      char cmd[] = "client.py ";
      #endif //end if !(_WIN32)
      strcat(cmd, argv[2]);
      strcat(cmd, " ");
      strcat(cmd, argv[3]);
      strcat(cmd, " ");
      strcat(cmd, argv[4]);
      system(cmd);
    }
    else if (string(argv[1]) == "--mksckt") {
      logo(); //print logo
      cout << "[+] Creating a socket with...\n";
      cout << "[-] Port: " << argv[2] << endl;
      cout << "[-] Message: " << argv[3] << endl;
      cout << "\n==============================\n\n";
      #if !(_WIN32) //If dont support Windows :: Do Def. Inst.
      char cmd[] = "python server.py "; //Add "python" word
      #else //If support, then...
      char cmd[] = "server.py ";
      #endif //end if !(_WIN32)
      strcat(cmd, argv[2]);
      strcat(cmd, " ");
      strcat(cmd, argv[3]);
      system(cmd);
    }
  }
  else { //If arguments is one, show help menu
    logo();
    help();
  }
  exit(0);
}

//Function to print sourcescript logo
void logo(void) {
  cout << "                                              _       _   \n"
  << "                                             (_)     | |  \n"
  << "  ___  ___  _   _ _ __ ___ ___  ___  ___ _ __ _ _ __ | |_ \n"
  << " / __|/ _ \\| | | | '__/ __/ _ \\/ __|/ __| '__| | '_ \\| __|\n"
  << " \\__ \\ (_) | |_| | | | (_|  __/\\__ \\ (__| |  | | |_) | |_ \n"
  << " |___/\\___/ \\__,_|_|  \\___\\___||___/\\___|_|  |_| .__/ \\__|\n"
  << "                                               | |        \n"
  << "                                               |_|        \n\n";
}

//Function to print help menu
void help(void) {
  cout << "Usage: sourcescript (--argv) [argv] ...\n\n";
  cout << "  --pi <num_cases>                 CALCULATE PI\n"; // Calculate a pi : pilib.h
  cout << "  --download <url> <output>        DOWNLOAD A FILE (REQUIRE PYTHON)\n"; //Download python script : wget.py
  cout << "  --speedtest                      DO SPEEDTEST ON YOUR NETWORK (REQUIRE PYTHON)\n"; //Speedtest python script : speedtest.py
  cout << "  -c -w                       	 CLEAR UNIX SCREEN (ONLY UNIX SUPPORT)\n"; //System command for unix : stdutils.h
  cout << "  -l                       	     SHOW SOURCESCRIPT LOGO\n"; 					//Show logo
  cout << "  --os                       	     SHOW OPERATION SYSTEM INFORMATIONS (REQUIRE PYTHON)\n"; //OS python script : os.py
  cout << "  --readfile <patch> -w            READ AN FILE\n"; //Read a file : stdfile.h
  cout << "  --delfile <patch>                DELETE AN FILE\n"; //Delete a file : stdfile.h
  cout << "  --copyfile <patch> <destination> COPY AN FILE TO ANY DESTINATION\n"; //Copy a file : stdfile.h
  cout << "  --sourcecode <url>               VIEW THE SOURCECODE OF ANY URL (REQUIRE PYTHON)\n"; //View sourcecode of any url
  cout << "  --whosts <ip> <host>             CHANGE WINDOWS HOSTS FILE (REQUIRE ADMIN)\n"; //Change windows hosts
  cout << "  --sckt <ip; --this> <port> <len> CONNECT TO A SIMPLE SOCKET (REQUIRE PYTHON)\n"; //Connect to a socket
  cout << "  --mksckt <port> <msg>            CREATE A SIMPLE SOCKET (REQUIRE PYTHON)\n"; //create/make a socket
}
