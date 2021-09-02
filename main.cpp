#include<iomanip>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;
int main();
static int p = 0,stand=56;
void options();
struct counting{
    int counter;
};
class motor

{

char busn[5]="1", driver[15]="jack", arrival[5]="12", depart[5]="3", board_cty[15]="addisabeba", destin_cty[15]="asosa", seat[14][4][10]={{"bisrat","dagi","leul","gaddaa",}};
int cash;
char sex[14][4][10];
int age[14][4];

public:

void add_bus();

void booking();

void empty();
float fee(int);
bool login();
void logincheck();
void registration();
void show();
void searcheng();

void seat_avail();

void position(int i);


}

bus[10];
float motor::fee(int nseat){
    int money;
    money=300*nseat;
}
bool motor::login()//user login page
{
    string user_name,password,un,up;
    bool check=false;
    char option;
    int counter=0;
    while(check==false){
        cout<<"enter user name: ";
        cin>>user_name;
        cout<<"enter password: ";
        cin>>password;
        ifstream read("data_store.txt");//inputs data from outside txt source 
        while(read.good())
        {
            read >>un >>up;
            //getline(read,un,);
            //getline(read,up);
        cout<<un<<" "<<up<<endl;
            if(user_name==un && password==up)//check the input user name and password with the data gathered form the txt file
            {
                counter=1;
                goto out;
                break;
                //main();
            }
        }
        out://get the password checking out of the loop
        if(counter==1){
            system("cls");
            cout<<setw(40)<<"welcome to safe bus reservation system"<<endl;
            check=true;
            system("PAUSE");
        }
        else{
            cout<<"wrong user name or password, please check and try again"<<endl;
            cout<<"to return to registration section press 1: ";
            cin>>option;
            if(option==1){
                bus[0].registration();
                cout<<"check\n";
            }

        }
    }


}
void motor::registration()//user registration
{
    string username,password,password2,un,up;
    jump:
    cout<<"choose a user name: ";
    cin>>username;

    ifstream read("data_store.txt");//check if the user name input already exist or not
        while(read.good()){
        getline(read,un,',');

        if(username==un ){
            cout<<"user name already taken please try again"<<endl;
            goto jump;
        }
        }
    repass://if the first and second password entry is not the same it comes back here to put password again 
    cout<<"input a password: ";
    cin>>password;
    cout<<"re-enter your password: ";
    cin>>password2;
    if(password!=password2){
        cout<<"please input the same password twice\n";
        goto repass;
    }

    ofstream file;//saves the registration in an txt file outside the program
    file.open("data_store.txt",ios::app);
        file <<username<<" "<<password<<endl;
    file.close();
    bus[0].login();


}
void vline(char ch)

{

for (int i=80;i>0;i--)

cout<<ch;

}

void motor::add_bus()//is used to install new buses on different routes

{
    int chz,row,col;
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
    cin.ignore();
    cin.getline(bus[p].board_cty,15);

    cout<<"\nTo: \t\t\t";
    cin.ignore();
    cin.getline(bus[p].destin_cty,15);

    bus[p].empty();

    p++;
    cout<<"\n to continue adding press any number, to exit press 1: ";
    cin>>chz;
    if(chz==1){
    check=true;
        break;
    }

    }

}

void motor::booking()

