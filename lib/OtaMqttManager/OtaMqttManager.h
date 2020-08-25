/**
 * @file OtaMqttManager.h
 * @author Wesley José Santos (binary-quantum.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __OTAMQTTMANAGER__H__
#define __OTAMQTTMANAGER__H__

#include "ArduinoOTA.h"
#include "FS.h"
#include "SPIFFS.h"
#include "WiFi.h"
#include "cJSON.h"
#include "OtaMqttManagerData.h"

typedef enum{
    OMM_ERR_OK,
    OMM_ERR_SPIFFS_INIT_FAIL
}omm_err_t;

class OtaMqttManager
{
private:
    OtaMqttManagerData data;
public:
    OtaMqttManager();
    int begin(char *ssid, char *pass);
};

#endif  //!__OTAMQTTMANAGER__H__