#include <DFMiniMp3.h>

class Mp3Notify
{
  public:
    static void OnError(uint16_t errorCode)
    {
      // see DfMp3_Error for code meaning
      Serial.println();
      Serial.print("Com Error ");
      Serial.println(errorCode);
    }

    static void OnPlayFinished(uint16_t globalTrack)
    {
      Serial.println();
      Serial.print("Play finished for #");
      Serial.println(globalTrack);
    }

    static void OnCardOnline(uint16_t code)
    {
      Serial.println();
      Serial.print("Card online ");
      Serial.println(code);
    }

    static void OnCardInserted(uint16_t code)
    {
      Serial.println();
      Serial.print("Card inserted ");
      Serial.println(code);
    }

    static void OnCardRemoved(uint16_t code)
    {
      Serial.println();
      Serial.print("Card removed ");
      Serial.println(code);
    }
};

DFMiniMp3<HardwareSerial, Mp3Notify> mp3(Serial1);
bool isPlaying = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  mp3.begin();
  mp3.setVolume(28);
  pinMode(A1, INPUT);
}

void loop() {
  if (analogRead(A1) > 100)
  {
    if (!isPlaying)
    {
      mp3.playMp3FolderTrack(1);  // sd:/mp3/0001.mp3
      delay(200);
      isPlaying = true;
    }
  }
  else
  {
    if (isPlaying)
    {
      mp3.pause();
      delay (200);
      isPlaying = false;
    }
  }
}
