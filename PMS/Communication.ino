void initWifi()
{
  delay(10);
  Serial.println("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  connected();
  delay(2000);
}

void sendtoServer()
{
  if(WiFi.status()== WL_CONNECTED){
    sending();
    HTTPClient http;

    String serverPath = serverName + "?api_key=CU52P30JDUUVEJ3W&field1="+String(getVoltage(0))+"&field2="+String(getVoltage(1))+"&field3="+String(getVoltage(2))+"&field4="+String(getCurrent(0))+"&field5="+String(getCurrent(1))+"&field6="+String(getCurrent(2))+"&field7="+String(getPower(0, 0))+"&field8="+String(getPower(2, 2));                         
    
    // Your Domain name with URL path or IP address with path
    http.begin(serverPath.c_str());
    
    // If you need Node-RED/server authentication, insert user and password below
    //http.setAuthorization("REPLACE_WITH_SERVER_USERNAME", "REPLACE_WITH_SERVER_PASSWORD");
    
    // Send HTTP GET request
    int httpResponseCode = http.GET();
    
    if (httpResponseCode>0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
      sent();
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
      fail();
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
    fail();
  }  
}
