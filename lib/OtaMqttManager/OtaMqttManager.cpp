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
 * @note Create an access point on your smartphone with these WiFi credentials
 * @param ssid name of external access point
 * @param pass password of external access point
 * @return int err code
 */
int OtaMqttManager::begin(char *ssid, char *pass){
    if(!SPIFFS.begin()){
        return OMM_ERR_SPIFFS_INIT_FAIL;
    }

    return OMM_ERR_OK;
}
