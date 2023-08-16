#include<stdio.h>
#include<stdint.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


#define ID_LEN 11


typedef struct Person {
    char           name[100];
    char           id[ID_LEN];
    unsigned short birthYear;
    char           birthMonth[3];
    char           birthDay[3];
    char           gender;

}Person;
Person *person_arr;
size_t capacity, cur_size;


//Allocate memory for capacity Person
void* initArray(size_t capacity){
    return (Person*)malloc(capacity*sizeof(Person));
}


int addPerson(char *name, unsigned short birthYear, char *birthMonth, char *birthDay, char gender){
   
   if(cur_size == capacity){
        return -1;
    }
    size_t name_size = strlen(name)+1;
    strcpy(person_arr[cur_size].name, name);
    
    
    srand(time(NULL));
    size_t i =0;
    for(; i < ID_LEN-1; i++){
        int cur_symbol = rand()%52;
        if(cur_symbol <= 25){
            (person_arr+cur_size)->id[i] = 'A' + cur_symbol;
        }else if(cur_symbol > 25){
            (person_arr+cur_size)->id[i] = 'a' + cur_symbol-26;
        }  
    }
    (person_arr+cur_size)->id[i] = '\0';

    
    (person_arr+cur_size)->birthYear = birthYear;
    
    strcpy(person_arr[cur_size].birthMonth, birthMonth);
    
    strcpy(person_arr[cur_size].birthDay, birthDay);
    
    person_arr[cur_size].gender = gender;
   
    
    cur_size++; 

    return 1;
      
}
int removePerson(char *id){
    size_t i =0;
    for(; i < cur_size; i++){
        if(!strcmp((person_arr+i)->id, id))//Search for Person with id
        {
            break;
        }      
    }

    for(;i < cur_size-1; i++){
        memcpy((person_arr+i), (person_arr+i+1), sizeof(Person));
    }
    cur_size--;
    
    return 1;
}

//Read data for Person and add to array
void readPerson(){
    char           name[100];
    unsigned short birthYear;
    char           birthMonth[3];
    char           birthDay[3];
    char           gender;

    printf("Input name for Person:\n");
    scanf("%s", name);

    printf("Input Birth year for Person:\n");
    scanf("%hu", &birthYear);

    printf("Input Birth month for Person:\n");
    scanf("%s", birthMonth);
    
    printf("Input Birthday for Person:\n");
    scanf("%s", birthDay);
    
    printf("Input Gender{m,f} for Person:\n");
    scanf(" %c", &gender);
    

    if(addPerson(name, birthYear, birthMonth, birthDay, gender) == -1){
        printf("Array of Person is full!\n");
    }else{

        printf("Person %s is added to array!\n\n", name);
    }
    


}
//Печата данни за човек с определен идентификатор (id) на стандартния изход. При успех връща 0, а при неуспех връща -1.
int printPerson(char *id){
    for(size_t i = 0; i < cur_size; i++){

        if(!strcmp((person_arr+i)->id, id)){
            
            printf("ID: ");
            for(size_t j =0; j < ID_LEN; j++){
                
                printf("%c  ",(person_arr+i)->id[j]); 
            }
            
            printf("Name: ");
            printf("%s  ",(person_arr+i)->name);
            // size_t name_size = strlen((person_arr+i)->name);
            // for(size_t j =0; j < name_size; j++){
                
            //     printf("%c  ",(person_arr+i)->name[j]); 
            // }
            

            printf("Birth year: %hu  ", (person_arr+i)->birthYear);
    
            printf("Birth month: %s  ", (person_arr+i)->birthMonth);
   
            printf("Birth day: %s  ", (person_arr+i)->birthDay);
   
            printf("Gender: %c  ", (person_arr+i)->gender);

            printf("\n");
            
            return 0;
        }else{
            return -1;
        }
        
    }

    return -1;
}
//Helpful func
void print_Person_Array(void){
    for(size_t i = 0; i < cur_size; i++){
        printf("ID: ");
        printf("%s  ",(person_arr+i)->id);
        // for(size_t j =0; j < ID_LEN; j++){
                
        //     printf("%c",(person_arr+cur_size)->id[j]); 
        // }
        printf(" ");
            
        printf("Name: ");
        printf("%s  ",(person_arr+i)->name);
        // size_t name_size = strlen((person_arr+cur_size)->name);
        // for(size_t j =0; j < name_size; j++){
                
        //     printf("%c",(person_arr+cur_size)->name[j]); 
        // }
        printf(" ");
            

        printf("Birth year: %hu  ", (person_arr+cur_size)->birthYear);
    
        printf("Birth month: %s  ", (person_arr+cur_size)->birthMonth);
   
        printf("Birth day: %s  ", (person_arr+cur_size)->birthDay);
   
        printf("Gender: %c  ", (person_arr+cur_size)->gender);

        printf("\n");
    }

}

int main(){
    capacity = 2;
    person_arr = (Person*)initArray(capacity);
    if(person_arr == NULL){
        printf("Can not allocate memmory!\n");
        return 0;
    }

    cur_size = 0;
    for(size_t i = 0; i < capacity; i++){
        readPerson();
    }
    print_Person_Array();
    
    //printPerson(arr_id);
    //removePerson(arr_id);
    //printPerson(arr_id);



    free(person_arr);
    return 0;
}