#include <stdio.h>

int main() {
  char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  printf("Input shift amount\n");
  int shift;
  scanf("%d", &shift);
  
  char ifile[30];
  
  printf("Enter input file name\n");
  
  scanf("%s", ifile);
  
  FILE *in = fopen(ifile, "r");
  
  printf("Input destination file\n");
  
    char ofile[30];
  
  scanf("%s\n", &ofile);
  

  
  FILE *out = fopen(ofile, "w");
  
  int c;
  
  while ((c = fgetc(in)) != EOF) {
    int i;
    for (i = 0; i < 62; i++) 
      if (c == a[i]) {
	c = a[(i  + shift) % 62];
	break;
      }
    
    fprintf(out, "%c", c);
  }
  fclose(in);
  fclose(out);
}