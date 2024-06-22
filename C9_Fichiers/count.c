#include <stdio.h>
#include <stdbool.h>

#define MAX 250

// *** TODO: counting functions
int countl(FILE* fin){

    int count = 0;
    char ligne [MAX];

    while(fgets(ligne,MAX,fin)!=NULL){
        count++;
    }
    return count ;
}
int countm (FILE* fin){

    int count = 0;
    char car ;
    bool isWord= false ;
    while((car=fgetc(fin))!=EOF){

        if(car!=' ' && !isWord){
            ++count;
            isWord = true ;
        }
        if(car==' '){
            isWord = false ;
        }
    }

    return count ;

}
int countc (FILE * fin){
    int count ;
    while(fgetc(fin)!=EOF){
        count++ ;
    }
    return count ;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

	FILE *fin;

    // *** TODO: open file
    fin=fopen(argv[1],"r");
    if(fin == NULL) {
        perror("ouverture de fichier impossible");
        return 1 ;
    }


    // count characters in file

    printf("%s contains %d lines\n", argv[1], countl(fin));

    fclose(fin);
    return 0;
}