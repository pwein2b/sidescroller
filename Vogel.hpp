#include <iostream>
#include <algoviz/SVG.hpp>
using namespace std;

class Vogel {
    
        // Erstellt die privaten Attribute

        private:
        Image bird;
        int posX;
        int posY;
        bool dead = true;
        
        // Ab hier alles auf public, also von außen zugreifbar
    
        public:
    
        // Unser Konstruktor den anfänglichen Koordinaten und der grafischen Darstellung des Vogels
    
        Vogel(SVG &spielfeld) {
            
            this->posX = 200;
            this->posY= 50;
            bird = Image("https://miro.medium.com/max/724/1*ey7wIxpYa7Er7nRHhwyirQ.png", posX, posY, 40, 40, &spielfeld);
        }
        
        // Unsere Operationen
    
        int getYCord() {
            
            return bird.getY();         
        }
    
        void birdHide() {
            
            bird.hide();
        }
    
        void birdShow() {
            
            bird.show();
        }
    
        // Wenn unser Vogel stirbt, soll er rotieren und zu Rick Astley werden.
    
        void vogelDead() {
            
            int rot;
            bird = Image("https://media.tenor.com/images/ff5faf4a21655f2fe7f93f120ec6b803/tenor.gif", posX, posY, 40, 40, &spielfeld);
            
            while (dead == true) {
                
                bird.moveTo(bird.getX(),bird.getY() + 2);
                bird.moveTo(bird.getX() + 1,bird.getY());
                bird.rotateTo(0 + rot);
                rot += 2;
                
                if (bird.getY() > 450) {
                    
                    dead = false;
                    bird.hide();
                }
            }
        }
    
        // Unser Vogel ist stationär, deswegen 200 als X-Wert.

        void move(int add) {
            
            bird.moveTo(200, add);
        }
        
        void rotate(int angle) {
            
            bird.rotateTo(angle);
        }
};