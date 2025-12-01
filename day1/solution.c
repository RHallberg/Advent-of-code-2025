#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

  if(argc < 2) return 1;

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) return 1;
  char row[6];
  int pos = 50;
  int sum1 = 0;
  int sum2 = 0;
  while(fgets(row,sizeof(row), fp)){
    int direction = row[0] == 'L' ? -1 : 1;
    row[0] = '0';
    int num = atoi(row) * direction;
    int movement = pos + num;
    if(movement <= 0 && pos != 0) sum2++;
    sum2 += abs(movement/100);
    pos = (((pos + num) % 100) + 100) % 100;
    if(pos == 0) sum1++;
  }
  printf("%d\n", sum1);
  printf("%d\n", sum2);
}
