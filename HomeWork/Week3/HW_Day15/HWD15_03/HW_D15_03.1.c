#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STUDENTS_CNT 1000

struct Student {
	char name[16];
	double avg_grade;
};

int main(){
	struct Student s[STUDENTS_CNT];
    char *names[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", 
                    "J", "K", "L", "M", "N", "O", "P", "Q", "R", 
                    "S", "T", "U", "V", "W", "X", "Y", "Z"
                    };
    
	FILE *f1 = fopen("students.bin", "w");
    if(!f1){
        perror("Error opening file!");
        exit(-1);
    }
	for(size_t i = 0; i < STUDENTS_CNT; i++){
        strcpy(s[i].name, names[rand()%26]);
        s[i].avg_grade = (200 + rand()%401)/100.;
			
	}

    if(fwrite(s, sizeof(struct Student), 1000, f1) != STUDENTS_CNT){
        perror("Error with writing file!\n");
        exit(-1);
    }

    fclose(f1);
	return 0;
}