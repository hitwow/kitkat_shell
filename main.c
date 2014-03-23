/*
 * main.c
 *
 *  Created on: 2014年3月20日
 *      Author: hitwow
 */
#include <stdio.h>
#include "m_user.h"
#include "m_input.h"

int main()
{
	char* cmd;

	init();

	while (1)
	{
		show();
        cmd = input();
		getcmd(cmd);
	}

	return 0;
}

