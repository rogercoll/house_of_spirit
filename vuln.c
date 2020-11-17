/* vuln.c
House of Spirit vulnerable program
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void fvuln(char *str1, int age)
{
   char *ptr1, name[44];
   int local_age;
   char *ptr2;
   local_age = age; /* Prereq 2 */

   ptr1 = (char *) malloc(256);
   printf("\nPTR1 = [ %p ]", ptr1);
   strcpy(name, str1); /* Prereq 1 */
   printf("\nPTR1 = [ %p ]\n", ptr1);
   free(ptr1); /* Prereq 2 */

   ptr2 = (char *) malloc(40); /* Prereq 3 */
   snprintf(ptr2, 40-1, "%s is %d years old", name, local_age); /* Prereq 4 */
   printf("\n%s\n", ptr2);
}

int main(int argc, char *argv[])
{
   int i=0;
   int stud_class[10];  /* Required since nextchunk size should lie in between 8 and arena's system_mem. */
   for(i=0;i<10;i++)
        stud_class[i] = 10;
   if (argc == 2)
      fvuln(argv[1], 25);
   return 0;
}
