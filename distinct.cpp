#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

void f2 (){
  ifstream ipfile("piworks.csv");

  map<int,list<int> > m;
  map<int,int> resultmap;

  string play_id;
  string song_id_str;
  string client_id_str ;
  string play_ts;

  int client_id;
  int song_id;
  int flag;
  int date;
  map<int,list<int> >::iterator it ;
  getline(ipfile,play_id,';');
  getline(ipfile,song_id_str,';');
  getline(ipfile,client_id_str,';');
  getline(ipfile,play_ts,'\n');

  while(!ipfile.eof()){
      flag=1;
      getline(ipfile,play_id,';');
      if(ipfile.eof()){
        break;
      }
      getline(ipfile,song_id_str,';');
      getline(ipfile,client_id_str,';');
      getline(ipfile,play_ts,'\n');
      client_id = atoi(client_id_str.c_str());
      song_id = atoi(song_id_str.c_str());

      if(play_ts.substr(0,10) == "10.08.2016"){

      }
      else{

        continue;
      }

      it= m.find(client_id);


      if(it == m.end() ){
        pair<int,list<int> > x;
        x.first = client_id;
        x.second.push_back(1);
        x.second.push_back(song_id);
        m.insert(x);

      }
      else {
        for (list<int>::iterator i = ++(*it).second.begin(); i != (*it).second.end(); i++){


          if ( (*i) == song_id) {
            flag=0;
            break;
          }

        }

        if(flag /*song_id secondda yoksa*/){
          (*it).second.front()++;
          (*it).second.push_back(song_id);

      }
    }

  }

  for(it=m.begin();it!=m.end();++it){

  }



  int songcount;
  map<int,int>::iterator it2;

    for(it=m.begin();it!=m.end();++it) {
      songcount = (*it).second.front();

      it2 = resultmap.find(songcount);

      if(it2 == resultmap.end()){
        /*not found*/

        pair<int,int> y;
        y.first = songcount;
        y.second = 1;
        resultmap.insert(y);
        it2=resultmap.find(songcount);

      }
      else{
        /*found*/

        (*it2).second ++;
        it2=resultmap.find(songcount);


      }
    }
    ofstream MyExcel;
    MyExcel.open("output.csv");
    MyExcel << "distinct songs"<<'\t'<<"client count"<<endl;
    for (it2=resultmap.begin(); it2!=resultmap.end(); ++it2) {
      MyExcel << (*it2).first<<'\t'<<(*it2).second<<endl;

    }
    ipfile.close();
    MyExcel.close();

  }


int main()
{

  f2();
  return 0;
}
