/*
 * File:   main.cpp
 * Author: madp
 *
 * Created on March 28, 2016, 1:51 PM
 */

#include "main.h"

using namespace std;

void usage(){
	fprintf(stdout, "Invalid arguments\n");
	fprintf(stdout, "Usage: [PROGNAME] [INPUT] [OUTPUT]\n");

}

int main(int argc, char** argv) {
/*
    const char* inPath = "/home/aluno/Área de Trabalho/Sort/cep.dat";
    const char* outPath = "/home/aluno/Área de Trabalho/Sort/out.dat";
    FILE* in = fopen(inPath, "r");
    fseek(in, 0, SEEK_END);
    long size = ftell(in)/300;
    fseek(in, 0, SEEK_SET);

    copy_archive(inPath, outPath, 4096);
    part(outPath, 0, size);

    fclose(in);
*/
	if(argc != 3){
		usage();
		return 1;
	}

    order(argv[1], argv[2]);

    return 0;
}


