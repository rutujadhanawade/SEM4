#include <iostream>
using namespace std;

class node{
	string key,type,ival;
	int chain;
public:
	friend class HashTable;
};

class HashTable{
	node* HT;
	int n;
public:
	HashTable(int d){
		n=d;
		HT=new node[n];
		for(int i=0;i<n;i++){
			HT[i].key="#";
			HT[i].chain=-1;
			}
	}
	void create();
	void withoutinsert(node); //linear probing without replacement
	void withinsert(node);	//linear probing with replacement
	void find();
	void del();
	void modify();
};


void HashTable::modify(){
string k,newival;
int v,u;

cout<<"\nEnter key of element to be modified";
cin>>k;
cout<<"\nEnter new initial value: ";
cin>>newival;

int l=k.length()%n;

	if(HT[l].key==k)
		HT[l].ival=newival;
		else{
		int v;
		v=l;
		u=HT[l].chain;
			while(u!=-1&&HT[v].key!=k)
			{
			v=u;
			u=HT[v].chain;
			}
			if(HT[v].key==k)
			HT[v].ival=newival;
			else
			cout<<"\nEntry does not exists!";

		}
}

void HashTable::del(){
string k;
int v,u;

cout<<"\nEnter key of element to be deleted";
cin>>k;

int l=k.length()%n;

	if(HT[l].key==k){
		HT[l].key="#";
		HT[l].type="";
		HT[l].ival="";
		cout<<"\nDELETED SUCCESSFULLY";
		}
		else{
		int v;
		v=l;
		u=HT[l].chain;
			while(u!=-1&&HT[v].key!=k)
			{
			v=u;
			u=HT[v].chain;
			}
			if(HT[v].key==k){
			HT[v].key="#";
			HT[v].type="";
			HT[v].ival="";
			cout<<"\nDELETED SUCCESSFULLY";
			}
			else
			cout<<"\nENTRY DOES NOT EXISTS";

		}
}

void HashTable::find(){
string k;
int v,u;

cout<<"\nEnter key of element to be found";
cin>>k;

int l=k.length()%n;

	if(HT[l].key==k)
		cout<<"\nFOUND!\n"<<HT[l].key<<HT[l].type<<HT[l].ival;
		else{
		int v;
		v=l;
		u=HT[l].chain;
			while(u!=-1&&HT[v].key!=k)
			{
			v=u;
			u=HT[v].chain;
			}
			if(HT[v].key==k)
			cout<<"\nFOUND!\n"<<HT[v].key<<HT[v].type<<HT[v].ival;
			else
			cout<<"\nNOT FOUND!";

		}
}

void HashTable::withinsert(node nn)
{
int l=nn.key.length()%n;

		if(HT[l].key=="#")
		{
			HT[l]=nn;
			HT[l].chain=-1;
		}
		else
		{
			if(HT[l].key.length()%n==l)
			{int v,u;

		v=l;
		u=HT[l].chain;

		while(u!=-1)
		{
		v=u;
		u=HT[v].chain;
		}
				int i;
				for(i=(l+1)%n;HT[i].key!="#";i=(i+1)%n);
				HT[i]=nn;
				HT[v].chain=i;
				HT[i].chain=-1;

			}
			else
			{
				node temp;
				temp=HT[l];
				HT[l]=nn;
				HT[l].chain=-1;
				int i;
				for(i=(l+1)%n;HT[i].key!="#";i=(i+1)%n);
				HT[i]=temp;

				int k;
				for(k=0;HT[k].chain!=l;k=(k+1)%n);
				HT[k].chain=i;
				HT[i].chain=-1;
			}


		}
		for(int i=0;i<n;i++)
cout<<"\n"<<HT[i].key<<"\t"<<HT[i].chain;

}

void HashTable::withoutinsert(node nn)
{
int v,u;
int l=nn.key.length()%n;
	if(HT[l].key=="#"){
		HT[l]=nn;
		HT[l].chain=-1;
		}
	else{
		v=l;
		u=HT[l].chain;

		while(u!=-1)
		{
		v=u;
		u=HT[v].chain;
		}
		int i;
			for(i=(l+1)%n;HT[i].key!="#";i=(i+1)%n);
			HT[i]=nn;
			HT[v].chain=i;
			HT[i].chain=-1;
	    }


for(int i=0;i<n;i++)
cout<<"\n"<<HT[i].key<<"\t"<<HT[i].chain;
}

void HashTable::create(){
	int ch;


	cout<<"\nEnter type of Linear Probing: \n1. Without Replacement\n2. With Replacement";
			cin>>ch;


	for(int i=0;i<n;i++)
	{ node nn;
		cout<<"\n"<<i+1<<" Entry";
		cout<<"\nEnter Identifier(symbol) Name: ";
		cin>>nn.key;
		cout<<"Enter data type: ";
		cin>>nn.type;
		cout<<"Enter initial value: ";
		cin>>nn.ival;

				if(ch==1)
					withoutinsert(nn);
				if(ch==2)
					withinsert(nn);
	}
}




int main(){
	int n;
	cout<<"\nEnter number of Identifiers(symbols) to be stored: ";
	cin>>n;
	HashTable obj(n);
	obj.create();
	do{
		cout<<"\nSELECT OPTION\n1. Retrieve\n2. Delete\n3. Modify\n4. Exit";
		cin>>n;
		if(n==1)
		obj.find();
		if(n==2)
		obj.del();
		if(n==3)
		obj.modify();
	}
	while(n!=4);

return 0;
}
/*
rutuja@rutuja-Aspire-ES1-520:~/ads$ g++ A7.cpp
rutuja@rutuja-Aspire-ES1-520:~/ads$ ./a.out

Enter number of Identifiers(symbols) to be stored: 3

Enter type of Linear Probing: 
1. Without Replacement
2. With Replacement2

1 Entry
Enter Identifier(symbol) Name: dot
Enter data type: char
Enter initial value: 0

dot	-1
#	-1
#	-1
2 Entry
Enter Identifier(symbol) Name: dash
Enter data type: char
Enter initial value: 1

dot	-1
dash	-1
#	-1
3 Entry
Enter Identifier(symbol) Name: dollar
Enter data type: int 
Enter initial value: 2

dot	2
dash	-1
dollar	-1
SELECT OPTION
1. Retrieve
2. Delete
3. Modify
4. Exit1

Enter key of element to be found2

NOT FOUND!
SELECT OPTION
1. Retrieve
2. Delete
3. Modify
4. Exit1

Enter key of element to be found-1

NOT FOUND!
SELECT OPTION
1. Retrieve
2. Delete
3. Modify
4. Exit1

Enter key of element to be founddot

FOUND!
dotchar0
SELECT OPTION
1. Retrieve
2. Delete
3. Modify
4. Exit3

Enter key of element to be modifieddot

Enter new initial value: 5

SELECT OPTION
1. Retrieve
2. Delete
3. Modify
4. Exit2

Enter key of element to be deleteddash

DELETED SUCCESSFULLY
SELECT OPTION
1. Retrieve
2. Delete
3. Modify
4. Exit4
 
*/
