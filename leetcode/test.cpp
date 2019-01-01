#include<iostream>
using namespace std;
string strc(string a,int b)
{
	string r;
	for(int i = 0;i<b;i++)
		r+=a;
	return r;
}
string one,two,three,four,five,Yi_Zu_Shu;

int main(){
	int k;
	cin>>k;
	cin>>Yi_Zu_Shu;
	for(int i = 0;i<Yi_Zu_Shu.length();i++)
	{
		if(Yi_Zu_Shu[i]== '1' || Yi_Zu_Shu[i]== '4')
			//one+="";
			one+="  "+strc(" ",k)+" ";
		else
			one+="  "+strc("-",k)+" ";//one+="  "+strc("-",k)+" ";
		if(Yi_Zu_Shu[i]== '1' || Yi_Zu_Shu[i]== '2' || Yi_Zu_Shu[i]== '3' || Yi_Zu_Shu[i]== '7')
			//two+="| ";
			two+="  "+strc(" ",k)+"|";
		else if(Yi_Zu_Shu[i]== '5' || Yi_Zu_Shu[i]== '6')
			two+=" |"+strc(" ",k)+" ";
		else
			//two+="|| ";
			two+=" |"+strc(" ",k)+"|";
		if(Yi_Zu_Shu[i]== '1' || Yi_Zu_Shu[i]== '7' || Yi_Zu_Shu[i]== '0')
			//three+="";
			three+="  "+strc(" ",k)+" ";
		else
			//three+=strc("-",k)+" ";
			three+="  "+strc("-",k)+" ";
		if(Yi_Zu_Shu[i] == '2')
			//four+="| ";
			four+=" |"+strc(" ",k)+" ";
		else if(Yi_Zu_Shu[i] == '6' || Yi_Zu_Shu[i] == '8' || Yi_Zu_Shu[i] == '0')
			//four+="|| ";
			four+=" |"+strc(" ",k)+"|";
		else
			//four+="| ";
			four+="  "+strc(" ",k)+"|";
		if(Yi_Zu_Shu[i] == '1' || Yi_Zu_Shu[i] == '4' || Yi_Zu_Shu[i] == '7')
			//five+="";
			five+="  "+strc(" ",k)+" ";
		else
			//five+=strc("-",k)+" ";
			five+="  "+strc("-",k)+" ";
	}
	cout<<one<<"\n";
	for(int i = 0;i<k;i++)cout<<two<<"\n";
	cout<<three<<"\n";
	for(int i = 0;i<k;i++)cout<<four<<"\n";
	cout<<five<<"\n";
	
}


