typedef struct pernode* Person;
#define ll long long 

struct pernode{
    char* name;
    char* nationality;
    int flno;
    int passport;
    ll phoneno;
    int cost;
    char seatno[3];
    struct pernode *next;
};

char *generateSeatNo(int flno){
    char *sno=(char*)malloc(sizeof(char)*3);
    if(flno==123||flno==143||flno==456||flno==466||flno==642||flno==612)
        sprintf(sno,"%02d%c",(rand()%30+1),((char)(97+rand()%6)));
    else if(flno==789||flno==729||flno==416||flno==406) 
        sprintf(sno,"%02d%c",(rand()%25+1),((char)(97+rand()%6)));
    return sno;
}

Person initPersons(){
	Person new=(Person)malloc(sizeof(struct pernode));
    new->name=(char *)malloc(sizeof(char)*15);
    new->nationality=(char *)malloc(sizeof(char)*15);
	new->next=NULL;
	return new;
}

void addBooking(Person list,char* name,char* nationality,int flno,int passno,ll phnno,int cost){
	
    Person f=initPersons();
    strcpy(f->name,name);
    strcpy(f->nationality,nationality);
    f->flno=flno;
	f->passport=passno;
    f->phoneno=phnno;
    f->cost=cost;
    strcpy(f->seatno,generateSeatNo(f->flno));
    Person tr=list;
	while(tr->next!=NULL)
		tr=tr->next;
	f->next=tr->next;
	tr->next=f;
   
}

void cancelBooking(Person list,int passno){
    Person tr=list;
    while(tr->next->passport!=passno)
        tr=tr->next;
    
    Person temp=tr->next;
    tr->next=temp->next;
    temp->next=NULL;
    free(temp);

}

void DisplayPDetails(Person list,int pass){
    for(Person t1=list->next;t1!=NULL;t1=t1->next){
        if(t1->passport==pass){
            printf("\n\n\t\t\tPASSENGER DETAILS\n");
            printf("_____________________________________________________________________________________\n");
            printf("Passport No.    %5s\t\tNationality\tFlight No.\tSeat No.\tPrice\n","Name");
            printf("______________________________________________________________________________________\n");
            printf("%d\t%15s\t%15s \t%d\t\t%s\t\t%d\n\n",t1->passport,t1->name,t1->nationality,t1->flno,t1->seatno,t1->cost);
            return;
        }
    }
    printf("Sorry No Passengers found.\n");
}
