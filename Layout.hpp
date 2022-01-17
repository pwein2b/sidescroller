#include <iostream>
#include <algoviz/SVG.hpp>
using namespace std;

class Layout {

        private:
        Rect backRed;
        Rect infoBack;
        Image hintergrund;
        Image gameover;
        Image welcome;          

        
        public:
        Layout(SVG &spielfeld) {    //x = 1200, y = 600
            hintergrund = Image("https://user-images.githubusercontent.com/18351809/46888871-624a3900-ce7f-11e8-808e-99fd90c8a3f4.png", 400, 200, 1000, 700, &spielfeld);
            gameover = Image("https://ak.picdn.net/shutterstock/videos/26123588/thumb/9.jpg", 400, 200, 1200, 700, &spielfeld);
            gameover.hide();
            backRed = Rect(0, 0, 800, 400, &spielfeld);
            backRed.setFill("transparent");
            backRed.setColor(1, 1, 1, 0);
            infoBack = Rect(-5, -20, 80, 20, &spielfeld);
            infoBack.setFill("white");
            infoBack.setColor("black");
            welcome = Image("https://www.codeview.net/wp-content/uploads/2018/03/Flappy-Bird-1.jpg", 400, 200, 1200, 700, &spielfeld);
        }
    
        void failedAttempt(){
            gameover.show();
            infoBack.setFill("black");
            infoBack.setColor("black");
        }
        
        // hide welcome image
        void hideWelcome(){
            welcome.hide();
        }
        
        // flicker screen
        void flackern(){
            for (int i = 0; i < 2; i++) {
                backRed.setFill(255, 0, 0);
                AlgoViz::sleep(100);
                backRed.setFill("transparent");
                AlgoViz::sleep(40);
            }
        }        
};