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

OtaMqttManager::OtaMqttManager(){

}

int OtaMqttManager::begin(char *ssid, char *pass){
    if(!SPIFFS.begin()){
        return OMM_ERR_SPIFFS_INIT_FAIL;
    }

    return OMM_ERR_OK;
}
