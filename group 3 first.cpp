
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
