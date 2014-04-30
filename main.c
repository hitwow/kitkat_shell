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
#include "info.h"

int main()
{
	init();

	while (1)
	{
        input();
        getcmd(cmd);
	}

	return 0;
}

