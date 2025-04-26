# robot-grisp-interrupt
simulate a robot with grisp moving around three positions. The grisp is simulated with a LED (on:closed, off:open). This project uses ESP32 interrupts and was develooped at platformIO integrated with wokwi.
Firstly, the servo moves to guarantee 0 degrees. Then a random position between 1 and 3 is chosen and it goes from pos1 to posx
After that it moves according to the button p1, p2, p3. Here I simulated the positions with angles (p1 = 0, p2 = 90, p3 - 180) degrees

Required materiais (Brazil price, without taxes, robocore.net, 26_04_2025):
- pushbutton, R$ 0.45und, qtd: 3, R$ 1.50
- esp42, R$ 50, qtd 1 R$ 50
- display oled 0.96 I2C, R$ 23, qtd 1, R$ 23
- microservo 9g sg90, R$ 13, qtd 1, R$ 13
- resitor 470R, R$ 0.07, qtd 1, R$ 0.07
- led, R$ 0.25, qtd 1, R$ 0.25
  ~R$88

https://wokwi.com/projects/428257902666164225

https://github.com/user-attachments/assets/589a6784-8367-49d1-93aa-7f937bcdcff1

