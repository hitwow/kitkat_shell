#include "m_user.h"
#include "getinfo.h"
#include "info.h"

#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <malloc.h>

int init ()
{
	int flag = 0;

    flag += init_user_info();
    flag += init_path_info();

    if (flag)
    	return 1;
    else
    	return 0;
}

void show ()
{
	printf("[%s@%s %s]%c ", uname, shost, sloc, uchar);
}

char* input()
{
    char* cmd = NULL;

	if (cmd)
	{
		free(cmd);
		cmd = NULL;
	}
	cmd = readline("");

	if (cmd&&*cmd)
	{
		add_history(cmd);
	}

    return cmd;
}

void output()
{

}
