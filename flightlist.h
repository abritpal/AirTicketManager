typedef struct node* Flight;
typedef struct time time;

struct time{
	int min;
int hr;
};
struct node{
    char* from;
    char* to;
    int flno;
    time arriv;
    time dept;
    int totalseats;
    int seatsfilled;
    struct node *next;
};

Flight createFNode(){
	Flight new=(Flight)malloc(sizeof(struct node));
    new->from=(char *)malloc(sizeof(char)*15);
    new->to=(char *)malloc(sizeof(char)*15);
	new->next=NULL;
	return new;
}

void addFlight(Flight list,char* from,char* to,int flno,time arriv,time dept,int totalseat,int seatsfilled){
	
    Flight f=createFNode();
    strcpy(f->from,from);
    strcpy(f->to,to);
    f->flno=flno;
    f->arriv.hr=arriv.hr;
    f->arriv.min=arriv.min;
    f->dept.hr=dept.hr;
    f->dept.min=dept.min;
    f->totalseats=totalseat;
    f->seatsfilled=seatsfilled;
	
	Flight tr=list;
	while(tr->next!=NULL)
		tr=tr->next;
	f->next=tr->next;
	tr->next=f;
    
}

void DisplayFlist(Flight list){
    printf("\n\n\t\t\t\t\t\tFLIGHT DETAILS\n");
    printf("____________________________________________________________________________________________________________________\n");
    printf("Flight No.\tArrival Time   Departure Time   From\t\tTo\t\tTotal Seats\tAvailable Seats\n");
    printf("____________________________________________________________________________________________________________________\n");
    for(Flight t1=list->next;t1!=NULL;t1=t1->next)
        printf("%d\t\t%02d:%02d\t\t%02d:%02d\t\t%s\t\t%s\t\t%d\t\t%d\n",t1->flno,t1->arriv.hr,t1->arriv.min,t1->dept.hr,t1->dept.min,t1->from,t1->to,t1->totalseats,t1->totalseats - t1->seatsfilled);
    
}

void DisplayFDetails(Flight list,int flno){
    
    for(Flight t1=list->next;t1!=NULL;t1=t1->next)
        if(t1->flno==flno){
            printf("\n\n\t\t\t\t\t\tFLIGHT DETAILS\n");
            printf("____________________________________________________________________________________________________________________\n");
            printf("Flight No.\tArrival Time   Departure Time   From\t\tTo\t\tTotal Seats\tAvailable Seats\n");
            printf("____________________________________________________________________________________________________________________\n");
            printf("%d\t\t%02d:%02d\t\t%02d:%02d\t\t%s\t\t%s\t\t%d\t\t%d\n\n",t1->flno,t1->arriv.hr,t1->arriv.min,t1->dept.hr,t1->dept.min,t1->from,t1->to,t1->totalseats,t1->totalseats - t1->seatsfilled);
            return;
        }
    
    printf("Sorry no flights found with Flight No.=%d\n",flno);
}

Flight initflights()
{
	Flight q1=createFNode();
    time arr,dep;
    arr.hr=1;
    arr.min=30;
    dep.hr=2;
    dep.min=15;
    addFlight(q1,"MAA","DEL",123,arr,dep,180,75);
    arr.hr=3;
    arr.min=20;
    dep.hr=4;
    dep.min=5;
    addFlight(q1,"DEL","MAA",143,arr,dep,180,55);
    arr.hr=05;
    arr.min=15;
    dep.hr=5;
    dep.min=45;
    addFlight(q1,"MAA","BOM",456,arr,dep,180,65);
    arr.hr=9;
    arr.min=45;
    dep.hr=10;
    dep.min=25;
    addFlight(q1,"BOM","MAA",466,arr,dep,180,78);
    arr.hr=10;
    arr.min=30;
    dep.hr=12;
    dep.min=15;
    addFlight(q1,"MAA","CCU",789,arr,dep,150,65);
    arr.hr=11;
    arr.min=20;
    dep.hr=11;
    dep.min=45;
    addFlight(q1,"CCU","MAA",729,arr,dep,150,74);
    arr.hr=13;
    arr.min=10;
    dep.hr=13;
    dep.min=55;
    addFlight(q1,"DEL","BLR",642,arr,dep,180,87);
    arr.hr=14;
    arr.min=30;
    dep.hr=15;
    dep.min=15;
    addFlight(q1,"BLR","DEL",612,arr,dep,180,35);
    arr.hr=15;
    arr.min=40;
    dep.hr=16;
    dep.min=15;
    addFlight(q1,"DEL","CCU",406,arr,dep,150,65);
    arr.hr=17;
    arr.min=30;
    dep.hr=18;
    dep.min=05;
    addFlight(q1,"CCU","DEL",416,arr,dep,150,55);
    return q1;
}


