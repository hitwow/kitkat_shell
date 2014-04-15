/*
 * main.c
 *
 *  Created on: 2014年3月20日
 *      Author: hitwow
 */
#include <stdio.h>
#include <malloc.h>
#include "m_user.h"
#include "m_input.h"
#include "m_inbuild.h"

int main()
{
	char* cmd;

	init();

	while (1)
	{
		cmd = (char*)malloc(CMDLEN);
		show();
      input(cmd);
      inhistory(cmd);
		getcmd(cmd);
	}

	return 0;
}

