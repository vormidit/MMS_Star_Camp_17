#include<stdio.h>
#include<stdint.h>


typedef struct MyTime{
    uint16_t year;//year
    uint8_t month;//month
    uint8_t day;//day
    uint8_t hour;//hour
    uint8_t minutes;//minutes
    uint8_t seconds;//sec
}MyTime;

char *month_arr[]={"January","February","March",
                "April","May","June","July","August",
                "September","Octomber","November","December"};

int isLeapYear(MyTime t){
    if( t.year % 4 == 0){
        return 1;
    }else{
        return 0;
    }

}
int totalDaysInYear(MyTime t){
    if(isLeapYear(t)){
        return 366;
    }else{
        return 365;
    }

}
void printMonth(MyTime t){
        
    printf("Month: %s\n", month_arr[t.month-1]);

}
int secondsPassed(MyTime t){
    uint64_t unix_seconds;
    uint16_t total_days = 0;
    MyTime i;
    for(i.year = 1970; i.year < t.year; i.year++){
        total_days += totalDaysInYear(i);//Сумираме дните от предходните години
        
    }
    
    total_days += t.day-1;//Броим дните без текущия

    if(t.month >1){
        total_days += (t.month-1) * 30;
    }
    if(t.month > 2){
        total_days -= 2;
    }

    if(isLeapYear(t) && t.month > 2){
        total_days++;
    }
    if((t.month >= 2 && t.month <= 8) || t.month==10 || t.month==12){//Ако месеца е в тези граници има толкова месеца преди него с с 31 дни
        total_days += t.month/2;
    }
    if(t.month == 9){//Ако е 9ти има 5 месеца с 31 дни
        total_days += 5;
    }
    if(t.month == 11){//Ако е 11 има 6 месеца с 31 дена
        total_days += 6;
    }
    
    unix_seconds = t.seconds + t.minutes*60 + t.hour*3600 + total_days*24*3600;
    return unix_seconds;

}


int main(){

    printf("Size of struct MyTime: %lu\n", sizeof(MyTime));
    MyTime t = {.year=2023,.month=8, .day=1, .hour=21, .minutes=58, .seconds=0};
    if(isLeapYear(t)){
        printf("This year is leap!\n");
    }else{
        printf("This year is not leap!\n");
    }
    printf("Total days in year: %d\n", totalDaysInYear(t));
    printMonth(t);
    printf("Seconds passed from 1970: %d\n", secondsPassed(t));

   

    return 0;
}