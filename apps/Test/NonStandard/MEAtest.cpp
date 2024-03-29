#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "../../../src/Models/MEAModel.hpp"

using namespace std;

int main(){

  float ti=0, tf=2, dt=0.0005;
  const short N = 20; //number of multipath
  float fc=2e9, mtv=30/3.6;
  float fmax=(mtv*fc)/3e8;
  float tc=1/fmax;
  

  vector<string> OutLine;
  fstream OutFile;
  ostream_iterator<string> out_it (OutFile,";");

  MEAModel<N,float> u1(0.7071,std::sqrt(std::numbers::ln2_v<float>)*fmax,2.0/std::sqrt(2.0/std::numbers::ln2_v<float>)),u2(0.7071,std::sqrt(std::numbers::ln2_v<float>)*fmax,2.0/std::sqrt(2.0/std::numbers::ln2_v<float>));
  vector<float> time((tf-ti)/dt);

  for(float i=0;i<(tf-ti)/dt;i++) time[i] = ti + i*dt;

  vector<float> u1value = u1.CalcProcess(time);
  vector<float> u2value = u2.CalcProcess(time);

  OutFile.open("RayleighChannelMEA.csv", ios::out | ios::trunc);

  OutFile<<"time"<<';';
  OutFile<<"u1"<<';';
  OutFile<<"u2"<<"\n";


  for(float i=0;i<(tf-ti)/dt;i++){
    OutLine.push_back(to_string(time[i]));
    OutLine.push_back(to_string(u1value[i]));
    OutLine.push_back(to_string(u2value[i]));
    copy(OutLine.begin(),OutLine.end()-1,out_it);
    OutFile<<OutLine.back()<<'\n';
    OutLine.clear();
  }
  OutFile.close();

  cout<<"coherence time: "<<tc<<"\n";

  return 0;
}
