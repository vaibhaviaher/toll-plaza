//============================================================================
// Name        : project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class node                               	//class for declaring data members
{
	string type;
	string plateno;
    int price;
	node *next;
public:
	friend class toll;
	node(string n, string c,int p)	       //parameterized constructor
	{
		type=n;
		plateno=c;
		price=p;
		next=NULL;
	}
};

class toll		                         //class for declaring functions
{
	node *start;
public:
    toll()		                        //default constructor
	{
		start=NULL;
	}
	void accept();
	void total();                     //declared functions as per requirement
	void search();
	void count();
	void individual_count();
};

void toll::accept()                    //function definiton of accept function
{
	int price,flag=0;
	node *ptr=NULL;                   //accepted details of vehicle such as plate no.,type
	int bno,q;                       //and then adding price according to the conditions including validations
	string type,plateno;            ////by creating a new node each time and then displaying the receipt
	char ch;
    {
	do
	{
		do
		{
	        cout<<"\n Enter booth number according to vehicle type \n 1:Car/Jeep\n 2:Tractor/minibus \n 3:bus/truck \n 4:Oversized vehicle";
	        cin>>bno;
		}while(bno<1||bno>4);

	if(bno==1)
	{
		do
		{
			flag=0;
		    cout<<"\n Enter the vehicle type: \n car/jeep ";
		    cin>>type;
		//cin.ignore();
		//getline(cin,type);

		if(type=="car"||type=="jeep")
		{
			flag=1;                          //validation
			break;
		}

		if(flag==0)
		{
			cout<<"\n Invalid vehicle type!!";
        }
		}while(flag==0);
    }

	else if(bno==2)
	{
		do
		{
		cout<<"\n Enter the vehicle type: \n tractor/minibus";
		cin>>type;
		//cin.ignore();
		//getline(cin,type);

		if(type=="tractor"||type=="minibus")
		{
		    flag=1;
			break;
		}
        if(flag==0)
		{
			cout<<"\n Invalid vehicle type!!";
		}
		}while(flag==0);
	}

	else if(bno==3)
	{
		do
		{
		cout<<"\n Enter the vehicle type: \n bus/truck";
		cin>>type;
		//cin.ignore();
		//getline(cin,type);

		if(type=="truck"||type=="bus")
		{
			 flag=1;
			 break;
		}
        if(flag==0)
		{
			 cout<<"\n Invalid vehicle type!!";
        }
		}while(flag==0);
    }

	else if(bno==4)
	{
		//cout<<"\n oversized vehicle";
		//cin>>type;
		type="oversized";
	}
	}while(bno>5||bno==0);


		cout<<"\n Enter number plate of the vehicle:";
		cin.ignore();
		getline(cin,plateno);
		//cin>>plateno;


        cout<<"\n Do you have VIP Pass? (y/n)";
		cin>>ch;

		if(ch=='n'||ch=='N')
		{
			do
			{
		       cout<<"\n Is it:\n 1:Single journey!  \n 2:Return journey!";
		       cin>>q;
			}while(q<1||q>2);
		switch(q)
		{
		case 1:

			    if(type=="car"||type=="jeep")
				{
					price=50;
            	}
                else if(type=="tractor"||type=="minibus")
				{
					price=75;
				}
				else if(type=="bus"||type=="truck")
				{
					price=160;
				}
				else if(type=="oversized")
				{
					price=300;
			    }
                //cout<<"price="<<price;
			    break;

		case 2:
			    if(type=="car"||type=="jeep")
				{
					price=75;
                }
                else if(type=="tractor"||type=="minibus")
				{
					price=115;
				}
				else if(type=="bus"||type=="truck")
				{
					price=240;
			    }
				else if(type=="oversized")
				{
					price=455;
				}
			//cout<<"price="<<price;

			break;

		default:
			cout<<" Enter a valid choice:";
			break;
		}

		cout<<"\n_________________________________________";
		cout<<"\n";
		cout<<"\n\tPune-Mumbai Highway Toll Plaza";
		cout<<"\n_________________________________________";
		cout<<"\n";
		cout<<"\n Number Plate"<<"\t :"<<plateno;                          //displaying receipt
		cout<<"\n Vehicle Type"<<"\t :"<<type;
		cout<<"\n Amount in Rs."<<"\t :Rs."<<price;
		cout<<"\n";
		cout<<"\n !!!Wish you a HAPPY JOURNEY!!!";
		cout<<"\n";
		cout<<"\n NOTE: 1)TICKET IS VALID FOR 24 HOURS.";
		cout<<"\n       2)MUST CARRY WHILE RETURN JOURNEY.";
		cout<<"\n_________________________________________";
        }

		else if(ch=='y'||ch=='Y')
		{
			price=0;
			cout<<"\n *No toll for VIP vehicles*";
			cout<<"\n\n !!!Wish you a HAPPY JOURNEY!!!";
		}
        }


		node *temp=new node(type,plateno,price);
		if(start==NULL)
		{
			start=temp;                                   //creating a node
		}
		else
		{
            for(ptr=start;ptr->next!=NULL;ptr=ptr->next)
			{

			}
			ptr->next=temp;
		}
}

