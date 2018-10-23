#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Date {
    public:
        int num;
        int year;
        int month;
        int day;
        int hour;
        int minute;
        int second;
        Date(int num,int year,int month,int day,int hour,int minute,int second):num(num),year(year),month(month),day(day),hour(hour),minute(minute),second(second){};
};
int main() {
	int n;
	Date *min=new Date(0,9999,99,99,99,99,99);
	while(1){
		scanf("%d",&n);
		if (n==0) break;
        Date *current=new Date(0,0,0,0,0,0,0);
        current->num=n;
		scanf("%d/%d/%d %d:%d:%d",&current->year,&current->month,&current->day,&current->hour,&current->minute,&current->second);
        printf("cur is %d/%d/%d %d:%d:%d\n",current->year,current->month,current->day,current->hour,current->minute,current->second);
        printf("min is %d/%d/%d %d:%d:%d\n",min->year,min->month,min->day,min->hour,min->minute,min->second);
        
        if(min->num==0) {min=current;continue;}
        char time1[15], time2[15];
        sprintf(time1, "%04d%02d%02d%02d%02d%02d", current->year, current->month, current->day, current->hour, current->minute, current->second);
        sprintf(time2, "%04d%02d%02d%02d%02d%02d", min->year, min->month, min->day, min->hour, min->minute, min->second);
        if(atof(time1)<atof(time2))
            min=current;
        
	}
    if(min->num!=0)
        printf("The urgent schedule is No.%d: %d/%d/%d %d:%d:%d",min->num,min->year,min->month,min->day,min->hour,min->minute,min->second);
	return 0;
}
