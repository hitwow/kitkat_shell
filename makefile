obj = main.o getinfo.o m_user.o

kk_shell : $(obj)
	gcc -o kk_shell $(obj) -lreadline -ltermcap 

main.o : main.c m_user.h
	cc -g -c main.c
m_user.o : m_user.c m_user.h getinfo.h info.h
	cc -g -c m_user.c
getinfo.o : getinfo.c getinfo.h info.h
	cc -g -c getinfo.c

.PHONY : clean
clean:
	rm kk_shell $(obj)
