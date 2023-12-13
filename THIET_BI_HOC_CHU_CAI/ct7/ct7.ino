#include <SPI.h>
#include <TFT_22_ILI9225.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
#include <DS3231.h>
#include <PS2Keyboard.h>
#include <Math.h>
#include <../fonts/Serif_bold_20.h>
#include <../fonts/Serif_bold_80.h>

const int DataPin = 3;
const int IRQpin =  2;
PS2Keyboard keyboard;

DS3231 rtc(SDA, SCL);

SoftwareSerial mySoftwareSerial(11,10);
DFRobotDFPlayerMini myDFPlayer;

#define TFT_RST 48
#define TFT_RS  49
#define TFT_CS  53 // SS
#define TFT_SDI 51 // MOSI
#define TFT_CLK 52 // SCK
#define TFT_LED 0 // 0 if wired to +5V directly
#define TFT_BRIGHTNESS 200 // Initial brightness of TFT backlight (optional)

// Use hardware SPI (faster - on Uno: 13-SCK, 12-MISO, 11-MOSI)
TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_LED, TFT_BRIGHTNESS);
// Use software SPI (slower)
//TFT_22_ILI9225 tft = TFT_22_ILI9225(TFT_RST, TFT_RS, TFT_CS, TFT_SDI, TFT_CLK, TFT_LED, TFT_BRIGHTNESS);
// Variables and constants
uint16_t x, y;

#define chedo 4
#define cndocthoigian 5
#define tvolume 6
#define gvolume 7
#define playpause 8
#define lui 12
#define tien 9
#define tgt 22
#define tgv 23
#define tgc 24
#define tgd 25
#define tugiac 26
#define thang 27
#define binhhanh 28
#define thoi 29
#define chunhat 30
#define vuong 31
#define tron 32
#define elip 33
#define ngugiac 34
#define lucgiac 35

int gio, phut, giay, dem, demchedo, gtvolume, cbh, ps, song, tamdung;
int demlannhantgt;
int demlannhantgv;
int demlannhantgc;
int demlannhantgd;
int demlannhanht;
int demlannhanhbh;
int demlannhanhthoi;
int demlannhanhcn;
int demlannhanhv;
int demlannhanhtr;
int demlannhanng;
int demlannhanlg;
int demlannhanhel;
int demlannhanhtg;
char key, dau;
float kq, so1, so2, num;
String chu, bieuthuc, bieuthuckq;
uint16_t color;

void setup() {
  Serial.begin(9600);

  pinMode(chedo, INPUT_PULLUP);
  pinMode(cndocthoigian, INPUT_PULLUP);
  pinMode(playpause, INPUT_PULLUP);
  pinMode(lui, INPUT_PULLUP);
  pinMode(tien, INPUT_PULLUP);
  pinMode(tgt, INPUT_PULLUP);
  pinMode(tgv, INPUT_PULLUP);
  pinMode(tgc, INPUT_PULLUP);
  pinMode(tgd, INPUT_PULLUP);
  pinMode(tugiac, INPUT_PULLUP);
  pinMode(thang, INPUT_PULLUP);
  pinMode(binhhanh, INPUT_PULLUP);
  pinMode(thoi, INPUT_PULLUP);
  pinMode(chunhat, INPUT_PULLUP);
  pinMode(vuong, INPUT_PULLUP);
  pinMode(tron, INPUT_PULLUP);
  pinMode(elip, INPUT_PULLUP);
  pinMode(ngugiac, INPUT_PULLUP);
  pinMode(lucgiac, INPUT_PULLUP);

  mySoftwareSerial.begin(9600);
  myDFPlayer.begin(mySoftwareSerial);
  rtc.begin();
  keyboard.begin(DataPin, IRQpin);
  tft.begin();

  demchedo=0;
  myDFPlayer.volume(15);
  gtvolume = 15;
  num = 0;
  cbh = 0;
  ps = 1;
  song = 0;
  tamdung = 0;
  demlannhantgt=0;
  demlannhantgv=0;
  demlannhantgc=0;
  demlannhantgd=0;
  demlannhanht=0;
  demlannhanhbh=0;
  demlannhanhthoi=0;
  demlannhanhcn=0;
  demlannhanhv=0;
  demlannhanhtr=0;
  demlannhanng=0;
  demlannhanlg=0;
  demlannhanhel=0;
  demlannhanhtg=0;
  //rtc.setDOW(MONDAY);
 //rtc.setTime(11,55, 0);
//rtc.setDate(24, 2, 2020);
}

