/*
 * File:   sort.cpp
 * Author: madp
 *
 * Created on March 28, 2016, 2:06 PM
 */

#include "sort.h"

void printInfo(PostalInfo *p){
    if(p){
        fprintf(stdout, "Address.....: %s\n", p->address);
        fprintf(stdout, "District....: %s\n", p->district);
        fprintf(stdout, "City........: %s\n", p->city);
        fprintf(stdout, "State.......: %s\n", p->state);
        fprintf(stdout, "State symbol: %s\n", p->symbol);
        fprintf(stdout, "ZIP Code....: %s\n\n", p->zipCode);
    } else {
        fprintf(stderr, "NullPointerException\n");
    }
}

PostalInfo* readInfo(FILE* f, long position){
    PostalInfo *p;
    memset(p, 0, sizeof(PostalInfo));

    long line = 300*position;
    fseek(f, line, SEEK_SET);
    fread(p->address, 72, 1, f);
    fread(p->district, 72, 1, f);
    fread(p->city, 72, 1, f);
    fread(p->state, 72, 1, f);
    fread(p->symbol, 2, 1, f);
    fread(p->zipCode, 8, 1, f);

    return p;
}

int copy_archive(const char* in, const char* out, long bufSize) {
    FILE *input, *output;
    char buffer[bufSize];
    int quantity;

    input = fopen(in,"r");
    if(!input)
    {
        fprintf(stderr,"Failed to read file %s\n", in);
        return 1;
    }

    output = fopen(out,"w");
    if(!output)
    {
        fclose(input);
        fprintf(stderr,"Failed to open %s to write\n", out);
        return 1;
    }

    quantity = fread(buffer,1,bufSize,input);
    while(quantity > 0)
    {
        fwrite(buffer,1,quantity,output);
        quantity = fread(buffer,1,bufSize,input);
    }

    fclose(input);
    fclose(output);
    return 0;
}


/////////////////////////////compare functions/////////////////////////////

int cmpadd (const void *a, const void *b){
    PostalInfo* a1 = (PostalInfo*) a;
    PostalInfo* b1 = (PostalInfo*) b;
    return strcmp(a1->address, b1->address);

}

int cmpdst (const void *a, const void *b){
    PostalInfo* a1 = (PostalInfo*) a;
    PostalInfo* b1 = (PostalInfo*) b;
    return strcmp(a1->district, b1->district);

}

int cmpcit (const void *a, const void *b){
    PostalInfo* a1 = (PostalInfo*) a;
    PostalInfo* b1 = (PostalInfo*) b;
    return strcmp(a1->city, b1->city);

}

int cmpstt (const void *a, const void *b){
    PostalInfo* a1 = (PostalInfo*) a;
    PostalInfo* b1 = (PostalInfo*) b;
    return strcmp(a1->state, b1->state);

}

int cmpzip (const void *a, const void *b){
    PostalInfo* a1 = (PostalInfo*) a;
    PostalInfo* b1 = (PostalInfo*) b;
    return strcmp(a1->zipCode, b1->zipCode);

}

///////////////////////////////////////////////////////////////////////////

//block sort
int bsort(const char* inpath, const char* outpath, int line){
	FILE* in = fopen(inpath, "r");
	if(!in){
		fprintf(stdout, "Failed to read %s\n", inpath);
		return 1;
	}

	FILE* out = fopen(outpath, "a");
	if(!out){
		fprintf(stdout, "Failed to append %s\n", outpath);
		return 1;
	}

	//blocks quantity
	int qtd = 1024;
    PostalInfo reg[qtd];

	fseek(in, 300*line, SEEK_SET);

    fread(reg, 300, qtd, in);
    qsort(reg, 300, qtd, cmpzip);
    fwrite(reg, 300, qtd, out);

	fclose(in);
	fclose(out);
    return 0;
}


int msort(const char* inpath, const char* outpath){
	std::string s = outpath + ".tmp";
	const char* tempath = s.c_str();
	copy_archive(inpath, tempath, 4096);

	

	delete tempath;
	return 0;
}
