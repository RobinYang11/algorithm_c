
#include <stdio.h>
#define FALSE 0;

struct Student
{
  char *name;
  int age;
  char *address;
  float score;
};

int main(){
  struct Student robin;
  robin.name="robin";
  robin.age=22;
  robin.address="ningxia";
  robin.score=134.f;

  printf("%s",robin.name);

  //结构题数组
  struct Student students[5];

  for(int i = 0 ;i<5 ;i++) 
  {
    students[i].name="robin";
    students[i].age=22;
    students[i].address="nx";
    students[i].score=23.2f;
  }

  // 结构题指针
  struct Student *dvid;

  struct Student _dvid ={
    "name",
    22,
    "nx",
    12.f
  } ;

  dvid = &_dvid;

  printf("%s",dvid->name);
  printf("%d",dvid->age);
  printf("%s",dvid->address);
  printf("%f",dvid->score);

  return FALSE;
}

