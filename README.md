Monitoring light using Arduino and ROS



We can start coding a basic Arduino-ROS node that can sense the amount of light using a 
light-dependent resistor (LDR). You can use any Arduino for this demo; 
The characteristic of an LDR is that it is basically a resistor in which the
resistance across it changes when light falls on it. The maximum resistance is when there is
no light and minimum when light falls on it.

We have to connect one pin to 5V from the Arduino board and the next terminal to the
Arduino's A0 pin. That terminal is connected to the GND pin through a 10 KΩ resistor. It is
basically a voltage divider circuit. The equation for finding the voltage at A0 is as follows:
V_a0 = 5 * (R2 / (R1 + R2))
From the equation, it is clear that when there is no light, we will get the minimum voltage,
and when there is light, we'll get the maximum. This value can be read out using an
Arduino program.


After compiling the code, you can select the board from Tools | Board and Serial Port from
the list. You can now burn the code into the Arduino board.



Running ROS serial server on PC


After burning the code, to start subscribing or publishing to the Arduino board, we should
start the ROS serial server on the PC side. Let's see how to do so:

1. Initialize roscore : $ roscore

2. Run the ROS serial server on the PC. The argument of the server is the serial
device name of the Arduino device:
$ rosrun rosserial_python serial_node.py /dev/ttyACM0

3. Now, you can see the /adc topic using the following command:
$ rostopic list

4. You can echo the /adc topic using the following command:
$ rostopic echo /adc/adc0

5. You may get values.
