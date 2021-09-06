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