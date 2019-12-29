#include <iostream>
#include <string>
#include <map>

using namespace std;
int integeralise(string roman){
	map<char,int> rmap;
	rmap['I'] =   1;
	rmap['i'] =   1;
	rmap['V'] =   5;
	rmap['v'] =   5;
	rmap['X'] =  10;
	rmap['x'] =  10;
	rmap['L'] =  50;
	rmap['l'] =  50;
	rmap['C'] = 100;
	rmap['c'] = 100;
	rmap['D'] = 500;
	rmap['d'] = 500;
	rmap['M'] =1000;
	rmap['m'] =1000;
	int number {};
	
	if(roman.length() == 1){          //in case the input is a single character
		return rmap[roman.at(0)];
	}
	else{  							  //in case the input is multi character
		int i{};
		while(i<roman.size()){
			if(rmap[roman[i]] < rmap[roman[i+1]]){
				number += rmap[roman[i+1]] - rmap[roman[i]];
				i+=2;
			}
			else{
				number += rmap[roman[i]];
				++i;
			}
		}
		return number;
	}
}

int main(){
	cout<<"Enter the roman number ";
	string roman {};
	getline(cin, roman);
	
	int number {};
	number=integeralise(roman);
	
	cout<<"Converted integer form is: "<<number<<endl;
	
	return 0;
}