void toll::total()                            //function definiton of total function
{
	 int sum=0;
	 node* ptr=start;
     while(ptr!=NULL)
	 {                                         //Total money collected by all vehicles passed through the toll
	    sum=sum+ptr->price;
	    ptr=ptr->next;
     }
	 cout<<"\n Total money collected: Rs "<<sum;
}

void toll::count()                               //function definiton of count function
{
	node* ptr=start;
	int h;                                       //Total number of vehicles passed through the toll
	while(ptr!=NULL)
	{
		h++;
		ptr=ptr->next;
	}
	cout<<"\n Total number of vehicles passed till now are:"<<h;
}

void toll::individual_count()                    //function definiton of individual count function
{
	node* ptr=start;
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0;
    while(ptr!=NULL)
	{
		if(ptr->type=="car")
		{
              a++;
			  ptr=ptr->next;                 //Individual count of respective vehicles
		}
        else if(ptr->type=="jeep")
		{
			  b++;
			  ptr=ptr->next;
	    }
        else if(ptr->type=="tractor")
		{
			  c++;
			  ptr=ptr->next;
		}
        else if(ptr->type=="minibus")
		{
			  d++;
			  ptr=ptr->next;
		}
        else if(ptr->type=="bus")
		{
			  e++;
			  ptr=ptr->next;
		}
        else if(ptr->type=="truck")
		{
			  f++;
			  ptr=ptr->next;
		}
        else if(ptr->type=="oversized")
		{
			  g++;
			  ptr=ptr->next;
	    }
     }

        int x;
		do
		{
			cout<<"\n Select the vehicle whose count you need:";
			cout<<"\n 1:Car\n 2:Jeep\n 3:Tractor\n 4:Minibus\n 5:Bus\n 6:Truck\n 7:Oversized\n 8:Exit";
			cin>>x;
			switch(x)
			{
			case 1:
				cout<<"\n Total number of cars that passed till now are: "<<a;
				break;
			case 2:                                                                //displaying count using switch case
				cout<<"\n Total number of jeeps that passed till now are: "<<b;
				break;
			case 3:
				cout<<"\n Total number of tractors that passed till now are: "<<c;
				break;
			case 4:
				cout<<"\n Total number of minibuses that passed till now are: "<<d;
				break;
			case 5:
				cout<<"\n Total number of buses that passed till now are: "<<e;
				break;
			case 6:
				cout<<"\n Total number of trucks that passed till now are: "<<f;
				break;
			case 7:
				cout<<"\n Total number of oversized vehicles that passed till now are: "<<g;
				break;
			case 8:
				break;
			default:
				cout<<"\n Enter valid choice";
				break;
		}
       }while(x!=8);
}