// Loop
void loop() {
 setvolume();
  thoigian();
  docthoigian();

  if (digitalRead(chedo)==0){
    demchedo=1;
    while (digitalRead(chedo)==0){}
  }

  if (demchedo==6) demchedo=0;

  if (demchedo==1){
    myDFPlayer.playFolder(6, 1);
    while (1){
      docthoigian();
      setvolume();
      thoigian();
      CHUTV();
      if (digitalRead(chedo)==0){
        while (digitalRead(chedo)==0){}
        demchedo+=1;
        tft.setGFXFont(&Serif_bold_80);
        tft.drawGFXText(60, 170, chu, COLOR_BLACK);
        break;
      }
    }
  }
  
  if (demchedo==2){
    myDFPlayer.playFolder(6, 2);
    while (1){
      docthoigian();
      setvolume();
      thoigian();
      CHUTA();
      if (digitalRead(chedo)==0){
        while (digitalRead(chedo)==0){}
        demchedo+=1;
        tft.setGFXFont(&Serif_bold_80);
        tft.drawGFXText(60, 170, chu, COLOR_BLACK);
        break;
      }
    }
  }
  
  if (demchedo==3){
    tft.setGFXFont(&Serif_bold_20);
    tft.drawGFXText(12, 110, "PHEP TOAN", COLOR_GREEN);
    myDFPlayer.playFolder(6, 3);
    while (1){
      docthoigian();
      setvolume();
      thoigian();
      SO();
      if (digitalRead(chedo)==0){
        while (digitalRead(chedo)==0){}
        demchedo+=1;
        tft.clear();
        bieuthuc = "";
        bieuthuckq = "";
        break;
      }
    }
  }

  if (demchedo==4){
    myDFPlayer.playFolder(6, 6);
    while (1){
      docthoigian();
      setvolume();
      thoigian();
      TOANHINH();
      if (digitalRead(chedo)==0){
        while (digitalRead(chedo)==0){}
        demchedo+=1;
        break;
      }
    }
  }


  if (demchedo==5){
    myDFPlayer.playFolder(6, 8);
    while (1){
      docthoigian();
      setvolume();
      thoigian();
      NGHENHAC();
      if (digitalRead(chedo)==0){
        while (digitalRead(chedo)==0){}
        demchedo+=1;
        ps = 1;
        song = 0;
        myDFPlayer.pause();
        break;
      }
    }
  }

}

void SO(){
  if (keyboard.available()){
    char c = keyboard.read();
    key = c;
    tinhtoan();

    if (c=='+'){
      myDFPlayer.playFolder(3, 43);
    }
    else if (c=='-'){
      myDFPlayer.playFolder(3, 44);
    }
    else if (c=='*'){
      myDFPlayer.playFolder(3, 45);
    }
    else if (c==';'){
      myDFPlayer.playFolder(3, 46);
    }
     else if (c=='['){
      myDFPlayer.playFolder(3, 49);
    }
     else if (c==']'){
      myDFPlayer.playFolder(3, 50);
    }
     else if (c=='/'){
      myDFPlayer.playFolder(6, 5);
    }
  }
}

