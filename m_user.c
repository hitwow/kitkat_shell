#include "m_user.h"
#include "getinfo.h"
#include "info.h"

#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <malloc.h>

void init ()
{
    init_user_info();
    init_path_info();
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
