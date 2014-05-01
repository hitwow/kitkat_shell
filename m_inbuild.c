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
    init_show();
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
	char* tmp = histable[hispos];
    
    if (tmp)
        free(tmp);

	histable[hispos++] = cmd;

	if (hispos==hisnum)
		hispos = 0;
}

void history()
{
	int tmp = hispos;
	int i = 0;

	if (!histable[hispos])
	{
		if (!hispos)
			return;
		else
			hispos = 0;
	}

	do{
		printf("\t%d\t%s\n", i, histable[hispos]);
		i++;
		hispos++;
		if (hispos==hisnum)
			hispos = 0;
	}while(hispos!=tmp);
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
    int tmp = hispos;
    int i = 0;
    FILE* fp;

    fp = fopen("history", "w");
        
    if (!histable[hispos])
    {
        if (!hispos)
            exit(0);
        else
            hispos = 0;
    }
    do{
        fwrite(histable[hispos], CMDLEN, 1, fp);
        i++;
        hispos++;
        if (hispos==hisnum)
            hispos = 0;
    }while(hispos!=tmp);

	exit(0);
}

void do_shell()
{
    return;
}
