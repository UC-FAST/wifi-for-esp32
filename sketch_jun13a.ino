/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <WiFi.h>
const char* ssid = "samuel jiang";
char ch[95];
char password[16];
int pwd[] = { 0,0,0,0,0,0,0,0,-1,-1,-1,-1,-1,-1,-1,-1 };//密码缓存
void func()
{
    pwd[0]++;
    if (pwd[0] == 95) {
        pwd[0] = 0;
        pwd[1]++;
    }
    if (pwd[1] == 95) {
        pwd[1] = 0;
        pwd[2]++;
    }
    if (pwd[2] == 95) {
        pwd[2] = 0;
        pwd[3]++;
    }
    if (pwd[4] == 95) {
        pwd[4] = 0;
        pwd[5]++;
    }
    if (pwd[5] == 95) {
        pwd[5] = 0;
        pwd[6]++;
    }
    if (pwd[6] == 95) {
        pwd[6] = 0;
        pwd[7]++;
    }
    if (pwd[7] == 95) {
        pwd[7] = 0;
        pwd[8]++;
    }
    if (pwd[8] == 95) {
        pwd[8] = 0;
        pwd[9]++;
    }
    if (pwd[9] == 95) {
        pwd[9] = 0;
        pwd[10]++;
    }
    if (pwd[10] == 95) {
        pwd[10] = 0;
        pwd[11]++;
    }
    if (pwd[11] == 95) {
        pwd[11] = 0;
        pwd[12]++;
    }
    if (pwd[12] == 95) {
        pwd[12] = 0;
        pwd[13]++;
    }
    if (pwd[13] == 95) {
        pwd[13] = 0;
        pwd[14]++;
    }
    if (pwd[14] == 95) {
        pwd[14] = 0;
        pwd[15]++;
    }
    if (pwd[15] == 95)
        return;
}
/*
{
'0','1','2','3','4','5','6','7','8','9',
'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
'o','p','q','r','s','t','u','v','w','x','y','z',
'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
'O','P','Q','R','S','T','U','V','W','X','Y','Z',
'\'','"',';',':',',','.','/','?','[',']','{','}','!','@',
'#','$','%','^','&','*','(',')','~','`',' ''\\','|'
}*/

void setup()
{
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);
   for (unsigned i = 0; i < sizeof(ch) / sizeof(char); i++)
        ch[i] = i + 32;
    Serial.println(ch);
}
void loop()
{
    do
    {
        func();
        for (unsigned i = 0; i < 16; i++) 
            if (pwd[i] != -1) 
                password[i ] = ch[pwd[i]];      
        
        for (unsigned i = 0; i <16; i++)
            if (pwd[i] == -1) 
                password[i] = '\0';
            
        Serial.println(password);
        WiFi.begin(ssid, password);
    }while(WiFi.status() != WL_CONNECTED);
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}


