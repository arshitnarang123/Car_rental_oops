#include<bits/stdc++.h>
#include<fstream>
#include<ctime>
using namespace std;
time_t currentTime = time(nullptr);
tm* localTime = localtime(&currentTime);
int year=(localTime->tm_year + 1900);
int month=(localTime->tm_mon + 1);
int date=localTime->tm_mday;
int no_of_days(int year1,int month1,int date1){
    int ans=0;
    ans+=(year1-year)*365;
    ans+=(month1-month)*(30);
    ans+=(date1-date);
    return ans;
}
int later(int year1,int month1,int date1){
    if(year>year1){
        return 1;
    }
    if(month>month1){
        return 1;
    }
    if(date>date1){
        return 1;
    }
    return 0;
}
//car_database=>model condition (rented or not) due_year due_month due_date id cost last_due_year last_due_month last_due_date record_change
//customer_database=>name id password record dues
void show_car_record(const string& car_database){
          ifstream inputFile(car_database);
          string line;
          int flag=0;
          while (getline(inputFile, line)) {
          istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(number2==0){
                cout<<"car model- "<<str1<<" car condition- "<<number1<<"  Not rented "<<"Rent cost(per day)- "<<cost<<"\n";
                flag=1;
            }
            else{
                flag=1;
                cout<<"car model- "<<str1<<" car condition- "<<number1<<"  Rented to "<<id1<<" Rent cost(per day)- "<<cost<<"\n";
            }
          }
          if(flag==0){
              cout<<"No car available\n";
          }
}
class user{
    protected:
     string name;
     int id;
     string password;
    public:
     void set_name(string s){
        name=s; 
     }
     void set_id(int i){
         id=i;
     }
     void set_password(string s){
         password=s;
     }
};
class manager: public user{
    public:
      void add_manager(const string& name1, int id1, const string& password1,const string& manager_database){
         this->name=name1;
         this->id=id1;
         this->password=password1;
         ofstream file(manager_database);
         file<<name1<<" "<<id1<<" "<<password1<<"\n";
         file.close();
      }
      void show_available_cars(const string& car_database){
          ifstream inputFile(car_database);
          string line;
          int flag=0;
          while (getline(inputFile, line)) {
          istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(number2==0){
                cout<<str1<<" "<<number1<<"\n";
                flag=1;
            }
          }
          if(flag==0){
              cout<<"No car available\n";
          }
      }
     
    
     void add_new_car(const string& name,int condition,int cost,const string& car_database){
         ofstream file(car_database,ios:: app);
         int rented=0;
         int due_year=-1;
         int due_month=-1;
         int due_date=-1;
         int id1=-1;
         int last_due_year=-1;
         int last_due_month=-1;
         int last_due_date=-1;
         int record_change=0;
         file<<name<<" "<<condition<<" "<<rented<<" "<<due_year<<" "<<due_month<<" "<<due_date<<" "<<id1<<" "<<cost<<" "<<last_due_year<<" "<<last_due_month<<" "<<last_due_date<<" "<<record_change<<"\n";
         cout<<"car added succesfully\n";
         
     }
     void remove_car(const string& name,int due_year,int due_month,int due_date,int id2,const string& car_database){
         ifstream inputFile(car_database);
         ofstream tempFile("temp1.txt");
         string line;
         int flag=0;
         while (getline(inputFile, line)) {
            istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(str1!=name){
                tempFile<<str1<<" "<<number1<<" "<<number2<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<id1<<" "<<cost<<" "<<last_due_year<<" "<<last_due_month<<" "<<last_due_date<<" "<<record_change<<"\n";
            }
            else{
                int status=1;
                tempFile<<str1<<" "<<number1<<" "<<status<<" "<<due_year<<" "<<due_month<<" "<<due_date<<" "<<id2<<" "<<cost<<" "<<due_year<<" "<<due_month<<" "<<due_date<<" "<<record_change<<"\n";
                flag=1;
            }
         }
         inputFile.close();
         tempFile.close();
         if(flag==0){
             cout<<"Please select a valid car\n";
         }
         else{
             remove(car_database.c_str());
             rename("temp1.txt",car_database.c_str());
             cout<<"Car rented succesfully\n";
         }

     }
     void delete_car(const string& model2,const string& car_database){
        ifstream inputFile(car_database);
         ofstream tempFile("temp100.txt");
         string line;
         
         while (getline(inputFile, line)) {
            istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(str1!=model2){
                tempFile<<str1<<" "<<number1<<" "<<number2<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<id1<<" "<<cost<<" "<<last_due_year<<" "<<last_due_month<<" "<<last_due_date<<" "<<record_change<<"\n";
            }
         }
         inputFile.close();
         tempFile.close();
         
             remove(car_database.c_str());
             rename("temp100.txt",car_database.c_str());
             cout<<"Car deleted succesfully\n";

     }
     void update_car(const string& model2,const string& car_database){
         ifstream inputFile(car_database);
         ofstream tempFile("temp101.txt");
         string line;
         
         while (getline(inputFile, line)) {
            istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(str1!=model2){
                tempFile<<str1<<" "<<number1<<" "<<number2<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<id1<<" "<<cost<<" "<<last_due_year<<" "<<last_due_month<<" "<<last_due_date<<" "<<record_change<<"\n";
            }
            else{
                cout<<"current car record:-\n";
                cout<<"model- "<<str1<<" condition- "<<number1<<" cost- "<<cost<<"\n";
                string new_model;
                int new_condition,new_cost;
                cout<<"Enter new model(only single string name allowed)\n";
                cin>>new_model;
                cout<<"Enter new condition(integer value)\n";
                cin>>new_condition;
                cout<<"Enter new cost(integer value)\n";
                cin>>new_cost;
                int status=0;
                int tempppp=-1;
                tempFile<<new_model<<" "<<new_condition<<" "<<status<<" "<<tempppp<<" "<<tempppp<<" "<<tempppp<<" "<<tempppp<<" "<<new_cost<<" "<<tempppp<<" "<<tempppp<<" "<<tempppp<<" "<<status<<"\n";
            }
         }
         inputFile.close();
         tempFile.close();
         
             remove(car_database.c_str());
             rename("temp101.txt",car_database.c_str());
     }
     int authenticate(const string& manager_database){
         int id2;
         cout<<"please enter your id(integer value):\n";
         cin>>id2;
         string password2;
         cout<<"please enter your password(only single string password allowed):\n";
         cin>>password2;
         ifstream file(manager_database);
         if (!file.is_open()) {
           cout << "Error opening file for writing!\n" << endl;
         }
         string line;
         int flag=0;
         string s3;
         while (getline(file, line)) {
            istringstream iss(line);
            string s1,s2;
            int no;
            iss>>s1;
            iss>>no;
            iss>>s2;
            if(id2==no){
                s3=s2;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"User Not found\n";
            return 0;
        }
        else{
            if(s3==password2){
                cout<<"Access granted\n";
                return 1;
            }
            else{
                cout<<"Wrong credentials\n";
                return 0;
            }
        }
        
     }
     
};
bool isFileEmpty(const string& filename) {
    ifstream file(filename);
    return file.peek() == ifstream::traits_type::eof();
}
int provide_id(const string& filename){
    if(isFileEmpty(filename)){
        ofstream file(filename);
        int no=1;
        file<<no;
        return no;
    }
    else{
        ifstream file(filename);
        string line;
        getline(file,line);
        istringstream iss(line);
        
        int no;
        iss>>no;
        ofstream tempFile("temp102.txt");
        no++;
        tempFile<<no;
        file.close();
        tempFile.close();
         
             remove(filename.c_str());
             rename("temp102.txt",filename.c_str());
        return no;     
    }
}
void show_dues(int id2,const string& customer_database){
    ifstream file(customer_database);
         string line;
         string s3;
         int flag=0;
         while (getline(file, line)) {
            istringstream iss(line);
            string s1,s2;
            int no,no1,no2;
            iss>>s1;
            iss>>no;
            iss>>s2;
            iss>>no1;
            iss>>no2;
            if(id2==no){
                flag=1;
                cout<<"Your dues are "<<no2<<"\n";
            }
        }
        if(flag==0){
            cout<<"Enter correct details\n";
        }
        file.close();
}
int find_cost(const string& model,const string& car_database){
    ifstream inputFile(car_database);
    string line;
    while (getline(inputFile, line)) {
            istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(str1==model){
                inputFile.close();
                return cost;
            }
         }
    return 0;
}
int find_record_of_customer(int id1, const string& customer_database){
    ifstream file(customer_database);
         string line;
         string s3;
         while (getline(file, line)) {
            istringstream iss(line);
            string s1,s2;
            int no,no1,no2;
            iss>>s1;
            iss>>no;
            iss>>s2;
            iss>>no1;
            iss>>no2;
            if(id1==no){
                return no1;
            }
        }
        file.close();
        return 10;
}
void change_car_record(const string& model, const string& car_database){
         ifstream inputFile(car_database);
         ofstream tempFile("temp2.txt");
         string line;
         
         while (getline(inputFile, line)) {
            istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(str1!=model){
                tempFile<<str1<<" "<<number1<<" "<<number2<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<id1<<" "<<cost<<" "<<last_due_year<<" "<<last_due_month<<" "<<last_due_date<<" "<<record_change<<"\n";
            }
            else{
                int status=1;
                tempFile<<str1<<" "<<number1<<" "<<number2<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<id1<<" "<<cost<<" "<<last_due_year<<" "<<last_due_month<<" "<<last_due_date<<" "<<status<<"\n";
                
            }
         }
         inputFile.close();
         tempFile.close();
         
             remove(car_database.c_str());
             rename("temp2.txt",car_database.c_str());
         
}
void change_car_dates(const string& model,int year1, int month1, int date1,const string& car_database){
    ifstream inputFile(car_database);
         ofstream tempFile("temp3.txt");
         string line;
         
         while (getline(inputFile, line)) {
            istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(str1!=model){
                tempFile<<str1<<" "<<number1<<" "<<number2<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<id1<<" "<<cost<<" "<<last_due_year<<" "<<last_due_month<<" "<<last_due_date<<" "<<record_change<<"\n";
            }
            else{
                
                tempFile<<str1<<" "<<number1<<" "<<number2<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<id1<<" "<<cost<<" "<<year1<<" "<<month1<<" "<<date1<<" "<<record_change<<"\n";
                
            }
         }
         inputFile.close();
         tempFile.close();
         
             remove(car_database.c_str());
             rename("temp3.txt",car_database.c_str());
    
}
class customer: public user{
    public:
     void add_customer(const string& name1, int id2, const string& password1,const string& customer_database){
         this->name=name1;
         this->id=id2;
         this->password=password1;
         ofstream file(customer_database,ios:: app);
         int customer_record=10;
         int dues=0;
         file<<name1<<" "<<id2<<" "<<password1<<" "<<customer_record<<" "<<dues<<"\n";
         file.close();
     }
     void update_customer(int id5,const string& customer_database){
         ifstream inputFile(customer_database);
         ofstream tempFile("temp205.txt");
         string line;
         
         while(getline(inputFile,line)){
             istringstream iss(line);
             string name,password1;
             int id1,record1,dues;
             iss>>name;
             iss>>id1;
             iss>>password1;
             iss>>record1;
             iss>>dues;
             if(id1==id5){
                 cout<<"Current customer details:- name- "<<name<<" id- "<<id1<<" password- "<<password1<<" customer record-"<<record1<<" dues- "<<dues<<"\n";
                 string new_name,new_password1;
                 int new_record1,new_dues;
                 cout<<"Please enter new name(only single string allowed)\n";
                 cin>>new_name;
                 cout<<"Please enter new password(only single string password allowed)\n";
                 cin>>new_password1;
                 cout<<"Please enter new customer record(integer value less than or equal to 10)\n";
                 cin>>new_record1;
                 cout<<"Please enter dues(integer value)\n";
                 cin>>new_dues;
                 tempFile<<new_name<<" "<<id1<<" "<<new_password1<<" "<<new_record1<<" "<<new_dues<<"\n";
             }
             else{
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
             }
         }
         inputFile.close();
         tempFile.close();
         remove(customer_database.c_str());
         rename("temp5.txt",customer_database.c_str());
     }
     int return_car(int id3,const string& model1,int condition1,const string& car_database){
         ifstream inputFile(car_database);
         ofstream tempFile("temp4.txt");
         string line;
         int flag=0;
         customer new2;
         while (getline(inputFile, line)) {
            istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(str1==model1&&id3==id1){
                flag=1;
                if(condition1<number1){
                    new2.change_record(id3,-1,"customer_database.txt");
                }
                int status=0;
                int temporary=-1;
                tempFile<<str1<<" "<<condition1<<" "<<status<<" "<<temporary<<" "<<temporary<<" "<<temporary<<" "<<temporary<<" "<<cost<<" "<<temporary<<" "<<temporary<<" "<<temporary<<" "<<status<<"\n";
            }
            else{
                tempFile<<str1<<" "<<number1<<" "<<number2<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<id1<<" "<<cost<<" "<<last_due_year<<" "<<last_due_month<<" "<<last_due_date<<" "<<record_change<<"\n";
            }
         }
         inputFile.close();
         tempFile.close();
         
             remove(car_database.c_str());
             rename("temp4.txt",car_database.c_str());
             if(flag==1){
                 return 1;
             }
             else{
                 return 0;
             }
     }
     int authenticate(const string& customer_database){
         int id2;
         cout<<"please enter your id(integer value):\n";
         cin>>id2;
         string password2;
         cout<<"please enter your password(only single string password allowed):\n";
         cin>>password2;
         ifstream file(customer_database);
         string line;
         int flag=0;
         string s3;
         while (getline(file, line)) {
            istringstream iss(line);
            string s1,s2;
            int no,no1,no2;
            iss>>s1;
            iss>>no;
            iss>>s2;
            iss>>no1;
            iss>>no2;
            if(id2==no){
                s3=s2;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"User Not found\n";
            return 0;
        }
        else{
            if(s3==password2){
                cout<<"Access granted\n";
                return id2;
            }
            else{
                cout<<"Wrong credentials\n";
                return 0;
            }
        }
        return 0;
     }
     void show_my_cars(int id2,const string& car_database ){
         ifstream inputFile(car_database);
          string line;
          int flag=0;
          while (getline(inputFile, line)) {
          istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(id1==id2){
                cout<<str1<<" "<<number1<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<cost<<"\n";
                flag=1;
            }
          }
          if(flag==0){
              cout<<"No car rented\n";
          }
     }
     void change_record(int id2,int record_change,const string& customer_database){
         ifstream inputFile(customer_database);
         ofstream tempFile("temp5.txt");
         string line;
         int flag=0;
         while(getline(inputFile,line)){
             istringstream iss(line);
             string name,password1;
             int id1,record1,dues;
             iss>>name;
             iss>>id1;
             iss>>password1;
             iss>>record1;
             iss>>dues;
             if(id1==id2){
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1+record_change<<" "<<dues<<"\n";
                 flag=1;
             }
             else{
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
             }
         }
         inputFile.close();
         tempFile.close();
         remove(customer_database.c_str());
         rename("temp5.txt",customer_database.c_str());
     }
     void delete_customer(int id5,const string& customer_database){
        ifstream inputFile(customer_database);
         ofstream tempFile("temp203.txt");
         string line;
         
         while(getline(inputFile,line)){
             istringstream iss(line);
             string name,password1;
             int id1,record1,dues;
             iss>>name;
             iss>>id1;
             iss>>password1;
             iss>>record1;
             iss>>dues;
             if(id1!=id5){
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
             }
             
         }
         inputFile.close();
         tempFile.close();
         remove(customer_database.c_str());
         rename("temp203.txt",customer_database.c_str()); 
     }
     void change_dues(int id2,int dues_change1,const string& customer_database){
         ifstream inputFile(customer_database);
         ofstream tempFile("temp6.txt");
         string line;
         int flag=0;
         while(getline(inputFile,line)){
             istringstream iss(line);
             string name,password1;
             int id1,record1,dues;
             iss>>name;
             iss>>id1;
             iss>>password1;
             iss>>record1;
             iss>>dues;
             if(id1==id2){
                 dues+=dues_change1;
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
                 flag=1;
             }
             else{
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
             }
         }
         inputFile.close();
         tempFile.close();
         remove(customer_database.c_str());
         rename("temp6.txt",customer_database.c_str());
     }
     void check_customer(int id2,const string& customer_database,const string& car_database){
         ifstream inputFile(car_database);
         string line;
         int change_in_dues=0;
         int change_in_record=0;
         while(getline(inputFile,line)){
             istringstream iss(line);
             string str1;
             int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
             iss >> str1;
             iss >> number1;
             iss>>number2;
             iss>>due_year1;
             iss>>due_month1;
             iss>>due_date1;
             iss>>id1;
             iss>>cost;
             iss>>last_due_year;
             iss>>last_due_month;
             iss>>last_due_date;
             iss>>record_change;
             if(id2==id1){
                if(record_change==0){
                    if(later(due_year1,due_month1,due_date1)){
                        change_in_record--;
                        change_car_record(str1,"car_database.txt");
                    }
                } 
                change_in_dues+=(-1*(no_of_days(last_due_year,last_due_month,last_due_date))*cost*(5))/4;
                change_car_dates(str1,year,month,date,"car_database.txt");
             }
             customer new1;
             if(change_in_record){
                 new1.change_record(id2,change_in_record,"customer_database.txt");
             }
             if(change_in_dues>0){
                 new1.change_dues(id2,change_in_dues,"customer_database.txt");
             }
         }
     }
     void rent_car(const string& model,int due_year,int due_month,int due_date,int id, const string& car_database){
         manager manager2;
         manager2.remove_car(model,due_year,due_month,due_date,id,car_database);
         customer new2;
         int cost=find_cost(model,car_database);
        //  cout<<cost<<" "<<no_of_days(due_year,due_month,due_date)<<"\n";
         new2.change_dues(id,(no_of_days(due_year,due_month,due_date))*cost,"customer_database.txt");
         return;
     }
};
class employee: public user{
    public:
     void add_employee(const string& name1, int id2, const string& password1,const string& employee_database){
         this->name=name1;
         this->id=id2;
         this->password=password1;
         ofstream file(employee_database,ios:: app);
         int employee_record=10;
         int dues=0;
         file<<name1<<" "<<id2<<" "<<password1<<" "<<employee_record<<" "<<dues<<"\n";
         file.close();
     }
     void update_employee(int id5,const string& employee_database){
         ifstream inputFile(employee_database);
         ofstream tempFile("temp208.txt");
         string line;
         
         while(getline(inputFile,line)){
             istringstream iss(line);
             string name,password1;
             int id1,record1,dues;
             iss>>name;
             iss>>id1;
             iss>>password1;
             iss>>record1;
             iss>>dues;
             if(id1==id5){
                 cout<<"Current employee details:- name- "<<name<<" id- "<<id1<<" password- "<<password1<<" customer record-"<<record1<<" dues- "<<dues<<"\n";
                 string new_name,new_password1;
                 int new_record1,new_dues;
                 cout<<"Please enter new name(only single string allowed)\n";
                 cin>>new_name;
                 cout<<"Please enter new password(only integer value)\n";
                 cin>>new_password1;
                 cout<<"Please enter new employee record(value less than or equal to 10)\n";
                 cin>>new_record1;
                 cout<<"Please enter dues(integer value)\n";
                 cin>>new_dues;
                 tempFile<<new_name<<" "<<id1<<" "<<new_password1<<" "<<new_record1<<" "<<new_dues<<"\n";
             }
             else{
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
             }
         }
         inputFile.close();
         tempFile.close();
         remove(employee_database.c_str());
         rename("temp208.txt",employee_database.c_str());
     }
     void delete_employee(int id5,const string& employee_database){
        ifstream inputFile(employee_database);
         ofstream tempFile("temp207.txt");
         string line;
         
         while(getline(inputFile,line)){
             istringstream iss(line);
             string name,password1;
             int id1,record1,dues;
             iss>>name;
             iss>>id1;
             iss>>password1;
             iss>>record1;
             iss>>dues;
             if(id1!=id5){
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
             }
             
         }
         inputFile.close();
         tempFile.close();
         remove(employee_database.c_str());
         rename("temp207.txt",employee_database.c_str()); 
     }
     int authenticate(const string& employee_database){
         int id2;
         cout<<"please enter your id(integer value):\n";
         cin>>id2;
         string password2;
         cout<<"please enter your password(only single string password allowed):\n";
         cin>>password2;
         ifstream file(employee_database);
         string line;
         int flag=0;
         string s3;
         while (getline(file, line)) {
            istringstream iss(line);
            string s1,s2;
            int no,no1,no2;
            iss>>s1;
            iss>>no;
            iss>>s2;
            iss>>no1;
            iss>>no2;
            if(id2==no){
                s3=s2;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"User Not found\n";
            return 0;
        }
        else{
            if(s3==password2){
                cout<<"Access granted\n";
                return id2;
            }
            else{
                cout<<"Wrong credentials\n";
                return 0;
            }
        }
        return 0;
     }
     void show_my_cars(int id2,const string& car_database ){
         ifstream inputFile(car_database);
          string line;
          int flag=0;
          while (getline(inputFile, line)) {
          istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(id1==id2){
                cout<<str1<<" "<<number1<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<cost<<"\n";
                flag=1;
            }
          }
          if(flag==0){
              cout<<"No car rented\n";
          }
     }
     void check_employee(int id2,const string& employee_database,const string& car_database){
         ifstream inputFile(car_database);
         string line;
         int change_in_dues=0;
         int change_in_record=0;
         while(getline(inputFile,line)){
             istringstream iss(line);
             string str1;
             int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
             iss >> str1;
             iss >> number1;
             iss>>number2;
             iss>>due_year1;
             iss>>due_month1;
             iss>>due_date1;
             iss>>id1;
             iss>>cost;
             iss>>last_due_year;
             iss>>last_due_month;
             iss>>last_due_date;
             iss>>record_change;
             if(id2==id1){
                if(record_change==0){
                    if(later(due_year1,due_month1,due_date1)){
                        change_in_record--;
                        change_car_record(str1,"car_database.txt");
                    }
                } 
                change_in_dues+=(-1*(no_of_days(last_due_year,last_due_month,last_due_date))*cost*17*5)/80;
                change_car_dates(str1,year,month,date,"car_database.txt");
             }
             customer new1;
             if(change_in_record){
                 new1.change_record(id2,change_in_record,"employee_database.txt");
             }
             if(change_in_dues>0){
                 new1.change_dues(id2,change_in_dues,"employee_database.txt");
             }
         }
     }
     void change_record(int id2,int record_change,const string& employee_database){
         ifstream inputFile(employee_database);
         ofstream tempFile("temp25.txt");
         string line;
         int flag=0;
         while(getline(inputFile,line)){
             istringstream iss(line);
             string name,password1;
             int id1,record1,dues;
             iss>>name;
             iss>>id1;
             iss>>password1;
             iss>>record1;
             iss>>dues;
             if(id1==id2){
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1+record_change<<" "<<dues<<"\n";
                 flag=1;
             }
             else{
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
             }
         }
         inputFile.close();
         tempFile.close();
         remove(employee_database.c_str());
         rename("temp25.txt",employee_database.c_str());
     }
     void change_dues(int id2,int dues_change1,const string& employee_database){
         ifstream inputFile(employee_database);
         ofstream tempFile("temp26.txt");
         string line;
         int flag=0;
         while(getline(inputFile,line)){
             istringstream iss(line);
             string name,password1;
             int id1,record1,dues;
             iss>>name;
             iss>>id1;
             iss>>password1;
             iss>>record1;
             iss>>dues;
             if(id1==id2){
                 dues+=dues_change1;
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
                 flag=1;
             }
             else{
                 tempFile<<name<<" "<<id1<<" "<<password1<<" "<<record1<<" "<<dues<<"\n";
             }
         }
         inputFile.close();
         tempFile.close();
         remove(employee_database.c_str());
         rename("temp26.txt",employee_database.c_str());
     }
     void rent_car(const string& model,int due_year,int due_month,int due_date,int id, const string& car_database){
         manager manager2;
         manager2.remove_car(model,due_year,due_month,due_date,id,car_database);
         employee new2;
         int cost=((17)*find_cost(model,car_database))/20;
        //  cout<<cost<<" "<<no_of_days(due_year,due_month,due_date)<<"\n";
         new2.change_dues(id,(no_of_days(due_year,due_month,due_date))*cost,"employee_database.txt");
         return;
     }
     int return_car(int id3,const string& model1,int condition1,const string& car_database){
         ifstream inputFile(car_database);
         ofstream tempFile("temp24.txt");
         string line;
         int flag=0;
         customer new2;
         while (getline(inputFile, line)) {
            istringstream iss(line);
            string str1;
            int number1,number2,due_date1,due_month1,due_year1,id1,cost,last_due_year,last_due_month,last_due_date,record_change;
            iss >> str1;
            iss >> number1;
            iss>>number2;
            iss>>due_year1;
            iss>>due_month1;
            iss>>due_date1;
            iss>>id1;
            iss>>cost;
            iss>>last_due_year;
            iss>>last_due_month;
            iss>>last_due_date;
            iss>>record_change;
            if(str1==model1&&id3==id1){
                flag=1;
                if(condition1<number1){
                    new2.change_record(id3,-1,"employee_database.txt");
                }
                int status=0;
                int temporary=-1;
                tempFile<<str1<<" "<<condition1<<" "<<status<<" "<<temporary<<" "<<temporary<<" "<<temporary<<" "<<temporary<<" "<<cost<<" "<<temporary<<" "<<temporary<<" "<<temporary<<" "<<status<<"\n";
            }
            else{
                tempFile<<str1<<" "<<number1<<" "<<number2<<" "<<due_year1<<" "<<due_month1<<" "<<due_date1<<" "<<id1<<" "<<cost<<" "<<last_due_year<<" "<<last_due_month<<" "<<last_due_date<<" "<<record_change<<"\n";
            }
         }
         inputFile.close();
         tempFile.close();
         
             remove(car_database.c_str());
             rename("temp24.txt",car_database.c_str());
             if(flag==1){
                 return 1;
             }
             else{
                 return 0;
             }
     }
     
};
int menu_customer(){
    cout<<"please select one of the following:-\n";
    cout<<"1.Login\n2.Add new customer\n3.Exit\n";
    int a;
    cin>>a;
    return a;
}
//bug in show my cars
void customer_handling(){
    string name;
    int id;
    string password;
    customer new1;
    manager manager1;
    int id1;
    int flag=1;
    while(flag){
    switch(menu_customer()){
        case 1:
          id1=new1.authenticate("customer_database.txt");
          if(id1){
              
              int flag1=1;
              while(flag1){
              cout<<"Please select one of the following option:-\n1.Show available cars\n2.Show my rented cars\n3.Rent a car\n4.Return the car\n5.Show dues\n6.Clear dues\n7.Exit\n";
              int a;
              cin>>a;
              string model1;
              
              int condition1;
              int due_year1,due_month1,due_date1;
              switch(a){
                  case 1:
                    manager1.show_available_cars("car_database.txt");
                    break;
                  case 2:
                    new1.check_customer(id1,"customer_database.txt","car_database.txt");
                    new1.show_my_cars(id1,"car_database.txt");
                    break;
                  case 3:
                    new1.check_customer(id1,"customer_database.txt","car_database.txt");
                    if(find_record_of_customer(id1,"customer_database.txt")<6){
                        cout<<"Not eligible to rent a car\n";
                    }
                    else{
                    cout<<"Please enter car model(only single string allowed)\n";
                    cin>>model1;
                    cout<<"please enter due year(only integer value)\n";
                    cin>>due_year1;
                    cout<<"please enter due month(only integer value from 1 to 12)\n";
                    cin>>due_month1;
                    cout<<"please enter due date(only integer value from 1 to 31)\n";
                    cin>>due_date1;
                    new1.rent_car(model1,due_year1,due_month1,due_date1,id1,"car_database.txt");
                    }
                    break;
                  case 4:
                    new1.check_customer(id1,"customer_database.txt","car_database.txt");
                    cout<<"Please enter model(only single string allowed)\n";
                    cin>>model1;
                    cout<<"please enter car condition(integer value ranging from 0 to 10)\n";
                    cin>>condition1;
                    if(new1.return_car(id1,model1,condition1,"car_database.txt")==0){
                        cout<<"Enter correct details\n";
                    }
                    else{
                        cout<<"Car returned successfully\n";
                    }
                    break;
                  case 5:
                    show_dues(id1,"customer_database.txt");
                    break;
                  case 6:
                    
                    show_dues(id1,"customer_database.txt");
                    cout<<"Enter money to be deposited(integer value):-\n";
                    int money;
                    cin>>money;
                    new1.change_dues(id1,-1*money,"customer_database.txt");
                    show_dues(id1,"customer_database.txt");
                    break;
                  case 7:
                    flag1=0;
                    break;
                  default:
                    cout<<"Please select valid option\n";
                    break;
              }
              }
              
          }
        //   else{
        //       cout<<"Wrong credentials\n";
        //   }
          break;
        case 2:
          cout<<"please enter name(single string allowed):\n";
          cin>>name;
        //   cout<<"please enter id:\n";
        //   cin>>id;
          cout<<"please enter password(single string allowed):\n";
          cin>>password;
          id=provide_id("id.txt");
          cout<<"Your id is: "<<id<<"\n";
          new1.add_customer(name,id,password,"customer_database.txt");
          cout<<"Registered successfully\nPlease login again to use\n";
          break;
        case 3:
          flag=0;
          break;
        default:
          cout<<"please select valid option\n";
          break;
    }
    }
}
void manager_handling(){
    manager manager1;
    int x=manager1.authenticate("manager_database.txt");
    if(x){
        int flag=1;
        while(flag){
        cout<<"please select one of the following:-\n1.add new car\n2.delete a car\n3.update a car record\n4.add a customer\n5.delete a customer\n6.modify a customer\n7.add an employee\n8.delete an employee\n9.modify an employee\n10.Show car record\n11.exit\n";
        int a;
        cin>>a;
        if(a==1){
            cout<<"please enter car model(only single string allowed)\n";
            string s;
            cin>>s;
            int con;
            cout<<"please enter car condition(integer value ranging from 0 to 10)\n";
            cin>>con;
            int cost;
            cout<<"please enter car cost(integer value)\n";
            cin>>cost;
            manager1.add_new_car(s,con,cost,"car_database.txt");
        }
        else if(a==2){
            string s;
            cout<<"please enter car model(only single string allowed)\n";//i am assuming that car model to be entered will not be rented at this moment
            cin>>s;
            manager1.delete_car(s,"car_database.txt");
        }
        else if(a==3){
            string s;
            cout<<"please enter car model(only single string allowed)\n";//i am assuming that car model to be entered will not be rented at this moment
            cin>>s;
            manager1.update_car(s,"car_database.txt");
        }
        else if(a==4){
            string s2,s3;
            cout<<"Please enter name(only single string allowed)\n";
            cin>>s2;
            cout<<"Please enter password(only single string allowed)\n";
            cin>>s3;
            int id5;
            id5=provide_id("id.txt");
            cout<<"Your id is: "<<id5<<"\n";
            customer c1;
            c1.add_customer(s2,id5,s3,"customer_database.txt");
            cout<<"Customer added successfully\n";
        }
        else if(a==5){
            int id5;
            cout<<"Please enter id of customer(to be deleted)(only single string allowed)\n";//i am assuming this customer has no car rented in his name
            cin>>id5;
            customer c1;
            c1.delete_customer(id5,"customer_database.txt");
        }
        else if(a==6){
            int id5;
            cout<<"Please enter id of customer(to be updated)(only single string allowed)\n";
            cin>>id5;
            customer c1;
            c1.update_customer(id5,"customer_database.txt");
        }
        else if(a==7){
            string s2,s3;
            cout<<"Please enter name(only single string allowed)\n";
            cin>>s2;
            cout<<"Please enter password(only single string allowed)\n";
            cin>>s3;
            int id5;
            id5=provide_id("id.txt");
            cout<<"Your id is: "<<id5<<"\n";
            employee c1;
            c1.add_employee(s2,id5,s3,"employee_database.txt");
        }
        else if(a==8){
            int id5;
            cout<<"Please enter id of employee(to be deleted)(only single string allowed)\n";//i am assuming this customer has no car rented in his name
            cin>>id5;
            employee c1;
            c1.delete_employee(id5,"employee_database.txt");
        }
        else if(a==9){
            int id5;
            cout<<"Please enter id of employee(to be updated)(only single string allowed)\n";
            cin>>id5;
            employee c1;
            c1.update_employee(id5,"employee_database.txt");
        }
        
        else if(a==10){
            show_car_record("car_database.txt");
        }
        else if(a==11){
            flag=0;
            return;
        }
        else{
            cout<<"Please select valid option\n";
            
        }
        }
    }
    else{
        return;
    }
    
}
int menu_employee(){
    cout<<"please select one of the following:-\n";
    cout<<"1.Login\n2.Add new employee\n3.Exit\n";
    int a;
    cin>>a;
    return a;
}
void employee_handling(){
    string name;
    int id;
    string password;
    employee new1;
    manager manager1;
    int id1;
    int flag=1;
    while(flag){
        switch(menu_employee()){
            case 1:
             id1=new1.authenticate("employee_database.txt");
             if(id1){
                 int flag1=1;
                 while(flag1){
                   cout<<"Please select one of the following option:-\n1.Show available cars\n2.Show my rented cars\n3.Rent a car\n4.Return the car\n5.Show dues\n6.Clear dues\n7.Exit\n";
                   int a;
                   cin>>a;
                   string model1;
                   int condition1;
                   int due_year1,due_month1,due_date1;
                   switch(a){
                      case 1:
                       manager1.show_available_cars("car_database.txt");
                       break;
                      case 2:
                       new1.check_employee(id1,"employee_database.txt","car_database.txt");
                       new1.show_my_cars(id1,"car_database.txt");
                       break;
                      case 3:
                       new1.check_employee(id1,"employee_database.txt","car_database.txt");
                       if(find_record_of_customer(id1,"employee_database.txt")<6){
                          cout<<"Not eligible to rent a car\n";
                       }
                       else{
                         cout<<"Please enter car model(only single string allowed)\n";
                         cin>>model1;
                         cout<<"please enter due year(only integer value)\n";
                         cin>>due_year1;
                         cout<<"please enter due month(only integer value from 1 to 12)\n";
                         cin>>due_month1;
                         cout<<"please enter due date(only integer value from 1 to 31)\n";
                         cin>>due_date1;
                         new1.rent_car(model1,due_year1,due_month1,due_date1,id1,"car_database.txt");
                        }
                        break;
                       case 4:
                         new1.check_employee(id1,"employee_database.txt","car_database.txt");
                         cout<<"Please enter model(only single string allowed)\n";
                         cin>>model1;
                         cout<<"please enter car condition(only integer value)\n";
                         cin>>condition1;
                         if(new1.return_car(id1,model1,condition1,"car_database.txt")==0){
                           cout<<"Enter correct details\n";
                         }
                         else{
                           cout<<"Car returned successfully\n";
                         }
                         break;
                        case 5:
                         show_dues(id1,"employee_database.txt");
                         break;
                        case 6:
                         show_dues(id1,"employee_database.txt");
                         cout<<"Enter money to be deposited(only integer value):-\n";
                         int money;
                         cin>>money;
                         new1.change_dues(id1,-1*money,"employee_database.txt");
                         show_dues(id1,"employee_database.txt");
                         break;
                        case 7: 
                         flag1=0;
                         break;
                        default:
                         cout<<"Please select valid option\n";
                         break;
                   }
                 }
             }
             else{
                 cout<<"Wrong credentials\n";
             }
             break;
            case 2:
             cout<<"please enter name(only single string allowed):\n";
             cin>>name;
            //  cout<<"please enter id:\n";
            //  cin>>id;
             cout<<"please enter password(only single string allowed):\n";
             cin>>password;
             id=provide_id("id.txt");
             cout<<"Your id is: "<<id<<"\n";
             new1.add_employee(name,id,password,"employee_database.txt");
             cout<<"Registered successfully\nPlease login again to use\n";
             break;
            case 3: 
             flag=0;
             break;
            default:
             cout<<"please select valid option\n";
             break;
        }
    }
}
int main(){
    manager manager1;
    manager1.add_manager("manager1",123,"12345","manager_database.txt");
    int flag1=1;
    customer new3;
    while(flag1){
    cout<<"please select one of the following:-\n1.customer\n2.employee\n3.manager\n4.Exit\n";
    int a;
    cin>>a;
    int flag=1;
    while(flag){
        switch(a){
            case 1:
              customer_handling();
              flag=0;
              break;
            case 2:
              employee_handling();
              flag=0;
              break;
            case 3:
              manager_handling();
              flag=0;
              break;
            
            case 4:
              flag=0;
              flag1=0;
              break;
            default:
              cout<<"Please select valid option\n";
        }
    }
    }
}