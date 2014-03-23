/*
 * getinfo.c
 *
 *  Created on: 2014年3月20日
 *      Author: hitwow
 */
#include "getinfo.h"
#include "info.h"

#include <pwd.h>
#include <sys/types.h>
#include <malloc.h>
#include <unistd.h>
#include <string.h>

void init_user_info()
{
	struct passwd *uinfo;

	uinfo = getpwuid(getuid());

	uname = uinfo->pw_name;
	upath = uinfo->pw_dir;
	uhost = (char*)malloc(HOSTLEN * sizeof(char));

	gethostname(uhost, HOSTLEN);
	get_shost();
	get_uchar();
}

void init_path_info()
{
	tloc = (char*)malloc(LOCLEN * sizeof(char));

	getcwd(tloc, LOCLEN);

	get_sloc();
}

void get_shost()
{
	int i;
	shost = (char*)malloc(HOSTLEN * sizeof(char));

	for (i=0; uhost[i]!='.'; i++)
		shost[i] = uhost[i];
	shost[i] = '\0';
}

void get_uchar()
{
	if (!strcmp(uname, "root"))
		uchar = '#';
	else
		uchar = '$';
}

void get_sloc()
{
	int i;

	sloc = (char*)malloc(SLOCLEN * sizeof(char));

	if (!strcmp(upath, tloc))
		sloc = "~";
	else if (!strcmp(tloc, "/"))
		sloc = "/";
	else
	{
		for (i=strlen(tloc); tloc[i]!='/'; i--);
		i++;
		strcpy(sloc, tloc+i);
	}
}

