/*
 * File:   sort.h
 * Author: madp
 *
 * Created on March 28, 2016, 2:06 PM
 */

#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct _PostalInfo PostalInfo;
struct _PostalInfo {
	char address[73];
	char district[73];
	char city[73];
	char state[73];
	char symbol[3];
	char zipCode[9];
	char trash[3];

};

void printInfo(PostalInfo *p);
PostalInfo* readInfo(FILE* f, long position);
int msort(const char* inpath, const char* outpath);

#endif	/* SORT_H */

