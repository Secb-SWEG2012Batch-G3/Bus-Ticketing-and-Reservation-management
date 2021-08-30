#include <iostream>

#include <string.h>

using namespace std;

static int p = 0;

class system

{

  char busn[5], driver[15], arrival[5], depart[5], board_cty[10], destin_cty[10], seat[8][4][10];
  int nseat,cash;

public:

  void add_bus();

  void booking();

  void empty();

  void show();

  void seat_avail();

  void position(int i);
  void fee();

}

bus[10];
void fee(int nseat){
	int money;
	money=300*nseat;
}

void vline(char ch)

{

  for (int i=80;i>0;i--)

  cout<<ch;

}

void system::add_bus()

{
	int chz;
	bool check=false;
	while(check==false){

	  cout<<"Enter Bus number: ";

	  cin>>bus[p].busn;

	  cout<<"\nEnter Driver's name: ";

	  cin>>bus[p].driver;

	  cout<<"\nArrival time: ";

	  cin>>bus[p].arrival;

	  cout<<"\nDeparture time: ";

	  cin>>bus[p].depart;

	  cout<<"\nFrom: \t\t\t";

	  cin>>bus[p].board_cty;

	  cout<<"\nTo: \t\t\t";

	  cin>>bus[p].destin_cty;
	  cout<<"\nTotal seats: ";
	  cin>>bus[p].nseat;

	  bus[p].empty();

	  p++;
	  cout<<"\n to continue adding press any number, to exit press 1: ";
	  cin>>chz;
	  if(chz==1){
	  	break;
	  }

	}

}

void system::booking()

{

  int seat_num;

  char number[5];

  top:

  cout<<"Bus no: ";

  cin>>number;

  int n;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

  while(n<=p)

  {

    cout<<"\nSeat Number: ";

    cin>>seat_num;

    if(seat_num>bus[p].nseat && seat_num<1)

    {

      cout<<"\nThere are only "<<bus[p].nseat<<" seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat_num/4][(seat_num%4)-1], "Empty")==0)

      {

        cout<<"Enter passanger's name: ";

        cin>>bus[n].seat[seat_num/4][(seat_num%4)-1];

        break;

      }

    else

      cout<<"The seat number. is already reserved.\n";

      }

      }

    if(n>p)

    {

      cout<<"Enter correct bus no.\n";

      goto top;

    }

  }


void system::empty()

{

  for(int i=0; i<8;i++)

  {

    for(int j=0;j<4;j++)

    {

      strcpy(bus[p].seat[i][j], "Empty");

    }

  }

}

void system::show()

{

  int n;

  char number[5];

  cout<<"Enter bus no: ";

  cin>>number;

  for(n=0;n<=p;n++)

  {

    if(strcmp(bus[n].busn, number)==0)

    break;

  }

while(n<=p)

{

  vline('-');

  cout<<"Bus no: \n \t"<<bus[n].busn

  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart <<"\nFrom: \t\t"<<bus[n].board_cty<<"\t\tTo: \t\t"<<

  bus[n].destin_cty<<"\n";

  vline('*');

  bus[0].position(n);

  int a=1;

  for (int i=0; i<8; i++)

  {

    for(int j=0;j<4;j++)

    {

      a++;

      if(strcmp(bus[n].seat[i][j],"Empty")!=0)

      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";

    }

  }

  break;

  }

  if(n>p)

    cout<<"Enter correct bus no: ";



}
