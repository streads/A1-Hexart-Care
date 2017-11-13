import processing.serial.*;

import java.io.BufferedWriter;
import java.io.FileWriter;
//declare
PrintWriter output;
Serial udSerial;



void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600);
  appendInFile(new java.util.Date().getTime() / 1000 + ";" + (int) (Math.random() * 300)); // add a random value
}
void draw() {
  if (udSerial.available() > 0) {
    String SenVal = udSerial.readString();
    if (SenVal != null) {
      appendInFile(new java.util.Date().getTime() / 1000 + ";" + SenVal);
    }
  }
}
void keyPressed() {
  exit();
}

void appendInFile(String newData){
  BufferedWriter bw = null;
  try {  
    FileWriter fw = new FileWriter(dataPath("../beatLogger.csv"), true);
    bw = new BufferedWriter(fw);
    bw.write(newData + System.getProperty("line.separator"));
  } catch (IOException e) {
  } finally {
    if (bw != null){
      try { 
        bw.close(); 
      } catch (IOException e) {}  
    }
  }
}