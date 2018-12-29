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
#include <queue>
#include <cstdlib> //size_t
#include "moneyBag.h"
using namespace std;

int main(){
    moneyBag moneyBag(); //Xaviers money bag
    queue<int> client;  //clients in the line
    const int lineLength = 7;
    //test
        int clientMoney[lineLength] = {2, 2, 2, 5, 2, 10, 16};
    int *clientIndex = new int[lineLength]; 
    for (int i=0;i<lineLength;++i)
    {
        // SET UP THE LINE:
        clientIndex[i]=clientMoney[i];

        //     clientMoney = rand() % 20+ 1;         //generate a random number from $1 to $20
        //     client.push(clientMoney);             //makeing a line with everyones money on hand  
        //     clientIndex[i] = client.front();
        //     cout << "client: "<< i <<"   $"<<clientMoney<< endl;  
    // }
}



// int main()
// {
//     queue<int> client;  //clients in the line
//     int money = 0;      //starting out with no money
//     int lineLength = 10;
//     int clientIndex[lineLength]; 
//     for (int i=0;i<lineLength;i++)
//     {
//         // SET UP THE LINE:
//         money cash;
//         cash.value = rand() % 20+ 1;         //generate a random number from $1 to $20
//         client.push(clientMoney);             //makeing a line with everyones money on hand  
//         clientIndex[i] = client.front();
//         cout << "client: "<< i <<"   $"<<clientMoney<< endl;  
//     }
//     int i=0;
//     while (!client.empty())
//     {
//         //CHECK IF YOU CAN PAY THE GUY OR NOT
//         int change = client.front()-2;
//         money = money + change;
//         if (change > money)//if i dont have change  
//         {
//             cout<<"cant pay client #"<<i<<endl;
//             client.pop();
//         }
//         else if (change <= money)   //if i do have change,  
//         {
//             money = money + 2;
//             cout<<"paid client #"<<i<<endl;
//             client.pop();
//         }
//         i++;
//     }
// }


/*
//THIS IS CODE TO FIND HOW MANY $10 CAN FIT:
int main()
{
    int x = 30;
    int z = 0;
    while(x-10>=0){
        ++z;
        x = x-10;
    }
    cout<<z;

    return 0;
}
*/

