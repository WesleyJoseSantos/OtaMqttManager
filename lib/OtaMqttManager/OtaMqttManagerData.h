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

/**
 * @brief Enumeration of possible erros of this module
 * 
 */
typedef enum{
    OMM_DATA_ERR_OK,                            ///< No errors
    OMM_DATA_ERR_JSON_PARSE_FAIL,               ///< Fail on initial json parse
    OMM_DATA_ERR_WIFI_JSON_PARSE_FAIL,          ///< Fail on WiFi data json parse
    OMM_DATA_ERR_MQTT_JSON_PARSE_FAIL,          ///< Fail on Mqtt data json parse
    OMM_DATA_ERR_TOPIC_JSON_PARSE_FAIL,         ///< Fail on Topic data json parse
    OMM_DATA_ERR_WIFI_SSID_JSON_PARSE_FAIL,     ///< ssid json key does not exist
    OMM_DATA_ERR_WIFI_PASS_JSON_PARSE_FAIL,     ///< pass json key does not exist
    OMM_DATA_ERR_MQTT_URL_JSON_PARSE_FAIL,      ///< url json key does not exist
    OMM_DATA_ERR_MQTT_USER_JSON_PARSE_FAIL,     ///< user json key does not exist
    OMM_DATA_ERR_MQTT_PASS_JSON_PARSE_FAIL,     ///< pass json key does not exist
    OMM_DATA_ERR_MQTT_PORT_JSON_PARSE_FAIL,     ///< port json key does not exist
    OMM_DATA_ERR_TOPIC_USER_JSON_PARSE_FAIL,    ///< user json key does not exist
    OMM_DATA_ERR_TOPIC_NET_JSON_PARSE_FAIL,     ///< topic json key does not exist
}omm_data_err_t;

/**
 * @brief WiFi credentials
 * 
 */
typedef struct{
    char *ssid;         ///< ssid of WiFi
    char *pass;         ///< pass of WiFi
}WiFiData;

/**
 * @brief Broker Mqtt Credentials
 * 
 */
typedef struct{
    char *url;          ///< Url of Broker Mqtt
    char *user;         ///< User of Broker Mqtt
    char *pass;         ///< Pass of Broker Mqtt
    int port;           ///< Port of Broker Mqtt
}MqttData;

/**
 * @brief Mqtt Topic elements
 * 
 */
typedef struct{
    char *user;         ///< OMM User Name
    char *network;      ///< OMM Network of this device
}TopicData;

/**
 * @brief Class to manager OMM Data
 * 
 */
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