int main()
{
	toll t;
	int num;
	char ch;
	node *ptr;

	{                              //displaying board of price details
	cout<< "\n___________________________________________________________________________________";
	cout<<"\n";
	cout<< "\n\t\t\t\t GOVERNMENT OF MAHARASHTRA";
	cout<< "\n\t\t\t Welcome to the Pune-Mumbai Express Highway Toll";
	cout<< "\n___________________________________________________________________________________";
	cout<<"\n";
	cout<< "\n |"<<"\t"<<"\t |"<<"\t Vehicle Type"<<"\t\t|"<<" Single Journey"<<" |"<<" Return Journey"<<"|";
	cout<< "\n |"<<"\t 1."<<"\t |"<<"\t Car/Jeep"<<"\t\t|"<<"\t 50"<<"\t |"<<"\t 75"<<"\t |";
	cout<< "\n |"<<"\t 2."<<"\t |"<<"\t Tractor/Minibus"<<"\t|"<<"\t 75"<<"\t |"<<"\t 115"<<"\t |";
	cout<< "\n |"<<"\t 3."<<"\t |"<<"\t Bus/Truck"<<"\t\t|"<<"\t 160"<<"\t |"<<"\t 240"<<"\t |";
	cout<< "\n |"<<"\t 4."<<"\t |"<<"\t Over Sized Vehicle"<<"\t|"<<"\t 300"<<"\t |"<<"\t 455"<<"\t |";
	cout<< "\n___________________________________________________________________________________";
	cout<< "\n\n\t\t Two wheelers and Ambulance are exempted from the toll tax.";
	}

	do
	{                                           //menu driven
		cout<<"\n\n MENU";
		cout<<"\n 1.New vehicle entry:";
		cout<<"\n 2.Total number of vehicles passed through the toll:";
		cout<<"\n 3.Individual count of respective vehicles:";
		cout<<"\n 4.Total money collected by all vehicles passed through the toll:";
		cout<<"\n 5.Exit.";
		cout<<"\n Enter your choice:";
		cin>>num;
		switch(num)
		{
		case 1:
			t.accept();
		    break;

		case 2:
			t.count();
			break;
                                                 //calling functions
		case 3:
			t.individual_count();
			break;

		case 4:
			t.total();
			break;

		case 5:
			break;

		default:
			cout<<"\n Enter valid choice";
			break;
		}
	}while(num!=5);
    return 0;
}




