/*
 * m_inbuild.c
 *
 *  Created on: 2014年3月22日
 *      Author: hitwow
 */

#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

#include "info.h"
#include "getinfo.h"
#include "m_inbuild.h"

void pwd()
{
	printf ("%s\n", tloc);
}

void cd (char* path)
{
	chdir(path);

	init_path_info();
}

void echo(char* sen)
{
	printf("%s\n", sen);
}

void inalias(char* s, char* t)
{
	FILE* fp;
	alnode al;

	fp = fopen("alias", "a");
	strcpy(al.sc, s);
	strcpy(al.tc, t);
	fwrite(&al, sizeof(al), 1, fp);

	fclose(fp);
}

void alias()
{
	FILE* fp;
	alnode al;

	fp = fopen("alias", "r");
	while (fread(&al, sizeof(al), 1, fp))
	{
		printf("%s='%s'\n", al.sc, al.tc);
	}
}

void inhistory(char* cmd)
{
	FILE* fp;

	fp = fopen
}

void help()
{
	FILE* fp;
	char ch;

	fp = fopen("help", "r");

	while ((ch=getc(fp))!=EOF)
		putchar(ch);

	putchar('\n');
}

void sl_exit()
{
	free(uname);
	free(uhost);
	free(shost);
	free(tloc);
	//free(sloc);

	exit(0);
}
