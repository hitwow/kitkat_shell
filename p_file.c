/*
 * p_file.c
 *
 *  Created on: 2014年3月23日
 *      Author: hitwow
 */
#include <stdio.h>
#include "p_file.h"

int w_file(char* fname, void* input, size_t size)
{
	FILE* fp;

	fp=fopen(fname, "ab");
	fwrite(input, size, 1, fp);

	return 0;
}

