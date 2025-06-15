#include<stdio.h>



int stringSize(char* str){
    int size = 0;
    while(*str != '\0') {
        size++;
        *str++;
    }

    return size;
}

int main(int argc, char* argv[]) {
  
    if (argc != 2) return 1;

    //printf("%s\n", argv[1]);
    //printf("%d\n", stringSize(argv[1]));
    int i = stringSize(argv[1]);
    int slash_1 = 0;
    int slash_2 = 0;
        
    for (; i >= 0; i--) {
        int slash_count = 0;
        if(argv[1][i] == '/') {
            if(slash_2 == 0)
                slash_2 = i;
            else {
                slash_1 = i;
                break;
            }
        }
    }

    //printf("%d %d", slash_1, slash_2);

    for (int i = slash_1 + 1; i < slash_2; i++ ) {
        printf("%c", argv[1][i]);
    }



    return 0;
}
