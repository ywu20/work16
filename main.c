
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){


 int child1 = fork();
 int child2;


if(child1){
 printf("Parent Message\n");
 child2 = fork();

 }

if(child1 == 0 ||  child2==0){
  printf("Child %d starts\n", getpid());
  srand(time(NULL));
  int t= rand() %4 + 2;
  sleep(t);
  printf("Finish child: %d\n",getpid());
  return t;
}
else{
  int w, status;
  w = wait(&status);
  printf("Child %d slept for %d\n", w, WEXITSTATUS(status));
  printf("End parent\n");
  return 0;
}


}
