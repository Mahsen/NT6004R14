#ifndef __DISPLAY_HPP
#define __DISPLAY_HPP
//----------------------------------------------------------
#include "defines.h"
//----------------------------------------------------------
class Display {
private: 
  
  static Display *Instance;
  Display();
  
public: 
  enum Icons {
    Icon_Light,
    Icon_Wifi,
    Icon_Music,
    Icon_Lock,
    Icon_Timer,
    Icon_Oven,
    Icon_Ring,
    Icon_Motor_Up,	
    Icon_Motor_Down,	
    Icon_Lamp,
    Icon_Centigrade,
    Icon_Clone_Up,
    Icon_Clone_Down,
    Icon_1000,
    Icon_Fan_0,
    Icon_Fan_1,
    Icon_Fan_2,
    Icon_Fan_3
  };
  static Display* getInstance() {
    if(Instance == NULL) {
      Instance = new Display();
    }
    return Instance;
  }
  void Icon(U16 Icons, bool Show);
};
//----------------------------------------------------------
#endif

