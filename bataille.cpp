#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

void bataille(){
	srand(time(0));
	vector<int> cartes={2,3,4,5,6,7,8,9,10,11,12,13,14,2,3,4,5,6,7,8,9,10,11,12,13,14,2,3,4,5,6,7,8,9,10,11,12,13,14,2,3,4,5,6,7,8,9,10,11,12,13,14};
	vector<int> c1={}; // players 1 cards
	vector<int> c2={};
	
	for (int i=0;i<=cartes.size()/2;i++){
		auto it=cartes.begin();
		int n=rand()%cartes.size();
		c1.push_back(cartes[n]);
		advance(it,n); // Define the indice 'n'
		cartes.erase(it); // Pop cartes[n]
	}
	for (int i=0;i<=cartes.size()/2;i++){
		int n=rand()%cartes.size();
		auto it=cartes.begin();
		c2.push_back(cartes[n]);
		advance(it,n);
		cartes.erase(it);
	}
	
	//Beginning of the game
	
	while (!c1.empty() && !c2.empty()){
		if (c1[0]>c2[0]){
			cout<<"Le joueur 1 remporte le pli avec "<<c1[0]<<" contre "<<c2[0]<<endl;
			auto it=c2.begin();
			auto ut=c1.begin();
			c1.push_back(c2[0]);
			c1.push_back(c1[0]);
			advance(it,0);
			advance(ut,0);
			c1.erase(ut);
			c2.erase(it);
		}
		else if(c1[0]<c2[0]){
			cout<<"Le joueur 2 remporte le pli avec "<<c2[0]<<" contre "<<c1[0]<<endl;
			auto it=c1.begin();
			auto ut=c2.begin();
			c2.push_back(c2[0]);
			c2.push_back(c1[0]);
			advance(ut,0);
			advance(it,0);
			c1.erase(it);
			c2.erase(ut);
		}
		else if(c1[0]==c2[0]){
			while (c1[0] == c2[0]) {
                		int n1 = rand() % c1.size();
                		int n2 = rand() % c2.size();
                		swap(c1[n1], c2[n2]); // Waiting while two cards are same
            	}
		}
	}
	if(c1.empty()){
		cout<<"Le joueur 2 a gagne la partie"<<endl;
	}
	else if(c2.empty()){
		cout<<"Le joueur 1 a gagne la partie"<<endl;
	}
}

int main(){
	bataille();
}