//Implementation of the SoS model class

#ifndef SOSMODEL_HPP
#define SOSMODEL_HPP

#include <vector>
#include <array>

template<short N, typename fpt>
//add a restriction for fpt, to only float and double types
class SoSModel{

private:

  //short MultPath;
  std::array<fpt,N> PathGains;
  std::array<fpt,N> DopplerFrequencies;
  std::array<fpt,N> Phases;

public:
  
  SoSModel();//set the attributes to nullptr
  ~SoSModel();//deletes the attributes

  std::vector<fpt> * CalcProcess(float *t);

  //Jakes form
  virtual void EstimateModel(float sig /*std_dev in lin*/, float fmax) = 0;
  //Gaussian form
  virtual void EstimateModel(float sig /*std_dev in lin*/, float fc, float kc) = 0; 

  void genPhases();//Considering only random generation until this moment
  

};

#endif
