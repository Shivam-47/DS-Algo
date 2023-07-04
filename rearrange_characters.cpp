//https://practice.geeksforgeeks.org/problems/rearrange-characters4649/1
// Time:: O(NLogN) Space:: O(N)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

 string rearrangeString(string str){
 	int n=str.length();
 	priority_queue <pair<int,int>,vector<pair<int,int> > > pq;
 	vector<int> count(26,0);
	
	//store frequency of each character
 	for(int i=0;i<n;i++)
 		count[str[i]-'a']++;
 	
	//create a max heap based on character frequency
 	for(int i=0;i<n;i++){
 		if(count[str[i]-'a']!=0){
 			pq.push({count[str[i]-'a'],str[i]});
 			count[str[i]-'a']=0;
		 }
	 }
	 

	 //pop out the root from max heap and push back in next
	 //iteration with updated frequency
	 string ans="";
	 pair <int,int> prev = make_pair(-1,'#');
	 while(pq.empty()==0){
	 	pair <int,int> f = pq.top();
	 	pq.pop();
	 	ans += char(f.second);
	 	
	 	if(prev.first>0){
	 		pq.push(prev);
		 }
	 	
	 	prev = make_pair(f.first-1,f.second);
	 }
	 
 	if(ans.length()==n)
 		return ans;
 		
	//not possible to create string without having
	//consecutive same characters
 	return "-1";
 	
 }

int main(){
	string str;
	cout<<"Enter string str:: "<<endl;
	cin>>str;
	cout<<rearrangeString(str)<<endl;
	return 0;
}
