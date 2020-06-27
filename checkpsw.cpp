#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>
#define MAX 1024 
int checkpsw(char *username, char *password) {
	FILE *f; 
    char user[MAX + 2], pass[MAX + 2], active[MAX + 2]; 
	/* printf(“%s,%s\n”,username,password); */ 
	if (!(f = fopen("userpwd", "r"))) { 
        perror("Open PASSWORD file error"); 
        printf("The password file not found\n"); 
        return -1;
    }
    while (!feof(f)) { 
        fscanf(f, "%s %s %s\n", user, pass, active); 
        //printf("user:%s pass:%s active:%s\n",user, pass, active); 
        if (strcmp(username, user)==0 && strcmp(password, pass)==0 && strcmp(active, "1")==0) { 
            fclose(f); 
            return 0 ; 
            //验证通过应该返回0; 
        } 
    } 
    fclose(f); 
    return 1; 
} 
int main() {
	int status; 
	/* printf(“%s,%s”,getenv(“USERNAME”),getenv(“PASSWORD”)); */ 
	status = checkpsw(getenv("USERNAME"), getenv("PASSWORD")); 
	return status; 
	}