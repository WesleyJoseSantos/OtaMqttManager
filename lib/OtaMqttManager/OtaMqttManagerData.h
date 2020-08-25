/**
 * @file OtaMqttManagerData.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __OTAMQTTMANAGERDATA__H__
#define __OTAMQTTMANAGERDATA__H__

#include "cJSON.h"
#include "WString.h"
#include "stdio.h"

typedef enum{
    OMM_DATA_ERR_OK,
    OMM_DATA_ERR_JSON_PARSE_FAIL,
    OMM_DATA_ERR_WIFI_JSON_PARSE_FAIL,
    OMM_DATA_ERR_MQTT_JSON_PARSE_FAIL,
    OMM_DATA_ERR_TOPIC_JSON_PARSE_FAIL,
    OMM_DATA_ERR_WIFI_SSID_JSON_PARSE_FAIL,
    OMM_DATA_ERR_WIFI_PASS_JSON_PARSE_FAIL,
    OMM_DATA_ERR_MQTT_URL_JSON_PARSE_FAIL,
    OMM_DATA_ERR_MQTT_USER_JSON_PARSE_FAIL,
    OMM_DATA_ERR_MQTT_PASS_JSON_PARSE_FAIL,
    OMM_DATA_ERR_MQTT_PORT_JSON_PARSE_FAIL,
    OMM_DATA_ERR_TOPIC_USER_JSON_PARSE_FAIL,
    OMM_DATA_ERR_TOPIC_NET_JSON_PARSE_FAIL,
}omm_data_err_t;

typedef struct{
    char *ssid;
    char *pass;
}WiFiData;

typedef struct{
    char *url;
    char *user;
    char *pass;
    int port;
}MqttData;

typedef struct{
    char *user;
    char *network;
}TopicData;

class OtaMqttManagerData
{
private:
public:
    WiFiData wifiData;
    MqttData mqttData;
    TopicData topicData;
    int fromJson(String jsonStr);
    String toJson();
};


#endif  //!__OTAMQTTMANAGERDATA__H__