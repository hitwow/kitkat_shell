/*
 * m_input.c
 *
 *  Created on: 2014年3月22日
 *      Author: hitwow
 */
#include "m_input.h"
#include "m_inbuild.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void getcmd(char* cmd)
{
	char* para[PARNUM] ={NULL};
	int i = 0;
	int pnum = 0;

	para[0] = cmd;
	while (cmd[i]!='\n')
	{
		if (cmd[i]==' ')
		{
			cmd[i] = '\0';
			para[++pnum] = cmd+i+1;
		}
		i++;
	}

	cmd[i] = '\0';
	docmd(para[0], para);
}

void docmd(char* cmd, char** para)
{
	if (!doinbuild(cmd, para))
		doexe(cmd, para);
}

int doinbuild(char* cmd, char** para)
{
	if (!strcmp(cmd, "pwd"))
		pwd();
	else if (!strcmp(cmd, "cd"))
		cd(para[1]);
	else if (!strcmp(cmd, "echo"))
		echo(para[1]);
	else if (!strcmp(cmd, "exit"))
		sl_exit();
	else if (!strcmp(cmd, "help"))
		help();
	else
		return 0;

	return 1;
}

void doexe(char* cmd, char** para)
{
	if (fork()!=0)
		wait(NULL);
	else
		execvp(cmd, para);
}
