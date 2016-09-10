all:
	gcc -o vfork vfork.c
	gcc -o environ environ.c  
	gcc -o execve execve.c  
	gcc -o execve_script execve_script.c  
	gcc -o fork fork.c  
	gcc -o process process.c  
	gcc -o script_invoked script_invoked.c 
	gcc -o file_desc file_desc.c
	gcc -o pthread -pthread pthread.c
	gcc -o pthread_mutex -pthread pthread_mutex.c
	gcc -o pthread_mutex2 -pthread pthread_mutex2.c
clean:
	rm -rf vfork environ execve execve_script fork process script_invoked file_desc message.txt a.out pthread pthread_mutex pthread_mutex2
