/*
 * m_inbuild.c
 *
 *  Created on: 2014年3月22日
 *      Author: hitwow
 */

#include <unistd.h>
#include <string.h>
#include <malloc.h>

#include "info.h"
#include "getinfo.h"

int pwd()
{
	if (tloc != NULL)
	{
		printf ("%s\n", tloc);
		return 0;
	}
	else
		return 1;
}

int cd (char* path)
{
	int flag = 0;

	flag += chdir(path);

	if (flag)
		return 1;

	flag += init_path_info();

	if (flag)
		return 1;

	return 0;
}

void echo(char* sen)
{
	printf("%s\n", sen);
}

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

void sl_exit()
{
	free(uname);
	free(uhost);
	free(shost);
	free(upath);
	free(tloc);
	free(sloc);

	exit(0);
}
