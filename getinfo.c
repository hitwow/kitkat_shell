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

int init_user_info()
{
	struct passwd *uinfo;
	int flag = 0;

	uinfo = getpwuid(getuid());

	uname = uinfo->pw_name;
	upath = uinfo->pw_dir;
	uhost = (char*)malloc(HOSTLEN * sizeof(char));

	if (!uhost)
		return 1;

	gethostname(uhost, HOSTLEN);
	flag += get_shost();
	flag += get_uchar();

	if (flag)
		return 1;
	else
		return 0;
}

int init_path_info()
{
	tloc = (char*)malloc(LOCLEN * sizeof(char));

	if (!tloc)
		return 1;

	if (!getcwd(tloc, LOCLEN))
		return 1;

	return get_sloc();
}

int get_shost()
{
	int i;
	shost = (char*)malloc(HOSTLEN * sizeof(char));

	if (!shost)
		return 1;

	for (i=0; uhost[i]!='.'; i++)
		shost[i] = uhost[i];
	shost[i] = '\0';

	return 0;
}

void get_uchar()
{
	if (!strcmp(uname, "root"))
		uchar = '#';
	else
		uchar = '$';
}

int get_sloc()
{
	int i;

	sloc = (char*)malloc(SLOCLEN * sizeof(char));

	if (!sloc)
		return 1;

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

	return 0;
}

