#include "m_user.h"
#include "getinfo.h"
#include "info.h"

#include <stdio.h>
#include <string.h>
#include <malloc.h>

void init ()
{
    init_user_info();
    init_path_info();
    init_history();
}

void show ()
{
	printf("[kk_shell][%s@%s %s]%c ", uname, shost, sloc, uchar);
}

void input(char* cmd)
{
    memset(cmd, '\0', CMDLEN);
	fgets(cmd, CMDLEN-1, stdin);
    p_cmd(cmd);
}

void p_cmd(char* cmd)
{
    char ncmd[CMDLEN] = "\0";
    int i, j;

    for (i=0, j=0; i<strlen(cmd); i++)
    {
        if (cmd[i] == '~')
        {
        	ncmd[j] = '\0';
            strcat (ncmd, upath);
            j += strlen(upath);
        }
        else
        {
            ncmd[j] = cmd[i];
            j++;
        }
    }

    strcpy(cmd, ncmd);
}

void init_history()
{
	FILE* fp;
	char* tmp;
	int i;

	hispos = 0;
	hisnum = 10;
	fp = fopen("history", "ab+");

	histable = (char**)malloc(hisnum*4);
	for (i=0; i<hisnum; i++)
		histable[i] = NULL;

	tmp = (char*)malloc(CMDLEN);
	while (fread(tmp, 100, 1, fp))
	{
		histable[hispos++] = tmp;
		tmp = (char*)malloc(CMDLEN);
		if (hispos==hisnum)
			hispos = 0;
	}

	fclose(fp);
}
