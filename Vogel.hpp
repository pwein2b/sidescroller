#include <iostream>
#include <algoviz/SVG.hpp>
using namespace std;

class Vogel {

        private:
        Image bird;
        int posx;
        int posy;
        bool dead = true;
        
        public:
        Vogel(SVG &spielfeld) { 
            this->posx = 200;
            this->posy= 50;
            bird = Image("https://miro.medium.com/max/724/1*ey7wIxpYa7Er7nRHhwyirQ.png", posx, posy, 40, 40, &spielfeld);
        }
    
        int getYCord(){
            return bird.getY();         
        }
    
        void birdHide(){
        bird.hide();
        }
    
        void birdShow(){
        bird.show();
        }
    
    
        void vogelDead(){
            int rot;
            while (dead == true){
                bird.moveTo(bird.getX(),bird.getY() + 2);
                bird.moveTo(bird.getX() + 1,bird.getY());
                bird.rotateTo(0 + rot);
                rot += 2;
                if (bird.getY() > 450){
                    dead = false;
                    bird.hide();
                }
            }
        }
    
        // Unser Vogel ist stationär, deswegen 200 als X-Wert
    

        void move(int add){
            bird.moveTo(200, add);
        }
        
        void rotate(int angle){
            bird.rotateTo(angle);
        }
};