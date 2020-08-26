/**
 * @file OtaMqttManager.cpp
 * @author Wesley José Santos (binary-quantum.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "OtaMqttManager.h"

/**
 * @brief Construct a new Ota Mqtt Manager:: Ota Mqtt Manager object
 * 
 */
OtaMqttManager::OtaMqttManager(){

}

/**
 * @brief Initialize OMM and set an external WiFi access point for communication between OMM App and device
 * @note Create an access point on your smartphone with these WiFi credentials to set initial settings
 * @param ssid name of external access point
 * @param pass password of external access point
 * @return int err code
 */
int OtaMqttManager::begin(char *ssid, char *pass){
    if(!SPIFFS.begin()){
        return OMM_ERR_SPIFFS_INIT_FAIL;
    }

    if(readFileData() == OMM_ERR_OK){

    }else{

    }

    return OMM_ERR_OK;
}

/**
 * @brief Read prov data
 * 
 * @return int err code
 */
int OtaMqttManager::readFileData(){
    File dataFile = SPIFFS.open(OMM_FILE_PROV);
    if(!dataFile || !dataFile.isDirectory()){
        return OMM_ERR_FAILED_TO_OPEN_FILE;
    }

    data.fromJson(dataFile.readString());

    return OMM_ERR_OK;
}