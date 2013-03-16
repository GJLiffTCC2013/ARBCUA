#include <SPI.h>
#include <Ethernet.h>

boolean incoming = 0;
int rele1 = 0;
int rele2 = 0;
int rele3 = 0;
int rele4 = 0;
int rele5 = 0;
int rele6 = 0;
//int rele7 = 0;
//int rele8 = 0;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,0,177);

EthernetServer server(80);
void setup()
{
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.begin(9600);

  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  pinMode(3, OUTPUT);
  digitalWrite(3, LOW);
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
  pinMode(5, OUTPUT);
  digitalWrite(5, LOW);
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
//  pinMode(8, OUTPUT);
//  digitalWrite(8, LOW);
//  pinMode(9, OUTPUT);
//  digitalWrite(9, LOW);
}

void loop()
{
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client)
  {
  // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    String str;
    while (client.connected())
    {
      if (client.available())
      {
        char c = client.read();
        str.concat(c);
        
        if(str.endsWith("/1on")) rele1 =1;
        else if(str.endsWith("/1off")) rele1 =0;
        if(str.endsWith("/2on")) rele2 =1;
        else if(str.endsWith("/2off")) rele2 =0;
        if(str.endsWith("/3on")) rele3 =1;
        else if(str.endsWith("/3off")) rele3 =0;
        if(str.endsWith("/4on")) rele4 =1;
        else if(str.endsWith("/4off")) rele4 =0;
        if(str.endsWith("/5on")) rele5 =1;
        else if(str.endsWith("/5off")) rele5 =0;
        if(str.endsWith("/6on")) rele6 =1;
        else if(str.endsWith("/6off")) rele6 =0;
//        if(str.endsWith("/7on")) rele7 =1;
//        else if(str.endsWith("/7off")) rele7 =0;
//        if(str.endsWith("/8on")) rele8 =1;
//        else if(str.endsWith("/8off")) rele8 =0;

        if (c == '\n' && currentLineIsBlank)
        {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          client.println("Casa Inteligente - TCC");
          server.print("<br><br>");
//          server.print("<div style='width : 320px; height : 780px;'>");

          if(rele1 == 1)
          {
            digitalWrite(2, HIGH);            
            client.println("Rele 1: Ligado");
            server.print("<a href='/1off'><button>DESLIGAR</button></a><br><br>");
          }
          else if (rele1 == 0)
          {
            digitalWrite(2, LOW);
            client.println("Rele 1: Desligado" );
            server.print("<a href='/1on'><button>LIGAR</button></a><br><br>");
          }
          
          if(rele2 == 1)
          {
            digitalWrite(3, HIGH);            
            client.println("Rele 2: Ligado");
            server.print("<a href='/2off'><button>DESLIGAR</button></a><br><br>");
          }
          else if (rele2 == 0)
          {
            digitalWrite(3, LOW);
            client.println("Rele 2: Desligado" );
            server.print("<a href='/2on'><button>LIGAR</button></a><br><br>");
          }
          
          if(rele3 == 1)
          {
            digitalWrite(4, HIGH);            
            client.println("Rele 3: Ligado");
            server.print("<a href='/3off'><button>DESLIGAR</button></a><br><br>");
          }
          else if (rele3 == 0)
          {
            digitalWrite(4, LOW);
            client.println("Rele 3: Desligado" );
            server.print("<a href='/3on'><button>LIGAR</button></a><br><br>");
          }          
          
          if(rele4 == 1)
          {
            digitalWrite(5, HIGH);            
            client.println("Rele 4: Ligado");
            server.print("<a href='/4off'><button>DESLIGAR</button></a><br><br>");
          }
          else if (rele4 == 0)
          {
            digitalWrite(5, LOW);
            client.println("Rele 4: Desligado" );
            server.print("<a href='/4on'><button>LIGAR</button></a><br><br>");
          }          
          
          if(rele5 == 1)
          {
            digitalWrite(6, HIGH);            
            client.println("Rele 5: Ligado");
            server.print("<a href='/5off'><button>DESLIGAR</button></a><br><br>");
          }
          else if (rele5 == 0)
          {
            digitalWrite(6, LOW);
            client.println("Rele 5: Desligado" );
            server.print("<a href='/5on'><button>LIGAR</button></a><br><br>");
          }

          if(rele6 == 1)
          {
            digitalWrite(7, HIGH);            
            client.println("Rele 6: Ligado");
            server.print("<a href='/6off'><button>DESLIGAR</button></a><br><br>");
          }
          else if (rele6 == 0)
          {
            digitalWrite(7, LOW);
            client.println("Rele 6: Desligado" );
            server.print("<a href='/6on'><button>LIGAR</button></a><br><br>");
          }

//          if(rele7 == 1)
//          {
//            digitalWrite(8, HIGH);            
//            client.println("Rele 7: Ligado");
//            server.print("<a href='/7off'><button>DESLIGAR</button></a><br><br>");
//          }
//          else if (rele7 == 0)
//          {
//            digitalWrite(8, LOW);
//            client.println("Rele 7: Desligado" );
//            server.print("<a href='/7on'><button>LIGAR</button></a><br><br>");
//          }
//          
//          if(rele8 == 1)
//          {
//            digitalWrite(9, HIGH);            
//            client.println("Rele 8: Ligado");
//            server.print("<a href='/8off'><button>DESLIGAR</button></a><br><br>");
//          }
//          else if (rele8 == 0)
//          {
//            digitalWrite(9, LOW);
//            client.println("Rele 8: Desligado" );
//            server.print("<a href='/8on'><button>LIGAR</button></a><br><br>");
//          }          
          
          client.println("Temperatura ambiente: ");
          int sensorReading = analogRead(5);
          client.print(sensorReading*0.488);
          client.println("C");
//          server.print("</div>");
          break;
        }
        if (c == '\n')
        {
          currentLineIsBlank = true;
        }
        else if (c != '\r')
        {
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
  }
}
