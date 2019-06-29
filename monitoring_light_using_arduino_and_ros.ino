#include <Arduino.h>   //The <Arduino.h> library contains definitions of Arduino-specific functions.

#include <ros.h>      //The <ros.h> library contains Arduino-to-ROS client functionalities.

#include <rosserial_arduino/Adc.h>   //The <rosserial_arduino/Adc.h> header contains message definitions for carrying 
                                      //several ADC values in a single message.

ros::NodeHandle nh;     //This create a ROS node handle. Like other ROS nodes, we are using this handle to publish 
                        //and subscribe to Arduino.
                        
rosserial_arduino::Adc adc_msg;
ros::Publisher p("adc", &adc_msg); // This code will create an adc_msg instance and create a publisher object.



void setup()
{
nh.initNode();
nh.advertise(p); //This will initialize the node and bind the publisher object to start publishing the topic called /adc .
}



//We average the analog reading to elminate some of the noise
int averageAnalog(int pin){
int v=0;
for(int i=0; i<4; i++) v+= analogRead(pin);
return v/4;
}

long adc_timer;

void loop()
{
adc_msg.adc0 = averageAnalog(0);//In the loop, the Analog value from pin A0 is read and the average is computed. The average
                                  //value will be published to the /adc topic.
p.publish(&adc_msg);
nh.spinOnce();
delay(50);
}
