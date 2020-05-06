#include <string>
using std::string;

#ifndef _Room_Master_h
#define _Room_Master_h

#define nulo 100 //Esa cant. de pines no la tiene ningun Arduino. Es solo para rellenar vectores y Logica
#define elements 5 // Cant. de elementos de los vectores de pines 
#define maxElements 20 // Cant. de elementos de la variable nombre de la habitacion 

class CRoom {
  private:
     
     //Entradas de sensores de movimiento
	 //Vector para pines de sensores de movimientos de la habitacion 
	int movSensors [elements]; //elements (5) sensores maximo por habitacion
	
	//Entradas de sensores de puertas
	//Vector para pines de sensores de puertas
	int doorSensors [elements]; //elements (5) sensores maximo por habitacion
	
	//Salida Digital de la Habitacion 
	//Numero del pin de salida para luz automatica de la habitacion
	int lightPin;
       
    // Input Pullup Pines
    int InPullupPin = nulo;
    
    //Declaracion de la variable estatica Master Password. La misma para todos 
    //los objetos de la clase CRoom
    static char masterPassword [elements];
    
    //Password del objeto
    char roomPassword[elements] = "0000";
    
    //Variable para saber si la habitacion está activa o no, detectando Alarmas
    bool actDeactRoomAlarm = false;
    
    //Variable para saber si en la habitacion está la luz Automática o no 
    //siempre y cuando no esté la alarma activa en la misma (actDeactRoomAlarm = false;)
    bool actDeactRoomLigth = false;
    
    //Funciones privadas que son llamadas cuando se requiere cambiar el MasterPaswword o 
	//el RoomPassword
	bool checkMasterPsw(char* _mPsw);
	void changePassword(char* targetPsw, char* newPsw);
	
	//Variable que guarda el nombre de la Habitacion 
	string roomName;
	//char roomName[maxElements];
	//Variable que guarda la cantidad de letras del nombre de la Habitacion 
	int nameElements = 0;
	
  public:     
       
    //Constructor1---> Solo 5 Entradas y 5 Salidas Digitales Maximo sin Pin para salida de Luz
    CRoom (int _doorSensors[], int _cantDoorS,  int _movSensors[], int _cantMovS);   
    
    //Constructor2---> doorSensorsPins[], movSensorsPins[], lightPin;
    CRoom (int _doorSensors[], int _cantDoorS,  int _movSensors[], int _cantMovS, int _lightPin);
    
    //Metodo para Inicializar un Pin como ImputPullup
    void setInPullupPin (int _InPullupPin); 
    
    //Metodo para activar y desactivar alarma en la Habitacion (Objeto CRoom)
    bool actDeactAlarm ();
    
    //Metodo para activar y desactivar el encendido automatico de la luz en la Habitacion (Objeto CRoom)
    bool actDeactLigth();
    
     //Metodo para Cambiar el Password de la Habitacion (Room) (Objeto CRoom)
    bool setPassword (char* MP, char* RP); //MP--> masterPassword , RP-->roomPassword
    
    //Metodo para Cambiar el Master Password y la variable estatica mPassword
    bool setMasterPsw (char* mPsw, char* newMPsw);
    
    //Metodo para poner nombre a la Habitacion
    void setName(string* _name);
    
    

    
};



#endif

