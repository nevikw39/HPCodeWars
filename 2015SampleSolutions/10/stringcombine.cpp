#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
#define ARR_SIZE 512
int compare(const void *a, const void *b){
	//int compare(char *a, char *b){
	char *p = (char *)a;
	char  *q=(char *)b;
	bool p_chk=false,q_chk=false;
	char *p_head=p, *q_head=q;
	while(1){
		if(*p>*q){
			return -1;
		}else{
			if(*p<*q){
				return 1;
			}
			else{
				if(*(p+1)=='\0'){
					p=p_head;
					p_chk=true;
				}else{
					p=p+1;
				}
				if(*(q+1)=='\0'){
					q=q_head;
					q_chk=true;
				}else{
					q=q+1;
				}
				if(q_chk==true && p_chk==true){
					return 0;
				}
			}
		}
	}
}
int bubble(char *buf[],int num){
	int i;
	int j;
	char *tmp;
	for (i=0;i<num;i++){
		for (j = 0; j < num-i-1; j++) {
			if(compare(buf[j], buf[j+1])==1){
			tmp=buf[0];
			buf[0]=buf[1];
			buf[1]=tmp;
			}
		}
	}
}

int insertion (char * array[],int num){
	int i;
	int j;
    char *tmp;
 for (i = 1 ; i <= num - 1; i++) {
    j = i;
    while ( j > 0 && compare(array[j], array[j-1])==-1) {
      tmp     = array[j];
      array[j]   = array[j-1];
      array[j-1] = 	tmp;
      j--;
    }
  }
}

int main()
{
	int num;
	char **buf;
	int i;
	char *ptr;

	while(cin >>num){

        buf=(char **) new char[sizeof(char*)*num+sizeof(char)*ARR_SIZE*num];
		ptr=(char *)buf+num*sizeof(char *);
		for (i=0;i<num;i++){
			ptr=ptr+ARR_SIZE*sizeof(char);
			buf[i]=ptr;
		}
        for (i=0;i<num;i++){
    		cin >> buf[i];
        }
        //cout <<"cmp="<<compare(buf[0], buf[1])<<endl;
        insertion(buf,num);
        for (i=0;i<num;i++){
            cout << buf[i] ;
        }
		cout <<  endl;
		delete [] buf;
}
	return 0;
}
