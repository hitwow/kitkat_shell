/*
 * m_inbuild.h
 *
 *  Created on: 2014年3月22日
 *      Author: hitwow
 */

#ifndef M_INBUILD_H_
#define M_INBUILD_H_
#include "m_user.h"

typedef struct{
	char sc[CMDLEN];
	char tc[CMDLEN];
}alnode;

void pwd();
void cd(char*);
void sl_exit();
void echo(char*);
//void p_path(char *);
void help();
void inalias(char*, char*);
void alias();
void inhistory(char*);
void history();


#endif /* M_INBUILD_H_ */
