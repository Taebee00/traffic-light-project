# traffic-light-project
2021년 1학기 펌웨어및디바이스드라이버 기말 프로젝트

![image](https://github.com/Taebee00/traffic-light-project/assets/104549849/6f7f0567-ac9d-48b2-be8b-6dbf06ecc190)

상세 동영상 링크 <[https://youtu.be/T8NQtY3ZAkc](https://youtu.be/elduLZWbFLk)>

## 프로젝트 조건
- 4거리 신호등 구현 
  - 3방향, 한 방향에 차량신호 4개(빨간불,노란불,좌회전,파란불), 보행자신호 2개(빨간불, 파란불), 총 18개의 LED 사용  
- 일정한 시간이 지나면 다음 Step으로 이동
  - 한방향 기준: 파란불(7초) -> 노란불(2초) -> 빨간불/좌회전(7초) -> 빨간불/노란불(2초) 반복
- 한 번의 set가 지날 때마다, 메인보드의 LED에 4자릿수로 카운트를 표시 (0000 -> 0001 -> 0010 -> 0011 ... 1111 -> 0000)
- 메인보드 내의 스위치 1개는 Reset기능, 누르게 되면 카운트 LED가 0000으로 리셋됨
- 파란불이 꺼질 때까지 남은 시간을 7segment를 통해 표시함
- 보행자 LED가 꺼지기 2초 전에는 빠르게 깜빡이도록 함
- 외부보드에 Skip 스위치를 통해 step을 넘어갈 수 있게 함
  
## 프로젝트 기간
2023.05.16 ~ 2023.06.02

## 논리식 도출
| |R1/2|Y1/2|L1/2|G1/2|R3|Y3|L3|G3| |A|B|C|
|-|----|----|----|----|--|--|--|--|-|-|-|-|
|파|	1|	1|	1|	0|	0|	1|	1|	1|		|0|	0|	0|
|노|	1|	0|	1|	1|	0|	1|	1|	1|		|0|	0|	1|
|빨/좌|	0|	1|	0|	1|	0|	1|	1|	1|	|	0|	1|	0|
|빨/노|	0|	0|	1|	1|	0|	1|	1|	1|	|	0|	1|	1|
|빨|	0|	1|	1|	1|	1|	1|	1|	0|		|1|	0|	0|
|빨|	0|	1|	1|	1|	1|	0|	1|	1|		|1|	0|	1|
|빨|	0|	1|	1|	1|	0|	1|	0|	1|		|1|	1|	0|
|빨|	0|	1|	1|	1|	0|	0|	1|	1|		|1|	1|	1|

## 회로도 구성

![image](https://github.com/Taebee00/traffic-light-project/assets/104549849/55f0f155-59ac-44c7-8fbe-2a0b0b09cfb6)



## Detection
### Face Detection
- Dlib library 에서 제공하는 `get_frontal_face_detector`함수를 이용하여 이미지 속 얼굴의 위치를 detect
- `shape_predictor`함수를 이용하여 detect된 얼굴을 68개의 landmark로 변환

![image](https://github.com/Taebee00/sleep-detection-system/assets/104549849/a8d12e17-0f28-4d23-9dc4-b51d683f8103)

### Eye Blink Detection
- Eye Aspect Ratio(EAR) Algorithm

  눈의 종횡 비 변화를 이용해 눈 감김을 판단하는 알고리즘
  
  ![image](https://github.com/Taebee00/sleep-detection-system/assets/104549849/50a3af23-f12e-4373-a9cb-432633a210e4)
  
- Face Detection을 통해 얻은 68개의 landmark 중 눈에 해당하는 36~47번 landmark를 이용하여 EAR rate를 계산
- EAR rate가 감소하며 눈의 종횡 비가 감소한 것이므로 '눈 감김'으로 판단
- '눈 감김'의 빈도를 count 하여 졸음을 감지

![image](https://github.com/Taebee00/sleep-detection-system/assets/104549849/5df815f4-9d9b-41ca-ac85-fee027cfcc9b)

## Warning
- I2C LCD에 경고 메세지 출력
`lcd.writ_string('Careful\r\nAre you sleepy?)`
- espeak를 통해 경고 메시지를 TTS 방식으로 출력
`os.system("espeak -a 200 -p 20 -s 240 -v en-us+f5" + " " +text)`

## 기대 효과 및 장점
- 단순히 눈을 감았다 뜨는 것이 아닌, 일정한 시간 안에 몇 번 감았는지를 계산해 운전자의 졸음 여부를 확실하고 체계적으로 감시하고 감지할 수 있음
- 졸음을 감지하면 운전자에게 시각적으로, 청각적으로 신호를 전달하여 운전자가 즉각적인 피드백을 받을 수 있도록 함
- 운전 관련 분야가 아닌 거짓말 탐지 등, 눈을 깜빡임을 인식하는 다른 다양한 분야에도 쓰일 수 있음

