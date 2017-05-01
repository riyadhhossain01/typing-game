

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void changedecknumbers(int x){
	if (x==0){cout<<"A";}
	else if (x==10){cout<<"J";}
	else if (x==11){cout<<"Q";}
	else if (x==12){cout<<"K";}
	else {cout<<x+1;}
}

int main() {
	srand(time(0));int wins[5]={0,0,0,0,0};int suitcount[20];int iwins=0;
	char deck[52] = {'S','S','S','S','S','S','S','S','S','S','S','S','S',
					 'H','H','H','H','H','H','H','H','H','H','H','H','H',
					 'C','C','C','C','C','C','C','C','C','C','C','C','C',
					 'D','D','D','D','D','D','D','D','D','D','D','D','D'};
	int decknumbers[52];
	for (int x=0; x<52;x++) {decknumbers[x] = x;}
//for (int x=0; x<52;x++) {cout<<decknumbers[x]<<", ";}
	for (int i=0; i<52; i++) {int r = rand() % 52;
	int temp = decknumbers[i]; decknumbers[i] = decknumbers[r]; decknumbers[r] = temp;}
//cout<<endl;for (int x=0; x<52;x++) {cout<<decknumbers[x]<<", ";}
	int playerhands[35];
	for (int j=0; j<35; j++){playerhands[j]=decknumbers[j];}
//cout<<endl;for (int x=0; x<35;x++) {cout<<playerhands[x]<<", ";}cout<<endl;
	char choices[7] = {'a','b','c','d','e','f','g'};
	cout<<endl<<endl<<endl;
	while (true){
//cout<<"hands: "<<endl;for (int x=0; x<35;x++) {cout<<playerhands[x]<<", ";}cout<<endl;
		for (int e=0;e<20;e++){suitcount[e]=0;}
		for (int b=0;b<5;b++){
			for (int c=(7*b);c<((b+1)*7);c++){
				if (deck[playerhands[c]]=='S'){suitcount[0+(b*4)]++;}
				else if (deck[playerhands[c]]=='H'){suitcount[1+(b*4)]++;}
				else if (deck[playerhands[c]]=='C'){suitcount[2+(b*4)]++;}
				else if (deck[playerhands[c]]=='D'){suitcount[3+(b*4)]++;}
			}
		}
//cout<<"wins: "<<iwins<<"  scores: "<<endl;for (int x=0; x<20;x++) {cout<<suitcount[x]<<", ";if(x%4==3){cout<<endl;}}cout<<endl;
		for (int f=0;f<20;f++){
			if (suitcount[f]==7){iwins++;wins[f/4]++;}
		}
		if (iwins>0){break;}
		for (int k=0; k<7;k++){cout<<"  ("<<choices[k]<<") "<<deck[playerhands[k]];changedecknumbers(playerhands[k]%13);}
		cout<<endl<<endl<<"Which one to replace? "<<endl;
		int picknumber=0;char playerpick;cin>>playerpick;picknumber=playerpick;
		while ((picknumber<97)||(picknumber>103)){cout<<"Invalid input, please re-enter--> ";cin>>playerpick;picknumber=playerpick;}
		picknumber=picknumber-97;int cardtrades[5];cardtrades[0]=picknumber;
		for (int x=1;x<5;x++){
			int hand[4]={0,0,0,0};char lowest;
			for (int y=(7*x);y<((x+1)*7);y++){
				if (deck[playerhands[y]]=='S'){hand[0]++;}
				else if (deck[playerhands[y]]=='H'){hand[1]++;}
				else if (deck[playerhands[y]]=='C'){hand[2]++;}
				else if (deck[playerhands[y]]=='D'){hand[3]++;}
			}
			for (int z=0;z<3;z++){
				for(int isuit=0;isuit<4;isuit++){
					if (hand[isuit]==3-z){lowest=deck[isuit*13];}
				}
			}
			for (int y=(7*x);y<((x+1)*7);y++){
				if (deck[playerhands[y]]==lowest){cardtrades[x]=y;}
			}
		}
//cout<<endl;for (int x=0; x<5;x++) {cout<<cardtrades[x]<<", ";}cout<<endl;
		int tradeholder[5];
		for (int a=0;a<5;a++){tradeholder[a]=playerhands[cardtrades[a]];}
		for (int p=0;p<5;p++){
			if (p==4){
				cout<<endl<<"Hint: player "<<p<<" passed "<< deck[tradeholder[p]];changedecknumbers((tradeholder[p]%13));cout<<" to player 0";
				playerhands[cardtrades[0]]=tradeholder[4];
			}
			else {
				cout<<endl<<"Hint: player "<<p<<" passed "<< deck[tradeholder[p]];changedecknumbers((tradeholder[p]%13));cout<<" to player "<<p+1;
				playerhands[cardtrades[p+1]]=tradeholder[p];
			}
		}
		cout<<endl<<endl;
	}
	for (int g=0;g<5;g++){
		if (wins[g]>0){cout<<"My Ship Sails! --- Player "<<g<<" Won... "<<endl;}
	}
	cout<<endl<<endl<<"[ Final card distributions ]";
	for (int m=0;m<5;m++){
		cout<<endl<<"Player "<<m;
		for (int n=(7*m);n<((m+1)*7);n++){
			cout<<"  ("<<choices[n%7]<<") "<<deck[playerhands[n]];changedecknumbers((playerhands[n]%13));
		}
	}
	return 0;
}
