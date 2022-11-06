#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;


class card{
int *arr;
char card_name[15];
int size;




public:
    card(int n){
        arr= new int[n];

        size=n;

    }
    int Sum(int num){
        int sum=0;  
        while (num!=0)
                {
                int rem=num%10;
                sum+=rem;
                num=num/10;
                }
                return sum;

    }
bool card_check(string card_nun){

        int sum=0;
        for(int i=0;i<size;i++){
            if(card_nun[i]>='0'&& card_nun[i]<='9'){
            int num =(card_nun[i]-'0');
            arr[i]=num;
            }
            else{
                return false;
            }
        }


        for(int i=0;i<size;i+=2){
            arr[i]*=2;
            if(arr[i]>9){
                arr[i]=Sum(arr[i]);
            } 
       }



          for(int i=0;i<size;i++){
           sum+=arr[i];
        }
       
    return sum%10==0;




}
void Card_name(string card_no){
    if(card_no[0]=='4'){
        strcpy(card_name,"visa card");

    }
    else if(card_no[0]=='6' && (card_no[1]=='0' || card_no[1]=='5') ){

        strcpy(card_name,"Rupay card ");

    }
    else if(card_no[0]=='8' && (card_no[1]=='1' || card_no[1]=='2' )) {


        strcpy(card_name,"Rupay card ");

    
    }
    else if(card_no[0]=='5' && (card_no[1]=='0' && card_no[2]=='8') ) {


        strcpy(card_name,"Rupay card ");

    
    }
    else if(card_no[0]=='3' && card_no[5]=='0' && (card_no[2]=='3' || card_no[2]=='6') ) {


        strcpy(card_name,"Rupay card ");

    
    }
     else if(card_no[0]=='5' && (card_no[1]=='1' || card_no[1]=='5') ){

        strcpy(card_name,"Mastercard card ");

    }
     else if(card_no[0]=='2' && (card_no[1]=='2' || card_no[1]=='7') && card_no[2]=='2' && (card_no[3]=='1' || card_no[3]=='1') ){

        strcpy(card_name,"Mastercard card ");

    }
}
    void display(){
        cout<<" You enter a valid  "<<card_name<<" detail"<<endl;


    }
    ~card(){}
    
};
int main(){
    char op;

   do
   {
    system("CLS");
     char *card_no=new char[20];
    cout<<"Enter the card number ";
    cin>>card_no;
    int n=strlen(card_no);
    card obj(n);

    if(obj.card_check(card_no)){
        obj.Card_name(card_no);
        obj.display();


    }
    else{
        cout<<"NOT A VALID CARD "<<endl;;
    }
    
    delete [] card_no;
    
    cout<<"Press 'y' to check again"<<endl<<"Press 'n' for exit "<<endl;
    cin>>op;
    fflush(stdin);
   } while (op =='y');
   
    return 0;
}