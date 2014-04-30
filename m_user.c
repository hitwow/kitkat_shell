#include "m_user.h"
#include "getinfo.h"
#include "info.h"
#include "m_inbuild.h"

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <readline/readline.h>

void init ()
{
    init_user_info();
    init_path_info();
    init_history();
    init_show();
}


void input()
{
    char* tcmd = NULL;
	tcmd = readline(show);
    
    if ((tcmd!=NULL)&&(&tcmd!=NULL))
    {
        add_history(tcmd);
        inhistory(tcmd);
    }

    p_cmd(tcmd);
}

void p_cmd(char* tcmd)
{
    int i, j;
    cmd = (char*)malloc(CMDLEN);

    for (i=0, j=0; i<strlen(tcmd); i++)
    {
        if (tcmd[i] == '~')
        {
        	cmd[j] = '\0';
            strcat (cmd, upath);
            j += strlen(upath);
        }
        else
        {
            cmd[j] = tcmd[i];
            j++;
        }
    }
    cmd[j] = '\0';
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

void init_show()
{
    show = (char*)malloc(100);
    sprintf(show, "[kk_shell][%s@%s %s]%c ", uname, shost, sloc, uchar);
}
