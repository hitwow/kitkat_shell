obj = main.o getinfo.o m_user.o m_inbuild.o m_input.o

kk_shell : $(obj)
	gcc -o kk_shell $(obj) -D READLINE_ON -I /usr/include -lreadline -ltermcap 

main.o : main.c m_user.h
	cc -g -c main.c
m_user.o : m_user.c m_user.h getinfo.h info.h
	cc -g -c m_user.c
getinfo.o : getinfo.c getinfo.h info.h
	cc -g -c getinfo.c
m_inbuild.o :m_inbuild.c info.h getinfo.h
	cc -g -c m_inbuild.c
m_input.o : m_input.c m_input.h m_inbuild.h
	cc -g -c m_input.c


.PHONY : clean
clean:
	rm kk_shell $(obj)
