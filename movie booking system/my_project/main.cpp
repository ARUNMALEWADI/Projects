#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
class movie
{
private :
    int tickets,bill,id,sit[10];
    char ch,theater[20],tier[10];
    string mname,name,date,time;

public :

    movie()
    {
        id=0;
        bill=0;

    }
    void pass();
    void admin();
    void clears();
    void get_theatre_name();
    void running_movie();
    void get_ticket(int a);
    void esquare();
    void prabhat();
    void gentyal();
    void bhagwat();
    void laxminarayan();
    void calculation();
    void storedata();
    void searchdata();
    void showdata();

} m;


void movie::storedata()
{ char t;


    if(bill==0)
    {
        cout<<"customer data is empty"<<endl;
        exit(0);
    }
    fstream fout;
    fout.open("userdata.txt",ios::app|ios::binary);
    fout.write((char*)this,sizeof(*this));
    fout.close();
    cout<<"you have booked seat successfully"<<endl;
   cout<<"\n*****REMEMBER MOVIE NAME IT IS IMPORTANT****"<<endl;
    cout<<"if you want to see details press y else press any key"<<endl;
    cin>>t;
    if(t=='y')
    {
    showdata();
    }
    cin.ignore();
}

void movie::searchdata()
{  string s,m;

   cout<<"Enter the your name:"<<endl;
  getline(cin>>ws,s);
cout<<"Enter movie name:"<<endl;
getline(cin>>ws,m);
    ifstream fin;
    fin.open("userdata.txt",ios::in|ios::binary);
    if(!fin)
        cout<<"\nFile not found";
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(s==name && m==mname )
                showdata();
     fin.read((char*)this,sizeof(*this));

        }
        fin.close();


    }

}
void movie::showdata()
{
    cout<<"\n\n************YOUR DETAILS************\n\n"<<endl;
    cout<<"customer id:"<<id<<endl;
    cout<<"\ncustomer:"<<name<<endl;
    cout<<"\nmovie:"<<mname<<endl;
    cout<<"\ntheater:"<<theater<<endl;
    cout<<"\ntype:"<<tier<<endl;
    for(int i=1;i<=tickets;i++)
{    cout<<"\nSEAT no:"<<sit[i]<<endl;
}
    cout<<"\nno.of tickets:"<<tickets<<endl;
    cout<<"\ndate:"<<date<<endl;
    cout<<"\ntime:"<<time<<endl;
    cout<<"\nTotal cost:"<<bill<<endl;
    cout<<"\n######THANK YOU######"<<endl;

}
void movie :: pass()
{
    double p,a,k,i=0;
    cout<<"\nEnter password to login  administrator"<<endl;
    cin>>p;
    if(p==1234)
    {
        cout<<"Login successful"<<endl;
        cout<<"1.add a movie\n2.clear seats of theatres"<<endl;
        cin>>a;
        if(a==1)
        {cout<<"How many movies do you want to add:"<<endl;
         cin>>k;
        while(i<k)  
       {  admin();
          i++;
         }

        }
        else if(a==2)
        { 
           clears();
        }
    }
    else
        cout<<"\n**INCOREECT PASSWORD**"<<endl;
}
void movie :: admin()
{ string add;
    fstream fout;
    fout.open("movie.txt",ios::app|ios::binary);
    cout<<"Enter the movie:"<<endl;
    getline(cin>>ws,add);

    fout<<'\0';
    fout<<add;
    fout.close();

}
void movie::clears()
{ int k; 
cout<<"Which theaters seats you want to clear:\n1.esquare\n2.prabhat\n3.bhagwat\n4.gentyal\n5.laxminarayan"<<endl;
         cin>>k;
if(k==1)
{
fstream fin;
fin.close();
fin.open("esquare.txt");
fin<<1;
fin.close();
cout<<"All seats are successsfully cleared"<<endl;
}
else if(k==2)
{ fstream fin;
fin.close();
fin.open("prabhat.txt");
fin<<1;
fin.close();
cout<<"All seats are successsfully cleared"<<endl;
}
else if(k==3)
{fstream fin;
fin.close();
fin.open("bhagwat.txt");
fin<<1;
fin.close();
cout<<"All seats are successsfully cleared"<<endl;
}
else if(k==4)
{fstream fin;
fin.close();
fin.open("gentyal.txt");
fin<<1;
fin.close();
cout<<"All seats are successsfully cleared"<<endl;
}
else if(k==5)
{fstream fin;
fin.close();
fin.open("laxminarayan.txt");
fin<<1;
fin.close();
cout<<"All seats are successsfully cleared"<<endl;
}
else
{ cout<<"Wrong input"<<endl;
}

}
void movie::running_movie()
{
 string s;
  cout<<"popular movies treading are as follows:\n";
    ifstream fin;
    fin.open("movie.txt");
    while(!fin.eof())
    { while(getline(fin,s,'\0'))
     {
        cout<<s<<'\n';

     }


    }
    fin.close();

int t=1;

while(t!=0)
{
 cout<<"\nEnter the movie name:(write correct name)"<<endl;
 getline(cin>>ws,mname);
  fin.open("movie.txt");
    while(!fin.eof())
    { while(getline(fin,s,'\0'))

     {      if(s==mname)
        {   t=0;

        }


     }

    }
    fin.close();
}


    get_theatre_name();



}
void movie::get_theatre_name()
{
    int f;
    cout<<"\n\nHERE ARE SOME HIGHEST RATED THEATRES ARE IN SOLAPUR:WHICH ARE SHOWING ABOVE MOVIE:"<<endl;
    cout<<"\n1.E-SQUARE:  5* \n2.PRABHAT THEATRE:  4.5* \n3.BHAGWAT CARNIWAL: 3.9* \n4.GENTYAL :3.7* \n5.LAXMINARAYAN : 3.2*"<<endl;
    cin>>f;
    get_ticket(f);
}
void movie::get_ticket(int a)
{
    switch(a)
    {
    case 1:
        strcpy(theater,"E-square");
        esquare();
        break;
    case 2:
        strcpy(theater,"prabhat");
        prabhat();
        break;
    case 3:
        strcpy(theater,"bhagwat");
        bhagwat();
        break;
    case 4:
        strcpy(theater,"gentyal");
        gentyal();
        break;
    case 5:
        strcpy(theater,"laxminarayan");
        laxminarayan();
        break;
    }
}
void movie::esquare()
{ int a;
    cout<<"\n\n\nWELCOME TO E_SQUARE WORLD"<<endl;
    cout<<"\n\n\nEnter the date for movie:\n1-2-2020\n3-2-2020\n5-2-2020"<<endl;
    getline(cin>>ws,date);
    while(date!="1-2-2020"&& date!="3-2-2020" && date!="5-2-2020")
    { cout<<"please enter the valid date";
     getline(cin>>ws,date);

    }
    cout<<"\nDaily schedule of this movie:\n1. 12:00 pm \n2. 3:00 pm \n3. 6:00 pm \n4. 9:00 pm" <<endl;
    cout<<"\nEnter your time"<<endl;
    cin>>a;
    while(a >=5||a <1)
    { cout<<"\nEnter the valid time:"<<endl;
      cin>>a;
    }
    if(a==1)
    { time="12:00 pm";
    }
    else if(a==2)
    {time="3:00 pm";
    }
    else if(a==3)
    { time="6:00 pm";

    }
    else
    { time="9:00 pm";

    }



    cout<<"Enter THE TYPE OF TICKET:"<<endl;
    cout<<"platinum:-RS.300/seat\ngold:-RS.200/seat\nsilver:-RS.100/seat"<<endl;
    cin>>tier;
    while((strcmp(tier,"platinum")!=0)&&(strcmp(tier,"gold")!=0)&&(strcmp(tier,"silver")!=0))
    {
        cout<<"Please enter valid type:"<<endl;
        cin>>tier;

    }
    cout<<"Enter the name of customer:"<<endl;
   getline(cin>>ws,name);
    cout<<"\nEnter the number of tickets"<<endl;
    cin>>tickets;
    cin.ignore();
    int i,j=1;
fstream fin;
fin.open("esquare.txt");
while(fin>>i)
 {
}
 if((25-i)<tickets)
   { cout<<"sorry this much seats are not available:please go to another theatre:"<<endl;
    fin.close();
    get_theatre_name();

   }
 if(i>25)
{ cout<<"sorry thetare is filled:"<<endl;
  cout<<"try other theatres:"<<endl;
   fin.close();
  get_theatre_name();
}
 while(j<=tickets)
  {sit[j]=i;
  j++;
  i++;
  }
  id=i+3;
 fin.close();
 fin.open("esquare.txt");
 fin<<i;
 fin.close();


    calculation();

}
void movie::prabhat()
{ int a;
    cout<<"WELCOME TO E_SQUARE WORLD"<<endl;
   cout<<"\n\n\nEnter the date for movie:\n1-2-2020\n3-2-2020\n5-2-2020"<<endl;
    getline(cin>>ws,date);
    while(date!="1-2-2020"&& date!="3-2-2020" && date!="5-2-2020")
    { cout<<"please enter the valid date";
     getline(cin>>ws,date);

    }
    cout<<"\nDaily schedule of this movie:\n1. 12:00 pm \n2. 3:00 pm \n3. 6:00 pm \n4. 9:00 pm" <<endl;
    cout<<"\nEnter your time"<<endl;
    cin>>a;
    while(a >=5||a <1)
    { cout<<"\nEnter the valid time:"<<endl;
      cin>>a;
    }
    if(a==1)
    { time="12:00 pm";
    }
    else if(a==2)
    {time="3:00 pm";
    }
    else if(a==3)
    { time="6:00 pm";

    }
    else
    { time="9:00 pm";

    }
    cout<<"Enter THE TYPE OF TICKET:"<<endl;
    cout<<"\nplatinum:-RS.300/seat\ngold:-RS.200/seat\nsilver:-RS.100/seat"<<endl;
    cin>>tier;
    while((strcmp(tier,"platinum")!=0)&&(strcmp(tier,"gold")!=0)&&(strcmp(tier,"silver")!=0))
    {
        cout<<"Please enter valid type:"<<endl;
        cin>>tier;

    }
    cout<<"Enter the name of customer:"<<endl;
     getline(cin>>ws,name);
    cout<<"\nEnter the number of tickets"<<endl;
    cin>>tickets;
int i,j=1;
fstream fin;
fin.open("prabhat.txt");
while(fin>>i)
 {
}
 if((25-i)<tickets)
   { cout<<"sorry this much seats are not available:please go to another theatre:"<<endl;
    fin.close();
    get_theatre_name();

   }
 if(i>25)
{ cout<<"sorry thetare is filled:"<<endl;
  cout<<"try other theatres:"<<endl;
   fin.close();
  get_theatre_name();
}
 while(j<=tickets)
  {sit[j]=i;
  j++;
  i++;
  }
  id=i+1;
 fin.close();
 fin.open("prabhat.txt");
 fin<<i;
 fin.close();


    calculation();


}
void movie::bhagwat()
{ int a;
    cout<<"WELCOME TO BAGHWAT WORLD"<<endl;
    cout<<"\n\n\nEnter the date for movie:\n1-2-2020\n3-2-2020\n5-2-2020"<<endl;
    getline(cin>>ws,date);
    while(date!="1-2-2020"&& date!="3-2-2020" && date!="5-2-2020")
    { cout<<"please enter the valid date";
     getline(cin>>ws,date);

    }
    cout<<"\nDaily schedule of this movie:\n1. 12:00 pm \n2. 3:00 pm \n3. 6:00 pm \n4. 9:00 pm" <<endl;
    cout<<"\nEnter your time"<<endl;
    cin>>a;
    while(a >=5||a <1)
    { cout<<"\nEnter the valid time:"<<endl;
      cin>>a;
    }
    if(a==1)
    { time="12:00 pm";
    }
    else if(a==2)
    {time="3:00 pm";
    }
    else if(a==3)
    { time="6:00 pm";

    }
    else
    { time="9:00 pm";

    }

    cout<<"Enter THE TYPE OF TICKET:"<<endl;
    cout<<"platinum:-RS.300/seat\ngold:-RS.200/seat\nsilver:-RS.100/seat"<<endl;
    cin>>tier;
    while((strcmp(tier,"platinum")!=0)&&(strcmp(tier,"gold")!=0)&&(strcmp(tier,"silver")!=0))
    {
        cout<<"Please enter valid type:"<<endl;
        cin>>tier;

    }
    cout<<"Enter the name of customer:"<<endl;
    getline(cin>>ws,name);
    cout<<"\nEnter the number of tickets"<<endl;
    cin>>tickets;
    int i,j=1;
fstream fin;
fin.open("bhagwat.txt");
while(fin>>i)
 {
}
 if((25-i)<tickets)
   { cout<<"sorry this much seats are not available:please go to another theatre:"<<endl;
    fin.close();
    get_theatre_name();

   }
 if(i>25)
{ cout<<"sorry thetare is filled:"<<endl;
  cout<<"try other theatres:"<<endl;
   fin.close();
  get_theatre_name();
}
 while(j<=tickets)
  {sit[j]=i;
  j++;
  i++;
  }
  id=i+1;
 fin.close();
 fin.open("bhagwat.txt");
 fin<<i;
 fin.close();

    calculation();


}
void movie::gentyal()
{ int a;
    cout<<"WELCOME TO GENTYAL WORLD"<<endl;
    cout<<"\n\n\nEnter the date for movie:\n1-2-2020\n3-2-2020\n5-2-2020"<<endl;
    getline(cin>>ws,date);
    while(date!="1-2-2020"&& date!="3-2-2020" && date!="5-2-2020")
    { cout<<"please enter the valid date";
     getline(cin>>ws,date);

    }
    cout<<"\nDaily schedule of this movie:\n1. 12:00 pm \n2. 3:00 pm \n3. 6:00 pm \n4. 9:00 pm" <<endl;
    cout<<"\nEnter your time"<<endl;
    cin>>a;
    while(a >=5||a <1)
    { cout<<"\nEnter the valid time:"<<endl;
      cin>>a;
    }
    if(a==1)
    { time="12:00 pm";
    }
    else if(a==2)
    {time="3:00 pm";
    }
    else if(a==3)
    { time="6:00 pm";

    }
    else
    { time="9:00 pm";

    }
    cout<<"Enter THE TYPE OF TICKET:"<<endl;
    cout<<"\nplatinum:-RS.300/seat\ngold:-RS.200/seat\nsilver:-RS.100/seat"<<endl;
    cin>>tier;
    while((strcmp(tier,"platinum")!=0)&&(strcmp(tier,"gold")!=0)&&(strcmp(tier,"silver")!=0))
    {
        cout<<"Please enter valid type:"<<endl;
        cin>>tier;

    }
    cout<<"Enter the name of customer:"<<endl;
    getline(cin>>ws,name);
    cout<<"\nEnter the number of tickets"<<endl;
    cin>>tickets;
    cin.ignore();
    int i,j=1;
fstream fin;
fin.open("gentyal.txt");
while(fin>>i)
 {
}
 if((25-i)<tickets)
   { cout<<"sorry this much seats are not available:please go to another theatre:"<<endl;
    fin.close();
    get_theatre_name();

   }
 if(i>25)
{ cout<<"sorry thetare is filled:"<<endl;
  cout<<"try other theatres:"<<endl;
   fin.close();
  get_theatre_name();
}
 while(j<=tickets)
  {sit[j]=i;
  j++;
  i++;
  }
  id=i+1;
 fin.close();
 fin.open("gentyal.txt");
 fin<<i;
 fin.close();

    calculation();


}
void movie::laxminarayan()
{ int a;
    cout<<"WELCOME TO LAXMINARAYAN WORLD"<<endl;
    cout<<"\n\n\nEnter the date for movie:\n1-2-2020\n3-2-2020\n5-2-2020"<<endl;
    getline(cin>>ws,date);
    while(date!="1-2-2020"&& date!="3-2-2020" && date!="5-2-2020")
    { cout<<"please enter the valid date";
     getline(cin>>ws,date);

    }
    cout<<"\nDaily schedule of this movie:\n1. 12:00 pm \n2. 3:00 pm \n3. 6:00 pm \n4. 9:00 pm" <<endl;
    cout<<"\nEnter your time"<<endl;
    cin>>a;
    while(a >=5||a <1)
    { cout<<"\nEnter the valid time:"<<endl;
      cin>>a;
    }
    if(a==1)
    { time="12:00 pm";
    }
    else if(a==2)
    {time="3:00 pm";
    }
    else if(a==3)
    { time="6:00 pm";

    }
    else
    { time="9:00 pm";

    }
    cout<<"Enter THE TYPE OF TICKET:"<<endl;
    cout<<"platinum:-RS.300/seat\ngold:-RS.200/seat\nsilver:-RS.100/seat"<<endl;
    cin>>tier;
    while((strcmp(tier,"platinum")!=0)&&(strcmp(tier,"gold")!=0)&&(strcmp(tier,"silver")!=0))
    {
        cout<<"Please enter valid type:"<<endl;
     cin>>tier;


    }
    cout<<"Enter the name of customer:"<<endl;
   getline(cin>>ws,name);
   cout<<"\nEnter the number of tickets"<<endl;
    cin>>tickets;
    cin.ignore();

int i,j=1;
fstream fin;
fin.open("laxminarayan.txt");
while(fin>>i)
 {
}
 if((25-i)<tickets)
   { cout<<"sorry this much seats are not available:please go to another theatre:"<<endl;
    fin.close();
    get_theatre_name();

   }
 if(i>25)
{ cout<<"sorry thetare is filled:"<<endl;
  cout<<"try other theatres:"<<endl;
   fin.close();
  get_theatre_name();
}
 while(j<=tickets)
  {sit[j]=i;
  j++;
  i++;
  }
  id=i+1;
 fin.close();
 fin.open("laxminarayan.txt");
 fin<<i;
 fin.close();

    calculation();


}
void movie::calculation()
{
    cout<<"\nCost of tickets is:"<<endl;
    if(strcmp(tier,"platinum")==0)
    {
        bill=tickets*300;
        cout<<bill<<"RS/-"<<endl;

    }
    else if(strcmp(tier,"gold")==0)
    {
        bill=tickets*200;
        cout<<bill<<"RS/-"<<endl;

    }
    else
    {
        bill=tickets*100;
        cout<<bill<<"RS/-"<<endl;

    }



}


int main()
{ 
    int ch,k=1;
cout<<"####WELCOME TO MOVIE BOOKING SYSTEM####"<<endl;
cout<<"Devloped by:"<<endl;
cout<<"VAIBHAV PUKALE"<<endl;    
cout<<"ANKIT MORDE"<<endl;
cout<<"BISWAJEET SAHOO"<<endl;
cout<<"ARUN MALEWADI"<<endl;
while(k=1)
    {cout << "1.Edition of data(only admin) \n2.Reservation of tickets for movie \n3.search record\n4.Exit the system" << endl;
    cin>>ch;

    switch(ch)
    {
    case 1:
        m.pass();
        break;
    case 2:
        m.running_movie();
        m.storedata();

        break;
    case 3:
       m.searchdata();
        break;
    case 4:

        exit(0);

    }
}

    return 0;
}

