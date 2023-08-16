/*Даден е следния бинарен файл: https://file.io/D5ZZg4G6AvQ0.
В него е записана информация за 1000 студента. Информацията за един студент се пази със следната структура:

struct Student {
	char name[16];
	double avg_grade;
};


Даденият файл е създаден с единствено извикване на fwrite:
fwrite(s, sizeof(Student), 1000, f1);
s е масив с 1000 инициализирани елемента от тип Student. 
f1 е указател към структура от тип FILE.

Реализирайте програма, която прочита съдържанието на файла и изпечатва информация за ученика с най-висок avg_grade.

Подсказки: 
Ползвайте fread за да прочетете информацията за всеки студент.
ghex file_name
*/
#include<stdio.h>
#include<stdlib.h>

#define STUDENTS_CNT 1000

struct Student {
	char name[16];
	double avg_grade;
};

int main(){
	struct Student student_array[STUDENTS_CNT];
    double highest_avg_grade = 0;
	size_t index_highest_avg_grade;
	FILE *f = fopen("students.bin", "r");
	if(!f){
        perror("Error opening file!");
        exit(-1);
	}

	for(size_t i = 0; i < STUDENTS_CNT; i++){
		if(fread((student_array+i), sizeof(struct Student), 1, f) == 1){
			if(student_array[i].avg_grade > highest_avg_grade){
				highest_avg_grade = student_array[i].avg_grade;
				index_highest_avg_grade = i;
			}
		}else{
			perror("Error with reading file!\n");
            exit(-1);
		}
		
	}
    fprintf(stdout, "Name of Student: %s, Avg. Grade: %.2lf\n", student_array[index_highest_avg_grade].name, student_array[index_highest_avg_grade].avg_grade);
	


    fclose(f);
	return 0;
}

