#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char **argv){
    printf("Checking the parentheses in argv arguments\n");
    int i,N,j,check=0;
    char n;
    Stack s;
    s.size = 0;
    s.top = NULL;
    
  // ใน repl ใช้ () ไม่ได้
  // ใช้แต่ [],{}
 
    for(i=1;i<argc;i++){
        for(j=0;j<strlen(argv[i]);j++){
            switch (argv[i][j]){
            case '{':
                push(&s,'{');
                break;
            
            case '[':
                push(&s,'[');
                break;
            
            case ']':
                n = pop(&s);
                if(n != '['){
                    check = 1;
                }
                break;

            case '}':
                n = pop(&s);
                if(n!='{'){
                    check=1;
                }
                break;
            }
            if(check==1){
                break;
            }
        }
        printf("\n========================================================\n");
        printf("\nThe size is : %d and check : %d\n",s.size,check);
        if(s.size!=0 || check==1){
            printf("The parentheses do not match for '%s'\n",argv[i]);
        }
        else{
            printf("The parentheses match successfully for '%s'\n",argv[i]);
        }
        check =0;
        s.size =0;
        pop_all(&s);
        printf("\n========================================================\n");
    }

return 0;
}
