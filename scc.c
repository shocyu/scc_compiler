#include <stdio.h>
#include <stdlib.h>

#define D_PRINT_TAB printf("  ");

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "number of arguments is not correct.\n");
    return 1;
  }

  char *p = argv[1];

  printf(".intel_syntax noprefix\n");
  printf(".globl _main\n");
  printf("_main:\n");
  D_PRINT_TAB
  printf("mov rax, %ld\n", strtol(p, &p, 10));

  while(*p){
    if(*p == '+'){
      p++;
      D_PRINT_TAB
      printf("add rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    if(*p == '-'){
      p++;
      D_PRINT_TAB
      printf("sub rax, %ld\n", strtol(p, &p, 10));
      continue;
    }

    fprintf(stderr, "error: unexpected input '%c'\n", *p);
    return 1;

  }

  printf("  ret\n");
  return 0;
}