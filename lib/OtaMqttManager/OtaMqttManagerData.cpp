/**
 * @file OtaMqttManagerData.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-08-24
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "OtaMqttManagerData.h"

/**
 * @brief Update object properties using an string with json format
 * 
 * @param jsonStr json string
 * @return int err code
 */
int OtaMqttManagerData::fromJson(String jsonStr){
    cJSON *json = cJSON_Parse(jsonStr.c_str());

    if(json == NULL) return OMM_DATA_ERR_JSON_PARSE_FAIL;

    cJSON *jsonWifiData = cJSON_GetObjectItem(json, "wifiData");
    cJSON *jsonMqttData = cJSON_GetObjectItem(json, "mqttData");
    cJSON *jsonTopicData = cJSON_GetObjectItem(json, "topicData");

    if(jsonWifiData == NULL) return OMM_DATA_ERR_WIFI_JSON_PARSE_FAIL;
    if(jsonMqttData == NULL) return OMM_DATA_ERR_MQTT_JSON_PARSE_FAIL;
    if(jsonTopicData == NULL) return OMM_DATA_ERR_TOPIC_JSON_PARSE_FAIL;

    cJSON *jwssid = cJSON_GetObjectItem(jsonWifiData, "ssid");
    cJSON *jwpass = cJSON_GetObjectItem(jsonWifiData, "pass");
    cJSON *jmurl = cJSON_GetObjectItem(jsonMqttData, "url");
    cJSON *jmuser = cJSON_GetObjectItem(jsonMqttData, "user");
    cJSON *jmpass = cJSON_GetObjectItem(jsonMqttData, "pass");
    cJSON *jmport = cJSON_GetObjectItem(jsonMqttData, "port");
    cJSON *jtuser = cJSON_GetObjectItem(jsonTopicData, "user");
    cJSON *jtnetwork = cJSON_GetObjectItem(jsonTopicData, "network");

    if(!jwssid) return OMM_DATA_ERR_WIFI_SSID_JSON_PARSE_FAIL;
    if(!jwpass) return OMM_DATA_ERR_WIFI_PASS_JSON_PARSE_FAIL;
    if(!jmurl) return OMM_DATA_ERR_MQTT_URL_JSON_PARSE_FAIL;
    if(!jmuser) return OMM_DATA_ERR_MQTT_USER_JSON_PARSE_FAIL;
    if(!jmpass) return OMM_DATA_ERR_MQTT_PASS_JSON_PARSE_FAIL;
    if(!jmport) return OMM_DATA_ERR_MQTT_PORT_JSON_PARSE_FAIL;
    if(!jtuser) return OMM_DATA_ERR_TOPIC_USER_JSON_PARSE_FAIL;
    if(!jtnetwork) return OMM_DATA_ERR_TOPIC_NET_JSON_PARSE_FAIL;

    wifiData.pass = jwpass->string;
    wifiData.ssid = jwssid->string;
    mqttData.pass = jmpass->string;
    mqttData.port = jmport->valueint;
    mqttData.url = jmpass->string;
    mqttData.user = jmpass->string;
    topicData.network = jtnetwork->string;
    topicData.user = jtuser->string;

    return OMM_DATA_ERR_OK;
}

/**
 * @brief Create an json string, to represents this object
 * 
 * @return String json string
 */
String OtaMqttManagerData::toJson(){
    cJSON *json = cJSON_CreateObject();

    cJSON *jsonWifiData = cJSON_CreateObject();
    cJSON *jsonMqttData = cJSON_CreateObject();
    cJSON *jsonTopicData = cJSON_CreateObject();

    cJSON_AddStringToObject(jsonWifiData, "ssid", wifiData.ssid);
    cJSON_AddStringToObject(jsonWifiData, "pass", wifiData.pass);
    cJSON_AddStringToObject(jsonMqttData, "url", mqttData.url);
    cJSON_AddStringToObject(jsonMqttData, "user", mqttData.user);
    cJSON_AddStringToObject(jsonMqttData, "pass", mqttData.pass);
    cJSON_AddNumberToObject(jsonMqttData, "port", mqttData.port);
    cJSON_AddStringToObject(jsonTopicData, "user", topicData.user);
    cJSON_AddStringToObject(jsonTopicData, "network", topicData.network);

    cJSON_AddItemReferenceToObject(jsonWifiData, "wifiData", json);
    cJSON_AddItemReferenceToObject(jsonMqttData, "mqttData", json);
    cJSON_AddItemReferenceToObject(jsonTopicData, "topicData", json);

    String jsonStr(cJSON_Print(json));

    return jsonStr;
}