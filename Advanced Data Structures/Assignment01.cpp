/* Assignment 1: Flight management: There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. The cost of the edge can be the time that flight takes to reach city B from A, or the amount of fuel used for the journey. Write a menu driven C++ program to represent this as a graph using adjacency matrix and adjacency list. The node can be represented by the airport name or name of the city. Check whether cities are connected through flight or not. Compare the storage representation.*/

#include<iostream>
using namespace std;

class Graph
{
	public: 
		int i,j,s1,d1;
		string src,dest;
		int Adjmat[10][10];
		int Time[10][10];
		string city[10];
		int n;
		
	void data() //member function: Initializes the city names entered by the user and sets up the adjacency matrix.
	{
		cout<<"Enter the Number of Cities: ";
		cin>>n;
	
		cout<<"Enter Name of Cities: ";
		for(i=0;i<n;i++)
		{
			cin>>city[i];
		}
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				Adjmat[i][j]=0;
				Time[i][j]=0;
			}
		}
		
	}
	void addflight()
	{
		
		cout<<"Enter the Starting and Destination City: ";
		cin>>src>>dest;
		
		
		for(i=0;i<n;i++)
		{	
			if(city[i]==src)
			{
				s1=i;
			}
		}
		
		for(i=0;i<n;i++)
		{	
			if(city[i]==dest)
			{
				d1=i;
			}
		}
		
		cout<<"Enter Time: ";
		cin>>Time[s1][d1];
		Adjmat[s1][d1]=1;
		Adjmat[d1][s1]=1;
		
	}
	
	void displayArray()   //member function: Displays the flight data using an adjacency matrix, including city names and flight times.
	{
		cout<<endl;
		
		 for(j=0;j<n;j++)
		 {  cout<<"\t"<<city[j];  }

		 for(i=0;i<n;i++)
		 {  
		 	cout<<"\n "<<city[i];
		    for(j=0;j<n;j++)
		    {   
				cout<<"\t"<<Time[i][j];
		    }
		        cout<<"\n";
		 }
	}
	
	
	void displayList() //member function: Placeholder function to display flight data using an adjacency list.
	{
    	for (i = 0; i < n; i++)
    	{
        	cout << city[i] << " is connected to: ";
        
        	for (j = 0; j < n; j++)
        	{
            	if (Adjmat[i][j] == 1)
            	{
                	cout << city[j] << " ";
            	}
        	}

        	cout << endl;
    	}
	}
		
};

int main()
{	
	Graph g;
	int choice;
	
	g.data();

	do
	{
		cout<<"\t\t---------------- Flight Management ----------------"<<endl;
		cout<<"\n1) Add Flight \n2) Display using Adjacency Matrix \n3) Display using Adjacency List \n4)exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
					g.addflight();
					break;
			case 2:
					g.displayArray();
					break;
			case 3:
					g.displayList();
					break;
					
			case 4: cout<<"Thank you for visit......!!"<<endl;
					break;
			default:
					cout<<"Wrong Choice!! Try Again...";
					break;
		}
		
	}while(choice!=4);
	
	return 0;
}