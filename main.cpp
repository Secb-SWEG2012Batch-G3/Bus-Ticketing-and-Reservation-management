#include<iomanip>
#include <iostream>
#include <fstream>
#include<cstring>
#include <string.h>
#include<windows.h>
using namespace std;
void pushX(int num){
    for(int i=0;i<num;i++)
        cout<<" ";

}
int main();
static int p = 0,stand=56;
int num;
void options();
struct counting{
    int counter;
};

class motor

{

char busn[5], driver[15], arrival[5], depart[5], board_cty[15], destin_cty[15], seat[14][4][10],clas[14];
int cash;
char sex[14][4][1];
int age[14][4];

public:

void add_bus();

void booking();
void displaysearch(int num,counting *counted);
void empty();
float fee(int);
bool login();
void logincheck();
void registration();
void show();
void showall();
void searcheng();

void seat_avail();
void discount();
void position(int i);


}bus[10];


float motor::fee(int nseat)//calculate fee
{
    int money;
    money=300*nseat;
}

void motor::discount()
{
    int pe,num_tra,ke;
    cout<< "Get a preview of our discounts: "<<endl;
    cout<<"press\n1.  if you are traveling with more than 5 families and friends press ";
    cout<<"\n 2.  if you are a veteran who served the country press \n3.  if you are aged 75+ or traveling with 7- aged press 3";
    cin>>pe;
    switch(pe){
    case 1:
        cout<<"how many travelers are there";
        cin>>num_tra;
        if(num_tra>=5){//  !!!!! missing if there are seats available for that many ppl!!!!
        cout<<"\nyour group will have a discounted payment of : "<<300*(num_tra-1)+0.5*300;
        cout<<"\nif you wish to continue with the discount booking press 1, else other key : ";
        cin>>ke;
        if(ke==1){
        for(int i=0;i<num_tra;i++)
            bus[p].booking();
        }
        }
        else
        {
            cout<<"you group number is not legible to have a discount\n";
            cout<< "\nif you want to have a reservation without discount press 1 else other key.";
            cin>>ke;
            if(ke=1)
                bus[p].booking();
        }
            break;
    case 2:
        cout<<"Thank you for serving the country , you are awarded with 50% discount\nYour payment is "<<150;
        bus[p].booking();
        break;
    case 3:
        cout<<"You are awarded with age discount,if you are 75+ press 1 and if you are traveling with 7- child press 2:\n";
        cin>>ke;
        if (ke=1){
            cout<<"your discount is 25% with payment of : "<<150;
            bus[p].booking();

            break;
        }
        else if(ke=2){
            cout<<"your discount is 25% for the child and payment is: "<<450;
            bus[p].booking();
            break;
        }
    default:
        break;
    }
}

