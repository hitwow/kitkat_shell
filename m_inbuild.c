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
/*
void p_path (char* path)
{
	if (path[0] == '~')
	{
		char npath[LOCLEN];

		strcpy(npath, upath);
		strcat(npath, path+1);
		path = npath;
	}
}
*/
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