void CHUTV(){
  if (keyboard.available()){
    tft.setGFXFont(&Serif_bold_80);
    char c = keyboard.read();
    
    if (c=='a'){
      myDFPlayer.playFolder(1, 1);
      displaytft(String(c));
    }
    else if (c=='b'){
      myDFPlayer.playFolder(1, 2);
      displaytft(String(c));
    }
    else if (c=='c'){
      myDFPlayer.playFolder(1, 3);
      displaytft(String(c));
    }
    else if (c=='d'){
      myDFPlayer.playFolder(1, 4);
      displaytft(String(c));
    }
    else if (c=='e'){
      myDFPlayer.playFolder(1, 5);
      displaytft(String(c));
    }
    else if (c=='g'){
      myDFPlayer.playFolder(1, 6);
      displaytft(String(c));
    }
    else if (c=='h'){
      myDFPlayer.playFolder(1, 7);
      displaytft(String(c));
    }
    else if (c=='i'){
      myDFPlayer.playFolder(1, 8);
      displaytft(String(c));
    }
    else if (c=='k'){
      myDFPlayer.playFolder(1, 9);
      displaytft(String(c));
    }
    else if (c=='l'){
      myDFPlayer.playFolder(1, 10);
      displaytft(String(c));
    }
    else if (c=='m'){
      myDFPlayer.playFolder(1, 11);
      displaytft(String(c));
    }
    else if (c=='n'){
      myDFPlayer.playFolder(1, 12);
      displaytft(String(c));
    }
    else if (c=='o'){
      myDFPlayer.playFolder(1, 13);
      displaytft(String(c));
    }
    else if (c=='p'){
      myDFPlayer.playFolder(1, 14);
      displaytft(String(c));
    }
    else if (c=='q'){
      myDFPlayer.playFolder(1, 15);
      displaytft(String(c));
    }
    else if (c=='r'){
      myDFPlayer.playFolder(1, 16);
      displaytft(String(c));
    }
    else if (c=='s'){
      myDFPlayer.playFolder(1, 17);
      displaytft(String(c));
    }
    else if (c=='t'){
      myDFPlayer.playFolder(1, 18);
      displaytft(String(c));
    }
    else if (c=='u'){
      myDFPlayer.playFolder(1, 19);
      displaytft(String(c));
    }
    else if (c=='v'){
      myDFPlayer.playFolder(1, 20);
      displaytft(String(c));
    }
    else if (c=='x'){
      myDFPlayer.playFolder(1, 21);
      displaytft(String(c));
    }
    else if (c=='y'){
      myDFPlayer.playFolder(1, 22);
      displaytft(String(c));
    }
    else if (c=='`'){  //ă
      myDFPlayer.playFolder(1, 23);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c==PS2_TAB){  //â
      myDFPlayer.playFolder(1, 24);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c==PS2_DELETE){ //đ
      myDFPlayer.playFolder(1, 25);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c==PS2_ESC){  //ê
      myDFPlayer.playFolder(1, 26);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c=='\\'){  //ô
      myDFPlayer.playFolder(1, 27);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c==PS2_UPARROW){  //ơ
      myDFPlayer.playFolder(1, 28);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c==PS2_DOWNARROW){  //ư
      myDFPlayer.playFolder(1, 29);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }   
    else if (c==PS2_PAGEUP){  
      myDFPlayer.playFolder(6, 4);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c==PS2_LEFTARROW){  
      myDFPlayer.playFolder(3, 40);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c==PS2_RIGHTARROW){  
      myDFPlayer.playFolder(3, 42);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c==','){  
      myDFPlayer.playFolder(3, 41);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c=='\''){  
      myDFPlayer.playFolder(3, 39);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if (c==PS2_PAGEDOWN){  
      myDFPlayer.playFolder(3, 38);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if ((c=='f')||(c=='j')||(c=='w')||(c=='z')){
      myDFPlayer.playFolder(1, 30);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
  }
}

void CHUTA(){
  if (keyboard.available()){
    tft.setGFXFont(&Serif_bold_80);
    char c = keyboard.read();
    
    if (c=='a'){
      myDFPlayer.playFolder(2, 1);
      displaytft(String(c));
    }
    else if (c=='b'){
      myDFPlayer.playFolder(2, 2);
      displaytft(String(c));
    }
    else if (c=='c'){
      myDFPlayer.playFolder(2, 3);
      displaytft(String(c));
    }
    else if (c=='d'){
      myDFPlayer.playFolder(2, 4);
      displaytft(String(c));
    }
    else if (c=='e'){
      myDFPlayer.playFolder(2, 5);
      displaytft(String(c));
    }
    else if (c=='f'){
      myDFPlayer.playFolder(2, 6);
      displaytft(String(c));
    }
    else if (c=='g'){
      myDFPlayer.playFolder(2, 7);
      displaytft(String(c));
    }
    else if (c=='h'){
      myDFPlayer.playFolder(2, 8);
      displaytft(String(c));
    }
    else if (c=='i'){
      myDFPlayer.playFolder(2, 9);
      displaytft(String(c));
    }
    else if (c=='j'){
      myDFPlayer.playFolder(2, 10);
      displaytft(String(c));
    }
    else if (c=='k'){
      myDFPlayer.playFolder(2, 11);
      displaytft(String(c));
    }
    else if (c=='l'){
      myDFPlayer.playFolder(2, 12);
      displaytft(String(c));
    }
    else if (c=='m'){
      myDFPlayer.playFolder(2, 13);
      displaytft(String(c));
    }
    else if (c=='n'){
      myDFPlayer.playFolder(2, 14);
      displaytft(String(c));
    }
    else if (c=='o'){
      myDFPlayer.playFolder(2, 15);
      displaytft(String(c));
    }
    else if (c=='p'){
      myDFPlayer.playFolder(2, 16);
      displaytft(String(c));
    }
    else if (c=='q'){
      myDFPlayer.playFolder(2, 17);
      displaytft(String(c));
    }
    else if (c=='r'){
      myDFPlayer.playFolder(2, 18);
      displaytft(String(c));
    }
    else if (c=='s'){
      myDFPlayer.playFolder(2, 19);
      displaytft(String(c));
    }
    else if (c=='t'){
      myDFPlayer.playFolder(2, 20);
      displaytft(String(c));
    }
    else if (c=='u'){
      myDFPlayer.playFolder(2, 21);
      displaytft(String(c));
    }
    else if (c=='v'){
      myDFPlayer.playFolder(2, 22);
      displaytft(String(c));
    }
    else if (c=='w'){
      myDFPlayer.playFolder(2, 23);
      displaytft(String(c));
    }
    else if (c=='x'){
      myDFPlayer.playFolder(2, 24);
      displaytft(String(c));
    }
    else if (c=='y'){
      myDFPlayer.playFolder(2, 25);
      displaytft(String(c));
    }
    else if (c=='z'){
      myDFPlayer.playFolder(2, 26);
      displaytft(String(c));
    }
   else if ((c=='`')||(c==PS2_TAB)||(c==PS2_ESC)||(c==PS2_DELETE)||(c=='\\')||(c==PS2_UPARROW)||(c==PS2_DOWNARROW))
            {
      myDFPlayer.playFolder(2, 28);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
    else if ((c==PS2_LEFTARROW)||(c==PS2_RIGHTARROW)||(c==',')||(c==PS2_PAGEDOWN)||(c=='\''))
     {
      myDFPlayer.playFolder(2, 27);
      tft.drawGFXText(60, 170, chu, COLOR_BLACK);
    }
  }
  
}

void displaytft(String a){
  tft.setGFXFont(&Serif_bold_80);
  tft.drawGFXText(60, 170, chu, COLOR_BLACK);
  a.toUpperCase();
  tft.drawGFXText(60, 170, a, COLOR_GREEN);
  chu = String(a);
}

void TOANHINH(){
  if ((digitalRead(tgt)==0)&&(demlannhantgt==0))
  {
    while (digitalRead(tgt)==0){}
    myDFPlayer.playFolder(8, 1);
    demlannhantgt=1;
  }
   if ((digitalRead(tgv)==0)&&(demlannhantgv==0))
  {
    while (digitalRead(tgv)==0){}
    myDFPlayer.playFolder(8, 2);
    demlannhantgv=1;
  }
  if ((digitalRead(tgc)==0)&&(demlannhantgc==0))
  {
   while (digitalRead(tgc)==0){}
   myDFPlayer.playFolder(8, 3);
   demlannhantgc=1;
  }
  if ((digitalRead(tgd)==0)&&(demlannhantgd==0))
  {
   while (digitalRead(tgd)==0){}
   myDFPlayer.playFolder(8, 4);
   demlannhantgd=1;
  }
  if ((digitalRead(thang)==0)&&(demlannhanht==0))
  {
   while (digitalRead(thang)==0){}
   myDFPlayer.playFolder(8, 5);
   demlannhanht=1;
  }
  if ((digitalRead(binhhanh)==0)&&(demlannhanhbh==0))
  {
   while (digitalRead(binhhanh)==0){}
   myDFPlayer.playFolder(8, 6);
   demlannhanhbh=1;
  }
  if ((digitalRead(thoi)==0)&&(demlannhanhthoi==0))
  {
   while (digitalRead(thoi)==0){}
   myDFPlayer.playFolder(8, 7);
   demlannhanhthoi=1;
  }
  if ((digitalRead(chunhat)==0)&&(demlannhanhcn==0))
  {
   while (digitalRead(chunhat)==0){}
   myDFPlayer.playFolder(8, 8);
   demlannhanhcn=1;
  }
  if ((digitalRead(vuong)==0)&&(demlannhanhv==0))
  {
   while (digitalRead(vuong)==0){}
   myDFPlayer.playFolder(8, 9);
   demlannhanhv=1;
  }
  if ((digitalRead(tron)==0)&&(demlannhanhtr==0))
  {
   while (digitalRead(tron)==0){}
   myDFPlayer.playFolder(8, 10);
   demlannhanhtr=1;
  }
  if ((digitalRead(ngugiac)==0)&&(demlannhanng==0))
  {
   while (digitalRead(ngugiac)==0){}
   myDFPlayer.playFolder(8, 11);
   demlannhanng=1;
  }
  if ((digitalRead(lucgiac)==0)&&(demlannhanlg==0))
  {
   while (digitalRead(lucgiac)==0){}
   myDFPlayer.playFolder(8, 12);
   demlannhanlg=1;
  }
  if ((digitalRead(elip)==0)&&(demlannhanhel==0))
  {
   while (digitalRead(elip)==0){}
   myDFPlayer.playFolder(8, 13);
   demlannhanhel=1;
  }
  if ((digitalRead(tugiac)==0)&&(demlannhanhtg==0))
  {
   while (digitalRead(tugiac)==0){}
   myDFPlayer.playFolder(8, 14);
   demlannhanhtg=1;
  }
//TA
  if ((digitalRead(tgt)==0)&&(demlannhantgt==1))
  {
   while (digitalRead(tgt)==0){}
   myDFPlayer.playFolder(7, 1);
   demlannhantgt=0;
  }
  if ((digitalRead(tgv)==0)&&(demlannhantgv==1))
  {
   while (digitalRead(tgv)==0){}
   myDFPlayer.playFolder(7, 2);
   demlannhantgv=0;
  }
  if ((digitalRead(tgc)==0)&&(demlannhantgc==1))
    {
    while (digitalRead(tgc)==0){}
    myDFPlayer.playFolder(7, 3);
    demlannhantgc=0;
  }
  if ((digitalRead(tgd)==0)&&(demlannhantgd==1))
    {
    while (digitalRead(tgd)==0){}
    myDFPlayer.playFolder(7, 4);
    demlannhantgd=0;
  }
   if ((digitalRead(thang)==0)&&(demlannhanht==1))
    {
    while (digitalRead(thang)==0){}
    myDFPlayer.playFolder(7, 5);
    demlannhanht=0;
  }
   if ((digitalRead(binhhanh)==0)&&(demlannhanhbh==1))
    {
    while (digitalRead(binhhanh)==0){}
    myDFPlayer.playFolder(7, 6);
    demlannhanhbh=0;
  }
   if ((digitalRead(thoi)==0)&&(demlannhanhthoi==1))
    {
    while (digitalRead(thoi)==0){}
    myDFPlayer.playFolder(7, 7);
    demlannhanhthoi=0;
  }
  if ((digitalRead(chunhat)==0)&&(demlannhanhcn==1))
    {
    while (digitalRead(chunhat)==0){}
    myDFPlayer.playFolder(7, 8);
    demlannhanhcn=0;
  }
  if ((digitalRead(vuong)==0)&&(demlannhanhv==1))
    {
    while (digitalRead(vuong)==0){}
    myDFPlayer.playFolder(7, 9);
    demlannhanhv=0;
  }
  if ((digitalRead(tron)==0)&&(demlannhanhtr==1))
    {
    while (digitalRead(tron)==0){}
    myDFPlayer.playFolder(7, 10);
    demlannhanhtr=0;
  }
  if ((digitalRead(ngugiac)==0)&&(demlannhanng==1))
    {
    while (digitalRead(ngugiac)==0){}
    myDFPlayer.playFolder(7, 11);
    demlannhanng=0;
  }
   if ((digitalRead(lucgiac)==0)&&(demlannhanlg==1))
    {
    while (digitalRead(lucgiac)==0){}
    myDFPlayer.playFolder(7, 12);
    demlannhanlg=0;
  }
   if ((digitalRead(elip)==0)&&(demlannhanhel==1))
    {
    while (digitalRead(elip)==0){}
    myDFPlayer.playFolder(7, 13);
    demlannhanhel=0;
  }
   if((digitalRead(tugiac)==0)&&(demlannhanhtg==1))
    {
    while (digitalRead(tugiac)==0){}
    myDFPlayer.playFolder(7, 14);
    demlannhanhtg=0;
  }
}

void NGHENHAC(){
  int x = 11;  // Số bài nhạc trong Folder
  
  if (digitalRead(playpause)==0){
    while (digitalRead(playpause)==0){}
    ps += 1;
    if (ps==3) ps = 1;

    if (ps==1) myDFPlayer.start();
    if (ps==2) myDFPlayer.pause();
  }

  if (digitalRead(tien)==0){
    while (digitalRead(tien)==0){}
    song += 1;
    if (song>x) song = 1;
    myDFPlayer.playFolder(9, song);
  }

  if (digitalRead(lui)==0){
    while (digitalRead(lui)==0){}
    song -= 1;
    if (song<1) song = x;
    myDFPlayer.playFolder(9, song);
  }
}

void tinhtoan(){
  tft.setGFXFont(&Serif_bold_20);
  
  if ((key=='1')||(key=='2')||(key=='3')||(key=='4')||(key=='5')||(key=='6')||(key=='7')||(key=='8')||(key=='9')||(key=='0')){
    bieuthuc += String(key);
    tft.drawGFXText(10, 150, bieuthuc, COLOR_GREEN);

    if (cbh==1){
      myDFPlayer.playFolder(3, 50);  // Đọc căn bậc hai
      delay(1000);
      myDFPlayer.playFolder(3, 58);  // Đọc của
      delay(800);
    }
    
    if (num==0){
      num = String(key).toInt();
      if (num==0) myDFPlayer.playFolder(3, 48);
      else docso(num, 0);
    }
    else{
      num = (num*10) + String(key).toInt();
      docso(num, 0);
    }  
  }
  if ((key=='+')||(key=='-')||(key=='*')||(key==';')){
    if (key==';') dau = ':';
    else dau = key;
    
    if(cbh==1){
      bieuthuc += ")";
      cbh = 0;
      num = sqrt(num);
      tft.drawGFXText(10, 150, bieuthuc, COLOR_GREEN);
    }
    
    so1 = num;
    num = 0;

    if (dau=='*') bieuthuc += "x";
    else bieuthuc += String(dau);
    tft.drawGFXText(10, 150, bieuthuc, COLOR_GREEN);
  }
  if (key=='['){
    bieuthuc += "^2";
    num = num*num;
    tft.drawGFXText(10, 150, bieuthuc, COLOR_GREEN);
  }
  if (key==']'){
    cbh = 1;
    bieuthuc += "sqrt(";
    tft.drawGFXText(10, 150, bieuthuc, COLOR_GREEN);
  }
  if (key=='='){
    tft.drawGFXText(10, 180, bieuthuckq, COLOR_BLACK);
    bieuthuckq = "";
    
    if(cbh==1){
      bieuthuc += ")";
      num = sqrt(num);
      tft.drawGFXText(10, 150, bieuthuc, COLOR_GREEN);
    }
    
    bieuthuckq += "=";
    tft.drawGFXText(10, 180, bieuthuckq, COLOR_GREEN);
    myDFPlayer.playFolder(3, 47);
    delay(1000);
    
    so2 = num;
    if (dau=='+') kq = so1 + so2;
    else if (dau=='-') kq = so1 - so2;
    else if (dau=='*') kq = so1 * so2;
    else if (dau==':') kq = so1 / so2;
    if ((dau!='+')&(dau!='-')&(dau!='*')&(dau!=':')){
      if (cbh==1) kq = num;
      else kq = num;
    }

    cbh = 0;
    String bien = String(kq,2);
    bien = bien.substring(bien.length()-2, bien.length()); 
    
    if ((so2==0)&(dau==':')){
      bieuthuckq += "Nan";
      tft.drawGFXText(10, 180, bieuthuckq, COLOR_GREEN);
      myDFPlayer.playFolder(3, 53);
    }
    else{
      if (bien.toInt()!=0) bieuthuckq += String(kq,2);  // int(kq*100)%100: Lấy phần thập phân
      else bieuthuckq += String(int(kq));
      tft.drawGFXText(10, 180, bieuthuckq, COLOR_GREEN);
      if (kq<=-1) myDFPlayer.playFolder(3, 56);  // Đọc "không đúng"
    }
 
    if (kq==0) myDFPlayer.playFolder(3, 48);
    if (kq>0) docso(int(kq), bien.toInt());
  }
  if (key=='.'){
    cbh = 0;
    so1 = 0; so2 = 0;
    num = 0;
    dau = ' ';
    tft.setGFXFont(&Serif_bold_20);
    tft.drawGFXText(10, 150, bieuthuc, COLOR_BLACK);
    tft.drawGFXText(10, 180, bieuthuckq, COLOR_BLACK);
    bieuthuc = "";
    bieuthuckq = "";
  }
}

void docso(int x, int tp){ 
  if (x==0) myDFPlayer.playFolder(3, 48);
  
  if ((x>=0)&(x<=10)){
    doc1chuso(x, 0);
  }  
  if ((x>10)&(x<=99)){
    doc2chuso(x); 
  }
  if ((x>99)&(x<=999)){
    doc3chuso(x);   
  }
  if ((x>999)&(x<=9999)){
    doc4chuso(x);   
  }
  if (x==10000){
    myDFPlayer.playFolder(3, 37);   
  }

  if (tp==0){}
  else{
    myDFPlayer.playFolder(3, 57);  // Đọc phẩy
    delay(800);
    if (tp%10 == 0) docso(tp/10, 0);
    else docso(tp, 0);
  }
}

void doc1chuso(int x, int chuc){
  if (chuc==0) myDFPlayer.playFolder(3, x);
  else{
    if (x==5) myDFPlayer.playFolder(3, 54);  // Đọc lăm
    if (x==1){
      if (chuc==1) myDFPlayer.playFolder(3, 1);  // Đọc một
      if (chuc>1) myDFPlayer.playFolder(3, 55);  // Đọc mốt
    }
    if ((x!=5)&(x!=1)) myDFPlayer.playFolder(3, x);
  }
  delay(700);
}

void doc2chuso(int x){
  if (x/10==0) myDFPlayer.playFolder(3, 51);  // Đọc lẻ
  else myDFPlayer.playFolder(3, x/10+9);
  int du = x%10;
  if (du!=0){
    delay(900);
    doc1chuso(du, x/10);
  }  
}

void doc3chuso(int x){
  if (x/100==0) myDFPlayer.playFolder(3, 52);  // Đọc không trăm
  else myDFPlayer.playFolder(3, x/100+18);
  int du = x%100;
  if (du!=0){
    delay(900);
    doc2chuso(du);
  }
}

void doc4chuso(int x){
  myDFPlayer.playFolder(3, x/1000+27);
  int du = x%1000;
  if (du!=0){
    delay(900);
    doc3chuso(du);
  }
}

void setvolume(){
  if (digitalRead(gvolume)==0){
    while (digitalRead(gvolume)==0){}
    gtvolume -=1;
    gtvolume = constrain(gtvolume, 0, 30);
    myDFPlayer.volume(gtvolume);
  }
  
  if (digitalRead(tvolume)==0){
    while (digitalRead(tvolume)==0){}
    gtvolume +=1;
    gtvolume = constrain(gtvolume, 0, 30);
    myDFPlayer.volume(gtvolume);
  }
}

void docthoigian(){
  if (digitalRead(cndocthoigian)==0){ 
    myDFPlayer.playFolder(5, gio+1);  // Đọc giờ
    delay(2500);
    myDFPlayer.playFolder(4, phut+1);  // Đọc phút
  }
}

void thoigian(){
  if (giay== 59){
    //dem = phut;
    color = COLOR_BLACK;
  }
  else color = COLOR_WHITE;

  tft.setGFXFont(&Serif_bold_20);
  tft.drawGFXText(28, 25, "KHKT QG", COLOR_RED);
  
  DOW(rtc.getDOWStr(),15,50);
  DATE(rtc.getDateStr(),15,75);
  TIME(rtc.getTimeStr(),95,50);
}

void DOW(String a, int x, int y){
  tft.drawGFXText(x, y, a.substring(0,3), color);
}

void DATE(String a, int x, int y){
  a = a.substring(0,2) + "/" + a.substring(3,5) + "/" + a.substring(6,10);
  tft.drawGFXText(x, y, a, color);
}

void TIME(String a, int x, int y){
  tft.drawGFXText(x, y, a.substring(0,5), color);
  tft.drawGFXText(x, y, "", color);
  gio = (a.substring(0,2)).toInt();
  phut = (a.substring(3,5)).toInt();
  giay = (a.substring(6,8)).toInt();
}
