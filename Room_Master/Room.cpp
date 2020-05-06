#include <iostream>
#include "Room.h"

using namespace std;

//Declaracion de la variable estatica Master Password. La misma para todos 
//los objetos de la clase CRoom
char CRoom::masterPassword [] = {"1234"};  


void CRoom::setName(string* _name){
	//changePassword(roomName, _name);
	roomName = *_name;
	
}

CRoom::CRoom(int _doorSensors[], int _cantDoorS,  int _movSensors[], int _cantMovS, int _lightPin){
	
	lightPin = _lightPin;
	//pinMode(lightPin, OUTPUT);
	
	for (int i = 0; i < elements; i++){
		if (i < _cantDoorS){
			doorSensors	[i] = _doorSensors[i];
		}
		else doorSensors [i] = nulo;
		
		if (i < _cantMovS){
			movSensors [i] = _movSensors[i];
		} 		
		else movSensors [i] = nulo;
	}
}


CRoom::CRoom(int _doorSensors[], int _cantDoorS,  int _movSensors[], int _cantMovS){
    
    for (int i = 0; i < elements; i++){
		if (i < _cantDoorS){
			doorSensors	[i] = _doorSensors[i];
		}
		else doorSensors [i] = nulo;
		
		if (i < _cantMovS){
			movSensors [i] = _movSensors[i];
		} 		
		else movSensors [i] = nulo;
	}
}


bool CRoom::checkMasterPsw(char* _mPsw){
	for (int i = 0; i < elements; i++){
		
		if (masterPassword[i] != _mPsw[i]){
			return false;
		}
	}
	return true;
}

void CRoom::changePassword(char* targetPsw, char* newPsw){
	for (int j = 0; j < elements; j++){
		targetPsw[j] = newPsw[j];
	}
} 




bool CRoom::setMasterPsw (char* mPsw, char* newMPsw){
	
	if(checkMasterPsw(mPsw)){
		changePassword(masterPassword, newMPsw);
		return true;
	}
	return false;		
}

bool CRoom::setPassword(char* MP, char* RP){
    
	if (checkMasterPsw(MP)){
        changePassword(roomPassword, RP);
        return true;
    }
    else {
        return false;
    }

}


bool CRoom::actDeactLigth(){
	if (actDeactRoomAlarm){
    	actDeactRoomLigth = false;
	}
	else {
		actDeactRoomLigth = !actDeactRoomLigth;
	}
	
	return actDeactRoomLigth;
}

bool CRoom::actDeactAlarm(){
        
        actDeactRoomAlarm = !actDeactRoomAlarm;
        if(actDeactRoomAlarm){
            actDeactRoomLigth = false;// Si está activa la alarma en el cuarto no hay luz Automática
        }
    
        return actDeactRoomAlarm;
}





void CRoom::setInPullupPin(int _InPullupPin){
    
    InPullupPin = _InPullupPin;
    
    //pinMode(InPullupPin, INPUT_PULLUP);
    
}




int main()
{
    
    int r1[] = {1, 2, 3, 4};
    int r2[] = {6, 7, 8, 9, 10};
    char m[] = "1234";
    char r[] = "ABCD";
    string sala = "Sala";
    string cuarto = "Cuarto";
    string* rName = &cuarto;
    CRoom R (r1, 4, r2, 5, 11);

    bool a = R.setPassword (m, r);
    bool b = R.setMasterPsw(m, r);
    R.setName(rName);
    
	CRoom Sala(r2, 5, r1, 4, 12);
	char s[] = "2D1C"; 
	rName = &sala;
	Sala.setMasterPsw(m, s);
	Sala.setName(rName);
    
    return 0;
}