void motor :: showall()//display all the input data of every person with out any parameter
{
    int num=0;
    cout<<setw(16)<<setfill(' ')<<left<<"\nNAME\t"<<setw(2)<<left<<"AGE\t"<<setw(2)<<left<<"SEX\t"<<setw(15)<<left<<"BOARIDING CITY\t"<<setw(15)<<left<<"DESTINATION\t"<<setw(2)<<left<<"ARRIVAL\t"<<setw(2)<<left<<"DEPARTURE\t"<<setw(5)<<left<<"BUS NUMBER\t"<<setw(5)<<left<<"SEAT NUMBER"<<setw(3)<<left<<"class"<<endl;

    while(num<=p){

        for(int i=0;i<14;i++){
            for(int j=0;j<4;j++){
                if(bus[num].age[i][j]==0)//if age is 0 then there wont be any out put ...and pass to next seat
                {
                    continue;

                }

                cout<<setw(15)<<left<<bus[num].seat[i][j]<<"\t  "<<setw(2)<<left<<bus[num].age[i][j]<<"\t";
                cout<<setw(2)<<left<<bus[num].sex[i][j]<<"\t"<<setw(15)<<left<<bus[num].board_cty<<"\t";
                cout<<setw(15)<<left<<bus[num].destin_cty<<"\t   ";
                cout<<setw(2)<<left<<bus[num].arrival<<"\t\t"<<setw(2)<<left<<bus[num].depart<<"\t"<<setw(5)<<left<<num<<"\t"<<setw(5)<<left<<setw(3)<<left<<bus[num].clas<<((i*4)+j)<<endl;
            }
        }
       num++;  //add number of buses up to p->which is max number of buses

    }
    end:
    system("PAUSE");

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
            check=true;//flag
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


    int chz,row,col,cl;

    bool check=false;


    while(check==false){
            cout<<"What class is the bus to be registered press firstclass or economyclass: \n";

              //cin.getline(bus[p].clas,14);
              cin>>bus[p].clas;

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
    //cin.ignore();
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

char b_cty[15],des[15],cls[14];
counting count[10];

top:
    cout<<"please enter either firstclass or economyclass with no space: ";
    cin>>cls;
cout<<"please enter boarding city: ";
cin.ignore();
cin.getline(b_cty,15);
//cin>>b_cty;
cout<<"please enter destination: ";
//cin.ignore();
cin.getline(des,15);
//cin>>des;

for(int i=0;i<p;i++)//check if there is a bus on the given destination and boarding city
{
    char xi=0;
    if((strcmp(b_cty,bus[i].board_cty) + strcmp(des,bus[i].destin_cty)+strcmp(cls,bus[i].clas) )==0)
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
//for(int i=0;i<num;i++){
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
        //cin.ignore();
        cin>>bus[n].age[seat_num/4][(seat_num%4)-1];

        if(bus[n].age[seat_num/4][(seat_num%4)-1]<18){
            cout<<"you are not allowed to travel (under age)";
            cout<<"THANK YOU FOR USING OUR SERVICE";
            exit('EXIT_SUCCESS');
        }

        cout<<"enter sex('m' for male or 'f' for female): ";
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
    char cl[13];
    bool check=false;
    char number[5];
    while(check=false){
            cout<<"please enter firstclass or economyclass with no space: ";
    cin.getline(cl,13);
        cout<<"Enter bus no: ";

        cin>>number;

        for(n=0;n<=p;n++)

        {

            if(strcmp(bus[n].busn, number)+strcmp(bus[n].clas,cl)==0)
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

        cout<<"class :\t"<<bus[n].clas<<"Bus no: \n \t"<<bus[n].busn

        <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart <<"\nFrom: \t\t"<<bus[n].board_cty<<"\t\tTo: \t\t"<<

        bus[n].destin_cty<<"\n";

        vline('*');

        bus[0].position(n);

        int a=1;

        for (int i=0; i<14; i++)

        {

            for(int j=0;j<4;j++)

            {

                a++;

                /*if(strcmp(bus[n].seat[i][j],"Empty")!=0)
                    cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";*/
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

    cout<<"\nclass: "<<bus[n].clas<<"\nBus no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver

    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"

    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].board_cty<<"\t\tTo: \t\t\t"

    <<bus[n].destin_cty<<"\n";

    vline('*');

    //vline('_');

}

}
void motor::displaysearch(int num,counting *counted){

    cout<<setw(16)<<setfill(' ')<<left<<"\nNAME\t"<<setw(2)<<left<<"AGE\t"<<setw(2)<<left<<"SEX\t"<<setw(15)<<left<<"BOARIDING CITY\t"<<setw(15)<<left<<"DESTINATION\t"<<setw(2)<<left<<"ARRIVAL\t"<<setw(2)<<left<<"DEPARTURE\t"<<endl;
    cout<<setw(15)<<left<<bus[num].seat[counted[0].counter][counted[1].counter]<<"\t  "<<setw(2)<<left<<bus[num].age[counted[0].counter][counted[1].counter]<<"\t";
    cout<<setw(2)<<left<<bus[num].sex[counted[0].counter][counted[1].counter]<<"\t"<<setw(15)<<left<<bus[num].board_cty<<"\t";
    cout<<setw(15)<<left<<bus[num].destin_cty<<"\t   ";
    cout<<setw(2)<<left<<bus[num].arrival<<"\t\t"<<setw(2)<<left<<bus[num].depart<<"\t"<<endl;
}
void motor::searcheng()//search engine
{
    int num,id[10],id2[10],count=0;
    char name[10];
    counting counted[2];
    cout<<"1.for name search \n"<<setw(10)<<"2.list groups of certain age level\n3.list groups of a certain sex";
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
                        counted[0].counter=id[i];
                        counted[1].counter=id2[i];

                        displaysearch(num,counted);
                    }
                    system("PAUSE");//
                }
                else
                    cout<<"no entries found\n";
                num++;
            }

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
    }


    else if(num==2)//search by stating age limits
    {
        count=0;
        num=0;
        cout<<"please enter the largest age limit: ";
        cin>>counted[0].counter;
        cout<<"please enter the smallest age limit: ";
        cin>>counted[1].counter;
        while(num<=p){
            for(int i=0;i<p;i++){
                for(int j=0;j<4;j++){

                    if(bus[num].age[i][j]<=counted[0].counter && bus[num].age[i][j]>=counted[1].counter )//checks every value to see if they meet the given parameter
                    {
                        id[count]=i;//stores the indexes of the names that were found in the search
                        id2[count]=j;
                        count++;
                    }
                }

            }
            if(count>0){
                //cout<<"entry found in bus"<<num<<": "<<endl;
                for(int i=0;i<count;i++){
                    counted[0].counter=id[i];
                    counted[1].counter=id2[i];

                    displaysearch(num,counted);
                    system("PAUSE");
                }

            }
            else{
                cout<<"no result found";
                system("PAUSE");
            }
            num++;//counts bus amount
        }


    }
    else if(num==3)//output all of the data on a given sex
    {
        char x[2];
        cout<<"which sex do you want to display: ";
        cin>>x;
        while(num<=p){
            for(int i=0;i<p;i++){
                for(int j=0;j<4;j++){

                    if(strcmp(bus[num].sex[i][j],x)==0 ){
                        id[count]=i;//stores the indexes of the names that were found in the search
                        id2[count]=j;
                        count++;
                    }
                }

            }
            if(count>0){
                //cout<<"entry found in bus"<<num<<": "<<endl;
                for(int i=0;i<count;i++){
                    counted[0].counter=id[i];
                    counted[1].counter=id2[i];

                    displaysearch(num,counted);
                    system("PAUSE");
                }

            }
            else{
                cout<<"no result found";
                system("PAUSE");
            }
            num++;
        }

    }



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
    //cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    //cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
/*for(int i=0;i<2;i++)
    for(int j=0;j<25;j++){


        system("CLS");
        pushX(j);
        cout << "*"  << "W E L C O M E !"  << "*" << endl;
        Sleep(100);
    }*/
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('-') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(45) << "Please Select One of the Following Options" << setfill(' ') << setw(5) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(32) << "1.MANAGER" << setfill(' ') << setw(18) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(33) << "2.USER" << setfill(' ') << setw(17) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(25) << "3. Quit/Exit" << setfill(' ') << setw(25) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill(' ') << setw(50) << "*" << endl;
    cout << "\t*" << setfill('*') << setw(50) << "*" << endl;
    cout << endl;
}

