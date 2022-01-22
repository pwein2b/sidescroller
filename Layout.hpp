#include <iostream>
#include <algoviz/SVG.hpp>
using namespace std;

class Layout {
        
        // Private Attribute
    
        private:
        Rect redFlash;
        Rect infoBack;
        Image hintergrund;
        Image gameover;
        Image welcome;          

        // Alles auf public
    
        public:
    
        // Konstruktor, der die grafischen Sachen macht
    
        Layout(SVG &spielfeld) {
            
            hintergrund = Image("https://user-images.githubusercontent.com/18351809/46888871-624a3900-ce7f-11e8-808e-99fd90c8a3f4.png", 0, 0, 1920, 1080, &spielfeld);
            
            gameover = Image("https://ak.picdn.net/shutterstock/videos/26123588/thumb/9.jpg", 400, 200, 1200, 700, &spielfeld);
            
            gameover.hide();
            
            redFlash = Rect(-100, 0, 1200, 600, &spielfeld);
            redFlash.setFill(255, 0, 0, 0);
            redFlash.setColor(255, 0, 0, 0);
            
            infoBack = Rect(-50, 0, 80, 20, &spielfeld);
            infoBack.setFill(255,255,255,1);
            infoBack.setColor(0,0,0,1);
            
            welcome = Image("https://www.codeview.net/wp-content/uploads/2018/03/Flappy-Bird-1.jpg", 400, 200, 1200, 700, &spielfeld);
            
        }
        
        // Wird ausgeführt bei Spielabbruch
    
        void gameOver() {
            
            gameover.show();
            infoBack.setFill("black");
            infoBack.setColor("black");
        }
        
        void hideWelcome() {
            
            welcome.hide();
        }
        
        // Wenn der Vogel stirbt, soll das Bild flackern.
    
        void dmg() {
            
            for (int i = 0; i < 2; i++) {
                
                redFlash.setFill(255, 0, 0, 1);
                AlgoViz::sleep(100);
                redFlash.setFill(255, 0, 0, 0);
                AlgoViz::sleep(40);
            }
        }        
};