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
    int err_code = OMM_DATA_ERR_OK;;
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

    if(!jwssid) err_code = OMM_DATA_ERR_WIFI_SSID_JSON_PARSE_FAIL;
    else wifiData.ssid = jwssid->string;

    if(!jwpass) err_code = OMM_DATA_ERR_WIFI_PASS_JSON_PARSE_FAIL;
    else wifiData.pass = jwpass->string;

    if(!jmurl) err_code = OMM_DATA_ERR_MQTT_URL_JSON_PARSE_FAIL;
    else mqttData.url = jmurl->string;

    if(!jmuser) err_code = OMM_DATA_ERR_MQTT_USER_JSON_PARSE_FAIL;
    else mqttData.user = jmuser->string;

    if(!jmpass) err_code = OMM_DATA_ERR_MQTT_PASS_JSON_PARSE_FAIL;
    else mqttData.pass = jmpass->string;

    if(!jmport) err_code = OMM_DATA_ERR_MQTT_PORT_JSON_PARSE_FAIL;
    else mqttData.port = jmport->valueint;

    if(!jtuser) err_code = OMM_DATA_ERR_TOPIC_USER_JSON_PARSE_FAIL;
    else topicData.user = jtuser->string;

    if(!jtnetwork) err_code = OMM_DATA_ERR_TOPIC_NET_JSON_PARSE_FAIL;
    else topicData.network = jtnetwork->string;

    return err_code;
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