/*
Queue Applications: Scheduling/Resource allocatioN
Check if Xavier can give change to every person in the queue

Customers are standing in a queue waiting to buy an ice-cream from Xavier which costs 2. 
The possible currencies are $1, $5, $10, and $20. 
Initially, Xavier has no money. 
Check if Xavier will be able to provide change to every person waiting to buy an ice-cream.

queue of customers, each buying one $2 ice cream
queue stores how much the customer pays
print out:
    - the index of the customer Xavier can't refund and Xavier's revenue
    - "Every customer refunded" + Xavier's revenue, did he make and money
Modification: also let customers buy more than one ice cream, Xavier has 100 in stock
    - the index of the customer Xavier is sold out at
    - how many Xavier has left after there are no more customers
Modification two: average
    - ice creames sold
    - revenue
*/


#include <iostream>
#include <iostream>
#include <queue>
#include "moneyBag.h"
#include <cstdlib> //size_t
#include <map>
using namespace std;

int main(){
    moneyBag Xavier;    //Xaviers money bag
    queue<int> clientMoney;  //clients in the line
    queue<int> notPaid;
    pair<int, int> person;
    map<int, int> waitlist;
    map<int,int>::iterator it;

    clientMoney.push(4);
    clientMoney.push(2);
    clientMoney.push(2);
    clientMoney.push(2);
    clientMoney.push(5);
    clientMoney.push(2);
    clientMoney.push(10);
    int size = clientMoney.size();
    for (int i=1;i<=size;++i)
    {
        //GET THE CHANGE. CAN YOU PAY THE GUY BACK IF HE BUYS AN ICECREAM?
        int change = clientMoney.front() - 2;
        cout<<"i: "<<i<<"    money: $"<<clientMoney.front()<<"     Xavier: $"<<Xavier.total()<<"      change: $"<<change<<endl;

        //THERE WAS A GUY I COULDNT GIVE CHANGE TO, I PUSHED HIM TO THE SIDE, I CAN NOW HAVE ENOUGH MONEY TO PAY HIM HIS CHANGE. SO I ACEPT HIM:
        if (Xavier.total() >= notPaid.front()-2){
            Xavier.putInBag(notPaid.front());
            int change = clientMoney.front() - 2;
            Xavier.takeOutBag(change);
            it = waitlist.begin();
            it=waitlist.find(notPaid.front());
            cout<<"Paid Customer "<<it->second<<"  Xavier's Revenue: $"<<Xavier.total()<<endl;
            notPaid.pop();
        }
        //I GOT ENOUGH MONEY TO GIVE CHANGE:
        else if (Xavier.total() >= change){
            Xavier.putInBag(clientMoney.front());
            Xavier.takeOutBag(change);
        }
        //I CANT GIVE THIS GUY CHANGE, PUSH HIM TO THE SIDE SO THAT I CAN PAY HIM HIS CHANGE WHEN I HAVE ENOUGH MONEY
        else{
            notPaid.push(clientMoney.front());  //pushing the money of the denied customer to front of queue. will use this as a key to the customer's index
            person.first = notPaid.front();     //money that the denied customer has
            person.second = i;                  //index in line of the denied person
            waitlist.insert(person);            //put the person in the waitlist map
            cout<<"Didnt pay customer: "<<i<<" He had: $"<<clientMoney.front()<<endl;
        }
        clientMoney.pop();
    }
    Xavier.printEach();
}