{

int number,seat_num,roll=0;

char b_cty[15],des[15];
counting count[10];

top:
cout<<"please enter boarding city: ";
cin.ignore();
cin.getline(b_cty,15);
//cin>>b_cty;
cout<<"please enter destination: ";
cin.ignore();
cin.getline(des,15);
//cin>>des;

for(int i=0;i<p;i++)//check if there is a bus on the given destination and boarding city
{
    char xi=0;
    if((strcmp(b_cty,bus[i].board_cty) + strcmp(des,bus[i].destin_cty) )==0)
    {
        bus[i].seat_avail();
        cout<<endl;
        count[roll].counter=i+1;
        roll++;
    }
    
    xi++;
}
if(roll==0){
        cout<<"there is no bus assigned from your location to the specified destination\n";
        cout<<"THANK YOU for using our service\n";
        system("PAUSE");
        options();

    
}
bool check=false;
int n=0;
while(check==false){
    cout<<"please choose a Bus number: ";
    cin>>number;

    /*for(n=0;n<=p;n++)

    {

        if(strcmp(bus[n].busn, number)==0)//check is the number input is aligned with the number of buses available
        {
            break;
        }
    }*/
    
    for(int i=0;i<roll;i++)//checks if the bus number entered is the same as the destination the user chose
    {
        cout<<count[i].counter<<" \t"<<number;
        
        if(number==count[i].counter){
            check=true;
        }
        else
            cout<<"please enter the correct bus number\n";
    }
}


while(n<=p)

{

    cout<<"\nSeat Number: ";

    cin>>seat_num;

    if(seat_num>stand && seat_num<1)

    {

    cout<<"\nThere are only "<<stand<<" seats available in this bus.";

    }

    else

    {

    if (strcmp(bus[n].seat[seat_num/4][(seat_num%4)-1], "Empty")==0)

    {

        cout<<"Enter passanger's name: ";
        cin.ignore();
        cin.getline(bus[n].seat[seat_num/4][(seat_num%4)-1],10);
        cout<<"enter age: ";
        cin.ignore();
        cin>>bus[n].age[seat_num/4][(seat_num%4)-1];
        cout<<"sex('m' for male or 'f' for female): ";
        cin.ignore();
        cin.getline(bus[n].sex[seat_num/4][(seat_num%4)-1],10);
        system("PAUSE");
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


void motor::empty()

{

for(int i=0; i<14;i++)

{

    for(int j=0;j<4;j++)

    {

    strcpy(bus[p].seat[i][j], "Empty");

    }

}

}

void motor::show()

{

    int n;
    bool check=false;
    char number[5];
    while(check=false){
        cout<<"Enter bus no: ";

        cin>>number;

        for(n=0;n<=p;n++)

        {

            if(strcmp(bus[n].busn, number)==0)
            {

                break;
            }

        }
        if(n>9){
            cout<<"please enter the correct bus number\n";
            continue;
        }
        else
            check=true;

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

void motor::position(int l)

{

int s=0;p=0;

for (int i =0; i<14;i++)

{

    cout<<"\n";

    for (int j = 0;j<4; j++)

    {

    s++;

    if(strcmp(bus[l].seat[i][j], "Empty")==0)

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        p++;

        }

        else

        {

        cout.width(5);

        cout.fill(' ');

        cout<<s<<".";

        cout.width(10);

        cout.fill(' ');

        cout<<bus[l].seat[i][j];

        }

    }
    }

cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;

}

void motor::seat_avail()

{


for(int n=0;n<p;n++)

{

    vline('*');

    cout<<"\nBus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].board_cty<<"\t\tTo: \t\t\t"

    <<bus[n].destin_cty<<"\n";

    vline('*');

    //vline('_');

}

}
void motor::searcheng()//search engine
{
    int num,id[10],id2[10],count=0;
    char name[10];
    cout<<"1.for name search \n"<<setw(10)<<"2.  :-";
    cin>>num;
    if(num==1){
        cout<<"1.for general search press\n2.for specific bus search: ";
        cin>>num;
        if(num==1)//searches name in every bus installed
        {
        num=0;//counts the amount of buses up to p(which is amount of buses installed)
        while(num<=p){
            cout<<"please enter the name: ";
            cin>>name;
            for(int i=0;i<14;i++){
                for(int j=0;j<4;j++){

                    if(strcmp(bus[num].seat[i][j],name )==0){
                        id[count]=i;//stores the indexes of the names that were found in the search
                        id2[count]=j;
                        count++;
                    }
                }
            }
            if(count>0){
                cout<<"entry found in bus"<<num<<": "<<endl;
                for(int i=0;i<count;i++){
                    int c=id[i];
                    int d=id2[i];
                    cout<<bus[num].seat[c][d]<<endl;
                }
                system("PAUSE");
            }
            else
                cout<<"no entries found\n";
            num++;
            }

        }

        num=0;
        }
        else if (num==2){

            cout<<"please enter bus number: ";
            cin>>num;
            cout<<"please enter the name: ";
            cin>>name;
            for(int i=0;i<stand;i++){
            for(int j=0;j<stand;j++){

                if(strcmp(bus[num].seat[i][j],name )==0){
                cout<<"entry found: ";
                cout<<bus[num].seat[i][j];
                }
                else
                cout<<"no entry found";

            }

            }
        }

    /*else if(num==2){
        cout<<"please enter bus number: ";
        cin>>num;

        for(int i=0;i<stand;i++){
            for(int j=0;j<stand;j++){

                if(strcmp(bus[num].seat[i][j],name )==0){
                cout<<"entry found: ";
                cout<<bus[num].seat[i][j];
                }
                else
                cout<<"no entry found";

            }

            }


    }


    }*/
}
void firstmenu()//function for login and signup
{
    int option;
    //cout<<setw(40)<<right<<"1.register\n"<<setw(40)<<right<<"2.login"<<endl<<"-> ";
    cin>>option;
    if(option==1){
        bus[0].registration();//if no account ..create an account
    }
    else if(option==2){
        bus[0].login();//if there is an account sign in
    }
}
void welcomeScreen()//first page greetings
{
    cout << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "W E L C O M E !" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(45) << "Please Select One of the Following Options" << setfill(' ') << setw(5) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "1.REGISTER" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << "2.LOGIN" << setfill(' ') << setw(17) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(25) << "3. Quit/Exit" << setfill(' ') << setw(25) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << endl;
}

void options(){
    int chz;
    string user_name,password;
    bool check=false;
    while(check==false)

{

    system("cls");

    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t1.Managerial"<<endl;
    cout<<"\t\t\t2.user"<<endl;
    cin>>chz;
    if(chz==1){
        cout<<"enter user name: "<<endl;
        cin>>user_name;
        cout<<"enter password"<<endl;
        cin>>password; //no password checking system for now
            cout<<"\t\t\t1.Install\n\t\t\t"<<"2.Show\n\t\t\t"<<"3.search";
            cout<<"\n\t\t\tEnter your choice: ";
            cin>>chz;
            switch(chz)

                {

                    case 1:  bus[p].add_bus();
                        
                        system("CLS");
                        break;
                    case 2:  bus[0].show();
                        
                        system("CLS");
                        break;
                    case 3:
                        system("CLS");
                        bus[0].searcheng();
                        break;
                }
    }
    else if(chz==2){

        //firstmenu();
        cout<<"\t\t\t1.Reservation\n\t\t\t"
        <<"2.Buses Available. \n\t\t\t"<<"3.modify\n\t\t\t"<<"4.cancel\n\t\t\t"
        <<"5.Exit";

        cout<<"\n\t\t\tEnter your choice: ";

        cin>>chz;
        switch(chz)

        {


            case 1:  bus[p].booking();

                //system("PAUSE");
                system("CLS");
                break;


            case 2:  bus[0].seat_avail();

                system("PAUSE");
                system("CLS");
                break;

            case 3://modify reservation
                break;
            case 4://delete reservation
                break;
            case 5:  exit(0);

        }

        }

    }


}

int main()

{

//system("cls");
welcomeScreen();
firstmenu();
options();
end:

    return 0;

}