void options()//mean menu for all
{
    system("cls");
    int chz;
    string user_name,password;
    bool check=false;
    welcomeScreen();
    while(check==false)
{
    cin>>chz;
    if(chz==1){
        cout<<"enter user name: "<<endl;
        cin>>user_name;
        cout<<"enter password"<<endl;
        cin>>password; //no password checking system for now
            cout<<"\t\t\t1.Install\n\t\t\t"<<"2.Show\n\t\t\t"<<"3.search\n\t\t\t"<<"4.all data inputs";
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
                    case 4:
                        system("CLS");
                        bus[0].showall();
                        break;
                }
    }
    else if(chz==2){

        firstmenu();
        cout<<"\t\t\t1.Reservation\n\t\t\t"<<"\t\t\t2.Discount Reservation"
        <<"3.Buses Available. \n\t\t\t"<<"4.modify\n\t\t\t"<<"5.cancel\n\t\t\t"
        <<"6.Exit";

        cout<<"\n\t\t\tEnter your choice: ";

        cin>>chz;
        switch(chz)

        {


            case 1:  bus[p].booking();

                //system("PAUSE");
                system("CLS");
                break;
            case 2:
                bus[p].discount();
                system("CLS");
                   break;

            case 3:  bus[0].seat_avail();

                system("PAUSE");
                system("CLS");
                break;

            case 4://modify reservation
                break;
            case 5://delete reservation
                break;
            case 6:  exit(0);

        }

        }

    }


}

int main()

{


    system("cls");
   welcomeScreen();
    system("PAUSE");
    firstmenu();
    options();
    end:

    return 0;

}

