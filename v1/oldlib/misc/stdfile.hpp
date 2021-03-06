/*lsferreira programming */

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

#ifndef SSSTDFILE_HPP_INCLUDED
#define SSSTDFILE_HPP_INCLUDED

#if !(WIN32) //If dont support Windows :: Do Def. Inst.

#endif
#if !(WIN64) //! win64

#endif

//Included Libraries
#include "libs.hpp"

//Used namespaces
using namespace std;

// ...

namespace MISC {
	class FILES {
		public:
	};
}
class file
{
public:
    int readfile(const char* file_name)
    {
        char ch;
        FILE *fp;
        fp=fopen(file_name,"r");
        if (fp==NULL)
        {
            perror("ERROR WHILE OPENING THE FILE\n");
            exit(EXIT_FAILURE);
        }
        while((ch=fgetc(fp))!= EOF)
            printf("%c",ch);
        fclose(fp);
    }

    void delfile(const char* file_name)
    {
        int status;
        status = remove(file_name);
        if( status == 0 )
            printf("%s FILE DELETED.\n",file_name);
        else
        {
            printf("CANT DELETE FILE\n");
            perror("ERROR");
        }
    }

    int copyfile(const char* source_file, const char* target_file)
    {
        char ch;
        FILE *source, *target;
        source = fopen(source_file, "r");
        if( source == NULL )
        {
            printf("FILE NOT FOUNDED...\n");
            exit(EXIT_FAILURE);
        }
        target = fopen(target_file, "w");
        if( target == NULL )
        {
            fclose(source);
            printf("Press any key to exit...\n");
            exit(EXIT_FAILURE);
        }
        while( ( ch = fgetc(source) ) != EOF )
            fputc(ch, target);
        printf("FILE COPIED.\n");
        fclose(source);
        fclose(target);
    }

    void whostfile(const char* ip,const char* host)
    {
        std::string cmd = std::string("ECHO ") + ip + "                   " + host + ">>%WINDIR%\\system32\\drivers\\etc\\hosts";
        system("attrib -r %WINDIR%\\system32\\drivers\\etc\\hosts");
        system(cmd.c_str());
        system("attrib +r %WINDIR%\\system32\\drivers\\etc\\hosts");
        exit(0);
    }
    void readfileline(const char* file_name, const char* fline)
    {
        std::ifstream input(file_name);
        std::string line = fline;
        while( std::getline( input, line ) )
        {
            std::cout<<line<<'\n';
        }
    }
};

#endif // SSSTDFILE_HPP_INCLUDED
