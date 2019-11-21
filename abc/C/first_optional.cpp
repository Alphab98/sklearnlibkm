#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
//FIRST FUNCTION
vector<char> first(char c,map<char,vector<string>> &m){
	auto itr = m.find(c);
	vector<char> f;
		for(auto itr2=itr->second.begin();itr2!=itr->second.end();itr2++){
		    int i=0;
			if(m.find(itr2[0][0])!=m.end()){
				vector<char> temp = first(itr2[0][0],m);
				for(auto a=temp.begin();a!=temp.end();a++){
				    if(*a=='%')
				        continue;
					f.push_back(*a);
			    }
				while(find(temp.begin(),temp.end(),'%')!=temp.end())
				{   i++;
				    temp.clear();
				    vector<char> temp;
                    if(itr2[0].length()>=i+1){
                        if(m.find(itr2[0][i])!=m.end()){
    					    temp = first(itr2[0][i],m);
                        }
                        else{
                            char s = itr2[0][i];
                            temp.push_back(s);
                        }
                        for(auto a=temp.begin();a!=temp.end();a++){
				            if(*a=='%')
				                continue;
					        f.push_back(*a);
			             }
					}
		        }
			}
		    else{
			    f.push_back(itr2[0][0]);
		    }
	    }
	return f;
}

//FOLLOW FUNCTION
vector<char> follow(char c,map<char,vector<string>> &m){
  vector<char> f;
	for(auto itr=m.begin();itr!=m.end();itr++){
			for(auto itr1=itr->second.begin();itr1!=itr->second.end();itr1++){
			    vector<char> temp;
				for(int i=0;i<itr1->size();i++){
					if(itr1[0][i]==c){
						if(i==itr1->size()-1){
							temp = follow(itr->first,m);
						}
						else{
						    if(m.find(itr1[0][i+1])!=m.end()){
							    temp = first(itr1[0][i+1],m);
									for(auto a=temp.begin();a!=temp.end();a++){
										if(*a=='%')
											continue;
										f.push_back(*a);
									}
									while(temp.find('%')!=m.end() and i!=itr1->size()-1){
										temp.clear();
										i++;
										temp = first(itr1[0][i+1],m);

									}
						    }
						    else{
						        temp.push_back(itr1[0][i+1]);
						    }
						}
						for(auto a=temp.begin();a!=temp.end();a++){
							f.push_back(*a);
						}
					}
				}
			}
		}
  return f;
}
int main(){
  int n;
	cin >>n;
	string s;
	map<char,vector<string>> m;
	for(int i=0;i<n;i++){
		cin >>s;
		if(m.find(s[0])!=m.end()){
			auto itr = m.find(s[0]);
			itr->second.push_back(s.substr(2,s.length()-1));
		}
		else{
		m[s[0]].push_back(s.substr(2,s.length()-1));
	    }
	}
	for(auto itr = m.begin();itr!=m.end();itr++){
	    vector<char> v = follow(itr->first,m);
	    cout<<itr->first<<"-->";
	    for(auto itr = v.begin();itr!=v.end();itr++){
	        cout<<*itr<<" ";
	    }
	    cout<<endl;
	}


}