/*
___________________________________________________________________________________

				 GOVERNMENT OF MAHARASHTRA
			 Welcome to the Pune-Mumbai Express Highway Toll
___________________________________________________________________________________

 |		 |	 Vehicle Type		| Single Journey | Return Journey|
 |	 1.	 |	 Car/Jeep	     	|	 50	         |	 75	         |
 |	 2.	 |	 Tractor/Minibus	|	 75	         |	 115	     |
 |	 3.	 |	 Bus/Truck		    |	 160     	 |	 240	     |
 |	 4.	 |	 Over Sized Vehicle	|	 300	     |	 455	     |
___________________________________________________________________________________

		 Two wheelers and Ambulance are exempted from the toll tax.

 MENU
 1.New vehicle entry:
 2.Total number of vehicles passed through the toll:
 3.Individual count of respective vehicles:
 4.Total money collected by all vehicles passed through the toll:
 5.Exit.
 Enter your choice: 1

 Enter booth number according to vehicle type
 1:Car/Jeep
 2:Tractor/minibus
 3:bus/truck
 4:Oversized vehicle 1

 Enter the vehicle type:
 car/jeep car

 Enter number plate of the vehicle:MH 12 AS 2345

 Do you have VIP Pass? (y/n)n

 Is it:
 1:Single journey!
 2:Return journey! 1

_________________________________________

	Pune-Mumbai Highway Toll Plaza
_________________________________________

 Number Plate	 :MH 12 AS 2345
 Vehicle Type	 :car
 Amount in Rs.	 :Rs.50

 !!!Wish you a HAPPY JOURNEY!!!

 NOTE: 1)TICKET IS VALID FOR 24 HOURS.
       2)MUST CARRY WHILE RETURN JOURNEY.
_________________________________________

 MENU
 1.New vehicle entry:
 2.Total number of vehicles passed through the toll:
 3.Individual count of respective vehicles:
 4.Total money collected by all vehicles passed through the toll:
 5.Exit.
 Enter your choice:1

 Enter booth number according to vehicle type
 1:Car/Jeep
 2:Tractor/minibus
 3:bus/truck
 4:Oversized vehicle3

 Enter the vehicle type:
 bus/truckbuuus

 Invalid vehicle type!!
 Enter the vehicle type:
 bus/truckbus

 Enter number plate of the vehicle:MH 56 HG 7896

 Do you have VIP Pass? (y/n)n

 Is it:
 1:Single journey!
 2:Return journey! 2

_________________________________________

	Pune-Mumbai Highway Toll Plaza
_________________________________________

 Number Plate	 :MH 56 HG 7896
 Vehicle Type	 :bus
 Amount in Rs.	 :Rs.240

 !!!Wish you a HAPPY JOURNEY!!!

 NOTE: 1)TICKET IS VALID FOR 24 HOURS.
       2)MUST CARRY WHILE RETURN JOURNEY.
_________________________________________

 MENU
 1.New vehicle entry:
 2.Total number of vehicles passed through the toll:
 3.Individual count of respective vehicles:
 4.Total money collected by all vehicles passed through the toll:
 5.Exit.
 Enter your choice: 1

 Enter booth number according to vehicle type
 1:Car/Jeep
 2:Tractor/minibus
 3:bus/truck
 4:Oversized vehicle1

 Enter the vehicle type:
 car/jeep car

 Enter number plate of the vehicle:MH 25 VG 6754

 Do you have VIP Pass? (y/n)y

 *No toll for VIP vehicles*

 !!!Wish you a HAPPY JOURNEY!!!

 MENU
 1.New vehicle entry:
 2.Total number of vehicles passed through the toll:
 3.Individual count of respective vehicles:
 4.Total money collected by all vehicles passed through the toll:
 5.Exit.
 Enter your choice:2

 Total number of vehicles passed till now are:3

 MENU
 1.New vehicle entry:
 2.Total number of vehicles passed through the toll:
 3.Individual count of respective vehicles:
 4.Total money collected by all vehicles passed through the toll:
 5.Exit.
 Enter your choice:3

 Select the vehicle whose count you need:
 1:Car
 2:Jeep
 3:Tractor
 4:Minibus
 5:Bus
 6:Truck
 7:Oversized
 8:Exit1

 Total number of cars that passed till now are: 2
 Select the vehicle whose count you need:
 1:Car
 2:Jeep
 3:Tractor
 4:Minibus
 5:Bus
 6:Truck
 7:Oversized
 8:Exit2

 Total number of jeeps that passed till now are: 0
 Select the vehicle whose count you need:
 1:Car
 2:Jeep
 3:Tractor
 4:Minibus
 5:Bus
 6:Truck
 7:Oversized
 8:Exit5

 Total number of buses that passed till now are: 1
 Select the vehicle whose count you need:
 1:Car
 2:Jeep
 3:Tractor
 4:Minibus
 5:Bus
 6:Truck
 7:Oversized
 8:Exit7

 Total number of oversized vehicles that passed till now are: 0
 Select the vehicle whose count you need:
 1:Car
 2:Jeep
 3:Tractor
 4:Minibus
 5:Bus
 6:Truck
 7:Oversized
 8:Exit8


 MENU
 1.New vehicle entry:
 2.Total number of vehicles passed through the toll:
 3.Individual count of respective vehicles:
 4.Total money collected by all vehicles passed through the toll:
 5.Exit.
 Enter your choice:4

 Total money collected: Rs 290

 MENU
 1.New vehicle entry:
 2.Total number of vehicles passed through the toll:
 3.Individual count of respective vehicles:
 4.Total money collected by all vehicles passed through the toll:
 5.Exit.
 Enter your choice:5
 * */
