#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "flightlist.h"
#include "personlist.h"
#include "routegraph.h"

#define ll long long
void displayMenu(Node* graph1,Flight f1,Person q1){
      int choice;         // user's menu choice

	do{
			printf("-----------------------------------------------");

			printf("\n\t AIRLINE RESERVATION SYSTEM \n\n");
			printf("Please pick an option from the menu below. \n");
			printf("1. Display flight schedule \n");
			printf("2. Display flight details \n");
			printf("3. Display passenger personal info \n");
			printf("4. Book reservation \n");
			printf("5. Cancel reservation \n");
			printf("6. Press any number other than 1..5 to exit \n\n");

			printf("-----------------------------------------------\n");

			printf("Enter the number of a menu option: ");
			scanf("%d",&choice);
			// check validity of input
			if((choice<=0)||(choice>=6))
                continue;

	
	int pass,flno;
	 char* name,*nation;

	switch(choice){
		
		case 1:	DisplayFlist(f1);
				break;
		case 2:	printf("Enter the flight number:");
				scanf("%d",&flno);
				DisplayFDetails(f1,flno);
				break;
		case 3:	printf("Enter your passport number:");
				scanf("%d",&pass);
				DisplayPDetails(q1,pass);
				break;
		case 4:	
				name=(char*)malloc(sizeof(char)*30);
				nation=(char*)malloc(sizeof(char)*30);
				ll phno;
				int cost;

				printf("Enter your full name:");
				scanf(" %[^\n]",name);
				printf("Enter your nationality:");
				scanf(" %s",nation);
				printf("Enter your passport number:");
				scanf("%d",&pass);
				printf("Enter your phone number:");
				scanf("%lld",&phno);
				printGraph(graph1);				
				
				int src, dest;
				printf("SELECT CITY OF DEPARTURE\n1.  MAA \n2.  DEL \n3.  BOM \n4.  BLR \n5.  CCU \n");
				scanf("%d", &src);
				printf("SELECT DESTINAION CITY\n1.  MAA \n2.  DEL \n3.  BOM \n4.  BLR \n5.  CCU \n");
				scanf("%d", &dest);
				switch (checkcon(graph1, src - 1, dest - 1))
				{
				case 0:
					printf("There are no direct flight from %s to %s\n", city[src-1], city[dest-1]);
					printf("You may need to take a conneting flight via %s\n", city[findRoute(graph1, src - 1, dest - 1)]);
					printf("A direct flight is available for your journey and the flight no is %d\n", flightNo(graph1, src - 1,findRoute(graph1,src-1,dest-1)));
					printf("A direct flight is available for your journey and the flight no is %d\n", flightNo(graph1, findRoute(graph1,src-1,dest-1), dest - 1));
					cost=fare(graph1, src - 1, dest - 1);
					printf("The fare for your journey is %d\n", cost);
					break;
				case 1:
					printf("A direct flight is available for your journey and the flight no is %d\n",flightNo(graph1,src-1,dest-1));
					cost=fare(graph1, src - 1, dest - 1);
					printf("The fare for your journey is %d\n", cost);
					break;
				default:
					break;
				}
				addBooking(q1,name,nation,flno,pass,phno,cost);

				break;
		case 5:	printf("Enter your passport number:");
				scanf("%d",&pass);
				cancelBooking(q1,pass);
				break;
	}

	}while((choice>0)&&(choice<6));
}



int main(){
	Node* graph1 = initgraph(graph1);
	Flight f1=initflights();
	Person q1=initPersons();
	displayMenu(graph1,f1,q1);
	return 0;
}