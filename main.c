// fork() returns child's pid.
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){

 // fork first.
 int child1 = fork();
 int child2 = 0;
int w, status;

if(child1){
 printf("Parent Message\n");
 child2 = fork();
 }

if(child1 == 0 || child2 == 0){
  printf("Child %d starts\n", getpid());
  srand(time(NULL));
  int t = rand() %4 + 2;
  sleep(t);
  printf("Finish child: %d\n",getpid());
}else{

  w = wait(&status);
  printf("Child %d slept for %d\n", w, WEXITSTATUS(status));
  printf("End parent\n");
}

/*
 else{
  printf("parent process initial message...\n");
  childpid = fork();
  w = wait (&status); // returns child's pid.
  printf("");
 }
 */

}
