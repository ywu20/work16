
#include<stdio.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
srand(time(NULL));
 int child1 = fork();
 int child2 = 0;
int w, status;
 
if(child1){
 printf("Parent Message\n");
 child2 = fork();
 }

if(child1 == 0 || child2 == 0){
  printf("Child %d starts\n", getpid());
 
  int t = rand() %4 + 2;
  sleep(t);
  printf("Finish child: %d ,%d\n",getpid(),t);
  return t;
}else{
for(int i=0;i<2;i++){
  w = wait(&status);
  printf("Child %d slept for %d\n", w, WEXITSTATUS(status));
  }
  printf("End parent\n");
}

}
