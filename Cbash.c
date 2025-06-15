#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main() {

  //printing to the console
  system("echo No more bash scripts lmaoooooo");
  system("fastfetch");

  //printing a c variable
  int x = 10*32;
  char str[32];
  char command[] = "echo ";
  sprintf(str, "%d", x);
  strcat(command, str);
  system(command);
  
  //executing a fish alias is not possible
  system("goonfetch");
  system("fish sh ~/Templates/imagefetch.sh ~/Pictures/The_Repo");

  //reading from a command
  int y = system("echo 32");
  printf("%d", y);


  return 0;
}
