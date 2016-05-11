#include <stdio.h>
#include <stdlib.h>

//there are many people in the world.
int lengthL(FILE*);
char* fileToStr(FILE*);
int find(char*, char*);
int findOffset(int, char*, char*);
int lengthS(char*);

int main(int argc, char const *argv[]) {
  FILE* fp;
  fp = fopen("lalla.txt", "r");
  char* str = fileToStr(fp);
  int i = find(str, "STOCK");
  int j = findOffset(i+1, str, "STOCK");
  printf("i: %i j: %i\n", i, j);
  return 0;
}

char* fileToStr(FILE* fp){
  int l = lengthL(fp);
  char* ch= malloc(l * sizeof(char));
  for (int i = 0; i < l; i++) {
    ch[i] = getc(fp);
    if(ch[i] == EOF){
      ch[i] = '\0';
      break;
    }
  }
  return ch;
}

int find(char* str1, char* str2){
  int i = 0;
  for (;;) {
    if(str1[i]=='\0'){
      break;
    }
    for (int j = 0; j < lengthS(str2); j++) {
      if(str1[i+j]!=str2[j]){
        break;
      }
      if(j==lengthS(str2)-1){
        return i;
      }
    }
    i++;
  }
  return -1;
}

int findOffset(int start, char* str1, char* str2){
  return find(&str1[start], str2);
}

int lengthL(FILE* fp){
  int length = 0;
  for(;;){
    length++;
    if(getc(fp) == EOF){
      rewind(fp);
      return length;
    }
  }
}

int lengthS(char* str){
  int l = 0;
  for (;;) {
    if(str[l]=='\0'){
      return l;
    }
    l++;
  }
}
