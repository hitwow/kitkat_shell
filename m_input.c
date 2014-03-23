/*
 * m_input.c
 *
 *  Created on: 2014年3月22日
 *      Author: hitwow
 */
#include "m_input.h"
#include "m_inbuild.h"

#include <string.h>

void getcmd(char* cmd)
{
	char* para;
	int i = 0;

	while (cmd[i]!=' '&&cmd[i]!='\0')
		i++;

	cmd[i]='\0';
	para = cmd+i+1;
	docmd(cmd, para);
}

void docmd(char* cmd, char* para)
{
	if (!doinbuild(cmd, para))
		doexe(cmd, para);
}

int doinbuild(char* cmd, char* para)
{
	if (!strcmp(cmd, "pwd"))
		pwd();
	else if (!strcmp(cmd, "cd"))
		cd(para);
	else if (!strcmp(cmd, "echo"))
		echo(para);
	else if (!strcmp(cmd, "exit"))
		sl_exit();
	else if (!strcmp(cmd, "help"))
		help();
	else
		return 0;

	return 1;
}

void doexe(char* cmd, char* para)
{

}
