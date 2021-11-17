// fork() returns child's pid.
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
int main(){

 /. fork first. 
 int childpid = 1;
 int wait, status;

if(childpid == 0){
 printf("print child pid: %d\n", childpid);
 sleep(2); // change to random sec later
 }else{
  printf("parent process initial message...\n");
  childpid = fork();
  w = wait (&status); // returns child's pid. 
  printf("");
 }
 
}
