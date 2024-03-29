//***************프로그램 설명******************//
// 20154215 구명회
// 가변저항을 아날로그 A5번 핀에 연결하고, 
// 피에조 스피커를 디지털 6번 핀에 연결합니다.
// 가변저항 값을 변화시킴에 따라
// 피에조 스피커에서 도레미파솔라시도를 재생할 수 있습니다.
//**************프로그램 설명 끝****************//

// 음계를 저장해놓은 헤더
#include <pitches.h>
// 음 길이 10을 매크로상수 DURATION으로 정의합니다.
#define DURATION 10

// val은 가변저항이 A5핀에 연결되어 있으며,
// 이 핀을 입력으로 사용합니다.
// pie는 피에조 스피커가 디지털 6번핀에 연결되어 있으며,
// 이 핀을 출력으로 사용합니다.
int val = A5;
int pie = 6;

// 변수 R은 가변저항값을 저장합니다.
// R은 0 ~ 1023의 값을 갖는데,
// 이를 map함수를 사용해서 0 ~ 7의 값으로 변환시켜
// 변수 i에 저장합니다.
long R, i;

int  notes[] = {  // 도레미파솔라시도 음계
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, 
  NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5 };

void setup() {
  // 시리얼 모니터를 출력하기 위함
  // Serial.begin(9600);
  
  pinMode(val, INPUT);  
  pinMode(pie, OUTPUT); 
}

void loop() {
  // 가변저항 값을 R에 저장
  R = analogRead(val); 
  // R값을 map함수로 변환시킨 값을 i에 저장    
  i = map(R,0,1023,0,7);  
  
  // 피에조 스피커를 작동
  // 가변저항의 값에 따라 변환되는 i는 0 ~ 7의 값을 가지며
  // 이에따라 notes[0] ~ notes[7]를 연주함
  tone(pie, notes[i], DURATION);

/*
  // 시리얼 모니터로 가변저항값을 확인하기 위함
  Serial.print(R);
  Serial.print(" ");
  Serial.println(i);
  */
}
