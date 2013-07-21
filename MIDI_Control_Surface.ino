/*
  MIDI Control Surface
  by Sami Halimi
  
  A MIDI controller with 37 inputs (20 rotary potentiometers + 17 pushbuttons)
  4 channels + master
*/


// CD47HC4067 Multiplexer Pins
int mux1In = 0; // Mux 1 - multiplexed potentiometers (analog)
int mux2In = 6; // Mux 2 (multiplexed buttons)
int muxS3 = 2;
int muxS2 = 3;
int muxS1 = 4;
int muxS0 = 5;

// Non-multiplexed inputs
int pot16Pin = 1; // analog
int pot17Pin = 2; // analog
int pot18Pin = 3; // analog
int pot19Pin = 4; // analog
int button16Pin = 7; // digital

// Input values
int pot0, pot1, pot2, pot3, pot4, pot5, pot6, pot7,
    pot8, pot9, pot10, pot11, pot12, pot13, pot14, pot15, 
    pot16, pot17, pot18, pot19;

int button0, button1, button2, button3, button4, button5,
    button6, button7, button8, button9, button10, button11,
    button12, button13, button14, button15, button16;

//// Control variables
// Playback & preset controls
int playButton = 0;
int stopButton = 0;
int rewButton = 0;
int ffwdButton = 0;
int recButton = 0;
int bankUpButton = 0;
int bankDownButton = 0;
// Channel 1
int c1Volume = 0;
int c1Pan = 0;
int c1Knob1 = 0;
int c1Knob2 = 0;
int c1Mute = 0;
int c1Solo = 0;
// Channel 2
int c2Volume = 0;
int c2Pan = 0;
int c2Knob1 = 0;
int c2Knob2 = 0;
int c2Mute = 0;
int c2Solo = 0;
// Channel 3
int c3Volume = 0;
int c3Pan = 0;
int c3Knob1 = 0;
int c3Knob2 = 0;
int c3Mute = 0;
int c3Solo = 0;
// Channel 4
int c4Volume = 0;
int c4Pan = 0;
int c4Knob1 = 0;
int c4Knob2 = 0;
int c4Mute = 0;
int c4Solo = 0;
// Master Channel
int mVolume = 0;
int mPan = 0;
int mKnob1 = 0;
int mKnob2 = 0;
int mMute = 0;
int mSolo = 0;


void setup() {
  // Mux1 Select
  pinMode(muxS0, OUTPUT); // Mux A
  pinMode(muxS1, OUTPUT); // Mux B
  pinMode(muxS2, OUTPUT); // Mux C
  pinMode(muxS3, OUTPUT); // Mux D
  
  pinMode(mux2In, INPUT); // Mux2 Input
  
  pinMode(button16Pin, INPUT); // button 16 input
  
  Serial.begin(31250);
}

void loop() {
  int s0 = 0;
  int s1 = 0;
  int s2 = 0;
  int s3 = 0;
  
  for (int count=0; count<16; count++) {  // which y pin is selected
    s0 = bitRead(count, 0); // s0 = count & 0x01;
    s1 = bitRead(count, 1); // s1 = (count>>1) & 0x01;
    s2 = bitRead(count, 2); // s2 = (count>>2) & 0x01
    s3 = bitRead(count, 3); // s3 = (count>>3) & 0x01;
    
    // Set select pins for mux 1
    digitalWrite(muxS0, s0);
    digitalWrite(muxS1, s1);
    digitalWrite(muxS2, s2);
    digitalWrite(muxS3, s3);
    
    readMuxInputs(count);
  }
  pot16 = analogRead(pot16Pin);
  pot17 = analogRead(pot17Pin);
  pot18 = analogRead(pot18Pin);
  pot19 = analogRead(pot19Pin);
  button16 = digitalRead(button16Pin);
  
  // Assign input to audio control variables
  // Channel 1
  /*
  c1Volume = pot??;
  c1Pan = pot??;
  c1Knob1 = pot??;
  c1Knob2 = pot??;
  c1Mute = button??;
  c1Solo = button??;*/
  // Channel 2
  /*
  c2Volume = pot??;
  c2Pan = pot??;
  c2Knob1 = pot??;
  c2Knob2 = pot??;
  c2Mute = button??;
  c2Solo = button??;*/
  // Channel 3
  /*
  c3Volume = pot??;
  c3Pan = pot??;
  c3Knob1 = pot??;
  c3Knob2 = pot??;
  c3Mute = button??;
  c3Solo = button??;*/
  // Channel 4
  /*
  c4Volume = pot??;
  c4Pan = pot??;
  c4Knob1 = pot??;
  c4Knob2 = pot??;
  c4Mute = button??;
  c4Solo = button??;*/
  // Master Channel
  /*
  mVolume = pot??;
  mPan = pot??;
  mKnob1 = pot??;
  mKnob2 = pot??;
  mMute = button??;
  mSolo = button??;*/
}


void readMuxInputs(int select) {
  switch (select) {
    case 0:
      pot0 = analogRead(mux1In);
      button0 = digitalRead(mux2In);
      break;
    case 1:
      pot1 = analogRead(mux1In);
      button1 = digitalRead(mux2In);
      break;
    case 2:
      pot2 = analogRead(mux1In);
      button2 = digitalRead(mux2In);
      break;
    case 3:
      pot3 = analogRead(mux1In);
      button3 = digitalRead(mux2In);
      break;
    case 4:
      pot4 = analogRead(mux1In);
      button4 = digitalRead(mux2In);
      break;
    case 5:
      pot5 = analogRead(mux1In);
      button5 = digitalRead(mux2In);
      break;
    case 6:
      pot6 = analogRead(mux1In);
      button6 = digitalRead(mux2In);
      break;
    case 7:
      pot7 = analogRead(mux1In);
      button7 = digitalRead(mux2In);
      break;
    case 8:
      pot8 = analogRead(mux1In);
      button8 = digitalRead(mux2In);
      break;
    case 9:
      pot9 = analogRead(mux1In);
      button9 = digitalRead(mux2In);
      break;
    case 10:
      pot10 = analogRead(mux1In);
      button10 = digitalRead(mux2In);
      break;
    case 11:
      pot11 = analogRead(mux1In);
      button11 = digitalRead(mux2In);
      break;
    case 12:
      pot12 = analogRead(mux1In);
      button12 = digitalRead(mux2In);
      break;
    case 13:
      pot13 = analogRead(mux1In);
      button13 = digitalRead(mux2In);
      break;
    case 14:
      pot14 = analogRead(mux1In);
      button14 = digitalRead(mux2In);
      break;
    case 15:
      pot15 = analogRead(mux1In);
      button15 = digitalRead(mux2In);
      break;
  }
}
