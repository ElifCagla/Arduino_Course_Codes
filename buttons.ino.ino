#define BIRINCI_LED_PIN 7
#define IKINCI_LED_PIN 6
#define BTN_PIN 2

bool btn_status = false;
bool birinci_led_state = false;
bool ikinci_led_state = false;
bool last_btn_status = false;

void setup()
{
  pinMode(BIRINCI_LED_PIN, OUTPUT);
  pinMode(IKINCI_LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  btn_status = digitalRead(BTN_PIN);

  while(btn_status == LOW && last_btn_status == HIGH){
    while(1){
      Serial.println("LAMBALARI ACTIM");
      birinci_led_state = !birinci_led_state;
      digitalWrite(BIRINCI_LED_PIN, birinci_led_state ? HIGH : LOW);

      if (birinci_led_state){
        Serial.println("BİRİNCİ LAMBAYI ACTIM");
        delay(1000);
        digitalWrite(BIRINCI_LED_PIN, LOW);
      }
      else{
        //digitalWrite(BIRINCI_LED_PIN, LOW);
        Serial.println("BİRİNCİ LAMBAYI KAPATTIM");
      }
      delay(100);
      ikinci_led_state = !ikinci_led_state;
      digitalWrite(IKINCI_LED_PIN, ikinci_led_state ? HIGH : LOW);

      if(birinci_led_state){
        Serial.println("IKINCI LAMBAYI ACTIM");
        delay(1000);
        digitalWrite(IKINCI_LED_PIN, LOW);

      }
      else{
        digitalWrite(IKINCI_LED_PIN, LOW);
        Serial.println("IKINCI LAMBAYI KAPATTIM");
        delay(1000);
      }

      /*if(btn_status == LOW && last_btn_status == HIGH ){
        digitalWrite(BIRINCI_LED_PIN, LOW);
        digitalWrite(IKINCI_LED_PIN, LOW);
        break;
      }*/
    }
    break;
  }
  delay(50);
  last_btn_status = btn_status;
}